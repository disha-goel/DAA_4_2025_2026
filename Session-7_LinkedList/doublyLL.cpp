#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int x) {
        data = x;
        prev = NULL;
        next = NULL;
    }
};
class DoublyLinkedList {
private:
    Node* head;
public:
    DoublyLinkedList() {
        head = NULL;
    }
    void insertAtBeg(int val) {
        Node* newNode = new Node(val);
        if (head != NULL) {
            newNode->next = head;
            head->prev = newNode;
        }
        head = newNode;
    }
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    void insertAtPos(int val, int pos) {
        if (pos <= 1 || head == NULL) {
            insertAtBeg(val);
            return;
        }
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp->next != NULL; i++) {
            temp = temp->next;
        }
        if (temp->next == NULL) {
            insertAtEnd(val);
            return;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
    void deleteAtBeg() {
        if (head == NULL) return;
        Node* temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        delete temp;
    }
    void deleteAtEnd() {
        if (head == NULL) return;
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        delete temp;
    }
    void deleteAtPos(int pos) {
        if (head == NULL) return;
        if (pos == 1) {
            deleteAtBeg();
            return;
        }
        Node* temp = head;
        for (int i = 1; i < pos && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) 
            return;
        if (temp->next != NULL){
            temp->next->prev = temp->prev;
        }
        if (temp->prev != NULL){
            temp->prev->next = temp->next;
        }
        delete temp;
    }
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};
int main() {
    DoublyLinkedList dll;
     cout << "After insertions:"<<endl;
    dll.insertAtBeg(10);
    dll.insertAtBeg(5);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);
    dll.insertAtPos(15, 3);
    dll.insertAtPos(2, 1);
    dll.insertAtPos(40, 10);

    dll.display();

     cout << "After deletions:"<<endl;
    dll.deleteAtBeg();
    dll.deleteAtEnd();
    dll.deleteAtPos(3);

    dll.display();

    return 0;
}
