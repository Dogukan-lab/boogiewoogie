//
// Created by hmkam on 09/10/2024.
//

#ifndef BUILDER_HPP
#define BUILDER_HPP

template<typename T>
class Builder {
public:
    virtual ~Builder() = default;
    virtual T&& build() = 0;
};

#endif //BUILDER_HPP
