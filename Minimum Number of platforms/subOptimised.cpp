#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct trainSchedule{
    int arrivalTime;
    int departureTime;

};

class Solution{
public:
    static bool comparator(struct trainSchedule ts1, trainSchedule ts2){
        if(ts1.arrivalTime <= ts2.arrivalTime) return true;
        else if(ts1.arrivalTime > ts2.arrivalTime) return false;
    }

    bool compareArrivalTime(int currArrivalTime, vector<int> currDep){
        for(auto it: currDep){
            if (currArrivalTime > it) return true;
        }
        return false;
    }

    vector<int> updateCurrDepartures(int newDepartureTime, vector<int> currDep){
        sort(currDep.begin(), currDep.end());
        currDep[0] = newDepartureTime;
        return currDep;
    }

    int countPlatforms(vector<int> arr, vector<int> dep){
        int n = arr.size();
        struct trainSchedule trainSchd[n];
        for(int i = 0;i < n;i++){
            trainSchd[i].arrivalTime = arr[i];
            trainSchd[i].departureTime = dep[i];
        }

        sort(trainSchd, trainSchd+n, comparator);

        int platforms = 1;
        vector<int> currDep = {trainSchd[0].departureTime};
        for(int i = 1;i < n; i++){
            if(compareArrivalTime(trainSchd[i].arrivalTime, currDep)){
                // Overlap platform and update lowest departure time with current departure time
                currDep = updateCurrDepartures(trainSchd[i].departureTime, currDep);
            }
            else{
                platforms += 1;
                currDep.push_back(trainSchd[i].departureTime);
            }
        }
        return platforms;
    }
};

int main(){
    Solution sol;
    vector<int> arrivals = {1020,1200};
    // vector<int> arrivals = {900,945,955,1100,1500,1800};
    vector<int> departures = {1050,1230};
    // vector<int> departures = {920,1200,1130,1150,1900,2000};
    cout<<sol.countPlatforms(arrivals, departures)<<endl;
    return 0;
}