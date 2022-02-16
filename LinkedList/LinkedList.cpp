#include <iostream>

template<typename T> struct Node {
    T data;
    Node *next = NULL;
    Node(T v) {
        data = v;
    }
};

template<typename T> class LinkedList {

    Node<T> *head = NULL;

public:
    bool isEmpty() {
        return (head == NULL);
    }

    void insertFirst(T data) {
        Node<T> *newNode = new Node<T>(data);

        newNode->next = head;
        head = newNode;
    }

    void insertBefore(T item, T data) {
        if (head == NULL)
            insertFirst(data);

        Node<T> *newNode = new Node<T>(data);
        Node<T> *temp = head;
        
        while (temp != NULL && temp->next->data != item)
        {
            temp = temp->next;
            if (temp->next == NULL){
                std::cout << "Not found!\n";
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
            std::cout << temp->data << "\t";
            temp = temp->next;
        }
        std::cout << "\n";
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
            std::cout << "LinkedList is empty\n";
            return;
        }
        Node<T> *ptr = head;
        if (item == head->data) {
            head = head->next;
        }
        else
        {
            Node<T> *prev = NULL;
            while (ptr && ptr->data != item)
            {
                prev = ptr;
                ptr = ptr->next;
            }
            if (ptr && ptr->data == item)
                prev->next = ptr->next;
        }
        delete ptr;
    }
};

int main() {

    LinkedList<std::string> list;

    if (list.isEmpty()) {
        std::cout << "The list is empty\n";
    } else {
        std::cout << "List contains " << list.count() << "items.\n";
    }

    list.insertFirst("two");
    list.insertFirst("three");
    list.insertFirst("five");
    list.display();
    list.insertBefore("three", "four");
    list.display();
    list.append("one");
    list.display();
    list.Delete("five");
    std::cout << "The List contains: " << list.count() << std::endl;
    list.display();
    std::cout << "LinkedList After reverse: \n";
    list.reverse();
    list.display();

}
