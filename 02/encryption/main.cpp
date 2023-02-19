#include <iostream>
#include <string>
//#include <cctype>

using namespace std;

//VARIABLES
string encrypKey = "";
string msg_to_encryp = "";
int total_ascii_value_of_ch = 0;


//checking first
//Encryption Key Lower Case check
  int lowercaseCheck (){
    for (int i = 0; i < 26; ++i) {
         char encrypC = encrypKey [i]; //each character
         int ascii_value_of_ch = static_cast< int >( encrypC );
         if (ascii_value_of_ch < 97 || ascii_value_of_ch > 123) { // option if(isupper(encrypC))
         return 1;
        }
    }
     return 0;
  }



//Encryption English Letter Check
int englishLetterCheck (){
 for( char ch = 'a'; ch <= 'z'; ++ch ){
      if (encrypKey.find(ch) == string::npos){
          return 1;
          }
      }
      return 0;
}


//Encryption English Letter Check
//encrypted text checking
int encryptedLowerCaseCheck (int textLength){
    for (int i = 0; i < textLength; ++i) {
         char ch_of_to_be_encrypted_text = msg_to_encryp [i]; //each character
         int ascii_value_of_encrypted_Text_ch = static_cast< int >( ch_of_to_be_encrypted_text );
         if (ascii_value_of_encrypted_Text_ch < 97 || ascii_value_of_encrypted_Text_ch > 123) {
         cout << "Error! The text to be encrypted must contain only lower case characters." << endl;
            return 1;
         }
    }
    return 0;
}


//Encryptio Key Check
int encrypCheck (int keyLength){
     //checking
     if (keyLength != 26){
         cout << "Error! The encryption key must contain 26 characters." << endl;
         return EXIT_FAILURE;
     } else if (keyLength == 26){
        if (lowercaseCheck ()){
            cout << "Error! The text to be encrypted must contain only lower case characters." << endl;
            return EXIT_FAILURE;
        } else if (!lowercaseCheck ()){
            if(englishLetterCheck ()){
                cout << "Error! The encryption key must contain all alphabets a-z." << endl;
                return 1;
            }
        }
     }
    return 0;
}


//Encryption function to Encrypt
string encryption_process (int textLength){
      string encrypted_final_txt = "";
      for (int i = 0; i < textLength; ++i){
            char letter = msg_to_encryp [i];
            int asciiValue = static_cast <int> (letter);
            int ordinalIndex = asciiValue - 97;
            char keyLetter = encrypKey [ordinalIndex];
            encrypted_final_txt += keyLetter;
      }
      return encrypted_final_txt;
}



int main(){
    string::size_type keyLength = 0;
    string::size_type textLength = 0;

    //Ask for key
    cout << "Enter the encryption key: ";
    getline (cin, encrypKey);
    keyLength = encrypKey.length();
    int encrypCheck_result = encrypCheck (keyLength);

    //Ask msg to encryption
    // bool true = 1, False = 0
    //where 1 means exit_failure and 0 means exit_success
         if (!encrypCheck_result){
         cout << "Enter the text to be encrypted: ";
         getline(cin, msg_to_encryp);
         textLength = msg_to_encryp.length();
         encrypCheck_result = encryptedLowerCaseCheck (textLength);

        //Encryption process stage
         if (!encrypCheck_result){
             cout << "Encrypted text: " <<  encryption_process (textLength) << endl;
         }
    }
    
    int return_value = (encrypCheck_result) ? 1 : 0;
    return return_value;
}
