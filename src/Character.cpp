#include <iostream>
#include "../include/Character.h"

using namespace std;

Character::Character() : _name(""), _life(0), _strength(0){}

Character::Character(string name,int life,int strength): _name(name), _life(life), _strength(strength){}

std::string Character::getName() const
{
    return _name;
}

int Character::getLife() const{
    return _life;
}

int Character::getStrength() const{
    return _strength;
}

int Character::setLife(int new_life)
{
    _life = new_life;
    return _life;
}

int Character::setStrength(int new_strength)
{
    _strength = new_strength;
    return _strength;
}

void Character::displayCharacter()
{
    cout << "Nom : " << this->getName() << " PV : " << this->getLife() << " Force : " << this->getStrength() << endl;
}