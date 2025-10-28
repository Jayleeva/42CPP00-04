//#include "Animal.hpp"
//#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
    {
        std::cout << "***\nMain 0" << std::endl;
        int     n = 4;
        Animal  *array = new Animal[n];

        int i = 0;
        while (i < n/2)
        {
            array[i] = Dog();
            array[i + n/2] = Cat();
            i ++;
        }
        std::cout << "HELLO" << std::endl;
        delete[] array;
    }

    {
        std::cout << "***\nMain 0" << std::endl;
        int     n = 4;
        Animal  *array[n];

        int i = 0;
        while (i < n/2)
        {
            array[i] = new Dog();
            array[i + n/2] = new Cat();
            i ++;
        }
        std::cout << "HELLO" << std::endl;
        i = 0;
        while (i < n)
        {
            delete array[i];
            i ++;
        }
    }
    {
        std::cout << "***\nMain 1" << std::endl;
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        delete j;
        delete i;
    }

}