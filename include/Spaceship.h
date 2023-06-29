#ifndef SPACESHIP_H
#define SPACESHIP_H
#include <string>
#include <vector>
#include <algorithm>

#include "Character.h"

using namespace std;

class Spaceship
{
    public:
        // Constructors
        Spaceship();
        Spaceship(string name);

        // Getters & Setters
        string getName() const;
        vector<Character*> getCrew();
        void addCrewMember(Character* member);

        Character findMember(string resident_name) const;

        void displaySpaceship();

    private:
        string _name;
        vector<Character*> _crew;
};

#endif // SPACESHIP_H
