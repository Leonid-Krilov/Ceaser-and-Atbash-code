#include <iostream>
#include "stdio.h"

using namespace std;

void CeaserCode(char buff[])
{
    for (int i = 0; i < strlen(buff); i++) {
        if (buff[i] != ' ')
            buff[i] += 3;
    }
    cout << "Code: " << buff << endl;

    cout << "Decode: ";
    for (int i = 0; i < strlen(buff); i++) {
        if (buff[i] != ' ')
            buff[i] -= 3;
    }
    cout << buff << endl;
}

void Atbash(const char* text, char* newtext)
{
    do {
        if (*text > 64 && *text < 91) *newtext = 155 - *text;
        else if (*text > 96 && *text < 123) *newtext = 219 - *text;
        else *newtext = *text;
    } while (newtext++, *text++);
    *newtext = 0;
}

int main() {
    int TaskNumber;
    char text[100] = { 0 };
    char  newtext[100];

    cout << "Enter message: ";
    cin.getline(text, 100);

    cout << "\n\n1-Ceaser code.\n2-Atbash code.\n\nEnter the task number > ";
    cin >> TaskNumber;

    while (true) {
        switch (TaskNumber) {
        case 1:
            CeaserCode(text);
            break;
        case 2:
            Atbash(text, newtext);
            cout << "\nCode: " << newtext << endl;
            Atbash(newtext, text);
            cout << "Decode: " << text << endl;
            break;
        default:
            cout << "\nError!\n";
            break;
        }
        break;
    }
    return 0;
}