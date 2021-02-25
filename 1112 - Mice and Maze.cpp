#include <iostream>
#include <vector>

#define N_MAX 100
#define INF 99999

int main()
{
    int vis[N_MAX + 1][N_MAX + 1];
    int N, E, T, M;
	int cases;

	std::cin >> cases;

	while(cases--)
    {
		std::cin >> N >> E >> T >> M;

		for(int i = 1; i <= N ; ++i)
			for(int j = 1; j <= N; ++j)
				vis[i][j] = INF;

		for(int i = 1; i <= N; ++i)
            vis[i][i] = 0;

		for(int i = 0; i < M; ++i)
        {
			int a, b, t;
			std::cin >> a >> b >> t;
			vis[a][b] = t;
		}

		// Algorytm floyda
        for(int k = 1; k <= N; ++k)
            for(int i = 1; i <= N; ++i)
                for(int j = 1; j<= N; ++j)
                    vis[i][j] = std::min(vis[i][j], vis[i][k] + vis[k][j]);

		int ret = 0;
		for(int i = 1; i <= N; ++i)
			if(vis[i][E] <= T)
                ret++;

		std::cout << ret;
		if(cases)
            std::cout << "\n\n";
        else
            std::cout << "\n";
	}
	return 0;
}