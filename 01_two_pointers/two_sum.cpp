#include<bits/stdc++.h>

using namespace std;

class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        int left=0, right=arr.size()-1;
        sort(arr.begin(), arr.end());
        while(left<right){
            int sum= arr[left]+arr[right];
            if(sum==target)
                return true;
            else if(sum<target)
                left++;
            else
                right--;
        }
        return false;
    }
};

int main(){
    int n, target;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    cin >> target;
    Solution sol;
    cout << sol.twoSum(arr, target) << endl;
}