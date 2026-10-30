// Given a string consisting of letters that indicate directions i.e. ‘L’ for left, ‘R’ for right, ‘U’
// for, up and ‘D’ for down, find the minimum length of string that can be obtained after
// deleting some characters of the string so that we reach the same destination as the
// original string.

#include<bits/stdc++.h>

using namespace std;

int minDir(string s){
    int x=0, y=0;
    for(char ch : s){
        if(ch=='L')
            x--;
        else if(ch=='R')
            x++;
        else if(ch=='D')
            y--;
        else if(ch=='U')
            y++;
    }
    return abs(x) + abs(y);
}

int main(){
    string s;
    cin >> s;
    cout << minDir(s) << endl;

    return 0;
}