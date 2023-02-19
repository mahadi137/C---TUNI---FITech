#include <cstdlib>
#include <iostream>
#include <deque>

// Write your swap function here.
void swap (int& value_i, int& value_j){//learning about referenceValues and references


       int copvalue_j = value_i;
       int copvalue_i = value_j;
       value_i = copvalue_i;
       value_j = copvalue_j;




}



#ifndef UNIT_TESTING
int main()
{
    std::cout << "Enter an integer: ";
    int i = 0;
    std::cin >> i;

    std::cout << "Enter another integer: ";
    int j = 0;
    std::cin >> j;

    swap(i, j);
    std::cout << "The integers are " << i << " and " << j << std::endl;

    return EXIT_SUCCESS;
}
#endif
