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
	
	int n;
	cin>>n;
	vi v(n);
	for(int i=0; i<n; i++) cin>>v[i];
	
	vector<vi> dp(n, vi(n,301));
	
	for(int size=0; size<n; size++){
		for(int i=0; i+size<n; i++){
			if(size==0) dp[i][i]=1;
			else{
				for(int j=i; j<=i+size; j++){
					if(j==i+size) dp[i][i+size]=min(dp[i][i+size],dp[i][i+size-1]+1);
					else if(v[j]==v[i+size]) {
						if(j==i) dp[i][i+size]=min(dp[i][i+size],dp[i][i+size-1]); 
						else dp[i][i+size]=min(dp[i][i+size],dp[i][j]+dp[j][i+size-1]-1); 
					}
					else dp[i][i+size]=min(dp[i][i+size], dp[i][j]+dp[j][i+size]+1);
				}
			}
		}
	}

	cout<<dp[0][n-1]<<"\n";
	return 0;	
}
