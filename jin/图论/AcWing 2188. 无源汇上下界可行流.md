```c++
#include <bits/stdc++.h>
using namespace std;
const int N = 210, M = (10200+N)*2, INF = 1e8;

int n,m,S,T;
int h[N],e[M],ne[M],f[M],l[M],idx;
int q[N],d[N],cur[N],A[N];

void add(int a,int b,int c,int d){
    e[idx] = b, f[idx] = d - c, l[idx] = c, ne[idx] = h[a], h[a] = idx++;
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
            int t = find(j,min(f[i],limit-flow));
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
    scanf("%d%d",&n,&m);
    S = 0, T = n + 1;
    for(int i = 0;i<m;i++){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        add(a,b,c,d);
        A[a] -= c, A[b] += c;
    }
    int tot = 0;
    for(int i = 1;i<=n;i++){
        if(A[i]>0) add(S,i,0,A[i]), tot += A[i];
        else if(A[i]<0) add(i,T,0,-A[i]);
    }
    if(dinic()!=tot) puts("NO");
    else{
        puts("YES");
        for(int i = 0;i<m*2;i+=2){
            printf("%d\n",f[i^1]+l[i]);
        }
    }
}
```
