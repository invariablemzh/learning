1. 假设第一行的开关已经被锁死了
2. 只要第一行开关的状态确定，则所有开关的状态都可以被推出来
3. Q:最少按多少次，可以全部变成1
4. 2^5枚举方式 for(int i = 0;i<32;i++)

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
const int N = 10, M = 1<<20;
typedef long long ll;
typedef pair<int,int> PII;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

char g[N][N], bg[N][N];
int dx[5] = {-1,0,1,0,0};
int dy[5] = {0,1,0,-1,0};

void turn(int x,int y){
    for(int i = 0;i<5;i++){
        int a = x + dx[i], b = y + dy[i];
        if(a<0||a>=5||b<0||b>=5) continue;
        g[a][b] ^= 1;
    }
}

int main(){
    int T; scanf("%d",&T);
    while(T--){
        int res = 10;
        for(int i = 0;i<5;i++) scanf("%s",bg[i]);
        for(int op = 0;op<32;op++){
            memcpy(g,bg,sizeof(bg));
            int cnt = 0;
            for(int i = 0;i<5;i++){
                if(op>>i&1){
                    turn(0,i);
                    cnt++;
                }
            }
            for(int i = 1;i<=4;i++){
                for(int j = 0;j<5;j++){
                    if(g[i-1][j]=='0') {
                        turn(i,j);
                        cnt++;
                    }
                }
            }
            bool success = true;
            for(int i = 0;i<5;i++){
                if(g[4][i]=='0') success = false;
            }
            if(success&&res>cnt) res = cnt;
        }
        if(res>6) res = -1;
        printf("%d\n",res);
    }
    return 0;
}
```
