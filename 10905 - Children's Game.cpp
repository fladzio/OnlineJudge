#include <iostream>
#include <vector>
#include <algorithm>

bool comp(std::string s1, std::string s2)
{
    return s2 + s1 < s1 + s2;
}

int main()
{
    int N;
    std::string val;

    while (std::cin >> N)
    {
        if(N == 0) break;

        std::string comm;
        std::vector<std::string> numbers;

        for (int i = 0; i < N; i++)
        {
            std::cin >> val;
            numbers.push_back(val);
        }

        sort(numbers.begin(), numbers.end(), comp);

        for(int i = 0; i < numbers.size(); i++)
        {
            comm += numbers[i];
        }
        std::cout << comm << std::endl;
    }
    return 0;
}
