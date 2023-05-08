#include<bits/stdc++.h>
using namespace std;
const int N=60;
const int M=1001;
const int mod=100000007;
int dp[N][M];
int coin[N];
int limit[N];
int fun(int n,int k);
int main()
{
    memset(dp,-1,sizeof(dp));
    int n,k;
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        cin>>coin[i];
    }
    for(int i=1; i<=n; i++)
    {
        cin>>limit[i];
    }
    cout<<fun(n,k);
    return 0;
}
int fun(int n,int k)
{
    if(n==0)
    {
        if(k==0)return 1;
        return 0;
    }
    if(dp[n][k]!=-1)return dp[n][k];
    int ans = fun(n-1,k);
    for(int i=1; i<=limit[n]; i++)
    {
        if(k-i*coin[n]<0)break;
        int ret = fun(n-1,k-i*coin[n]);
        ans =(ans+ret)%mod;
    }
    dp[n][k]=ans;
    return ans;
}
