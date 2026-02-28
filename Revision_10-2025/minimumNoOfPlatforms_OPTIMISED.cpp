#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int findPlatform(vector<int>& Arrival, vector<int>& Departure){
       // Sort Arrivals and Departures Separately
       sort(Arrival.begin(), Arrival.end()); 
       sort(Departure.begin(), Departure.end());
       
       int i = 0, j = 0; // Separate iterators for Arr and Dep
       int n = Arrival.size();
       int platforms = 0, maxPlatforms = 0;

       while(i < n && j < n){
        if(Arrival[i] <= Departure[j]){
            platforms += 1;
            i++;
        }
        else{
            platforms -= 1;
            j++;
        }
        maxPlatforms = max(maxPlatforms, platforms);
       }
       return maxPlatforms;
    }
};


int main(){
    Solution sol;
    // vector<int> arrivals = {900, 1100, 1235};
    vector<int> arrivals = {900, 940, 950, 1100, 1500, 1800};
    // vector<int> departures = {1000, 1200, 1240};
    vector<int> departures = {910, 1200, 1120, 1130, 1900, 2000};
    cout<<sol.findPlatform(arrivals, departures)<<endl;
    return 0;
}