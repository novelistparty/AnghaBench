#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct sdma_conf {int dummy; } ;
struct sc_pcminfo {scalar_t__ chnum; void* dev; struct sc_info* sc; } ;
struct sc_info {void* dev; int dma_size; scalar_t__ sdma_channel; int /*<<< orphan*/  ih; int /*<<< orphan*/ * res; int /*<<< orphan*/  buf_base; int /*<<< orphan*/  buf_base_phys; int /*<<< orphan*/  dma_map; int /*<<< orphan*/  dma_tag; int /*<<< orphan*/  bsh; int /*<<< orphan*/  bst; int /*<<< orphan*/ * lock; void* conf; scalar_t__ pos; int /*<<< orphan*/ * sr; } ;
typedef  void* device_t ;

/* Variables and functions */
 int BUS_DMA_COHERENT ; 
 int BUS_DMA_NOWAIT ; 
 int /*<<< orphan*/  BUS_SPACE_MAXADDR ; 
 int /*<<< orphan*/  BUS_SPACE_MAXADDR_32BIT ; 
 int ENXIO ; 
 int INTR_MPSAFE ; 
 int INTR_TYPE_AV ; 
 int /*<<< orphan*/  M_DEVBUF ; 
 int M_NOWAIT ; 
 int M_WAITOK ; 
 int M_ZERO ; 
 int /*<<< orphan*/  PCMDIR_PLAY ; 
 int SD_F_MPSAFE ; 
 int SND_STATUSLEN ; 
 scalar_t__ bus_alloc_resources (void*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int bus_dma_tag_create (int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int bus_dmamap_load (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 int bus_dmamem_alloc (int /*<<< orphan*/ ,void**,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bus_get_dma_tag (void*) ; 
 int bus_setup_intr (void*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ,struct sc_pcminfo*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bzero (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  device_get_nameunit (void*) ; 
 int /*<<< orphan*/  device_printf (void*,char*) ; 
 scalar_t__ find_sdma_controller (struct sc_info*) ; 
 int /*<<< orphan*/  imx_ccm_ssi_configure (void*) ; 
 void* malloc (int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mixer_init (void*,int /*<<< orphan*/ *,struct sc_pcminfo*) ; 
 int /*<<< orphan*/  pcm_addchan (void*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,struct sc_pcminfo*) ; 
 int pcm_getflags (void*) ; 
 int pcm_register (void*,struct sc_pcminfo*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pcm_setflags (void*,int) ; 
 int /*<<< orphan*/  pcm_setstatus (void*,char*) ; 
 int /*<<< orphan*/ * rate_map ; 
 int /*<<< orphan*/  rman_get_bushandle (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rman_get_bustag (int /*<<< orphan*/ ) ; 
 scalar_t__ sdma_alloc () ; 
 int /*<<< orphan*/  setup_ssi (struct sc_info*) ; 
 int /*<<< orphan*/ * snd_mtxcreate (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*) ; 
 int /*<<< orphan*/  ssi_dmamap_cb ; 
 int /*<<< orphan*/  ssi_intr ; 
 int /*<<< orphan*/  ssi_spec ; 
 int /*<<< orphan*/  ssichan_class ; 
 int /*<<< orphan*/  ssimixer_class ; 

__attribute__((used)) static int
ssi_attach(device_t dev)
{
	char status[SND_STATUSLEN];
	struct sc_pcminfo *scp;
	struct sc_info *sc;
	int err;

	sc = malloc(sizeof(*sc), M_DEVBUF, M_WAITOK | M_ZERO);
	sc->dev = dev;
	sc->sr = &rate_map[0];
	sc->pos = 0;
	sc->conf = malloc(sizeof(struct sdma_conf), M_DEVBUF, M_WAITOK | M_ZERO);

	sc->lock = snd_mtxcreate(device_get_nameunit(dev), "ssi softc");
	if (sc->lock == NULL) {
		device_printf(dev, "Can't create mtx\n");
		return (ENXIO);
	}

	if (bus_alloc_resources(dev, ssi_spec, sc->res)) {
		device_printf(dev, "could not allocate resources\n");
		return (ENXIO);
	}

	/* Memory interface */
	sc->bst = rman_get_bustag(sc->res[0]);
	sc->bsh = rman_get_bushandle(sc->res[0]);

	/* SDMA */
	if (find_sdma_controller(sc)) {
		device_printf(dev, "could not find active SDMA\n");
		return (ENXIO);
	}

	/* Setup PCM */
	scp = malloc(sizeof(struct sc_pcminfo), M_DEVBUF, M_NOWAIT | M_ZERO);
	scp->sc = sc;
	scp->dev = dev;

	/*
	 * Maximum possible DMA buffer.
	 * Will be used partially to match 24 bit word.
	 */
	sc->dma_size = 131072;

	/*
	 * Must use dma_size boundary as modulo feature required.
	 * Modulo feature allows setup circular buffer.
	 */

	err = bus_dma_tag_create(
	    bus_get_dma_tag(sc->dev),
	    4, sc->dma_size,		/* alignment, boundary */
	    BUS_SPACE_MAXADDR_32BIT,	/* lowaddr */
	    BUS_SPACE_MAXADDR,		/* highaddr */
	    NULL, NULL,			/* filter, filterarg */
	    sc->dma_size, 1,		/* maxsize, nsegments */
	    sc->dma_size, 0,		/* maxsegsize, flags */
	    NULL, NULL,			/* lockfunc, lockarg */
	    &sc->dma_tag);

	err = bus_dmamem_alloc(sc->dma_tag, (void **)&sc->buf_base,
	    BUS_DMA_NOWAIT | BUS_DMA_COHERENT, &sc->dma_map);
	if (err) {
		device_printf(dev, "cannot allocate framebuffer\n");
		return (ENXIO);
	}

	err = bus_dmamap_load(sc->dma_tag, sc->dma_map, sc->buf_base,
	    sc->dma_size, ssi_dmamap_cb, &sc->buf_base_phys, BUS_DMA_NOWAIT);
	if (err) {
		device_printf(dev, "cannot load DMA map\n");
		return (ENXIO);
	}

	bzero(sc->buf_base, sc->dma_size);

	/* Setup interrupt handler */
	err = bus_setup_intr(dev, sc->res[1], INTR_MPSAFE | INTR_TYPE_AV,
	    NULL, ssi_intr, scp, &sc->ih);
	if (err) {
		device_printf(dev, "Unable to alloc interrupt resource.\n");
		return (ENXIO);
	}

	pcm_setflags(dev, pcm_getflags(dev) | SD_F_MPSAFE);

	err = pcm_register(dev, scp, 1, 0);
	if (err) {
		device_printf(dev, "Can't register pcm.\n");
		return (ENXIO);
	}

	scp->chnum = 0;
	pcm_addchan(dev, PCMDIR_PLAY, &ssichan_class, scp);
	scp->chnum++;

	snprintf(status, SND_STATUSLEN, "at simplebus");
	pcm_setstatus(dev, status);

	mixer_init(dev, &ssimixer_class, scp);
	setup_ssi(sc);

	imx_ccm_ssi_configure(dev);

	sc->sdma_channel = sdma_alloc();
	if (sc->sdma_channel < 0) {
		device_printf(sc->dev, "Can't get sDMA channel\n");
		return (1);
	}

	return (0);
}