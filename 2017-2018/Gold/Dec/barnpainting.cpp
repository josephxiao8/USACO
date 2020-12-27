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


const ll mod=1e9+7;
vector<vi> adj;
vector<bool> visited;
vector<bool> visited2;
vi color;
vector<vl> dp;

void dfs(int start){
	bool child=true;
	for(auto u:adj[start]){
		if(!visited[u]){
			child=false;
			visited[u]=true;
			dfs(u);
		}
	}
	
	if(child){
		if(color[start]!=-1) {
			for(int i=0; i<3; i++) if(i!=color[start]) dp[start][i]=0;
		}
	}
	else{
		if(color[start]==-1){
			for(auto u:adj[start]){
				if(visited2[u]){
					for(int i=0; i<3; i++){
						ll temp=0;
						for(int j=0; j<3; j++){
							if(i==j) continue;
							temp=(temp+dp[u][j])%mod;
						}
						dp[start][i]=(dp[start][i]*temp)%mod;
					}
				}
			}
		}
		else{
			for(auto u:adj[start]){
				if(visited2[u]){
					ll temp=0;
					for(int j=0; j<3; j++){
						if(color[start]==j) continue;
						temp=(temp+dp[u][j])%mod;
					}
					dp[start][color[start]]=(dp[start][color[start]]*temp)%mod;
				}
			}
			for(int i=0; i<3; i++) if(i!=color[start]) dp[start][i]=0;
		}
	}
	
	visited2[start]=true;
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);
	
	ofstream cout ("barnpainting.out");
	ifstream cin ("barnpainting.in");
	
	int n,k;
	cin>>n>>k;
	adj=vector<vi>(n);
	for(int i=0; i<n-1; i++){
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	color=vi(n,-1);
	for(int i=0; i<k; i++){
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		color[a]=b;
	}
	
	visited=vector<bool>(n,false);
	visited2=vector<bool>(n,false);
	visited[0]=true;
	dp=vector<vl>(n, vl(3,1));
	dfs(0);
	
	int ans=0;
	for(int i=0; i<3; i++) ans=(ans+dp[0][i])%mod;
	cout<<ans<<"\n";
	return 0;
}
