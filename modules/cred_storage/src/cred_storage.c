/**
 * @file
 * @brief Implementation of the credentials storage
 * @ingroup cred_storage
 * @details 
 * @{
 */

/* Include -------------------------------------------------------------------*/
#include <string.h>
#include <stdio.h>
#include "cred_storage.h"
#include "fs.h"

/* Configuration -------------------------------------------------------------*/
#define CREDENTIALS_FILENAME "credentials.txt"
#define NEWLINE               "\r\n"
/* Macro ---------------------------------------------------------------------*/
/* Typedef -------------------------------------------------------------------*/
/* Constant ------------------------------------------------------------------*/
/* Variable ------------------------------------------------------------------*/

static credentials_t g_credentials = { 0 };

/* Function Declaration ------------------------------------------------------*/

cred_storage_ret_values cred_storage_save_credentials(const credentials_t* credentials)
{
  cred_storage_ret_values res = CRED_ST_RET_ERR;
  char creds[sizeof(credentials_t) + 2/*new line*/ + 1/*null term*/];
  snprintf(creds, sizeof(creds), "%s%s%s", credentials->username, NEWLINE, credentials->password);
  if(FS_RET_OK == fs_write_string(CREDENTIALS_FILENAME, creds))
  {
    memcpy(&g_credentials, credentials, sizeof(credentials_t));
    res = CRED_ST_RET_OK;
  }
  return res;
}

cred_storage_ret_values cred_storage_read_credentials(credentials_t* credentials)
{
  //If there is no creds yet, try to read from the file
  if(!strlen(g_credentials.username))
  {
    char creds[sizeof(credentials_t) + 2/*new line*/ + 1/*null term*/] = { 0 };
    if(EOF == fs_read(CREDENTIALS_FILENAME, creds, sizeof(creds)))
    {
      return CRED_ST_RET_ERR;
    }
    char *str = strtok(creds, NEWLINE);
    if(!str)
    {
      return CRED_ST_RET_ERR;
    }
    strcpy(g_credentials.username, str);
    str = strtok(NULL, NEWLINE);
    if(!str)
    {
      return CRED_ST_RET_ERR;
    }
    if('\n' == str[0])
    {
      str++;
    }
    strcpy(g_credentials.password, str);
  }
  memcpy(credentials, &g_credentials, sizeof(credentials_t));
  return CRED_ST_RET_OK;
}

/** @} */
