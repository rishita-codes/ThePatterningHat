// Maximum Score: An interviewer at HackerRank recently came up with an interesting
// problem for the candidates. Given an array arr of n integers, start with a score of 0. In one
// operation, one element of the array is chosen, and its value is added to the score. The element
// is replaced by the integer ceiling of one-third of its value. For example, if the element is 10, then
// 10 is added to the score and the element is replaced by ceil(10/3)=4. The task is to find the
// maximum possible score after k operations.

#include<bits/stdc++.h>

using namespace std;

long long maxScore(vector<long long>& arr, long k){
    priority_queue<long long> maxHeap;
    for(auto i : arr)
        maxHeap.push(i);
    long long sum=0;
    while(k){
        long long top= maxHeap.top();
        maxHeap.pop();
        sum += top;
        long long newVal= (top+2)/3;
        maxHeap.push(newVal);
        k--;
    }
    return sum;
}


int main(){
    
    long long n, k;
    cin >> n;
    vector<long long> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    cin >> k;

    cout << maxScore(arr, k);

    return 0;
}

/*
testcase:
5
10 20 30 40 50
3
*/