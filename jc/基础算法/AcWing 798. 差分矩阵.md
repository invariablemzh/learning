```c++
#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1010;

int n,m,q;
int s[N][N];

int main(){
    scanf("%d%d%d",&n,&m,&q);
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            int tmp;
            scanf("%d",&tmp);
            s[i][j] += tmp;
            s[i+1][j] -= tmp;
            s[i][j+1] -= tmp;
            s[i+1][j+1] += tmp;
        }
    }
    while(q--){
        int x1,x2,y1,y2,c;
        scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&c);
        s[x1][y1] += c;
        s[x1][y2+1] -= c;
        s[x2+1][y1] -= c;
        s[x2+1][y2+1] += c;
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + s[i][j];
            printf("%d ",s[i][j]);
        }
        puts("");
    }
    return 0;
}
```
