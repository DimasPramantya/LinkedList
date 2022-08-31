#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

void pushNode(node** head, int data);
void printList(node* head);
void searchNode(node* head, int data);
void deleteNode(node** head, int data);

int main()
{
    node* head = nullptr;
    node* traverse;
    pushNode(&head, 1);
    pushNode(&head, 2);
    pushNode(&head, 3);
    printList(head);
    deleteNode(&head, 1);
}
void pushNode(node** head, int data) {
    node* traverse;
    node* newNode = new node();
    newNode->data = data;
    if (*head == nullptr) {
        *head = newNode;
    }
    else {
        for (traverse = *head; traverse->next != nullptr; traverse = traverse->next) {
        }
        traverse->next = newNode;
        traverse = traverse->next;
        traverse->next = nullptr;
    }
};

void printList(node* head) {
    node* traverse;
    for (traverse = head; traverse != nullptr; traverse = traverse->next) {
        cout << traverse->data << " ";
    }
    cout << endl;
}

void deleteNode(node** head, int data) {
    node* traverse;
    node* temp;
    for (traverse = *head; traverse->next != nullptr; traverse = traverse->next) {
        temp = traverse->next;
        if (traverse->data == data) {
            *head = traverse->next;
            delete traverse;
            cout << "Your new list are: ";
            printList(*head);
            return;
        }
        if (temp->data == data) {
            traverse->next = temp->next;
            delete temp;
            cout << "Your new list are: ";
            printList(*head);
            return;
        }
    }
    cout << "Data not found!!!\n";
}