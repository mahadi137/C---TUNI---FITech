#include <iostream>
using namespace std;

int main()
{
    cout << "Enter a number: ";

    // Write your code here
    int givenNumber, cube;
    cin >> givenNumber;

    cube = givenNumber*givenNumber*givenNumber;


    if (cube == 0 || cube % givenNumber == 0){
        cout << "The cube of " << givenNumber << " is " << cube <<"." << endl;
    } else if (cube < 0 || cube % givenNumber != 0){
         cout << "Error! The cube of " << givenNumber << " is not " << cube <<"." << endl;
    }


    return 0;
}
