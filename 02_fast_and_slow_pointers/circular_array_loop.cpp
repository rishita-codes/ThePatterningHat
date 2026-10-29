#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getNext(vector<int>& nums, int i){
        int n= nums.size();
        int next= (i+nums[i])%n;
        if(next<0)
            next= n+next;
        return next;
    }
    bool circularArrayLoop(vector<int>& nums) {
        int slow=0, fast=0, n=nums.size();
        if(n==1)
            return false;
        for(int i=0; i<n; i++){
            if(nums[i]==0)  
                continue;
            int slow= i, fast= i;
            bool isForward= nums[i]>0;

            while(true){
                int next_slow= getNext(nums, slow);
                if( nums[next_slow]==0 || (nums[next_slow]>0)!=isForward )
                    break;
                
                int next_fast1= getNext(nums, fast);
                if( nums[next_fast1]==0 || (nums[next_fast1]>0)!=isForward)
                    break;

                int next_fast2= getNext(nums, next_fast1);
                if( nums[next_fast2]==0 || (nums[next_fast2]>0)!=isForward)
                    break;

                slow= next_slow;
                fast= next_fast2;

                if(slow==fast){
                    if(slow == getNext(nums, slow))
                        break;
                    return true;
                }
            }
            int cur=i;
            bool curForward= nums[i]>0;
            while( nums[cur]!=0 && (nums[cur]>0) == curForward ){
                int next_cur= getNext(nums, cur);
                nums[cur]=0;
                cur= next_cur;
            }
        }
        return false;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++)
        cin>> nums[i];
    Solution sol;
    if(sol.circularArrayLoop(nums))
        cout << "true\n";
    else
        cout << "false\n";
}