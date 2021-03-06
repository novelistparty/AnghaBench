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
typedef  int /*<<< orphan*/  FLAC__StreamDecoderWriteCallback ;
typedef  int /*<<< orphan*/  FLAC__StreamDecoderMetadataCallback ;
typedef  int /*<<< orphan*/  FLAC__StreamDecoderInitStatus ;
typedef  int /*<<< orphan*/  FLAC__StreamDecoderErrorCallback ;
typedef  int /*<<< orphan*/  FLAC__StreamDecoder ;

/* Variables and functions */
 int /*<<< orphan*/  init_file_internal_ (int /*<<< orphan*/ *,char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,void*,int) ; 

FLAC__StreamDecoderInitStatus FLAC__stream_decoder_init_ogg_file(
	FLAC__StreamDecoder *decoder,
	const char *filename,
	FLAC__StreamDecoderWriteCallback write_callback,
	FLAC__StreamDecoderMetadataCallback metadata_callback,
	FLAC__StreamDecoderErrorCallback error_callback,
	void *client_data
)
{
	return init_file_internal_(decoder, filename, write_callback, metadata_callback, error_callback, client_data, /*is_ogg=*/true);
}