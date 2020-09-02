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

ofstream cout ("where.out");
ifstream cin ("where.in");

int n;
cin>>n;

vector<vector<char> > grid(n, vector<char>(n));
for(int j=0; j<n; j++){
	for(int i=0; i<n; i++){
		cin>>grid[j][i];
	}
}

vector<pair<pi,pi> > ans; //to store coordinates of potential pcl's
vi dy={1,-1,0,0};
vi dx={0,0,1,-1};
for(int l=0; l<n; l++){
	for(int k=0; k<n; k++){
		for(int j=l+1; j<=n; j++){
			for(int i=k+1; i<=n; i++){
				
				int colors=0; //to check if the number of colors present in pcl is 2
				vi times(26,0); //to check how many connected components there are
				vector<vector<bool> > visited(n,vector<bool>(n,false));
				for(int b=l; b<j; b++){
					for(int a=k; a<i; a++){
						if(!visited[b][a]){
							visited[b][a]=true;
							queue<pi> q;
							q.push(mp(b,a));								
							if(times[grid[b][a]-'A']==0) colors++;
							times[grid[b][a]-'A']++;
							while(!q.empty()){
								int c,d;
								tie(d,c)=q.front(); q.pop();
								for(int x=0; x<4; x++){
									int e=c+dx[x];
									int f=d+dy[x];
									if(e<k || e>=i || f<l || f>=j) continue;
									else if(grid[f][e]==grid[b][a] && !visited[f][e]){
										visited[f][e]=true;
										q.push(mp(f,e));
									}
								}
							}
			
						}
					}
				}
				
				if(colors==2){
					bool single=false, doubleormore=false;
					for(auto x:times){
						if(x==1) single=true;
						if(x>1) doubleormore=true;
					}
					if(single && doubleormore) ans.pb({{l,k},{j,i}});
				}
			}
		}
	}
}

int counter=0;
for(auto x:ans){
	bool good=true;
	for(auto y:ans){
		if(x==y) continue;
		int a,b,c,d,e,f,g,h;
		tie(a,b)=x.f;
		tie(c,d)=x.s;
		tie(e,f)=y.f;
		tie(g,h)=y.s;
		if(e<=a && a<=g && f<=b && b<=h && e<=c && c<=g && f<=d && d<=h){
			good=false;
			break;
		}
	}
	if(good) counter++;
}

cout<<counter<<"\n";
return 0;
}
