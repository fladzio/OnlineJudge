#include <iostream>

int main()
{
    int N, S;

    while(std::cin >> N >> S)
    {
        int arr[N];
        int current_sum = 0;
        int ret = N + 1;

        for(int i = 0; i < N; ++i)
            std::cin >> arr[i];

        for(int i = 0; i < N; ++i)
        {
            current_sum = arr[i];
            if(current_sum >= S)
            {
                ret = 1;
                break;
            }

            for(int j = i + 1; j < N; ++j)
            {
                current_sum += arr[j];

                if(current_sum >= S)
                {
                    if((j + 1 - i) < ret)
                        ret = j + 1 - i;
                    break;
                }
            }
        }

        if(ret == N + 1)
            ret = 0;

        std::cout << ret << "\n";
    }

    return 0;
}