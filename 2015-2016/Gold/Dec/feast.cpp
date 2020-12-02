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
typedef priority_queue<pl,vector<pl>,greater<pl>> pqg;
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

	ofstream cout ("feast.out");
	ifstream cin ("feast.in");
	
	int t,a,b;
	cin>>t>>a>>b;
	
	vector<bool> dp(t+1,false);
	vi maxx(t+1);
	dp[0]=true;
	maxx[0]=0;
	for(int i=1; i<=t; i++){
		if(i-a>=0) if(dp[i-a]) dp[i]=true;
		if(i-b>=0) if(dp[i-b]) dp[i]=true;
		if(dp[i]) maxx[i]=i;
		else maxx[i]=maxx[i-1];
	}
	
	int ans=0;
	for(int i=0; i<t; i++){
		if(!dp[i]) continue;
		int temp=i/2+maxx[t-i/2];
		ans=max(ans,max(i,temp));
	}
	
	cout<<ans<<"\n";
	return 0;
}
