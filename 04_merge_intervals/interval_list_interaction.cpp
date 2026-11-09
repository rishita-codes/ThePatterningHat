#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n1=firstList.size(), n2=secondList.size();
        vector<vector<int>> result;
        vector<int> interval(2);
        int i=0, j=0;
        while(i<n1 && j<n2){
            vector<int> a= firstList[i];
            vector<int> b= secondList[j];
            if(b[1]<a[0]){
                j++;
                continue;
            }
            if(a[1]<b[0]){
                i++;
                continue;
            }
            interval[0]= max(a[0], b[0]);
            if(a[1]<b[1]){
                interval[1]= a[1];
                i++;
            }
            else{
                interval[1]= b[1];
                j++;
            }
            result.push_back(interval);
        }
        return result;
    }
};

int main(){
    int n1, n2;
    cin >> n1;
    vector<vector<int>> firstList(n1, vector<int>(2));
    for(int i=0; i<n1; i++){
        cin >> firstList[i][0] >> firstList[i][1];
    }
    cin >> n2;
    vector<vector<int>> secondList(n2, vector<int>(2));
    for(int i=0; i<n2; i++){
        cin >> secondList[i][0] >> secondList[i][1];
    }
    Solution sol;
    vector<vector<int>> result= sol.intervalIntersection(firstList, secondList);
    cout << "result:\n" ;
    for(auto k : result){
        cout << k[0] << " " << k[1] << endl;
    }
    return 0;
}