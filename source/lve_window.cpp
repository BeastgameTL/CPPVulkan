//
// Created by Beast GAMEING on 14.06.2022.
//

#include "lve_window.hpp"

//std
#include <stdexcept>

namespace lve {

    lve_window::lve_window(int w, int h, const std::string &name)
    : width{w}
    , height{h}
    , window_name{name}
    {
        initWindow();
    }

    lve_window::~lve_window() {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void lve_window::initWindow() {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, false);

        window = glfwCreateWindow(width, height, window_name.c_str(), nullptr, nullptr);
    }

    void lve_window::createWindowSurface(VkInstance instance, VkSurfaceKHR *surface) {
        if(glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS) {
            throw std::runtime_error("Failed to create window surface");
        }
    }

}

