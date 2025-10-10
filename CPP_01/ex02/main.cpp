#include <iostream>
#include <iomanip>

using namespace std;

int	main()
{
	string	str = "Hi this is brain";
	string	*stringPTR = &str;
	string	&stringREF = str;

	cout << setw(35) << left << "adress of string: " << &str << endl;
	cout << setw(35) << left << "adress held by pointer: " << stringPTR << endl;
	cout << setw(35) << left << "adress held by reference: " << &stringREF << endl;

	cout << setw(35) << left << "value of string: " << str << endl;
	cout << setw(35) << left << "value pointed to by pointer: " << *stringPTR << endl;
	cout << setw(35) << left << "value pointed to by reference: " << stringREF << endl;
	return (0);
}