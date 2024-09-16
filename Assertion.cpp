#include <cassert>
#include <iostream>

class Account {
public:
    Account(double balance) : balance(balance) {
        assert(balance >= 0); // Invariant: balance must be non-negative
    }

    void deposit(double amount) {
        assert(amount > 0); // Precondition: amount must be positive
        balance += amount;
        assert(balance >= 0); // Postcondition: balance must be non-negative
    }

    void withdraw(double amount) {
        assert(amount > 0); // Precondition: amount must be positive
        assert(balance >= amount); // Precondition: balance must be sufficient
        balance -= amount;
        assert(balance >= 0); // Postcondition: balance must be non-negative
    }

    double getBalance() const {
        return balance;
    }

private:
    double balance;
};

int main() {
    Account myAccount(100.0);
    myAccount.deposit(50.0);
    myAccount.withdraw(30.0);
    std::cout << "Current balance: " << myAccount.getBalance() << std::endl;
    return 0;
}
