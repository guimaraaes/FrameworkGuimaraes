#pragma once
#include "../Behavior.h"

class HighLow : public Behavior
{

    bool findElementInValue(int value)
    {
        Interaction *interaction = history->list.shift();

        bool interactionFound = this->isInteractionInValueAndInPin(interaction, value, this->pin);
        bool historyHasInteractions = history->list.size() > 0;

        while (!interactionFound && historyHasInteractions)
        {
            interaction = history->list.shift();
            interactionFound = this->isInteractionInValueAndInPin(interaction, value, this->pin);
            historyHasInteractions = history->list.size() > 0;
        }

        return interactionFound;
    }

    bool isInteractionInValueAndInPin(Interaction *interaction, int value, int pin)
    {
        bool interactionInValue = interaction->value == value;
        bool interactionInPin = interaction->pin == this->pin;
        return interactionInValue && interactionInPin;
    };

public:
    HighLow(int pin) : Behavior(pin){};

    bool raiseSensorHigh()
    {
        return this->findElementInValue(HIGH);
    };

    bool raiseSensorLow()
    {
        return this->findElementInValue(LOW);
    };

    bool isActuatorHigh()
    {
        Interaction *interaction = history->list.shift();
        return this->isInteractionInValueAndInPin(interaction, HIGH, this->pin);
    };

    bool isActuatorLow()
    {
        Interaction *interaction = history->list.shift();
        return this->isInteractionInValueAndInPin(interaction, LOW, this->pin);
    };
};
