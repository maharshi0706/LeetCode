#include <cmath>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution{
public:
    int getBucketSize(int n){
        if (n == 0 || n == 1) return 1;
        return n * getBucketSize(n-1);
    }

    void processPermutation(vector<int>& searchSpace, int n, int k, string& output){
        // Base Case -> if no elements in search space, return
        if(searchSpace.empty()) {
            return;
        }

        // Get number of elements starting with each element of searchspace for every iteration -> (n-1)!
        int bucketSize = getBucketSize(n-1);

        // Get position of starting element from searchspace
        // k-1 -> for 0 indexing | check for k = 0 | divide by bucketSize
        int seqPosition = (k == 0) ? 0 / bucketSize : k / bucketSize;

        // Calculate new num of permutations possible for next iteration
        k = (k == 0) ? 0 : k % bucketSize; 
        
        // Get and Remove element from searchSpace
        int elementInPosition = searchSpace[seqPosition];
        searchSpace.erase(searchSpace.begin() + seqPosition);
        
        // Append to output after int to string
        string element = to_string(elementInPosition);
        output += element;

        // Recursion Call
        processPermutation(searchSpace, searchSpace.size(), k, output);
    }
    
    string getPermutation(int n, int k){
        vector<int> searchSpace;
        for(int i = 0;i < n;i++){
            searchSpace.push_back(i+1);
        }
        for(auto it: searchSpace){
            cout<<it<<" ";
        }
        cout<<endl;

        string output = "";

        processPermutation(searchSpace, n, k-1, output);
        return output;
    }
};


int main(){
    Solution sol;
    string output = sol.getPermutation(3, 3);
    cout<<output<<endl;
    return 0;
}