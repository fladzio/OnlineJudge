#include <iostream>
#include <queue>

struct Road
{
    int start, dest, length;

    bool operator<(const Road o) const
    {
        return length > o.length;
    }
};

int getGroup(int groups[], int start)
{
    if(groups[start] == start)
        return start;
    else
        return getGroup(groups, groups[start]);
}

int main()
{
    int m, n;
    while(std::cin >> m >> n)
    {
        if(m == 0 && n == 0) break;

        std::priority_queue<Road> roads;
        int groups[m];
        int originalCost = 0;
        int treeCost = 0;

        for(int i = 0; i < n; i++)
        {
            Road road;
            std::cin >> road.start >> road.dest >> road.length;
            originalCost += road.length;
            roads.push(road);
        }

        for(int i = 0; i < m; i++)
            groups[i] = i;

        while(!roads.empty())
        {
            Road road = roads.top();
            roads.pop();
            int groupStart = getGroup(groups, road.start);
            int groupDest = getGroup(groups, road.dest);

            if (groupStart != groupDest)
            {
                treeCost += road.length;
                groups[groupDest] = groupStart;
            }
        }
        std::cout << originalCost - treeCost << std::endl;
    }
    return 0;
}
