#include <iostream>
#include <cmath>

#define MAX 10000

int main()
{
    int T, N, R;
    int cases = 1;
	int s, d;

    std::cin >> T;
    while(T--)
    {
		std::cin >> N >> R;

        int connections[N][N];

		for(int i = 0; i < N; ++i)
		{
			for(int j = 0; j < N; ++j)
			{
				if(i == j)
					connections[i][j] = 0;
				else
					connections[i][j] = MAX;
			}
		}

        for(int i = 0; i < R; ++i)
        {
            int u, v;
            std::cin >> u >> v;

            connections[u][v] = 1;
            connections[v][u] = 1;
        }

		// Floyd
        for(int k = 0; k < N; ++k)
            for(int i = 0; i < N; ++i)
                for(int j = 0; j < N; ++j)
                    connections[i][j] = std::min(connections[i][j], connections[i][k] + connections[k][j]);

		std::cin >> s >> d;

        int time = 0;

        for(int i = 0; i < N; ++i)
            if(connections[s][i] != MAX && connections[i][d] != MAX)
                time = std::max(time, connections[s][i] + connections[i][d]);

        std::cout << "Case " << cases++ << ": " << time << std::endl;
    }
    return 0;
}