#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int left = 0;
        int right = (m * n) - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            int midValue = matrix[mid / n][mid % n];
            if(midValue == target) return true;
            else if(midValue > target) right = mid - 1;
            else left = mid + 1;
        }
        return false;
    }
};



int main(){
    Solution sol;
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    // vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 16;
    bool output = sol.searchMatrix(matrix, target);
    cout<<output<<endl;
    return 0;
}