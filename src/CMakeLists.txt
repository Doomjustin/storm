add_library(storm_base INTERFACE)

add_library(storm::base ALIAS storm_base)

target_link_libraries(storm_base INTERFACE base)

target_include_directories(storm_base INTERFACE ${PROJECT_SOURCE_DIR}/include/)

target_compile_features(storm_base INTERFACE cxx_std_23)

target_compile_definitions(storm_base 
    INTERFACE
        $<$<CONFIG:Debug>:STORM_SPIRIT_DEBUG>
)


configure_file(config.h.in ${PROJECT_SOURCE_DIR}/include/storm/config.h @ONLY)
