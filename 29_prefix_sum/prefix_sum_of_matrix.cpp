#include<bits/stdc++.h>

using namespace std;

class Solution {
  public:
    vector<vector<int>> computeBeforeMatrix(vector<vector<int>>& after) {
        int m= after.size(), n=after[0].size();
        vector<vector<int>> before(m, vector<int>(n));
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                before[i][j]= after[i][j] 
                - ( (i-1>=0 && j>=0) ? after[i-1][j] : 0 ) 
                - ( (i>=0 && j-1>=0) ? after[i][j-1] : 0 ) 
                + ( (i-1>=0 && j-1>=0) ? after[i-1][j-1] : 0 );
            }
        }
        return before;
    }
};

int main(){
    int m, n;
    cin >> m >> n;
    vector<vector<int>> after(m, vector<int>(n));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> after[i][j];
        }
    }
    Solution sol;
    vector<vector<int>> before= sol.computeBeforeMatrix(after);
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << before[i][j] << " ";
        }
        cout << endl;
    }
}