#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // bool isPresent = false;
        for(int i = 0;i < matrix.size();i++){
            if(target <= matrix[i].back()){
                for(int j = 0;j < matrix[i].size();j++){
                    if(matrix[i][j] == target) {
                        // isPresent = true;
                        return true;
                        // break;
                    }
                }
                return false;
            }
            
            // if(!isPresent) return isPresent;
        }
        return false;
    }
};



int main(){
    Solution sol;
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    // vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 13;
    bool output = sol.searchMatrix(matrix, target);
    cout<<output<<endl;
    return 0;
}