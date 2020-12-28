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
	
	ofstream cout ("hayfeast.out");
	ifstream cin ("hayfeast.in");
	
	ll n;
	ll m;
	cin>>n>>m;
	vpl v(n);
	for(ll i=0; i<n; i++) cin>>v[i].f>>v[i].s;
	
	multiset<ll> sett;
	ll l=0;
	ll r=0;
	ll sum=0;
	ll ans=1e9;
	while(r!=n){
		sum+=v[r].f;
		sett.insert(v[r].s);
		if(sum>=m) ans=min(ans,*(--sett.end()));
		while(sum>=m){
			sum-=v[l].f;
			sett.erase(sett.find(v[l].s));
			l++;
		}
		r++;
	}
	
	cout<<ans<<"\n";
	return 0;
}
