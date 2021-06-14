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


int main() {
ios::sync_with_stdio(0);
cin.tie(0);

	ofstream cout ("threesum.out");
	ifstream cin ("threesum.in");
	
	ll n,q;
	cin>>n>>q;
	vi v(n);
	for(ll i=0; i<n; i++) cin>>v[i];
	vector<vl> ans(n, vl(n,0));
	
	for(ll i=0; i+2<n; i++){
		gp_hash_table<int,int> mapp({},{},{},{},{1<<13}); 
		mapp[v[i+1]]++;
		for(ll j=i+2; j<n; j++){
			int lookFor=-(v[i]+v[j]);
			auto it=mapp.find(lookFor);
			if(it!=end(mapp)) ans[i][j]=(*it).s;
			mapp[v[j]]++;
		}
	}
	
	for(int r=0; r<n; r++){
		for(int l=r-2; l>=0; l--) ans[l][r]+=ans[l+1][r]+ans[l][r-1]-ans[l+1][r-1];
	}
	
	while(q--){
		ll a,b;
		cin>>a>>b;
		cout<<ans[a-1][b-1]<<"\n";
	}
	return 0;	
}
