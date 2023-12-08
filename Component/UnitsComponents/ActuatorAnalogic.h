#pragma once
#include "../Component.h"

#ifdef SYSTEM_TESTS_ENVIROMENT
#include "../UnitsBehaviors/Numeric.h"
#endif

class ActuatorAnalogic : public Component
{
public:
#ifdef SYSTEM_TESTS_ENVIROMENT
    Numeric *behavior;
#endif

    ActuatorAnalogic(uint8_t pin)
    {
        this->pin = pin;
#ifdef SYSTEM_TESTS_ENVIROMENT
        this->behavior = new Numeric(pin, 0, 1023);
#endif
        pinMode(pin, OUTPUT);
    };

    void write(int value)
    {
        analogWrite(this->pin, value);
        this->addHistory(this->pin, value);
    };

    void componentTest()
    {
        Serial.println((String) "Begining component test to component in pin " + this->pin);
        this->assertValue(0);
        this->assertValue(500);
        this->assertValue(1023);
        Serial.println();
        Serial.println();
    }

    void assertValue(int value)
    {
        Serial.println((String) "--- Verify if within 2 seconds component is during 5 second with the value " + value);
        delay(2000);
        Serial.println("--- Component test result: you must assert. Wait to answer.");
        this->write(value);
        delay(5000);
    }
};