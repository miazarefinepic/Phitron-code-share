#include<bits/stdc++.h>
using namespace std;
int par[100005];
int group_size[100005];
void dsu_int(int n){
    for(int i=1;i<=n;i++){
        par[i] = -1;
        group_size[i] = 1;
    }
}
int dsu_find(int node)
{
    if(par[node] == -1) 
        return node;
    int leader = dsu_find(par[node]);
    par[node] = leader;
    return leader;
}

void dsu_union(int node1, int node2)
{
    int leader1 = dsu_find(node1);
    int leader2 = dsu_find(node2);
    if(group_size[leader1] >= group_size[leader2])
    {
        par[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
    }
    else
    {
        par[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
    }
}
int main()
{
    int n,e;
    cin >> n >> e;
    dsu_int(n);
    while(e--){
        int u,v;
        cin >> u >> v;
        int leaderU = dsu_find(u);
        int leaderV = dsu_find(v);
        if(leaderU != leaderV){
            dsu_union(u,v);
        }
    }
    int cnt = 0;
    vector<int> ans;
    for(int node=1;node<=n;node++){
        int leader_1 = dsu_find(1);
        int leader_node = dsu_find(node);
        if(leader_1 != leader_node){
            dsu_union(1,node);
            cnt++;
            ans.push_back(node);
        }
    }
    cout << cnt << endl;
    for(auto it : ans){
        cout << 1 << " " << it << endl;
    }
    return 0;
}