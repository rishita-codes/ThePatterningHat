#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n= nums.size();
        for(int i=0; i<n; ){
            if(nums[i]<n && nums[i]!=nums[nums[i]]){
                swap(nums[i], nums[nums[i]]);
            }
            else{
                i++;
            }
        }
        for(int i=0; i<n; i++){
            if(nums[i]!=i){
                return i;
            }
        }
        return n;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++)
        cin >> nums[i];
    Solution sol;
    cout << sol.missingNumber(nums) << endl;
    return 0;
}