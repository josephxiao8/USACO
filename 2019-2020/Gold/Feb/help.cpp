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

bool comp(pl a, pl b){
	return a.s<b.s;
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

	ofstream cout ("help.out");
	ifstream cin ("help.in");
	
	ll n;
	cin>>n;
	vpl v;
	vi pre(2*n+2,0);
	for(ll i=0; i<n; i++){
		ll l,r;
		cin>>l>>r;
		v.pb(mp(l,r));
		pre[l]++;
		pre[r]--;
	}
	sort(v.begin(), v.end(), comp);
	for(ll i=1; i<2*n+2; i++) pre[i]+=pre[i-1];
	
	vl pow(n+1);
	pow[0]=1;
	for(ll i=1; i<=n; i++) pow[i]=(pow[i-1]*2)%mod;
	
	ll ans=0;
	for(ll i=0; i<n; i++){
		ans+=pow[n-1-(pre[v[i].s])];
		ans%=mod;
	}
	
	cout<<ans<<"\n";
	return 0;	
}
