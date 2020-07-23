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

ofstream cout ("backforth.out");
ifstream cin ("backforth.in");

vi v1(12,0);
vi v2(12,0);
for(int i=0; i<10; i++) cin>>v1[i];
for(int i=0; i<10; i++) cin>>v2[i];
	
set<int> sett;
for(int a=0; a<12; a++){
	int counter1a=1000, counter2a=1000;  
	vi va=v1;
	int tempa=va[a];
	va[a]=0;
	counter2a+=tempa;
	counter1a-=tempa;
	if(tempa==0) continue;

	
	for(int b=0; b<12; b++){
		int counter1b=counter1a, counter2b=counter2a;
		vi vb=v2;
		vb[10]=tempa;
		int tempb=vb[b];
		vb[b]=0;
		counter1b+=tempb;
		counter2b-=tempb;
		if(tempb==0) continue;

		
		for(int c=0; c<12; c++){
			int counter1c=counter1b, counter2c=counter2b;
			vi vc=va;
			vc[10]=tempb;
			int tempc=vc[c];
			vc[c]=0;
			counter2c+=tempc;
			counter1c-=tempc;
			if(tempc==0) continue;
				
			for(int d=0; d<12; d++){
				int counter1d=counter1c, counter2d=counter2c;
				vi vd=vb;
				vd[11]=tempc;
				int tempd=vd[d];
				vd[d]=0;
				counter1d+=tempd;
				counter2d-=tempd;
				if(tempd==0) continue;
					
				sett.insert(counter1d);
			}
		}
	}
}

cout<<sett.size()<<endl;
return 0;
}
