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
typedef priority_queue<pi,vector<pi>,greater<pi>> pqg;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
 
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound


int main(){
ios::sync_with_stdio(0);
cin.tie(0);

	ofstream cout ("cowmbat.out");
	ifstream cin ("cowmbat.in");
	
	int n,m,k;
	string s;
	cin>>n>>m>>k>>s;
	
	vector<vi> dis(m, vi(m,1e9+7));
	for(int j=0; j<m; j++){
		for(int i=0; i<m; i++){
			cin>>dis[j][i];
		}
	}
	for(int i=0; i<m; i++){
		for(int j=0; j<m; j++){
			for(int a=0; a<m; a++){
				dis[j][a]=min(dis[j][a],dis[j][i]+dis[i][a]);
			}
		}
	}
	
	vector<vi> cost(m, vi(n+1,0));
	for(int j=0; j<m; j++){
		for(int i=1; i<=n; i++){
			cost[j][i]=cost[j][i-1]+dis[s[i-1]-'a'][j];
		}
	}
	
	vector<vi> dp2(m, vi(n));
	vi dp(n,1e9+7);
	for(int j=k-1; j<min(n,2*k-1); j++){
		for(int i=0; i<m; i++){
			dp2[i][j]=cost[i][j+1];
			dp[j]=min(dp[j],dp2[i][j]);
		}
	}
	
	for(int i=2*k-1; i<n; i++){
		for(int j=0; j<m; j++){
			dp2[j][i]=min(dp[i-k]+cost[j][i+1]-cost[j][i-k+1],dp2[j][i-1]+dis[s[i]-'a'][j]);
			dp[i]=min(dp[i],dp2[j][i]);
		}
	}
	
	cout<<dp[n-1]<<"\n";
	return 0;
}
