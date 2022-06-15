//
// Created by Beast GAMEING on 14.06.2022.
//

#ifndef VULKAN_TUT_LVE_PIPELINE_H
#define VULKAN_TUT_LVE_PIPELINE_H

#include "lve_device.hpp"

//std
#include <string>
#include <vector>

namespace lve {

    struct pipeline_config_info {

        VkViewport viewport;
        VkRect2D scissor;
        VkPipelineViewportStateCreateInfo viewport_info;
        VkPipelineInputAssemblyStateCreateInfo input_assembly_info;
        VkPipelineRasterizationStateCreateInfo rasterization_info;
        VkPipelineMultisampleStateCreateInfo multisample_info;
        VkPipelineColorBlendAttachmentState color_blend_attachment;
        VkPipelineColorBlendStateCreateInfo color_blend_info;
        VkPipelineDepthStencilStateCreateInfo depth_stencil_info;
        VkPipelineLayout pipeline_layout = 0;
        VkRenderPass  render_pass = 0;
        uint32_t subpass = 0;

        pipeline_config_info(pipeline_config_info const &) = delete;
        pipeline_config_info(pipeline_config_info &&) = delete;
        void operator=(pipeline_config_info const &) = delete;
        void operator=(pipeline_config_info &&) = delete;

        void init_default_pipeline_config_info(uint32_t width, uint32_t height, pipeline_config_info &config_info);

    };

    struct lve_pipeline {
    public:
        lve_pipeline(lve_Device &device,
                     std::string const &vert_filepath,
                     std::string const &frag_filepath,
                     pipeline_config_info const &configInfo);
        ~lve_pipeline();

        lve_pipeline(lve_pipeline const &) = delete;
        void operator=(lve_pipeline const &) = delete;

        static void init_default_pipeline_config_info(uint32_t width, uint32_t height, pipeline_config_info &config_info);

    private:
        static std::vector<char> read_file(std::string const &filepath);

        void create_graphics_pipeline(std::string const &vert_filepath,
                                      std::string const &frag_filepath,
                                      pipeline_config_info const &configInfo);


        void create_shader_module(std::vector<char> const &code, VkShaderModule *shader_module);

        lve_Device &lve_device;
        VkPipeline graphics_pipeline;
        VkShaderModule vertShaderModule;
        VkShaderModule fragShaderModule;
    };


}

#endif //VULKAN_TUT_LVE_PIPELINE_H
