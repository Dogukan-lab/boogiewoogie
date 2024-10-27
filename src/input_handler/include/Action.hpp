//
// Created by hmkam on 27/10/2024.
//

#ifndef ACTION_HPP
#define ACTION_HPP

/**
 * The Command interface
 */
class Action {
public:
    virtual ~Action() = default;

    virtual void Execute() const = 0;
};


#endif //ACTION_HPP
