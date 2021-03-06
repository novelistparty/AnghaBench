#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  s_mtime; } ;
struct grub_nilfs2_data {TYPE_1__ sblock; } ;
typedef  scalar_t__ grub_int32_t ;
typedef  int /*<<< orphan*/  grub_err_t ;
typedef  int /*<<< orphan*/  grub_disk_t ;
typedef  TYPE_2__* grub_device_t ;
struct TYPE_5__ {int /*<<< orphan*/  disk; } ;

/* Variables and functions */
 int /*<<< orphan*/  grub_dl_ref (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  grub_dl_unref (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  grub_errno ; 
 int /*<<< orphan*/  grub_free (struct grub_nilfs2_data*) ; 
 scalar_t__ grub_le_to_cpu64 (int /*<<< orphan*/ ) ; 
 struct grub_nilfs2_data* grub_nilfs2_mount (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  my_mod ; 

__attribute__((used)) static grub_err_t
grub_nilfs2_mtime (grub_device_t device, grub_int32_t * tm)
{
  struct grub_nilfs2_data *data;
  grub_disk_t disk = device->disk;

  grub_dl_ref (my_mod);

  data = grub_nilfs2_mount (disk);
  if (!data)
    *tm = 0;
  else
    *tm = (grub_int32_t) grub_le_to_cpu64 (data->sblock.s_mtime);

  grub_dl_unref (my_mod);

  grub_free (data);

  return grub_errno;
}