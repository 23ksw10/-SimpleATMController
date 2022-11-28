#include <iostream>
#include "ATM.h"

int main() {
    // example of process


    vector<Card>data={
        Card(7,{Account(150,"12345678")},"2022"),
        Card(10,{Account(45334589000,"12123434"),Account(34589000,"32427899")},"0022"),
        Card(19,{Account(150,"15678765"),Account(350,"58889234"),Account(9,"34112345")},"4332")
    };

    //declare
    ATM atm = ATM(data);
    Card myCard;
    vector<Account> accounts;
    Account currentAccount;



    while(1){
        // 1. Insert Card
        cout << "========================================" << endl;
        cout << "Please insert your card" << endl;
        cout << "Your card number : ";
        long long  cardNumber;
        cin >> cardNumber;
        if (!atm.isCardValid(cardNumber, myCard)) {
            cout << "Your card does not exist. Please try again" << endl;
            continue;
        }

        // 2. PIN NUMBER
        // Pin must have 4 digits
        string pin = "";
        while(pin.size() != 4 || !myCard.isCorrect(pin)) {
            cout << "Enter your PIN number (4 digits): " ;
            cin >> pin;
            if(pin.size() != 4) {
                cout << "Your PIN must be 4 digits"<< endl;
                continue;
            }
            if(!myCard.isCorrect(pin)) {
                cout << "Your pin is not correct Try again"<< endl;
                continue;
            }
        }

        if(myCard.ok()){
            // 3. Select Account

            cout << "Enter number to select you account : "<< endl;
            accounts = myCard.getAccounts();
            for(int i = 0; i < accounts.size(); i++) {
                cout << i+1 << ": " << accounts[i].getAccountNumber() << endl;
            }
            long long  accountIndex;
            cin >> accountIndex;
            if(accountIndex < 1 || accountIndex >= accounts.size()+1) {
                cout << "Please enter a valid account"<< endl;
                continue;
            }
            currentAccount = accounts[accountIndex-1];


            //4. Balance/ Deposit/ Withdraw
            while(1) {
                long long money;
                cout << "Actions: " << endl;
                cout << "1. See Balance" << endl;
                cout << "2. Deposit" << endl;
                cout << "3. Withdraw" << endl;
                cout << "Press the button you need: ";
                int button;
                cin >> button;
                if (button < 1 || button > 3) {
                    cout << "Please enter a valid number" << endl;
                    continue;
                }
                if (button == 1) {
                    cout << "Your Balance : " << currentAccount.accountBalance() << endl;
                } else if (button == 2) {
                    cout << "Enter deposit money : ";
                    cin >> money;
                    while(money<=0){
                        cout << "Money should be positive" << endl;
                        cin >> money;
                    }
                    cout << "Your are successfully deposit to your account. New balance: "
                         << currentAccount.deposit(money) << endl;
                } else {
                    cout << "Enter withdraw money : ";
                    cin >> money;
                    while(money<=0){
                        cout << "Money should be positive" << endl;
                        cin >> money;
                    }
                    int newBalance = currentAccount.withdraw(money);
                    if (newBalance == -1) {
                        cout << "Your account does not have enough money. Please try again " << endl;
                        continue;
                    } else {
                        cout << "Your are successfully withdraw. New balance: " << newBalance << endl;
                    }
                }
                int exit;
                cout << "========================================" << endl;
                cout << "If you want out press 0 or you will be able to continue other tasks" << endl;
                cin >> exit;
                if(exit==0)break;
            }
            int exit;
            cout << "========================================" << endl;
            cout << "If you want out press 0 or you will be able to continue other tasks" << endl;
            cin >> exit;
            if(exit==0)break;
        }
    }
    return 0;
}