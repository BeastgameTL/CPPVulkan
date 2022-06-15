//
// Created by Beast GAMEING on 14.06.2022.
//

#ifndef VULKAN_LVE_WINDOW_HPP
#define VULKAN_LVE_WINDOW_HPP

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <string>
#include <memory>


namespace lve {

    struct lve_window {
    private:
        void initWindow();

        int const width;
        int const height;

        std::string window_name;
        GLFWwindow *window;

    public:
        lve_window(int w, int h, std::string const &name);
        ~lve_window();

        lve_window(lve_window const &) = delete;
        lve_window &operator=(lve_window const &) = delete;

        inline bool should_close() {
            return glfwWindowShouldClose(window);
        }

        void createWindowSurface(VkInstance instance, VkSurfaceKHR *surface);
    };

}

#endif //VULKAN_LVE_WINDOW_HPP


