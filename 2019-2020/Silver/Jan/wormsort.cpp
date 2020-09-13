#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long ul;
 
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
 
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
 
typedef priority_queue<int> pq;
typedef priority_queue<int,vector<int>,greater<int>> pqg;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound


int n,m;
vi pos;
set<int> sett;
vector<tuple<int,int,int> > edj;
vector<vi> adj;
vi cc;
vector<bool> visited;
int counter;

bool comp(tuple<int,int,int> a, tuple<int,int,int> b){
	return get<2>(a)>get<2>(b);
}

void dfs(int start){
	for(auto u:adj[start]){
		if(!visited[u]){
			visited[u]=true;
			cc[u]=counter;
			dfs(u);
		}
	}
	return;
}

bool possible(int k){
	auto it=sett.begin();
	advance(it, k);
	adj.clear();
	adj=vector<vi>(n);
	for(auto x:edj){
		int a,b,c;
		tie(a,b,c)=x;
		if(c<*it) break;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	cc.clear();
	cc=vi(n);
	counter=0;
	visited.clear();
	visited=vector<bool>(n,false);
	for(int i=0; i<n; i++){
		if(!visited[i]){
			visited[i]=true;
			cc[i]=counter;
			dfs(i);
			counter++;
		}
	}
	
	for(int i=0; i<n; i++){
		if(cc[i]!=cc[pos[i]]) return false;
	}
	return true;
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

ofstream cout ("wormsort.out");
ifstream cin ("wormsort.in");

bool sorted=true;
cin>>n>>m;
pos=vi(n);
for(int i=0; i<n; i++) {
	cin>>pos[i];
	pos[i]--;
	if(i>0 && pos[i]<pos[i-1]) sorted=false;
}

if(sorted){
	cout<<-1<<"\n";
	return 0;
}

for(int i=0; i<m; i++){	
	int a,b,c;
	cin>>a>>b>>c;
	a--;
	b--;
	edj.pb(make_tuple(a,b,c));
	sett.insert(c);
}
sort(edj.begin(), edj.end(), comp);

int k=0;
for(int b=sett.size()/2; b>=1; b/=2){
	while(k+b<sett.size() && possible(k+b)) k+=b;
}

auto jt=sett.begin();
advance(jt,k);
cout<<*jt<<"\n";
return 0;
}
