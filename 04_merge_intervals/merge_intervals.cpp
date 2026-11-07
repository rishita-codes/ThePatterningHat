#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        vector<int> interval= intervals[0];
        int n= intervals.size();
        for(int i=1; i<n; i++){
            vector<int> cur= intervals[i];
            if(cur[1]<=interval[1]){
                continue;
            }
            if(cur[0]<=interval[1]){
                interval[1]=cur[1];
            }
            else{
                merged.push_back(interval);
                interval= cur;
            }
        }
        merged.push_back(interval);
        return merged;
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
    vector<vector<int>> merged= sol.merge(intervals);
    cout << "merged:\n" ;
    for(auto k : merged){
        cout << k[0] << " " << k[1] << endl;
    }
    return 0;
}