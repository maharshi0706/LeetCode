#include <stack>
#include <iostream>
using namespace std;

class MyQueue {
public:
    stack<int> s1, s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty()) {
            while(s1.size()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int n = s2.top();
        s2.pop();
        return n;
    
    }
    
    int peek() {
        if(s2.empty()){
            while(s1.size()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
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