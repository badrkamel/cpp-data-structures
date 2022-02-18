/*  C++ program to implement hashtable
	Collision resolution by Open addressing and Quadratic probing
*/
#include <iostream>

struct HT_item {
	int key;
	std::string value;
};

class HashTable
{
	size_t BUCKET;
	size_t length;
	size_t i; // The counter {i} increases each time a collision occurs
	HT_item* items;

public:
	HashTable(int BUCKET) : BUCKET(BUCKET) {
		length = 0;
		i = 1;
		items = new HT_item[BUCKET];
	}

	int hash(int);
	void insert(int, const char*);
	void display();
	HT_item* getItem(int);
};

int main() {

	HashTable ht(10);

	ht.insert(22, "hello");
	ht.insert(222, "this");
	ht.insert(13, "is");
	ht.insert(15, "me");

	HT_item* item =  ht.getItem(22);
	if (item) {
		item->value = "Updated";
	}

	item =  ht.getItem(22);

	ht.display();
	return 0;
}

int HashTable::hash(int key)
{
	return (key%BUCKET);
}

void HashTable::insert(int key, const char* value)
{
	if (length < BUCKET) {
		size_t ind = hash(key);
		
		while (items[ind].key != 0)
		{
			ind = (key+(i*i))%BUCKET;
			i++;
		}
		items[ind] = {key, value};
	}
}

void HashTable::display()
{
	for (size_t i{}; i < BUCKET; i++)
	{
		std::cout << "{" << items[i].key << ", " << items[i].value << "}\n";
	}
}

HT_item* HashTable::getItem(int key)
{
	int ind = hash(key);

	int i = 1;
	while (items[ind].key != key)
	{
		ind = (key+(i*i))%BUCKET;
		i++;
		if (this->i<i)
		return nullptr;
	}
	std::cout << items[ind].value << "\n";
	return &items[ind];
}
