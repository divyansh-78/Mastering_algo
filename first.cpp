#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;
int main() {
    int n;
    int x;
    cin>>n>>x;
    vector<int>coins(n);
    for (int k=0;k<n;k++) {
        cin >>coins[k];
    }
    sort(coins.begin(), coins.end());
    vector<int>memo(x+1, 0);
    memo[0]= 1; 
    int i= 0;
    int j= 0;
    for (i=1;i<=x;i++) {
        for (j=0;j<coins.size();j++) {
            if (i-coins[j] >= 0) {
                memo[i] = (memo[i]+memo[i-coins[j]]) % 1000000007;
            }
        }
    }
    cout<<memo[x]<<endl;
    return 0;
}
