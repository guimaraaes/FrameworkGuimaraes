#pragma once
#include "../lib/LinkedList/LinkedList.h"
#include "Interaction.h"

class History
{
protected:
    History()
    {
        list = LinkedList<Interaction *>();
    }
    static History *history_;

public:
    LinkedList<Interaction *> list;
    static History *getInstance();

    void getHistory()
    {
        // Serial.println("---- begin history embedded system ----");
        Serial.println("---- histórico do sistema embarcado ----");
        Serial.println("----       tempo, pino, valor");
        Interaction *interaction;
        for (int i = 0; i < this->list.size(); i++)
        {
            interaction = this->list.get(i);
            Serial.print(interaction->time);
            Serial.print(", ");
            Serial.print(interaction->pin);
            Serial.print(", ");
            Serial.print(interaction->value);

            Serial.println(" ");
        }
        // Serial.println("---- end history embedded system ----");
        Serial.println("---- fim do histórico do sistema embarcado ----");
    }

    History(History &other) = delete;

    void operator=(const History &) = delete;

    bool proceedTime(unsigned long time)
    {
        Interaction *interaction1 = this->list.shift();
        Interaction *interaction2 = this->list.get(0);

        return (interaction2->time - interaction1->time) >= time;
    }
};
History *History::history_ = nullptr;
;

History *History::getInstance()
{
    if (history_ == nullptr)
    {
        history_ = new History();
    }
    return history_;
}

History *history = History::getInstance();
