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
struct Curl_easy {int /*<<< orphan*/  multi; } ;

/* Variables and functions */
 int /*<<< orphan*/  singlesocket (int /*<<< orphan*/ ,struct Curl_easy*) ; 

void Curl_updatesocket(struct Curl_easy *data)
{
  singlesocket(data->multi, data);
}