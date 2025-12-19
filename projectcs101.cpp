#include<iostream>//using input output library 
#include<fstream>  //fstream lirary for file handling 
#include<string>//library for handling strings 
using namespace std; //using standrd namespace 
//intializing global varaible
const int roomcount = 5;
const int invenmax = 10; // initializing  constants 
// global array for room names 
string roomNames[roomcount] = {
    "FCSE",
    "ACB",
    "CAFE",
    "TUC",
    "LIBRARY"
};
// global array for descriptions of rooms
string roomDescriptions[roomcount] = {
    "A building where offices,lecture hall and labs are situated. ",
    "A building where many students are taking lectures.",
    "A place where tea and snacks are getting sale .",
    "place where many foods are being served and a reg desk is setted up.",
    "students are studing there ."
};
// global array for puzzle 
string puzzleQuestions[roomcount] = {
    "what is 2+2 ",
    "What comes after d",
    "A shape with no corners",
    "I m white but i have yellow inside me . i am oval guess who i am ?",
    "LIFE is not a bed of ------?"
};

// global array for answers of puzzle 
string puzzleAnswers[roomcount] = {
    "4",
    "e",
    "circle",
    "egg",
    "roses"
}; 
// global array for puzzle status 
bool puzzleSolved[roomcount] = { false, false, false, false, false };

// Inventory data
string inventory[invenmax];
int inventoryCount = 0;

// FUNCTION DECLARATIONS 
void mainMenu();
void startNewGame();
void loadGame();
void gameLoop(int startRoom);
void showRoomMenu(int *currentRoom);
void viewRoom(int room);
void showInventory();
void addItemToInventory(const string &itemName);
void saveGame(int currentRoom);
bool loadGameFromFile(int &currentRoom);
void moveToNextRoom(int *currentRoom);
void solvePuzzleRecursive(int roomIndex);//recursion used here

int main() { //main function 
    mainMenu();// calling main menu function
    return 0;
}

// MAIN MENU  function 
void mainMenu() {
    bool isRunning = true;  //declaring isrunning 

    while (isRunning) {
        cout << "===================================="<<endl;
        cout << "        MYSTERY ADVENTURE GAME      "<<endl;
        cout << "===================================="<<endl<<endl;
        cout << "1. Start New Game"<<endl;
        cout << "2. Load Game"<<endl;
        cout << "3. Exit"<<endl<<endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nStarting a new game..."<<endl<<endl;
                startNewGame();
                break;

            case 2:
                cout <<endl<<"Loading game..."<<endl<<endl;
                loadGame();
                break;

            case 3:
                cout << endl<<"Exiting game. Goodbye!"<<endl;
                isRunning = false;   
                break;

            default:
                cout << endl<<"Invalid choice. Please try again."<<endl<<endl;
                break;
        }
    }
} 

void startNewGame() {
    
    for (int i = 0; i < roomcount; i++) {
        puzzleSolved[i] = false;
    }

  
    inventoryCount = 0;

    int startingRoom = 0;
    gameLoop(startingRoom);
}


void loadGame() {
    int loadedRoom = 0;
    bool success = loadGameFromFile(loadedRoom);

    if (success) {
        cout << "Game loaded successfully!"<<endl;
        cout << "You are currently in: " << roomNames[loadedRoom] <<endl<<endl;
        gameLoop(loadedRoom);
    } else {
        cout << "No valid save file found. Starting a new game instead.\n\n";
        startNewGame();
    }
}
void gameLoop(int startRoom) {
    bool inGame = true;
    int currentRoom = startRoom;
    int *currentRoomPtr = &currentRoom;  

    while (inGame) {
       
        if (currentRoom >= roomcount) {
            cout << endl<<"You have reached the end of the mansion."<<endl;
            cout << "Congratulations, you completed the adventure!"<<endl<<endl;
            break;
        }

        cout << "------------------------------------"<<endl;
        cout << "You are now in: " << roomNames[currentRoom] << endl;
        cout << "------------------------------------"<<endl;

       
        showRoomMenu(currentRoomPtr);

       
        if (currentRoom >= roomcount) {
            cout << "\nYou step out into the daylight as the mansion disappears behind you."<<endl;
            cout << "========= GAME OVER ========="<<endl<<endl;
            break;
        }

       
        cout << "\nDo you want to continue this session? (y/n): ";
        char choice;
        cin >> choice;

        if (choice == 'n' || choice == 'N') {
            cout << endl<<"Returning to main menu..."<<endl<<endl;
            inGame = false;
        }
    }
}