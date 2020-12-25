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
typedef priority_queue<tuple<int,pi,int>,vector<tuple<int,pi,int>>,greater<tuple<int,pi,int>>> pqg;
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

int main() {
ios::sync_with_stdio(0);
cin.tie(0);
	
	ofstream cout ("visitfj.out");
	ifstream cin ("visitfj.in");
	
	int n,t;
	cin>>n>>t;
	vector<vi> grid(n, vi(n));
	for(int j=0; j<n; j++){
		for(int i=0; i<n; i++){
			cin>>grid[j][i];
		}
	}
	
	vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(n, vector<bool>(3,false)));
	
	pqg q;
	q.push(mt(0,mp(0,0),0));
	while(!q.empty()){
		int a,b,c,d;
		a=get<0>(q.top());
		tie(b,c)=get<1>(q.top());
		d=get<2>(q.top());
		q.pop();
		
		if(b==n-1 && c==n-1){
			cout<<a<<"\n";
			return 0;
		}
		
		for(int i=0; i<4; i++){
			int b2=b+dy[i];
			int c2=c+dx[i];
			
			if(b2<0 || b2>=n || c2<0 || c2>=n) continue;
			if(!visited[b2][c2][(d+1)%3]){
				visited[b2][c2][(d+1)%3]=true;
				int temp=a+t;
				if((d+1)%3==0) temp+=grid[b2][c2];
				q.push(mt(temp,mp(b2,c2),(d+1)%3));
			}
		}
	}
	
	

	return 0;
}
