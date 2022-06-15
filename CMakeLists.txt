cmake_minimum_required(VERSION 3.21)


set(Recipe_Name vulkan_tut)
set(CMAKE_CXX_STANDARD 20)
project(${Recipe_Name})



find_package(glm REQUIRED)
find_package(glfw3 3.3 REQUIRED)
find_package(Vulkan REQUIRED PATH F:/Tools/VulkanSDK)

file(GLOB_RECURSE CPP_FILES ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp)
#file(GLOB_RECURSE HPP_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/*.*)

add_executable(${Recipe_Name} ${CPP_FILES})

set(VULKAN_SDK "F:/Tools/VulkanSDK")
set(VULKAN_VERSION "1.3.211.0")
set(VULKAN_PATH "${VULKAN_SDK}")
SET(HEBBO 3)

target_link_libraries(${Recipe_Name} glm::glm)
target_link_libraries(${Recipe_Name} glfw)
target_link_libraries(${Recipe_Name} F:/Tools/VulkanSDK/Lib32/vulkan-1.lib)

target_include_directories(${Recipe_Name} PRIVATE F:/Tools/VulkanSDK/Include ./include)


target_compile_options(${Recipe_Name} PRIVATE /W4)

# Define project properties
set_property(TARGET ${Recipe_Name} PROPERTY RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/binaries)
set_property(TARGET ${Recipe_Name} PROPERTY RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/binaries)
set_property(TARGET ${Recipe_Name} PROPERTY RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/binaries)
set_property(TARGET ${Recipe_Name} PROPERTY RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL ${CMAKE_CURRENT_SOURCE_DIR}/binaries)
set_property(TARGET ${Recipe_Name} PROPERTY RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${CMAKE_CURRENT_SOURCE_DIR}/binaries)