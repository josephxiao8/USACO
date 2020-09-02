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
 
typedef priority_queue<pair<int,string>> pq;
typedef priority_queue<int,vector<int>,greater<int>> pqg;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound


vector<vi> adj;
vi color;
vi previous;
int cycle_start;
int cycle_end;

void dfs(int start){
	color[start]=1;
	for(auto u:adj[start]){
		if(color[u]==0){
			previous[u]=start;
			dfs(u);
		}
		else if(color[u]==1){
			cycle_end=start;
			cycle_start=u;
		}
	}
	color[start]=2;
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

ofstream cout ("shuffle.out");
ifstream cin ("shuffle.in");

int n;
cin>>n;
adj=vector<vi>(n);
color=vi(n,0);
previous=vi(n,-1);

for(int i=0; i<n; i++){
	int j;
	cin>>j;
	j--;
	adj[i].pb(j);
}

int ans=0;
for(int i=0; i<n; i++){
	cycle_start=-1;
	cycle_end=-1;
	if(color[i]==0){
		dfs(i);
		if(cycle_end!=-1){
			for(int j=cycle_end; j!=cycle_start; j=previous[j]){
				ans++;
			}
			ans++;
		}
	}
}

cout<<ans<<"\n";
return 0;
}
