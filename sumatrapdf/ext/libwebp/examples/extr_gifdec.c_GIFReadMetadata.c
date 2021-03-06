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
struct WebPData {int dummy; } ;
struct GifFileType {int dummy; } ;
typedef  int /*<<< orphan*/  GifByteType ;

/* Variables and functions */
 int /*<<< orphan*/  ErrorGIFNotAvailable () ; 

int GIFReadMetadata(struct GifFileType* const gif, GifByteType** const buf,
                    struct WebPData* const metadata) {
  (void)gif;
  (void)buf;
  (void)metadata;
  ErrorGIFNotAvailable();
  return 0;
}