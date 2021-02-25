#include <iostream>

int findParent(int parent[], int len[], int I)
{
	if(I == parent[I])
        return I;

	int p = findParent(parent, len, parent[I]);
	len[I] += len[parent[I]];
	parent[I] = p;

	return parent[I];
}

int main()
{
    int T;
    std::cin >> T;
    while(T--)
    {
        int N;
        std::string command;
        std::cin >> N;
        int len[N + 1];
        int parent[N + 1];

        for(int i = 1; i <= N; i++)
        {
			parent[i] = i;
			len[i] = 0;
        }

        while(std::cin >> command)
        {
            if(command[0] == 'O')
                break;
            else if(command[0] == 'I')
            {
                int I, J;
                std::cin >> I >> J;
                parent[I] = J;
				len[I] = abs(I - J) % 1000;
            }
            else
            {
                int I;
                std::cin >> I;
				findParent(parent, len, I);
				std::cout << len[I] << "\n";
            }
        }
    }

    return 0;
}