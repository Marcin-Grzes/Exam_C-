//
//  main.cpp
//  Exam_task_2
//
//  Created by Marcin Grześ on 20/01/2024.
//

#include <iostream>
#include <string>

using namespace std;

struct Student {
    string imie;
    int wiek;
    float* srednie;
    int lataStudiow;
};

int liczbaA(string str) {
    int count = 0;
    for (char c : str) {
        if (c == 'a' || c == 'A') count++;
    }
    return count;
}

int main() {
    int liczbaStudentow;
    cout << "Podaj liczbe studentow: ";
    cin >> liczbaStudentow;

    Student* studenci = new Student[liczbaStudentow];

    for (int i = 0; i < liczbaStudentow; i++) {
        cout << "Student " << i + 1 << " - Imie: ";
        cin >> studenci[i].imie;

        cout << "Wiek: ";
        cin >> studenci[i].wiek;

        cout << "Lata studiow (4, 5 lub 6): ";
        cin >> studenci[i].lataStudiow;
        studenci[i].srednie = new float[studenci[i].lataStudiow];

        for (int j = 0; j < studenci[i].lataStudiow; j++) {
            cout << "Srednia rok " << j + 1 << ": ";
            cin >> studenci[i].srednie[j];
        }
    }

    int sumaLat = 0;
    float sumaSrednich = 0;
    int liczbaStudentowSpełniającychWarunek = 0;

    for (int i = 0; i < liczbaStudentow; i++) {
        if (liczbaA(studenci[i].imie) >= 2) {
            sumaLat += studenci[i].lataStudiow;
            for (int j = 0; j < studenci[i].lataStudiow; j++) {
                sumaSrednich += studenci[i].srednie[j];
            }
            liczbaStudentowSpełniającychWarunek++;
           
        }
    }

    if (liczbaStudentowSpełniającychWarunek > 0) {
        float srednia = sumaSrednich / sumaLat;
        cout << "Srednia arytmetyczna wynikow: " << srednia << endl;
    } else {
        cout << "Brak studentow spelniajacych warunki." << endl;
    }

    for (int i = 0; i < liczbaStudentow; i++) {
        delete[] studenci[i].srednie;
    }
    delete[] studenci;

    return 0;
}

