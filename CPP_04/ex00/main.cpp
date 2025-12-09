#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    {
        std::cout << "***\nMain 0\n------" << std::endl;
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
        std::cout << "***\nMain 1\n------" << std::endl;
        const WrongAnimal* meta = new WrongAnimal();
        const Animal* j = new Dog();
        const WrongAnimal* i = new WrongCat();

        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); //will output the rong cat sound!
        j->makeSound();
        meta->makeSound();
        delete meta;
        delete i;
        delete j;
    }
    {
        std::cout << "***\nMain 2\n------" << std::endl;
        Animal  a("Cat");
        Animal  b("Dog");
        Animal  c = Cat();
        Animal  d = Dog();

        std::cout << a.getType() << " a goes: ";
        a.makeSound();
        std::cout << b.getType() << " b goes: ";
        b.makeSound();
        std::cout << c.getType() << " c goes: ";
        c.makeSound();
        std::cout << d.getType() << " d goes: ";
        d.makeSound();
        std::cout << std::endl;
    }
}