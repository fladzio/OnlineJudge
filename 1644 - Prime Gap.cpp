#include <iostream>

#define N 1299709

bool prime[N];

void sito()
{
    for (int i = 2; i * i <= N; i++) 
    {							
        if (!prime[i])
		    for (int j = i * i ; j <= N; j += i)
                prime[j] = true;
    }
}

int range(int n)
{
    int left = n;
    int right = n;

    if(!prime[n])
        return 0;

    while(left--)
    {
        if(!prime[left])
            break;
    }

    while(right++)
    {
        if(!prime[right])
            break;
    }

    return right - left;
}

int main()
{
    int n;
    sito();

    while(std::cin >> n && n != 0)
    {
        std::cout << range(n) << std::endl;
    }

    return 0;
}