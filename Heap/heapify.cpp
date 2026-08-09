#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Heap{
public:
    void heapifyMax(vector<int>& nums, int i, int size){
        int largest = i;
        int leftChildIndex = i*2 + 1;
        int rightChildIndex = i*2 + 2;

        if(leftChildIndex < size && nums[largest] < nums[leftChildIndex]) largest = leftChildIndex;

        if(rightChildIndex < size && nums[largest] < nums[rightChildIndex]) largest = rightChildIndex;

        if(largest != i){
            std::swap(nums[largest], nums[i]);
            // i = largest;
            heapifyMax(nums, largest, size);
        }
    }
    
    void heapifyMin(vector<int>& nums, int i){
        int smallest = i;
        int leftChildIndex = i*2 + 1;
        int rightChildIndex = i*2 + 2;

        if(leftChildIndex < nums.size() && nums[smallest] > nums[leftChildIndex]) smallest = leftChildIndex;

        if(rightChildIndex < nums.size() && nums[smallest] > nums[rightChildIndex]) smallest = rightChildIndex;

        if(smallest != i){
            std::swap(nums[smallest], nums[i]);
            // i = largest;
            heapifyMin(nums, smallest);
        }
    }

    void heapify(vector<int>& nums){
        for(int i = nums.size() / 2 - 1;i >= 0;i--){
            heapifyMax(nums, i, nums.size());
            // heapifyMin(nums, i);
        }

        // return nums;
    }

    void heapSort(vector<int>& nums){
        int size = nums.size();
        while(size>1){
            std::swap(nums[0], nums[size-1]);
            size--;
    
            heapifyMax(nums, 0, size);
        }
    }

    void print(vector<int>& nums){
        for(int i = 0;i < nums.size();i++){
            cout<<nums[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    Heap h;
    vector<int> nums = {54,53,55,52,50};
    h.heapify(nums);
    h.print(nums);
    h.heapSort(nums);
    h.print(nums);
    return 0;

}