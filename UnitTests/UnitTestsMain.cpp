#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>

TEST_CASE("Stupid nullptr chack", "[irrilavnt information)")
{
	int* number = nullptr;
	REQUIRE(number == nullptr);
}