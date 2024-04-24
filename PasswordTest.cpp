/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PracticeTest : public ::testing::Test
{
	protected:
		PracticeTest(){} //constructor runs before each test
		virtual ~PracticeTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, double_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ZZ");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, digit_only_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("1");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, digit_and_character_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("1Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, endline_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("\n");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, double_endline_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("\n\n");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, sandwiched_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ZalsdfjlsjdfZ");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, case_test)
{
	Password my_password;
	int actual = my_password.has_mixed_case("aAa");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, endline_in_middle) {
	Password my_password;
	bool actual = my_password.has_mixed_case("A \n z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, only_one_case) {
	Password my_password;
	bool actual = my_password.has_mixed_case("zzzzzz");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, character) {
	Password my_password;
	bool actual = my_password.has_mixed_case("a##");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, authenticate) {
	Password my_password;
	my_password.set("newPassword");
	bool actual = my_password.authenticate("newPassword");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, using_old_password) {
	Password my_password;
	my_password.set("newPassword");
	my_password.set("newnewPassword");
	my_password.set("newPassword");
	bool actual = my_password.authenticate("newPassword");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, not_enough_char) {
	Password my_password;
	my_password.set("pw");
	bool actual = my_password.authenticate("pw");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, one_case_set) {
	Password my_password;
	my_password.set("password");
	bool actual = my_password.authenticate("password");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, only_symbols) {
	Password my_password;
	my_password.set("########");
	bool actual = my_password.authenticate("########");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, too_many_char) {
	Password my_password;
	my_password.set("abcdefghijklmnopqrstuvwxyz");
	bool actual = my_password.authenticate("abcdefghijklmnopqrstuvwxyz");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, 4_leading_char) {
	Password my_password;
	my_password.set("aaaaBcdef");
	bool actual = my_password.authenticate("aaaaBcdef");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, 2_leading_char) {
	Password my_password;
	my_password.set("aaBcdefg");
	bool actual = my_password.authenticate("aaBcdefg");
	ASSERT_EQ(1, actual);
}