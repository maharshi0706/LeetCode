#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    void markRow(int i, vector<vector<int>>& matrix){
        for(int j = 0;j < matrix[i].size();j++){
            if(matrix[i][j] != 0) matrix[i][j] = -1;
        }
    }

    void markCol(int j, vector<vector<int>>& matrix){
        for(int i = 0;i < matrix.size();i++){
            if(matrix[i][j] != 0) matrix[i][j] = -1;
        }
    }

    vector<vector<int>> setZeroes(vector<vector<int>>& matrix) {
        for(int i = 0;i < matrix.size();i++){
            for(int j = 0;j < matrix[i].size();j++){
                if(matrix[i][j] == 0){
                    // mark entire row and column for 0
                    markRow(i, matrix);
                    markCol(j, matrix);
                }
            }
        }
        for(int i = 0;i < matrix.size();i++){
            for(int j = 0;j < matrix[i].size();j++){
                if(matrix[i][j] == -1) matrix[i][j] = 0;
            }
        }

        return matrix;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    vector<vector<int>> output = sol.setZeroes(matrix);
    for(auto row: output){
        for(auto col: row){
            cout<<col<<" ";
        }
        cout<<endl;
    }
    return 0;
}