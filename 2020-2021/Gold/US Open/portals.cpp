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


int n;
vi parent;
vi siz;

void init(){
	parent=vi(2*n);
	siz=vi(2*n);
	for(int i=0; i<2*n; i++){
		parent[i]=i;
		siz[i]=1;
	}
}

int find(int node){
	if(parent[node]!=node){
		parent[node]=find(parent[node]);
	}
	return parent[node];
}

void unite(int a, int b){
	a=find(a);
	b=find(b);
	if(a==b) return;
	
	if(siz[a]<siz[b]) swap(a,b);
	parent[b]=a;
	siz[a]+=siz[b];
}


int main() {
ios::sync_with_stdio(0);
cin.tie(0);
	
	cin>>n;
	init();
	vpi c(n);
	vector<vi> adj(n, vi(4));
	for(int i=0; i<n; i++){
		cin>>c[i].f;
		c[i].s=i;
		for(int j=0; j<4; j++) {
			cin>>adj[i][j];
			adj[i][j]--;
		}
	}
	
	for(int i=0; i<n; i++){
		unite(adj[i][0],adj[i][1]);
		unite(adj[i][2],adj[i][3]);
	}
	
	sort(c.begin(), c.end());
	
	int ans=0;
	for(int i=0; i<n; i++){
		if(find(adj[c[i].s][0])!=find(adj[c[i].s][2])){
			unite(adj[c[i].s][0], adj[c[i].s][2]);
			ans+=c[i].f;
		}
	}
	
	cout<<ans<<"\n";
	return 0;	
}
