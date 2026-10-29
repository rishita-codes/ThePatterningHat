// Patterns used: Prefix Sum (29), Modified Binary Search (16)

// Alex is shopping at Ozone Galleria Mall. There is a dedicated cubicle for a type of product at
// the shopping center. All the products sold at the ith cubicle are priced the same, denoted by
// prices[i]. The cubicles are arranged such that the price of the products sold at each cubicle are
// in non-decreasing order. Several queries would be asked about the problem. In each query, the
// cubicle number Alex is initially standing at, and the amount of money Alex has is given, and Alex
// can travel in the right direction visiting from the current cubicle to the last cubicle. Alex may buy
// at most one item from any cubicle visited, but the total cost of the purchase must not exceed
// the amount Alex has. Report the maximum number of products that can be purchased for each
// query. More formally, given an array of n integers, prices, where prices[i] denotes the price of the
// product sold in the ith cubicle. The array prices are in non-decreasing order (i.e., the
// price[i]≤price[i+1]), and q queries need to be processed. For each query, two integers are given:
// pos: Alex’s initial position
// amount: the amount of money Alex has
// Alex needs to visit each cubicle from number pos to n, purchasing at most one product from
// each cubicle. For each query, the goal is to find the maximum number of products that Alex can
// buy

#include<bits/stdc++.h>

using namespace std;

vector<long long> optimalPurchase(vector<long long>& price, vector<pair<long long, long long>>& query){
    long long n= price.size();
    vector<long long> result;
    
    vector<long long> prefixSum(n);
    prefixSum[0]= price[0];
    for(long long i=1; i<n; i++){
        prefixSum[i] = prefixSum[i-1] + price[i];
    }
    
    for(auto q : query){
        long long start= q.first;
        long long amount= q.second;
        
        long long low=start, high=n-1, ans=start-1;
        while(low <= high){
            long long mid= low + (high-low)/2;
            long long cost= prefixSum[mid] - (start>0 ? prefixSum[start-1] : 0);
            if(cost <= amount){
                ans= mid;
                low= mid+1;
            }
            else{
                high= mid-1;
            }
        }
        result.push_back(ans-start+1);
    }
    return result;
}

int main(){

    long long n, k;
    cin >> n;
    vector<long  long> price(n);
    for(long long i=0; i<n; i++){
        cin >> price[i];
    }
    cin >> k;
    vector<pair<long long, long long>> query(k);
    for(long long i=0; i<k; i++){
        cin >> query[i].first >> query[i].second;
    }

    vector<long  long> result= optimalPurchase(price, query);
    
    for(auto r : result){
        cout << r << " ";
    }

    return 0;
}

/*
testcase:
5
10 20 30 40 50
4
0 60
1 100
3 10
2 90
*/