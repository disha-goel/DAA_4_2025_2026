#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};
Node* insertbegin(int value, Node* head) {
    Node* newNode = new Node(value);
    newNode->next = head;
    return newNode;
}
Node* insertend(int value, Node* head) {
    if (head == nullptr)
        return new Node(value);
    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = new Node(value);
    return head;
}
Node* insertatindex(int value, int index, Node* head) {
    if (index == 0)
        return insertbegin(value, head);
    Node* temp = head;
    for (int i = 0; i < index - 1 && temp != nullptr; i++)
        temp = temp->next;
    if (temp == nullptr) {
        cout << "Invalid index" << endl;
        return head;
    }
    Node* newNode = new Node(value);
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}
Node* insertaftervalue(int value, int after, Node* head) {
    Node* temp = head;
    while (temp != nullptr && temp->data != after)
        temp = temp->next;
    if (temp == nullptr) {
        cout << "Value not found" << endl;
        return head;
    }
    Node* newNode = new Node(value);
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}
Node* deletebegin(Node* head) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return head;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}
Node* deleteend(Node* head) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return head;
    }
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }
    Node* temp = head;
    while (temp->next->next != nullptr)
        temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
    return head;
}
Node* deleteatindex(int index, Node* head) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return head;
    }
    if (index == 0)
        return deletebegin(head);
    Node* temp = head;
    for (int i = 0; i < index - 1 && temp->next != nullptr; i++)
        temp = temp->next;
    if (temp->next == nullptr) {
        cout << "Invalid index" << endl;
        return head;
    }
    Node* del= temp->next;
    temp->next = del->next;
    delete del;
    return head;
}
Node* deletebyvalue(int value, Node* head) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return head;
    }
    if (head->data == value)
        return deletebegin(head);
    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != value)
        temp = temp->next;
    if (temp->next == nullptr) {
        cout << "Value not found" << endl;
        return head;
    }
    Node* del= temp->next;
    temp->next = del->next;
    delete del;
    return head;
}
void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main() {
    Node* head = nullptr;
    head = insertbegin(10, head);
    head = insertend(20, head);
    head = insertatindex(15, 1, head);
    head = insertaftervalue(25, 20, head);
    display(head);
    head = deletebegin(head);
    head = deleteend(head);
    head = deleteatindex(1, head);
    head = deletebyvalue(15, head);
    display(head);
    return 0;
}
