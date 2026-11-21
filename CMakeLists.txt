cmake_minimum_required(VERSION 3.16)
project(cpp_ui_library LANGUAGES CXX)

find_package(SDL3 CONFIG QUIET)

if(NOT SDL3_FOUND)
    include(FetchContent)

    set(SDL_INSTALL OFF CACHE BOOL "" FORCE)
    set(SDL_SHARED ON CACHE BOOL "" FORCE)
    set(SDL_STATIC OFF CACHE BOOL "" FORCE)
    set(SDL_TESTS OFF CACHE BOOL "" FORCE)
    set(SDL_EXAMPLES OFF CACHE BOOL "" FORCE)

    FetchContent_Declare(SDL3
        URL https://github.com/libsdl-org/SDL/releases/download/release-3.4.20/SDL3-3.4.20.tar.gz
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
    )
    FetchContent_MakeAvailable(SDL3)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(cpp_ui_library SHARED
	src/compute/computeUi.cpp
	src/render/renderUi.cpp
	src/render/renderUtil.cpp
)

target_include_directories(cpp_ui_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_compile_features(cpp_ui_library PUBLIC cxx_std_17)

target_link_libraries(cpp_ui_library PRIVATE SDL3::SDL3)

