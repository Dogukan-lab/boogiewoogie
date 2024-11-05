//
// Created by doguk on 11/5/2024.
//

#include "include/Window.hpp"

Window::Window(const int width, const int height, const char *name = "BoogieWoogie") {
    _properties = {
        .width = width,
        .height = height,
        .title = name,
        .extras = 0
    };
}