/////////////////////
// Class: GAME1011
// Name: John Husky
// ID: 101426515
// Date: Feb 03-05 2023
///Prod: LAB2
/////////////////////




#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Weapon {
public:
    Weapon(string name, int damage) : name(name), damage(damage) {}
    string name;
    int damage;
    vector<string> specialAbilities;

    friend ostream& operator<<(ostream& os, const Weapon& weapon) {
        os << "Weapon name: " << weapon.name << endl;
        os << "Damage: " << weapon.damage << endl;
        os << "Special abilities: ";
        for (auto ability : weapon.specialAbilities) {
            os << ability << " ";
        }
        return os;
    }

    bool operator==(const Weapon& rhs) const {
        return (this->name == rhs.name) && (this->damage == rhs.damage);
    }
};

class Armour {
public:
    Armour(string name, int value) : name(name), value(value) {}
    string name;
    int value;
    string description;

    friend ostream& operator<<(ostream& os, const Armour& armour) {
        os << "Armour name: " << armour.name << endl;
        os << "Armour value: " << armour.value << endl;
        os << "Description: " << armour.description << endl;
        return os;
    }

    bool operator==(const Armour& rhs) const {
        return (this->name == rhs.name) && (this->value == rhs.value);
    }
};

class Character {
public:
    Character(string name, string species, int health, Weapon weapon, Armour armour)
        : name(name), species(species), health(health), weapon(weapon), armour(armour) {}
    string name;
    string species;
    int health;
    Weapon weapon;
    Armour armour;
    string epicBackstory;

    friend ostream& operator<<(ostream& os, const Character& character) {
        os << "Character name: " << character.name << endl;
        os << "Species: " << character.species << endl;
        os << "Health: " << character.health << endl;
        os << character.weapon << endl;
        os << character.armour << endl;
        os << "Backstory: " << character.epicBackstory << endl;
        return os;
    }

    bool operator==(const Character& rhs) const {
        return (this->name == rhs.name) && (this->health == rhs.health);
    }
};

void createCharacter(vector<Character>& characters) {
    string name, species, epicBackstory;
    int health;
    cout << "Enter character name: ";
    cin >> name;
    cout << "Enter species: ";
    cin >> species;
    cout << "Enter starting health value (100-200): ";
    cin >> health;
    cout << "Enter backstory: ";
    cin.ignore();
    getline(cin, epicBackstory);
    system("pause");
    system("CLS");
    vector<Weapon> weapons = {
     Weapon("Sword", 10),
     Weapon("Axe", 20),
     Weapon("Bow", 15),
     Weapon("Spear", 25)
    };
    cout << "1. Sword" << endl;
    cout << "2. Axe" << endl;
    cout << "3. Bow" << endl;
    cout << "4. Spear" << endl;
    int weaponChoice;
    cout << "Enter weapon choice: ";
    cin >> weaponChoice;
    Weapon chosenWeapon = weapons[weaponChoice - 1];
    system("pause");
    system("CLS");

    cout << "Available armours:" << endl;
    vector<Armour> armours = {
        Armour("Leather", 5),
        Armour("Chain", 10),
        Armour("Plate", 15)
    };
    cout << "1. Leather" << endl;
    cout << "2. Chain" << endl;
    cout << "3. Plate" << endl;
    int armourChoice;
    cout << "Enter armour choice: ";
    cin >> armourChoice;
    Armour chosenArmour = armours[armourChoice - 1];
    system("pause");
    system("CLS");
    Character newCharacter(name, species, health, chosenWeapon, chosenArmour);
    newCharacter.epicBackstory = epicBackstory;
    characters.push_back(newCharacter);
}

void compareCharacters(const vector<Character>& characters) {
    int firstChoice, secondChoice;
    cout << "Enter first character to compare (1-" << characters.size() << "): ";
    cin >> firstChoice;
    cout << "Enter second character to compare (1-" << characters.size() << "): ";
    cin >> secondChoice;
    if (characters[firstChoice - 1] == characters[secondChoice - 1]) {
        cout << "The two characters have the same stats." << endl;
    }
    else {
        cout << "The two characters have different stats." << endl;
    }
}

void displayCharacter(const vector<Character>& characters) {
    int choice;
    cout << "Enter character to display (1-" << characters.size() << "): ";
    cin >> choice;
    cout << characters[choice - 1] << endl;
    system("pause");
    system("CLS");
}

int main() {
    cout << "Welcome to the character Editor v2.2.2G!" << endl;
    vector<Character> characters;
    int choice = 1;
    while (choice != 0 && characters.size() < 3) {
        cout << "1. Create a new character" << endl;
        cout << "2. Compare stats of two characters" << endl;
        cout << "3. Display information of a character" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        system("pause");
        system("CLS");
        switch (choice) {
        case 1:
            createCharacter(characters);
            break;
        case 2:
            compareCharacters(characters);
            break;
        case 3:
            displayCharacter(characters);
            break;
        case 0:
            cout << "Exiting character customizer." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
            break;
        }
    }
    return 0;
}
