#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix){
        // [0][0] -> first column && col0 -> first row
        // [0][n] -> make column 0
        // [n][0] -> make row 0
        int col0 = 0;
        for(int i = 0;i < matrix.size();i++){
            for(int j = 0;j < matrix[i].size();j++){
                if(matrix[i][j] == 0){
                    if(i == 0 && j == 0) col0 = 0;
                    // else matrix[i][j] = 0;
                    matrix[i][0] = 0; // make row 0
                    matrix[0][j] = 0; // make column 0
                }
            }
        }
        int j = 1;
        for(int i = 0;i < matrix.size();i++){
            if(matrix[i][0] == 0){
                while(j < matrix[i].size()){
                    matrix[i][j++] = 0;
                }
            }
        }
        int i = 1;
        for(int j = 0;j < matrix.size();j++){
            if(matrix[0][j] == 0){
                while(i < matrix.size()){
                    matrix[i++][j] = 0;
                }
            }
        }
        i = 0;
        j = 0;
        if(matrix[i][j] == 0){
            while(j < matrix[i].size()){
                matrix[0][j++] = 0;
            }
        }
        if(col0 == 0){
            while(i < matrix.size()){
                matrix[i++][0] = 0;
            }
        }
        for(auto row: matrix){
            for(auto col: row){
                cout<<col<<" ";
            }
        cout<<endl;
        }
    }
    
};

int main(){
    Solution sol;
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    sol.setZeroes(matrix);
    return 0;
}