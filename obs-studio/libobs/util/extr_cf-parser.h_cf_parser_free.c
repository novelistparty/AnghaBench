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
struct cf_parser {int /*<<< orphan*/ * cur_token; int /*<<< orphan*/  error_list; int /*<<< orphan*/  pp; int /*<<< orphan*/  lex; } ;

/* Variables and functions */
 int /*<<< orphan*/  cf_lexer_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cf_preprocessor_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  error_data_free (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void cf_parser_free(struct cf_parser *parser)
{
	cf_lexer_free(&parser->lex);
	cf_preprocessor_free(&parser->pp);
	error_data_free(&parser->error_list);

	parser->cur_token = NULL;
}