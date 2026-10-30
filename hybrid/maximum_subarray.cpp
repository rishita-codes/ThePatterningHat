#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int max_sum= nums[0];
        int cur_sum= nums[0];
        for(int i=1; i<n; i++){
            cur_sum= max(cur_sum+nums[i], nums[i]);
            max_sum= max(max_sum, cur_sum);
        }
        return max_sum;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    Solution sol;
    cout << sol.maxSubArray(nums) << endl;

    return 0;
}