#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> previous;
        vector<vector<int>> output;
        for(int i = 0;i < numRows;i++){
            vector<int> curr(i+1, 1);
            for(int j = 1;j < i;j++){
                curr[j] = previous[j] + previous[j-1];
            }
            output.push_back(curr);
            previous = curr;
        }
        return output;
    }
};


int main(){
    Solution sol;
    int numRows = 5;
    vector<vector<int>> output = sol.generate(numRows);
    for(auto row: output){
        for(auto col: row){
            cout<<col<<" ";
        }
        cout<<endl;
    }
    return 0;
}