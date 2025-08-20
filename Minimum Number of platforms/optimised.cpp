#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int countPlatforms(vector<int>& arr, vector<int>& dep){
        sort(arr.begin(), arr.end());        
        sort(dep.begin(), dep.end());        

        int i = 1;
        int j = 0;
        int n = arr.size();
        int platforms = 1;
        int maxPlatforms = INT16_MIN;
        while(i < n && j < n){
            if(arr[i] <= dep[j]){
                platforms += 1;
                i++;
            }
            else{
                platforms -= 1;
                j++;
            }
            maxPlatforms = max(platforms, maxPlatforms);
        }
        return maxPlatforms;
    }
};

int main(){
    Solution sol;
    // vector<int> arrivals = {1020,1200};
    vector<int> arrivals = {900,945,955,1100,1500,1800};
    // vector<int> departures = {1050,1230};
    vector<int> departures = {920,1200,1130,1150,1900,2000};
    cout<<sol.countPlatforms(arrivals, departures)<<endl;
    return 0;
}