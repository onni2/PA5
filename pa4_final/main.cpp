#include "being.h"

void press_to_contin(){
    cout << "\nPress Enter to continue...";
    cin.ignore(); 
    cin.get();
}

// reads the roles.txt file into the roles vector
vector<Role> read_roles_file(){
    ifstream infile("roles.txt");
    string name;
    vector<Role> roles;

    while (infile >> name) {
        int life_min, life_max, intelligence_min, intelligence_max, strength_min, strength_max;
        infile >> life_min; infile.ignore(1, '-'); infile >> life_max;
        infile >> strength_min; infile.ignore(1, '-');infile >> strength_max; 
        infile >> intelligence_min; infile.ignore(1, '-'); infile >> intelligence_max;
        
        roles.push_back({name, {life_min, life_max}, {intelligence_min, intelligence_max}, {strength_min, strength_max}});
    }

    return roles;
}

// reads the species.txt file into the species vector
vector<Species> read_species_file(){
    ifstream infile("species.txt");
    string name;
    vector<Species> species;

    while (infile >> name) {
        int life, strength, intelligence, disquiet;
        bool natural;

        infile >> life >> strength >> intelligence >> boolalpha >> natural >> disquiet;
        species.push_back({name, life, intelligence, strength, natural, disquiet});
    }

    return species;
}

// reads the eldrich.txt file into the eldrich_horror vector
vector<Eldritch_horror> read_eldritch_file(){
    ifstream infile("eldritch.txt");
    string name;
    vector<Eldritch_horror> eldritch_horror;

    while (infile >> name) {
        int life, strength, intelligence, traumatism;

        infile >> life >> strength >> intelligence >> traumatism;
        eldritch_horror.push_back({name, life, intelligence, strength, false, 10, traumatism});
    }

    return eldritch_horror;
}

enum BeingType {
    PersonType = 1,
    CreatureType,
    EldritchHorrorType,
};

void print_person(Role person){
    cout << "Name: " << person.name << endl;
    cout << "Life: (" + to_string(get<0>(person.life_min_max)) + "-" + to_string(get<1>(person.life_min_max)) + ")" << endl;
    cout << "Strength: (" + to_string(get<0>(person.strength_min_max)) + "-" + to_string(get<1>(person.strength_min_max)) + ")" << endl;
    cout << "Intelligence: (" + to_string(get<0>(person.intelligence_min_max)) + "-" + to_string(get<1>(person.intelligence_min_max)) + ")" << endl;

    press_to_contin();
}

void print_creature(Species species){
    cout << "Name: " << species.name << endl;
    cout << "Life value: " << species.life << endl;
    cout << "Intelligence value: " << species.intelligence << endl;
    cout << "Strength value: " << species.strength << endl;
    cout << "Disquiet value: " << species.disquiet << endl;
    cout << "Natural (true/false): " << (species.natural == 1 ? "true" : "false") << endl;

    press_to_contin();
}

void print_eldritch(Eldritch_horror eldritch_horror){
    cout << "Name: " << eldritch_horror.name << endl;
    cout << "Life value: " << eldritch_horror.life << endl;
    cout << "Intelligence value: " << eldritch_horror.intelligence << endl;
    cout << "Strength value: " << eldritch_horror.strength << endl;
    cout << "Disquiet value: " << eldritch_horror.disquiet << endl;
    cout << "Natural (true/false): " << (eldritch_horror.natural == 1 ? "true" : "false") << endl;
    cout << "Traumatism value: " << eldritch_horror.traumatism << endl;

    press_to_contin();
}

// creates a new being of one of the three types (person/creature/eldritch)
void create_new_being(vector<Role> &roles, vector<Species> &species, vector<Eldritch_horror> &eldritch_horror){
    cout << "What type would you like to create? (type the corresponding number)\n" << endl;
    cout << "(1) Person" << endl;
    cout << "(2) Creature" << endl;
    cout << "(3) Eldritch horror" << endl;
    cout << "(b) back" << endl;
    cout << "\n> ";

    int choice;
    char input_char;
    cin >> input_char; cout << endl;
    if (static_cast<int>(input_char) == 'b') return;
    choice = static_cast<int>(input_char) - '0';

    switch (choice) {
        case PersonType: { // person
            string name; cout << "Name of person: "; cin >> name;
            int min_life, max_life, min_strength, max_strength, min_intelligence, max_intelligence;

            cout << "Min. life value: "; cin >> min_life;
            cout << "Max. life value: "; cin >> max_life;
            cout << "Min. strength value: "; cin >> min_strength;
            cout << "Max. strength value: "; cin >> max_strength;
            cout << "Min. intelligence value: "; cin >> min_intelligence; 
            cout << "Max. intelligence value: "; cin >> max_intelligence; cout << endl;

            roles.push_back({name, {min_life, max_life}, {min_intelligence, max_intelligence},
                {min_strength, max_strength}});

            cout << "-------- New person --------\n" << endl;
            print_person(roles.back());
            break;
        } 
        case CreatureType: { // species
            string name; cout << "Name of species: "; cin >> name;
            int life, intelligence, strength, disquiet;
            bool natural; 

            cout << "Life value: "; cin >> life;
            cout << "Intelligence value: "; cin >> intelligence;
            cout << "Strength value: "; cin >> strength;
            cout << "Disquiet value: "; cin >> disquiet;
            cout << "Natural (true/false): "; cin >> boolalpha >> natural; cout << endl;

            species.push_back({name, life, intelligence, strength, natural, disquiet});

            cout << "-------- New creature --------\n" << endl;
            print_creature(species.back());
            break;
        } 
        case EldritchHorrorType: { // eldritch horror
            string name; cout << "Name of eldritch horror: "; cin >> name;
            int life, intelligence, strength, traumatism;

            cout << "Life value: "; cin >> life;
            cout << "Intelligence value: "; cin >> intelligence;
            cout << "Strength value: "; cin >> strength;
            cout << "Traumatism value: "; cin >> traumatism; cout << endl;

            eldritch_horror.push_back({name, life, intelligence, strength, false, 10, traumatism});

            cout << "-------- New eldritch horror --------\n" << endl;
            print_eldritch(eldritch_horror.back());
            break;
        } 
        default:
            cout << "Invalid choice" << endl;
            press_to_contin();
            break;
    }
}

int get_rand_val(int min, int max){
    return rand() % (max - min + 1) + min;
}

Person* create_person(Role &role){
    int life = get_rand_val(get<0>(role.life_min_max), get<1>(role.life_min_max));
    int strength = get_rand_val(get<0>(role.strength_min_max), get<1>(role.strength_min_max));
    int intelligence = get_rand_val(get<0>(role.intelligence_min_max), get<1>(role.intelligence_min_max));

    string name;
    cout << "Type the name of the new character: " << endl; cout << "> ";
    cin.ignore(); getline(cin, name);

    string gender; cout << "Type the gender of the new charcter: \n> "; cin >> gender;
    cout << endl;
    
    int fear = get_rand_val(0, 10);

    Person* person = new Person(life, strength, intelligence, role, name, gender, fear);
    person->type = "Person";

    return person;
}

Investigator* create_investigator(Role &role){
    int life = get_rand_val(get<0>(role.life_min_max), get<1>(role.life_min_max));
    int strength = get_rand_val(get<0>(role.strength_min_max), get<1>(role.strength_min_max));
    int intelligence = get_rand_val(get<0>(role.intelligence_min_max), get<1>(role.intelligence_min_max));

    string name;
    cout << "Type the name of the new character: " << endl; cout << "> ";
    cin.ignore(); getline(cin, name);
    
    string gender; cout << "Type the gender of the new charcter: \n> "; cin >> gender;
    cout << endl;
    
    int fear = get_rand_val(0, 10);
    int terror = get_rand_val(0, 3);

    Investigator* investigator = new Investigator(life, strength, intelligence, role, name, gender, fear, terror);
    investigator->type = "Investigator";

    return investigator;
}

Creature* create_creature(Species &species, map<string, int> &creature_counts){
    string name;

    // check what number to assign the creature to
    if (creature_counts.count(species.name) == 1){
        name = species.name + " " + to_string(creature_counts[species.name]);
    } else {
        creature_counts[species.name] = 1;
        name = species.name + " " + "1";
    }
    creature_counts[species.name]++;

    int disquiet = get_rand_val(0, 10);

    Creature* creature = new Creature(species, name, disquiet);
    creature->type = "Creature";

    return creature; 
}

Eldritch* create_eldritch(Eldritch_horror &eldritch, map<string, int> &creature_counts){
    string name;
    if (creature_counts.count(eldritch.name) == 1){
        name = eldritch.name + " " + to_string(creature_counts[eldritch.name]);
    } else {
        creature_counts[eldritch.name] = 1;
        name = eldritch.name + " " + "1";
    }
    creature_counts[eldritch.name]++;

    int disquiet = 10;
    int traumatism = get_rand_val(0, 3);

    Eldritch* new_eldritch = new Eldritch(eldritch, name, disquiet, traumatism);
    new_eldritch->type = "Eldritch horror";

    return new_eldritch; 
} 

void create_new_character(vector<Role> &roles, vector<Species> &species, vector<Eldritch_horror> &eldritch_horror,
vector<Being*> &characters, map<string, int> &creature_counts){

    cout << "What type of character you like to create? (type the corresponding number)" << endl;
    cout << "(1) Person" << endl;
    cout << "(2) Creature" << endl;
    cout << "(3) Eldritch horror" << endl;
    cout << "(b) back" << endl;
    cout << "\n> ";

    int choice;
    char input_char;
    cin >> input_char; cout << endl;
    if (static_cast<int>(input_char) == 'b') return;
    choice = static_cast<int>(input_char) - '0';


    if (choice == 1 || choice == 2 ||choice == 3){
        if (choice == 1){ // person
            char investigator; cout << "Is this person an Investigator? (y/n)\n> "; cin >> investigator;
            if (investigator != 'y' && investigator != 'n'){
                cout << "Invalid choice!" << endl; 
                return;
            }
            cout << endl;

            cout << "Choose what role you want to your person to be: \n" << endl;
            cout << left << setw(7) << "No." << setw(15) << "Name" << setw(20) << "Life (min-max)" << setw(25) << "Intelligence (min-max)" << setw(25) << "Strength (min-max)" << endl;

            int i = 1;
            for (const Role& r : roles) {
                cout << left << setw(7) << "(" + to_string(i) + ")"
                    << setw(15) << r.name
                    << setw(20) << "(" + to_string(get<0>(r.life_min_max)) + "-" + to_string(get<1>(r.life_min_max)) + ")"
                    << setw(25) << "(" + to_string(get<0>(r.intelligence_min_max)) + "-" + to_string(get<1>(r.intelligence_min_max)) + ")"
                    << setw(25) << "(" + to_string(get<0>(r.strength_min_max)) + "-" + to_string(get<1>(r.strength_min_max)) + ")" << endl;
                i++;
            }

            cout << "\n> ";
            int choice; cin >> choice; cout << endl;

            Person* character = nullptr; 
            if (investigator == 'y'){
                character = create_investigator(roles[choice - 1]); // assign the Investigator pointer to character
            } else if (investigator == 'n'){
                character = create_person(roles[choice - 1]); // assign the Person pointer to character
            }

            cout << "-------- New character --------\n" << endl;
            if (character) { // check if character is not a nullptr
                character->print();
                characters.push_back(character);
            }

        }

        else if (choice == 2){ // creature
            cout << "Choose what species you want to your creature to be: \n" << endl;
            cout << left << setw(7) << "No." << setw(13) << "Name" << setw(8) << "Life" << setw(15) << "Intelligence" << setw(12) << "Strength" << setw(12) << "Natural" << setw(12) << "Disquiet" << endl;

            int i = 1;
            for (const Species& s : species) {
                cout << left << setw(7) << "(" + to_string(i) + ")"
                    << setw(13) << s.name
                    << setw(8) << s.life
                    << setw(15) << s.intelligence
                    << setw(12) << s.strength
                    << setw(12) << (s.natural ? "true" : "false")
                    << setw(12) << s.disquiet << endl;
                i++;
            }

            cout << "\n> ";
            int choice; cin >> choice; cout << endl;

            cout << "-------- New character --------\n" << endl;
            Creature* creature = create_creature(species[choice - 1], creature_counts);
            creature->print();
            characters.push_back(creature);
        }

        else if (choice == 3){ // eldritch
            cout << "Choose what eldritch horror you want to your character to be: \n" << endl;
            cout << left << setw(7) << "No." << setw(13) << "Name" << setw(8) << "Life" << setw(15) << "Intelligence" << setw(12) << "Strength"<< setw(12) << "Natural" << setw(12) << "Disquiet" << setw(12) << "Traumatism" << endl;

            int i = 1;
            for (const Eldritch_horror& h : eldritch_horror) {
                cout << left << setw(7) << "(" + to_string(i) + ")"
                    << setw(13) << h.name
                    << setw(8) << h.life
                    << setw(15) << h.intelligence
                    << setw(12) << h.strength
                    << setw(12) << (h.natural ? "true" : "false")
                    << setw(12) << h.disquiet
                    << setw(12) << h.traumatism << endl;
                i++;
            }

            cout << "\n> ";
            int choice; cin >> choice; cout << endl;

            cout << "-------- New character --------" << endl;
            Eldritch* eldritch = create_eldritch(eldritch_horror[choice - 1], creature_counts);
            eldritch->print();
            characters.push_back(eldritch);
        }

        press_to_contin();

    }
    else {
        cout << "Invalid choice!" << endl;
    }
}

// finds the index of the characters role/creature/eldritch type 
template<typename T>
int find_vector_index(T t, string name){
    int i = 0;
    for (const auto& value : t){
        if (t[i].name == name){
            return i;
        }
        i++;
    }
    return -1;
}

// reads the characters.txt file to a vector that holds all of the existing characters
void read_characters_file(vector<Role> roles, vector<Species> species, vector<Eldritch_horror> eldritch_horror, 
vector<Being*> &characters, string filename){

    ifstream infile(filename);
    string line;
    
    while (getline(infile, line)) {
        // if (!line.empty() && line[line.size() - 1] == '\r') {
        //     line.erase(line.size() - 1);
        // }

        if (line == "//") {
            string name; getline(infile, name);
            string type; getline(infile, type);
            string being_type; getline(infile, being_type);
            string life; getline(infile, life);
            string strength; getline(infile, strength);
            string intelligence; getline(infile, intelligence);

            if (type == "Person" || type == "Investigator"){
                string gender; getline(infile, gender);
                string fear; getline(infile, fear);

                if (type == "Investigator"){
                    string terror; getline(infile, terror);
                    Investigator* investigator = new Investigator(stoi(life), stoi(strength), stoi(intelligence), 
                        roles[find_vector_index(roles, being_type)], name, gender, stoi(fear), stoi(terror));
                    characters.push_back(investigator);
                    investigator->type = type;
                } else {
                    Person* person = new Person(stoi(life), stoi(strength), stoi(intelligence), 
                        roles[find_vector_index(roles, being_type)], name, gender, stoi(fear));
                    characters.push_back(person);
                    person->type = type;
                }
            }
            else if(type == "Creature" || type == "Eldritch horror"){
                string natural; getline(infile, natural);
                string disquiet; getline(infile, disquiet);

                if (type == "Eldritch horror"){
                    string traumatism; getline(infile, traumatism);
                    Eldritch* eldritch = new Eldritch(eldritch_horror[find_vector_index(eldritch_horror, being_type)], name, 
                        stoi(disquiet), stoi(traumatism));
                    characters.push_back(eldritch);
                    eldritch->type = type;
                } else {
                    Creature* creature = new Creature(species[find_vector_index(species, being_type)], name, stoi(disquiet));
                    characters.push_back(creature);
                    creature->type = type;
                }
            }
        }
    }
}

// counts instances of creatures so we can number them, e.g. wolf 1, wolf 2, etc...
map<string, int> count_creature_instances(vector<Being*> characters){
    map<string, int> creature_counts; 

    for (auto character : characters) {
        if (character->type != "Person" && character->type != "Investigator") {
            if (creature_counts.count(character->being_type) == 1) {
                creature_counts[character->being_type]++;
            } else {
                creature_counts[character->being_type] = 2;
            }
        }
    }

    return creature_counts;
}

void edit_character(vector<Being*> &characters){
    cout << "Select a character that you want to edit: \n" << endl;

    int i = 1;
    for (auto character : characters) {
        cout << "(" << i << ") ";
        character->print_name_type();
        i++;
    }
    cout << "(b) back" << endl;
    cout << "\n> ";

    int choice;
    char input_char;
    cin >> input_char; cout << endl;
    choice = static_cast<int>(input_char) - '0';

    if (static_cast<int>(input_char) == 'b') return;

    cout << "Select a stat that you want to edit ('b' to go back): \n" << endl;
    characters[choice - 1]->edit_stats();

    cout << "-------- Character updated --------\n" << endl;
    characters[choice - 1]->print();
    press_to_contin();
}

void print_all_roles(vector<Role> &roles){
    cout << "All roles in the game: (type corresponding number for more or 'b' for back)\n" << endl;

    int i = 1;
    for (const auto &r : roles){
        cout << "(" << i << ") " << r.name << endl;
        i++;
    }
    cout << "(b) back" << endl;
    cout << "\n> ";

    int choice;
    char input_char;

    cin >> input_char; cout << endl;

    while (static_cast<int>(input_char) != 'b') {
        choice = static_cast<int>(input_char) - '0';

        print_person(roles[choice - 1]); cout << endl;

        cout << "-------------------------" << endl;

        int i = 1;
        for (const auto &r : roles){
            cout << "(" << i << ") " << r.name << endl;
            i++;
        }
        cout << "(b) back" << endl;

        cout << "\n> ";
        cin >> input_char; cout << endl;
    }
}

void print_all_creatures(vector<Species> species){
    cout << "All creatures in the game: (type corresponding number for more or 'b' for back)\n" << endl;

    int i = 1;
    for (const auto &r : species){
        cout << "(" << i << ") " << r.name << endl;
        i++;
    }
    cout << "(b) back" << endl;
    cout << "\n> ";

    int choice;
    char input_char;

    cin >> input_char; cout << endl;

    while (static_cast<int>(input_char) != 'b') {
        choice = static_cast<int>(input_char) - '0';

        print_creature(species[choice - 1]); cout << endl;

        cout << "-------------------------" << endl;

        int i = 1;
        for (const auto &r : species){
            cout << "(" << i << ") " << r.name << endl;
            i++;
        }
        cout << "(b) back" << endl;

        cout << "\n> ";
        cin >> input_char; cout << endl;
    }
}

void print_all_eldritch(vector<Eldritch_horror> eldritch_horror){
    cout << "All creatures in the game: (type corresponding number for default stats or 'b' for back)\n" << endl;

    int i = 1;
    for (const auto &r : eldritch_horror){
        cout << "(" << i << ") " << r.name << endl;
        i++;
    }
    cout << "(b) back" << endl;
    cout << "\n> ";

    int choice;
    char input_char;

    cin >> input_char; cout << endl;

    while (static_cast<int>(input_char) != 'b') {
        choice = static_cast<int>(input_char) - '0';

        print_eldritch(eldritch_horror[choice - 1]); cout << endl;

        cout << "-------------------------" << endl;

        int i = 1;
        for (const auto &r : eldritch_horror){
            cout << "(" << i << ") " << r.name << endl;
            i++;
        }
        cout << "(b) back" << endl;

        cout << "\n> ";
        cin >> input_char; cout << endl;
    }
}

void print_character_roster(vector<Being*> characters){
    cout << "----------------------------" << endl;
    cout << "############################" << endl;
    cout << "##### Character roster #####" << endl;
    cout << "############################" << endl;
    cout << "----------------------------\n" << endl;

    for (const auto& character : characters) {
        character->print();
        cout << "----------------------------" << endl;
    }  

    press_to_contin(); cout << endl;
}

void print_investigators(vector<Being*> characters){
    cout << "----------------------------" << endl;
    cout << "############################" << endl;
    cout << "####### Investigators ######" << endl;
    cout << "############################" << endl;
    cout << "----------------------------\n" << endl;

    for (const auto& character : characters) {
        if (dynamic_cast<Investigator*>(character)) {
            character->print();
            cout << "----------------------------" << endl;
        }
    }

    press_to_contin(); cout << endl;
}

void print_menu_options(){
    cout << "Type a number for an action: \n" << endl;
    cout << "(1) Print all roles" << endl;
    cout << "(2) Print all creatues" << endl;
    cout << "(3) Print all eldritch horrors" << endl;
    cout << "(4) Create new being" << endl;
    cout << "(5) Remove being" << endl;
    cout << "(6) Create new character (add character to the game)" << endl;
    cout << "(7) Edit character" << endl;
    cout << "(8) Print character roster" << endl;
    cout << "(9) Print investigators" << endl;
    cout << "(s) Save roster" << endl;
    cout << "(l) Load roster" << endl;
    cout << "(q) Quit" << endl;
    cout << "\n> ";
}

// saves the roles, species, eldritch horrors and characters to txt files
void save_sheet(vector<Role> roles, vector<Species> species, vector<Eldritch_horror> eldritch_horror) {
    ofstream roles_file("roles.txt");
    ofstream species_file("species.txt");
    ofstream eldritch_horror_file("eldritch.txt");

    for (const auto &r : roles){
        roles_file << r.name << endl;
        roles_file << to_string(get<0>(r.life_min_max)) << "-" << to_string(get<1>(r.life_min_max)) << endl;
        roles_file << to_string(get<0>(r.strength_min_max)) << "-" << to_string(get<1>(r.strength_min_max)) << endl;
        roles_file << to_string(get<0>(r.intelligence_min_max)) << "-" << to_string(get<1>(r.intelligence_min_max)) << endl;
    }

    for (const auto &s : species){
        species_file << s.name << endl;
        species_file << s.life << endl;
        species_file << s.strength << endl;
        species_file << s.intelligence << endl;
        species_file << (s.natural == 1 ? "true" : "false") << endl;
        species_file << s.disquiet << endl;
    }

    for (const auto &e : eldritch_horror){
        eldritch_horror_file << e.name << endl;
        eldritch_horror_file << e.life << endl;
        eldritch_horror_file << e.strength << endl;
        eldritch_horror_file << e.intelligence << endl;
        eldritch_horror_file << e.traumatism << endl;
    }
}

template<class T>
void remove_from_vector(vector<T> &vec){
    if (vec.size() <= 0){
        cout << "This category is empty, nothing to remove!" << endl;
    } else {
        int i = 1;
        for (const auto &r : vec){
            cout << "(" << i << ") " <<  r.name << endl;
            i++;
        }
        cout << "(b) back" << endl;

        int choice; 
        char input_char; 
        cout << "\n> ";
        cin >> input_char;
        if (static_cast<int>(input_char) == 'b') return;
        choice = static_cast<int>(input_char) - '0';

        if (choice <= 0 || choice > vec.size()){
            cout << "\nInvalid choice!" << endl;
            return;
        }

        cout << "\n" << vec[choice - 1].name << " removed." << endl;
        vec.erase(vec.begin() + choice - 1);
    }

}

void remove_being(vector<Role> &roles, vector<Species> &species, vector<Eldritch_horror> &eldritch_horror){
    cout << "Select a being category: (type the corresponding number)\n" << endl;
    cout << "(1) Person" << endl;
    cout << "(2) Creature" << endl;
    cout << "(3) Eldritch horror" << endl;
    cout << "(b) back" << endl;
    cout << "\n> ";

    int choice;
    char input_char;
    cin >> input_char; cout << endl;
    if (static_cast<int>(input_char) == 'b') return;
    choice = static_cast<int>(input_char) - '0';

    if (choice == 1){
        remove_from_vector(roles);

    } else if (choice == 2){
        remove_from_vector(species);
    } else if (choice == 3){
        remove_from_vector(eldritch_horror);
    } else {
        cout << "Invalid choice!" << endl;
    }

    press_to_contin();
}

void save_roster(vector<Being*> characters){
    cout << "Type name for saved roster file (including .txt): "; 
    string name; cin >> name;

    ofstream characters_file(name);

    for (auto character : characters) {
        characters_file << "//" << endl;
        if (auto investigator_character = dynamic_cast<Investigator*>(character)) {
            investigator_character->write_to_file(characters_file);
        } else if (auto creature_character = dynamic_cast<Creature*>(character)) {
            creature_character->write_to_file(characters_file);
        } else if (auto person_character = dynamic_cast<Person*>(character)) {
            person_character->write_to_file(characters_file);
        } else if (auto eldritch_character = dynamic_cast<Eldritch*>(character)) {
            eldritch_character->write_to_file(characters_file);
        }
    }

    cout << "\nRoster: " << name << " saved." << endl;
    press_to_contin();
}

void load_roster(vector<Role> roles, vector<Species> species, vector<Eldritch_horror> eldritch_horror, 
vector<Being*> &characters){

    characters.clear();

    cout << "Type name for roster file you want to load (including .txt): "; 
    string name; cin >> name;

    read_characters_file(roles, species, eldritch_horror, characters, name);

    cout << "\nRoster: " << name << " loaded." << endl;
    press_to_contin();
}

int main(){
    srand(chrono::system_clock::to_time_t(chrono::system_clock::now()));

    // Reads the txt files with the existing roles/species/eldrich horrors
    vector<Role> roles = read_roles_file();
    vector<Species> species = read_species_file();
    vector<Eldritch_horror> eldritch_horror = read_eldritch_file();

    // List of characters that have been created
    vector<Being*> characters;

    // create a map with the creature counts 
    map<string, int> creature_counts = count_creature_instances(characters);

    cout << "---- Welcome to the characters sheets! ----\n" << endl;
    print_menu_options();

    int choice;
    char input_char;

    cin >> input_char; cout << endl;

    while (static_cast<int>(input_char) != 'q') {
        if (static_cast<int>(input_char) == 's') save_roster(characters);
        else if (static_cast<int>(input_char) == 'l') load_roster(roles, species, eldritch_horror, characters);

        else {
            choice = static_cast<int>(input_char) - '0';

            if (choice == 1) print_all_roles(roles);
            else if (choice == 2) print_all_creatures(species);
            else if (choice == 3) print_all_eldritch(eldritch_horror);
            else if (choice == 4) create_new_being(roles, species, eldritch_horror);
            else if (choice == 5) remove_being(roles, species, eldritch_horror);
            else if (choice == 6) create_new_character(roles, species, eldritch_horror,characters, creature_counts);
            else if (choice == 7) edit_character(characters);
            else if (choice == 8) print_character_roster(characters);
            else if (choice == 9) print_investigators(characters);
        }

        cout << "----------------------------" << endl;
        print_menu_options();

        cin >> input_char; cout << endl;
    }

    save_sheet(roles, species, eldritch_horror);
}
