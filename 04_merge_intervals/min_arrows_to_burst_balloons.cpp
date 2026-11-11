#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    static bool compare(vector<int> a, vector<int> b){
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), compare);
        int n= points.size(), lastShoot=points[0][1], count=1;
        for(int i=1; i<n; i++){
            vector<int> cur= points[i];
            if(cur[0]>lastShoot){
                count++;
                lastShoot= cur[1];
            }
        }
        return count;
    }
};

int main(){
    int n;
    cin >> n;
    vector<vector<int>> points(n, vector<int>(2));
    for(int i=0; i<n; i++){
        cin >> points[i][0] >> points[i][1];
    }
    Solution sol;
    int arrows= sol.findMinArrowShots(points);
    cout << arrows << endl;

    return 0;
}