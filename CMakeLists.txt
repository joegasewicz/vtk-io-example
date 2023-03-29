cmake_minimum_required(VERSION 3.23)
project(vtk_demo1)

set(CMAKE_CXX_STANDARD 17)

find_package(VTK COMPONENTS
        CommonColor
        CommonCore
        CommonDataModel
        FiltersSources
        InteractionStyle
        IOLegacy
        RenderingContextOpenGL2
        RenderingCore
        RenderingFreeType
        RenderingGL2PSOpenGL2
        RenderingOpenGL2
        )


if (NOT VTK_FOUND)
    message(FATAL_ERROR "vtk_demo1: Unable to find the VTK build folder.")
endif()

add_executable(vtk_demo1 main.cpp)

target_link_libraries(vtk_demo1 ${VTK_LIBRARIES})
