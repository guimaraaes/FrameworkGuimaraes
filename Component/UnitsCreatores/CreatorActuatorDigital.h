#pragma once
#include "../Creator.h"
#include "../Component.h"
#include "../UnitsComponents/ActuatorDigital.h"

class CreatorActuatorDigital : public Creator
{
public:
    CreatorActuatorDigital(){};
    Component *createComponent(int pin)
    {
        return new ActuatorDigital(pin);
    };
};
