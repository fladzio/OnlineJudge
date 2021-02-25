#include <iostream>
#include <algorithm>
#include <vector>

bool prefixCheck(std::string a, std::string b)
{
    if(b.length() < a.length())
        return false;

    for(int i = 0; i < a.length(); i++)
    {
        if(a[i] != b[i])
            return false;
    }

    return true;
}
int main()
{
    int t, n;
    std::string phone;
    
    std::cin >> t;
    while(t--)
    {
        std::vector<std::string> phone_list;
        std::cin >> n;
        for(int i = 0; i < n; i++)
        {
            std::cin >> phone;
            phone_list.push_back(phone);
        }

        std::sort(phone_list.begin(), phone_list.end());

        bool checker = true;

        for(int i = 0; i < n - 1; i++)
        {
            if(prefixCheck(phone_list[i], phone_list[i + 1]))
            {
                checker = false;
                break;
            }
        }

        if(checker)
            std::cout<<"YES\n";
        else
            std::cout<<"NO\n";
    }
    return 0;
}