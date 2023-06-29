#include <iostream>
#include <limits>

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

int validInput()
{
    unsigned int num;
    while (1) {
        cin >> num;
        if (cin.fail() && num > 3) {
            cin.clear();
            cin.sync();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout << "Erreur de saisie\n";
            displayMainMenu();
            continue;
        }
        return num;
    }
}

int main()
{
    Controller controller("test");
    controller.initialize();
//    controller.displayPlanets();
//    controller.displaySpaceships();
//    controller.displayCharacters();
//    controller.findPlanet("Terre")->getResidents().at(1)->setLife(124);
//    controller.displayCharacters();
//    controller.displayMissions();
   // controller.setSaveFile("save2.txt");
    //controller.save();
    while(1)
    {
        displayMainMenu();
        int choice = validInput();
        switch (choice) {
            case 1:
                controller.displayMissions();
                break;
            case 2:
                break;
            case 3:
                break;
            case 0:
                cout << u8"Où voulez-vous sauvegrder votre partie ? Appuyez sur Entrée pour utiliser le fichier de sauvegarde par défaut.\n";
                string input;
                cin >> input;
                if (input.length()!=0) controller.setSaveFile(input);
                controller.save();
                return EXIT_SUCCESS;
        }
    }
    return 0;
}