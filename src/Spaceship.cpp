#include <iostream>
#include "../include/Spaceship.h"

using namespace std;

Spaceship::Spaceship() : _name("") {}

Spaceship::Spaceship(string name): _name(name){}

string Spaceship::getName() const
{
    return _name;
}

vector<Character*> Spaceship::getCrew()
{
    return _crew;
}

void Spaceship::addCrewMember(Character* member)
{
    _crew.push_back(member);
}

Character Spaceship::findMember(string resident_name) const
{
    auto matchMemberName = [resident_name](Character *character)
    {
        return character->getName()==resident_name;
    };

    auto character_it = find_if(_crew.begin(), _crew.end(), matchMemberName);
    if (character_it == _crew.end())
        return *new Character();
    else return **character_it;
}

void Spaceship::displaySpaceship()
{
    cout << "Nom : " << this->getName() << endl;
    for (int i=0; i< this->getCrew().size(); i++)
    {
        this->getCrew()[i]->displayCharacter();
    }
}
