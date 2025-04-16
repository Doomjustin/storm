cmake_minimum_required(VERSION 3.29)

project(STORM
    VERSION 0.0.1
    LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API ON)

include(CTest)
include(CMakeDependentOption)

cmake_dependent_option(${PROJECT_NAME}_BUILD_TESTS
    "Enable ${PROJECT_NAME} project tests targets" ON
    "BUILD_TESTING" OFF
)

set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)
include(ConfigSafeGuards)
include(Colors)
include(Warnings)
include(LTO)
include(Coverage)
include(CopyDllsForDebug)

find_lto(CXX)


add_subdirectory(third-party EXCLUDE_FROM_ALL)

add_subdirectory(app)
add_subdirectory(src)

if(${PROJECT_NAME}_BUILD_TESTS)
    set(TEST_RUNNER_PARAMS "--force-colors=true" CACHE STRING "Options to add to our test runners commands")
    list(APPEND CUSTOM_COVERAGE_EXCLUDE "/test/")
    add_subdirectory(test)

    configure_file(
        ${CMAKE_CURRENT_LIST_DIR}/cmake/CTestCustom.cmake.in
        ${CMAKE_CURRENT_BINARY_DIR}/CTestCustom.cmake
        @ONLY
    )
endif()
