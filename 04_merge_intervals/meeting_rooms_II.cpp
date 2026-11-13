#include<bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        int rooms=1, n=start.size();
        vector<vector<int>> intervals(n, vector<int>(2));
        for(int i=0; i<n; i++){
            intervals[i][0]= start[i];
            intervals[i][1]= end[i];
        }
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> minHeap;
        minHeap.push(intervals[0][1]);
        for(int i=1; i<n; i++){
            vector<int> cur= intervals[i];
            int earliestEnding= minHeap.top();
            if(cur[0]<earliestEnding){
                rooms++;
            }
            else{
                minHeap.pop();
            }
            minHeap.push(cur[1]);
        }
        return rooms;
    }
};


int main(){
    int n;
    cin >> n;
    vector<int> start(n);
    vector<int> end(n);
    for(int i=0; i<n; i++){
        cin >> start[i];
    }
    for(int i=0; i<n; i++){
        cin >> end[i];
    }
    Solution sol;
    cout << sol.minMeetingRooms(start, end) << endl; 

    return 0;
}