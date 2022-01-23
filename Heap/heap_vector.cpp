#include <string>
#include <vector>
#include <iostream>

using namespace std;


class MINHeap {

	vector<int> heap;

	int left(int node) {
		int left = (node*2) +1;
		return (left >= size()) ? -1 : left;
	}
	int right(int node) {
		int right = (node*2) +2;
		return (right >= size()) ? -1: right;
	}
	int parent(int node) {
		return node == 0 ? -1 : (node-1)/2;
	}

	void reheapUp(int pos) {
		if (pos==0||(heap[parent(pos)]<heap[pos])) {
			return;
		}
		swap(heap[pos], heap[parent(pos)]);
		reheapUp(parent(pos));
	}

public:
	int top();
	int size();
	void push(int node);
	void print();
	void getVertex(int node);

};

int MINHeap::size() {
	return heap.size();
}

int MINHeap::top() {
	if (size()==0) {
		return -1;
	}
	return heap.front();
}

void MINHeap::print() {
	cout << "MINHeap : [ ";
	for (int i=0; i<size();i++)
		cout << heap[i] << " ";
	cout << "]\n";
}

void MINHeap::push(int node) {
	heap.push_back(node);
	reheapUp(size()-1);
}


void MINHeap::getVertex(int node) {
	string parent, l, r;

	parent = to_string(heap[node]);
	l = to_string(heap[left(node)]);
	r = to_string(heap[right(node)]);

	cout << endl;
	cout << "Vertex "+parent+":  (" + parent + ")\n";
	cout << "\t   /  \\ \n\t (" + l + ")  (" + r + ")";
	cout << endl;

}

int main () {

	MINHeap heap;

	int nodes[9] = {5,3,6,12,10,4,3,8,2};
    int size = sizeof(nodes) / sizeof(nodes[0]);
	for (int i=0;i<size;i++)
		heap.push(nodes[i]);

	heap.print();

	heap.getVertex(1);

	cout << "\nSome methods: \n";
	cout << " - Top: " << heap.top() << endl;
	cout << " - Size: " << heap.size() << endl;

}
