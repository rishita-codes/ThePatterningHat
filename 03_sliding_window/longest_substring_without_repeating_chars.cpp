#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size(), sub=0, max_sub=0;
        vector<int> freq(256, 0);
        for(int i=0, j=0; j<n; j++){
            char ch= s[j];
            freq[ch]++;
            if(freq[ch]>1){
                while(freq[ch]>1){
                    freq[s[i]]--;
                    i++;
                }
            }
            sub= j-i+1;
            max_sub= max(max_sub, sub);
        }
        return max_sub;
    }
};

int main(){
    string s;
    cin >> s;
    Solution sol;
    cout << sol.lengthOfLongestSubstring(s) << endl;

    return 0;
}