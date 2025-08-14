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
#include <unordered_map>
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) return head;

        ListNode* temp = head;
        int len = 1;
        while(temp->next != NULL){
            len += 1;
            temp = temp->next;
        }
        temp->next = head;
        k = k % len;
        int rotateLen = len - k;
        while(rotateLen--) temp = temp->next;
        
        head = temp->next;
        temp->next = NULL;
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
    for(int i = 0;i < 5;i++){
        ListNode* newNode = new ListNode(i+2, nullptr);
        temp->next = newNode;
        temp = newNode;
    }
    print(head);
    head = sol.rotateRight(head, 13);
    print(head);
    return 0;
}