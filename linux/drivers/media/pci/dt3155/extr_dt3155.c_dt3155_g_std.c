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
typedef  int /*<<< orphan*/  v4l2_std_id ;
struct file {int dummy; } ;
struct dt3155_priv {int /*<<< orphan*/  std; } ;

/* Variables and functions */
 struct dt3155_priv* video_drvdata (struct file*) ; 

__attribute__((used)) static int dt3155_g_std(struct file *filp, void *p, v4l2_std_id *norm)
{
	struct dt3155_priv *pd = video_drvdata(filp);

	*norm = pd->std;
	return 0;
}