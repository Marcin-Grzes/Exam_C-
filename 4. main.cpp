//
//  main.cpp
//  Exam_task_4
//
//  Created by Marcin Grześ on 20/01/2024.
//

#include <iostream>
#include <vector>

class Ssak {
protected:
    float waga;
    float wiek;

public:
    Ssak(float waga, float wiek) : waga(waga), wiek(wiek) {}

    float SprawdzWage() const {
        return waga;
    }

    float SprawdzWiek() const {
        return wiek;
    }

    virtual void PijWode() = 0;
    virtual void JemSiano() {}
    virtual void JemWszystkoOproczSiana() {}
};

class Kon : public Ssak {
public:
    Kon(float waga, float wiek) : Ssak(waga, wiek) {}

    void PijWode() override {
    };

    void JemSiano()override {
    };
};

class Krowa : public Ssak {
public:
    Krowa(float waga, float wiek) : Ssak(waga, wiek) {}

    void PijWode() override {
    };

    void JemSiano() override {
    };
};

class Owca : public Ssak {
public:
    Owca(float waga, float wiek) : Ssak(waga, wiek) {}

    void PijWode() override {
    };

    void JemSiano() override {
    };
};

class Swinia : public Ssak {
public:
    Swinia(float waga, float wiek) : Ssak(waga, wiek) {}

    void PijWode() override {

    };

    void JemWszystkoOproczSiana() override{
        
    };
};

int main() {
    std::vector<Ssak*> zwierzeta = {
        new Kon(800, 20), new Kon(700, 10),
        new Krowa(500, 5), new Krowa(700, 4),
        new Owca(100, 5), new Owca(120, 7), new Owca(160, 8),
        new Swinia(300, 5), new Swinia(350, 6), new Swinia(250, 2)
    };

    float sumaWody = 0;
    float sumaSiana = 0;
    float najlzejszeZwierze = zwierzeta[0]->SprawdzWage();
    float najstarszeZwierze = zwierzeta[0]->SprawdzWiek();

    for (auto zwierze : zwierzeta) {
        if (auto kon = dynamic_cast<Kon*>(zwierze)) {
            sumaWody += 5;
            sumaSiana += 100;
        } else if (auto krowa = dynamic_cast<Krowa*>(zwierze)) {
            sumaWody += 3;
            sumaSiana += 80;
        } else if (auto owca = dynamic_cast<Owca*>(zwierze)) {
            sumaWody += 2;
            sumaSiana += 40;
        } else if (auto swinia = dynamic_cast<Swinia*>(zwierze)) {
            sumaWody += 1;
        }

        if (zwierze->SprawdzWage() < najlzejszeZwierze) {
            najlzejszeZwierze = zwierze->SprawdzWage();
        }

        if (zwierze->SprawdzWiek() > najstarszeZwierze) {
            najstarszeZwierze = zwierze->SprawdzWiek();
        }
    }

    std::cout << "Całkowita ilość wypitej wody: " << sumaWody << "l" << std::endl;
    std::cout << "Całkowita ilość zjedzonego siana: " << sumaSiana << " jednostek" << std::endl;
    std::cout << "Najlżejsze zwierzę waży: " << najlzejszeZwierze << "kg" << std::endl;
    std::cout << "Najstarsze zwierzę ma: " << najstarszeZwierze << " lat" << std::endl;

    return 0;
}
