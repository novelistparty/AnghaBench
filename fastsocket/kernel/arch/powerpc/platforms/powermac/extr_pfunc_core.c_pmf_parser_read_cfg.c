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
typedef  int /*<<< orphan*/  u32 ;
struct pmf_handlers {int dummy; } ;
struct pmf_cmd {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  LOG_PARSE (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PMF_PARSE_CALL (int /*<<< orphan*/ ,struct pmf_cmd*,struct pmf_handlers*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pmf_next32 (struct pmf_cmd*) ; 
 int /*<<< orphan*/  read_cfg ; 

__attribute__((used)) static int pmf_parser_read_cfg(struct pmf_cmd *cmd, struct pmf_handlers *h)
{
	u32 offset = pmf_next32(cmd);
	u32 bytes = pmf_next32(cmd);

	LOG_PARSE("pmf: read_cfg(offset: %x, bytes: %ud)\n", offset, bytes);

	PMF_PARSE_CALL(read_cfg, cmd, h, offset, bytes);
}