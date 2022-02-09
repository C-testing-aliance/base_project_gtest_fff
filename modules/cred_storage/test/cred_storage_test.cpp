/**
 * @file
 * @brief Tests implementation
 * @defgroup cred_storage_test
 * @{
 */

extern "C" {
#include "cred_storage.c"
}

#include "./../../../libs/thirdparty/fff/fff.h"
#include <gtest/gtest.h>

DEFINE_FFF_GLOBALS;

FAKE_VALUE_FUNC(fs_ret_values, fs_write_string, const char*, const char*);
FAKE_VALUE_FUNC(int, fs_read, const char*, char*, short unsigned int);

class CredStorageTest : public ::testing::Test
{
  struct Parameters
  {
    credentials_t credentials{};
  };

protected:

  static constexpr const char* USERNAME = "Admin";
  static constexpr const char* PASSWORD = "very_strong_password";

  void SetUp()
  {
    strcpy(parameters.credentials.username, USERNAME);
    strcpy(parameters.credentials.password, PASSWORD);
    RESET_FAKE(fs_write_string);
    RESET_FAKE(fs_read);
    FFF_RESET_HISTORY();
  }

  void TearDown()
  {
    
  }

  Parameters parameters;
};

TEST_F(CredStorageTest, storeTest)
{
  char* expectedFileData = "Admin\r\nvery_strong_password";
  fs_write_string_fake.return_val = FS_RET_OK;
  cred_storage_ret_values res = cred_storage_save_credentials(&parameters.credentials);
  ASSERT_EQ(fs_write_string_fake.call_count, 1);
  ASSERT_EQ(strcmp(fs_write_string_fake.arg0_val, CREDENTIALS_FILENAME), 0);
  // !!! Not able to check this as the arg1_val is local var inside save_credentials
  //ASSERT_EQ(strcmp(fs_write_string_fake.arg1_val, expectedFileData), 0);
  EXPECT_EQ(CRED_ST_RET_OK, res);
  EXPECT_TRUE(0 == std::memcmp(&g_credentials, &parameters.credentials, sizeof(credentials_t)));
}

TEST_F(CredStorageTest, storeFsFailTest)
{
  char* expectedFileData = "Admin\r\nvery_strong_password";
  fs_write_string_fake.return_val = FS_RET_ERR;
  cred_storage_ret_values res = cred_storage_save_credentials(&parameters.credentials);
  ASSERT_EQ(fs_write_string_fake.call_count, 1);
  ASSERT_EQ(strcmp(fs_write_string_fake.arg0_val, CREDENTIALS_FILENAME), 0);
  // !!! Not able to check this as the arg1_val is local var inside save_credentials
  //ASSERT_EQ(strcmp(fs_write_string_fake.arg1_val, expectedFileData), 0);
  EXPECT_EQ(CRED_ST_RET_ERR, res);
  EXPECT_EQ(strlen(g_credentials.username), 0);
  EXPECT_EQ(strlen(g_credentials.password), 0);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

/** @} */