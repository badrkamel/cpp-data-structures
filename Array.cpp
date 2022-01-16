#include <iostream>

using namespace std;

class Array {
    private :
        int size;
        int length;
        int *items;

    public :

        Array(int arrSize) {
            size = arrSize;
            length = 0;
            items = new int[arrSize];
        }

        void Fill() {
            int no_of_items;
            cout << "How many itmes you want to fill: ";
            cin >> no_of_items;

            if (no_of_items > size) {
                cout << "You cannot exceed the array size";
                return;
            }

            for (int i=0; i < no_of_items; i++) {
                
                cout << "Enter the item: ";
                cin >> items[i];
                length++;
            }
        }

        void Display() {
            cout << "The array content\n";

            for (int i=0; i < length; i++) {
                cout << items[i] << "\t";
            }
            cout << endl;
        }

        int getLength() {
            return length;
        }

        int getSize() {
            return size;
        }

        int Search(int key) {
            int index = -1;

            for (int i=0; i < length; i ++) {
                if (key == items[i]){
                    index = key;
                    break;
                }
            }
            return index;
        }

        void Append(int newItem) {
            if (length < size) {
                items[length] = newItem;
                length++;
            } else {
                cout << "The array is full\n";
            }
        }

        void Insert(int index, int newItem) {
            if (!(index >= 0 && index < size)) {
                cout << "Index out of array range\n";
                return;
            }
            if (length < size) {
                for (int i = length; i > index; i--) {
                    items[i] = items[i-1];
                }
                items[index] = newItem;
                length++;
            } else {
                cout << "The array is full\n";
            }
        }

        void Delete(int index) {
            if (!(index >= 0 && index < size)) {
                cout << "Index out of array range\n";
                return;
            }
            for (int i = index; i < length-1; i++)
                items[i] = items[i+1];
            length--;
        }
};

int main() {
    cout << "ADT for array\n";

    int arrSize;
    cout << "Enter the array size: ";
    cin >> arrSize;

    Array myArray(arrSize);
    myArray.Fill();

    cout << "Array size = " << myArray.getSize() << " while the length = " << myArray.getLength() << endl;
    myArray.Display();

    // Search
    int key;
    cout << "Enter the item youre loooking for: ";
    cin >> key;
    int index = myArray.Search(key);
    if (index == -1){
        cout << "Item not found!\n";
    } else {
        cout << "The item index is: " << index<< endl;
    }

    // Append
    int newItem;
    cout << "Enter item to append to the array: ";
    cin >> newItem;
    myArray.Append(newItem);
    myArray.Display();
    
    // Insert
    int insItem, position;
    cout << "Insert item: ";
    cin >> insItem;
    cout << "Position of item: ";
    cin >> position;
    myArray.Insert(position, insItem);
    myArray.Display();

    int del;
    cout << "Delete item at index: ";
    cin >> del;
    myArray.Delete(del);
    myArray.Display();
}
