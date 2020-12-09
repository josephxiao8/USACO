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


int A,B,n,m;
vi parent;
vi size;

//DSU
void init() {
    for(int i=0; i<(n+1)*(m+1); i++) {
        parent[i]=i;
        size[i]=1;
    }
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
    
	parent[b]=a;
	size[a]+=size[b];
}


int main() {
ios::sync_with_stdio(0);
cin.tie(0);
	
	ofstream cout ("fencedin.out");
	ifstream cin ("fencedin.in");
	
	cin>>A>>B>>n>>m;
	
	parent=vi((n+1)*(m+1));
	size=vi((n+1)*(m+1));
	init();
	
	vi a(n+2);
	a[0]=0; a[n+1]=A;
	for(int i=1; i<=n; i++) cin>>a[i];
	sort(a.begin(), a.end());
	
	vi b(m+2);
	b[0]=0; b[m+1]=B;
	for(int i=1; i<=m; i++) cin>>b[i];
	sort(b.begin(), b.end());
	
	vti v;
	for(int i=0; i<n+1; i++) v.pb(mt(a[i+1]-a[i], i, 0));
	for(int j=0; j<m+1; j++) v.pb(mt(b[j+1]-b[j], j, 1));
	sort(v.begin(), v.end());
	
	vti edges;
	for(auto x:v){
		int dis,start,dir;
		tie(dis,start,dir)=x;
		if(dir==0){
			for(int j=0; j<m; j++) edges.pb(mt(dis, j*(n+1)+start, (j+1)*(n+1)+start));
		}
		else{
			for(int i=0; i<n; i++) edges.pb(mt(dis, start*(n+1)+i, start*(n+1)+i+1));
		}
	}
	
	ll ans=0;
	for(auto x:edges){
		int a,b,c;
		tie(a,b,c)=x;
		if(find(b)!=find(c)){
			unite(b,c);
			ans+=a;
		}
	}
	
	cout<<ans<<"\n";
	return 0;
}
