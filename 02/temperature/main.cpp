#include <iostream>

using namespace std;

int main()
{
    cout << "Enter a temperature: ";

    float givenTemp, formulaCelToFah, formulaFahToCel;
    cin >> givenTemp;

    // Celcius to Fahrenheit
    formulaCelToFah = (givenTemp * 1.8) + 32;
    cout << givenTemp << " degrees Celsius is " << formulaCelToFah << " degrees Fahrenheit" << endl;

    // Fahrenheit to Celcius
    formulaFahToCel = (givenTemp - 32) / 1.8;
    cout << givenTemp << " degrees Fahrenheit is " << formulaFahToCel << " degrees Celsius" << endl;


    return 0;
}
