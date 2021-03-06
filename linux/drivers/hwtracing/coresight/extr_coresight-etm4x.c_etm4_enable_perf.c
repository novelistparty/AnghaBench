#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct perf_event {int dummy; } ;
struct etmv4_drvdata {scalar_t__ cpu; } ;
struct TYPE_2__ {int /*<<< orphan*/  parent; } ;
struct coresight_device {TYPE_1__ dev; } ;

/* Variables and functions */
 int EINVAL ; 
 scalar_t__ WARN_ON_ONCE (int) ; 
 struct etmv4_drvdata* dev_get_drvdata (int /*<<< orphan*/ ) ; 
 int etm4_enable_hw (struct etmv4_drvdata*) ; 
 int etm4_parse_event_config (struct etmv4_drvdata*,struct perf_event*) ; 
 scalar_t__ smp_processor_id () ; 

__attribute__((used)) static int etm4_enable_perf(struct coresight_device *csdev,
			    struct perf_event *event)
{
	int ret = 0;
	struct etmv4_drvdata *drvdata = dev_get_drvdata(csdev->dev.parent);

	if (WARN_ON_ONCE(drvdata->cpu != smp_processor_id())) {
		ret = -EINVAL;
		goto out;
	}

	/* Configure the tracer based on the session's specifics */
	ret = etm4_parse_event_config(drvdata, event);
	if (ret)
		goto out;
	/* And enable it */
	ret = etm4_enable_hw(drvdata);

out:
	return ret;
}