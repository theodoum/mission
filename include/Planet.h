#ifndef PLANET_H
#define PLANET_H

#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Character.h"

using namespace std;

class Planet
{
    public:
        // Constructors
        Planet();
        Planet(string name, string description);

        // Getters & Setters
        string getName() const;
        string getDescription() const;
        vector<Character*> getResidents() const;
        string setDescription(string new_description);
        void addResident(Character* resident);

        Character findResident(string resident_name) const;

        void displayPlanet();

    private:
        string _name;
        string _description;
        vector<Character*> _residents;
};

#endif // PLANET_H
