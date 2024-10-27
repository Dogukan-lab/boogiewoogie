//
// Created by hmkam on 27/10/2024.
//

#include "AdjustBoxAtMousePointer.hpp"



void AdjustBoxAtMousePointer::Execute() const {
    auto [x, y] = mouseAndKeyboard->getMouseLocation();
    mapActionHandler->AdjustBox(x, y);
}