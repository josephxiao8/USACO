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
 
typedef priority_queue<int> pq;
typedef priority_queue<int,vector<int>,greater<int>> pqg;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound


int n;

void fall(vector<vi>& grid){
	for(int i=0; i<10; i++){
		stack<int> stac;
		bool non_zero=false;
		bool change=false;
		for(int j=0; j<n; j++){
			if(grid[j][i]==0){
				if(non_zero) change=true;
			}
			else{
				non_zero=true;
				stac.push(grid[j][i]);
			}
		}
		
		if(change){
			for(int j=n-1; j>=0; j--){
				if(!stac.empty()) {
					grid[j][i]=stac.top(); stac.pop();
				}
				else grid[j][i]=0;
			}
		}
	}
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

ofstream cout ("mooyomooyo.out");
ifstream cin ("mooyomooyo.in");

int k;
cin>>n>>k;
vector<vi> grid(n, vi(10));
for(int j=0; j<n; j++){
	string temp;
	cin>>temp;
	for(int i=0; i<10; i++){
		grid[j][i]=temp[i]-'0';
	}
}

bool finished=false;
while(!finished){
	vi dy={1,-1,0,0};
	vi dx={0,0,1,-1};
	vector<vector<bool> > visited(n, vector<bool>(10,false));
	finished=true;
	for(int j=0; j<n; j++){
		for(int i=0; i<10; i++){
			if(grid[j][i]!=0 && !visited[j][i]){
				visited[j][i]=true;
				queue<pi> q;
				queue<pi> region;
				q.push(mp(j,i));
				region.push(mp(j,i));
				while(!q.empty()){
					int a,b;
					tie(b,a)=q.front(); q.pop();
					for(int k=0; k<4; k++){
						int c=a+dx[k];
						int d=b+dy[k];
						if(c<0 || c>=10 || d<0 || d>=n) continue;
						if(grid[d][c]==grid[b][a] && !visited[d][c]){
							visited[d][c]=true;
							q.push(mp(d,c));
							region.push(mp(d,c));
						}
					}
				}
				if(int(region.size())>=k){
					finished=false;
					while(!region.empty()){
						int a,b;
						tie(b,a)=region.front(); region.pop();
						grid[b][a]=0;
					}
				}
			}
		}
	}
	fall(grid);
}


for(int j=0; j<n; j++){
	for(int i=0; i<10; i++){
		cout<<grid[j][i];
	}
	cout<<"\n";
}

return 0;
}
