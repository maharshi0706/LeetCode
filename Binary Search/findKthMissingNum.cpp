#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    int binarySearch(int low, int high, int k, vector<int>& arr){
        if(low > high) return low + k;

        int mid = low + ((high - low) / 2);
        int missingNums = arr[mid] - (mid + 1);
        if(missingNums < k) return binarySearch(mid + 1, high, k ,arr);
        
        return binarySearch(low, mid - 1, k, arr);
    }

    int findKthPositive(vector<int>& arr, int k) {
        return binarySearch(0, arr.size() - 1, k, arr);
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2,3,4};
    cout<<sol.findKthPositive(nums, 2)<<endl;
    return 0;
}