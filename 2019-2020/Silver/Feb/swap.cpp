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

ofstream cout ("swap.out");
ifstream cin ("swap.in");

int n,m,k;
cin>>n>>m>>k;

vpi v(m);
for(int i=0; i<m; i++){
	int a,b;
	cin>>a>>b;
	v[i]=mp(a,b);
}

vi cows(n);
for(int i=0; i<n; i++) {
	cows[i]=i;
}
for(auto x:v){
	int a,b;
	tie(a,b)=x;
	reverse(cows.begin()+a-1, cows.begin()+b);
}

vector<vi> cc(100000); //contains all nodes in cc
vi cycle; //contains the legnth of cycle in each cc
map<int,int> id; //maps each node to a cc
map<int,int> pos; //maps each node's position in cc
vector<bool> visited(n,false);
int temp=0; //cc id
for(int i=0; i<n; i++){
	if(!visited[i]){
		visited[i]=true;
		int counter=1;
		cc[temp].pb(i);
		id[i]=temp;
		pos[i]=0;
		int start=cows[i];
		while(start!=i){
			cc[temp].pb(start);
			id[start]=temp;
			pos[start]=counter;
			visited[start]=true;
			start=cows[start];
			counter++;
		}
		
		cycle.pb(counter);
		temp++;
	}
}

for(int i=0; i<n; i++){
	int cc_id=id[i];
	cout<<cc[cc_id][(pos[i]+k)%cycle[cc_id]]+1<<"\n";
}

return 0;	
}

