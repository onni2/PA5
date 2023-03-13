#include "being.h"

void Being::print(){
    cout << "Name of character: " << this->name << endl;
    cout << "Character type: " << this->type << endl;
    cout << "Character being type: " << this->being_type << endl;
    cout << "Life: " << this->life << endl;
    cout << "Strength: " << this->strength << endl;
    cout << "Intelligence: " << this->intelligence << endl;
}

// the user can not edit type or being type
void Being::edit_stats(){
    cout << "(1) Name: " << this->name << endl;
    cout << "(2) Life: " << this->life << endl;
    cout << "(3) Strength: " << this->strength << endl;
    cout << "(4) Intelligence: " << this->intelligence << endl;
}

void Being::edit_name(){
    cout << "New name: ";
    string name;
    cin.ignore(); // consume the newline character left in the input stream
    getline(cin, name);
    this->name = name;
}

void Being::edit_life(){
    cout << "New life: ";
    int life; cin >> life;
    this->life = life;
}

void Being::edit_strength(){
    cout << "New strength: ";
    int strength; cin >> strength;
    this->strength = strength;
}

void Being::edit_intelligence(){
    cout << "New intelligence: ";
    int intelligence; cin >> intelligence;
    this->intelligence = intelligence;
}

void Person::print(){
    Being::print();
    cout << "Gender: " << this->gender << endl;
    cout << "Fear: " << this->fear << endl;
}

void Person::edit_gender(){
    cout << "New gender: ";
    string gender; cin >> gender;
    this->gender = gender;
}

void Person::edit_fear(){
    cout << "New fear: ";
    int fear; cin >> fear;
    this->fear = fear;
}

void Person::edit_stats(){
    Being::edit_stats();
    cout << "(5) Gender: " << this->gender << endl;
    cout << "(6) Fear: " << this->fear << endl;
    cout << "(b) back" << endl;
    cout << "\n> ";

    int choice;
    char input_char;

    cin >> input_char; cout << endl;

    while (static_cast<int>(input_char) != 'b') {
        choice = static_cast<int>(input_char) - '0';

        if (choice == 1) edit_name();
        else if (choice == 2) edit_life();
        else if (choice == 3) edit_strength();
        else if (choice == 4) edit_intelligence();
        else if (choice == 5) edit_gender();
        else if (choice == 6) edit_fear();

        cout << endl;
        cout << "-------------------------" << endl;
        Being::edit_stats();
        cout << "(5) Gender: " << this->gender << endl;
        cout << "(6) Fear: " << this->fear << endl;
        cout << "(b) back" << endl;
        cout << "\n> ";
        cin >> input_char; cout << endl;
    }
}

void Investigator::print(){
    Person::print();
    cout << "Terror: " << this->terror << endl;
}

void Investigator::edit_terror(){
    cout << "New terror: ";
    int terror; cin >> terror;
    this->terror = terror;
}

void Investigator::edit_stats(){
    Being::edit_stats();
    cout << "(5) Gender: " << this->gender << endl;
    cout << "(6) Fear: " << this->fear << endl;
    cout << "(7) Terror: " << this->terror << endl;
    cout << "(b) back" << endl;
    cout << "\n> ";

    int choice;
    char input_char;

    cin >> input_char; cout << endl;

    while (static_cast<int>(input_char) != 'b') {
        choice = static_cast<int>(input_char) - '0';

        if (choice == 1) edit_name();
        else if (choice == 2) edit_life();
        else if (choice == 3) edit_strength();
        else if (choice == 4) edit_intelligence();
        else if (choice == 5) edit_gender();
        else if (choice == 6) edit_fear();
        else if (choice == 7) edit_terror();

        cout << endl;
        cout << "-------------------------" << endl;
        Being::edit_stats();
        cout << "(5) Gender: " << this->gender << endl;
        cout << "(6) Fear: " << this->fear << endl;
        cout << "(7) Terror: " << this->terror << endl;
        cout << "(b) back" << endl;
        cout << "\n> ";
        cin >> input_char; cout << endl;
    }
}

void Creature::print(){
    Being::print();
    cout << "Natural: " << (this->natural == 1 ? "true" : "false") << endl;
    cout << "Disquiet: " << this->disquiet << endl;
}

void Creature::edit_natural(){
    cout << "Natural (true/false): "; 
    cin >> boolalpha >> natural;
    this->natural = natural;
}

void Creature::edit_disquiet(){
    cout << "New disquiet: ";
    int disquiet; cin >> disquiet;
    this->disquiet = disquiet;
}

void Creature::edit_stats(){
    Being::edit_stats();
    cout << "(5) Natural: " << (this->natural == 1 ? "true" : "false") << endl;
    cout << "(6) Disquiet: " << this->disquiet << endl;
    cout << "(b) back" << endl;
    cout << "\n> ";

    int choice;
    char input_char;

    cin >> input_char; cout << endl;

    while (static_cast<int>(input_char) != 'b') {
        choice = static_cast<int>(input_char) - '0';

        if (choice == 1) edit_name();
        else if (choice == 2) edit_life();
        else if (choice == 3) edit_strength();
        else if (choice == 4) edit_intelligence();
        else if (choice == 5) edit_natural();
        else if (choice == 6) edit_disquiet();

        cout << endl;
        cout << "-------------------------" << endl;
        Being::edit_stats();
        cout << "(5) Natural: " << (this->natural == 1 ? "true" : "false") << endl;
        cout << "(6) Disquiet: " << this->disquiet << endl;
        cout << "(b) back" << endl;
        cout << "\n> ";
        cin >> input_char; cout << endl;
    }
}

void Eldritch::print(){
    Creature::print();
    cout << "Traumatism: " << this->traumatism << endl;
}

void Eldritch::edit_traumatism(){
    cout << "New traumatism: ";
    int traumatism; cin >> traumatism;
    this->traumatism = traumatism;
}

void Eldritch::edit_stats(){
    Being::edit_stats();
    cout << "(5) Natural: " << (this->natural == 1 ? "true" : "false") << endl;
    cout << "(6) Disquiet: " << this->disquiet << endl;
    cout << "(7) Traumatism: " << this->traumatism << endl;
    cout << "(b) back" << endl;
    cout << "\n> ";

    int choice;
    char input_char;

    cin >> input_char; cout << endl;

    while (static_cast<int>(input_char) != 'b') {
        choice = static_cast<int>(input_char) - '0';

        if (choice == 1) edit_name();
        else if (choice == 2) edit_life();
        else if (choice == 3) edit_strength();
        else if (choice == 4) edit_intelligence();
        else if (choice == 5) edit_natural();
        else if (choice == 6) edit_disquiet();
        else if (choice == 7) edit_traumatism();

        cout << endl;
        cout << "-------------------------" << endl;
        Being::edit_stats();
        cout << "(5) Natural: " << (this->natural == 1 ? "true" : "false") << endl;
        cout << "(6) Disquiet: " << this->disquiet << endl;
        cout << "(7) Traumatism: " << this->traumatism << endl;
        cout << "(b) back" << endl;
        cout << "\n> ";
        cin >> input_char; cout << endl;
    }
}

void Being::print_name_type(){
    cout << this->name << " of being type " << this->being_type << " (" << this->type << ")" << endl;
}

void Person::write_to_file(ofstream &file){
    file << this->name << endl;
    file << this->type << endl;
    file << this->being_type << endl;
    file << this->life << endl;
    file << this->strength << endl;
    file << this->intelligence << endl;
    file << this->gender << endl;
    file << this->fear << endl;
}

void Investigator::write_to_file(ofstream &file){
    Person::write_to_file(file);
    file << this->terror << endl;
}

void Creature::write_to_file(ofstream &file){
    file << this->name << endl;
    file << this->type << endl;
    file << this->being_type << endl;
    file << this->life << endl;
    file << this->strength << endl;
    file << this->intelligence << endl;
    file << this->natural << endl;
    file << this->disquiet << endl;
}

void Eldritch::write_to_file(ofstream &file){
    Creature::write_to_file(file);
    file << this->traumatism << endl;
}