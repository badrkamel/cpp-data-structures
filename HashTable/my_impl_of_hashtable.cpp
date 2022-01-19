#include <cmath>
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
    int BUCKET;
    int lenght;
    int i; // for collison
    int *items;
    const double A = (sqrt(5)-1)/2;

public:
    HashTaple (int v) {
        BUCKET = v;
        lenght = 0;
        i = 1;
        items = new int [BUCKET];
    }

    int Hash(int key) {

        double KA = (key*A);
        double f = KA-(int)KA;
        
        return (floor(f*BUCKET));
    }

    void insert(Ht_item *ht_item) {

        if (lenght == BUCKET) {
            cout << "The HashTaple is full\n";
            return;
        }
        int key = ht_item->key;
        int value = ht_item->value;

        int ind = Hash(key);
        if (items[ind] != 0) {
            while (items[ind] != 0) {
                // cout << "Repeated index: " << ind << endl;
                ind = ((key + (i*i)) % BUCKET);
                i++;
            }
        }
        items[ind] = value;
        lenght++;
    }

    void getItem(int key) {
        int ind = Hash(key);
        cout << "Value: " << items[ind] << endl;
    }

    void display() {
        cout << "HashTable Length is: " << lenght << endl;
        for (int i=0; i<BUCKET; i++) {
            cout << i << "-> " << items[i] << " ";
        }
        cout << endl;
    }

};

int main () {

    cout << "HashTable ADT\n";

    // Create empty hashtable with 10 buckets
    HashTaple h(10);

    int keys[] = {23,27,37,13,33,43,47,57,52,55,105};
    int values[] = {10,15,20,25,30,35,40,45,50,55,60};

    // Hashing the keys with their values
    for (int i=0; i<11; i++) {
        Ht_item *ht_item = new Ht_item(keys[i], values[i]);
        h.insert(ht_item);
    }

    // Retrieve item from the hashtable by his key
    h.getItem(27);
    h.getItem(33);
    h.getItem(13);
    
    h.display();
}
