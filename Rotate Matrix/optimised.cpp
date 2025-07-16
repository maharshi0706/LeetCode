#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // vector<vector<int>> temp(matrix.size());
        for(int i = 0;i < matrix.size();i++){
            for(int j = i+1;j < matrix[i].size();j++){
                // int temp = matrix[i][j];
                // matrix[i][j] = matrix[j][i];
                // matrix[j][i] = temp; 
                swap(matrix[i][j], matrix[j][i]);
            }
            reverse(matrix[i].begin(), matrix[i].end());
        }

        for(int i = 0;i < matrix.size();i++){
            for(int j = 0;j < matrix[i].size();j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};


int main(){
    Solution sol;
    // vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    sol.rotate(matrix);
    return 0;
}