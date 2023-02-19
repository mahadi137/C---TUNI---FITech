#include "account.hh"
#include <iostream>

Account::Account(const std::string& owner, bool has_credit):
    owner_(owner), has_credit_(has_credit)
{
    generate_iban();


}

// Setting initial value for the static attribute running_number_
int Account::running_number_ = 0;


void Account::generate_iban()
{
    ++running_number_;
    std::string suffix = "";
    if(running_number_ < 10)
    {
        suffix.append("0");
    }
    else if(running_number_ > 99)
    {
        std::cout << "Too many accounts" << std::endl;
    }
    suffix.append(std::to_string(running_number_));

    iban_ = "FI00 1234 ";
    iban_.append(suffix);
}



void Account::set_credit_limit (int card_ammount){
    if (has_credit_ == false){
    std::cout << "Cannot set credit limit: the account has no credit card" << std::endl;
    } else {
        credit_account_credit = card_ammount;
    }
}


void Account::save_money (int amount_for_save) {
      save_amount = amount_for_save;
}


void Account::take_money (int take_money_order){
    int substraction_for_take_money_order = (save_amount - take_money_order);


    if (substraction_for_take_money_order < 0 && has_credit_ == false){
                std:: cout << "Cannot take money: balance underflow" << std::endl;
    } else if (substraction_for_take_money_order < 0 && has_credit_ == true){

        int credit_amount_calculation_after_req = credit_account_credit + substraction_for_take_money_order;
        if (credit_amount_calculation_after_req < 0) {
                std::cout << "Cannot take money: credit limit overflow" << std::endl;
        } else {
                credit_account_credit = credit_amount_calculation_after_req;
                save_amount = substraction_for_take_money_order;
                std::cout << take_money_order << " euros taken: new balance of " << iban_ << " is " << substraction_for_take_money_order << " euros" << std::endl;;
        }

    } else {

        save_amount = substraction_for_take_money_order;
        std::cout << take_money_order << " euros taken: new balance of " << iban_ << " is " << save_amount << " euros"  << std::endl;
        }
}


void Account::transfer_to (Account& account_name, int transfer_money){
    int substraction_for_transfer_money = (save_amount - transfer_money);
    if (substraction_for_transfer_money < 0 && has_credit_ == false){
        std:: cout << "Cannot take money: balance underflow" << std::endl;
        std:: cout << "Transfer from " << iban_ << " failed" << std::endl;

    } else if (substraction_for_transfer_money < 0 && has_credit_ == true){

        int credit_amount_calculation_Trans_req = credit_account_credit + substraction_for_transfer_money;

        if (credit_amount_calculation_Trans_req < 0) {
                std::cout << "Cannot take money: credit limit overflow" << std::endl;
                std:: cout << "Transfer from " << iban_ << " failed" << std::endl;
        } else { //if (credit_amount_calculation_Trans_req >= 0)
                credit_account_credit = credit_amount_calculation_Trans_req;
                save_amount = substraction_for_transfer_money;
                account_name.save_amount += transfer_money;
                std::cout << transfer_money << " euros taken: new balance of " << iban_ << " is " << substraction_for_transfer_money << " euros" << std::endl;
        }

    } else {
        int money_to_save_aftertransfer = transfer_money + account_name.save_amount;
        save_amount = substraction_for_transfer_money;
        account_name.save_money (money_to_save_aftertransfer);
        std::cout << transfer_money << " euros taken: new balance of " << iban_ << " is " << save_amount << " euros" << std::endl;
    }
}


void Account::print () const {
       std::cout << owner_ << " : " << iban_ << " : " << save_amount << " " << "euros" << std::endl;
}


