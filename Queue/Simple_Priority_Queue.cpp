#include <iostream>  
#include<queue>  
using namespace std;

int main()  {  
    priority_queue<int> pQueue;  // variable declaration.  
    pQueue.push(10); // inserting 10 in a queue, top=10  
    pQueue.push(30); // inserting 30 in a queue, top=30  
    pQueue.push(20); // inserting 20 in a queue, top=30  
    
    printf(
        "Number of elements available in 'pQueue' : %ld\n", pQueue.size());

    while(!pQueue.empty())  
    {  
        cout << pQueue.top() << endl;   
        pQueue.pop();  
    }  
    return 0;  
}  
