//#include "Animal.hpp"
//#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
    {
        Animal  array[4];

        int i = 0;
        while (i < 2)
        {
            array[i] = new Dog();
            i ++;
        }
        while (i < 4)
        {
            array[i] = new Cat();
            i ++;
        }
    }
    {
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        delete j;//should not create a leak
        delete i;
    }

}