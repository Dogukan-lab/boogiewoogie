//
// Created by doguk on 11/5/2024.
//

#ifndef WINDOW_HPP
#define WINDOW_HPP

class Window {
public:
    explicit Window(int width, int height, const char* name, size_t extras);


    ~Window() = default;

private:
    struct WindowProperties {
        int width{};
        int height{};
        size_t extras{};
        const char* title{};
    };

    WindowProperties _properties;

};



#endif //WINDOW_HPP