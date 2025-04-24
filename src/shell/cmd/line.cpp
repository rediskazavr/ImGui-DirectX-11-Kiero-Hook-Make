#include <iostream>
#include <limits>
#include <stdio.h>

#include "line.hpp"
#include "../../dll_inject.hpp"
using namespace std;

void line() {
    int choice;
    while (true) {
        cout << "%enter%: ";
        
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                main_func();
                break;
            case 2:
                return;
                break;
            case 3:
                cout << "Example3" << endl;
                break;
            case 4:
            cout << "Example4" << endl;
            break;
            case 5:
            cout << "Example5" << endl;
            break;
            case 6:
            cout << "Example6" << endl;
            break;
            case 7:
            cout << "Example7" << endl;
            break;
            case 8:
            cout << "Example8" << endl;
            break;
            case 9:
            cout << "Example9" << endl;
            break;
            case 10:
            return;
            break;
            default:
                cout << "$Error: command not found" << endl;
                break;
        }
    }
}
