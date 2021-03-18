#include <iostream>
#include <string>

int main()
{
    int T, cases = 0;

    while(std::cin >> T && T != 0)
    {
        int numbers[T];
        for(int i = 0; i < T; i++)
            std::cin >> numbers[i];

        std::cout << "Case " << ++cases << ':' << std::endl;

        for(int i = 0; i < T; i++)
        {
            if(numbers[i] + 1 != numbers[i + 1])
            {
                std::cout << '0' << numbers[i] << std::endl;
            }
            else
            {
                int range = 1;
                while(numbers[i] + range == numbers[i + range])
                    range++;

                std::string s1 = std::to_string(numbers[i]);
                std::string s2 = std::to_string(numbers[i + range - 1]);

                int index = 0;
                for(int k = 0; k < s1.length(); k++)
                {
                    if(s1[k] != s2[k])
                    {
                        index = k;
                        break;
                    }
                }

                std::string ret = s2.substr(index);

                std::cout << '0' << numbers[i] << '-' << ret << std::endl;
                i += range - 1;
            }
        }
        std::cout << "\n";
    }

    return 0;
}
