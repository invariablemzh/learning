```c++
#include <bits/stdc++.h>
using namespace std;
const int N = 10010, M = 200010, INF = 1e8;

int n,m,S,T;
int h[N],e[M],ne[M],f[M],idx;
int q[N],cur[N],d[N];

void add(int a,int b,int c){
    e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a] = idx++;
    e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx++;
}

bool bfs(){
    memset(d,-1,sizeof(d));
    int hh = 0, tt = 0;
    q[0] = S, cur[S] = h[S], d[S] = 0;
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
    for(int i = cur[u];~i&&flow<limit;i=ne[i]){
        int j = e[i];
        cur[u] = i;
        if(d[j]==d[u]+1&&f[i]){
            int t = find(j,min(f[i],limit-flow));
            if(!t) d[t] = -1;
            f[i] -= t, f[i^1] += t, flow += t;
        }
    }
    return flow;
}

int dinic(){
    int r = 0, flow;
    while(bfs()) while(flow = find(S,INF)) r += flow;
    return r;
}

int main(){
    memset(h,-1,sizeof(h));
    scanf("%d%d%d%d",&n,&m,&S,&T);
    while(m--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
    }
    printf("%d\n",dinic());
    for(int i = 0;i<idx;i+=2){
        if(!f[i]){
            printf("%d %d\n",e[i^1], e[i]);
        }
    }
}
```
