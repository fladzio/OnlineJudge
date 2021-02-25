#include <iostream>
#include <string>

void isValid(std::string c)
{
    int step1 = 0, step2 = 0;
    int x;
    std::string xd;

    for(int i = 0; i < c.size(); i++)
    {
        if(i % 2 == 0)
        {
            xd = std::to_string((c[i] - '0') * 2);

            for(int j = 0; j < xd.size(); j++)
            {
                step1 += xd[j] - '0';
            }
        }
        else
        {
            step2 += c[i] - '0';
        }
    }

    xd = std::to_string(step1 + step2);
    if(xd[xd.size() - 1] == '0')
        std::cout << "Valid\n";
    else
        std::cout << "Invalid\n";
}

int main()
{
    std::string card, q1, q2, q3, q4;
    int cases;

    std::cin >> cases;
    while(cases--)
    {
        std::cin >> q1 >> q2 >> q3 >> q4;
        card = q1 + q2 + q3 +q4;

        isValid(card);
    }

    return 0;
}
