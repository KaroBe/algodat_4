/*

Karoline Brehm
117190

SS2017

Algorithmen und Datenstrukturen - Beleg 3

*/

#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

#include "algodat_3_tests.cpp"

TEST_CASE ("read_input test", "aufg_3")
{
	std::string one = read_input("123");
	REQUIRE(one == "123");
}

