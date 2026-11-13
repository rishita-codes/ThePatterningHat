#include<bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int minMeetingRoomsHeap(vector<int> &start, vector<int> &end) {
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

    // sweep-line algorithm
    int minMeetingRoomsTwoPointer(vector<int> &start, vector<int> &end) {
        int rooms=0, n=start.size();
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int s_ptr=0, e_ptr=0, max_rooms=0;
        while(s_ptr<n){
            if(start[s_ptr]<end[e_ptr]){
                rooms++;
                s_ptr++;
            }
            else{
                rooms--;
                e_ptr++;
            }
            max_rooms= max(max_rooms, rooms);
        }
        return max_rooms;
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
    cout << sol.minMeetingRoomsHeap(start, end) << endl;
    cout << sol.minMeetingRoomsTwoPointer(start, end) << endl;

    return 0;
}