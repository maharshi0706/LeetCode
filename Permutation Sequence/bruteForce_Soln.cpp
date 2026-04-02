#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution{
public:
    void findPermutation(vector<int>& sequence, int k){
        if(k == 0){
            for(auto it: sequence){
                cout<<it<<" ";
            }
            cout<<endl;
            return;
        }

        // loop from right to left
        int n = sequence.size()-1;
        bool toSort = true;
        for(int i = n-1;i >= 0;i--){
            if(sequence[i] < sequence[i+1]){
                for(int j = n;j > i;j--){
                    if(sequence[j] > sequence[i]){
                        // swap
                        int temp = sequence[j];
                        sequence[j] = sequence[i];
                        sequence[i] = temp;
                        break;
                    }
                }
                reverse(sequence.begin()+i+1, sequence.end());
                toSort = false;
                break;
            }
        }
        if(toSort) sort(sequence.begin(), sequence.end());
        
        findPermutation(sequence, k-1);

    }

    string getPermutation(int n, int k){
        vector<int> sequence;
        for(int i = 0;i < n;i++) sequence.push_back(i+1);

        for(auto it: sequence){
                cout<<it<<" ";
            }
        cout<<endl;
        
        findPermutation(sequence, k-1);
        return "";
    }
};


int main(){
    Solution sol;
    string output = sol.getPermutation(3,3);
    cout<<output<<endl;
    return 0;
}