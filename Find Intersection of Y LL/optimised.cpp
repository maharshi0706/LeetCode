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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       ListNode* tempA = headA;
       ListNode* tempB = headB;
       while(tempA != tempB){
        tempA = tempA == NULL ? headB : tempA->next;
        tempB = tempB == NULL ? headA : tempB->next;
       }
       return tempA;
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
    for(int i = 0;i < 4;i++){
        ListNode* newNode = new ListNode(i+2, nullptr);
        temp1->next = newNode;
        temp1 = newNode;
    }
    ListNode* head2 = new ListNode(9, nullptr);
    ListNode* temp2 = head2;
    for(int i = 10;i < 12;i++){
        ListNode* newNode = new ListNode(i, nullptr);
        temp2->next = newNode;
        temp2 = newNode;
    }
    // temp2->next = head1->next;
    print(head1);
    print(head2);
    ListNode* intersectionNode = sol.getIntersectionNode(head1, head2);
    if(intersectionNode != NULL) cout<<intersectionNode->data<<endl;
    else cout<<"NULL"<<endl;
    return 0;
}