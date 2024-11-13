#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
protected:
    PasswordTest() {} // Constructor runs before each test
    virtual ~PasswordTest() {} // Destructor cleans up after tests
    virtual void SetUp() {} // Sets up before each test (after constructor)
    virtual void TearDown() {} // Clean up after each test, (before destructor)
};

// Test for count_leading_characters
TEST(PasswordTest, single_letter_password) {
    Password my_password;
    int actual = my_password.count_leading_characters("Z");
    ASSERT_EQ(1, actual);
}

TEST(PasswordTest, multiple_leading_characters) {
    Password my_password;
    int actual = my_password.count_leading_characters("AAAxyz");
    ASSERT_EQ(3, actual);
}

TEST(PasswordTest, no_repeating_leading_characters) {
    Password my_password;
    int actual = my_password.count_leading_characters("ABCD");
    ASSERT_EQ(1, actual);
}

TEST(PasswordTest, empty_string) {
    Password my_password;
    int actual = my_password.count_leading_characters("");
    ASSERT_EQ(0, actual);
}

TEST(PasswordTest, all_same_characters) {
    Password my_password;
    int actual = my_password.count_leading_characters("BBBBB");
    ASSERT_EQ(5, actual);
}

// Test for has_mixed_case
TEST(PasswordTest, mixed_case_password) {
    Password my_password;
    ASSERT_TRUE(my_password.has_mixed_case("Password123"));
    ASSERT_TRUE(my_password.has_mixed_case("helloWORLD"));
}

TEST(PasswordTest, all_lowercase_password) {
    Password my_password;
    ASSERT_FALSE(my_password.has_mixed_case("alllowercase"));
}

TEST(PasswordTest, all_uppercase_password) {
    Password my_password;
    ASSERT_FALSE(my_password.has_mixed_case("ALLUPPERCASE"));
}

TEST(PasswordTest, no_letters) {
    Password my_password;
    ASSERT_FALSE(my_password.has_mixed_case("123456"));
}

TEST(PasswordTest, mixed_case_with_symbols) {
    Password my_password;
    ASSERT_TRUE(my_password.has_mixed_case("Mix3d_C@s3"));
}

