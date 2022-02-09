/**
 * @file
 * @brief User credentials storage API
 * @defgroup cred_storage Credentials storage
 * @details API for read/write user credentials
 * @{
 */

#ifndef CRED_STORAGE_H
#define CRED_STORAGE_H

/* Include -------------------------------------------------------------------*/
/* Configuration -------------------------------------------------------------*/

#define USERNAME_MAX_SIZE   64U
#define PASSWORD_MAX_SIZE   32U

/* Typedef -------------------------------------------------------------------*/

/**
 * @brief Return Values
*/
typedef enum 
{
  CRED_ST_RET_OK = 0,
  CRED_ST_RET_ERR = 1,
} cred_storage_ret_values;

/**
 * @brief Credentials
*/
typedef struct credentials_s
{
  char username[USERNAME_MAX_SIZE];
  char password[PASSWORD_MAX_SIZE];
} credentials_t;

/* Function Declaration ------------------------------------------------------*/

/**
 * @brief      Save credentials to the filesystem
 * @details    
 * @param[in]  credentials Credentials to store
 * @return     CRES_ST_RET_OK on success, CRES_ST_RET_ERR otherwise
 */
cred_storage_ret_values cred_storage_save_credentials(const credentials_t *credentials);

/**
 * @brief      Read credentials from the filesystem
 * @details
 * @param[out] credentials Credentials will be read to this struct
 * @return     CRES_ST_RET_OK on success, CRES_ST_RET_ERR otherwise
 */
cred_storage_ret_values cred_storage_read_credentials(credentials_t *credentials);


#endif /* CRED_STORAGE_H */

/** @} */