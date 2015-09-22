/*
  parsedemo - An example on how to use FreeSDP to parse SDP descriptions.
  Copyright (C) 2001,2002  Federico Montesino Pouzols <fedemp@altern.org>
  
  parsedemo is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.
  
  parsedemo is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include <stdio.h>
#include <freesdp/parser.h>

fsdp_error_t
do_parse(const char *, size_t);

/**
 * Parses the textual SDP description in text, which is len octets
 * long.
 **/
fsdp_error_t
do_parse(const char *text, size_t len)
{
  fsdp_description_t *dsc = NULL;
  fsdp_error_t result;
  unsigned int i = 0;

  /* Allocate a description object */
  dsc = fsdp_description_new();

  /* Parse */
  printf(" Starting to parse...\n");
  result = fsdp_parse(text,dsc);
  
  if ( result == FSDPE_OK )
    printf(" completed succesfully!\n");
  else 
    printf(" failed with error code %d: %s.\n",result,fsdp_strerror(result));

  /* Get properties */
  printf(" The owner of the session seems to be \"%s\".\n",
	 fsdp_get_owner_username(dsc));
  printf(" The session is called \"%s\"\n",fsdp_get_name(dsc));
  printf(" and is described as \"%s\".\n",fsdp_get_information(dsc));
  printf(" It consists of %u media streams.\n",fsdp_get_media_count(dsc));

  for (i = 0; i < fsdp_get_media_count(dsc); i++ )
    printf(" the media announcement number %d has %d rtpmap attributes\n",
	   i + 1,
	   fsdp_get_media_rtpmap_count(fsdp_get_media(dsc,i)));

  printf(" the description has %d unknown session level attributes:\n",
	 fsdp_get_unidentified_attributes_count(dsc));

  for (i = 0; i < fsdp_get_unidentified_attribute_count(dsc); i++ ) {
    printf("   #%d: %s\n",i+1,fsdp_get_unidentified_attribute(dsc,i));
  }

  /* Free the new fsdp_description_t object previously allocated */
  fsdp_description_delete(dsc);
  
  /* Return parse error code */
  return result;
}

int main(int argc, char *argv[])
{
  const int MAX_SIZE = 5000;
  char text[MAX_SIZE], *filename = NULL;
  size_t size = MAX_SIZE;
  FILE *file = NULL;
  fsdp_error_t result;

  if ( argc == 2 ) {
    filename = argv[1];
  } else {
    filename = "rfc-example.sdp";
  }

  if ( (file = fopen(filename,"r")) ) {
    size = fread(text,1,size,file);
    /* Here is where FreeSDP works */
    result = do_parse(text,size);
    printf("  Parsed a %d octets long SDP description.\n  Result: %d\n",
	   size,result);
    fclose(file);
  } else {
    printf("Could not open file.\n");
  }
  return 0;
}
