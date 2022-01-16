#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node *next;
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
            Node *newItem = new Node();
            newItem->data = data;

            if (isEmpty()) {
                newItem->next = NULL;
            } else {
                newItem->next = head;
            }

            head = newItem;
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
	lst.insertFirst(20);
	lst.display();
	cout << "The List contains " << lst.count() << endl;

}
