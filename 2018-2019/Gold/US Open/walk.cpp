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


const ll mod=2019201997;

int main(){
ios::sync_with_stdio(0);
cin.tie(0);

	ofstream cout ("walk.out");
	ifstream cin ("walk.in");
	
	ll n,k;
	cin>>n>>k;
	
	vector<bool> vis(n,false);
	vl minn(n,INT_MAX);
	for(ll j=0; j<n; j++){
		ll node=-1;
		for(ll i=0; i<n; i++){
			if(vis[i]) continue;
			if(node==-1 || minn[i]<minn[node]) node=i;
		}
		vis[node]=true;
		for(ll i=0; i<n; i++){
			if(vis[i]) continue;
			ll dis=((2019201913*(min(i,node)+1))%mod+(2019201949*(max(i,node)+1))%mod)%mod;
			minn[i]=min(minn[i], dis);
		}
	}
	sort(minn.begin(), minn.end());
	cout<<minn[n-k]<<"\n";
	return 0;
}
