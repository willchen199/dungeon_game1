#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

// Class representing a player in the game
class Player {
public:
    std::string name;   // Player's name
    int health;         // Player's health
    int damage;         // Player's damage

    // Constructor to initialize player attributes
    Player(const std::string& playerName) : name(playerName), health(100), damage(20) {}

    // Function to display player's status
    void displayStatus() const {
        std::cout << "Player: " << name << " | Health: " << health << " | Damage: " << damage << std::endl;
    }
};

// Class representing a monster in the game
class Monster {
public:
    std::string type;   // Monster's type
    int health;         // Monster's health
    int damage;         // Monster's damage

    // Constructor to initialize monster attributes
    Monster(const std::string& monsterType) : type(monsterType), health(50), damage(15) {}

    // Function to display monster's status
    void displayStatus() const {
        std::cout << "Monster: " << type << " | Health: " << health << " | Damage: " << damage << std::endl;
    }
};

// Class representing the main game logic
class DungeonGame {
private:
    Player player;              // Player object
    std::vector<Monster> monsters;  // Vector to store monsters in the dungeon

public:
    // Constructor to initialize the game with a player and populate monsters
    DungeonGame(const std::string& playerName) : player(playerName) {
        // Populate monsters in the dungeon
        monsters.push_back(Monster("Goblin"));
        monsters.push_back(Monster("Skeleton"));
        monsters.push_back(Monster("Orc"));
    }

    // Function to display a welcome message
    void displayWelcomeMessage() const {
        std::cout << "Welcome to the Dungeon Crawler Game, " << player.name << "!\n";
    }

    // Function to simulate exploring the dungeon
    void exploreDungeon() {
        std::cout << "You enter the dark dungeon...\n";

        // Loop through each monster in the dungeon
        for (size_t i = 0; i < monsters.size(); ++i) {
            Monster& currentMonster = monsters[i];
            currentMonster.displayStatus();

            // Player encounters the monster
            std::cout << "You encounter a " << currentMonster.type << "!\n";

            // Battle with the monster
            while (player.health > 0 && currentMonster.health > 0) {
                // Player attacks
                int playerAttack = rand() % player.damage + 1;
                std::cout << "You attack the " << currentMonster.type << " for " << playerAttack << " damage!\n";
                currentMonster.health -= playerAttack;

                // Check if the monster is defeated
                if (currentMonster.health <= 0) {
                    std::cout << "You defeated the " << currentMonster.type << "!\n";
                    break;
                }

                // Monster attacks
                int monsterAttack = rand() % currentMonster.damage + 1;
                std::cout << "The " << currentMonster.type << " attacks you for " << monsterAttack << " damage!\n";
                player.health -= monsterAttack;

                // Check if the player is defeated
                if (player.health <= 0) {
                    std::cout << "You were defeated by the " << currentMonster.type << "!\n";
                    return;
                }

                // Display current status
                player.displayStatus();
                currentMonster.displayStatus();
            }

            // Ask if the player wants to continue exploring
            std::cout << "Do you want to continue exploring? (Y/N): ";
            char choice;
            std::cin >> choice;

            if (choice != 'Y' && choice != 'y') {
                std::cout << "You exit the dungeon.\n";
                return;
            }
        }

        std::cout << "You have successfully explored the entire dungeon!\n";
    }
};

// Main function where the program starts
int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation

    std::cout << "Enter your name: ";
    std::string playerName;
    std::cin >> playerName;

    // Create a DungeonGame object with the player's name
    DungeonGame game(playerName);

    // Display a welcome message
    game.displayWelcomeMessage();

    // Simulate exploring the dungeon
    game.exploreDungeon();

    return 0;
}