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


vpi dir={{0,1},{1,0},{0,-1},{-1,0}};

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

	ofstream cout ("radio.out");
	ifstream cin ("radio.in");
	
	map<char,int> mapp;
	mapp['N']=0;
	mapp['E']=1;
	mapp['S']=2;
	mapp['W']=3;
	
	int n,m;
	pi f,b;
	string fj, bes;
	cin>>n>>m>>f.f>>f.s>>b.f>>b.s>>fj>>bes;
	
	vpi pos_fj(n+1);
	pos_fj[0]=f;
	for(int i=1; i<=n; i++){
		int dx,dy;
		tie(dx,dy)=dir[mapp[fj[i-1]]];
		pos_fj[i]=mp(pos_fj[i-1].f+dx, pos_fj[i-1].s+dy);
	}
	
	vpi pos_bes(m+1);
	pos_bes[0]=b;
	for(int i=1; i<=m; i++){
		int dx,dy;
		tie(dx,dy)=dir[mapp[bes[i-1]]];
		pos_bes[i]=mp(pos_bes[i-1].f+dx, pos_bes[i-1].s+dy);
	}
	
	vector<vi> dp(n+1, vi(m+1, 1e9+7));
	for(int j=0; j<=n; j++){
		for(int i=0; i<=m; i++){
			if(j==0 && i==0) dp[0][0]=0;
			else{
				int temp=(pos_fj[j].f-pos_bes[i].f)*(pos_fj[j].f-pos_bes[i].f)+(pos_fj[j].s-pos_bes[i].s)*(pos_fj[j].s-pos_bes[i].s);
				if(j-1>=0) dp[j][i]=min(dp[j-1][i]+temp, dp[j][i]);
				if(i-1>=0) dp[j][i]=min(dp[j][i-1]+temp, dp[j][i]);
				if(j-1>=0 && i-1>=0) dp[j][i]=min(dp[j-1][i-1]+temp, dp[j][i]);
			}
		}
	}
	
	cout<<dp[n][m]<<"\n";
	return 0;
}
