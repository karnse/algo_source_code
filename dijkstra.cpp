#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> g[100010];
int dijk[100010];
priority_queue<pair<int,int> > q;//max heap(sort with ) for dijkstra
int main()
{
    for(int i = 0;i < 100010; i++)
    {
        dijk[i] = 1e9;//initial distance
    }
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;//n is number of vertex, m is number of edge
    int s,t;//s is start vertex, t is end vertex
    for(int i = 0; i < m; i++)
    {
        int u,v,w;//u is first vertex, v is second vertex, w is weight
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    dijk[s] = 0;
    q.push({0,s});
    while(!q.empty())
    {
        int u = q.top().second;
        int w = -q.top().first;
        q.pop();
        if(dijk[u] < w) continue;
        for(int i = 0; i < g[u].size(); i++)//try all edge from vertex u
        {
            int v = g[u][i].first;
            int nw = g[u][i].second + w;
            if(nw < dijk[v])//relax if it is better
            {
                dijk[v] = nw;
                q.push({-nw,v});
            }
        }
    }
    cout<<dijk[t]<<endl;//print shortest path from s to t
    return 0;
}