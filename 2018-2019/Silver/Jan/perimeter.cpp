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


int main() {
ios::sync_with_stdio(0);
cin.tie(0);

ofstream cout ("perimeter.out");
ifstream cin ("perimeter.in");

int n;
cin>>n;
vector<vector<char> > grid(n, vector<char>(n));
for(int j=0; j<n; j++){
	for(int i=0; i<n; i++){
		cin>>grid[j][i];
	}
}


int ans1=0, ans2=0;
vi dy={1,-1,0,0};
vi dx={0,0,1,-1};
vector<vector<bool> >visited(n, vector<bool>(n));
for(int j=0; j<n; j++){
	for(int i=0; i<n; i++){
		if(!visited[j][i] && grid[j][i]=='#'){
			int counter1=0, counter2=0;
			visited[j][i]=true;
			queue<pi> q;
			q.push(mp(j,i));
			
			while(!q.empty()){
				int a,b;
				tie(b,a)=q.front(); q.pop();
				counter1++;
				for(int k=0; k<4; k++){
					int c=a+dx[k];
					int d=b+dy[k];
					if(c<0 || c>=n || d<0 || d>=n || grid[d][c]=='.') counter2++;
					else if(!visited[d][c]){
						visited[d][c]=true;
						q.push(mp(d,c));
					}
				}	
			}
			
			if(counter1>ans1){
				ans1=counter1;
				ans2=counter2;
			}
			else if(counter1==ans1){
				ans2=min(ans2,counter2);
			}
		}
	}
}


cout<<ans1<<" "<<ans2<<"\n";
return 0;	
}

