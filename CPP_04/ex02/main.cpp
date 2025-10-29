//#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
    {
        std::cout << "***\nMain 0\nCreates an array of half Dogs half Cats, sets and exposes some of their thoughts and then delete them as Animals" << std::endl;
        int     n = 4;
        AAnimal  *array[n];

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
    //juste? 
	{
		std::cout << "***\nMain 2\nCheck deep copy of Cat (no double free + thoughts are different even if set before the copy), using assignment operator overload:" << std::endl;
		Cat *catA = new Cat;
		Cat *catB = new Cat;

        catA->getBrain().setIdea(0, "I'M A PREDATOR!!!");
        catB->getBrain().setIdea(0, "We cuddle when I say we cuddle.");
    
		*catA = *catB;

        std::cout << "catA's first thought is: \"" << catA->getBrain().getIdea(0) << "\"" << std::endl;
        std::cout << "catB's first thought is: \"" << catB->getBrain().getIdea(0) << "\"" << std::endl;
		delete catA;
		delete catB;
	}
    {
        std::cout << "***\nMain 3\nGiven main" << std::endl;
        const AAnimal* j = new Dog();
        const AAnimal* i = new Cat();
        delete j;
        delete i;
    }
}