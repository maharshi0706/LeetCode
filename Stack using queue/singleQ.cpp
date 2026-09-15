#include <queue>
#include <iostream>
using namespace std;

class MyStack {
public:
    MyStack() {
    }
    std::queue<int> stack;
    
    void push(int x) {
        int s = stack.size();
        stack.push(x);
        for(int i = 0;i < s;i++){
            stack.push(stack.front());
            stack.pop();
        }
    }
    
    int pop() {
        int n = stack.front();
        stack.pop();
        return n;
    }
    
    int top() {
        return stack.front();
    }
    
    bool empty() {
        return stack.empty();
    }
};

int main(){
    MyStack* stack = new MyStack();
    // stack->push(1);
    stack->push(2);
    cout<<stack->pop();
    cout<<stack->top();
    cout<<stack->empty();
    return 0;

}