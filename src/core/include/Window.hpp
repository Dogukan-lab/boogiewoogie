//
// Created by doguk on 11/5/2024.
//

#ifndef WINDOW_HPP
#define WINDOW_HPP

class Window {
public:
    explicit Window(int width, int height, const char* name);


    ~Window() = default;

private:
    struct WindowProperties {
        int width{};
        int height{};
        const char* title{};
        unsigned int extras{};
    };

    WindowProperties _properties;

};



#endif //WINDOW_HPP