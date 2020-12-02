#define CATCH_CONFIG_MAIN
#include <string>
#include "catch.hpp"
#include "activity.h"

TEST_CASE("testing balancedBrackets", "[balancedBrackets]") {
	REQUIRE(balancedBrackets("") == true);
	REQUIRE(balancedBrackets("(7)") == true);
	REQUIRE(balancedBrackets("[]{}()([]{})") == true);
	REQUIRE(balancedBrackets("[({(([[{}][{}][{}]]))})]") == true);

	REQUIRE(balancedBrackets("{") == false);
	REQUIRE(balancedBrackets("]({})") == false);
	REQUIRE(balancedBrackets("((((") == false);
	REQUIRE(balancedBrackets("))))") == false);
	REQUIRE(balancedBrackets("(]{)[}") == false);
	REQUIRE(balancedBrackets("[]{}()[]{})([])") == false);
	REQUIRE(balancedBrackets("[[({(([[{}][{}][{}]]))})]") == false);
}
