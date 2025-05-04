cmake_minimum_required(VERSION 3.30)

project(STORM
    VERSION 0.0.1
    LANGUAGES C CXX
)

include(CTest)
include(CMakeDependentOption)

cmake_dependent_option(${PROJECT_NAME}_BUILD_TESTS
    "Enable ${PROJECT_NAME} project tests targets" ON
    "BUILD_TESTING" OFF
)

set(CMAKE_POSITION_INDEPENDENT_CODE TRUE)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)
include(ConfigSafeGuards)
include(Colors)
include(LTO)
include(CopyDllsForDebug)
include(Warnings)
include(InstallFmt)
include(InstallSpdlog)
include(InstallGSL)
include(InstallDoctest)
include(InstallPybind11)
include(InstallGLFW)
add_subdirectory(extern)

find_lto(CXX)

add_subdirectory(src)
add_subdirectory(opengl)
