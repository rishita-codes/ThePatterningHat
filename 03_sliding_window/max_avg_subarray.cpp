#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        double sum=0;
        for(int i=0; i<k; i++){
            sum+= nums[i];
        }
        double avg= sum/k;
        double max_avg= INT_MIN;
        max_avg= max(max_avg, avg);
        for(int i=1; i<=n-k; i++){
            sum-= nums[i-1];
            sum+= nums[i+k-1];
            avg= sum/k;
            max_avg= max(max_avg, avg);
        }
        return max_avg;
    }
};

int main(){
    int n, k;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    cin >> k;
    Solution sol;
    cout << sol.findMaxAverage(nums, k) << endl;

    return 0;
}