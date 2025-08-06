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
        int sizeOfLL = 0;
        ListNode* temp = head;
        while(temp != nullptr){
            sizeOfLL++;
            temp = temp->next;
        }
        int nodeToRemove = sizeOfLL - n + 1;
        int counter = 0;
        temp = head;
        ListNode* prev = NULL;
        while(temp != nullptr){
            counter += 1;
            if(counter == nodeToRemove) break;
            
            prev = temp;
            temp = temp->next;
        }
        if (prev == NULL) {
            head = head->next;
            delete temp;
        } else {
            prev->next = temp->next;
            delete temp;
        }
        return head;        
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
    for(int i = 1;i < 7;i++){
        ListNode* newNode = new ListNode(i+1, nullptr);
        temp->next = newNode;
        temp = newNode;
    }
    print(head);
    head = sol.removeNthFromEnd(head, 2);
    print(head);
    return 0;
}