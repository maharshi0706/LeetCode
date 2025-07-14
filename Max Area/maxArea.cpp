#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int left = 0;
        int right = height.size()-1;
        while(left<right){
            int minimum = min(height[left],height[right]);
            int currArea = (minimum * (right-left));
            if(currArea > maxArea) maxArea = currArea;

            if(minimum == height[left]) left++;

            else if(minimum == height[right]) right--;

            else{
                left += 1;
                right -= 1;
            }
        }
        return maxArea;
    }
};


int main(){
    Solution sol;
    vector<int> height = {1,1};
    // vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout<<sol.maxArea(height)<<endl;
    return 0;
}