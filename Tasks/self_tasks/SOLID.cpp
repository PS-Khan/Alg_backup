#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <cstring>
#include <queue>
#include <limits>
#include <vector>

using namespace std;


class Animal {
public:
    virtual void voice_sound() const = 0;  
    virtual ~Animal() {} 
};

class Animals_db {
    std::vector<Animal*> animals;  

public:
    void add_animal(Animal* animal) {
        animals.push_back(animal);
    }

    std::vector<Animal*>& get_animals() {
        return animals;
    }
};

class Lion : public Animal {
public:
    void voice_sound() const override {
        std::cout << "roar!";
    }
};

class Cat : public Animal {
public:
    void voice_sound() const override {
        std::cout << "Meow!";
    }
};

int main() {
    Animals_db animal_db;
    Lion l; Cat c;
    animal_db.add_animal(&l);
    std::vector<Animal*>& const animals = animal_db.get_animals();
    animal_db.add_animal(&c);
    animals = animal_db.get_animals();


    for (const Animal* animal : animals) {
        animal->voice_sound();
        std::cout << std::endl;
    }

    return 0;
}