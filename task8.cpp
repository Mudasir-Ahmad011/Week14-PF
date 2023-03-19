#include <iostream>
#include<windows.h>
#include<conio.h>
#include<fstream>
using namespace std;
void loadData(char plane[][6], int rowsize);
void gotoxy(int x, int y);
char getCharAtxy(short int x, short int y);
void resetPlane_seat(char plane[][6], int rowsize);
void printPlane_seat(char plane[][6], int rowsize);
void storePlane_seat(char plane[][6], int rowsize);
bool check(string ticket_type, string desired_type);
void booking(string ticket_type, string desired_type, char plane[][6], int rowsize);
int menu();
int number(char me);
int seatX = 0;
int seatY = 0;
main() {
    char plane[13][6];
    loadData(plane, 13);
    while (true) {
        system("cls");
        int choice = menu();
        if (choice == 1) {
            loadData(plane, 13);
        }
        if (choice == 2) {
            string ticket_type, desired_seat;
            cout << "Enter the ticket type: ";
            cin.clear();
            cin.sync();
            getline(cin, ticket_type);
            cout << "Enter desired seat: ";
            cin >> desired_seat;
            booking(ticket_type, desired_seat, plane, 13);
        }
        if (choice == 3) {
            printPlane_seat(plane, 13);
        }
        if (choice == 4) {
            storePlane_seat(plane, 13);
        }
        if (choice == 5) {
            resetPlane_seat(plane, 13);
        }
        getch();
        storePlane_seat(plane, 13);
    }


}
int menu() {
    int choice;
    cout << "1. Load the reserved seats arranagement" << endl;
    cout << "2. Ask the user for ticket type and desired type" << endl;
    cout << "3. Print the reserved seat arrangement" << endl;
    cout << "4. Store the reserved seat arranagement" << endl;
    cout << "5. New plane arranagement" << endl;
    cin >> choice;
    return choice;
}
int number(char me, char me2) {
    int num;
    if (me == '1' && me2 == '0') {
        num = 10;
    }
    else if (me == '1' && me2 == '1') {
        num = 11;
    }
    else if (me == '1' && me2 == '2') {
        num = 12;
    }
    else if (me == '1' && me2 == '3') {
        num = 13;
    }
    else if (me == '1') {
        num = 1;
    }
    else if (me == '2') {
        num = 2;
    }
    else if (me == '3') {
        num = 3;
    }
    else if (me == '4') {
        num = 4;
    }
    else if (me == '5') {
        num = 5;
    }
    else if (me == '6') {
        num = 6;
    }
    else if (me == '7') {
        num = 7;
    }
    else if (me == '8') {
        num = 8;
    }
    else if (me == '9') {
        num = 9;
    }
    return num;
}
bool check(string ticket_type, string desired_seat) {
    bool isbool = false;
    int length = desired_seat.length();
    char me = desired_seat[1];
    char me2 = ' ';
    if (length == 3) {
        me2 = desired_seat[2];
    }
    int num = number(me, me2);
    if (ticket_type == "first class") {
        if (num <= 2) {
            isbool = true;
        }
    }
    if (ticket_type == "business class") {
        if (num >= 3 && num <= 7) {
            isbool = true;
        }
    }
    if (ticket_type == "economy class") {
        if (num >= 8 && num <= 13) {
            isbool = true;
        }
    }
    return isbool;
}
void booking(string ticket_type, string desired_seat, char plane[][6], int rowsize) {
    bool checking = check(ticket_type, desired_seat);
    int length = desired_seat.length();
    char me = desired_seat[1];
    char me2 = ' ';
    if (length == 3) {
        me2 = desired_seat[2];
    }
    int num = number(me, me2);
    int col;
    if (checking == true) {
        char current;
        if (desired_seat[0] == 'A') {
            col = 0;
            current = plane[num - 1][col];
        }
        if (desired_seat[0] == 'B') {
            col = 1;
            current = plane[num - 1][col];
        }
        if (desired_seat[0] == 'C') {
            col = 2;
            current = plane[num - 1][col];
        }
        if (desired_seat[0] == 'D') {
            col = 3;
            current = plane[num - 1][col];
        }
        if (desired_seat[0] == 'E') {
            col = 4;
            current = plane[num - 1][col];
        }
        if (desired_seat[0] == 'F') {
            col = 5;
            current = plane[num - 1][col];
        }
        if (current == '*') {
            plane[num - 1][col] = 'X';
        }
        if (current == 'X') {
            cout << "Seat is not available";
        }
    }
    checking = false;
}
void loadData(char plane[][6], int rowsize) {
    fstream myFile;
    myFile.open("plane.txt", ios::in);
    string line;
    int row = 0;
    while (getline(myFile, line)) {
        for (int index = 0;index < line.length();index++) {
            plane[row][index] = line[index];
        }
        row++;
    }
    myFile.close();
}
void printPlane_seat(char plane[][6], int rowsize) {
    for (int i = 0;i < rowsize;i++) {
        for (int j = 0;j < 6;j++) {
            cout << plane[i][j];
        }
        cout << endl;
    }
}
void storePlane_seat(char plane[][6], int rowsize) {
    fstream myFile;
    myFile.open("plane.txt", ios::out);
    for (int i = 0;i < rowsize;i++) {
        for (int j = 0;j < 6;j++) {
            myFile << plane[i][j];
        }
        myFile << endl;
    }
    myFile.close();
}
void resetPlane_seat(char plane[][6], int rowsize) {
    for (int i = 0;i < rowsize;i++) {
        for (int j = 0;j < 6;j++) {
            plane[i][j] = '*';
        }
    }
}

void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

char getCharAtxy(short int x, short int y) {
    CHAR_INFO ci;
    COORD xy = { 0,0 };
    SMALL_RECT rect = { x,y,x,y };
    COORD coordBufsize;
    coordBufsize.X = 1;
    coordBufsize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufsize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}