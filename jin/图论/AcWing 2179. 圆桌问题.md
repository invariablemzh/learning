```c++
#include <bits/stdc++.h>
using namespace std;
const int N = 430, M = (150*270+N)*2, INF = 0x3f3f3f3f;

int n,m,S,T;
int h[N], e[M], ne[M], f[M], idx;
int q[N], d[N], cur[N];

void add(int a,int b,int c){
    e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a] = idx++;
    e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx++;
}

bool bfs(){
    memset(d,-1,sizeof(d));
    int hh = 0, tt = 0;
    q[0] = S, d[S] = INF, cur[S] = h[S];
    while(hh<=tt){
        int t = q[hh++];
        for(int i = h[t];~i;i=ne[i]){
            int j = e[i];
            if(d[j]==-1&&f[i]){
                d[j] = d[t] + 1;
                cur[j] = h[j];
                if(j==T) return true;
                q[++tt] = j;
            }
        }
    }
    return false;
}

int find(int u,int limit){
    if(u==T) return limit;
    int flow = 0;
    for(int i = h[u];~i&&flow<limit;i=ne[i]){
        int j = e[i];
        cur[u] = i;
        if(d[j]==d[u]+1&&f[i]){
            int t = find(j, min(f[i],limit-flow));
            if(!t) d[j] = -1;
            f[i] -= t, f[i^1] += t, flow += t;
        }
    }
    return flow;
}

int dinic(){
    int flow,r = 0;
    while(bfs()) while(flow = find(S,INF)) r += flow;
    return r;
}

int main(){
    memset(h,-1,sizeof(h));
    scanf("%d%d",&m,&n);
    S = 0, T = n + m + 1;
    int tot = 0;
    for(int i = 1;i<=m;i++){
        int r; scanf("%d",&r);
        add(S,i,r);
        tot += r;
    }
    for(int i = 1;i<=n;i++){
        int c; scanf("%d",&c);
        add(i+m,T,c);
    }
    for(int i = 1;i<=m;i++){
        for(int j = 1;j<=n;j++){
            add(i,j+m,1);
        }
    }
    if(dinic()!=tot) puts("0");
    else{
        puts("1");
        for(int i = 1;i<=m;i++){
            for(int j = h[i];~j;j=ne[j]){
                if(e[j]>m&&e[j]<=n+m&&!f[j]){
                    printf("%d ", e[j]-m);
                }
            }
            puts("");
        }
    }
}
```
