//
// Created by doguk on 11/5/2024.
//

#include "include/Window.hpp"

Window::Window(const int width = 600, const int height = 600, const char *name, size_t extras = 0) {
    _properties = {
        .width = width,
        .height = height,
        .title = name,
        .extras =  extras
    };
}