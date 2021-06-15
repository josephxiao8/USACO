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

	ofstream cout ("timeline.out");
	ifstream cin ("timeline.in");
	
	int n,m,c;
	cin>>n>>m>>c;
	vi s(n);
	for(int i=0; i<n; i++) cin>>s[i];
	
	vector<vpi> adj(n);
	vi deg(n,0);
	while(c--){
		int a,b,d;
		cin>>a>>b>>d;
		a--; b--;
		adj[a].pb(mp(b,d));
		deg[b]++;
	}
	
	queue<int> q;
	for(int i=0; i<n; i++){
		if(deg[i]==0) q.push(i);
	}
	
	while(!q.empty()){
		int start=q.front(); q.pop();
		for(auto u:adj[start]){
			int b,d;
			tie(b,d)=u;
			s[b]=max(s[b],s[start]+d);
			deg[b]--;
			if(deg[b]==0) q.push(b);
		}
	}
	
	for(auto x:s) cout<<x<<"\n";
	return 0;	
}
