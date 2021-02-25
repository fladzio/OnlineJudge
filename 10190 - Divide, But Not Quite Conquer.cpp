#include <iostream>
#include <vector>
int main()
{
    unsigned int n, m;
    while(std::cin >> n >> m)
    {
        std::vector<int> val;
        bool boring = false;
        val.push_back(n);

        if(n == 0 || m == 0 || m == 1 || n == 1)
            boring = true;

        if(!boring)
        {
            while(n != 1)
            {
                if(n % m == 0)
                {
                    n = n / m;
                    val.push_back(n);
                }
                else
                {
                    boring = true;
                    break;
                }
            }
        }

        if(boring)
            printf("Boring!\n");
        else
        {
            for(int i = 0; i < val.size(); i++)
            {
                if(i == val.size() - 1)
                    printf("%d\n", val[i]);
                else
                    printf("%d ", val[i]);
            }
        }
    }
    return 0;
}
