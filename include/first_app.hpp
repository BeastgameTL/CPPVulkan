//
// Created by Beast GAMEING on 14.06.2022.
//

#ifndef VULKAN_TUT_FIRST_APP_HPP
#define VULKAN_TUT_FIRST_APP_HPP

#include "lve_window.hpp"
#include "lve_pipeline.hpp"
#include "lve_device.hpp"

namespace lve {
    struct first_app {
    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 800;
        void run();

        first_app();

    private:
        lve_window window{WIDTH, HEIGHT, "Hebbo Vulkan!"};
        lve_Device device{window};
        lve_pipeline pipeline;

    };
}


#endif //VULKAN_TUT_FIRST_APP_HPP
