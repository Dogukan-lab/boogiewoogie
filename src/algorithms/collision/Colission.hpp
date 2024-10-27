//
// Created by hmkam on 24/10/2024.
//

#ifndef COLISSION_HPP
#define COLISSION_HPP
#include <iostream>
#include <memory>

class Colission {
public:
    template<typename T, typename Y>
    bool doCollide(const T &a, const Y &b) {
        return (
            a.position.x <= b.position.x + b.shape.width &&
            a.position.x + a.shape.width >= b.position.x &&
            a.position.y <= b.position.y + b.shape.height &&
            a.position.y + a.shape.height >= b.position.y
        );
    }

    template<typename T, typename Y>
    bool doCollide(const std::shared_ptr<T> &a, const std::shared_ptr<Y> &b) {
        return doCollide(*a, *b);
    }

    template<typename T, typename Y>
    bool doCollide(const std::shared_ptr<T> &a, const Y &b) {
        return doCollide(*a, b);
    }

    template<typename T, typename Y>
    bool doCollide(const T &a, const std::shared_ptr<Y> &b) {
        return doCollide(a, *b);
    }
};


#endif //COLISSION_HPP
