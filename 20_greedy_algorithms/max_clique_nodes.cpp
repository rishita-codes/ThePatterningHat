// Given the number of nodes and the number of edges connecting these nodes, arrange these
// edges such that maximum number of nodes are strongly connected. Return the number of
// nodes that could be strongly connected. [Hint:- To make first node strongly connected you need
// n-1 edges for second you need n-2 and so on. i.e edges – (n-1) – (n-2) - … - (n-k) >= 0, then largest
// k possible is the answer)

#include<bits/stdc++.h>

using namespace std;

int maxCliqueNodes(int n, int k){
    int c=0, nodes=1;
    for(int i=1; i<=n; i++){
        if(c+i<=k){
            c += i;
            nodes++;
        }
        else{
            break;
        }
    }
    return min(nodes, n);
}

int main(){
    int n, k;
    cin >> n >> k;
    cout << maxCliqueNodes(n, k) << endl;
    return 0;
}