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


int temp;
vector<bool> vis;
vector<vi> adj;
map<int,int> size;
map<int,int> color;
vector<set<int> > sett;

void dfs(int start, int color1, int color2){
	for(auto u:adj[start]){
		if(!vis[u] && (color[u]==color1 || color[u]==color2)){
			if(sett[start].count(u) || sett[u].count(start)) continue;
			vis[u]=true;
			temp+=size[u];
			sett[start].insert(u);
			dfs(u, color1, color2);
		}
	}
	return;
}


int main() {
ios::sync_with_stdio(0);
cin.tie(0);

ofstream cout ("multimoo.out");
ifstream cin ("multimoo.in");

int n;
cin>>n;
vector<vi> grid(n, vi(n));
for(int j=0; j<n; j++){
	for(int i=0; i<n; i++){
		cin>>grid[j][i];
	}
}

int ans1=0;
vector<vi> region(n, vi(n));
int id=0;
vi dy={1,-1,0,0};
vi dx={0,0,1,-1};
vector<vector<bool> > visited(n, vector<bool>(n,false));
for(int j=0; j<n; j++){
	for(int i=0; i<n; i++){
		if(!visited[j][i]){
			visited[j][i]=true;
			region[j][i]=id;
			queue<pi> q;
			q.push(mp(j,i));
			int counter=1;
			while(!q.empty()){
				int a,b;
				tie(b,a)=q.front(); q.pop();
				for(int k=0; k<4; k++){
					int c=a+dx[k];
					int d=b+dy[k];
					if(c<0 || c>=n || d<0 || d>=n) continue;
					if(grid[d][c]==grid[b][a] && !visited[d][c]){
						visited[d][c]=true;
						region[d][c]=id;
						counter++;
						q.push(mp(d,c));
					}
				}
			}
			ans1=max(ans1, counter);
			size[id]=counter;
			color[id]=grid[j][i];
			id++;
		}
	}
}

adj=vector<vi>(id);
visited.clear();
visited=vector<vector<bool> >(n, vector<bool>(n,false));
for(int j=0; j<n; j++){
	for(int i=0; i<n; i++){
		if(!visited[j][i]){
			visited[j][i]=true;
			queue<pi> q;
			q.push(mp(j,i));
			while(!q.empty()){
				int a,b;
				tie(b,a)=q.front(); q.pop();
				for(int k=0; k<4; k++){
					int c=a+dx[k];
					int d=b+dy[k];
					if(c<0 || c>=n || d<0 || d>=n) continue;
					if(region[d][c]==region[b][a] && !visited[d][c]){
						visited[d][c]=true;
						q.push(mp(d,c));
					}
					else if(region[d][c]!=region[b][a]){
						adj[region[b][a]].pb(region[d][c]);
					}
				}
			}
		}
	}
}

int ans2=0;
sett=vector<set<int> >(id);
for(int i=0; i<id; i++){
	for(auto u:adj[i]){
		if(sett[i].count(u) || sett[u].count(i)) continue;
		vis.clear();
		vis=vector<bool>(id, false);
		vis[i]=true;
		temp=size[i];
		dfs(i,color[i], color[u]);
		ans2=max(ans2, temp);
	}
}

cout<<ans1<<"\n"<<ans2<<"\n";
return 0;
}
