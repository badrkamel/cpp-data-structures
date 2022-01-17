#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node *next;
        Node() {
            data = 0;
            next = NULL;
        }
};

class LinkedList {
    Node *head;
    public:
        LinkedList() {
            head = NULL;
        }

        bool isEmpty() {
            return (head==NULL);
        }

        void insertFirst(int data) {
            Node *newNode = new Node();
            newNode->data = data;

            if (isEmpty()) {
                newNode->next = NULL;
            } else {
                newNode->next = head;
            }

            head = newNode;
        }

        void insertBefore(int item, int data) {
            if (isEmpty())
                insertFirst(data);
            Node *newNode = new Node();
            newNode->data = data;

            Node *temp = head;
            
            while (temp != NULL && temp->next->data != item)
            {
                temp = temp->next;
                if (temp->next == NULL){
                    cout << "Not found!\n";
                    return;
                }
            }

            newNode->next = temp->next;
            temp->next = newNode;
        }

        void append(int data) {
            if (isEmpty())
                insertFirst(data);

            Node *newNode = new Node();
            newNode->data = data;
            newNode->next = NULL;

            Node *temp = head;
            
            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }

        void display() {
            Node *temp = head;
            
            while (temp != NULL)
            {
                cout << temp->data << "\t";
                temp = temp->next;
            }
            cout << endl;
        }

        int count() {

            int counter = 0;
            Node *temp = head;
            while (temp != NULL)
            {
                counter++;
                temp = temp->next;
            }
            return counter;
        }

        bool isFound(int key) {

            bool found = false;
            Node *temp = head;
            while (temp != NULL)
            {
                if (key == temp->data)
                    found = true;
                temp = temp->next;
            }
            return found;
        }

        void Delete(int item) {
            if (isEmpty()){
                cout << "LinkedList is empty\n";
                return;
            }
            Node *ptr = head;
            if (item == head->data) {
                head = head->next;
                delete ptr;
            } else {
                Node *prev = NULL;
                while (ptr->data != item)
                {
                    prev = ptr;
                    ptr = ptr->next;
                }
                prev->next = ptr->next;

            }
        }
};

int main() {

    LinkedList lst;

    if (lst.isEmpty()) {
        cout << "The list is empty\n";
    } else {
        cout << "List contains " << lst.count() << "items.\n";
    }

    lst.insertFirst(10);
    lst.insertFirst(15);
    lst.insertFirst(25);
    lst.display();
    lst.insertBefore(15, 20);
    lst.display();
    lst.append(35);
    lst.display();
    lst.Delete(20);
    lst.display();   
    

    cout << "The List contains " << lst.count() << endl;

}