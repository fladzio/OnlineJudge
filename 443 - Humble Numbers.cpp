#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define MAX 2000000000
#define PRECISION 31

std::vector<int> create()
{
    std::vector<int> vec;

    for (int i = 0; i < PRECISION; i++)
        for (int j = 0; j < PRECISION; j++)
            for (int k = 0; k < PRECISION; k++)
                for (int m = 0; m < PRECISION; m++)
                {
                    int  number = std::pow(2, i) * std::pow(3, j) * std::pow(5, k) * std::pow(7, m);

                    if (number > MAX || number < 0)
                        break;

                    vec.push_back(number);
                }

    std::sort(vec.begin(), vec.end());

    return vec;
}

int main()
{
    std::vector<int> humble = create();

    int N;
    while (std::cin >> N)
    {
        if(N == 0)
            break;

        int reminder = N % 100;
        std::string ending;

        if(reminder > 10 && reminder < 20)
            ending = "th";
        else if (N % 10 == 1)
            ending = "st";
        else if (N % 10 == 2)
            ending = "nd";
        else if (N % 10 == 3)
            ending = "rd";
        else
            ending = "th";

        std::cout << "The " << N << ending << " humble number is " << humble[N - 1] << ".\n";
    }
    return 0;
}
