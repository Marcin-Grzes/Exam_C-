//
//  main.cpp
//  Exam_task_3b
//
//  Created by Marcin Grześ on 20/01/2024.
//

#include <iostream>
#include <string>

class Car {
private:
    std::string marka;
    int przebieg;
    int wartosc;

public:
    Car(std::string m = "", int p = 0, int w = 0) : marka(m), przebieg(p), wartosc(w) {}

    Car(const Car &c) : marka(c.marka), przebieg(c.przebieg), wartosc(c.wartosc) {}

    bool operator==(const Car &c) const {
        return (marka == c.marka) && (przebieg == c.przebieg);
    }

    void cofnijLicznik(int wartosc) {
        przebieg = (wartosc < przebieg) ? (przebieg - wartosc) : 0;
    }

    Car operator+(const Car &c) const {
        std::string nowaMarka = (wartosc > c.wartosc) ? marka : c.marka;
        int nowyPrzebieg = (przebieg < c.przebieg) ? przebieg : c.przebieg;
        int nowaWartosc = (wartosc + c.wartosc) / 2 + 20;
        return Car(nowaMarka, nowyPrzebieg, nowaWartosc);
    }

    Car& operator+=(const Car &c) {
        if (wartosc < c.wartosc) {
            wartosc += 10000;
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream &os, const Car &c) {
        os << "Marka: " << c.marka << ", Przebieg: " << c.przebieg << ", Wartosc: " << c.wartosc;
        return os;
    }

    friend std::istream& operator>>(std::istream &is, Car &c) {
        is >> c.marka >> c.przebieg >> c.wartosc;
        return is;
    }
};

int main() {

    Car car1("Toyota", 50000, 150000);
    Car car2("Toyota", 30000, 170000);

    std::cout << "Car 1: " << car1 << std::endl;
    std::cout << "car 2: " << car2 << std::endl;

    if (car1 == car2) {
        std::cout << "Samochody mają tę samą markę i przebieg." << std::endl;
    } else {
        std::cout << "Samochody są różne." << std::endl;
    }

    car1.cofnijLicznik(10000);
    std::cout << "Car1 po cofnięciu licznika: " << car1 << std::endl;

    Car car3 = car1 + car2;
    std::cout << "Nowy samochód (car3): " << car3 << std::endl;

    return 0;
}
