#include <iostream>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;

public:
    ListNode(int data, ListNode* next1): val(data), next(next1) {}
};

class Solution{
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp != NULL){
            ListNode* ahead = temp->next;
            temp->next = prev;
            prev = temp;
            temp = ahead;
        }
        return prev;
    }
};

void print(ListNode* head){
    ListNode* temp = head;
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    Solution sol;

    ListNode* head = new ListNode(1, nullptr);
    ListNode* temp = head;

    for(int i = 2;i <= 5;i++){
        ListNode* newNode = new ListNode(i, nullptr);
        temp->next = newNode;
        temp = newNode;
    }
    print(head);
    head = sol.reverseList(head);
    print(head);
    return 0;
}