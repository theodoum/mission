#include <iostream>

#include "../include/Mission.h"

using namespace std;

Mission::Mission() : _name(""), _description(""), _isCompleted(0){}

Mission::Mission(string name,string description, int is_complete): _name(name), _description(description), _isCompleted(is_complete){}

string Mission::getName() const
{
    return _name;
}

string Mission::getDescription() const
{
    return _description;
}

int Mission::getIsCompleted() const
{
    return _isCompleted;
}

void Mission::setIsCompleted(int result)
{
    _isCompleted = result;
}

void Mission::displayMission()
{
    cout << "Nom : " << this->getName() << " Description : " << this->getDescription() << u8" Terminé ? " << this->getIsCompleted() << endl;
}
