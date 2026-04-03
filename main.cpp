//COMSC-210-5068， lab 24, Yang Liu
#include <iostream>
#include <fstream>
#include <set>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

void delete_goat(set<Goat> &trip);
void add_goat(set<Goat>& trip, string names[], string colors[]);
void display_trip(set<Goat> trip);
int main_menu();

int main() {
    srand(time(0));
    bool again = true;

    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();

    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    set<Goat> trip;

    while (again) {
        int ch = main_menu();
        switch (ch) {
            case 1: add_goat(trip, names, colors); break;
            case 2: delete_goat(trip); break;
            case 3: display_trip(trip); break;
            case 4: again = false; break;
        }
    }
    return 0;
}

int main_menu() {
    int choice;
    cout << endl;
    cout << "*** GOAT MANAGER 3001 ***" << endl;
    cout << "[1] Add a goat" << endl;
    cout << "[2] Delete a goat" << endl;
    cout << "[3] List goats" << endl;
    cout << "[4] Quit" << endl;
    cout << "Choice --> ";
    cin >> choice;
    while (choice < 1 || choice > 4) {
        cout << "Invalid choice, enter 1-4: ";
        cin >> choice;
    }
    return choice;
}

void add_goat(set<Goat> &trip, string names[], string colors[]) {
    int n = rand() % SZ_NAMES;
    int c = rand() % SZ_COLORS;
    int a = rand() % (MAX_AGE + 1);
    Goat g(names[n], a, colors[c]);
    trip.insert(g);
    cout << endl;
}

void display_trip(set<Goat> trip) {
    cout << endl;
    int i = 1;
    for (Goat g : trip) {
        cout << "   [" << i++ << "] " << g.get_name()
             << " (" << g.get_age() << ", " << g.get_color() << ")" << endl;
    }
    cout << endl;
}

void delete_goat(set<Goat> &trip) {
    if (trip.empty()) {
        cout << endl;
        return;
    }
    cout << endl;

    int choice;
    display_trip(trip);
    
    cout << "Enter number to delete: ";
    cin >> choice;

    int size = trip.size();
    if (choice < 1 || choice > size) {
        cout << "Invalid number!" << endl;
        return;
    }

    auto it = trip.begin();
    for (int i = 0; i < choice - 1; i++) {
        it++;
    }
    trip.erase(it);
    cout << endl;
}