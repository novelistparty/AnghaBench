#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  TYPE_1__* seq_block ;
typedef  TYPE_1__* matching_seq ;
struct TYPE_5__ {struct TYPE_5__* next_seq_block; struct TYPE_5__* next_matching_seq; struct TYPE_5__* matching_seqs; } ;

/* Variables and functions */
 int /*<<< orphan*/  free (TYPE_1__*) ; 
 TYPE_1__* seq_blocks ; 

__attribute__((used)) static void
free_seq_blocks (void)
{
  while (seq_blocks)
    {
      seq_block sb = seq_blocks;
      while (sb->matching_seqs)
        {
          matching_seq mseq = sb->matching_seqs;
          sb->matching_seqs = mseq->next_matching_seq;
          free (mseq);
        }
      seq_blocks = sb->next_seq_block;
      free (sb);
    }
}