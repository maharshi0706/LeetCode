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


#include <queue>
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


class Solution {
public:
    struct Compare{
        bool operator()(ListNode* n1, ListNode* n2){
            return n1->data > n2->data;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* outputHead = new ListNode(0, nullptr);
        ListNode* temp = outputHead;
        
        priority_queue<ListNode*, vector<ListNode*>, Compare> minPQ;

        // Add first element of each LL to minPQ
        for(auto it: lists){
            if(it != nullptr) minPQ.push(it);
        }

        // Remove the smallest->Store it->add its next to minPQ
        while(!minPQ.empty()){
            ListNode* topPQ = minPQ.top();
            minPQ.pop();
            temp->next = topPQ;
            temp = topPQ;
            
            if(topPQ->next != NULL) minPQ.push(topPQ->next);
        }

        return outputHead->next;
        
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
    for(int i = 2;i < 12;i+=2){
        ListNode* newNode = new ListNode(i, nullptr);
        temp1->next = newNode;
        temp1 = newNode;
    }
    
    ListNode* head2 = new ListNode(1, nullptr);
    ListNode* temp2 = head2;
    for(int i = 3;i < 12;i+=3){
        ListNode* newNode = new ListNode(i, nullptr);
        temp2->next = newNode;
        temp2 = newNode;
    }

    ListNode* head3 = new ListNode(1, nullptr);
    ListNode* temp3 = head3;
    for(int i = 7;i < 14;i+=2){
        ListNode* newNode = new ListNode(i, nullptr);
        temp3->next = newNode;
        temp3 = newNode;
    }

    vector<ListNode*> input = {head1, head2, head3};
    print(head1);
    print(head2);
    print(head3);
    ListNode* outputHead = sol.mergeKLists(input);
    print(outputHead);
    return 0;
}