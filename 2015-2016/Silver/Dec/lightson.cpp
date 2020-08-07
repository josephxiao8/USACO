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

ofstream cout ("lightson.out");
ifstream cin ("lightson.in");

int n,m;
cin>>n>>m;

vector<vector<bool> > visited(n, vector<bool>(n,false));
vector<vector<bool> > lit(n, vector<bool>(n,false)); //a room can be lit but not visited yet
vector<vector<vpi>> adj(n, vector<vpi>(n)); //adj stores the rooms whose light can be turned on from room (x,y);
for(int i=0; i<m; i++){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	a--;
	b--;
	c--;
	d--;
	adj[a][b].pb(mp(c,d));
}

queue<pi> q;
q.push(mp(0,0));
visited[0][0]=true;
lit[0][0]=true;

int counter=1;
vpi dir={{1,0}, {0,1}, {-1,0}, {0,-1}};
while(!q.empty()){
	int a,b;
	tie(a,b)=q.front(); q.pop();
	
	for(auto u:adj[a][b]){ //light up every possible room with the swithes in the current room
		int c,d;
		tie(c,d)=u;
		if(visited[c][d]) continue;
		if(!lit[c][d]){
			lit[c][d]=true;
			counter++;
		}
		for(int i=0; i<4; i++){
			int ver=dir[i].f, hor=dir[i].s;
			if(0<=c+hor && c+hor<=n-1 && 0<=d+ver && d+ver<=n-1 && visited[c+hor][d+ver]){ //if there is a path to room (c+hor,d+ver), add room to queue
				visited[c][d]=true;
				q.push(mp(c,d));
				break;
			}
		}
	}
	
	for(int i=0; i<4; i++){ //check the 4 neighbouring rooms, if lit, add room (a+hor,b+ver) to queue
		int ver=dir[i].f, hor=dir[i].s;
		if(0<=a+hor && a+hor<=n-1 && 0<=b+ver && b+ver<=n-1 && lit[a+hor][b+ver]){
				if(visited[a+hor][b+ver]) continue;
				visited[a+hor][b+ver]=true;
				q.push(mp(a+hor,b+ver));
		}
	}
}

cout<<counter<<"\n";
return 0;	
}
