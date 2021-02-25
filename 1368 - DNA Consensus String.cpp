#include <iostream>
#include <vector>
#include <bits/stdc++.h>

int main()
{
    int T;
    std::vector<char> values = {'A', 'C', 'G', 'T'};
    std::cin >> T;

    while(T--)
    {
        int n, m;
        std::cin >> m >> n;

        std::vector<std::string> DNA;
        std::string ret = std::string(n, ' ');

        for(int i = 0; i < m; ++i)
        {
            std::string code;
            std::cin >> code;
            DNA.push_back(code);
        }
        int counter = 0;

        for(int i = 0; i < n; ++i)
        {
            int summary[4] = {0};

            for(int j = 0; j < m; ++j)
                summary[find(values.begin(), values.end(), DNA[j][i]) - values.begin()]++;

            int val = 0;

            for(int k = 0; k < 4; ++k)
                if(summary[k] > val)
                    val = summary[k];

            if(summary[0] == val) ret[i] = 'A';
            else if(summary[1] == val) ret[i] = 'C';
            else if(summary[2] == val) ret[i] = 'G';
            else if(summary[3] == val) ret[i] = 'T';

            counter += summary[0] + summary[1] + summary[2] + summary[3] - val;
        }
        std::cout << ret << std::endl << counter << std::endl;
    }
    return 0;
}