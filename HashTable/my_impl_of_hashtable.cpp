#include <cmath>
#include <iostream>

using namespace std;

struct Ht_item {
    int key;
    int value;
};

class HashTaple {
    int BUCKET;
    int lenght;
    int i; // for collison
    Ht_item *items;
    const double A = (sqrt(5)-1)/2;

public:
    HashTaple (int v) {
        BUCKET = v;
        lenght = 0;
        i = 1;
        items = new Ht_item [BUCKET];
    }

    int Hash(int key) {

        double KA = (key*A);
        double f = KA-(int)KA;
        
        return (floor(f*BUCKET));
    }

    void insert(int key, int value) {
        if (lenght >= BUCKET) {
            cout << "The HashTaple is full\n";
            return;
        }
        
        int ind = Hash(key);
        if (items[ind].key != 0) { // Collision occurred
            while (items[ind].key != 0) {
                ind = abs((key + (i*i)) % BUCKET);
                i++;
            }
        }
        items[ind] = {key,value};
        lenght++;
    }

    void getItem(int key) {
        int ind = Hash(key);
        if (items[ind].key != key) {
            int i{};
            while (items[ind].key != key) {
                // cout << "Repeated index: " << ind << endl;
                ind = abs((key + (i*i)) % BUCKET);
                i++;
                if (i>this->i) {
                    cout << "The key: " << key << " not in the HashTable\n";
                    return;
                }
            }
        }

        cout << "Value: " << items[ind].value << endl;
    }

    void display() {
        cout << "HashTable contains: " << lenght << " Items." << endl;
        for (int i=0; i<BUCKET; i++) {
            cout << "table[" << i << "] -> {";
            cout << items[i].key << ", " << items[i].value << "}" << endl;
        }
    }

};

int main () {

    cout << "HashTable ADT\n";

    // Create empty hashtable with 10 buckets
    HashTaple h(10);

    int keys[] = {23,27,37,13,33,43,47,57,52,55};
    int values[] = {10,15,20,25,30,35,40,45,50,55};

    // Hashing the keys with their values
    for (int i=0; i<11; i++) {
        h.insert(keys[i], values[i]);
    }

    // Retrieve item from the hashtable by his key
    h.getItem(27);
    h.getItem(33);
    h.getItem(13);
    h.getItem(52);

    // Not in the HashTable
    h.getItem(100);

    
    h.display();
}
