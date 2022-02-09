/**
 * @file
 * @brief Filesystem API
 * @defgroup fs Filesystem
 * @details API for work with filesystem
 * @{
 */

#ifndef FS_H
#define FS_H

/* Include -------------------------------------------------------------------*/
/* Configuration -------------------------------------------------------------*/
/* Typedef -------------------------------------------------------------------*/

/**
 * @brief Return Values
*/
typedef enum
{
  FS_RET_OK = 0,
  FS_RET_ERR = 1,
} fs_ret_values;

/* Function Declaration ------------------------------------------------------*/

/**
 * @brief      Write data to the filesystem
 * @details    If file exist old data will be deleted
 * @param[in]  path Path to the file
 * @param[in]  data Data to write
 * @param[in]  data_size Data size
 * @return     FS_RET_OK on success, FS_RET_ERR otherwise
 */
fs_ret_values fs_write_string(const char *path, const char *data);

/**
 * @brief      Read data from the filesystem
 * @details    
 * @param[in]  path Path to the file
 * @param[out] data Data will be read in this array
 * @param[in]  data_size Data size
 * @return     Number of bytes that was read on success, EOF otherwise
 */
int fs_read(const char* path, char* data, unsigned short data_size);


#endif /* FS_H */

/** @} */