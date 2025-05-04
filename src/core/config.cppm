module;

#include <doctest/doctest.h>

export module storm.config;

export
namespace storm {

constexpr auto PROJECT_VERSION = "0.0.1";

constexpr int PROJECT_MAJOR = 0;

constexpr int PROJECT_MINOR = 0;

constexpr int PROJECT_PATCH = 1;

constexpr auto PROJECT_NAME = "STORM";

constexpr auto PROJECT_SOURCE_DIR = "E:/storm";

constexpr auto RESOURCE_DIR = "E:/storm/src/resource";

} // namespace storm


TEST_CASE("test version")
{
    REQUIRE(storm::PROJECT_VERSION == "0.0.1");
}
