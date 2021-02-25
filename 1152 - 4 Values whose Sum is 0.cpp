#include <iostream>
#include <vector>

#define MAX 100005

int HashNumber(int n)
{
	return abs(n) % MAX;
}

int main()
{
    int T;
    std::cin >> T;

    while(T--)
    {
        int mix, val, N, counter = 0;
        std::vector<int> all[MAX];
        std::cin >> N;
        int A[N], B[N], C[N], D[N];

        for(int i = 0; i < N; ++i)
            std::cin >> A[i] >> B[i] >> C[i] >> D[i];

        for(int i = 0; i < N; ++i)
        {
			for(int j = 0; j < N; ++j)
            {
				mix = A[i] + B[j];
				val = HashNumber(mix);
				all[val].push_back(mix);
			}
		}

		for(int i = 0; i < N; ++i)
        {
			for(int j = 0; j < N; ++j)
            {
				mix = -(C[i] + D[j]);
				val = HashNumber(mix);
				for(int k = 0; k < all[val].size(); ++k)
					if(all[val][k] == mix)
						counter++;
            }
        }

        std::cout << counter << std::endl;
    }
    return 0;
}