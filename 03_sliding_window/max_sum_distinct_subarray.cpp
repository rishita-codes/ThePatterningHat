#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        vector<int> freq(100005, 0); 
        int n= nums.size(), distinct=0;
        long long sum=0;
        long long max_sum= 0;
        for(int i=0; i<n; i++){
            if(freq[nums[i]]==0){
                distinct++;
            }
            sum += nums[i];
            freq[nums[i]]++;
        
            if(i>=k){
                freq[nums[i-k]]--;
                if(freq[nums[i-k]]==0){
                    distinct--;
                }
                sum -= nums[i-k];
            }
            if(i>=k-1 && distinct==k){
                max_sum= max(max_sum, sum);
            }
        }
        return max_sum;
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
    cout << sol.maximumSubarraySum(nums, k) << endl;

    return 0;
}