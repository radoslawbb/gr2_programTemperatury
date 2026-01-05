// gr2_programTemperatury.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include "headerFile.h"
using namespace std;

int main()
{
    srand(time(NULL));
    while (1) {
        system("cls");
        menu();
        
        int opcja;

        cout << "Wybierz opcje: ";
        cin >> opcja;

        switch (opcja) {
        case 1:
            FtoC();
            break;
        case 2:
            FtoK();
            break;
        case 3:
            CtoF();
            break;
        case 4:
            CtoK();
            break;
        case 5:
            KtoC();
            break;
        case 6:
            KtoF();
            break;
        case 7:
            usunZHistorii();
            break;
        case 8:
            modHis();
            break;
        case 9:
            losHis();
            break;
        case 10:
            system("cls");
            wyborHistorii();
            break;
        default:
            return 0;
            break;
        }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
