```c++
#include <bits/stdc++.h>
using namespace std;
const int N = 220, M = (10010+N)*2, INF = 1e8;

int n,m,S,T;
int h[N], e[M], f[M], ne[M], idx;
int q[N], d[N], cur[N], A[N];

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
    for(int i = cur[u];~i&&flow<limit;i=ne[i]){
        int j = e[i];
        cur[u] = i;
        if(d[j]==d[u]+1&&f[i]){
            int t = find(j,min(limit-flow, f[i]));
            if(!t) d[j] = -1;
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
    int s,t;
    scanf("%d%d%d%d",&n,&m,&s,&t);
    S = 0, T = n + 1;
    for(int i = 0;i<m;i++){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        add(a,b,d-c);
        A[a] -= c, A[b] += c;
    }
    int tot = 0;
    for(int i = 1;i<=n;i++){
        if(A[i]>0) add(S,i,A[i]), tot += A[i];
        else if(A[i]<0) add(i,T,-A[i]);
    }
    add(t,s,INF);
    if(dinic()!=tot) puts("No Solution");
    else{
        int res = f[idx-1];
        f[idx-1] = f[idx-2] = 0;
        S = s, T = t;
        printf("%d\n",res + dinic());
    }
}
```
