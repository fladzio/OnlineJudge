#include <iostream>
#include <vector>
#include <cmath>

#define MAX 10000

int start;

int getPosition(std::string names[], int arrSize, std::string str)
{
    for(int i = 0; i < arrSize; ++i)
        if(names[i] == str)
            return i;

    names[start] = str;
    return start++;
}

int main()
{
    int P, R;
    int cases = 1;

    while(std::cin >> P >> R)
    {
        if(P == 0 && R == 0)
            break;

        start = 0;

        std::string names[P];
        std::vector<std::vector<int>> connections(P, std::vector<int>(P, MAX));

        for(int i = 0; i < R; ++i)
        {
            std::string str1, str2;
            std::cin >> str1 >> str2;

            int pos1 = getPosition(names, P, str1);
            int pos2 = getPosition(names, P, str2);

            connections[pos1][pos2] = 1;
            connections[pos2][pos1] = 1;
        }

        for(int k = 0; k < P; ++k)
            for(int i = 0; i < P; ++i)
                for(int j = 0; j < P; ++j)
                    connections[i][j] = std::min(connections[i][j], connections[i][k] + connections[k][j]);

        int farthest = 0;

        for(int i = 0; i < P; ++i)
            for(int j = i + 1; j < P; ++j)
                farthest = std::max(connections[i][j], farthest);

        std::cout << "Network " << cases++ << ": ";

        if(farthest == MAX)
            std::cout << "DISCONNECTED\n";
        else
            std::cout << farthest << '\n';

        std::cout << '\n';
    }
    return 0;
}