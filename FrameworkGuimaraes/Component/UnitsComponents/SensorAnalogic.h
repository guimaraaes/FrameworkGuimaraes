#pragma once
#include "../Component.h"

#ifdef SYSTEM_TESTS_ENVIROMENT
#include "../UnitsBehaviors/Numeric.h"
#endif
class SensorAnalogic : public Component
{
public:
#ifdef SYSTEM_TESTS_ENVIROMENT
    Numeric *behavior;
#endif
    SensorAnalogic(uint8_t pin)
    {
        this->pin = pin;
#ifdef SYSTEM_TESTS_ENVIROMENT
        this->behavior = new Numeric(pin, 0, 1023);
#endif
        pinMode(pin, INPUT);
    };

    int read()
    {
        int value = analogRead(this->pin);
        Serial.println((String) "--- Value readed: " + (int)value);
        this->addHistory(this->pin, value);
        return value;
    };

    void unitTest()
    {
        Serial.println((String) "Begining unit test to component in pin " + this->pin);
        this->assertValue(0);
        this->assertValue(500);
        this->assertValue(1023);
        Serial.println();
        Serial.println();
    }

    void assertValue(int value)
    {

        Serial.println((String) "--- Put within 5 seconds component with the value " + value);
        delay(5000);
        int valueReaded = this->read();
        Serial.println("--- Component test result: you must assert. Wait to answer.");
        delay(2000);
        Serial.println((String) "---- Value expected" + value);
        Serial.println((String) "---- Value readed" + valueReaded);
        delay(2000);
    }
};