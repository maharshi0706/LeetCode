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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {        
        bool carryOver = false;
        ListNode* newListHead = new ListNode(-1,nullptr);
        ListNode* dummyNode = newListHead;
        while(l1 != NULL && l2 != NULL){
            int sum = l1->data + l2->data;
            if(carryOver) sum += 1;
            
            if(sum >= 10) {
                sum = sum - 10;
                carryOver = true;
            }
            else carryOver = false;

            ListNode* newNode = new ListNode(sum,nullptr);
            dummyNode->next = newNode;
            dummyNode = newNode;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1 != NULL){
            while(l1 != NULL){
            int sum = l1->data;
            if(carryOver) sum += 1;
            
            if(sum >= 10) {
                sum = sum - 10;
                carryOver = true;
            }
            else carryOver = false;

            ListNode* newNode = new ListNode(sum,nullptr);
            dummyNode->next = newNode;
            dummyNode = newNode;
            l1 = l1->next;
            }
        }
        else if(l2 != NULL){
            while(l2 != NULL){
            int sum = l2->data;
            if(carryOver) sum += 1;
            
            if(sum >= 10) {
                sum = sum - 10;
                carryOver = true;
            }
            else carryOver = false;

            ListNode* newNode = new ListNode(sum,nullptr);
            dummyNode->next = newNode;
            dummyNode = newNode;
            l2 = l2->next;
            }
        }
        if (carryOver){
            ListNode* newNode = new ListNode(1, nullptr);
            dummyNode->next = newNode;
            dummyNode = newNode;
        }
        return newListHead->next;
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
    ListNode* head1 = new ListNode(1, nullptr);
    ListNode* temp1 = head1;
    for(int i = 0;i < 3;i++){
        ListNode* newNode = new ListNode(i+2, nullptr);
        temp1->next = newNode;
        temp1 = newNode;
    }
    ListNode* head2 = new ListNode(1, nullptr);
    ListNode* temp2 = head2;
    for(int i = 0;i < 2;i++){
        ListNode* newNode = new ListNode(i+5, nullptr);
        temp2->next = newNode;
        temp2 = newNode;
    }
    print(head1);
    print(head2);
    ListNode* head3 = sol.addTwoNumbers(head1, head2);
    print(head3);
    return 0;
}