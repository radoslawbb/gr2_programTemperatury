using namespace std; 

double pamiec[100] = { 0 };
char pamiecZ[100] = { 0 };
int dataCounter = 0;

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
        pamiec[dataCounter] = stopnie;
        pamiecZ[dataCounter] = 'F';
        pamiec[dataCounter + 1] = wynik;
        pamiecZ[dataCounter + 1] = 'C';
        dataCounter += 2;
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
        pamiec[dataCounter] = stopnie;
        pamiecZ[dataCounter] = 'F';
        pamiec[dataCounter + 1] = wynik;
        pamiecZ[dataCounter + 1] = 'K';
        dataCounter += 2;
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
        pamiec[dataCounter] = stopnie;
        pamiecZ[dataCounter] = 'C';
        pamiec[dataCounter + 1] = wynik;
        pamiecZ[dataCounter + 1] = 'F';
        dataCounter += 2;
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
        pamiec[dataCounter] = stopnie;
        pamiecZ[dataCounter] = 'C';
        pamiec[dataCounter + 1] = wynik;
        pamiecZ[dataCounter + 1] = 'K';
        dataCounter += 2;
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
        pamiec[dataCounter] = stopnie;
        pamiecZ[dataCounter] = 'K';
        pamiec[dataCounter + 1] = wynik;
        pamiecZ[dataCounter + 1] = 'C';
        dataCounter += 2;
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
        cout << "K: " << stopnie << " F: " << wynik << endl;
        pamiec[dataCounter] = stopnie;
        pamiecZ[dataCounter] = 'K';
        pamiec[dataCounter + 1] = wynik;
        pamiecZ[dataCounter + 1] = 'F';
        dataCounter += 2;
        system("pause");
        return wynik;
    }
}

void pokazHistorie() {
    int licz = 0;
    for (int i = 0; i < dataCounter / 2; i++) {
        cout << "<" << i + 1 << "> " << pamiec[licz] << pamiecZ[licz] << " = " << pamiec[licz + 1] << pamiecZ[licz + 1] << endl;
        licz += 2;
    }
    system("pause");
}

void menu() {
    cout << "1 - przelicz Fahr -> Celsius" << endl;
    cout << "2 - przelicz Fahr -> Kelwin" << endl;
    cout << "3 - przelicz Celsius -> Fahr" << endl;
    cout << "4 - przelicz Celsius -> Kelwin" << endl;
    cout << "5 - przelicz Kelwin -> Celsius" << endl;
    cout << "6 - przelicz Kelwin -> Fahr" << endl;
    cout << "7 - pokaz historie" << endl;
    cout << "8 - zakoncz dzaialanie programu" << endl;
}