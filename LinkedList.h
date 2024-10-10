// LinkedList.h
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Customer.h"

class Node {
public:
    Customer customer;
    Node* next; 

    Node(Customer customer);
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList();

    void insert(Customer customer, bool& check);
    void display();
    Customer* findCustomerById(int id);
    void deleteCustomerById(int id, bool& check);
    void withdrawFromAccount(int id, double amount);
    void displayAccountBalance(int id);
    int Count();
};

#endif // LINKEDLIST_H
