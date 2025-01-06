#pragma once

class EmbeddedSystem
{
protected:
    String description;
    String author;

public:
    EmbeddedSystem(String description, String author)
    {
        this->description = description;
        this->author = author;
    };
    void configuration();
    void setupES();
    void loopES();
    void runComponentTests();
};
