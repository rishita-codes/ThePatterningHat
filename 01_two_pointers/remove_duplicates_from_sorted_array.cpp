#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1, j=1;
        while(j<nums.size()){
            if(nums[j]!=nums[j-1]){
                nums[i++]= nums[j];
            }
            j++;
        }
        return i;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    Solution sol;
    int k= sol.removeDuplicates(arr);
    for(int i=0; i<k; i++)
        cout<< arr[i] << " ";
    return 0;
}