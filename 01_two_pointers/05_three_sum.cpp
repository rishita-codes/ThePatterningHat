#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n= nums.size();
        vector<vector<int>> v;
        for(int i=0; i<n-2; i++){
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int left=i+1, right=n-1;
            while(left<right){
                int sum= nums[left]+nums[right];
                int target= -nums[i];
                if(sum==target){
                    v.push_back({nums[i], nums[left], nums[right]});
                    while(left<right && nums[left]==nums[left+1])
                        left++;
                    while(left<right && nums[right]==nums[right-1])
                        right--;
                    left++;
                    right--;
                }
                else if(sum<target){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        return v;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++)
        cin >> nums[i];
    Solution sol;
    vector<vector<int>> v= sol.threeSum(nums);
    if(v.empty()){
        cout << "vector empty\n";
    }
    else{
        for(auto i : v){
            for(auto j : i)
                cout << j << " ";
            cout<< endl;
        }
    }

    return 0;
}