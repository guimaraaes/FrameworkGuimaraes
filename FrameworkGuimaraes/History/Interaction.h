#pragma once

class Interaction
{

public:
    unsigned long time;
    int value;
    int pin;
    Interaction(){};
    Interaction(unsigned long time, int value, int pin)
    {
        this->time = time;
        this->value = value;
        this->pin = pin;
    };
};
Interaction *interaction;
