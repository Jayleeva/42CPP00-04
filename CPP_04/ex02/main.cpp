//#include "Animal.hpp"
//#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
    {
        std::cout << "***\nMain 0\nCreates an array of half Dogs half Cats, sets and exposes some of their thoughts and then delete them as Animals" << std::endl;
        int     n = 4;
        Animal  *array[n];

        for (int i = 0; i < n/2; i ++)
        {
            array[i] = new Dog();
            array[i + n/2] = new Cat();  
        }
		array[0]->getBrain().setIdea(0, "Let's go for a walk!!!");
		array[0]->getBrain().setIdea(50, "I want my toy!");
		array[0]->getBrain().setIdea(99, "Excuse me can I get some of that? It smells good!");
		std::cout << "First animal's first thought is: \"" << array[0]->getBrain().getIdea(0) << "\"" << std::endl;
		std::cout << "First animal's 50th thought is: \"" << array[0]->getBrain().getIdea(50) << "\"" << std::endl;
		std::cout << "First animal's last thought is: \"" << array[0]->getBrain().getIdea(99) << "\"" << std::endl;
        for (int i = 0; i < n; i++)
            delete array[i];
    }
	{
		std::cout << "***\nMain 1\nCheck deep copy of Dog (no double free + thoughts are different because set after the copy):" << std::endl;
		Dog *dogA = new Dog;
		Dog *dogB = new Dog(*dogA);

        dogA->getBrain().setIdea(0, "I'M SO FAST!!!");
        dogB->getBrain().setIdea(0, "Please don't go to work, stay with meeeee");
        std::cout << "dogA's first thought is: \"" << dogA->getBrain().getIdea(0) << "\"" << std::endl;
        std::cout << "dogB's first thought is: \"" << dogB->getBrain().getIdea(0) << "\"" << std::endl;
		delete dogA;
		delete dogB;
	}
    {
        std::cout << "***\nMain 2\nGiven main" << std::endl;
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        delete j;
        delete i;
    }
}