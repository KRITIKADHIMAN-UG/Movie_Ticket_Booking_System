#ifndef CINEMA_CPP
#define CINEMA_CPP

#include <vector>
#include <string>
#include "03_Screen.cpp"
using namespace std;

// Cinema: knows its name and OWNS its screens (composition - Cinema 1 *-- 1..* Screen).
// Must NOT know about movies, shows, or bookings.
class Cinema {
private:
    string name;
    vector<Screen> screens;

public:
    Cinema(string name) : name(name) {}

    void addScreen(const Screen& screen) {
        screens.push_back(screen);
    }

    string getName() const { return name; }
    vector<Screen>& getScreens() { return screens; }
};

#endif
