/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <iostream>
using namespace std;

class ListNode{
public:
    int data;
    ListNode* next;
public:
    ListNode(int data1, ListNode* next1){
        data = data1;
        next = next1;
    }
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head->next == NULL) return NULL;

        ListNode* dummyHead = new ListNode(0, head);
        ListNode* fast = dummyHead;
        ListNode* slow = dummyHead;
        for(int i = 0;i <= n;i++){
            fast = fast->next;
        }
        while(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* temp = slow->next;
        slow->next = temp->next;
        delete temp;

        return dummyHead->next;
    }

};


void print(ListNode* head){
    ListNode* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
    Solution sol;
    ListNode* head = new ListNode(1, nullptr);
    ListNode* temp = head;
    for(int i = 1;i < 6;i++){
        ListNode* newNode = new ListNode(i+1, nullptr);
        temp->next = newNode;
        temp = newNode;
    }
    print(head);
    head = sol.removeNthFromEnd(head, 2);
    print(head);
    return 0;
}