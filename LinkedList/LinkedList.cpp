#include <iostream>

using namespace std;

template<typename T>
struct Node {
    T data;
    Node<T> *next = NULL;
    Node(T v) {
        data = v;
    }
};

template<typename T>
class LinkedList {

    Node<T> *head = NULL;

public:
    bool isEmpty() {
        return (head==NULL);
    }

    void insertFirst(T data) {
        Node<T> *newNode = new Node<T>(data);

        if (isEmpty()) {
            newNode->next = NULL;
        } else {
            newNode->next = head;
        }

        head = newNode;
    }

    void insertBefore(T item, T data) {
        if (isEmpty())
            insertFirst(data);
        Node<T> *newNode = new Node<T>(data);

        Node<T> *temp = head;
        
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

    void append(T data) {
        if (isEmpty())
            insertFirst(data);

        Node<T> *newNode = new Node<T>(data);
        newNode->next = NULL;

        Node<T> *temp = head;
        
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void reverse() {
        if (!head)
            return;
        Node<T> *current = head;
        Node<T> *next = NULL;
        Node<T> *prev = NULL;

        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    void display() {
        Node<T> *temp = head;
        
        while (temp != NULL)
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << endl;
    }

    int count() {

        int counter = 0;
        Node<T> *temp = head;
        while (temp != NULL)
        {
            counter++;
            temp = temp->next;
        }
        return counter;
    }

    bool isFound(int key) {

        bool found = false;
        Node<T> *temp = head;
        while (temp != NULL)
        {
            if (key == temp->data)
                found = true;
            temp = temp->next;
        }
        return found;
    }

    void Delete(T item) {
        if (isEmpty()){
            cout << "LinkedList is empty\n";
            return;
        }
        Node<T> *ptr = head;
        if (item == head->data) {
            head = head->next;
            delete ptr;
        } else {
            Node<T> *prev = NULL;
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

    LinkedList<string> lst;

    if (lst.isEmpty()) {
        cout << "The list is empty\n";
    } else {
        cout << "List contains " << lst.count() << "items.\n";
    }

    lst.insertFirst("two");
    lst.insertFirst("three");
    lst.insertFirst("five");
    lst.display();
    lst.insertBefore("three", "four");
    lst.display();
    lst.append("one");
    lst.display();
    lst.Delete("five");
    cout << "The List contains: " << lst.count() << endl;
    lst.display();

    cout << "LinkedList After reverse: \n";
    lst.reverse();
    lst.display();

}
