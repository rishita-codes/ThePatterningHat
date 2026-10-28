#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getNext(int n){
        int sum=0;
        while(n){
            int d= n%10;
            n= n/10;
            sum += d*d;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow=n, fast=n;
        while(fast!=1){
            slow= getNext(slow);
            fast= getNext(getNext(fast));
            if(slow==fast && slow!=1)
                return false;
        }
        return true;
    }
};

int main(){
    int n;
    cin >> n;
    Solution sol;
    if(sol.isHappy(n))
        cout << "true\n";
    else
        cout << "false\n";
}