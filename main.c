#include <stdio.h>
#include <string.h>
#include "cred_storage.h"

#define USERNAME "Admin"
#define PASSWORD "very_strong_password"

static credentials_t credentials = { 0 };

int main(int argc, char **argv)
{
  strcpy(credentials.username, USERNAME);
  strcpy(credentials.password, PASSWORD);
  if (CRED_ST_RET_ERR == cred_storage_read_credentials(&credentials)) 
  {
    printf("No file with creds! Save first...\r\n");
    cred_storage_save_credentials(&credentials);
    cred_storage_read_credentials(&credentials);
  }
  printf("Read creds:\r\nUsername: %s\r\nPassword:%s\r\n", credentials.username, credentials.password);
  return 0;
}