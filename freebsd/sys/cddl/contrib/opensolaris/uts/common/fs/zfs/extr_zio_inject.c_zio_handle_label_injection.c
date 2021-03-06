#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct TYPE_10__ {scalar_t__ io_offset; TYPE_3__* io_vd; } ;
typedef  TYPE_2__ zio_t ;
struct TYPE_11__ {scalar_t__ vdev_psize; scalar_t__ vdev_guid; } ;
typedef  TYPE_3__ vdev_t ;
typedef  scalar_t__ uint64_t ;
struct TYPE_9__ {scalar_t__ zi_start; scalar_t__ zi_end; scalar_t__ zi_cmd; scalar_t__ zi_guid; } ;
struct TYPE_12__ {TYPE_1__ zi_record; } ;
typedef  TYPE_4__ inject_handler_t ;

/* Variables and functions */
 int /*<<< orphan*/  RW_READER ; 
 scalar_t__ VDEV_LABEL_END_SIZE ; 
 scalar_t__ VDEV_LABEL_START_SIZE ; 
 scalar_t__ ZINJECT_LABEL_FAULT ; 
 int /*<<< orphan*/  inject_handlers ; 
 int /*<<< orphan*/  inject_lock ; 
 TYPE_4__* list_head (int /*<<< orphan*/ *) ; 
 TYPE_4__* list_next (int /*<<< orphan*/ *,TYPE_4__*) ; 
 int /*<<< orphan*/  rw_enter (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rw_exit (int /*<<< orphan*/ *) ; 
 int vdev_label_number (scalar_t__,scalar_t__) ; 
 scalar_t__ vdev_label_offset (scalar_t__,int,scalar_t__) ; 

int
zio_handle_label_injection(zio_t *zio, int error)
{
	inject_handler_t *handler;
	vdev_t *vd = zio->io_vd;
	uint64_t offset = zio->io_offset;
	int label;
	int ret = 0;

	if (offset >= VDEV_LABEL_START_SIZE &&
	    offset < vd->vdev_psize - VDEV_LABEL_END_SIZE)
		return (0);

	rw_enter(&inject_lock, RW_READER);

	for (handler = list_head(&inject_handlers); handler != NULL;
	    handler = list_next(&inject_handlers, handler)) {
		uint64_t start = handler->zi_record.zi_start;
		uint64_t end = handler->zi_record.zi_end;

		if (handler->zi_record.zi_cmd != ZINJECT_LABEL_FAULT)
			continue;

		/*
		 * The injection region is the relative offsets within a
		 * vdev label. We must determine the label which is being
		 * updated and adjust our region accordingly.
		 */
		label = vdev_label_number(vd->vdev_psize, offset);
		start = vdev_label_offset(vd->vdev_psize, label, start);
		end = vdev_label_offset(vd->vdev_psize, label, end);

		if (zio->io_vd->vdev_guid == handler->zi_record.zi_guid &&
		    (offset >= start && offset <= end)) {
			ret = error;
			break;
		}
	}
	rw_exit(&inject_lock);
	return (ret);
}