# Spainting

```cpp
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std; 
using namespace __gnu_pbds;
 
typedef long long ll;
 
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef tuple<int,int,int> ti;
typedef tuple<ll,ll,ll> tl;
 
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<ti> vti;
typedef vector<tl> vtl;
 
typedef priority_queue<int> pq;
typedef priority_queue<int,vector<int>,greater<int>> pqg;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
 
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound


const ll mod=1e9+7;

int main() {
ios::sync_with_stdio(0);
cin.tie(0);
	
	ofstream cout ("spainting.out");
	ifstream cin ("spainting.in");
	
	ll n,m,k;
	cin>>n>>m>>k;
	
	vector<vl> dp(n+1, vl(2,0));
	vector<vl> presum(n+1, vl(2,0));
	
	for(ll i=1; i<=n; i++){
		if(i<k) dp[i][0]=m;
		else dp[i][1]=m;
	}
	
	for(ll i=1; i<=n; i++){
		(dp[i][0]+=(m-1)*(presum[i-1][0]-presum[max(0LL,i-k)][0]))%=mod;
		(dp[i][1]+=(m-1)*(presum[i-1][1]-presum[max(0LL,i-k)][1]))%=mod;
		if(i>=k) (dp[i][1]+=(m-1)*(presum[i-k][0]+presum[i-k][1]))%=mod;
			
		(presum[i][0]+=((presum[i-1][0]+dp[i][0])%mod))%=mod;
		(presum[i][1]+=((presum[i-1][1]+dp[i][1])%mod))%=mod;
	}
	
	cout<<(dp[n][1]+mod)%mod<<"\n";
	return 0;
}

```
