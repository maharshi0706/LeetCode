// loop through each word -> add letter in string if match ?
// compare first and second word -> store common prefix -> check prefix in rest words -> remove if not present -> return 

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            if(strs.size() == 1) return strs[0];

            string output = "";
            string firstWord = strs[0];
            string secondWord = strs[1];
            // cout<<"First word: "<<firstWord<<"\n Second word: "<<secondWord<<endl;
            int n = (firstWord.size() < secondWord.size()) ? firstWord.size() : secondWord.size();

            // cout<<n<<endl;
            for(int i = 0;i < n; i++){
                // cout<<firstWord[i]<<" "<<secondWord[i]<<endl;
                if(firstWord[i] == secondWord[i]){
                    // cout<<firstWord[i]<<endl;
                    output.push_back(firstWord[i]);
                }
                else break;
            }
            cout<<"INITIAL OUTPUT: "<<output<<endl;
            
            if (strs.size() == 2) return output; // IF ONLY 2 Words present in vector

            for(int i = 2;i < strs.size(); i++){
                // int n = (strs[i].size() < output.size()) ? strs[i].size() : output.size();
                // cout<<"N: "<<n<<endl;
                if(strs[i] == "") return "";
                // else if(strs[i].size() < output.size()) {
                //     cout<<"IN ELIF"<<endl;
                //     cout<<"STRS VAL: "<<strs[i]<<endl;
                //     cout<<"STRS size: "<<strs[i].size()<<" OUTPUT size: "<<output.size()<<endl;
                //     output.erase(strs[i].size(), output.size()-1);
                // }
                else{
                    cout<<"IN ELSE"<<endl;
                    for(int j = 0;j < output.size(); j++){
                        // if(output[j] == strs[i][j]){
                        //     continue;
                        // }
                        if(output[j] != strs[i][j]){
                            // cout<<"Val: "<<output[j]<<endl;
                            output.erase(j);
                            // cout<<"LEN OF OUTPUT: "<<output.size()<<endl;
                        }
                    }

                }
            }
            // cout<<"FINAL OUTPUT: "<<output<<endl;
            return output;
        }
};

int main(){
    Solution sol;
    // vector<string> strs = {"cb","cbb","a"};
    // vector<string> strs = {"dog","racecar","car"};
    // vector<string> strs = {"cir","car"};
    vector<string> strs = {"flower","flow","flight","fly"};
    string result = sol.longestCommonPrefix(strs);
    cout<<"RESULT: "<<result<<endl;
    return 0;
}