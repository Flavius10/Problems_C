#include<iostream>
using namespace std;

class Animal
{
public:

	Animal()
	{}

	Animal(string name, int age)
	{}

private:
	string name;
	int age;
};

int main()
{
	Animal animal = Animal("Caine", 10);
	string nume = animal.nume;
}