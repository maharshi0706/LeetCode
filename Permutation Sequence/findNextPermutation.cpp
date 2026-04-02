#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    vector<int> sequence = {1,3,2};
    
    for(auto it:sequence){
        cout<<it<<" ";
    }
    cout<<endl;

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

    for(auto it: sequence){
        cout<<it<<" ";
    }
    cout<<endl;
    

}
// #include <vector>
// #include <iostream>
// #include <algorithm>
// using namespace std;

// int main(){
//     vector<int> sequence = {1,2,3};
    
//     for(auto it:sequence){
//         cout<<it<<" ";
//     }
//     cout<<endl;

//     int pivot = -1;
//     int pivotIndex = -1;
//     for(int i = sequence.size()-1;i > 0;i--){
//         if(sequence[i-1] < sequence[i]){
//             pivot = sequence[i-1];
//             pivotIndex = i-1;
//             break;
//         }  
//     }
//     if(pivot != -1){
//         int nextBig = sequence[0];
//         int nextBigIndex = 0;
//         for(int j = 1;j < sequence.size();j++){
//             if(sequence[j] < pivot && sequence[j] > sequence[j-1]) {
//                 // nextBig = max(sequence[j], nextBig);
//                 nextBig = sequence[j];
//                 nextBigIndex = j;
//             }
//         }
//         std::iter_swap(sequence.begin() + pivotIndex, sequence.begin() + nextBigIndex);
        
//         for(auto it:sequence){
//             cout<<it<<" ";
//         }
//         cout<<endl;
        
//         std::reverse(sequence.begin() + pivotIndex, sequence.end());
        
//         for(auto it:sequence){
//             cout<<it<<" ";
//         }
//         cout<<endl;
//     }
//     // else{
//     std::reverse(sequence.begin(), sequence.end());
//     // }

//     for(auto it:sequence){
//         cout<<it<<" ";
//     }
//     cout<<endl;
    

// }