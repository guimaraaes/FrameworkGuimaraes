
#pragma once

#include "../Component.h"

#ifdef SYSTEM_TESTS_ENVIROMENT
#include "../UnitsBehaviors/HighLow.h"
#endif

class ActuatorDigital : public Component
{
public:
#ifdef SYSTEM_TESTS_ENVIROMENT
    HighLow *behavior;
#endif
    ActuatorDigital(int pin)
    {
#ifdef SYSTEM_TESTS_ENVIROMENT
        this->behavior = new HighLow(pin);
#endif
        this->pin = pin;
        pinMode(pin, OUTPUT);
    };

    void write(int value)
    {
        digitalWrite(this->pin, value);
        this->addHistory(this->pin, value);
    };

    void componentTest()
    {
        // Serial.println((String) "Begining component test to component in pin " + this->pin);
        Serial.println((String) "Iniciando teste de componente no pino " + this->pin);
        this->assertValue(HIGH);
        this->assertValue(LOW);
        Serial.println();
        Serial.println();
    }

    void assertValue(int value)
    {
        // Serial.println((String) "--- Verify if within 2 seconds component is during 10 second with the value " + value);
        Serial.println((String) "--- Verifique se em 2 segundos o componente está durante 10 segundos com o valor " + getValueString(value));
        delay(2000);
        // Serial.println("--- Component test result: you must assert. Wait to answer.");
        Serial.println("--- Resultado do teste de componente: você deve afirmar. Aguarde para responder.");
        this->write(value);
        delay(10000);
    }

    String getValueString(int value)
    {
        return (value == HIGH) ? "HIGH" : "LOW";
    }
};
