#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();
        int maxlen=1;
        vector<int> dp(n, 1);
        dp[0]= 1;
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]>nums[j])
                    dp[i]= max(dp[i], dp[j]+1);
            }
            maxlen= max(maxlen, dp[i]);
        }
        return maxlen;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++)
        cin >> nums[i];
    Solution sol;
    cout << sol.lengthOfLIS(nums) << endl;
    return 0;
}