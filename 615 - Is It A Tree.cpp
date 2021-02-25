#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#define maxi 100

std::vector<int> edges[maxi];
bool visited[maxi];
int in[maxi];
int cnt;
bool cycle;


void Dfs(int x)
{
    visited[x] = true;
    cnt++;
    for(std::vector<int>::iterator i = edges[x].begin(); i != edges[x].end(); i++)
    {
        if(!visited[*i])
            Dfs(*i);
        else
            cycle = true;
    }
}
int main()
{
    int u , v , cs = 1;
    while(true)
    {
        memset(in,0,sizeof in);
        std::map<int,int> M;
        int n = 0;
        for(int i = 0; i <= maxi - 1; i++)
        {
            edges[i].clear();
            visited[i] = false;
        }

        while(std::cin >> u >> v)
        {
            if(u == 0 && v == 0) break;
            if(u == -1 && v == -1) return 0;
            if(!M[u]) M[u] = ++n;
            if(!M[v]) M[v] = ++n;

            edges[M[u]].push_back(M[v]);
            in[M[v]]++;
        }
        cycle = false;
        cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            if(in[i] == 0)
            {
                Dfs(i);
                break;
            }
        }
        if(cnt == n  && !cycle)
            std::cout << "Case " << cs++ << " is a tree.\n";
        else
            std::cout << "Case " << cs++ << " is not a tree.\n";
    }
}
