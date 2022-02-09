/**
 * @file
 * @brief Implementation of the filesystem API
 * @ingroup fs
 * @details
 * @{
 */

/* Include -------------------------------------------------------------------*/
#include <stdio.h>
#include "fs.h"

/* Configuration -------------------------------------------------------------*/
/* Macro ---------------------------------------------------------------------*/
/* Typedef -------------------------------------------------------------------*/
/* Constant ------------------------------------------------------------------*/
/* Variable ------------------------------------------------------------------*/
/* Function Declaration ------------------------------------------------------*/

fs_ret_values fs_write_string(const char *path, const char *data)
{
  FILE *file;
  file = fopen(path, "wb+");
  if(!file)
  {
    return FS_RET_ERR;
  }
  int res = fputs(data, file);
  fclose(file);
  if(EOF == res) {
    return FS_RET_ERR;
  }
  return FS_RET_OK;
}

int fs_read(const char* path, char* data, unsigned short data_size)
{
  int ret = EOF;
  FILE* file;
  file = fopen(path, "rb");
  if(!file)
  {
    return ret;
  }
  ret = fread(data, sizeof(char), data_size, file);
  if((ret != data_size) && !feof(file))
  {
    ret = EOF;
  }
  fclose(file);
  return ret;
}

/** @} */
