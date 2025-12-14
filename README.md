#include<iostream>         //using input output library 
#include<fstream>         //fetream library for file handling 
#include<string>         //library for handling strings 
using namespace std;   //using stranderd namespace 
//global variables 
const int roomcount=5;   //initializing constants
const int invenmax=10;    //initializing constants
//global array for rooom names 
string roomNames[roomcount]={
"FCSE",
"ACB",
"CAFE",
"TUC",
"LIBRARY"
};
//global array for description of rooms 
string roomDescriptions[roomcount]={
"A building where offices,labs and lectures hall are situated",
"A building where many students are taking lectures",
"A place where tea and snacks are getting sold",
"A place where many foods are offered and a reg desk is setted up",
"Students are studing there "
};
//global array for puzzle 
string puzzleQuestions[roomcount]={
"What is 2+2?",
"What comes after d?",
"A shape with no corners ---",
"I am white but i have yellow inside me . I am oval guess who i am?",
"Life is not a bed of ----?"
};
//global array for answers of puzzle 
string puzzleAnswers[roomcount]={
"4",
"e",
"circle",
"egg",
"roses"
};
//global array for puzzle status
bool puzzleSolved[roomcount]={false,false,false,false,false};
//Inventory data
string inventory[invenmax];
int inventoryCount=0;
//function prototype
//we are declaring the follwing function before main so we can use them in main
void mainMenu();
void startNewGame();
void loadGame();
void gameLoop(int startRoom);
void shoeRoomMenu(int *currentroom);
void viewRoom(int room);
void showInventory();
void addItemToInventory(const string &itemName);
void saveGame(int currentRoom);
boolloadGameFromFile(int &currentRoom);
void moveToNextRoom(int *currentRoom);
void solvePuzzleRecursive(int roomIndex);     //recursion used here 
int main(){  //main function
  mainMenu(); //calling main menu function 
  return 0;
}
//Main menu function 
void mainMenu(){
 bool isRunning = true; //declaring is running 
 while(isRunning){      //using while loop to show main menueah time 
  cout<<"=================================="<<endl;
  cout<<"     MYSTERY ADVENTURE GAME       "<<endl;
  cout<<"=================================="<<endl<<endl;
  cout<<"1. Start New Game "<<endl;
  cout<<"2. Load Game "<<endl;
  cout<<"3. Exit "<<endl<<endl;
  cout<<"Enter your choice :";
  int choice;     //declaring choice 
  cin>>choice     //input from user 
  cout << endl;
  switch (choice)
    case 1: 
      cout << "Starting new game .."<<endl<<endl;
      startNewGame();
      break;
    case 2:
      cout << "loading game ...."<<endl<<endl;
      loadGame ();
      break;
    case 3:
      cout << Exiting game .Good bye ....."<<end<<endl;
      isRunning = false ;
      break;
  default : 
    cout << "Invalid choice . Please try again ."<<endl <<endl;
  //START NEW GAME
  void atartNewGame (){
    //reset puzzles to unsolved 
    for (int i = 0; i <roomcount ; i++ ){
          puzzleSolved [i] = false ;
    }
    //clear inventory 
    inventoryCount = 0;
    bool success = loadGameFromFile(loadedRoom);
    if (success){
          cout << "Game loaded successfully "<<endl;
          cout << "you are currently in ... "<<roomNames[loadedRoom]<<endl<<endl;
          gameloop(loadedRoom);
    }
    else {
        cout << "No valid save file found .Starting a new game instead "<<endl<<endl;
        startNewGame ();
      }
  }
  //Main game loop 
  void gameLoop(int startRoom){
            bool inGame = true;
            int currentRoom = startRoom;
            int currentRoomPtr = &currentRoom;
            while(inGame){
                //player move to last room 
                if (currentRoom >= countroom ){
                    cout << "you have reached at the end of giki "<< endl;
                    cout << "congratulation you have completed the adventure "<<endl << endl;
                    break;
                }
            cout << "================================="<<endl;
            cout << "now you are in : << roomNames [currentRoom] << endl;
            cout << "=================================="<< endl;
            showRoomMenu(currentRoomPtr);
            if (currentRoomMenu >= roomcount){
                      cout << "you finally stepped out from giki "<<endl;
                      cout <<"===========Game Over ============"<<endl;
              }
                        
                












 



























