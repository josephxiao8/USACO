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
	
	int n,k;
	cin>>n>>k;
	vi b(n);
	for(int i=0; i<n; i++) {
		cin>>b[i];
		b[i]--;
	}
	
	vector<vi> s(k+1, vi(k));
	for(int j=0; j<k; j++){
		for(int i=0; i<k; i++){
			char c;
			cin>>c;
			s[j][i]=c-'0';
		}
	}
	
	for(int i=0; i<k; i++) s[k][i]=s[b[0]][i];
	
	if(n==1){
		cout<<0<<"\n";
		return 0;
	}
	
	queue<ti> q;
	q.push(mt(0,0,k));
	vector<vector<bool>> vis(n, vector<bool>(k+1,false));
	vis[0][b[0]]=true;
	while(!q.empty()){
		int cost, start, breed;
		tie(cost, start, breed)=q.front(); q.pop();
		if(start==n-1 && breed==b[n-1]){
			cout<<cost<<"\n";
			return 0;
		}
		if(start-1>=0){
			if(s[breed][b[start-1]] && !vis[start-1][b[start-1]]){
				vis[start-1][b[start-1]]=true;
				q.push(mt(cost+1,start-1, b[start-1]));
			}
			if(!vis[start-1][breed]){
				vis[start-1][breed]=true;
				q.push(mt(cost+1,start-1, breed));
			}
		}
		if(start+1<n){
			if(s[breed][b[start+1]] && !vis[start+1][b[start+1]]){
				vis[start+1][b[start+1]]=true;
				q.push(mt(cost+1,start+1, b[start+1]));
			}
			if(!vis[start+1][breed]){
				vis[start+1][breed]=true;
				q.push(mt(cost+1,start+1, breed));
			}
		}
	}
	
	cout<<-1<<"\n";
	return 0;	
}
