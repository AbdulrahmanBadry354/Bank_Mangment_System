// Customer.h
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;

class Customer {
private:
    string name;
    int age;
    string username;
    string password;
    int id;
    double balance;

public:
    Customer(string name, int age, string username, string password, int id, double balance);

    string getName() const;
    int getAge() const;
    string getUsername() const;
    string getPassword() const;
    int getId() const;
    double getBalance() const;

    void withdraw(double amount);
    void deposit(double amount);
    void displayAccountInfo();
};

#endif // CUSTOMER_H
