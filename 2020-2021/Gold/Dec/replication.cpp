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
 
typedef priority_queue<ti> pq;
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
	
	int n,d;
	cin>>n>>d;
	vector<vector<char>> grid(n, vector<char>(n));
	vector<vector<bool>> vis(n, vector<bool>(n, false));
	vector<vi> time(n, vi(n,-1));
	pq q;
	queue<pi> q1;
	queue<pi> q2;
	for(int j=0; j<n; j++){
		for(int i=0; i<n; i++){
			cin>>grid[j][i];
			if(grid[j][i]=='#') q1.push(mp(j,i));
			else if(grid[j][i]=='S') {
				q2.push(mp(j,i));
				vis[j][i]=true;
				time[j][i]=0;
				q.push(mt(0,j,i));
			}
		}
	}
	
	vi dy={1,-1,0,0};
	vi dx={0,0,1,-1};	
	
	vector<vi> dis(n, vi(n,0));
	while(!q1.empty()){
		int y,x;
		tie(y,x)=q1.front(); q1.pop();
		for(int i=0; i<4; i++){
			int y2=y+dy[i];
			int x2=x+dx[i];
			if(y2<0 || y2>=n || x2<0 || x2>=n || dis[y2][x2]!=0 || grid[y2][x2]=='#') continue;
			dis[y2][x2]=1+dis[y][x];
			q1.push(mp(y2,x2));
		}
	}
	 
	vector<vector<bool>> subtract(n, vector<bool>(n, false));
	while(!q2.empty()){
		int y,x;
		tie(y,x)=q2.front(); q2.pop();
		for(int i=0; i<4; i++){
			int y2=y+dy[i];
			int x2=x+dx[i];
			if(y2<0 || y2>=n || x2<0 || x2>=n || vis[y2][x2] || grid[y2][x2]=='#') continue;
			if(time[y][x]/d>=dis[y2][x2]) continue;
			time[y2][x2]=time[y][x]+1;
			vis[y2][x2]=true;
			if((time[y2][x2])%d==0){
				if(time[y2][x2]/d>=dis[y2][x2]) subtract[y2][x2]=true;
				else q2.push(mp(y2,x2));
			}
			else q2.push(mp(y2,x2));
			
			if(subtract[y2][x2]) q.push(mt(time[y2][x2]/d-1, y2, x2));
			else q.push(mt(time[y2][x2]/d,y2,x2));
		}
	}
	
	int ans=0;
	vis=vector<vector<bool>>(n, vector<bool>(n, false));
	while(!q.empty()){
		int distance,y,x;
		tie(distance,y,x)=q.top(); q.pop();
		if(vis[y][x]) continue;
		vis[y][x]=true;
		ans++;
		for(int i=0; i<4; i++){
			int y2=y+dy[i];
			int x2=x+dx[i];
			if(distance==0 || vis[y2][x2]) continue;
			q.push(mt(distance-1,y2,x2));
		}
	}
	
	cout<<ans<<"\n";
	return 0;	
}
