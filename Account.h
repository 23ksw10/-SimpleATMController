#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Account {
private:
    long long  balance;
    string accountNumber;

public:
    Account(){}
    Account(long long  money, string accNum){
        balance = money;
        accountNumber=accNum;
    }
    string getAccountNumber(){
        return accountNumber;
    }
    long long  accountBalance(){
        return balance;
    }
    long long  deposit(long long  money){
        balance += money;
        return balance;
    }
    long long  withdraw(long long  money) {
        if (balance >= money) {
            balance -= money;
            return balance;
        }
        return -1;
    }
};
