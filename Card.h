#include "Account.h"

class Card {
private:
    long long  cardNumber;
    vector<Account> accounts;
    string pin;
    bool isOk;

public:
    Card(){}
    Card(long long  cardNum, vector<Account> acc, string Pin){
        cardNumber = cardNum;
        accounts = acc;
        pin = Pin;
        isOk = false;
    }
    long long  getCardNumber() {
        return cardNumber;
    }
    bool ok(){
        return isOk;
    }
    bool isCorrect(string enteredPin) {
        if (pin == enteredPin) {
            isOk = true;
            return true;
        }
        return false;
    }
    vector<Account>& getAccounts() {
        return accounts;
    }
};