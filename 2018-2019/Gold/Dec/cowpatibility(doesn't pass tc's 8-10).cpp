#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;
using namespace std; 
 
typedef long long ll;
 
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef tuple<int,int,int> ti;
typedef tuple<ll,ll,ll> tl;
 
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<ti> vti;
typedef vector<tl> vtl;
 
typedef priority_queue<int> pq;
typedef priority_queue<int,vector<int>,greater<int>> pqg;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
 
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound


int main() {
ios::sync_with_stdio(0);
cin.tie(0);
    
    ofstream cout ("cowpatibility.out");
    ifstream cin ("cowpatibility.in");
    
    int n;
    cin>>n;
    vector<array<int,5>> v(n, array<int,5>());
    map<array<int,5>,int> mapp;
    for(int j=0; j<n; j++){
        for(int i=0; i<5; i++){
            cin>>v[j][i];
        }
        sort(v[j].begin(), v[j].end());
        for(int i=1; i<(1<<5); i++){
            array<int,5> x;
            for(int i=0; i<5; i++) x[i]=-1;
            int idx=0;
            for(int mask=0; mask<5; mask++){
                if(i&(1<<mask)) x[idx++]=v[j][mask];
            }
            mapp[x]++;
        }
    }
    
    int pairs=0;
    for(int j=0; j<n; j++){
        for(int i=1; i<(1<<5); i++){
            array<int,5> x;
            for(int i=0; i<5; i++) x[i]=-1;
            int idx=0;
            for(int mask=0; mask<5; mask++){
                if(i&(1<<mask)) x[idx++]=v[j][mask];
            }
            pairs+=int(pow(-1,idx+1))*(mapp[x]-1);
        }
    }
    
    cout<<(n*(n-1))/2 - pairs/2<<"\n";
    return 0;
}
