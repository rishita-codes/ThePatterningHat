#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size(), n2=s2.size();
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        for(int i=0; i<n1; i++){
            freq1[s1[i]-'a']++;
        }
        for(int i=0, j=0; j<n2; j++){
            char ch=s2[j];
            freq2[ch-'a']++;
            while(freq2[ch-'a']>freq1[ch-'a']){
                freq2[s2[i]-'a']--;
                i++;
            }
            if(freq1==freq2){
                return true;
            }
        }
        return false;
    }
};

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    Solution sol;
    if(sol.checkInclusion(s1, s2))
        cout << "true";
    else
        cout << "false";

    return 0;
}