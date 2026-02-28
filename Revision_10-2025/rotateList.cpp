#include <iostream>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;
public:
    ListNode(int data, ListNode* next): val(data), next(next) {}
};

class Solution{
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // Handle edge case
        if(!head || !head->next || k == 0) return head;


        int count = 1;
        ListNode* temp = head;
        while(temp->next){
            count++;
            temp = temp->next;
        }

        int rotateBy = k % count;
        if(rotateBy == 0) return head; // EDGE CASE

        temp->next = head;
        int breakPoint = count - rotateBy;
        ListNode* tail = temp;
        while(breakPoint--) tail = tail->next;

        ListNode* newHead = tail->next;
        tail->next = NULL;
        return newHead;
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
    for(int i = 2;i <= 6;i++){
        ListNode* newnode = new ListNode(i, nullptr);
        temp->next = newnode;
        temp = newnode;
    }
    print(head);
    head = sol.rotateRight(head,2);
    print(head);
    return 0;
}