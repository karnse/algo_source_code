#include<bits/stdc++.h>
using namespace std;
int mark[100010];
vector<pair<int,int>> g[100010];
priority_queue<pair<int,pair<int,int> > > q;//max heap(sort edge with weight with log(n) in each update) for prim
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
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(auto x: g[0])//try all edge from some vertex(in this case 0)
    {
        int v = x.first;
        int w = x.second;
        q.push({-w,{0,v}});
    }
    int ans=0;
    while(!q.empty())
    {
        int u = q.top().second.first;
        int v = q.top().second.second;
        int w = -q.top().first;
        q.pop();
        if(mark[v]) continue;//if v is already in MST
        mark[v] = 1;//mark v as in MST
        cout<<u<<" "<<v<<" "<<w<<endl;//print edge
        ans+=w;//add weight to answer
        for(auto x: g[v])//try all edge from vertex v
        {
            int v = x.first;
            int w = x.second;
            if(!mark[v]) q.push({-w,{v,u}});
        }
    }
    cout<<ans<<endl;//print total weight of MST
    return 0;
}