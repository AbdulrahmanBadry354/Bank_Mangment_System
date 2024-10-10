// LinkedList.cpp
#include "LinkedList.h"
#include <iostream>
using namespace std;

Node::Node(Customer customer) : customer(customer), next(nullptr) {}

LinkedList::LinkedList() : head(nullptr) {}

void LinkedList::insert(Customer customer, bool& check) { // insert newObject to linkedList
    if (head == nullptr) { // insert FirstObject to linkedList
        Node* newNode = new Node(customer);
        newNode->next = head;
        head = newNode;
    }
    else {  // insert newObject to linkedList
        Customer* existingCustomer = findCustomerById(customer.getId()); // check if the user is exists or not
        if (existingCustomer == nullptr) {
            Node* newNode = new Node(customer);
            newNode->next = head;
            head = newNode;
        }
        else {
            cout << "Please check the ID you received from customer services as there is an existing one.\n";
            cout << "Enter the right one as there shouldn't be two IDs equal.\n";
            check = true;
        }
    }
}

void LinkedList::display() { // Additional function
    Node* temp = head;
    while (temp != nullptr) {
        temp->customer.displayAccountInfo();
        temp = temp->next;
    }
}

Customer* LinkedList::findCustomerById(int id) { // To check if there is a customer with the same id 
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->customer.getId() == id) {
            return &(temp->customer);
        }
        temp = temp->next;
    }
    return nullptr;
}

void LinkedList::deleteCustomerById(int id, bool& check) { // Delete customer
    Node* temp = head;
    Node* prev = nullptr;
    Customer* customer = findCustomerById(id);
    if (customer == nullptr) {
        cout << "There isn't an account with this ID " << id << "\n";
        check = true;
    }
    else {
        while (temp != nullptr) {
            if (temp->customer.getId() == id) {
                if (prev == nullptr) {
                    head = temp->next;
                }
                else {
                    prev->next = temp->next;
                }
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
    }
}

void LinkedList::withdrawFromAccount(int id, double amount) { // to withdraw from the balance accssed from object
    Customer* customer = findCustomerById(id);
    if (customer != nullptr) {
        customer->withdraw(amount);
    }
    else {
        cout << "Customer with ID " << id << " not found" << endl;
    }
}

void LinkedList::displayAccountBalance(int id) { // to displayAccountBalance from the balance accssed from object
    Customer* customer = findCustomerById(id);
    if (customer != nullptr) {
        cout << "Account " << id << " balance: $" << customer->getBalance() << endl;
    }
    else {
        cout << "Customer with ID " << id << " not found" << endl;
    }
}

int LinkedList::Count()
{
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}