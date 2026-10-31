//  Given ‘n’ Jars filled with ‘m’ number of Jellybeans. ‘T’ represents the number of 
//  operations performed on these jars. Given a range [a-b] and number of jelly beans to be 
//  filled in the jars lying in the range [a-b], find the number of jelly beans in each jar after 
//  these ‘T’ operations .. take this eg and solve : n=5, m=2, op=[[1,3],[2,4]], k=[4,3]

#include<bits/stdc++.h>

using namespace std;

vector<int> getModifiedArray(int n, int m, vector<vector<int>> op){
    vector<int> arr(n+2, 0);
    for(auto p : op){
        arr[p[0]] += p[2];
        arr[p[1]+1] -= p[2];
    }
    for(int i=1; i<=n; i++){
        arr[i] += arr[i-1] ;
    }
    vector<int> res(n);
    for(int i=0; i<n; i++){
        res[i]=arr[i+1] + m;
    }
    return res;
}

int main(){
    int n, m, t;
    cin >> n >> m >> t;
    vector<vector<int>> op(t, vector<int>(3));
    for(int i=0; i<t; i++){
        cin >> op[i][0] >> op[i][1] >> op[i][2];  // a, b, k
    }
    vector<int> arr= getModifiedArray(n, m, op);
    for(auto i : arr)
        cout << i << " ";
    return 0;
}

/*
5 2 2
1 3 4
2 4 3
*/