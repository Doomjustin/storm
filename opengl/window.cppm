module;

#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>

#include <cstdlib>
#include <stdexcept>
#include <string_view>

export module opengl.window;

import opengl.config;

using namespace std;

namespace opengl {

struct GlfwInitializer {
    static auto error_callback(int error, const char* description)
    {
        spdlog::error("Error: {}", description);
    }

    GlfwInitializer(int major, int minor)
    {
        glfwSetErrorCallback(error_callback);

        if (!glfwInit())
            throw runtime_error("Failed to initialize GLFW3");

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

        spdlog::info("Initialized. OpenGL version: {}.{}.", OPENGL_VERSION_MAJOR, OPENGL_VERSION_MINOR);
    }

    GlfwInitializer(const GlfwInitializer&) = delete;
    GlfwInitializer& operator=(const GlfwInitializer&) = delete;

    GlfwInitializer(GlfwInitializer&& other) noexcept = default;
    GlfwInitializer& operator=(GlfwInitializer&& other) noexcept = default;

    ~GlfwInitializer()
    {
        glfwTerminate();
        spdlog::info("Terminated.");
    }
};


export
class Window {
private:
    static GlfwInitializer initializer;

    GLFWwindow* window_;

    static auto key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        spdlog::trace("Key pressed: {}", key);
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
            glfwSetWindowShouldClose(window, GLFW_TRUE);
    }

    static auto framebuffer_size_callback(GLFWwindow* window, int width, int height)
    {
        spdlog::trace("Framebuffer size: {}x{}", width, height);
        glViewport(0, 0, width, height);
    }

    static auto clear_view()
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }

public:
    Window(int width, int height, const string_view title)
    {
        window_ = glfwCreateWindow(width, height, title.data(), nullptr, nullptr);
        if (!window_) {
            spdlog::error("Failed to create GLFW window.");
            throw runtime_error("Failed to create window.");
        }

        glfwSetFramebufferSizeCallback(window_, framebuffer_size_callback);
        glfwSetKeyCallback(window_, key_callback);

        glfwMakeContextCurrent(window_);
        gladLoadGL(glfwGetProcAddress);
        glfwSwapInterval(1);

        spdlog::info("Created window.");
    }

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    Window(Window&& other) noexcept = default;
    Window& operator=(Window&& other) noexcept = default;

    ~Window()
    {
        glfwDestroyWindow(window_);
        spdlog::info("Destroyed window.");
    }

    auto run() const noexcept
    {
        while (!glfwWindowShouldClose(window_)) {
            clear_view();

            glfwSwapBuffers(window_);
            glfwPollEvents();
        }

        return EXIT_SUCCESS;
    }
};

GlfwInitializer Window::initializer{ OPENGL_VERSION_MAJOR, OPENGL_VERSION_MINOR };

}
