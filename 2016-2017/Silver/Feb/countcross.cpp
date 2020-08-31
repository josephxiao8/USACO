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
 
typedef priority_queue<pair<int,string>> pq;
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

ofstream cout ("countcross.out");
ifstream cin ("countcross.in");

int n,k,r;
cin>>n>>k>>r;

set<pair<pi,pi> > sett;
for(int i=0; i<r; i++){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	a--;
	b--;
	c--;
	d--;
	sett.insert({{a,b},{c,d}});
	sett.insert({{c,d},{a,b}});
}

vector<vector<bool> > cow(n, vector<bool>(n,false));
for(int i=0; i<k; i++){
	int a,b;
	cin>>a>>b;
	a--;
	b--;
	cow[a][b]=true;
}

vector<vector<bool> > visited(n, vector<bool>(n,false));
vi dy={1,-1,0,0};
vi dx={0,0,1,-1};
vi ans;
int sum=0;
for(int j=0; j<n; j++){
	for(int i=0; i<n; i++){
		if(!visited[j][i]){
			int counter=0;
			visited[j][i]=true;
			queue<pi> q;
			q.push(mp(j,i));
			while(!q.empty()){
				int b,a;
				tie(b,a)=q.front(); q.pop();
				if(cow[b][a]) counter++;
				for(int k=0; k<4; k++){
					int c=a+dx[k];
					int d=b+dy[k];
					if(c<0 || c>=n || d<0 || d>=n) continue;
					if(!visited[d][c] && !sett.count({{b,a},{d,c}})){
						visited[d][c]=true;
						q.push(mp(d,c));
					}
				}
			}
			ans.pb(counter);
			sum+=counter;
		}
	}
}

int temp=0;
for(auto x:ans){
	sum-=x;
	temp+=x*sum;
}

cout<<temp<<"\n";
return 0;
}
