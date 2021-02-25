#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>

bool isPrime(int n)
{
    for(int i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    std::string str, reverse_str;
    while(std::cin >> str)
    {
        int N = atoi(str.c_str());
        std::reverse(str.begin(), str.end());
        int reverse_N = atoi(str.c_str());

        bool prime = isPrime(N);
        if(prime && isPrime(reverse_N) && N != reverse_N)
            printf("%d is emirp.\n", N);
        else if(prime)
            printf("%d is prime.\n", N);
        else
            printf("%d is not prime.\n", N);
    }
    return 0;
}
