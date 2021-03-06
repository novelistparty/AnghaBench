#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct vlc_logger_operations {int dummy; } ;
struct vlc_logger {int dummy; } ;
struct TYPE_5__ {int /*<<< orphan*/  logger; } ;
struct TYPE_6__ {TYPE_1__ obj; } ;
typedef  TYPE_2__ libvlc_int_t ;

/* Variables and functions */
 int /*<<< orphan*/  VLC_OBJECT (TYPE_2__*) ; 
 struct vlc_logger discard_log ; 
 struct vlc_logger* vlc_LogExternalCreate (struct vlc_logger_operations const*,void*) ; 
 int /*<<< orphan*/  vlc_LogSpam (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vlc_LogSwitch (int /*<<< orphan*/ ,struct vlc_logger*) ; 

void vlc_LogSet(libvlc_int_t *vlc, const struct vlc_logger_operations *ops,
                void *opaque)
{
    struct vlc_logger *logger;

    if (ops != NULL)
        logger = vlc_LogExternalCreate(ops, opaque);
    else
        logger = NULL;

    if (logger == NULL)
        logger = &discard_log;

    vlc_LogSwitch(vlc->obj.logger, logger);
    vlc_LogSpam(VLC_OBJECT(vlc));
}