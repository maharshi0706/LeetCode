#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    bool getBloomedFlowers(int bloomingDay,int m, int k, vector<int>& bloomDay){
        int counter = 0;
        int bouquetCount = 0;
        for(int i = 0;i < bloomDay.size();i++){
            if(bloomDay[i] <= bloomingDay){
                counter += 1;
                // continue;
            }
            else{
                bouquetCount += (counter / k); // Num of flowers divided by adjacent flowers per bouquet required = num of bouquets made
                counter = 0;
            }
        }
        bouquetCount += (counter / k); // To add last counter value bouquet made
        
        // Check if mid(bloomingDay) is valid
        return bouquetCount >= m;
    }

    int binarySearch(int low, int high, int m, int k, int ans, vector<int>& bloomDay){
        if(low > high) return ans;

        long long mid = low + ((high - low) / 2);
        if(getBloomedFlowers(mid, m, k, bloomDay)) return binarySearch(low, mid - 1, m, k, mid, bloomDay);

        else return binarySearch(mid + 1, high, m, k, ans, bloomDay);
    }

    int minDays(vector<int>& bloomDay, int m, int k){
        // Edge case -> Check if there are enough flowers to make bouquets at all
        if(bloomDay.size() < (m * 1LL * k * 1LL)) return -1;

        return binarySearch(*min_element(bloomDay.begin(), bloomDay.end()), *max_element(bloomDay.begin(), bloomDay.end()), m , k, INT32_MAX, bloomDay);
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,18,13,8,24};
    cout<<sol.minDays(nums, 2, 2)<<endl;
    return 0;
}