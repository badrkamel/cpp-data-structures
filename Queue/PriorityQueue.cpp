#include <iostream>
#include <unordered_map>

using namespace std;

struct Node
{
    int data;
    Node *next = NULL;

    Node(int data) : data(data) {};
};

class pQueue
{

    int top{};
    unordered_map<int, pair<Node*, Node*>> map;

    void print_key_value(int level, pair<Node*, Node*> p)
    {
        cout
        << "Priority:[" << level 
        << "]\tFront:[" << p.first->data 
        << "]\tRear:["  << p.second->data << "]\n";
    };
    public:
    void enQueue(int, int);
    void deQueue();
    void Map();
    void reverse();
    void get_level(int);
    int peek();
};


int main() {

    pQueue q;

    q.enQueue(0, 10);
    q.enQueue(0, 20);
    q.enQueue(0, 30);
    
    q.enQueue(1, 15);
    q.enQueue(1, 25);

    q.enQueue(2, 100);

    q.Map();
    q.get_level(0);

    cout << q.peek() << endl;

    q.deQueue();
    cout << q.peek() << endl;
    q.Map();

    q.get_level(1);
    q.deQueue();
    q.get_level(1);
    q.deQueue();
    q.Map();
    

    return 0;
}

void pQueue::enQueue(int level, int value)
{
    Node *node = new Node(value);
    
    if (map.find(level) == map.end())
        map[level].first = map[level].second = node;
    
    map[level].second->next = node;
    map[level].second = node;

    if (level>top)
        top = level;
}

void pQueue::Map()
{
    for (const auto& i : map)
        print_key_value(i.first, i.second);
}

void pQueue::get_level(int level)
{
    Node *temp = map[level].first;
    
    while (temp)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int pQueue::peek()
{
    return map[this->top].second->data;
}

void pQueue::deQueue()
{
    Node *temp = map[top].first;

    if (map[top].first != map[top].second)
    {
        map[top].first = temp->next;
    }
    else
    {
        map.erase(top);
        top--;
    }

    delete temp;
}
