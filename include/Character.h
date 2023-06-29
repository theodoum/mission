#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>

using namespace std;

class Character
{
    public:
        // Constructors
        Character();
        Character(string name,int life, int strength);

        // Getter & Setter
        string getName() const;
        int getLife() const;
        int getStrength() const;
        int setLife(int new_life);
        int setStrength(int new_strength);

        void displayCharacter();

    private:
        string _name;
        int _life;
        int _strength;
};

#endif // CHARACTER_H
