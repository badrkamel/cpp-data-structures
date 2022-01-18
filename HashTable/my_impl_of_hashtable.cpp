#include <iostream>

using namespace std;

struct Ht_item {
    int key;
    int value;

    Ht_item (int k, int v) {
        key = k;
        value = v;
    }
};

class HashTaple {
    int size;
    int lenght;
    int i; // for collison
    int *items;

public:
    HashTaple (int SIZE) {
        size = SIZE;
        lenght = 0;
        i = 1;
        items = new int [size];
    }

    void hash(Ht_item *ht_item) {

        if (lenght == size) {
            cout << "The heap is full\n";
            return;
        }
        int key = ht_item->key;
        int value = ht_item->value;

        int ind = key%size;

        if (items[ind] == 0) {
            cout << "Index: " << ind << endl;
            ind = key%size;
        } else {
            while (items[ind] != 0) {
                cout << "Repeated index: " << ind << endl;
                ind = ((key + (i*i)) % size);
                i++;
            }
            
        }
        items[ind] = value;
        lenght++;
    }

    void getItem(int key) {
        cout << "Value: " << items[key%size] << endl;
    }

    void display() {
        cout << "HashTable Length is: " << lenght << endl;
        for (int i=0; i<size; i++) {
            cout << i << "-> " << items[i] << " ";
        }
        cout << endl;
    }

};

int main () {
    cout << "HashTable ADT\n";

    // Create empty hashtable
    HashTaple h(10);

    int keys[] = {23,27,27,13,13,13,27,27,25,55,105};
    int values[] = {10,15,20,25,30,35,40,45,50,55,60};

    // Hashing the keys with their values
    for (int i=0; i<11; i++) {
        Ht_item *ht_item = new Ht_item(keys[i], values[i]);
        h.hash(ht_item);
    }

    // Retrieve item from the hashtable by his key
    h.getItem(27);
    
    h.display();
}
