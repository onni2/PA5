#include <string>
#include <vector>
#include <stdlib.h>
#include <chrono>
#include <tuple>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <map>

using namespace std;

// Structs that hold the info about each role/species/eldrich (i.e. not charcters instances)
struct Role {
    string name;
    tuple<int, int> life_min_max;
    tuple<int, int> intelligence_min_max;
    tuple<int, int> strength_min_max;
};

struct Species {
    string name;
    int life;
    int intelligence;
    int strength;
    bool natural;
    int disquiet;
};

struct Eldritch_horror {
    string name;
    int life;
    int intelligence;
    int strength;
    bool natural;
    int disquiet;
    int traumatism;
};

// ----------------

class Being{
public:
    // species
    Being(Species species, string name) : being_type(species.name), life(species.life), 
        strength(species.strength), intelligence(species.intelligence), name(name) {}

    // person 
    Being(string name, int life, int strength, int intelligence, Role role) : name(name), life(life), 
        strength(strength), intelligence(intelligence), being_type(role.name) {}

    // eldritch
    Being(Eldritch_horror eldritch, string name) : being_type(eldritch.name), life(eldritch.life), 
        strength(eldritch.strength), intelligence(eldritch.intelligence), name(name) {}

    virtual void print();
    void print_name_type();
    virtual void edit_stats();

    virtual ~Being() {}

    string type; // person/creature/eldrich
    string being_type; // name of the being (e.g. ghoul, nurse, etc)

protected:
    int life; // 0 - 10
    int strength; // 0 - 10
    int intelligence; // 0 - 10
    string name; // name of character

    void edit_name();
    void edit_life();
    void edit_strength();
    void edit_intelligence();
};

class Person : public Being{
public:
    Person(int life, int strength, int intelligence, Role role, string name, string gender, int fear) : 
        gender(gender), fear(fear), Being(name, life, strength, intelligence, role) {}


    void edit_stats();
    void print();
    void write_to_file(ofstream &file);

protected:
    string gender; 
    int fear; // 0 - 10

    void edit_gender();
    void edit_fear();
};

class Investigator : public Person{
public:
    Investigator(int life, int strength, int intelligence, Role role, string name, string gender, int fear, int terror) :
        terror(terror), Person(life, strength, intelligence, role, name, gender, fear) {}

    void print();
    void edit_stats();
    void write_to_file(ofstream &file);

private:
    int terror; // 0 - 3

    void edit_terror();
};

class Creature : public Being{
public:
    Creature(Species species, string name, int disquiet) : natural(species.natural), disquiet(disquiet),
        Being(species, name) {}

    Creature(Eldritch_horror eldritch, string name, int disquiet) : natural(eldritch.natural), disquiet(disquiet),
        Being(eldritch, name) {}

    void print();
    void edit_stats();
    virtual void write_to_file(ofstream &file);

protected:
    bool natural;
    int disquiet; // 0 - 10

    void edit_natural();
    void edit_disquiet();
};


class Eldritch : public Creature{
public:
    Eldritch(Eldritch_horror eldritch, string name, int disquiet, int traumatism) : traumatism(traumatism),
        Creature(eldritch, name, disquiet) {}

    void print();
    void edit_stats();
    void write_to_file(ofstream &file);

private:
    int traumatism; // 0 - 3 

    void edit_traumatism();
};

