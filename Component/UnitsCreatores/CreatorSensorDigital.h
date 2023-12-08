#pragma once
#include "../Creator.h"
#include "../Component.h"
#include "../UnitsComponents/SensorDigital.h"

class CreatorSensorDigital : public Creator
{
public:
    CreatorSensorDigital(){};
    Component *createComponent(int pin)
    {
        return new SensorDigital(pin);
    };
};
