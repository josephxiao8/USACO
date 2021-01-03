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


int n;
vi parent;
vi size;

//DSU
void init() {
    for(int i=0; i<n; i++) {
        parent[i]=i;
        size[i]=1;
    }
}
 
int find(int node) {
    if(parent[node]!=node) {
      parent[node]=find(parent[node]);
    }
    return parent[node];
}
 
void unite(int a, int b) {
    a=find(a);
    b=find(b);
    if(size[a]<size[b]) swap(a,b);
    
    parent[b]=a;
    size[a]+=size[b];
}


int main() {
ios::sync_with_stdio(0);
cin.tie(0);
	
	ofstream cout ("mootube.out");
	ifstream cin ("mootube.in");
	
	int q;
	cin>>n>>q;
	
	parent=vi(n);
	size=vi(n);
	init();
	
	vti edges;
	for(int i=0; i<n-1; i++){
		int a,b,c;
		cin>>a>>b>>c;
		a--;
		b--;
		edges.pb(mt(c,a,b));
	}
	sort(edges.rbegin(), edges.rend());
	
	vti v;
	for(int i=0; i<q; i++){
		int a,b;
		cin>>a>>b;
		b--;
		v.pb(mt(a,b,i));
	}
	sort(v.rbegin(), v.rend());
	
	vi ans(q);
	int j=0;
	for(int i=0; i<q; i++){
		for(; j<n-1 && get<0>(edges[j])>=get<0>(v[i]); j++){
			int a,b,c;
			tie(c,a,b)=edges[j];
			unite(a,b);
		}
		ans[get<2>(v[i])]=size[find(get<1>(v[i]))]-1;
	}
	
	for(auto x:ans) cout<<x<<"\n";
	return 0;
}
