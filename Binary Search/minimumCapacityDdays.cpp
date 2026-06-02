#include <vector>
#include <numeric>
#include <iostream>
using namespace std;

class Solution{
public:
    bool checkDaysTaken(int weightCapacity, int days, vector<int>& weights){
        int daysTaken = 0;
        int weight = 0; 
        int i = 0;
        while(i < weights.size()){
            if((weight + weights[i]) <= weightCapacity) weight += weights[i++];

            else{
                daysTaken++;
                weight = 0;
            }
        }
        daysTaken++;
        return daysTaken <= days;
    }

    int binarySearch(int low, int high, int days, int ans, vector<int>& weights){
        if(low > high) return ans;

        int mid = low + ((high - low) / 2);
        if(checkDaysTaken(mid, days, weights)) return binarySearch(low, mid - 1, days, mid, weights);

        else return binarySearch(mid + 1, high, days, ans, weights);
    }

    int shipWithinDays(vector<int>& weights, int days){
        return binarySearch(*max_element(weights.begin(), weights.end()), accumulate(weights.begin(), weights.end(), 0), days, -1, weights);
    }
};

int main(){
    Solution sol;
    vector<int> weights = {1,2,3,1,1};
    cout<<sol.shipWithinDays(weights, 4)<<endl;
    return 0;
}