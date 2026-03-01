#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    void printAllSubsets(vector<int> input, vector<int> output){
        // Base case -> IF INPUT EMPTY, PRINT OUTPUT & RETURN
        if(input.size() == 0) {
            for(auto it: output){
                cout<<it<<" ";
            }
            cout<<endl;
            return;
        }

        int first = input[0];
        output.push_back(first);
        printAllSubsets(vector<int>(input.begin() + 1, input.end()), vector<int>(output.begin(), output.end() - 1)); // Exclude case
        printAllSubsets(vector<int>(input.begin() + 1, input.end()), output); // Include case

    }
};


int main(){
    Solution sol;
    sol.printAllSubsets({5,2,1},{});
    return 0;
}