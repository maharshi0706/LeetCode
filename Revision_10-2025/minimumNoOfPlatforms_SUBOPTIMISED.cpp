#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

    bool checkArrivalTime(int arr, vector<int>& trainsWaiting){
        for(auto dep: trainsWaiting){
            if(arr < dep) continue;

            else return false;
        }
        return true;
    }

    int findPlatform(vector<int>& Arrival, vector<int>& Departure){
        vector<tuple<int, int>> trainTimesSorted;
        for(int i = 0;i < Arrival.size();i++){
            trainTimesSorted.push_back({Departure[i], Arrival[i]});
            // trainTimesSorted[i][0] = Departure[i];
            // trainTimesSorted[i][1] = Arrival[i];
            // trainTimesSorted[i][0] = Departure[i];
        } 

        sort(trainTimesSorted.begin(), trainTimesSorted.end()); // Sort based on departure times;

        vector<int> trainsWaiting;
        trainsWaiting.push_back(get<0>(trainTimesSorted[0])); // Add first train's depart time into list 
        
        int numOfPlatforms = 1;

        for(int i = 1;i < Arrival.size();i++){
            int dep = get<0>(trainTimesSorted[i]);
            int arr = get<1>(trainTimesSorted[i]);
            // int maxDepartureTime = getMaxTime(trainsWaiting);
            if(checkArrivalTime(arr, trainsWaiting)){
                numOfPlatforms += 1;
            }
            else{
                auto it = std::min_element(trainsWaiting.begin(), trainsWaiting.end());
                if(it != trainsWaiting.end()) trainsWaiting.erase(it);
            }
            // cout<<dep<<" "<<arr<<endl;
            trainsWaiting.push_back(dep);
        }
        return numOfPlatforms;
    }
};


int main(){
    Solution sol;
    vector<int> arrivals = {900, 1100, 1235};
    // vector<int> arrivals = {900, 940, 950, 1100, 1500, 1800};
    vector<int> departures = {1000, 1200, 1240};
    // vector<int> departures = {910, 1200, 1120, 1130, 1900, 2000};
    cout<<sol.findPlatform(arrivals, departures)<<endl;
    return 0;
}