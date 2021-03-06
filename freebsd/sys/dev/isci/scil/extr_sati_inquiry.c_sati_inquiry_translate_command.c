#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  U8 ;
struct TYPE_7__ {int allocation_length; int /*<<< orphan*/  type; int /*<<< orphan*/  state; } ;
typedef  TYPE_1__ SATI_TRANSLATOR_SEQUENCE_T ;
typedef  int /*<<< orphan*/  SATI_STATUS ;

/* Variables and functions */
 int /*<<< orphan*/  SATI_COMPLETE ; 
 int /*<<< orphan*/  SATI_FAILURE_CHECK_RESPONSE_DATA ; 
 int /*<<< orphan*/  SATI_SEQUENCE_INQUIRY_ATA_INFORMATION ; 
 int /*<<< orphan*/  SATI_SEQUENCE_INQUIRY_BLOCK_DEVICE ; 
 int /*<<< orphan*/  SATI_SEQUENCE_INQUIRY_DEVICE_ID ; 
 int /*<<< orphan*/  SATI_SEQUENCE_INQUIRY_EXECUTE_DEVICE_DIAG ; 
 int /*<<< orphan*/  SATI_SEQUENCE_INQUIRY_SERIAL_NUMBER ; 
 int /*<<< orphan*/  SATI_SEQUENCE_INQUIRY_STANDARD ; 
 int /*<<< orphan*/  SATI_SEQUENCE_INQUIRY_SUPPORTED_PAGES ; 
 int /*<<< orphan*/  SATI_SEQUENCE_STATE_INCOMPLETE ; 
 int /*<<< orphan*/  SATI_SUCCESS ; 
 int /*<<< orphan*/  SCSI_ASCQ_INVALID_FIELD_IN_CDB ; 
 int /*<<< orphan*/  SCSI_ASC_INVALID_FIELD_IN_CDB ; 
#define  SCSI_INQUIRY_ATA_INFORMATION_PAGE 132 
#define  SCSI_INQUIRY_BLOCK_DEVICE_PAGE 131 
#define  SCSI_INQUIRY_DEVICE_ID_PAGE 130 
 int SCSI_INQUIRY_EVPD_ENABLE ; 
#define  SCSI_INQUIRY_SUPPORTED_PAGES_PAGE 129 
#define  SCSI_INQUIRY_UNIT_SERIAL_NUM_PAGE 128 
 int /*<<< orphan*/  SCSI_SENSE_ILLEGAL_REQUEST ; 
 int /*<<< orphan*/  SCSI_STATUS_CHECK_CONDITION ; 
 int /*<<< orphan*/  sati_ata_execute_device_diagnostic_construct (void*,TYPE_1__*) ; 
 int /*<<< orphan*/  sati_ata_identify_device_construct (void*,TYPE_1__*) ; 
 int /*<<< orphan*/ * sati_cb_get_cdb_address (void*) ; 
 int sati_get_cdb_byte (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  sati_inquiry_supported_pages_translate_data (TYPE_1__*,void*) ; 
 int /*<<< orphan*/  sati_scsi_sense_data_construct (TYPE_1__*,void*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

SATI_STATUS sati_inquiry_translate_command(
   SATI_TRANSLATOR_SEQUENCE_T * sequence,
   void                       * scsi_io,
   void                       * ata_io
)
{
   U8 * cdb = sati_cb_get_cdb_address(scsi_io);

   /**
    * SPC dictates:
    * - that the page code field must be 0, if VPD enable is 0.
    */
   if (  ((sati_get_cdb_byte(cdb, 1) & SCSI_INQUIRY_EVPD_ENABLE) == 0)
      && (sati_get_cdb_byte(cdb, 2) != 0) )
   {
      sati_scsi_sense_data_construct(
         sequence,
         scsi_io,
         SCSI_STATUS_CHECK_CONDITION,
         SCSI_SENSE_ILLEGAL_REQUEST,
         SCSI_ASC_INVALID_FIELD_IN_CDB,
         SCSI_ASCQ_INVALID_FIELD_IN_CDB
      );
      return SATI_FAILURE_CHECK_RESPONSE_DATA;
   }

   // Set the data length based on the allocation length field in the CDB.
   sequence->allocation_length = (sati_get_cdb_byte(cdb, 3) << 8) |
                                 (sati_get_cdb_byte(cdb, 4));

   // Check to see if there was a request for the vital product data or just
   // the standard inquiry.
   if (sati_get_cdb_byte(cdb, 1) & SCSI_INQUIRY_EVPD_ENABLE)
   {
      // Parse the page code to determine which translator to invoke.
      switch (sati_get_cdb_byte(cdb, 2))
      {
         case SCSI_INQUIRY_SUPPORTED_PAGES_PAGE:
            sequence->type  = SATI_SEQUENCE_INQUIRY_SUPPORTED_PAGES;
            sati_inquiry_supported_pages_translate_data(sequence, scsi_io);
            return SATI_COMPLETE;
         break;

         case SCSI_INQUIRY_UNIT_SERIAL_NUM_PAGE:
            sequence->type = SATI_SEQUENCE_INQUIRY_SERIAL_NUMBER;
         break;

         case SCSI_INQUIRY_DEVICE_ID_PAGE:
            sequence->type = SATI_SEQUENCE_INQUIRY_DEVICE_ID;
         break;

         case SCSI_INQUIRY_ATA_INFORMATION_PAGE:

            if(sequence->state == SATI_SEQUENCE_STATE_INCOMPLETE)
            {
               sati_ata_execute_device_diagnostic_construct(
                  ata_io,
                  sequence
               );
               sequence->type = SATI_SEQUENCE_INQUIRY_EXECUTE_DEVICE_DIAG;
            }
            else
            {
               sequence->type = SATI_SEQUENCE_INQUIRY_ATA_INFORMATION;
            }
         break;

         case SCSI_INQUIRY_BLOCK_DEVICE_PAGE:
            sequence->type = SATI_SEQUENCE_INQUIRY_BLOCK_DEVICE;
         break;

         default:
            sati_scsi_sense_data_construct(
               sequence,
               scsi_io,
               SCSI_STATUS_CHECK_CONDITION,
               SCSI_SENSE_ILLEGAL_REQUEST,
               SCSI_ASC_INVALID_FIELD_IN_CDB,
               SCSI_ASCQ_INVALID_FIELD_IN_CDB
            );
            return SATI_FAILURE_CHECK_RESPONSE_DATA;
         break;
      }
   }
   else
   {
      sequence->type = SATI_SEQUENCE_INQUIRY_STANDARD;
   }

   sati_ata_identify_device_construct(ata_io, sequence);

   return SATI_SUCCESS;
}