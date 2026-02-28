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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyNode = new ListNode(0, head); // Use dummynode for edge case of deleting head;
        ListNode* fast = dummyNode;
        ListNode* slow = dummyNode;

        for(int i = 0;i <= n; i++) fast = fast->next; // Gap should be n+1 & not n -> handling edge case

        while(fast != NULL){
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return dummyNode->next;
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
    for(int i = 2;i <= 5;i++){
        ListNode* newNode = new ListNode(i, nullptr);
        temp->next = newNode;
        temp = newNode;
    }
    print(head);
    head = sol.removeNthFromEnd(head, 2);
    print(head);
    return 0;
}