#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;
using namespace std; 
 
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

	ofstream cout ("poetry.out");
	ifstream cin ("poetry.in");
	
	ll n,m,k;
	cin>>n>>m>>k;
	vector<vl> v(n);
	vl v2;
	for(ll i=0; i<n; i++){
		ll a,b;
		cin>>a>>b;
		v[b-1].pb(a);
		v2.pb(a);
	}
	
	vl dp(k+1,0); //knapsack dp
	dp[0]=1;
	for(ll i=1; i<=k; i++){
		for(auto x:v2){
			if(i-x>=0) dp[i]=(dp[i]+dp[i-x])%mod;
		}
	}
	
	vector<vl> dp2(n,vl(18,0)); //binary exp
	for(ll i=0; i<n; i++){
		for(auto x:v[i]){
			if(k-x>=0) dp2[i][0]=(dp2[i][0]+dp[k-x])%mod;
		}
		for(ll j=1; j<18; j++){
			dp2[i][j]=(dp2[i][j-1]*dp2[i][j-1])%mod;
		}
	}
	
	vl scheme(26,0);
	for(ll i=0; i<m; i++){
		char c;
		cin>>c;
		scheme[c-'A']++;
	}
	
	ll ans=1;
	for(auto x:scheme){
		if(x!=0){
			ll temp=0;
			for(ll i=0; i<n; i++){
				if(dp2[i][0]==0) continue;
				ll temp2=1;
				for(int mask=0; mask<18; mask++){
					if(x&(1<<mask)) {
						temp2=(temp2*dp2[i][mask])%mod;
					}
				}
				temp=(temp+temp2)%mod;
			}
			ans=(ans*temp)%mod;
		}
	}
	
	cout<<ans<<"\n";
	return 0;
}
