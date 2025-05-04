add_library(storm_extern INTERFACE)

add_library(storm::extern ALIAS storm_extern)

target_link_libraries(storm_extern 
    INTERFACE
        fmt::fmt
        spdlog::spdlog
        Microsoft.GSL::GSL
        doctest::doctest
)

target_compile_features(storm_extern INTERFACE cxx_std_23)

target_compile_definitions(storm_extern
    INTERFACE
        $<$<CONFIG:Debug>:STORM_DEBUG>
        $<$<CONFIG:Release>:DOCTEST_CONFIG_DISABLE>
)


add_subdirectory(core)
