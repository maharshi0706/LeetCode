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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyNode = new ListNode(-1, nullptr);
        ListNode* temp = dummyNode;
        while(list1 != nullptr && list2 != nullptr){
            if(list1->data <= list2->data){
                temp->next = list1;
                list1 = list1->next;
            }
            else{
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }

        if(list1 != nullptr) temp->next = list1;    
        else temp->next = list2;

        return dummyNode->next;
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
    ListNode* head2 = new ListNode(1, nullptr);
    ListNode* temp2 = head2;
    for(int i = 0;i < 4;i++){
        ListNode* newNode = new ListNode(i+3, nullptr);
        temp2->next = newNode;
        temp2 = newNode;
    }
    print(head1);
    print(head2);
    //  head3 = new Node(-1);
    ListNode* head3 = sol.mergeTwoLists(head1, head2);
    print(head3);
    return 0;
}