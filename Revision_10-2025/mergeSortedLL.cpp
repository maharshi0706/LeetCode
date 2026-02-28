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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* newHead = new ListNode(0, nullptr);
        ListNode* head = newHead;

        while(list1 != NULL && list2 != NULL){ // IMPORTANT && -> not ||
            if(list1->val < list2->val){
                head->next = list1;
                list1 = list1->next;
            }
            else if (list2->val <= list1->val){
                head->next = list2;
                list2 = list2->next;
            }
            head = head->next;
        }   
        if(list1 != NULL) head->next = list1;
        if(list2 != NULL) head->next = list2;
        return newHead->next;
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

    ListNode* head = new ListNode(1,nullptr);
    ListNode* temp = head;
    for(int i = 2;i <= 8;i+=2){
        ListNode* newnode = new ListNode(i, nullptr);
        temp->next = newnode;
        temp = newnode;
    }
    ListNode* head1 = new ListNode(0,nullptr);
    ListNode* temp1 = head1;
    for(int i = 1;i <= 9;i+=2){
        ListNode* newnode = new ListNode(i, nullptr);
        temp1->next = newnode;
        temp1 = newnode;
    }
    print(head);
    print(head1);
    ListNode* head2 = sol.mergeTwoLists(head, head1);
    print(head2);
    return 0;
}