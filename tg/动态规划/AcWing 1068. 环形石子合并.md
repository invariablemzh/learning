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
const int N = 410, M = 18;
typedef long long ll;
typedef pair<int,int> PII;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 9901;
#define x first
#define y second

int w[N],s[N];
int f[N][N],g[N][N];

int main(){
    int n; scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        scanf("%d",&w[i]);
        w[i+n] = w[i];
    }
    for(int i = 1;i<=2*n;i++) s[i] = s[i-1] + w[i];
    memset(f,0x3f,sizeof(f));
    memset(g,-0x3f,sizeof(g));
    for(int len = 1;len<=n;len++){
        for(int l = 1;l+len-1<=2*n;l++){
            int r = l + len - 1;
            if(len==1) f[l][r] = g[l][r] = 0;
            else{
                for(int k = l;k<r;k++){
                    f[l][r] = min(f[l][k]+f[k+1][r]+s[r]-s[l-1],f[l][r]);
                    g[l][r] = max(g[l][k]+g[k+1][r]+s[r]-s[l-1],g[l][r]);
                }
            }
        }
    }
    int minv = INF, maxv = -INF;
    for(int i = 1;i<=n;i++){
        minv = min(minv,f[i][i+n-1]);
        maxv = max(maxv,g[i][i+n-1]);
    }
    printf("%d\n",minv);
    printf("%d\n",maxv);
}
```
