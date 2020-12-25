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
typedef priority_queue<tuple<int,pair<pi,int>, pair<pi,int>>,vector<tuple<int,pair<pi,int>, pair<pi,int>>>,greater<tuple<int,pair<pi,int>, pair<pi,int>>>> pqg;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
 
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound


vi dy={-1,0,1,0};
vi dx={0,1,0,-1};
bool visited[20][20][4][20][20][4];

int main() {
ios::sync_with_stdio(0);
cin.tie(0);
	
	ofstream cout ("cownav.out");
	ifstream cin ("cownav.in");
	
	int n;
	cin>>n;
	vector<vector<char>> grid(n, vector<char>(n));
	for(int j=0; j<n; j++){
		for(int i=0; i<n; i++){
			cin>>grid[j][i];
		}
	}
	
	pqg q;
	q.push(mt(0,mp(mp(n-1,0),0),mp(mp(n-1,0),1)));
	visited[n-1][0][0][n-1][0][1]=true;
	
	while(!q.empty()){
		int len,y1,x1,d1,y2,x2,d2;
		len=get<0>(q.top());
		tie(y1,x1)=(get<1>(q.top())).f;
		d1=(get<1>(q.top())).s;
		tie(y2,x2)=(get<2>(q.top())).f;
		d2=(get<2>(q.top())).s;
		q.pop();
		
		if(y1==0 && x1==n-1 && y2==0 && x2==n-1){
			cout<<len<<"\n";
			return 0;
		}
		
		for(int i=0; i<3; i++){
			if(i!=2){ //turn left or right
				int d3,d4;
				if(i==0){
					d3=(d1+3)%4;
					d4=(d2+3)%4;
				}
				else{
					d3=(d1+1)%4;
					d4=(d2+1)%4;
				}
				
				if(!visited[y1][x1][d3][y2][x2][d4]){
					visited[y1][x1][d3][y2][x2][d4]=true;
					q.push(mt(len+1,mp(mp(y1,x1),d3),mp(mp(y2,x2),d4)));
				}
			}
			else{ //move forward
				int y3=min(max(y1+dy[d1],0),n-1);
				int x3=min(max(x1+dx[d1],0),n-1);
				if(grid[y3][x3]=='H' || (y1==0 && x1==n-1)){
					y3=y1;
					x3=x1;
				}
				int y4=min(max(y2+dy[d2],0),n-1);
				int x4=min(max(x2+dx[d2],0),n-1);
				if(grid[y4][x4]=='H' || (y2==0 && x2==n-1)){
					y4=y2;
					x4=x2;
				}
				
				if(!visited[y3][x3][d1][y4][x4][d2]){
					visited[y3][x3][d1][y4][x4][d2]=true;
					q.push(mt(len+1,mp(mp(y3,x3),d1),mp(mp(y4,x4),d2)));
				}
			}
		}
	}
	
	return 0;
}
