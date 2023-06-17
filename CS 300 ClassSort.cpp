//Nicholas Martin

#include <iostream>
//for string input
#include <fstream>
#include <string>
//for the mapping
#include <map>
//#include "LinkedListNodes.cpp"
#include <vector>

using namespace std;

vector<int> codeNumerics;
vector<string> informitiveClass;

void clearScreen() {
    cout << "\033[2J\033[1;1H"; //this just clears the screen
}

//this is a conversion map to convert the letters of the class code to a numerical value.
//the numbers are a higher value to give them more weight when sorting, would not recommend opening or keeping open
int mappingLetters(char letter) {
    map<char, int> mp;
    mp['A'] = 100;
    mp['B'] = 200;
    mp['C'] = 300;
    mp['D'] = 400;
    mp['E'] = 500;
    mp['F'] = 600;
    mp['G'] = 700;
    mp['H'] = 800;
    mp['I'] = 900;
    mp['J'] = 1000;
    mp['K'] = 1100;
    mp['L'] = 1200;
    mp['M'] = 1300;
    mp['N'] = 1400;
    mp['O'] = 1500;
    mp['P'] = 1600;
    mp['Q'] = 1700;
    mp['R'] = 1800;
    mp['S'] = 1900;
    mp['T'] = 2000;
    mp['U'] = 2100;
    mp['V'] = 2200;
    mp['W'] = 2300;
    mp['X'] = 2400;
    mp['Y'] = 2500;
    mp['Z'] = 2600;
    mp['a'] = 100;
    mp['b'] = 200;
    mp['b'] = 300;
    mp['d'] = 400;
    mp['e'] = 500;
    mp['f'] = 600;
    mp['g'] = 700;
    mp['h'] = 800;
    mp['i'] = 900;
    mp['j'] = 1000;
    mp['k'] = 1100;
    mp['l'] = 1200;
    mp['m'] = 1300;
    mp['n'] = 1400;
    mp['o'] = 1500;
    mp['p'] = 1600;
    mp['q'] = 1700;
    mp['r'] = 1800;
    mp['s'] = 1900;
    mp['t'] = 2000;
    mp['u'] = 2100;
    mp['v'] = 2200;
    mp['w'] = 2300;
    mp['x'] = 2400;
    mp['y'] = 2500;
    mp['z'] = 2600;
    mp['1'] = 1;
    mp['2'] = 2;
    mp['3'] = 3;
    mp['4'] = 4;
    mp['5'] = 5;
    mp['6'] = 6;
    mp['7'] = 7;
    mp['8'] = 8;
    mp['9'] = 9;
    mp['0'] = 0;

    return mp[letter];

}


//The linked list didn't work out. It would not do what I wanted, switching to another method of storing data.
// 
//I was going to struct this but decided to make the linked list its own class
/*struct Node {
    int numericCode; //this is the numerical class code
    string classInformation; //this is all the information for the class
    Node* next;
};


//this creates new nodes in the linked list as new lines are read from the file
void insertNewNodes(Node* head, int classNumber, string classInfo) {
    
    Node* temporaryPointer;
    temporaryPointer = new Node(classNumber, classInfo);
    head = temporaryPointer;
    cout << temporaryPointer->classInformation << endl;
    
}

//This goes through all the nodes and prints them
void printClassList(Node* head) {

    Node* tempPnter;
    tempPnter = head;

    while (tempPnter != NULL) {
        cout << tempPnter->classInformation;
        tempPnter = tempPnter->next;
    }
}*/


//This adds to the vectors the number value and the line info
void addClassInList(string line, int classNumericalCode) {
    codeNumerics.push_back(classNumericalCode);
    informitiveClass.push_back(line);
}

//this sorts the class list using selection sort
void sortClassList() {
    for (int i = 0; i < codeNumerics.size(); i++) {
        int min = i;
        for (int j = i + 1; j < codeNumerics.size(); j++) {
            if (codeNumerics[min] > codeNumerics[j]) {
                min = j;
            }
        }
        int tempInteger = codeNumerics[i];
        codeNumerics[i] = codeNumerics[min];
        codeNumerics[min] = tempInteger;

        string tempString = informitiveClass[i];
        informitiveClass[i] = informitiveClass[min];
        informitiveClass[min] = tempString;
    }
    
}
//this will search through the list for the specific class
void searchingClasses(int requestedNumber) {
    for (int i = 0; i < codeNumerics.size(); i++) {
        if (codeNumerics[i] == requestedNumber) {
            cout << informitiveClass[i] << endl;
        }
                
    }
}

//this prints one of the vectors, the one with the information.
void printClassList() {
    for (auto it = informitiveClass.begin(); it != informitiveClass.end(); it++) {
        cout << *it << endl;
    }    
}

int loadFile() {
    string line;
    int classNumericalCode = 0;
    int numberStorage = 0;
    ifstream myfile("ABCU_Advising_Program_Input.txt");
    if (myfile.is_open())
    {

        while (getline(myfile, line)) {           
            classNumericalCode = 0;

            for (int i = 0; i < 4; i++) {
                classNumericalCode += mappingLetters(line[i]);
                
            }
            //this converts the number part of the class code to an actual integer
            classNumericalCode += mappingLetters(line[4]) * 100;
            classNumericalCode += mappingLetters(line[5]) * 10;
            classNumericalCode += mappingLetters(line[6]);

            addClassInList(line, classNumericalCode);

            //insertNewNodes(head, classNumericalCode, line);
            
        }
        myfile.close();
        sortClassList();
    }
    return 0;
}


//requests a class to search for then goes to search for it.
void specificClass() {
    string requestedClass = "Q";
    int requestedNumber = 0;
    cout << "What class code are you looking for?" << endl;
    cin >> requestedClass;
    if (requestedClass.length() < 7) {
        cout << "Not a valid class to search for." << endl;
    }

    for (int i = 0; i < 4; i++) {

        requestedNumber += mappingLetters(requestedClass[i]);
    }
    requestedNumber += mappingLetters(requestedClass[4]) * 100;
    requestedNumber += mappingLetters(requestedClass[5]) * 10;
    requestedNumber += mappingLetters(requestedClass[6]);
    searchingClasses(requestedNumber);
}

int mainMenu(int menuOption) {

    //clearScreen();

    cout << "Please enter an option?" << endl;
    cout << "1. Load File" << endl;
    cout << "2. Print All Classes" << endl;
    cout << "3. Search for a Class" << endl;
    cout << "9. Exit" << endl;
    cin >> menuOption;

    switch (menuOption) {
    case 1:
        loadFile();
        break;
    case 2:
        printClassList();
        break;
    case 3:
        specificClass();
        break;
    case 9:
        break;
    default:
        cout << "That is not a valid option" << endl;
        menuOption = 9;
        break;
    }
    return menuOption;
}


int main(){

    int menuOption = 0;
    while (menuOption != 9) { //this allows the menu to cylce more than once
        menuOption = mainMenu(menuOption);
    }

    cout << "Goodbye" << endl;
}


