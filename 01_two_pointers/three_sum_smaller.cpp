#include<bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int countTriplets(int sum, vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n= arr.size(), count=0;
        for(int i=0 ;i<n-2; i++){
            if(i>0 && arr[i]==arr[i-1])
                continue;
            int left= i+1;
            int right= n-1;
            while(left<right){
                int cur_sum= arr[i]+arr[left]+arr[right];
                if(cur_sum<sum){
                    count += right-left;
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        return count;
    }
};


int main(){
    int n, sum;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    cin >> sum;
    Solution sol;
    cout << sol.countTriplets(sum, arr) << endl;

    return 0;
}