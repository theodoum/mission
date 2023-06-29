//
// Created by boris on 28/06/2023.
//

#ifndef MISSION_CONTROLLER_H
#define MISSION_CONTROLLER_H

#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Character.h"
#include "Spaceship.h"
#include "Planet.h"
#include "Mission.h"

using namespace std;

class Controller {
    public :
        Controller(string name, string saveFile="../save.txt");
        //getter
        string getSaveFile();
        vector<Character*> getCharacters();
        vector<Spaceship*> getSpaceships();
        vector<Planet*> getPlanets();
        vector<Mission*> getMissions();

        void setSaveFile(string fileName);

        Character* findCharacter(string character_name) const;
        Spaceship* findSpaceship(string spaceship_name) const;
        Planet* findPlanet(string planet_name) const;
        Mission* findMission(string mission_name) const;

        void addCharacter(Character* character);
        void addSpaceship(Spaceship* spaceship);
        void addPlanet(Planet* planet);
        void addMission(Mission* mission);
        void initialize ();
        void save();

        void displayCharacters();
        void displaySpaceships();
        void displayPlanets();
        void displayMissions();


    private:
        string _name;
        string _saveFile;
        vector<Character*> _characters;
        vector<Spaceship*> _spaceships;
        vector<Planet*> _planets;
        vector<Mission*> _missions;
        vector<string> split(const string &s, char delim);
        void savePlanets();
        void saveSpaceShips();
        void saveCharacters();
        void saveMissions();

};

#endif //MISSION_CONTROLLER_H