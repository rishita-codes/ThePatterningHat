#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n= intervals.size();
        vector<vector<int>> result;
        
        int i=0;
        while(i<n && intervals[i][1]<newInterval[0]){
            result.push_back(intervals[i]);
            i++;
        }

        while(i<n && intervals[i][0]<=newInterval[1]){
            newInterval[0]= min(newInterval[0], intervals[i][0]);
            newInterval[1]= max(newInterval[1], intervals[i][1]);
            i++;
        }
        result.push_back(newInterval);

        while(i<n){
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};

int main(){
    int n;
    cin >> n;
    vector<vector<int>> intervals(n, vector<int>(2));
    for(int i=0; i<n; i++){
        cin >> intervals[i][0] >> intervals[i][1];
    }
    vector<int> newInterval(2);
    cin >> newInterval[0] >> newInterval[1];
    Solution sol;
    vector<vector<int>> result= sol.insert(intervals, newInterval);
    cout << "result:\n" ;
    for(auto k : result){
        cout << k[0] << " " << k[1] << endl;
    }
    return 0;
}