#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int n=nums.size(), count=0;
        vector<int> freq(101, 0);
        for(int i=0; i<n; i++){
            if(nums[i]-k >= 1){
                count += abs(freq[nums[i]-k]);
            }
            if(nums[i]+k <= 100){
                count += abs(freq[nums[i]+k]);
            }
            freq[nums[i]]++;
        }
        return count;
    }
};


int main(){
    int n, k;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    cin >> k;
    Solution sol;
    cout << sol.countKDifference(arr, k) << endl;
}