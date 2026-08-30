#include <queue>
#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minPQ;
        for(int i = 0;i < k; i++){
            minPQ.push(nums[i]);
        }
        for(int i = k;i < nums.size();i++){
            if(nums[i] > minPQ.top()){
                minPQ.pop();
                minPQ.push(nums[i]);
            }
        }

        return minPQ.top();
    }
};

int main(){
    Solution sol;
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    cout<<sol.findKthLargest(nums, 4)<<endl;
    return 0;
}