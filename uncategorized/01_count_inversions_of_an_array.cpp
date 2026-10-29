#include<bits/stdc++.h>

using namespace std;

int countInversions(vector<int>& arr, int start, int end, vector<int>& temp){
    if(start==end)
        return 0;
    int mid= start+(end-start)/2;

    int inv = countInversions(arr, start, mid, temp) + countInversions(arr, mid+1, end, temp);

    int i=start, j=mid+1, k=start;
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j])
            temp[k++]=arr[i++];
        else{
            temp[k++]=arr[j++];
            inv += mid-i+1;
        }
    }
    while(i<=mid)
        temp[k++]=arr[i++];
    while(j<=end)
        temp[k++]=arr[j++];
    for(int i=start; i<=end; i++){
        arr[i]= temp[i];
    }
    return inv;
}

int main(){

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    vector<int> temp(n);
    cout << countInversions(arr, 0, n-1, temp) << endl;

    return 0;
}

/*
8
3 5 1 10 9 2 6 8
*/