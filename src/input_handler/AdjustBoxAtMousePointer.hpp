//
// Created by hmkam on 27/10/2024.
//

#ifndef ADJUSTBOXATMOUSEPOINTER_HPP
#define ADJUSTBOXATMOUSEPOINTER_HPP
#include "Action.hpp"
#include "MouseAndKeyboard.hpp"
#include "../../MapActionHandler.hpp"


class AdjustBoxAtMousePointer : public Action {
public:
    AdjustBoxAtMousePointer(MouseAndKeyboard *mouse, MapActionHandler *mapHandler) : mouseAndKeyboard(mouse),
        mapActionHandler(mapHandler) {}

    ~AdjustBoxAtMousePointer() override {
        delete mouseAndKeyboard;
        delete mapActionHandler;
    }

    void Execute() const override;

private:
    MouseAndKeyboard *mouseAndKeyboard;
    MapActionHandler *mapActionHandler;
};

#endif //ADJUSTBOXATMOUSEPOINTER_HPP
