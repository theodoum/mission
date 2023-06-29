#ifndef MISSION_H
#define MISSION_H
#include <string>

using namespace std;

class Mission
{
    public:
        // Constructors
        Mission();
        Mission(string name,string description, int is_complete=0);

        // Getters & Setters
        string getName() const;
        string getDescription() const;
        int getIsCompleted() const;
        void setIsCompleted(int result);

        void displayMission();

    private:
        string _name;
        string _description;
        int _isCompleted;
};

#endif // MISSION_H