```c++
#include <bits/stdc++.h>
using namespace std;
const int N = 2010, M = 44010, INF = 1e9;

int n,m,c,need = 0,S,T;
int h[N],e[M],ne[M],f[M],idx;
int cur[N],d[N],q[N];
int wp[N],wr[N];
struct Edge{
    int u,v,w;
}edges[M];

void add(int a,int b,int c){
    e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a] = idx++;
    e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx++;
}

void build(int mid){
    memset(h,-1,sizeof(h));
    idx = 0;
    for(int i = 1;i<=m;i++){
        add(S,i,wr[i]);
    }
    for(int i = 1;i<=n;i++){
        add(i+m,T,wp[i]);
    }
    for(int i = 1;i<=c;i++){
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if(w<=mid) add(u,v+m,INF);
    }
//    for(int i = 0;i<idx;i+=2){
//        cout<<e[i^1]<<' '<<e[i]<<endl;
//    }
}

bool bfs(){
    memset(d,-1,sizeof(d));
    int hh = 0, tt = 0;
    q[0] = S, d[S] = 0, cur[S] = h[S];
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
            if(!t) d[j] = -1;
            f[i] -= t, f[i^1] += t, flow += t;
        }
    }
    return flow;
}

int dinic(int mid){
    build(mid);
    int r = 0, flow;
    while(bfs()) while(flow = find(S,INF)) r += flow;
    if(r==need) return true;
    else return false;
}

int main(){
    //freopen("1.txt","r",stdin);
    memset(h,-1,sizeof(h));
    scanf("%d%d%d",&n,&m,&c);
    S = 0, T = n + m + 1;
    for(int i = 1;i<=n;i++){
        scanf("%d",&wp[i]);
        need += wp[i];
    }
    for(int i = 1;i<=m;i++) scanf("%d",&wr[i]);
    int time = 0;
    for(int i = 1;i<=c;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        edges[i] = {v,u,w};
        time = max(time,w);
    }

    int l = 0,r = time;
    if(!dinic(r)){
        puts("-1");
        return 0;
    }
    else{
        while(l<r){
            int mid = l + r >> 1;
            if(dinic(mid)) r = mid;
            else l = mid + 1;
        }
        printf("%d\n",r);
    }
}
```
