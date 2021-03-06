#include <iostream>
#include <queue>
#include <algorithm>

int timeArrive[10004];
int timeLeave[10004];
std::queue<int> Q[2];

int main()
{
    int test;
    int N, T, M;
    int minute;
    std::string side;

    std::cin >> test;
    while(test--)
    {
        std::cin >> N >> T >> M;
        for(int i = 0; i < M; i++)
        {
            std::cin >> minute >> side;
            timeArrive[i] = minute;
            if(side == "left") Q[0].push(i);
            else Q[1].push(i);
        }
        int actualTime = 0;
        int actualSide = 0;
        while(!Q[0].empty() || !Q[1].empty())
        {
            int next = Q[0].empty() ? timeArrive[Q[1].front()] :
                       Q[1].empty() ? timeArrive[Q[0].front()] :
                       std::min( timeArrive[Q[0].front()], timeArrive[Q[1].front()]);
            actualTime = std::max(actualTime, next);
            int cnt = 0;
            while (!Q[actualSide].empty() && timeArrive[Q[actualSide].front()]<=actualTime && cnt < N)
            {
                timeLeave[ Q[actualSide].front() ] = actualTime + T;
                cnt++;
                Q[actualSide].pop();
            }
            actualTime += T;
            actualSide = (actualSide + 1) % 2;
        }
        for(int i  =0; i < M; i++) std::cout << timeLeave[i] << std::endl;
        if (test) std::cout << std::endl;
    }

    return 0;
}
