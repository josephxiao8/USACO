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
typedef priority_queue<ti,vector<ti>,greater<ti>> pqg;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
 
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound


vi parent;
vi size;
int counter=0;

//DSU
void init(int i) {
	parent[i]=i;
	size[i]=1;
}
 
int find(int node) {
    if (parent[node]!=node) {
		parent[node]=find(parent[node]);
	}
    return parent[node];
}
 
void unite(int a, int b) {
    a=find(a);
    b=find(b);
    if(size[a]<size[b]) swap(a,b);
    
    if(a!=b) counter--;
    
	parent[b]=a;
	size[a]+=size[b];
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);
	
	ofstream cout ("closing.out");
	ifstream cin ("closing.in");
	
	int n,m;
	cin>>n>>m;
	vpi edges;
	for(int i=0; i<m; i++){
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		edges.pb(mp(a,b));
	}
	
	vi v(n);
	map<int,int> mapp;
	for(int i=0; i<n; i++) {
		cin>>v[n-1-i];
		v[n-1-i]--;
		mapp[v[n-1-i]]=n-1-i;
	}
	
	vector<vi> adj(n);
	for(int i=0; i<m; i++) {
		int a,b;
		tie(a,b)=edges[i];
		if(mapp[a]<mapp[b]) swap(a,b);
		adj[a].pb(b);
	}
	
	parent=vi(n);
	size=vi(n);
	
	vi ans(n);
	for(int i=0; i<n; i++){
		int node=v[i];
		init(node);
		counter++;
		for(auto x:adj[node]) unite(node, x);
		if(counter==1) ans[n-1-i]=1;
		else ans[n-1-i]=0;
	}
	
	for(auto x:ans){
		if(x==1) cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}
