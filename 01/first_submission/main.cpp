#include <iostream>
#include <string>

int main()
{
    std::string name = "";
    std::cout << "Enter your name: ";
    getline(std::cin, name);

    int age = 0;
    std::cout << "Enter your age: ";
    std::cin >> age;

    std::cout << "Pleased to meet you, " << name << "!" << std::endl;

    //New output line
    int newAge = age + 1;
    std::cout << "In your next birthday you'll be " << newAge << " years old!" << std::endl;
    //

    return EXIT_SUCCESS;
}
