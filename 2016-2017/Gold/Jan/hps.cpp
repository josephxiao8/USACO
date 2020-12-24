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
	
	ofstream cout ("hps.out");
	ifstream cin ("hps.in");
	
	int n,k;
	cin>>n>>k;
	vector<char> v(n);
	map<char,int> mapp;
	mapp['H']=0;
	mapp['P']=1;
	mapp['S']=2;
	for(int i=0; i<n; i++){
		char c;
		cin>>c;
		v[i]=mapp[c];
	}
	
	vector<vector<vi>> dp(n, vector<vi>(3, vi(k+1,INT_MIN)));
	for(int i=0; i<3; i++){
		if(i==0){
			if(v[0]==2) dp[0][i][0]=1;
			else dp[0][i][0]=0;
		}
		else if(i==1){
			if(v[0]==0) dp[0][i][0]=1;
			else dp[0][i][0]=0;
		}
		else{
			if(v[0]==1) dp[0][i][0]=1;
			else dp[0][i][0]=0;
		}
	}
	
	int ans=1;
	for(int i=1; i<n; i++){
		for(int j=0; j<3; j++){
			for(int a=0; a<=min(i,k); a++){
				int maxx;
				if(a==0) maxx=0;
				else maxx=max(dp[i-1][0][max(0,a-1)], max(dp[i-1][1][max(0,a-1)], dp[i-1][2][max(0,a-1)]));
				if(j==0){
					if(v[i]==2) dp[i][j][a]=max(dp[i-1][j][a], maxx)+1;
					else dp[i][j][a]=max(dp[i-1][j][a], maxx);
				}
				else if(j==1){
					if(v[i]==0) dp[i][j][a]=max(dp[i-1][j][a], maxx)+1;
					else dp[i][j][a]=max(dp[i-1][j][a], maxx);
				}
				else{
					if(v[i]==1) dp[i][j][a]=max(dp[i-1][j][a], maxx)+1;
					else dp[i][j][a]=max(dp[i-1][j][a], maxx);
				}
				ans=max(ans, dp[i][j][a]);
			}
		}
	}
	
	cout<<ans<<"\n";
	return 0;
}
