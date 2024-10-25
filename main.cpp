#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();

int main() {
    srand(time(0));
    bool again;

    // read & populate arrays for names and colors
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

    list<Goat> trip;

    int op = main_menu();
    while(op != 4)
    {
       if (op == 1)
       {
           add_goat();
       }
       else if (op == 2)
       {

       }
       else if (op == 3)
       {

       }
    }



    return 0;
}

int main_menu()
{
    int entry;
    cout << "*** GOAT MANAGER 3001 ***" << endl;
    cout << "[1] Add a goat" << endl;
    cout << "[2] Delete a goat" << endl;
    cout << "[3] List Goats" << endl;
    cout << "[4] Quit" << endl;
    cout << "Choice -->";
    cin >> entry;
    while(entry < 1 || entry > 4)
    {
        cout << "Please enter a valid entry";
        cin >> entry;
        cout << endl;
    }

    return entry;
}

void add_goat(list<Goat> &trip, string[] names, string[] colors)
{
    string n = names[rand() % SZ_NAMES];
    string c = names[rand() % SZ_COLORS];
    int a = rand() % MAX_AGE;
    Goat temp = new Goat(n, a, c);
    trip.push_back(temp);
}

void delete_goat(list<Goat> &trip)
{
    int entry;

    cout << "Select which goat to delete: ";
    cin >> entry;

    auto itd = trip.begin();
    advance(itd, entry);
    trip.erase(itd);

    cout << "New List: " << endl;
    for(auto it = trip.begin(); it != trip.end(); it++)
    {
        Goat temp = *it;
        cout << "[" << i << "] " << temp.get_name() << "( " << temp.get_age() << ", " << temp.get_color() << ")" << endl;
        cout << "Select which goat to delete: ";
        cin >> entry;
    }
}

void display_trip(list<Goat> trip)
{
   int i = 1;

   for(auto it = trip.begin(); it != trip.end(); it++)
   {
        Goat temp = *it;
        cout << "[" << i << "] " << temp.get_name() << "( " << temp.get_age() << ", " << temp.get_color() << ")" << endl;
   }
}
