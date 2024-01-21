#pragma once
#include "../Behavior.h"

class Numeric : public Behavior
{
    int upperValue;
    int lowerValue;

    bool findInteractionInViVf(int Vi, int Vf)
    {
        Interaction *interaction = history->list.shift();

        bool interactionFound = this->isInteractionInViVfAndPin(interaction, Vi, Vf, this->pin);
        bool historyHasInteractions = history->list.size() > 0;

        while (!interactionFound && historyHasInteractions)
        {
            interaction = history->list.shift();
            interactionFound = this->isInteractionInViVfAndPin(interaction, Vi, Vf, this->pin);
            historyHasInteractions = history->list.size() > 0;
        }

        return interactionFound;
    }

    bool isInteractionInViVfAndPin(Interaction *interaction, int Vi, int Vf, int pin)
    {
        bool interactionInViVf = interaction->value >= Vi && interaction->value <= Vf;
        bool interactionInPin = interaction->pin == this->pin;
        return interactionInViVf && interactionInPin;
    }

public:
    Numeric(int pin, int upper, int lower) : Behavior(pin)
    {
        this->upperValue = upper;
        this->lowerValue = lower;
    }

    bool raiseSensorViVf(int Vi, int Vf)
    {
        return this->findInteractionInViVf(Vi, Vf);
    };

    bool isActuatorViVf(int Vi, int Vf)
    {
        Interaction *interaction = history->list.shift();
        return this->isInteractionInViVfAndPin(interaction, Vi, Vf, this->pin);
    };
};