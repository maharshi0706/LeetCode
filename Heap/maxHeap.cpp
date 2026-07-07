#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Heap{
public:
    vector<int> heapArray;

    Heap(){
        heapArray.push_back(-1);
    }

    void insert(int val){
        heapArray.push_back(val);
        int index = heapArray.size() - 1; // current insertable position

        while(index > 1){
            int parent = index / 2;
            if(heapArray[index] > heapArray[parent]) {
                std::swap(heapArray[index], heapArray[parent]);
                index = parent;
            }
            else return;
        }
    }

    void deleteFromHeap(){

        if(heapArray.size() <= 1) {
            cout<<"Nothing to delete."<<endl;
            return;
        }
        
        int lastNodeIndex = heapArray.size() - 1;
        heapArray[1] = heapArray[lastNodeIndex]; // Overwrite root with last and pop last
        heapArray.pop_back();

        // print();
        int i = 1;
        while(true){
            int largest = i;
            int leftChildIndex = 2 * i;
            int rightChildIndex = (2 * i) + 1;

            if(leftChildIndex < heapArray.size() && heapArray[leftChildIndex] > heapArray[largest]){
                largest = leftChildIndex;
            }
            if(rightChildIndex < heapArray.size() && heapArray[rightChildIndex] > heapArray[largest]){
                largest = rightChildIndex;
            }
            if(largest == i) break;
            
            std::swap(heapArray[i], heapArray[largest]);
            i = largest;
        }

    }


    void print(){
        for(int i = 0;i < heapArray.size();i++){
            cout<<heapArray[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    Heap heap;
    heap.insert(40);
    heap.insert(50);
    heap.insert(10);
    heap.insert(45);
    heap.insert(60);
    heap.insert(15);
    heap.insert(55);
    heap.insert(58);

    heap.print();
    
    heap.deleteFromHeap();
    heap.print();
    return 0;

}