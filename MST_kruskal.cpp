#include<bits/stdc++.h>
using namespace std;
int par[100010];
priority_queue<pair<int,pair<int,int> > > q;//max heap(sort edge with weight with log(n) in each update) for kruskal
int find(int x)
{
    if(par[x] == x) return x;
    return par[x] = find(par[x]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;//n is number of vertex, m is number of edge
    for(int i = 0; i < m; i++)
    {
        int u,v,w;//u is first vertex, v is second vertex, w is weight
        cin>>u>>v>>w;
        q.push({-w,{u,v}});
    }
    for(int i = 0; i < 100010; i++)
    {
        par[i] = i;//initial parent of each vertex is itself
    }
    int ans = 0;
    while(!q.empty())
    {
        int u = q.top().second.first;
        int v = q.top().second.second;
        int w = -q.top().first;
        q.pop();
        if(find(u) != find(v))//if u and v are not in the same set
        {
            par[find(u)] = find(v);//merge u and v
            cout<<u<<" "<<v<<" "<<w<<endl;//print edge
            ans+=w;//add weight to answer
        }
    }
    cout<<ans<<endl;//print total weight of MST
    return 0;
}