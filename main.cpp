#include <iostream>
#include "include/Controller.h"

using namespace std;

void displayMainMenu()
{
    cout << "Menu principal :" << endl;
    cout << "   1. Voir les missions" << endl;
    cout << "   2. Parler aux personnages" << endl;
    cout << "   3. Voyager vers une autre planete" << endl;
    cout << "   0. Quitter le jeu" << endl;
}

int main() {
    Controller controller("test");
    controller.initialize();
    controller.displayPlanets();
    controller.displaySpaceships();
    controller.displayCharacters();
    controller.findPlanet("Terre")->getResidents().at(1)->setLife(124);
    controller.displayCharacters();
    controller.displayMissions();
    controller.setSaveFile("save2.txt");
    controller.save();
    return 0;
}