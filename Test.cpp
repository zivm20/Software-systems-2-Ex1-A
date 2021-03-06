/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: Ziv Morgan
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Good input") {
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
													 "@-------@\n"
													 "@-@@@@@-@\n"
													 "@-@---@-@\n"
													 "@-@@@@@-@\n"
													 "@-------@\n"
													 "@@@@@@@@@"));

	CHECK(nospaces(mat(13, 5, '@', '-')) == nospaces("@@@@@@@@@@@@@\n"
													"@-----------@\n"
													"@-@@@@@@@@@-@\n"
													"@-----------@\n"
													"@@@@@@@@@@@@@\n"));

	CHECK(nospaces(mat(1, 5, '@', '-')) == nospaces("@\n"
													"@\n"
													"@\n"
													"@\n"
													"@\n"));

	CHECK(nospaces(mat(5, 1, '@', '-')) == nospaces("@@@@@\n"));

	CHECK(nospaces(mat(1, 1, '@', '-')) == nospaces("@\n"));

	CHECK(nospaces(mat(5, 5, '@', '-')) == nospaces("@@@@@\n"
													"@---@\n"
													"@-@-@\n"
													"@---@\n"
													"@@@@@\n"));

	CHECK(nospaces(mat(3, 15, '@', '-')) == nospaces("@@@\n"
													"@-@\n"
													"@-@\n"
													"@-@\n"
													"@-@\n"
													"@-@\n"
													"@-@\n"
													"@-@\n"
													"@-@\n"
													"@-@\n"
													"@-@\n"
													"@-@\n"
													"@-@\n"
													"@-@\n"
													"@@@\n"));

	CHECK(nospaces(mat(15, 3, '@', '-')) == nospaces("@@@@@@@@@@@@@@@\n"
													"@-------------@\n"
													"@@@@@@@@@@@@@@@\n"));

	CHECK(nospaces(mat(15, 9, '@', '-')) == nospaces("@@@@@@@@@@@@@@@\n"
													"@-------------@\n"
													"@-@@@@@@@@@@@-@\n"
													"@-@---------@-@\n"
													"@-@-@@@@@@@-@-@\n"
													"@-@---------@-@\n"
													"@-@@@@@@@@@@@-@\n"
													"@-------------@\n"
													"@@@@@@@@@@@@@@@\n"));

	CHECK(nospaces(mat(9, 15, '@', '-')) == nospaces("@@@@@@@@@\n"
													"@-------@\n"
													"@-@@@@@-@\n"
													"@-@---@-@\n"
													"@-@-@-@-@\n"
													"@-@-@-@-@\n"
													"@-@-@-@-@\n"
													"@-@-@-@-@\n"
													"@-@-@-@-@\n"
													"@-@-@-@-@\n"
													"@-@-@-@-@\n"
													"@-@---@-@\n"
													"@-@@@@@-@\n"
													"@-------@\n"
													"@@@@@@@@@\n"));

	CHECK(nospaces(mat(13, 5, '&', '-')) == nospaces("&&&&&&&&&&&&&\n"
													"&-----------&\n"
													"&-&&&&&&&&&-&\n"
													"&-----------&\n"
													"&&&&&&&&&&&&&\n"));

	CHECK(nospaces(mat(13, 5, '@', '.')) == nospaces("@@@@@@@@@@@@@\n"
													"@...........@\n"
													"@.@@@@@@@@@.@\n"
													"@...........@\n"
													"@@@@@@@@@@@@@\n"));

	CHECK(nospaces(mat(13, 5, '=', '.')) == nospaces("=============\n"
													"=...........=\n"
													"=.=========.=\n"
													"=...........=\n"
													"=============\n"));

	CHECK(nospaces(mat(13, 5, '=', '=')) == nospaces("=============\n"
													"=============\n"
													"=============\n"
													"=============\n"
													"=============\n"));
}







TEST_CASE("Even numbers") {
    CHECK_THROWS(mat(10, 5, '$', '%'));
	CHECK_THROWS(mat(10, 6, '$', '%'));
	CHECK_THROWS(mat(9, 6, '$', '%'));
}

TEST_CASE("Negative numbers") {
	CHECK_THROWS(mat(9, -5, '$', '%'));
	CHECK_THROWS(mat(-9, 5, '$', '%'));
	CHECK_THROWS(mat(-9, -5, '$', '%'));
}

TEST_CASE("Negative and even numbers mix") {
	CHECK_THROWS(mat(10, -5, '$', '%'));
	CHECK_THROWS(mat(-10, 5, '$', '%'));
	CHECK_THROWS(mat(-10, -5, '$', '%'));
	
	CHECK_THROWS(mat(9, -6, '$', '%'));
	CHECK_THROWS(mat(-9, 6, '$', '%'));
	CHECK_THROWS(mat(-9, -6, '$', '%'));
	
	CHECK_THROWS(mat(10, -6, '$', '%'));
	CHECK_THROWS(mat(-10, 6, '$', '%'));
	CHECK_THROWS(mat(-10, -6, '$', '%'));
}

TEST_CASE("Invalid Characters") {
	CHECK_THROWS(mat(9, 5, '\r', '%'));
	CHECK_THROWS(mat(9, 5, '\t', '%'));
	CHECK_THROWS(mat(9, 5, '\n', '%'));
	CHECK_THROWS(mat(9, 5, ' ', '%'));

	CHECK_THROWS(mat(9, 5, '%', '\r'));
	CHECK_THROWS(mat(9, 5, '%', '\t'));
	CHECK_THROWS(mat(9, 5, '%', '\n'));
	CHECK_THROWS(mat(9, 5, '%', ' '));

	CHECK_THROWS(mat(9, 5, ' ', ' '));
    
}



