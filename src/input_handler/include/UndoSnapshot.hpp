//
// Created by hmkam on 07/11/2024.
//

#ifndef UNDOSNAPSHOT_HPP
#define UNDOSNAPSHOT_HPP
#include "Action.hpp"


class UndoSnapshot : public Action{
public:
    void Execute() const override;
};



#endif //UNDOSNAPSHOT_HPP