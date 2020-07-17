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

ofstream cout ("hps.out");
ifstream cin ("hps.in");

int n;
cin>>n;

vpi v(n);
for(int i=0; i<n; i++) {
	int n1,n2;
	cin>>n1>>n2;
	v[i]=mp(n1,n2);
}

int maxx=0;
for(int i=1; i<=3; i++){
	for(int j=1; j<=3; j++){
		if(i==j) continue;
		for(int k=1; k<=3; k++){
			if(j==k || i==k) continue;
			int counter=0;
			for(auto x:v){
				int n1,n2;
				tie(n1,n2)=x;
				if(n1==i){
					if(n2==j) counter++;
				}
				
				else if(n1==j){
					if(n2==k) counter++;
				}
				
				else{
					if(n2==i) counter++;
				}
			}
			maxx=max(maxx,counter);
		}
	}
}

cout<<maxx<<endl;
return 0;
}
