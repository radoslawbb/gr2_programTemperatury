// gr2_programTemperatury.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
using namespace std;

int check(float temp, char stopnie) {
    switch (stopnie) {
        case 'K':
            if (temp < 0) return -999.0;
            break;
        case 'C':
            if (temp < -273.15) return -999.0;
            break;
        case 'F':
            if (temp < -459.67) return -999.0;
            break;
        default:
            return temp;
            break;
    }
}

float pobierzC() {
    float stopnie;
    cout << "Podaj stopnie (C): ";
    cin >> stopnie;
    return stopnie;
}

float pobierzF() {
    float stopnie;
    cout << "Podaj stopnie (F): ";
    cin >> stopnie;
    return stopnie;
}

float pobierzK() {
    float stopnie;
    cout << "Podaj stopnie (K): ";
    cin >> stopnie;
    return stopnie;
}

float FtoC() {
    float stopnie = pobierzF();
    int sprawdz = check(stopnie, 'F');
    if (sprawdz == -999.0) {
        cout << "Nie ma takiej temperatury" << endl;
        system("pause");
    }
    else {
        float wynik = (5.0 / 9.0) * (stopnie - 32.0);
        cout << "F: " << stopnie << " C: " << wynik << endl;
        system("pause");
        return wynik;
    }
}

float FtoK() {
    float stopnie = pobierzF();
    int sprawdz = check(stopnie, 'F');
    if (sprawdz == -999.0) {
        cout << "Nie ma takiej temperatury" << endl;
        system("pause");
    }
    else {
        float wynik = (5.0 / 9.0) * (stopnie + 459.67);
        cout << "F: " << stopnie << " K: " << wynik << endl;
        system("pause");
        return wynik;
    }
}

float CtoF() {
    float stopnie = pobierzC();
    int sprawdz = check(stopnie, 'C');
    if (sprawdz == -999.0) {
        cout << "Nie ma takiej temperatury" << endl;
        system("pause");
    }
    else {
        float wynik = stopnie * (9.0 / 5.0) + 32.0;
        cout << "C: " << stopnie << " F: " << wynik << endl;
        system("pause");
        return wynik;
    }
}

float CtoK() {
    float stopnie = pobierzC();
    int sprawdz = check(stopnie, 'C');
    if (sprawdz == -999.0) {
        cout << "Nie ma takiej temperatury" << endl;
        system("pause");
    }
    else {
        float wynik = stopnie + 273.15;
        cout << "C: " << stopnie << " K: " << wynik << endl;
        system("pause");
        return wynik;
    }
}

float KtoC() {
    float stopnie = pobierzK();
    int sprawdz = check(stopnie, 'K');
    if (sprawdz == -999.0) {
        cout << "Nie ma takiej temperatury" << endl;
        system("pause");
    }
    else {
        float wynik = stopnie - 273.15;
        cout << "K: " << stopnie << " C: " << wynik << endl;
        system("pause");
        return wynik;
    }
}

float KtoF() {
    float stopnie = pobierzK();
    int sprawdz = check(stopnie, 'K');
    if (sprawdz == -999.0) {
        cout << "Nie ma takiej temperatury" << endl;
        system("pause");
    }
    else {
        float wynik = stopnie * (9.0 / 5.0) - 459.67;
        cout << "K: " << stopnie << " F: " << wynik <<endl;
        system("pause");
        return wynik;
    }
}

void menu() {
    cout << "1 - przelicz Fahr -> Celsius" << endl;
    cout << "2 - przelicz Fahr -> Kelwin" << endl;
    cout << "3 - przelicz Celsius -> Fahr" << endl;
    cout << "4 - przelicz Celsius -> Kelwin" << endl;
    cout << "5 - przelicz Kelwin -> Celsius" << endl;
    cout << "6 - przelicz Kelwin -> Fahr" << endl;
    cout << "7 - zakoncz dzaialanie programu" << endl;
}

int main()
{
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
