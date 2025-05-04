set(OPENGL_VERSION_MAJOR 4)
set(OPENGL_VERSION_MINOR 6)

configure_file(config.cppm.in ${CMAKE_CURRENT_LIST_DIR}/config.cppm @ONLY)


add_library(storm_opengl)
add_library(storm::opengl ALIAS storm_opengl)

target_sources(storm_opengl
    PUBLIC FILE_SET CXX_MODULES
    FILES
        config.cppm
        window.cppm
        render.cppm
)

target_compile_features(storm_opengl PRIVATE cxx_std_23)

target_link_libraries(storm_opengl
    PUBLIC
        storm::core
        glfw
        glad::glad
)


add_executable(opengl main.cpp)
target_link_libraries(opengl PRIVATE storm::opengl)
