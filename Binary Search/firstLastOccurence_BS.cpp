#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    int binarySearchFirst(int low, int high, int target, int first, vector<int>& nums){
        if(low > high) return first;

        int mid = low + ((high - low) / 2);
        if(nums[mid] == target) return binarySearchFirst(low, mid - 1, target, mid, nums);

        else if(nums[mid] > target) return binarySearchFirst(low, mid - 1, target, first, nums);

        else return binarySearchFirst(mid + 1, high, target, first, nums);
    }

    int binarySearchLast(int low, int high, int target, int last, vector<int>& nums){
        if(low > high) return last;

        int mid = low + ((high - low) / 2);
        if(nums[mid] == target) return binarySearchLast(mid + 1, high, target, mid, nums);

        else if(nums[mid] > target) return binarySearchLast(low, mid - 1, target, last, nums);

        else return binarySearchLast(mid + 1, high, target, last, nums);
    }
    
    pair<int, int> firstLastOccurence(int target, vector<int>& nums){

        int first = binarySearchFirst(0, nums.size() - 1, target, -1, nums);
        int last = binarySearchLast(0, nums.size() - 1, target, -1, nums);

        return {first, last};
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,4,6,8,8,8,11,13};
    pair<int, int> firstAndLast = sol.firstLastOccurence(15, nums);
    cout<<firstAndLast.first<<"\t"<<firstAndLast.second<<endl;
    return 0;
}