#pragma once
#include "../EmbeddedSystem/EmbeddedSystem.h"
#include "../Component/Behavior.h"
#include "../History/History.h"

class SystemTests
{

public:
    EmbeddedSystem *embeddedsystem;
    History *history = History::getInstance();
    void enter(String name);
    void exit();
    void run();
};
