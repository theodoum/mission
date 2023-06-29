#include <iostream>
#include "../include/Planet.h"

using namespace std;

Planet::Planet() : _name(""), _description("") {}

Planet::Planet(string name, string description): _name(name), _description(description) {}

std::string Planet::getName() const
{
    return _name;
}

string Planet::getDescription() const
{
    return _description;
}

std::vector<Character*> Planet::getResidents() const
{
    return _residents;
}

string Planet::setDescription(string new_description)
{
    _description.assign(new_description);
    return _description;
}

void Planet::addResident(Character* resident)
{
    _residents.push_back(resident);
}

Character Planet::findResident(string resident_name) const
{
    auto matchResidentName = [resident_name](Character *character)
    {
        return character->getName()==resident_name;
    };

    auto character_it = find_if(_residents.begin(), _residents.end(), matchResidentName);
    if (character_it == _residents.end())
        return *new Character();
    else return **character_it;
}

void Planet::displayPlanet()
{
    cout << "Nom : " << this->getName() << " Description : " << this->getDescription() << endl;
    for (int i=0; i< this->getResidents().size(); i++)
        this->getResidents()[i]->displayCharacter();
}