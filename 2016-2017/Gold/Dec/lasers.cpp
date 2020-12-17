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


bool comp (pi a, pi b){
	if(a.s==b.s) return a.f<b.f;
	else return a.s<b.s;
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);
	
	ofstream cout ("lasers.out");
	ifstream cin ("lasers.in");
	
	int n, xl, yl, xb, yb;
	cin>>n>>xl>>yl>>xb>>yb;
	
	vpi v;
	v.pb(mp(xl, yl));
	v.pb(mp(xb, yb));
	for(int i=0; i<n; i++){
		int a,b;
		cin>>a>>b;
		v.pb(mp(a, b));
	}
	
	map<pi,int> mapp;
	int count=0;
	sort(v.begin(), v.end());
	for(auto x:v) mapp[x]=count++;
	
	vector<vi> adj(n+2);
	for(int i=0; i<n+2; i++){
		int jump=i;
		for(int j=i; j<n+2 && v[j].f==v[i].f && j<n+1 && v[j].f==v[j+1].f; j++){
			adj[mapp[v[j]]].pb(mapp[v[j+1]]);
			adj[mapp[v[j+1]]].pb(mapp[v[j]]);
			jump=j;
		}
		i=jump;
	}
	
	sort(v.begin(), v.end(), comp);
	for(int i=0; i<n+2; i++){
		int jump=i;
		for(int j=i; j<n+2 && v[j].s==v[i].s && j<n+1 && v[j].s==v[j+1].s; j++){
			adj[mapp[v[j]]].pb(mapp[v[j+1]]);
			adj[mapp[v[j+1]]].pb(mapp[v[j]]);
			jump=j;
		}
		i=jump;
	}
	
	sort(v.begin(), v.end());
	vector<vector<bool> > visited(n+2, vector<bool>(4,false)); //up, right, down, left
	pqg q;
	for(auto u:adj[mapp[mp(xl,yl)]]) q.push(mt(1,u,mapp[mp(xl,yl)]));
	
	while(!q.empty()){
		int a,b,c;
		tie(c,a,b)=q.top(); q.pop();
		
		if(a==mapp[mp(xb,yb)]){
			cout<<c-1<<"\n";
			return 0;
		}
		
		if(a==mapp[mp(xl,yl)]){
			for(auto u:adj[a]){
				int dx=v[u].f-v[a].f;
				int dy=v[u].s-v[a].s;
				int dirx=v[a].f-v[b].f;
				int diry=v[a].s-v[b].s;
				if(dirx==0 ){ 
					if(dx!=0) continue;
					if(diry>0 && dy>0)  q.push(mt(u,b,c));
					else if(diry<0 && dy<0) q.push(mt(u,b,c));
				}
				else{ 
					if(dy!=0) continue;
					if(dirx>0 && dx>0) q.push(mt(u,b,c));
					else if(dirx<0 && dx<0) q.push(mt(u,b,c));
				}
			}
			
			continue;
		}
		
		int dirx=v[a].f-v[b].f;
		int diry=v[a].s-v[b].s;
		for(auto u:adj[a]){
			int dx=v[u].f-v[a].f;
			int dy=v[u].s-v[a].s;
			if(dirx==0){
				if(dx==0) {
					if(diry>0 && dy>0) q.push(mt(c,u,a));
					else if(diry<0 && dy<0) q.push(mt(c,u,a));
				}
				else {
					if(dx>0 && !visited[a][1]) {
						q.push(mt(c+1,u,a));
						visited[a][1]=true; 
					}
					else if(dx<0 && !visited[a][3]){
						q.push(mt(c+1,u,a));
						visited[a][3]=true; 
					}
				}
			}
			else{ 
				if(dx==0) {
					if(dy>0 && !visited[a][0]){
						q.push(mt(c+1,u,a));
						visited[a][0]=true;
					}
					else if(dy<0 && !visited[a][2]){
						q.push(mt(c+1,u,a));
						visited[a][2]=true;
					}
				}
				else {
					if(dirx>0 && dx>0) q.push(mt(c,u,a));
					else if(dirx<0 && dx<0) q.push(mt(c,u,a));
				}
			}
		}
	}
	
	cout<<-1<<"\n";
	return 0;
}
