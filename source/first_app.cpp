//
// Created by Beast GAMEING on 14.06.2022.
//

#include "first_app.hpp"

namespace lve {
    void first_app::run() {
        while (!window.should_close()) {
            glfwPollEvents();
        }
    }

    first_app::first_app() {
        lve_pipeline::init_default_pipeline_config_info(WIDTH, HEIGHT, this->)
        device,
                "artifacts/shader/simple_shader.vert.spv",
                "artifacts/shader/simple_shader.frag.spv",
                init_default_pipeline_config_info(WIDTH, HEIGHT)}
    }
}