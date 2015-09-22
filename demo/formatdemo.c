/*
  formatdemo - An example on how to use FreeSDP to format SDP descriptions.
  Copyright (C) 2002,2003 Federico Montesino Pouzols <fedemp@altern.org>
  
  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.
  
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include <stdio.h>
#include <stdlib.h>
#include <freesdp/formatter.h>

int main(int argc, char *argv[])
{
  fsdp_description_t *dsc = NULL;
  fsdp_media_description_t *mdsc1 = NULL, *mdsc2 = NULL;
  char *text = NULL;
  fsdp_error_t result;

  printf(" Beginning to print a new SDP description...\n");

  /* With this routine we set the mandatory fields in the description */
  /* Note that fsdp_make_description allocates a new description object in
     *dsc */
  fsdp_make_description(&dsc,0,"A test session","1000000000","1111111111",
			"userfoo",FSDP_NETWORK_TYPE_INET,
			FSDP_ADDRESS_TYPE_IPV4,"127.0.0.1",
			time(NULL),time(NULL)+36000);

  /* Now, we can set additional fields */
  fsdp_set_information(dsc,"This is just a test multimedia session.");
  fsdp_set_session_type(dsc,FSDP_SESSION_TYPE_MODERATED);
  fsdp_set_uri(dsc,"http://www.example.com/foo/user.html");
  fsdp_add_email(dsc,"user1@foo.example.com (User 1)");
  fsdp_add_email(dsc,"user2@foo.example.com (User 2)");
  fsdp_add_phone(dsc,"+11 111 11 11 11");

  fsdp_set_conn_address(dsc,FSDP_NETWORK_TYPE_INET,FSDP_ADDRESS_TYPE_IPV4,
			"127.0.0.3",0,0);
  fsdp_set_sendrecv(dsc,FSDP_SENDRECV_SENDRECV);

  /* and also media descriptions */
  fsdp_make_media(&mdsc1,FSDP_MEDIA_AUDIO,30000,0,FSDP_TP_RTP_AVP,"96");
  fsdp_add_media_format(mdsc1,"97");
  fsdp_add_media_format(mdsc1,"98");
  fsdp_add_media_rtpmap(mdsc1,"96","PCMA",8000,NULL);
  fsdp_add_media_rtpmap(mdsc1,"97","PCMU",8000,NULL);
  fsdp_add_media_rtpmap(mdsc1,"98","L6",11025,"2");
  fsdp_set_media_title(mdsc1,"An audio example.");
  fsdp_add_media_bw_info(mdsc1,FSDP_BW_MOD_TYPE_CONFERENCE_TOTAL,64000,NULL);
  fsdp_set_media_ptime(mdsc1,20);
  fsdp_set_media_maxptime(mdsc1,40);

  fsdp_make_media(&mdsc2,FSDP_MEDIA_VIDEO,31000,0,FSDP_TP_RTP_AVP,"0");
  fsdp_set_media_title(mdsc2,"A video example.");
  fsdp_set_media_conn_address(mdsc2,FSDP_NETWORK_TYPE_INET,
			      FSDP_ADDRESS_TYPE_IPV4,"127.0.0.5",0,0);
  fsdp_set_media_sendrecv(mdsc2,FSDP_SENDRECV_SENDONLY);
  fsdp_set_media_encryption(mdsc2,FSDP_ENCRYPTION_METHOD_URI,
			    "http://www.example.com/key");

  fsdp_add_media(dsc,mdsc1);
  fsdp_add_media(dsc,mdsc2);

  /* Print SDP into memory. Note that fsdp_format allocates memory for *text */
  result = fsdp_format(dsc,&text);

  if ( result == FSDPE_OK ) {
    printf(" completed succesfully!\n Below is the description:\n");
    printf("------------------------------------\n");
  } else {
    printf(" failed with error code %d: %s.\n",result,fsdp_strerror(result));
    printf(" Below is what could be formatted:\n");
    printf("------------------------------------\n");
  }

  /* Dump textual SDP description to screen */
  printf(text);

  /* Free allocated description object and text */
  fsdp_description_delete(dsc);
  free(text);

  return 0;
}
