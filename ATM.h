#include "Card.h"

class ATM{
private:
    vector<Card> bankDatabase;
    map<int,Card> bankMap;
public:
    ATM(vector<Card> database) {
        bankDatabase = database;
        for(auto card:database){
            auto num=card.getCardNumber();
            bankMap[num]=card;
        }
    }
    bool isCardValid(long long  cardNumber, Card& currentCard) {

        if(bankMap.count( cardNumber)){
            currentCard=bankMap[cardNumber];
            return true;
        }
        return false;
    }
};
