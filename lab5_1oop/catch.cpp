#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "FloatPower.cpp"
#include "FloatPower.hpp"

TEST_CASE( "Arguments initialized") {
    FloatPower a;
    a.SetSecond(5);
    float b = a.GetSecond();
    float c = 5;
    REQUIRE( b == c);
}
