//#include "Animal.hpp"
//#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    {
        std::cout << "***\nMain 0" << std::endl;
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); //will output the cat sound!
        j->makeSound();
        meta->makeSound();
        delete meta;
        delete i;
        delete j;
    }
    {
        std::cout << "***\nMain 1" << std::endl;
        const WrongAnimal* meta = new WrongAnimal();
        const Animal* j = new Dog();
        const WrongAnimal* i = new WrongCat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); //will output the cat sound!
        j->makeSound();
        meta->makeSound();
        delete meta;
        delete i;
        delete j;
    }
}