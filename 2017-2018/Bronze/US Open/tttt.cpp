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

ofstream cout ("tttt.out");
ifstream cin ("tttt.in");

int single=0, doubles=0;
set<char> set_single;
set<pair<char,char> > set_double;

vector<vector<char> > grid(3, vector<char>(3));
for(int j=0; j<3; j++){
    for(int i=0; i<3; i++){
		cin>>grid[j][i];
	}	
}

//horizontal
for(int j=0; j<3; j++){
    set<char> temp;
    for(int i=0; i<3; i++){
		temp.insert(grid[j][i]);
	}
	if(temp.size()==1 && !set_single.count(*temp.begin())) {
		single++;
		set_single.insert(*temp.begin());
	}
	else if(temp.size()==2 && !set_double.count(mp(*temp.begin(),*(++temp.begin())))) {
		set_double.insert(mp(*temp.begin(),*(++temp.begin())));
		doubles++;
	}
}

//vertical
for(int i=0; i<3; i++){
    set<char> temp;
    for(int j=0; j<3; j++){
		temp.insert(grid[j][i]);
	}
	if(temp.size()==1 && !set_single.count(*temp.begin())) {
		single++;
		set_single.insert(*temp.begin());
	}
	else if(temp.size()==2 && !set_double.count(mp(*temp.begin(),*(++temp.begin())))) {
		set_double.insert(mp(*temp.begin(),*(++temp.begin())));
		doubles++;
	}
}

//diagonals
set<char> temp;
for(int i=0; i<3; i++) temp.insert(grid[i][i]);
if(temp.size()==1 && !set_single.count(*temp.begin())) {
		single++;
		set_single.insert(*temp.begin());
}
else if(temp.size()==2 && !set_double.count(mp(*temp.begin(),*(++temp.begin())))) {
	set_double.insert(mp(*temp.begin(),*(++temp.begin())));
	doubles++;
}

temp.clear();
for(int i=0; i<3; i++)temp.insert(grid[2-i][i]);
if(temp.size()==1 && !set_single.count(*temp.begin())) {
	single++;
	set_single.insert(*temp.begin());
}
else if(temp.size()==2 && !set_double.count(mp(*temp.begin(),*(++temp.begin())))) {
	set_double.insert(mp(*temp.begin(),*(++temp.begin())));
	doubles++;
}

cout<<single<<endl<<doubles<<endl;
return 0;	
}
