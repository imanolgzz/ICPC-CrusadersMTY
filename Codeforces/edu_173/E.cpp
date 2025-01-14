// Editorial
#include<bits/stdc++.h>
 
using namespace std;
 
struct graph
{
    int V;
    vector<vector<int>> g;
    vector<int> color;
 
    bool dfs(int v)
    {
        if(color[v] != 0) return false;
        color[v] = 1;
        bool res = false;
        for(auto y : g[v])
        {
            if(color[y] == 2) continue;
            else if(color[y] == 0)
                res |= dfs(y);
            else res = true;
        }
        color[v] = 2;
        return res;
    }
 
    void add_edge(int x, int y)
    {
        g[x].push_back(y);
    }
 
    graph(int V)
    {
        this->V = V;
        this->g.resize(V);
        this->color.resize(V);
    };
};
 
int get_bit(int x, int y)
{
    return (x >> y) & 1;
}
 
bool check(const vector<vector<int>>& a, const vector<vector<int>>& b, int k)
{
    int n = a.size();
    int m = a[0].size();
    vector<bool> must_row(n);
    vector<bool> must_col(m);
    auto G = graph(n + m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            if(get_bit(a[i][j], k) != get_bit(b[i][j], k))
            {
                if(get_bit(b[i][j], k) == 0) must_row[i] = true;
                else must_col[j] = true;
            }
            if(get_bit(b[i][j], k) == 0) G.add_edge(j + n, i);
            else G.add_edge(i, j + n);
        }                 
    for(int i = 0; i < n; i++)
        if(must_row[i] && G.dfs(i))
            return false;
    for(int j = 0; j < m; j++)
        if(must_col[j] && G.dfs(j + n))
            return false;
    return true;
}
 
void solve()
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<int>> a(n, vector<int>(m));
    auto b = a;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &b[i][j]);
    for(int i = 0; i < 30; i++)
    {
        if(!check(a, b, i))
        {
            puts("No");
            return;
        }
    }
    puts("Yes");
}


void redirectIO(){
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
}

int main()
{                         
#ifndef ONLINE_JUDGE    
    redirectIO();
#endif
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++) solve();
}