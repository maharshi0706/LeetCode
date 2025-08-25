#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

struct AllJobs{
    int jobId;
    int deadLine;
    int profit;
};

class Solution{  
  public:  
    bool static comparator(AllJobs j1, AllJobs j2){
        if(j1.profit < j2.profit) return false;
        else return true;
    }

    int findMaxDeadline(int n, AllJobs job[]){
        int maxDeadline = job[0].deadLine;
        for(int i = 1;i < n;i++){
            maxDeadline = max(maxDeadline, job[i].deadLine);
        }
        return maxDeadline;
    } 

    vector<int> JobScheduling(vector<vector<int>>& Jobs) { 
        int n = Jobs.size();
        struct AllJobs jobs[n];
        for(int i = 0;i < n;i++){
            jobs[i].jobId = Jobs[i][0];
            jobs[i].deadLine = Jobs[i][1];
            jobs[i].profit = Jobs[i][2];
        }
        sort(jobs, jobs + n, comparator);

        int maxDeadline = findMaxDeadline(n, jobs);

        vector<int> jobSequence(maxDeadline+1, -1);
        int profit = 0;
        int numOfJobs = 0;
        for(int i = 0;i < n;i++){
            int currDeadline = jobs[i].deadLine;
            for(int j = currDeadline;j > 0;j--){
                if(jobSequence[j] == -1){
                    jobSequence[j] = i;
                    numOfJobs++;
                    profit += jobs[i].profit;
                    break;
                }
            }
        }
            // if(jobSequence[currDeadline] == -1){
            //     profit += jobs[i].profit;
            //     numOfJobs += 1;
            //     jobSequence[currDeadline] = jobs[i].jobId;
            // }
            // else{
            //     while(--currDeadline){
            //         if(jobSequence[currDeadline] == -1){
            //             profit += jobs[i].profit;
            //             numOfJobs += 1;
            //             jobSequence[currDeadline] = jobs[i].jobId;
            //             break;
            //         }
            //     }
            // }
        // }
        return {numOfJobs, profit};
    } 
};


int main(){
    Solution sol;
    // vector<vector<int>> input = {{1, 2, 100} , {2, 1, 19} , {3, 2, 27} , {4, 1, 25} , {5, 1, 15}};
    vector<vector<int>> input = {{1, 4, 20} , {2, 1, 10} , {3, 1, 40} , {4, 1, 30}};
    vector<int> output = sol.JobScheduling(input);
    for(auto it: output){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}