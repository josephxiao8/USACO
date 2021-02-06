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


int main() {
ios::sync_with_stdio(0);
cin.tie(0);

	ofstream cout ("teamwork.out");
	ifstream cin ("teamwork.in");
	
	ll n,k;
	cin>>n>>k;
	vl v(n);
	for(ll i=0; i<n; i++) cin>>v[i];
	
	vl dp(n+1,LONG_LONG_MIN);
	dp[n]=0;
	dp[n-1]=v[n-1];
	for(ll i=n-2; i>=0; i--){
		ll maxx=LONG_LONG_MIN;
		for(ll j=0; j<min(k,n-i); j++){
			maxx=max(maxx,v[i+j]);
			dp[i]=max(dp[i], maxx*(j+1)+dp[i+j+1]);
		}
	}
	
	cout<<dp[0]<<"\n";
	return 0;
}
