//
// Created by doguk on 11/7/2024.
//

#ifndef BOOGIEWOOGIE_REDOSNAPSHOT_HPP
#define BOOGIEWOOGIE_REDOSNAPSHOT_HPP


#include "Action.hpp"

class RedoSnapshot : public Action {
public:
    void Execute() const override;
};


#endif //BOOGIEWOOGIE_REDOSNAPSHOT_HPP