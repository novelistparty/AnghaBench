#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/ * text; int /*<<< orphan*/  cursor; } ;
typedef  TYPE_1__ textbox ;
typedef  int /*<<< orphan*/  gunichar ;
typedef  int /*<<< orphan*/  gchar ;
typedef  scalar_t__ GUnicodeBreakType ;

/* Variables and functions */
 scalar_t__ G_UNICODE_BREAK_ALPHABETIC ; 
 scalar_t__ G_UNICODE_BREAK_HEBREW_LETTER ; 
 scalar_t__ G_UNICODE_BREAK_NUMERIC ; 
 scalar_t__ G_UNICODE_BREAK_QUOTATION ; 
 scalar_t__ g_unichar_break_type (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  g_utf8_get_char (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * g_utf8_offset_to_pointer (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int g_utf8_pointer_to_offset (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * g_utf8_prev_char (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  textbox_cursor (TYPE_1__*,int) ; 

__attribute__((used)) static void textbox_cursor_dec_word ( textbox *tb )
{
    // Find word boundaries, with pango_Break?
    gchar *n;
    gchar *c = g_utf8_offset_to_pointer ( tb->text, tb->cursor );
    while ( ( c = g_utf8_prev_char ( c ) ) && c != tb->text ) {
        gunichar          uc = g_utf8_get_char ( c );
        GUnicodeBreakType bt = g_unichar_break_type ( uc );
        if ( ( bt == G_UNICODE_BREAK_ALPHABETIC || bt == G_UNICODE_BREAK_HEBREW_LETTER ||
               bt == G_UNICODE_BREAK_NUMERIC || bt == G_UNICODE_BREAK_QUOTATION ) ) {
            break;
        }
    }
    if ( c != tb->text ) {
        while ( ( n = g_utf8_prev_char ( c ) ) ) {
            gunichar          uc = g_utf8_get_char ( n );
            GUnicodeBreakType bt = g_unichar_break_type ( uc );
            if ( !( bt == G_UNICODE_BREAK_ALPHABETIC || bt == G_UNICODE_BREAK_HEBREW_LETTER ||
                    bt == G_UNICODE_BREAK_NUMERIC || bt == G_UNICODE_BREAK_QUOTATION ) ) {
                break;
            }
            c = n;
            if ( n == tb->text ) {
                break;
            }
        }
    }
    int index = g_utf8_pointer_to_offset ( tb->text, c );
    textbox_cursor ( tb, index );
}