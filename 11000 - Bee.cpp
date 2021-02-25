#include <iostream>

int main()
{
    int N;
    while(true)
    {
        std::cin >> N;
        if(N == -1)
            return 0;

        int male = 0;
        int last_male = 0;
        long long int sum = 1;
        for(int i = 0; i < N; i++)
        {
            last_male = male;
            male = sum;
            sum += last_male + 1;
        }
        printf("%d %lld\n", male, sum);
    }
}