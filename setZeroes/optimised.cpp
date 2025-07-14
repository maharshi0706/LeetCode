#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> setZeroes(vector<vector<int>>& matrix) {
        // row -> matrix[..][0]
        // col -> matrix[0][..]

        int col = 1;
        for(int i = 0;i < matrix.size();i++){
            for(int j = 0;j < matrix[i].size();j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0; // mark row for 0
                   
                    if(j != 0) matrix[0][j] = 0; // mark col for 0
                   
                    else col = 0; // Unless first element -> {0,0}
                }
            }
        }
        for(int i = 1;i < matrix.size();i++){
            for(int j = 1;j < matrix[i].size();j++){
                if(matrix[i][j] != 0){
                    if(matrix[i][0] == 0 || matrix[0][j] == 0){
                        matrix[i][j] = 0;
                    }
                }   
            }
        }
        if(matrix[0][0] == 0){
            for(int j = 0;j < matrix[0].size();j++){
                matrix[0][j] = 0;
            }
        }
        if(col == 0){
            for(int i = 0;i < matrix.size();i++){
                matrix[i][0] = 0;
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