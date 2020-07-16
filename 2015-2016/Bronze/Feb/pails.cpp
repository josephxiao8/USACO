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

ofstream cout ("pails.out");
ifstream cin ("pails.in");

int x,y,m;
cin>>x>>y>>m;

int counter=0, maxx=0;
while(m>=counter+x){
	counter+=x;
}
maxx=max(maxx,counter);

while(counter>=x) {
	counter-=x;
	int temp=counter;
	while(m>=counter+y){
	counter+=y;
	maxx=max(maxx,counter);	
	}
	counter=temp;
}

cout<<maxx<<endl;

return 0;
}
