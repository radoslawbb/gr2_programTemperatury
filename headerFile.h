#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std; 

double pamiec[100] = { 0 };
char pamiecZ[100] = { 0 };
int dataCounter = 0;
int ileC = 0, ileF = 0, ileK = 0;

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
    while (!(cin >> stopnie)) {
        cout << "Wprowadz poprawnie dane: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    return stopnie;
}

float pobierzF() {
    float stopnie;
    cout << "Podaj stopnie (F): ";
    while (!(cin >> stopnie)) {
        cout << "Wprowadz poprawnie dane: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    return stopnie;
}

float pobierzK() {
    float stopnie;
    cout << "Podaj stopnie (K): ";
    while (!(cin >> stopnie)) {
        cout << "Wprowadz poprawnie dane: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
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
        if (dataCounter <= 98) {
            float wynik = (5.0 / 9.0) * (stopnie - 32.0);
            cout << "F: " << stopnie << " C: " << wynik << endl;
            pamiec[dataCounter] = stopnie;
            pamiecZ[dataCounter] = 'F';
            pamiec[dataCounter + 1] = wynik;
            pamiecZ[dataCounter + 1] = 'C';
            dataCounter += 2;
            ileF++;
            system("pause");
            return wynik;
        }
        else {
            cout << "Przekroczono limit" << endl;
            system("pause");
            return 0;
        }
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
        if (dataCounter <= 98) {
            float wynik = (5.0 / 9.0) * (stopnie + 459.67);
            cout << "F: " << stopnie << " K: " << wynik << endl;
            pamiec[dataCounter] = stopnie;
            pamiecZ[dataCounter] = 'F';
            pamiec[dataCounter + 1] = wynik;
            pamiecZ[dataCounter + 1] = 'K';
            dataCounter += 2;
            ileF++;
            system("pause");
            return wynik;
        }
        else {
            cout << "Przekroczono limit" << endl;
            system("pause");
            return 0;
        }
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
        if (dataCounter <= 98) {
            float wynik = stopnie * (9.0 / 5.0) + 32.0;
            cout << "C: " << stopnie << " F: " << wynik << endl;
            pamiec[dataCounter] = stopnie;
            pamiecZ[dataCounter] = 'C';
            pamiec[dataCounter + 1] = wynik;
            pamiecZ[dataCounter + 1] = 'F';
            dataCounter += 2;
            ileC++;
            system("pause");
            return wynik;
        }
        else {
            cout << "Przekroczono limit" << endl;
            system("pause");
            return 0;
        }
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
        if (dataCounter <= 98) {
            float wynik = stopnie + 273.15;
            cout << "C: " << stopnie << " K: " << wynik << endl;
            pamiec[dataCounter] = stopnie;
            pamiecZ[dataCounter] = 'C';
            pamiec[dataCounter + 1] = wynik;
            pamiecZ[dataCounter + 1] = 'K';
            dataCounter += 2;
            ileC++;
            system("pause");
            return wynik;
        }
        else {
            cout << "Przekroczono limit" << endl;
            system("pause");
            return 0;
        }
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
        if (dataCounter <= 98) {
            float wynik = stopnie - 273.15;
            cout << "K: " << stopnie << " C: " << wynik << endl;
            pamiec[dataCounter] = stopnie;
            pamiecZ[dataCounter] = 'K';
            pamiec[dataCounter + 1] = wynik;
            pamiecZ[dataCounter + 1] = 'C';
            dataCounter += 2;
            ileK++;
            system("pause");
            return wynik;
        }
        else {
            cout << "Przekroczono limit" << endl;
            system("pause");
            return 0;
        }
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
        if (dataCounter <= 98) {
            float wynik = stopnie * (9.0 / 5.0) - 459.67;
            cout << "K: " << stopnie << " F: " << wynik << endl;
            pamiec[dataCounter] = stopnie;
            pamiecZ[dataCounter] = 'K';
            pamiec[dataCounter + 1] = wynik;
            pamiecZ[dataCounter + 1] = 'F';
            dataCounter += 2;
            ileK++;
            system("pause");
            return wynik;
        }
        else {
            cout << "Przekroczono limit" << endl;
            system("pause");
            return 0;
        }
    }
}

void pokazHistorie() {
    int licz = 0;
    for (int i = 0; i < dataCounter / 2; i++) {
        cout << "<" << i + 1 << "> " << pamiec[licz] << pamiecZ[licz] << " = " << pamiec[licz + 1] << pamiecZ[licz + 1] << endl;
        licz += 2;
    }
}

void menu() {
    cout << "1 - przelicz Fahr -> Celsius" << endl;
    cout << "2 - przelicz Fahr -> Kelwin" << endl;
    cout << "3 - przelicz Celsius -> Fahr" << endl;
    cout << "4 - przelicz Celsius -> Kelwin" << endl;
    cout << "5 - przelicz Kelwin -> Celsius" << endl;
    cout << "6 - przelicz Kelwin -> Fahr" << endl;
    cout << "7 - usun z historii" << endl;
    cout << "8 - modyfikacja wpisu z historii" << endl;
    cout << "9 - losowe wypelnienie historii" << endl;
    cout << "10 - pokaz historie" << endl;
    cout << "11 - zakoncz dzaialanie programu" << endl;
}

void wyborHistorii() {
    int poz;
    cout << "Wybierz pozycje: " << endl;
    cout << "1. Tylko C -> inne" << endl;
    cout << "2. Tylko F -> inne" << endl;
    cout << "3. Tylko K -> inne" << endl;
    cout << "4. Cala historia" << endl;
    while (!(cin >> poz)) {
        cout << "Wprowadz poprawnie dane: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    switch (poz) {
    case 1:
        if (ileC > 0) {
            int licz = 0;
            for (int i = 0; i < dataCounter / 2; i++) {
                if (pamiecZ[licz] == 'C') {
                    cout << "<" << i + 1 << "> " << pamiec[licz] << pamiecZ[licz] << " = " << pamiec[licz + 1] << pamiecZ[licz + 1] << endl;
                } 
                licz += 2;
            }
        }
        else {
            cout << "brak danych" << endl;
        }

        system("pause");
        break;
    case 2:
        if (ileF > 0) {
            int licz = 0;
            for (int i = 0; i < dataCounter / 2; i++) {
                if (pamiecZ[licz] == 'F') {
                    cout << "<" << i + 1 << "> " << pamiec[licz] << pamiecZ[licz] << " = " << pamiec[licz + 1] << pamiecZ[licz + 1] << endl;
                }
                licz += 2;
            }
        }
        else {
            cout << "brak danych" << endl;
        }

        system("pause");
        break;
    case 3:
        if (ileK > 0) {
            int licz = 0;
            for (int i = 0; i < dataCounter / 2; i++) {
                if (pamiecZ[licz] == 'K') {
                    cout << "<" << i + 1 << "> " << pamiec[licz] << pamiecZ[licz] << " = " << pamiec[licz + 1] << pamiecZ[licz + 1] << endl;
                }
                licz += 2;
            }
        }
        else {
            cout << "brak danych" << endl;
        }

        system("pause");
        break;
    case 4:
        if (ileC == 0 && ileK == 0 && ileF == 0) {
            cout << "brak danych" << endl;

            system("pause");
        }
        else {
            pokazHistorie();
            system("pause");
        }
        break;
    default:
        break;
    }
}

void usunZHistorii() {
    int entityToRemove;
    system("cls");
    pokazHistorie();
    cout << "Ktora linie usunac?: ";
    while (!(cin >> entityToRemove)) {
        cout << "Wprowadz poprawnie dane: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    if (entityToRemove > dataCounter/2) {
        cout << "Nie istnieje taka pozycja w historii" << endl;
        system("pause");
    }
    else {
        for (int i = entityToRemove * 2; i < dataCounter * 2 - 1; i++) {
            pamiec[i-2] = pamiec[i];
            pamiecZ[i-2] = pamiecZ[i];
            pamiec[i-1] = pamiec[i+1];
            pamiecZ[i-1] = pamiecZ[i+1];
        }
        dataCounter -= 2;
    }
}

void modHis() {
    int poz, nowaTemp, temp;
    char nowaTempZnak, znak;
    string nowaTemperatura;
    pokazHistorie();
    cout << "Ktora linie modyfikowac?: ";
    while (!(cin >> poz)) {
        cout << "Wprowadz poprawnie dane: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    if (poz > dataCounter / 2) {
        cout << "Nie istnieje taka pozycja w historii" << endl;
        system("pause");
    }
    else {
        cout << "\nPodaj nowa temperature (np. 10F): " << endl;
        cin >> nowaTemperatura;
        if (nowaTemperatura.empty()) {
            cout << "Nie podano poprawnie temperatury" << endl;
            system("pause");
        }
        else {
            nowaTempZnak = nowaTemperatura[nowaTemperatura.length() - 1];
            nowaTemp = stoi(nowaTemperatura.substr(0, nowaTemperatura.length() - 1));
            /*cout << "Int: " << nowaTemp << endl;
            cout << "Char: " << nowaTempZnak << endl;*/
            if (nowaTempZnak != 'K' && nowaTempZnak != 'F' && nowaTempZnak != 'C') {
                cout << "Podano nieprawidlowy znak" << endl;
                system("pause");
            }
            else {
                pamiec[poz] = nowaTemp;
                pamiecZ[poz] = nowaTempZnak;
                cout << "Na co? (Podaj znak odpowiadajacy stopniom temperatury (np. F, C, K))" << endl;
                cin >> znak;
                if (znak == nowaTempZnak) {
                    cout << "Podano ten sam znak" << endl;
                }
                else {
                    switch (znak) {
                    case 'K':
                        if (nowaTempZnak == 'C') {
                            temp = nowaTemp + 273;
                            pamiec[poz+1] = temp;
                            pamiecZ[poz+1] = 'K';
                        }
                        else if (nowaTempZnak == 'F') {
                            temp = (nowaTemp + 460) * 5 / 9;
                            pamiec[poz+1] = temp;
                            pamiecZ[poz+1] = 'K';
                        }
                        else {
                            cout << "blad" << endl;
                        }
                        break;
                    case 'C':
                        if (nowaTempZnak == 'K') {
                            temp = nowaTemp - 273;
                            pamiec[poz+1] = temp;
                            pamiecZ[poz+1] = 'C';
                        }
                        else if (nowaTempZnak == 'F') {
                            temp = (nowaTemp - 32) * 5 / 9;
                            pamiec[poz+1] = temp;
                            pamiecZ[poz+1] = 'C';
                        }
                        else {
                            cout << "blad" << endl;
                        }
                        break;
                    case 'F':
                        if (nowaTempZnak == 'K') {
                            temp = nowaTemp * 9 / 5 - 460;
                            pamiec[poz+1] = temp;
                            pamiecZ[poz+1] = 'F';
                        }
                        else if (nowaTempZnak == 'C') {
                            temp = nowaTemp * 9 / 5 + 32;
                            pamiec[poz+1] = temp;
                            pamiecZ[poz+1] = 'F';
                        }
                        else {
                            cout << "blad" << endl;
                        }
                        break;
                    default:
                        cout << "blad" << endl;
                        break;
                    }
                    system("pause");
                }
            }
        }
    }
}

void losHis() {
    int ilosc;
    char znak;
    cout << "Podaj ile losowych wartosci przeliczyc: ";
    while (!(cin >> ilosc)) {
        cout << "Wprowadz poprawnie dane: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    if (ilosc > (100 - dataCounter*2)) {
        cout << "Podana liczba przekracza zakres tablicy" << endl;
        cout << "Czy chcesz wygenerowac tyle wpisow ile zostalo miejsca? (T/N): ";
        cin >> znak;
        switch (znak) {
        case 'T':
            for (int i = 0; i < 100 - (dataCounter * 2); i++) {
                int liczba = rand() % 3;
                char z1, z2;
                float t1, t2;
                switch (liczba) {
                case 0:
                    t1 = -273 + rand() % 1000;
                    z1 = 'C';
                    liczba = rand() % 2;
                    if (liczba == 0) {
                        t2 = t1 * 9 / 5 + 32;
                        z2 = 'F';
                        ileF++;
                    }
                    else {
                        t2 = t1 + 273;
                        z2 = 'K';
                        ileK++;
                    }
                    pamiec[dataCounter] = t1;
                    pamiecZ[dataCounter] = z1;
                    pamiec[dataCounter + 1] = t2;
                    pamiecZ[dataCounter + 1] = z2;
                    ileC++;
                    dataCounter += 2;
                    break;
                case 1:
                    t1 = -460 + rand() % 1000;
                    z1 = 'F';
                    liczba = rand() % 2;
                    if (liczba == 0) {
                        t2 = (t1 - 32) * 5 / 9;
                        z2 = 'C';
                        ileC++;
                    }
                    else {
                        t2 = (t1 + 460) * 5 / 9;
                        z2 = 'K';
                        ileK++;
                    }
                    pamiec[dataCounter] = t1;
                    pamiecZ[dataCounter] = z1;
                    pamiec[dataCounter + 1] = t2;
                    pamiecZ[dataCounter + 1] = z2;
                    ileF++;
                    dataCounter += 2;
                    break;
                case 2:
                    t1 = rand() % 1000;
                    z1 = 'K';
                    liczba = rand() % 2;
                    if (liczba == 0) {
                        t2 = t1 - 273;
                        z2 = 'C';
                        ileC++;
                    }
                    else {
                        t2 = t1 * 9 / 5 - 460;
                        z2 = 'F';
                        ileF++;
                    }
                    pamiec[dataCounter] = t1;
                    pamiecZ[dataCounter] = z1;
                    pamiec[dataCounter + 1] = t2;
                    pamiecZ[dataCounter + 1] = z2;
                    ileK++;
                    dataCounter += 2;
                    break;
                default:
                    break;
                }
            }
            system("pause");
            break;
        case 'N':
            break;
        default:
            break;
        }
    }
    else {
        for (int i = 0; i < ilosc; i++) {
            int liczba = rand() % 3;
            char z1, z2;
            int t1, t2;
            switch (liczba) {
            case 0:
                t1 = -273 + rand() % 1000;
                z1 = 'C';
                liczba = rand() % 2;
                if (liczba == 0) {
                    t2 = t1 * 9 / 5 + 32;
                    z2 = 'F';
                    ileF++;
                }
                else {
                    t2 = t1 + 273;
                    z2 = 'K';
                    ileK++;
                }
                pamiec[dataCounter] = t1;
                pamiecZ[dataCounter] = z1;
                pamiec[dataCounter + 1] = t2;
                pamiecZ[dataCounter + 1] = z2;
                ileC++;
                dataCounter += 2;
                break;
            case 1:
                t1 = -460 + rand() % 1000;
                z1 = 'F';
                liczba = rand() % 2;
                if (liczba == 0) {
                    t2 = (t1 - 32) * 5 / 9;
                    z2 = 'C';
                    ileC++;
                }
                else {
                    t2 = (t1 + 460) * 5 / 9;
                    z2 = 'K';
                    ileK++;
                }
                pamiec[dataCounter] = t1;
                pamiecZ[dataCounter] = z1;
                pamiec[dataCounter + 1] = t2;
                pamiecZ[dataCounter + 1] = z2;
                ileF++;
                dataCounter += 2;
                break;
            case 2:
                t1 = rand() % 1000;
                z1 = 'K';
                liczba = rand() % 2;
                if (liczba == 0) {
                    t2 = t1 - 273;
                    z2 = 'C';
                    ileC++;
                }
                else {
                    t2 = t1 * 9 / 5 - 460;
                    z2 = 'F';
                    ileF++;
                }
                pamiec[dataCounter] = t1;
                pamiecZ[dataCounter] = z1;
                pamiec[dataCounter + 1] = t2;
                pamiecZ[dataCounter + 1] = z2;
                dataCounter += 2;
                ileK++;
                break;
            default:
                break;
            }
        }
        system("pause");
    }
}