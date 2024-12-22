#pragma once
#include "../Behavior.h"
#include "../SearchType.h"

class Numeric : public Behavior
{
private:
    int upperValue;
    int lowerValue;

    bool findInteractionInValue(int value, int precision)
    {
        Interaction *interaction = history->list.shift();

        bool interactionFound = this->isInteractionInValue(interaction, value, precision);
        bool historyHasInteractions = history->list.size() > 0;

        while (!interactionFound && historyHasInteractions)
        {
            interaction = history->list.shift();
            interactionFound = this->isInteractionInValue(interaction, value, precision);
            historyHasInteractions = history->list.size() > 0;
        }

        return interactionFound;
    }

    bool isInteractionInValue(Interaction *interaction, int value, int precision)
    {
        int maxValue = value + precision;
        int minValue = value - precision;

        bool interactionInValue = interaction->value >= minValue && interaction->value <= maxValue;
        bool interactionInPin = interaction->pin == this->pin;
        return interactionInValue && interactionInPin;
    }

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

    int getUpperValue()
    {
        return this->upperValue;
    }

    int getLowerValue()
    {
        return this->lowerValue;
    }

    bool isComponentInValue(int value, int precision, SearchType searchType)
    {
        if (searchType == SearchType::NEXT)
        {
            Interaction *interaction = history->list.shift();
            return this->isInteractionInValue(interaction, value, precision);
        }

        return this->findInteractionInValue(value, precision);
    };

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