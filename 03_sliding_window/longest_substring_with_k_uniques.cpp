#include<bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n=s.size(), sub=0, max_sub=0, distinct=0;
        vector<int> freq(26, 0);
        for(int i=0, j=0; j<n; j++){
            char ch= s[j];
            if(freq[ch-'a']==0){
                distinct++;
            }
            freq[ch-'a']++;
            if(distinct>k){
                char p= s[i];
                while(freq[p-'a']>0){
                    freq[s[i]-'a']--;
                    if(freq[s[i]-'a']==0){
                        i++;
                        distinct--;
                        break;
                    }
                    i++;
                }
            }
            if(distinct==k){
                sub= j-i+1;
                max_sub= max(max_sub, sub);
            }
        }
        if(max_sub==0)
            return -1;
        return max_sub;
    }
};

int main(){
    int k;
    string s;
    cin >> s >> k;
    Solution sol;
    cout << sol.longestKSubstr(s, k) << endl;

    return 0;
}