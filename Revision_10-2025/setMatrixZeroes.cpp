#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    void markRow(int i, vector<vector<int>>& matrix){
        int j = 1;
        while(j < matrix[i].size()){
            matrix[i][j++] = 0;
        }
    }

    void markCol(int j, vector<vector<int>>& matrix){
        int i = 1;
        while(i < matrix.size()){
            matrix[i++][j] = 0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix){
        // [0][0] -> first column && col0 -> first row
        // [0][n] -> make column 0
        // [n][0] -> make row 0
        int col0 = 0;
        for(int i = 0;i < matrix.size();i++){
            for(int j = 0;j < matrix[i].size();j++){
                if(matrix[i][j] == 0){
                    if(j == 0) col0 = 1;
                    else matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        // MARK ROW BASED ON 0's outside of first row
        int i = 1;
        while(i < matrix.size()){
            if(matrix[i][0] == 0){
                markRow(i, matrix);
            }
            i++;
        }

        // MARK COLUMN BASED ON 0's outside of first column
        int j = 1;
        while(j < matrix[0].size()){
            if(matrix[0][j] == 0){
                markCol(j, matrix);
            }
            j++;
        }

        // Modify First Row FIRST -> Since col0 will modify first column and if that modified first then cause problem
        if(matrix[0][0] == 0){
            for(int j = 0;j < matrix[0].size();j++){
                matrix[0][j] = 0;
            }
        }

        // Modify first column if flag active
        if(col0 == 1){
            for(int i = 0;i < matrix.size();i++){
                matrix[i][0] = 0;
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
    vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    // vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    sol.setZeroes(matrix);
    return 0;
}