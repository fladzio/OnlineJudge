#include <iostream>

int main()
{
    int cases;
    std::cin >> cases;
    while(cases--)
    {
        int out = 0, val = 0;
        std::string input;
        std::cin >> input;
        for(auto &i : input)
        {
            if(i == 'O')
                val++;
            else if(i == 'X')
                val = 0;

            out += val;
        }
        printf("%d\n", out);
    }
    return 0;
}