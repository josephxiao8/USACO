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

	ofstream cout ("deleg.out");
	ifstream cin ("deleg.in");
	
	int n;
	cin>>n;
	vi deg(n,0);
	vector<vi> adj(n);
	for(int i=0; i<n-1; i++){
		int a,b;
		cin>>a>>b;
		a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
		deg[a]++; deg[b]++;
	}
	
	int degGreaterThan2=0;
	int star_start=0;
	for(int i=0; i<n; i++){
		if(deg[i]>2) {
			degGreaterThan2++;
			star_start=i;
		}
	}
	
	if(degGreaterThan2<2){
		queue<pi> q;
		q.push(mp(star_start,0));
		vector<bool> vis(n, false);
		vi dis;
		while(!q.empty()){
			int a,b;
			tie(a,b)=q.front(); q.pop();
			vis[a]=true;
			bool bo=false;
			for(auto u:adj[a]){
				if(!vis[u]) {
					q.push(mp(u,b+1));
					bo=true;
				}
			}
			if(!bo) dis.pb(b);
		}
		
		for(int k=1; k<n; k++){
			if((n-1)%k==0){
				vi mapp(k,0);
				for(auto x:dis) mapp[x%k]++;
				bool bo=true;
				for(int i=1; i<k && bo; i++){
					if(2*i==k){
						if(mapp[i]%2==1) bo=false;
					}
					else {
						if(mapp[i]!=mapp[k-i]) bo=false;
					}
				}
				if(bo) cout<<1;
				else cout<<0;
			}
			else cout<<0;
		}
		return 0;
	}
	
	queue<int> q;
	q.push(0);
	vector<bool> vis(n, false);
	vi topo;
	while(!q.empty()){
		int start=q.front(); q.pop();
		vis[start]=true;
		topo.pb(start);
		for(auto u:adj[start]){
			if(!vis[u]) q.push(u);
		}
	}
	
	reverse(topo.begin(), topo.end());
	vi ans(n,0);
	for(int k=1; k<n; k++){
		if((n-1)%k!=0) continue;
		vi dp(n,0);
		vis=vector<bool>(n,false);
		for(int i=0; i<n-1; i++){
			if(ans[k]==-1) break;
			int start=topo[i];
			vis[start]=true;
			multiset<int> sett;
			for(auto u:adj[start]){
				if(vis[u] && dp[u]!=0) {
					if(sett.count(k-dp[u])) sett.erase(sett.find(k-dp[u]));
					else sett.insert(dp[u]);
				}
			}
			if(sett.size()>1) ans[k]=-1;
			else if(sett.size()==1){
				if(1+*(sett.begin())==k) dp[start]=0;
				else dp[start]=1+*(sett.begin());
			}
			else{
				if(1==k) dp[start]=0;
				else dp[start]=1;
			}
		}
		
		if(ans[k]==-1) {
			ans[k]=0;
			continue;
		}
		
		multiset<int> sett;
		for(auto u:adj[0]){
			if(vis[u] && dp[u]!=0) {
				if(sett.count(k-dp[u])) sett.erase(sett.find(k-dp[u]));
				else sett.insert(dp[u]);
			}
		}
		if(sett.size()!=0) ans[k]=0;
		else ans[k]=1;
	}
	
	for(int i=1; i<n; i++) cout<<ans[i];
	cout<<"\n";
	return 0;	
}
