#include <stack>
#include <iostream>
using namespace std;

class MyQueue {
public:
    stack<int> s1, s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(s1.size()){
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        while(s2.size()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int n = s1.top();
        s1.pop();
        return n;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};


int main(){
    MyQueue* q = new MyQueue();
    q->push(1);
    q->push(2);
    cout<<q->peek();
    cout<<q->pop();
    cout<<q->empty();
    return 0;
}