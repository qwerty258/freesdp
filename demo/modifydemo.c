/*
  modifydemo - An example on how to use FreeSDP to modify SDP descriptions.
  Copyright (C) 2003 Federico Montesino Pouzols <fedemp@altern.org>
  
  modifydemo is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.
  
  modifydemo is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include <stdio.h>
#include <stdlib.h>
#include <freesdp/freesdp.h>

#define MAX_SIZE 5000

int main(int argc, char *argv[])
{
  const char *filename = NULL;
  char text[MAX_SIZE];
  char *modified_text;
  size_t size = MAX_SIZE;
  FILE *file = NULL;
  fsdp_description_t *dsc = NULL;
  fsdp_error_t result;

  if ( argc == 2 ) {
    filename = argv[1];
  } else {
    filename = "rfc-example.sdp";
  }

  if ( (file = fopen(filename,"r")) ) {
    size = fread(text,1,size,file);
    
    /* Allocate a description object */
    dsc = fsdp_description_new();
  
    /* Parse */
    printf(" Parsing %s...",filename);
    result = fsdp_parse(text,dsc);
    
    if ( result == FSDPE_OK )
      printf(" completed succesfully!\n");
    else 
      printf(" failed with error code %d: %s.\n",result,fsdp_strerror(result));
    
    /* Modify */
    printf(" This is the original description:\n%s\n",text);
    fsdp_set_information(dsc,"Modified information field");
    fsdp_add_email(dsc,"added.email@foo.example.com");
    result = fsdp_format(dsc,&modified_text);
    printf(" And this is a slightly modified version of it:\n%s\n",
	   modified_text);

    /* Free the new fsdp_description_t object previously allocated */
    fsdp_description_delete(dsc);
    /* Free the text string allocated by fsdp_format */
    free(modified_text);
    fclose(file);
  } else {
    printf("Could not open file.\n");
  }
  
  return 0;
}
