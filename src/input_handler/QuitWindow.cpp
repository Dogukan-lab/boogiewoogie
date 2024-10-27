//
// Created by doguk on 10/27/2024.
//

#include "QuitWindow.hpp"

#include <BoogieWoogieApp.hpp>

void QuitWindow::Execute() const {
    BoogieWoogieApp::GetInstance().isRunning = false;
}
