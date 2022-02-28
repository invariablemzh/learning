1≤a,b,p≤10^18

快速幂: 乘法 -> 乘方

今天: 加法 -> 乘法

转化成a个b相加

a  % p

2a % p

4a % p

8a % p

……

2^62a % p

b = (11010)2

b = 2^1 + 2^3 + 2^4

ab = 2^1a + 2^3a + 2^4a

```
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
const int N = 5e4+10, M = 1<<20;
typedef long long ll;
typedef pair<int,int> PII;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

ll qadd(ll a,ll b,ll p){
    ll res = 0;
    while(b){
        if(b&1) res = (res + a) % p;
        a = (a + a) % p;
        b>>=1;
    }
    return res;
}

int main(){
    ll a,b,p;
    scanf("%lld%lld%lld",&a,&b,&p);
    printf("%lld\n",qadd(a,b,p));
    return 0;
}
```
