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
    void deleteNode(ListNode* node) {
        node->data = node->next->data;
        node->next = node->next->next;
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
    sol.deleteNode(head);
    print(head);
    return 0;
}