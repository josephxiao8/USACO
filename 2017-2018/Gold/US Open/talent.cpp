#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std; 
using namespace __gnu_pbds;
 
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


ll n,w;
vpl cows;

bool possible(ll k){
	vector<vl> dp(n,vl(w+1,LONG_LONG_MIN));
	dp[0][0]=0;
	dp[0][min(w,cows[0].f)]=cows[0].s*1000-cows[0].f*k;
	for(ll j=1; j<n; j++){
		for(ll i=0; i<=w; i++){
			dp[j][i]=max(dp[j][i],dp[j-1][i]);
			if(dp[j-1][i]!=LONG_LONG_MIN) dp[j][min(w,i+cows[j].f)]=max(dp[j][min(w,i+cows[j].f)], dp[j-1][i]+cows[j].s*1000-cows[j].f*k);
		}
	}
	return dp[n-1][w]>=0;
}


int main() {
ios::sync_with_stdio(0);
cin.tie(0);

	ofstream cout ("talent.out");
	ifstream cin ("talent.in");

	cin>>n>>w;
	cows=vpl(n);
	ll sum=0;
	for(ll i=0; i<n; i++) {
		cin>>cows[i].f>>cows[i].s;
		sum+=cows[i].s;
	}
	sum*=1000;
	
	ll k=0;
	for(ll b=sum/2; b>=1; b/=2){
		while(k+b<=sum && possible(k+b)) k+=b;
	}
	
	cout<<k<<"\n";
	return 0;
}
