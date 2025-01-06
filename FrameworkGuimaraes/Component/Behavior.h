#pragma once
#include "../History/History.h"
#include "../History/Interaction.h"

class Behavior
{

public:
    int pin;
    History *history = History::getInstance();

    Behavior(int pin)
    {
        this->pin = pin;
    };
};
