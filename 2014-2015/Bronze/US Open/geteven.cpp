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

ofstream cout ("geteven.out");
ifstream cin ("geteven.in");

int n;
cin>>n;
map<char,int> mapp;
mapp['B']=0;
mapp['E']=1;
mapp['S']=2;
mapp['I']=3;
mapp['G']=4;
mapp['O']=5;
mapp['M']=6;

vector<vi> v(7);

for(int i=0; i<n; i++){
	char tempc;
	int tempi;
	cin>>tempc>>tempi;
	v[mapp[tempc]].pb(tempi);
}


// if m is even
int ans=0;
int count=0;
for(int i=0; i<v[6].size(); i++){
	if(v[6][i]%2==0){
		count++;
		v[6].erase(v[6].begin()+i);
		i--;
	}
}
for(int i=0; i<6; i++){
	count*=v[i].size();
}
ans+=count;

int add=v[6].size();
for(auto b:v[0])
for(auto e:v[1])
for(auto s:v[2])
for(auto i:v[3])
for(auto g:v[4])
for(auto o:v[5]){
	if((b+i)%2==0) ans+=add;
	else if((g+o+e+s)%2==0) ans+=add;
	}

cout<<ans<<endl;
return 0;
}
