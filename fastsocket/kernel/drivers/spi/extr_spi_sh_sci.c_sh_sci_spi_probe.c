#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct spi_master {int dummy; } ;
struct TYPE_9__ {TYPE_2__* master; int /*<<< orphan*/ * txrx_word; int /*<<< orphan*/  chipselect; } ;
struct sh_sci_spi {TYPE_4__ bitbang; int /*<<< orphan*/  membase; int /*<<< orphan*/  val; TYPE_1__* info; } ;
struct resource {scalar_t__ start; scalar_t__ end; } ;
struct TYPE_10__ {TYPE_1__* platform_data; } ;
struct platform_device {TYPE_5__ dev; } ;
struct TYPE_8__ {int /*<<< orphan*/  num_chipselect; int /*<<< orphan*/  bus_num; } ;
struct TYPE_7__ {int /*<<< orphan*/  num_chipselect; int /*<<< orphan*/  bus_num; } ;

/* Variables and functions */
 int ENOENT ; 
 int ENOMEM ; 
 int ENXIO ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  PIN_INIT ; 
 int /*<<< orphan*/  SCSPTR (struct sh_sci_spi*) ; 
 size_t SPI_MODE_0 ; 
 size_t SPI_MODE_1 ; 
 size_t SPI_MODE_2 ; 
 size_t SPI_MODE_3 ; 
 int /*<<< orphan*/  dev_err (TYPE_5__*,char*) ; 
 int /*<<< orphan*/  ioread8 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ioremap (scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  iounmap (int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct sh_sci_spi*) ; 
 int /*<<< orphan*/  setbits (struct sh_sci_spi*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  sh_sci_spi_chipselect ; 
 int /*<<< orphan*/  sh_sci_spi_txrx_mode0 ; 
 int /*<<< orphan*/  sh_sci_spi_txrx_mode1 ; 
 int /*<<< orphan*/  sh_sci_spi_txrx_mode2 ; 
 int /*<<< orphan*/  sh_sci_spi_txrx_mode3 ; 
 struct spi_master* spi_alloc_master (TYPE_5__*,int) ; 
 int spi_bitbang_start (TYPE_4__*) ; 
 TYPE_2__* spi_master_get (struct spi_master*) ; 
 struct sh_sci_spi* spi_master_get_devdata (struct spi_master*) ; 
 int /*<<< orphan*/  spi_master_put (TYPE_2__*) ; 

__attribute__((used)) static int sh_sci_spi_probe(struct platform_device *dev)
{
	struct resource	*r;
	struct spi_master *master;
	struct sh_sci_spi *sp;
	int ret;

	master = spi_alloc_master(&dev->dev, sizeof(struct sh_sci_spi));
	if (master == NULL) {
		dev_err(&dev->dev, "failed to allocate spi master\n");
		ret = -ENOMEM;
		goto err0;
	}

	sp = spi_master_get_devdata(master);

	platform_set_drvdata(dev, sp);
	sp->info = dev->dev.platform_data;

	/* setup spi bitbang adaptor */
	sp->bitbang.master = spi_master_get(master);
	sp->bitbang.master->bus_num = sp->info->bus_num;
	sp->bitbang.master->num_chipselect = sp->info->num_chipselect;
	sp->bitbang.chipselect = sh_sci_spi_chipselect;

	sp->bitbang.txrx_word[SPI_MODE_0] = sh_sci_spi_txrx_mode0;
	sp->bitbang.txrx_word[SPI_MODE_1] = sh_sci_spi_txrx_mode1;
	sp->bitbang.txrx_word[SPI_MODE_2] = sh_sci_spi_txrx_mode2;
	sp->bitbang.txrx_word[SPI_MODE_3] = sh_sci_spi_txrx_mode3;

	r = platform_get_resource(dev, IORESOURCE_MEM, 0);
	if (r == NULL) {
		ret = -ENOENT;
		goto err1;
	}
	sp->membase = ioremap(r->start, r->end - r->start + 1);
	if (!sp->membase) {
		ret = -ENXIO;
		goto err1;
	}
	sp->val = ioread8(SCSPTR(sp));
	setbits(sp, PIN_INIT, 1);

	ret = spi_bitbang_start(&sp->bitbang);
	if (!ret)
		return 0;

	setbits(sp, PIN_INIT, 0);
	iounmap(sp->membase);
 err1:
	spi_master_put(sp->bitbang.master);
 err0:
	return ret;
}