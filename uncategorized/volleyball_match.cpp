#include<bits/stdc++.h>

using namespace std;

bool isTerminal(int a, int b){
    int max_score= max(a, b);
    int min_score= min(a, b);
    if(max_score==25 && min_score<24)
        return true;
    if(max_score>25 && min_score>=24 && max_score-min_score!=2)
        return true;
    return false;
}

long long diffSeq(int a, int b){
    int max_a= max(a, b);
    int max_b= min(a, b);
    if(max_a < 25)
        return 0;
    if(max_a == 25 && max_b >= 24)
        return 0;
    if(max_a > 25){
        if(max_b<24 || max_a-max_b != 2)
            return 0;
    }
    vector<vector<long long>> dp(a+1, vector<long long>(b+1, 0));
    dp[0][0]=1;
    for(int i=0; i<=a; i++){
        for(int j=0; j<=b; j++){
            if(i==0 && j==0)
                continue;
            long long ways= 0;
            if(i>0){
                if(!isTerminal(i-1, j)){
                    ways = (ways+dp[i-1][j]) % (1000000007);
                }
            }
            if(j>0){
                if(!isTerminal(i, j-1)){
                    ways = (ways+dp[i][j-1]) % (1000000007);
                }
            }
            dp[i][j]= ways;
        }
    }
    return dp[a][b];
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << diffSeq(a, b);
       
    return 0;
}
