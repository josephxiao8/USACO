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
vector<set<string> > palin;
vector<set<string> > palinrev;

void search(int y, int x, vector<vector<char> > grid, string str){
	str+=grid[y][x];
	if(y+x==n-1){
		palin[x].insert(str);
		return;
	}
	search(y+1,x,grid,str);
	search(y,x+1,grid,str);	
}

void searchrev(int y, int x, vector<vector<char> > grid, string str){
	str+=grid[y][x];
	if(y+x==n-1){
		palinrev[x].insert(str);
		return;
	}
	searchrev(y-1,x,grid,str);
	searchrev(y,x-1,grid,str);	
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

ofstream cout ("palpath.out");
ifstream cin ("palpath.in");

cin>>n;
palin.resize(n);
palinrev.resize(n);
vector<vector<char> > grid(n, vector<char>(n));

for(int j=0; j<n; j++){
	for(int i=0; i<n; i++){
		cin>>grid[j][i];
	}
}

string str="";
search(0,0,grid,str);
str="";
searchrev(n-1,n-1,grid,str);

set<string> ans;
for(int i=0; i<n; i++){
	for(auto x: palin[i]){
		if(palinrev[i].count(x)) ans.insert(x);
	}
}

cout<<ans.size()<<endl;
return 0;
}
