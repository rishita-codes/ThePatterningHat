#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0, right= height.size()-1, max_water=0;
        while(left<right){
            int w= right-left, h;
            if(height[left]<height[right]){
                h= height[left];
                left++;
            }
            else{
                h= height[right];
                right--;
            }
            int cur= h*w;
            max_water= max(cur, max_water);
        }
        return max_water;
    }
};


int main(){
    int n;
    cin >> n;
    vector<int> heights(n);
    for(int i=0; i<n; i++)
        cin >> heights[i];
    Solution sol;
    cout << sol.maxArea(heights) << endl;
    return 0;
}