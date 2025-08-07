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
        int carryOver = 0;
        ListNode* newListHead = new ListNode(-1,nullptr);
        ListNode* dummyNode = newListHead;
        while(l1 != NULL || l2 != NULL || carryOver){
            int l1Sum = (l1 != NULL) ? l1->data : 0;
            int l2Sum = (l2 != NULL) ? l2->data : 0;
            int sum = l1Sum + l2Sum + carryOver;
            carryOver = sum / 10;

            dummyNode->next = new ListNode(sum % 10, nullptr);
            dummyNode = dummyNode->next;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
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
    for(int i = 0;i < 4;i++){
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