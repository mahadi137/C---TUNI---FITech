#include <iostream>

using namespace std;

int main()
{
    cout << "Enter a positive number: ";

    // Write your code here
    int givenNumber = 0;
    int divInteger_1 = 0, divInteger_2 = 0;

    cin >> givenNumber;

    //Positive Number Checking
    if (givenNumber <= 0){
        cout << "Only positive numbers accepted" << endl;

    } else {
        //Nearest Factor checking
            for (int i = 1; i * i <= givenNumber; ++i){
            if (givenNumber % i == 0){
                 divInteger_1 = i;
                }
            }

            divInteger_2 = givenNumber/divInteger_1;

     cout << givenNumber << " = " <<divInteger_1 << " * " << divInteger_2 <<endl;
    }

    return 0;
}
