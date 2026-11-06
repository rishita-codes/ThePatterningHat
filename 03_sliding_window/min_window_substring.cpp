#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int n1=s.size(), n2=t.size(), match=0, min_win=INT_MAX, start=-1;
        vector<int> freq1(126, 0);
        vector<int> freq2(126, 0);
        for(int i=0; i<n2; i++){
            freq1[t[i]]++;
        }
        for(int i=0, j=0; j<n1; j++){
            char ch= s[j];
            freq2[ch]++;
            if(freq1[ch]>0 && freq2[ch]<=freq1[ch]){
                match++;
            }
            while(match==n2){
                int win= j-i+1;
                if(win < min_win){
                    min_win= win;
                    start= i;
                }
                char left_ch= s[i];
                freq2[left_ch]--;
                if(freq1[left_ch]>0 && freq2[left_ch]<freq1[left_ch]){
                    match--;
                }
                i++;
            }

        }
        if(start==-1)
            return "";
        return s.substr(start, min_win);
    }
};


int main(){
    string s, t;
    cin >> s >> t;
    Solution sol;
    cout << sol.minWindow(s, t) << endl;

    return 0;
}