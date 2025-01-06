#pragma once
#include "../Creator.h"
#include "../Component.h"
#include "../UnitsComponents/SensorUltrasonicCM.h"

class CreatorUltrasonic : public Creator
{
public:
    CreatorUltrasonic(){};
    Component *createComponent(int pinTrigger, int pinEcho)
    {
        return new SensorUltrasonicCM(4, 5);
    };
};