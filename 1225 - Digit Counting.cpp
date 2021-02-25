#include <iostream>
#include <string>

int main()
{
    int cases;

    std::cin >> cases;
    while(cases--)
    {
        int sum[10] = {0};
        int N;
        std::cin >> N;

        while(N != 0)
        {
            std::string str = std::to_string(N);
            for(auto s : str)
                sum[s - '0']++;

            N--;
        }

        for(int i = 0; i <= 9; ++i)
        {
            if(i == 9)
                std::cout << sum[i] << "\n";
            else
                std::cout << sum[i] << " ";
        }
    }

    return 0;
}