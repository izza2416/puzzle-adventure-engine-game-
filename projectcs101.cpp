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

    while (isRunning) {  //using while loop to show main menu each time 
        cout << "===================================="<<endl;
        cout << "        MYSTERY ADVENTURE GAME      "<<endl;
        cout << "===================================="<<endl<<endl;
        cout << "1. Start New Game"<<endl;
        cout << "2. Load Game"<<endl;
        cout << "3. Exit"<<endl<<endl;
        cout << "Enter your choice: ";

        int choice; //declaring choice 
        cin >> choice; //user input choice

        switch (choice) { //using switch 
            case 1:
                cout << "\nStarting a new game..."<<endl<<endl;
                startNewGame();//calling startnewgame function
                break; //using break so it should stop 

            case 2:
                cout <<endl<<"Loading game..."<<endl<<endl;
                loadGame();  //calling newgame 
                break;

            case 3:
                cout << endl<<"Exiting game. Goodbye!"<<endl;
                isRunning = false;   // stop main menu loop
                break;

            default: 	//defalut for wrong choice 
                cout << endl<<"Invalid choice. Please try again."<<endl<<endl;
                break;
        }
    }
} 
//start new game 
void startNewGame() {
    // reset puzzles to unsolved
    for (int i = 0; i < roomcount; i++) {
        puzzleSolved[i] = false;
    }

  //clear inventory
    inventoryCount = 0;

    int startingRoom = 0; //initializing starting room 
    gameLoop(startingRoom); //recurssive function
}

//load game entry
void loadGame() {
    int loadedRoom = 0; //initializing
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
// MAIN GAME LOOP (ROOM PROGRESSION)
void gameLoop(int startRoom) {
    bool inGame = true;
    int currentRoom = startRoom;
    int *currentRoomPtr = &currentRoom;  // pointer to current room

    while (inGame) {
        // If player has moved beyond last room ? game finished
        if (currentRoom >= roomcount) {
            cout << endl<<"You have reached the end of the mansion."<<endl;
            cout << "Congratulations, you completed the adventure!"<<endl<<endl;
            break;
        }

        cout << "------------------------------------"<<endl;
        cout << "You are now in: " << roomNames[currentRoom] << endl;
        cout << "------------------------------------"<<endl;

       // Show room menu that uses pointer and functions
        showRoomMenu(currentRoomPtr);

       // If player completed all rooms inside room menu
        if (currentRoom >= roomcount) {
            cout << "\nYou step out into the daylight as the mansion disappears behind you."<<endl;
            cout << "========= GAME OVER ========="<<endl<<endl;
            break;
        }
          // Ask if player wants to keep playing this session
        cout << endl<<"Do you want to continue this session? (y/n): ";
        char choice;
        cin >> choice;

        if (choice == 'n' || choice == 'N') {
            cout << endl<<"Returning to main menu..."<<endl<<endl;
            inGame = false;
        }
    }
}
// FUNCTION FOR ROOM MENU  
void showRoomMenu(int *currentRoom) {
    bool stayInRoom = true;      //bool condition for staying in the room 

    while (stayInRoom) {        //while condition until the user want to stay in the room 
        cout << endl << "Room Menu " << roomNames[*currentRoom] << endl;
        //option for room menu 
        cout << "1. View Room Details" << endl;
        cout << "2. Solve Puzzle" << endl;
        cout << "3. Show Inventory" << endl;
        cout << "4. Move to Next Room" << endl;
        cout << "5. Save Game" << endl;
        cout << "6. Exit to Main Menu"<< endl;
        cout << "Enter your choice: " << endl;

        int choice;         					//declaring choice variable 
        cin >> choice;							//user  input 
        
		//using switch for different choices 
        switch (choice) {      
			//view room         
            case 1:
                viewRoom(*currentRoom);
                break;				//using break
			//solving puzzle 
            case 2:
            		//if else condition for checking puzzle 
                if (puzzleSolved[*currentRoom]) {				//if puzzle is correct 
                    cout << "\nThe puzzle in this room is already solved."<< endl << endl;
                } else {										//if puzzle is wrong 
                    cout << "Attempting puzzle" << endl;
                    solvePuzzleRecursive(*currentRoom);   // calling recurrsive function 
                }
                break;			
			//show inventory 
            case 3:
                showInventory();       // calling function 
                break;					
			//next room 
            case 4:
                moveToNextRoom(currentRoom);		//recurrsive function 
                // if wan to go another room leave this room 
                if (*currentRoom >= roomcount) {
                    stayInRoom = false;
                }
                break;     				
			//save game 
            case 5:
                saveGame(*currentRoom);				//calling function 
                break;         
			//exit game 				
            case 6:
                cout << endl << "Exiting to main menu from this room..." << endl;
                stayInRoom = false;			
                break;			

            default:		//condition if the choice is wrong 
                cout << endl << "Invalid choice, please try again."<< endl;
                break;				
        }

        // in the last room if user want to change room show error 
        if (!stayInRoom) {
            break;    			//using break
        }
    }
}
// ROOM DETAILS 
void viewRoom(int room) {		
    cout << endl << "Room: " << roomNames[room] << endl << endl;    //showing room names 
    cout << roomDescriptions[room] << endl ;     // array for rooms 

    if (puzzleSolved[room]) {		//if puzzle solved show this message 
        cout << endl << "Status: Puzzle solved." << endl << endl;
    } 
	else {    //if puzzle is not solved  show this message 
        cout << "Status: Puzzle not solved yet."<< endl << endl;
    }
}

// SHOW INVENTORY 
void showInventory() {     
    cout << "---------- Inventory ----------"<< endl;
    // condition if user want to see inventory in the start of game 
    if (inventoryCount == 0) {       
        cout << "Your inventory is empty."<< endl;
    }
	 // if user want to see inventory durinh game 
	 else {
	 	// using for loop of user want to see inventory at any instant of the game 
        for (int i = 0; i < inventoryCount; i++) {      	
            cout << (i + 1) << ". " << inventory[i] << endl ;
        }
    }
    cout << "-------------------------------" << endl;
}

//  ADD ITEM TO INVENTORY 
void addItemToInventory(const string &itemName) {     //using call to refrence 
    if (inventoryCount < invenmax) {		//if condition for item les avilable  
        inventory[inventoryCount] = itemName; 
        inventoryCount++;    //incrementing items 
        cout << "Item added to inventory: " << itemName << endl;
    } else {			// condition if items finish in room 
        cout << "Inventory is full! Cannot add more items." << endl;
    }
}

// SAVING  GAME TO FILE 
void saveGame(int currentRoom) {    
    ofstream outFile("savefile.txt");      //opening file 
    if (!outFile) {						//if file does not open show error 
        cout << "Error opening save file for writing.\n";
        return;
    }
    // Save current room
    outFile << currentRoom << endl;
    // Save puzzleSolved array using for loop 
    for (int i = 0; i < roomcount; i++) {
        outFile << puzzleSolved[i] << " ";
    }
    outFile << endl ; //next line in file 

    // Save inventoryCount  and items
    outFile << inventoryCount << endl;
    for (int i = 0; i < inventoryCount; i++) { // for loop for saving inventory in file 
        outFile << inventory[i] << endl;
    }

    outFile.close();     //closing file 
    cout << endl <<  "Game saved successfully to " << "savefile.txt" << endl ;
}
// LOAD GAME FROM FILE 
bool loadGameFromFile(int &currentRoom) {   // using refrence loop 
    ifstream inFile("savefile.txt");       //reading from file 
    if (!inFile) {						//if file does not open 
        return false;   // file not found
    }
    // Load current room
    inFile >> currentRoom;

    // Load puzzleSolved array
    for (int i = 0; i < roomcount; i++) {
        int val;     //declaring variable 
        inFile >> val;               // 0 or 1
        puzzleSolved[i] = (val != 0);        
    }

    // Load inventoryCount and items
    inFile >> inventoryCount;    // reading from file 
    inFile.ignore(); // ignore empty  newline
    for (int i = 0; i < inventoryCount; i++) {   //for loop for reading file 
        getline(inFile, inventory[i]);
    }

    inFile.close();   //closing file 
    return true;     //returning true because it is bool type function
}
// MOVE TO NEXT ROOM 
void moveToNextRoom(int *currentRoom) {     // using pass by pointer 
    if (*currentRoom >= roomcount) {		//if user is in last room 
        cout << endl << "You are already beyond the last room." << endl;
        return;
    }
    if (!puzzleSolved[*currentRoom]) {          // if user want to go to another room without solving puzzle 
        cout << "You cannot move to the next room yet." << endl;
        cout << "Solve the puzzle in this room first." << endl;
        return;
    }
    cout << endl << "The door unlocks and slowly opens..." << endl ;
    (*currentRoom)++;     //incrementing the room number pointer 

    if (*currentRoom >= roomcount) {        //condition if puzzle is solved 
        cout << "You walk through the final door towards freedom." << endl;
    } 
	else {
        cout << "You move into the next room: " << roomNames[*currentRoom] << endl;
    }
}
// SOLVE PUZZLE 
void solvePuzzleRecursive(int roomIndex) {      //recurrsive function 
    cout << "Puzzle for room: " << roomNames[roomIndex] << endl;
    cout << "Question: " << endl << puzzleQuestions[roomIndex] << endl;
    cout << "Enter your answer (single word, lowercase): ";
    string answer;       // declaring string variable 
    cin >> answer;		//input user 
    if (answer == puzzleAnswers[roomIndex]) {		//if puzzle solved  sow message 
        cout <<  endl << "Correct! You solved the puzzle." << endl;
        puzzleSolved[roomIndex] = true;     // increasing room index 
        // Example reward item
        string reward = "Key from " + roomNames[roomIndex];     // reward 
        addItemToInventory(reward);   			//recurrsive function  calling another function inside this function 
    }