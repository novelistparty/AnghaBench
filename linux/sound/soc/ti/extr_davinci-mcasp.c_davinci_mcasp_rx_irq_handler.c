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
typedef  int u32 ;
struct snd_pcm_substream {int dummy; } ;
struct davinci_mcasp {int* irq_request; int /*<<< orphan*/  dev; struct snd_pcm_substream** substreams; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  DAVINCI_MCASP_RXSTAT_REG ; 
 int /*<<< orphan*/  IRQ_RETVAL (int) ; 
 int ROVRN ; 
 size_t SNDRV_PCM_STREAM_CAPTURE ; 
 int XRERR ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ ,char*,...) ; 
 int mcasp_get_reg (struct davinci_mcasp*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mcasp_set_reg (struct davinci_mcasp*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  snd_pcm_stop_xrun (struct snd_pcm_substream*) ; 

__attribute__((used)) static irqreturn_t davinci_mcasp_rx_irq_handler(int irq, void *data)
{
	struct davinci_mcasp *mcasp = (struct davinci_mcasp *)data;
	struct snd_pcm_substream *substream;
	u32 irq_mask = mcasp->irq_request[SNDRV_PCM_STREAM_CAPTURE];
	u32 handled_mask = 0;
	u32 stat;

	stat = mcasp_get_reg(mcasp, DAVINCI_MCASP_RXSTAT_REG);
	if (stat & ROVRN & irq_mask) {
		dev_warn(mcasp->dev, "Receive buffer overflow\n");
		handled_mask |= ROVRN;

		substream = mcasp->substreams[SNDRV_PCM_STREAM_CAPTURE];
		if (substream)
			snd_pcm_stop_xrun(substream);
	}

	if (!handled_mask)
		dev_warn(mcasp->dev, "unhandled rx event. rxstat: 0x%08x\n",
			 stat);

	if (stat & XRERR)
		handled_mask |= XRERR;

	/* Ack the handled event only */
	mcasp_set_reg(mcasp, DAVINCI_MCASP_RXSTAT_REG, handled_mask);

	return IRQ_RETVAL(handled_mask);
}