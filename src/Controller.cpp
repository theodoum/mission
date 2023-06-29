//
// Created by boris on 28/06/2023.
//

#include "../include/Controller.h"

using namespace std;

Controller::Controller(string name, string saveFile) : _name(name), _saveFile(saveFile) {}

string Controller::getSaveFile()
{
    return _saveFile;
}

vector<Character*> Controller::getCharacters()
{
    return _characters;
}

vector<Spaceship*> Controller::getSpaceships()
{
    return _spaceships;
}

vector<Planet*> Controller::getPlanets()
{
    return _planets;
}

vector<Mission*> Controller::getMissions()
{
    return _missions;
}

void Controller::setSaveFile(string fileName)
{
    _saveFile=fileName;
}

Character* Controller::findCharacter(string character_name) const
{
    auto matchCharacterName = [character_name](Character character)
    {
        return character.getName()==character_name;
    };

    auto character_it = find_if(*_characters.begin(), *_characters.end(), matchCharacterName);
    if (character_it == *_characters.end())
        return new Character();
    else return character_it;
}

Spaceship* Controller::findSpaceship(string spaceship_name) const
{
    auto matchSpaceShipName = [spaceship_name](Spaceship spaceship)
    {
        return spaceship.getName()==spaceship_name;
    };

    auto spaceship_it = find_if(*_spaceships.begin(), *_spaceships.end(), matchSpaceShipName);
    if (spaceship_it == *_spaceships.end())
            return new Spaceship();
    else return spaceship_it;
}

Planet* Controller::findPlanet(string planet_name) const
{
    auto matchPlanetName = [planet_name](Planet planet)
    {
        return planet.getName()==planet_name;
    };

    auto planet_it = find_if(*_planets.begin(), *_planets.end(), matchPlanetName);
    if (planet_it == *_planets.end())
        return new Planet();
    else return planet_it;
}

Mission* Controller::findMission(string mission_name) const
{
    auto matchMissionName = [mission_name](Mission mission)
    {
        return mission.getName()==mission_name;
    };

    auto mission_it = find_if(*_missions.begin(), *_missions.end(), matchMissionName);
    if (mission_it == *_missions.end())
        return new Mission();
    else return mission_it;
}

void Controller::addCharacter(Character* character)
{
    _characters.push_back(character);
}

void Controller::addSpaceship(Spaceship* spaceship)
{
    _spaceships.push_back(spaceship);
}

void Controller::addPlanet(Planet* planet)
{
    _planets.push_back(planet);
}

void Controller::addMission(Mission* mission)
{
    _missions.push_back(mission);
}

vector<string> Controller::split (const string &s, char delim) {
    vector<string> result;
    stringstream ss (s);
    string item;

    while (getline (ss, item, delim)) {
        result.push_back(item);
    }
    return result;
}
void Controller::initialize()
{
    ifstream file("../save.txt");
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            vector<string> parsedLine = this->split(line, ':');
            if (parsedLine.at(0)=="planet")
            {
                string name=parsedLine.at(1), description=parsedLine.at(2);
                this->addPlanet(new Planet(name, description));
            }
            else if (parsedLine.at(0)=="spaceship")
            {
                string name=parsedLine.at(1);
                this->addSpaceship(new Spaceship(name));
            }
            else if (parsedLine.at(0) == "character")
            {
                string name=parsedLine.at(1), health=parsedLine.at(2), strength=parsedLine.at(3), location=parsedLine.at(4);
                this->addCharacter(new Character(name, stoi(health), stoi(strength)));
                if (location=="planet")
                {
                    string name_location = parsedLine.at(5);
                    this->findPlanet(name_location)->addResident(this->getCharacters().back());
                }
                else if (location=="spaceship")
                {
                    string name_location=parsedLine.at(5);
                    cout << "character spaceship parsed " << name << endl;
                    this->findSpaceship(name_location)->addCrewMember(this->getCharacters().back());
                }
            }
            else if (parsedLine.at(0)=="mission")
            {
                string name=parsedLine.at(1), description=parsedLine.at(2), is_complete=parsedLine.at(3);
                this->addMission(new Mission(name, description, stoi(is_complete)));
            }
        }
        file.close();
    }
    else cout << "file error";
}

void Controller::displayCharacters()
{
    cout << "======= Characters =======" << endl;
    for (int i=0; i<this->getCharacters().size();i++)
        this->getCharacters()[i]->displayCharacter();
}

void Controller::displayPlanets()
{
    cout << "======= Planets =======" << endl;
    for (int i=0; i<this->getPlanets().size();i++)
        this->getPlanets()[i]->displayPlanet();
}

void Controller::displaySpaceships()
{
    cout << "======= Spaceships =======" << endl;
    for (int i=0; i<this->getSpaceships().size();i++)
        this->getSpaceships()[i]->displaySpaceship();
}

void Controller::displayMissions()
{
    cout << "======= Missions =======" << endl;
    for (int i=0; i<this->getMissions().size();i++)
        this->getMissions()[i]->displayMission();
}

void Controller::savePlanets()
{
    ofstream file {this->getSaveFile()};
    for (auto planet : this->getPlanets())
    {
        file << "planet" <<  ":" << planet->getName() << ":" << planet->getDescription() << "\n";
    }
    //file.close();
}

void Controller::saveSpaceShips()
{
    ofstream file {this->getSaveFile()};
    for (auto spaceship : this->getSpaceships())
    {
        file << "spaceship" << ":" << spaceship->getName() << "\n";
    }
    file.close();
}

void Controller::saveCharacters()
{
    ofstream file {this->getSaveFile()};
    for (auto character : this->getCharacters())
    {
        file << "character" << ":" << character->getName() << ":" << character->getLife() << ":" << character->getStrength() << ":";
        for (Planet* planet : this->getPlanets())
        {
            if (planet->findResident(character->getName()).getName()!="")
            {
                file << "planet" << ":" << planet->getName() << "\n";
                file.close();
                return;
            }
        }
        for (Spaceship* spaceship : this->getSpaceships())
        {
            if (spaceship->findMember(character->getName()).getName()!="")
            {
                file << "spaceship" << ":" << spaceship->getName() << "\n";
                file.close();
                return;
            }
        }
        file << "none" << "\n";
        file.close();
    }
}

void Controller::saveMissions()
{
    ofstream file {this->getSaveFile()};
    for (auto mission : this->getMissions())
    {
        file << "mission" << ":" << mission->getName() << ":" << mission->getDescription() << ":" << mission->getIsCompleted() << "\n";
    }
    file.close();
}

void Controller::save()
{
    ofstream file {this->getSaveFile()};
    savePlanets();
//    saveSpaceShips();
//    saveCharacters();
//    saveMissions();
    //save planets
    {
        for (auto planet : this->getPlanets())
        {
            file << "planet" <<  ":" << planet->getName() << ":" << planet->getDescription() << "\n";
        }
    }
    //save spaceships
    {
        for (auto spaceship : this->getSpaceships())
        {
            file << "spaceship" << ":" << spaceship->getName() << "\n";
        }
    }
    //save characters
    {
        for (auto character : this->getCharacters())
        {
            file << "character" << ":" << character->getName() << ":" << character->getLife() << ":" << character->getStrength() << ":";
            bool found=false;
            for (Planet* planet : this->getPlanets())
            {
                if (planet->findResident(character->getName()).getName()!="")
                {
                    file << "planet" << ":" << planet->getName() << "\n";
                    found=true;
                    break;
                }
            }
            for (Spaceship* spaceship : this->getSpaceships())
            {
                if (spaceship->findMember(character->getName()).getName()!="")
                {
                    file << "spaceship" << ":" << spaceship->getName() << "\n";
                    found=true;
                    break;
                }
            }
            if (!found) file << "none" << "\n";
        }
    }
    //save missions
    {
        for (auto mission : this->getMissions())
        {
            file << "mission" << ":" << mission->getName() << ":" << mission->getDescription() << ":" << mission->getIsCompleted() << "\n";
        }
    }
}
