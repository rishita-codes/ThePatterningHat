#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        int n= intervals.size(), count=0, prev_end=intervals[0][1];
        for(int i=1; i<n; i++){
            if(intervals[i][0]<prev_end){
                count++;
            }
            else{
                prev_end= intervals[i][1];
            }
        }
        return count;
    }
};

int main(){
    int n;
    cin >> n;
    vector<vector<int>> intervals(n, vector<int>(2));
    for(int i=0; i<n; i++){
        cin >> intervals[i][0] >> intervals[i][1];
    }
    Solution sol;
    int need_to_remove= sol.eraseOverlapIntervals(intervals);
    cout << need_to_remove << endl;

    return 0;
}