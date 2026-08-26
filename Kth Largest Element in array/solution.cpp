#include <queue>
#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    int findKthLargest(vector<int>& nums, int k) {
        """
            Using Max Heap. O(N log N).
        """
        priority_queue<int> pq;
        for(auto num: nums){
            pq.push(num);
        }

        k -= 1;
        while(k--) pq.pop();

        return pq.top();
    }
};

int main(){
    Solution sol;
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    cout<<sol.findKthLargest(nums, 4)<<endl;
    return 0;
}