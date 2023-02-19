#include <iostream>


int main()
{
    std::cout << "How many numbers would you like to have? ";

    // Write your code here
    int catchInput;
    int i = 0;
    std::cin >> catchInput;

    //Loop for numbers
    while( i < catchInput ){
         i++;
        //Conditions
         if ((i % 3 == 0 && i % 7 == 0)){
            std::cout << "zip boing" << std::endl;
            }
         else if (i % 3 == 0){
             std::cout << "zip" << std::endl;
         }
         else if (i % 7 == 0){
             std::cout << "boing" << std::endl;
         }
        else {
             std::cout << i << std::endl;
        }
    }

    return 0;
}
