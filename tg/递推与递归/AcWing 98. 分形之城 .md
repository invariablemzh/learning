```c++
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_set>
#include <cstring>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;
const int N = 10, M = 1<<20;
typedef long long ll;
typedef pair<int,int> PII;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 9901;
#define x first
#define y second

struct Point{
    ll x,y;
};

Point find(ll n,ll a){
    if(n==0) return {0,0};
    ll len = 1ll<<(n-1), block = 1ll<<(2*n-2);
    auto p = find(n-1,a%block);
    ll x = p.x, y = p.y;
    int z = a / block;
    if(z==0) return {y,x};
    else if(z==1) return {x,y+len};
    else if(z==2) return {x+len,y+len};
    return {2 * len - y - 1,len - x - 1};
}

int main(){
    int T; scanf("%d",&T);
    while(T--){
        ll n,a,b;
        scanf("%lld%lld%lld",&n,&a,&b);
        auto pa = find(n,a-1);
        auto pb = find(n,b-1);
        double dx = pa.x - pb.x;
        double dy = pa.y - pb.y;
        printf("%.0lf\n",10*sqrt(dx*dx+dy*dy));
    }
    return 0;
}
```
