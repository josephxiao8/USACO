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


int main() {
ios::sync_with_stdio(0);
cin.tie(0);

ofstream cout ("fenceplan.out");
ifstream cin ("fenceplan.in");

int n,m;
cin>>n>>m;
vpi pos(n);
for(int i=0; i<n; i++) cin>>pos[i].f>>pos[i].s;

vector<vi> adj(n);
for(int i=0; i<m; i++){
	int a,b;
	cin>>a>>b;
	a--;
	b--;
	adj[a].pb(b);
	adj[b].pb(a);
}

int ans=INT_MAX;
vector<bool> visited(n,false);
for(int i=0; i<n; i++){
	if(!visited[i]){
		int x1=INT_MAX;
		int x2=INT_MIN;
		int y1=INT_MAX;
		int y2=INT_MIN;
		visited[i]=true;
		queue<int> q;
		q.push(i);
		while(!q.empty()){
			int start=q.front(); q.pop();
			int x,y;
			tie(x,y)=pos[start];
			x1=min(x1,x);
			x2=max(x2,x);
			y1=min(y1,y);
			y2=max(y2,y);
			for(auto u:adj[start]){
				if(!visited[u]){
					visited[u]=true;
					q.push(u);
				}
			}
		}
		
		int p;
		if((x2-x1==0) || (y2-y1==0)) p=0;
		else p=2*(x2-x1+y2-y1);
		ans=min(ans,p);
	}
}

cout<<ans<<"\n";
return 0;
}
