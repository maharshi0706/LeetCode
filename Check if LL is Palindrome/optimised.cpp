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
#include <stack>
#include <vector>
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

ListNode* reverseLL(ListNode* head){
    ListNode* prev = NULL;
    ListNode* current = head;
    while(current != NULL){
        ListNode* ahead = current->next;
        current->next = prev;
        prev = current;
        current = ahead; 
    }
    return prev;
}
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* secondHead = reverseLL(slow->next);
        ListNode* first = head;
        ListNode* second = secondHead;
        while(second != NULL){
            if(first->data != second->data) {
                reverseLL(secondHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverseLL(secondHead);
        return true;

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
    vector<int> arr = {1,2,3,2,1};
    ListNode* head = new ListNode(arr[0], nullptr);
    ListNode* temp = head;
    for(int i = 1;i < arr.size();i++){
        ListNode* newNode = new ListNode(arr[i], nullptr);
        temp->next = newNode;
        temp = newNode;
    }
    print(head);
    cout<<sol.isPalindrome(head);
    return 0;
}