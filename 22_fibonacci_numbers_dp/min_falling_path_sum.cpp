#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp= matrix;
        for(int i=n-2; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                dp[i][j]= min({ (i+1<n && j-1>=0) ? dp[i+1][j-1] : INT_MAX,
                                dp[i+1][j], 
                                (i+1<n && j+1<n) ? dp[i+1][j+1] : INT_MAX
                                }) + matrix[i][j];
            }
        }
        return *min_element(dp[0].begin(), dp[0].end());
    }
};

int main(){
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> matrix[i][j];
        }
    }
    Solution sol;
    cout << sol.minFallingPathSum(matrix) << endl;
}