#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr(n);
        int p=0, q=n-1, k=n-1;
        while(p<=q){
            int psq= nums[p]*nums[p];
            int qsq= nums[q]*nums[q];
            if(psq>qsq){
                arr[k--]= psq;
                p++;
            }
            else{
                arr[k--]= qsq;
                q--;
            }
        }
        return arr;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++)
        cin >> nums[i];
    Solution sol;
    vector<int> arr= sol.sortedSquares(nums);
    for(int i=0; i<n; i++)
        cout<< arr[i] << " ";
    return 0;
}