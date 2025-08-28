#pragma once
#include "../Astra.hpp"

struct GLFWwindow;

class Application
{
public:
     Application(const char *title, int width, int height);

     ~Application() noexcept;

     Application(const Application &) = delete;
     Application &operator=(const Application &) = delete;

     void run();

private:
     GLFWwindow *window = nullptr;
};