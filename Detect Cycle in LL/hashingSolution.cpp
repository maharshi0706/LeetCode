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
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, int> nodeCount;
        ListNode* temp = head;
        while (temp != NULL){
            if(nodeCount.find(temp) != nodeCount.end()) return true;
            
            nodeCount[temp] = 1;
            temp = temp->next;
        }
        return false;
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
    for(int i = 0;i < 4;i++){
        ListNode* newNode = new ListNode(i+2, nullptr);
        temp->next = newNode;
        temp = newNode;
    }
    print(head);
    // temp->next = head->next;
    cout<<sol.hasCycle(head);
    return 0;
}