#include<iostream>
#include<fstream>
using namespace std;

const int roomcount = 5;
const int invenmax = 10;

string roomNames[roomcount] = {
    "FCSE",
    "ACB",
    "CAFE",
    "TUC",
    "LIBRARY"
};

string roomDescriptions[roomcount] = {
    "A building where offices,lecture hall and labs are situated. ",
    "A building where many students are taking lectures.",
    "A place where tea and snacks are getting sale .",
    "place where many foods are being served and a reg desk is setted up.",
    "students are studing there ."
};
string puzzleQuestions[roomcount] = {
    "what is 2+2 ",
    "What comes after d",
    "A shape with no corners",
    "I m white but i have yellow inside me . i am oval guess who i am ?",
    "LIFE is not a bed of ------?"
};


string puzzleAnswers[roomcount] = {
    "4",
    "e",
    "circle",
    "egg",
    "roses"
};
