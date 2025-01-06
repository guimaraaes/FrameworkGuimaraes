#pragma once
#include "../Component.h"

#ifdef SYSTEM_TESTS_ENVIROMENT
#include "../UnitsBehaviors/HighLow.h"
#endif

class SensorDigital : public Component
{
public:
#ifdef SYSTEM_TESTS_ENVIROMENT
    HighLow *behavior;
#endif
    SensorDigital(int pin)
    {
        this->pin = pin;
#ifdef SYSTEM_TESTS_ENVIROMENT
        this->behavior = new HighLow(pin);
#endif
        pinMode(pin, INPUT);
    };

    int read()
    {
        int value = digitalRead(this->pin);
        Serial.println((String) "--- Value readed: " + (int)value);
        this->addHistory(this->pin, value);
        return value;
    };

    void componentTest()
    {
        Serial.println((String) "Begining component test to component in pin " + this->pin);
        this->assertValue(1);
        this->assertValue(0);
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
