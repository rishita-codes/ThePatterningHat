#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size(), min_sub= INT_MAX, sub=0, sum=0;
        for(int i=0, j=0; i<n; i++){
            sum += nums[i];
            while(sum>=target){
                sub = i-j+1;
                min_sub= min(min_sub, sub);
                sum -= nums[j];
                j++;
            }
        }
        if(min_sub==INT_MAX)
            return 0;
        return min_sub;
    }
};

int main(){
    int n, k;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++)
        cin >> nums[i];
    cin >> k;
    Solution sol;
    cout << sol.minSubArrayLen(k, nums) << endl;

    return 0;
}