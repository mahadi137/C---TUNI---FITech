#ifndef ACCOUNT_HH
#define ACCOUNT_HH

#include <string>

class Account
{
public:
    // Constructor
    Account(const std::string& owner, bool has_credit = false);

    // More methods
    void print () const;
    void save_money (int amount_for_save);
    void set_credit_limit (int card_ammount);
    void take_money (int take_money_order);
    void transfer_to (Account& account_name, int transfer_money);

    //bool set_credit_limit(100)

private:
    std::string owner_;
    bool has_credit_;

    // Generates IBAN (based on running_number_ below).
    // Allows no more than 99 accounts.
    void generate_iban();

    // Used for generating IBAN.
    // Static keyword means that the value of running_number_ is the same for
    // all Account objects.
    // In other words, running_number_ is a class-wide attribute, there is
    // no own copies of it for each object of the class.
    static int running_number_;

    // More attributes/methods
     std::string iban_;
     int credit_account_credit = 0;
     int save_amount = 0;
     int rest_of_save_money = 0;
};

#endif // ACCOUNT_HH
