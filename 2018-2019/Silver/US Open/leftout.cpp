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


bool possible(set<string> sett, string temp){
	sett.insert(temp);
	if(sett.size()==1) return true;
	else if(sett.size()==2){
		auto it=sett.begin();
		auto jt=(--sett.end());
		for(int i=0; i<int((*it).size()); i++){
			if((*it)[i]==(*jt)[i]) return false;
		}
		return true;
	}
	else return false;
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

ofstream cout ("leftout.out");
ifstream cin ("leftout.in");

int n;
cin>>n;
vector<string> v(n);
vector<set<string> > grid(n);
for(int j=0; j<n; j++){
	string temp;
	cin>>temp;
	v[j]=temp;
	for(int i=0; i<n; i++){
		if(i==j) continue;
		grid[i].insert(temp);
	}
}

for(int j=0; j<n; j++){
	for(int i=0; i<n; i++){
		string temp=v[j];
		if(temp[i]=='R') temp[i]='L';
		else temp[i]='R';
		
		if(possible(grid[j],temp)){
			cout<<j+1<<" "<<i+1<<"\n";
			return 0;
		}
	}
}

cout<<-1<<"\n";
return 0;	
}

