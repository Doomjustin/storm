configure_file(config.cppm.in ${CMAKE_CURRENT_LIST_DIR}/config.cppm @ONLY)

add_library(storm_core STATIC)

add_library(storm::core ALIAS storm_core)

target_sources(storm_core
    PUBLIC FILE_SET CXX_MODULES
    FILES
        config.cppm
)

target_compile_features(storm_core
    INTERFACE cxx_std_20
    PRIVATE cxx_std_23
)

target_link_libraries(storm_core PUBLIC storm::extern)

target_set_warnings(storm_core ENABLE ALL AS_ERROR ALL DISABLE Annoying)


if (${PROJECT_NAME}_BUILD_TESTS)
    add_subdirectory(test)
endif ()
