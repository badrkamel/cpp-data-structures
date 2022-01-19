// CPP program to implement hashing with chaining

#include <list>
#include <cmath>
#include <iostream>

using namespace std;

class Hash
{
	int BUCKET; // No. of buckets
	const double A = (sqrt(5)-1)/2;

	// Pointer to an array containing buckets
	list<int> *table;
public:
	Hash(int V); // Constructor

	// inserts a key into hash table
	void insertItem(int x);

	// deletes a key from hash table
	void deleteItem(int key);

	// hash function to map values to key
	int hashFunction(int k) {
		/*
			Multiplication Method
			h(k) = ⌊m(kA mod 1)⌋

			where,

			kA mod 1 gives the fractional part kA,
			⌊ ⌋ gives the floor value
			A is any constant. The value of A lies between 0 and 1. 
			But, an optimal choice will be ≈ (√5-1)/2 suggested by Knuth.
		*/
		double KA = (k*A);
		double f = KA-(long)KA;
		return (floor(f*BUCKET));
	}

	void displayHash();
};

Hash::Hash(int b)
{
	this->BUCKET = b;
	table = new list<int>[BUCKET];
}

void Hash::insertItem(int key)
{
	int index = hashFunction(key);
	table[index].push_back(key);
}

void Hash::deleteItem(int key)
{
// get the hash index of key
int index = hashFunction(key);

// find the key in (index)th list
list <int> :: iterator i;
for (i = table[index].begin();
		i != table[index].end(); i++) {
	if (*i == key)
	break;
}

// if key is found in hash table, remove it
if (i != table[index].end())
	table[index].erase(i);
}

// function to display hash table
void Hash::displayHash() {
for (int i = 0; i < BUCKET; i++) {
	cout << "table[" << i << "]";
	for (auto x : table[i])
	cout << " --> " << x;
	cout << endl;
}
}

// Driver program
int main()
{
	// array that contains keys to be mapped
	int a[] = {15, 11, 27, 8, 12, 22, 48, 89};
	int n = sizeof(a)/sizeof(a[0]);

	// insert the keys into the hash table
	Hash h(7); // 7 is count of buckets in
				// hash table
	for (int i = 0; i < n; i++)
		h.insertItem(a[i]);
	
	// delete 12 from hash table
	h.deleteItem(12);

	// display the Hash table
	h.displayHash();

	return 0;
}
