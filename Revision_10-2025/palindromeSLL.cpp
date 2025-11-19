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

    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        if(fast != NULL) slow = slow->next; // MOVE slow ahead by 1 SINCE ODD LENGTH

        slow = reverseList(slow);
        while(slow != NULL){
            if(head->val != slow->val) return false;

            head = head->next;
            slow = slow->next;
        }
        return true;
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
    cout<<sol.isPalindrome(head)<<endl;
    return 0;
}