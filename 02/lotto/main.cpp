#include <iostream>
using namespace std;


//FACTORIAL FUNCTION
 int factorial_of_number (int find_fac_lot_ball, int find_fac_draw_ball){


    long double initial_fact_lot = 1, initial_fact_lotdraw = 1,initial_fact_draw = 1; // the type is long double Bcoz the final calculation return a double value


    //Substraction
   int subtraction_lotdraw = (find_fac_lot_ball - find_fac_draw_ball);


    //factorialNumber_lot
    for (int i = 1; i <= find_fac_lot_ball; ++i){
         initial_fact_lot *= i;

    }


    //factorialNumber_lotdraw
    for (int j = 1; j <= subtraction_lotdraw; ++j){
        initial_fact_lotdraw *= j;

    }


    //factorialNumber_draw
    for (int k = 1; k <= find_fac_draw_ball; ++k){
            initial_fact_draw *= k;

    }


    //Calculation
   long double combination = initial_fact_lot/(initial_fact_lotdraw * initial_fact_draw);
   cout << "The probability of guessing all " << find_fac_draw_ball << " balls correctly is 1/" << combination <<endl;

   return 0;
}


 //DATA CHECKING FUNCTION
 int checkData (int check_lot, int check_draw){

     if (check_lot < 0){
         cout << "The number of balls must be a positive number." << endl;
     } else if (check_draw > check_lot) {
         cout << "The maximum number of drawn balls is the total amount of balls." << endl;
     } else {
          factorial_of_number (check_lot, check_draw);
     }
    return 0;//EXIT_SUCCESS
     }



//DATA RECIEVE FUNCTION
void lottoData (){
    int lot_ball, draw_ball;
    cout << "Enter the total number of lottery balls: ";
    cin >> lot_ball;

    cout << "Enter the number of drawn balls: ";
    cin >> draw_ball;
    //calling
    checkData (lot_ball, draw_ball);
}




int main() {
    // Write C++ code here
    lottoData ();



  return 0;
}


