PA4 - Character sheets - Group XX

We would like to claim the full 100% plus the 10% bonus (more details below)

-------------------------------------------
To compile:

g++ main.cpp being.cpp -std=c++11 -o pa4

To run:

.\pa4.exe
-------------------------------------------
When using the program:

The code has some error checks but will often fail if the user types invalid things when prompted. 
Most of these fails are when e.g. the user types a value of an option that doesn't exist. 
If the user reads what the program is asking for and follows that, the code should never crash. 

Example: 

- Names can be with spaces, genders can not (code will crash or get messed up)
- Code will sometimes crash when the user types a letter when he is asked for a number 
(there are some error checks for this tho, back button (b) is always okay to use if it is on the screen) 

-------------------------------------------
Structure:

The code runs with 3 txt files:

roles.txt - includes all of the persons (roles) that have been created.
species.txt - includes all of the creatures (species) that have been created.
eldritch.txt - includes all of the eldritch horrors that have been created.

DO NOT go into these files if you want to change beings in the game, always do it through the program itself. 

It is possible to create new creatures/roles in the game (option 4 on the menu).
The game will save all of the creatures/roles that are created (in the same txt files) when you press "q" (quit) on the menu.

Each being can be used when creating a character. The character roster can be saved by pressing
"s" on the menu, or a new roster can be loaded by pressing "l" on the menu. 

The characters are created by using the classes in being.h/being.cpp, the roles/species/eldritch are created
by using the structs in being.h and then stored in vectors. 
Note that options 7-9 are empty if there are no characters in the game. 

--------------------------------------------
Example for the bonus:

Start the code with: .\pa4.exe

1) Load roster:

This will run the program with an empty characters list (i.e. no characters in the game).

To load a character roster: type "l", then type the name of the characters roster file you want to load. 
You can use roster1.txt/roster2.txt/roster3.txt, or any roster than you have saved.

After this, the roster has been loaded. You can test it by printing the roster with options 8 and 9 on the menu.

2) Save roster:

First create some characters with option 6 in the menu.
When you want to save the roster, press "s" on the menu and type the name of the file you want to store the roster in.

The code will then save the roster, but it will keep running with the same roster after that. 
If you want to update it more, you can do that but you will have to save again. 
