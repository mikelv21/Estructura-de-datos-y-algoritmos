#define CATCH_CONFIG_MAIN
#include <string>
#include "catch.hpp"
#include "activity.h"

TEST_CASE("testing convertInfixToPostfix", "[convertInfixToPostfix]") {
	REQUIRE("42" == convertInfixToPostfix("42"));
	REQUIRE("1 2 +" == convertInfixToPostfix("(1 + 2)"));
	REQUIRE("1 2 * 3 +" == convertInfixToPostfix("1 * 2 + 3"));
	REQUIRE("1 2 + 3 + 4 +" == convertInfixToPostfix("1 + 2 + 3 + 4"));
	REQUIRE("1 2 +" == convertInfixToPostfix("(1 + 2)"));
	REQUIRE("1 2 3 4 + + +" == convertInfixToPostfix("(1 + (2 + (3 + 4)))"));
	REQUIRE("1 2 3 * +" == convertInfixToPostfix("1 + 2 * 3"));
	REQUIRE("1 2 + 3 *" == convertInfixToPostfix("(1 + 2) * 3"));
	REQUIRE("1 2 3 * + 4 +" == convertInfixToPostfix("1 + 2 * 3 + 4"));
	REQUIRE("1 2 + 3 4 + *" == convertInfixToPostfix("(1 + 2) * (3 + 4)"));
	REQUIRE("1 2 + 3 4 * 5 / -" == convertInfixToPostfix("1 + 2 - 3 * 4 / 5"));
	REQUIRE("1 2 / 3 * 4 - 5 +" == convertInfixToPostfix("1 / 2 * 3 - 4 + 5"));
	REQUIRE("1 2 / 3 4 * - 5 +" == convertInfixToPostfix("1 / 2 - 3 * 4 + 5"));
	REQUIRE("1 2 3 - + 4 5 / *" == convertInfixToPostfix("(1 + (2 - 3)) * (4 / 5)"));
	REQUIRE("1 2 3 - / 4 5 + *" == convertInfixToPostfix("1 / (2 - 3) * (4 + 5)"));
	REQUIRE("1 2 3 - 4 5 + * /" == convertInfixToPostfix("1 / ((2 - 3) * (4 + 5))"));
	REQUIRE("1 2 3 4 * - 5 + /" == convertInfixToPostfix("1 / (2 - 3 * 4 + 5)"));
	REQUIRE("42" == convertInfixToPostfix("(42)"));
	REQUIRE("42" == convertInfixToPostfix("(((42)))"));
	REQUIRE("1 2 +" == convertInfixToPostfix("(1 + 2)"));
	REQUIRE("1 2 *" == convertInfixToPostfix("(((1) * (2)))"));
}
