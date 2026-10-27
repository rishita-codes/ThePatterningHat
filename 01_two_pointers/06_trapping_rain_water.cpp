#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(), left=0, right=n-1, water=0, leftmax=height[left], rightmax=height[right];
        while(left<right){
            if(height[left] < height[right]){
                if(height[left]>=leftmax){
                    leftmax= height[left];
                }
                else{
                    water += leftmax - height[left];
                }
                left++;
            }
            else{
                if(height[right]>=rightmax){
                    rightmax= height[right];
                }
                else{
                    water += rightmax - height[right];
                }
                right--;
            }

        }
        return water;
    }
};


int main(){
    int n;
    cin >> n;
    vector<int> heights(n);
    for(int i=0; i<n; i++)
        cin >> heights[i];
    Solution sol;
    cout << sol.trap(heights) << endl;
    return 0;
}