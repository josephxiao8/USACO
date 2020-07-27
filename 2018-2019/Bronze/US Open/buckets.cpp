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

ofstream cout ("buckets.out");
ifstream cin ("buckets.in");

pi b;
pi l;
vector<vector<char> > grid(10,vector<char>(10));
for(int j=0; j<10; j++){
	for(int i=0; i<10; i++){
		cin>>grid[j][i];
		if(grid[j][i]=='B') b=mp(j,i);
		if(grid[j][i]=='L') l=mp(j,i);
	}
}

vector<vector<bool> > visited(10, vector<bool>(10,false));
vector<vi> distance(10, vi(10, 1e9));
queue<pi> q;
q.push(b);
distance[b.f][b.s]=0;
visited[b.f][b.s]=true;

vpi dir={{1,0}, {0,1}, {-1,0}, {0,-1}};
while(!q.empty()){
	int y=q.front().f;
	int  x=q.front().s;
	q.pop();
	
	for(int i=0; i<4; i++){
		int v=dir[i].f;
		int h=dir[i].s;
		if(0<=y+v && y+v<=9 && 0<=x+h && x+h<=9 && !visited[y+v][x+h] && grid[y+v][x+h]!='R') {
			
			if(y+v==l.f && x+h==l.s){
				cout<<distance[y][x];
				return 0;
			}
			
			q.push(mp(y+v,x+h));
			visited[y+v][x+h]=true;
			distance[y+v][x+h]=distance[y][x]+1;
		}
	}
}

return 0;	
}
