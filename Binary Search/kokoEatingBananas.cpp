#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    long long totalTimeTaken(vector<int>& piles, int minEatingSpeed){
        long long totalHours = 0;
        for(int i = 0;i < piles.size();i++){
            totalHours += ceil((double)piles[i] / (double)minEatingSpeed);
        }
        return totalHours;
    }

    int binarySearch(int low, int high, int ans, int h, vector<int>& piles){
        // Base condition
        if(low > high) return ans;

        int mid = low + ((high - low) / 2);
        if(totalTimeTaken(piles, mid) <= h) return binarySearch(low, mid - 1, mid, h, piles);

        else return binarySearch(mid + 1, high, ans, h, piles);
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        return binarySearch(1, *max_element(piles.begin(), piles.end()), INT32_MAX, h, piles);
    }
};


int main(){
    Solution sol;
    vector<int> nums = {30,11,23,4,20};
    cout<<sol.minEatingSpeed(nums, 5)<<endl;
    return 0;
}