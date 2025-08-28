#include <stdexcept>

#include "../../include/Astra.hpp"
#include "../../include/core/Application.hpp"

Application::Application(const char *title, int width, int height)
{
    if (!glfwInit())
    {
        throw std::runtime_error("ERROR: Failed to initialize GLFW");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        throw std::runtime_error("ERROR: Failed to create GLFW window");
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
    {
        throw std::runtime_error("ERROR: Failed to initialize GLAD");
    }

    glfwSwapInterval(0);
    glViewport(0, 0, width, height);
}

Application::~Application() noexcept
{
    if (window)
    {
        glfwDestroyWindow(window);
    }
    glfwTerminate();
}

void Application::run()
{
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        // Redering in line

        glfwSwapBuffers(window);
        glfwPollEvents();

        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        {
            glfwSetWindowShouldClose(window, true);
        }
    }
}