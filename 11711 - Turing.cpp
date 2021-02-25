#include <iostream>
#include <vector>

#define MAX 1001

int main()
{
    int N, M, X, Y;
    int qp, cp, qn, cn;
    char move;

    while(std::cin >> N >> M)
    {
        if(N == 0 && M == 0)
            break;

        std::vector<std::vector<std::vector<int>>> q(MAX);

        for(int i = 0; i < N; i++)
        {
            std::cin >> qp >> cp >> qn >> cn >> move;
            std::vector<int> v;
            v.push_back(cp);
            v.push_back(qn);
            v.push_back(cn);
            
            if(move == 'R')
                v.push_back(1);
            else
                v.push_back(0);

            q[qp].push_back(v);
        }

        for(int i = 0; i < M; i++)
        {
            std::string tape = "";
            int current_q = 0, current_pos = 0, it = 0, ret = 0;

            std::cin >> X >> Y;
            for(int j = 0; j < MAX; j++)
                (j < X) ? tape += "1" : tape += "0";

            while(true)
            {
                it++;
                if(current_pos < 0 || current_pos >= MAX)
                {
                    ret = 4;
                    break;
                }

                int val = tape[current_pos] - '0';

                if(q[current_q].size() == 0)
                {
                    int cnt = 0;
                    for(int j = 0; j < MAX; j++)
                    {
                        if(tape[j] == '1')
                            cnt++;
                        else
                            break;
                    }

                    if(cnt == Y)
                    {
                        ret = 1;
                        break;
                    }
                    else
                    {
                        ret = 2;
                        break;
                    }
                    
                }

                for(int j = 0; j < q[current_q].size(); j++)
                {
                    if(q[current_q][j][0] == val)
                    {
                        tape[current_pos] = q[current_q][j][2] + '0';

                        if(q[current_q][j][3] == 1)
                            current_pos++;
                        else
                            current_pos--;

                        current_q = q[current_q][j][1];
                        break;
                    }
                }

                if(it >= 10000)
                {
                    ret = 3;
                    break;
                }
            }

            if(ret == 1)
                std::cout << "AC\n";
            else if(ret == 2)
                std::cout << "WA\n";
            else if(ret == 3)
                std::cout << "TLE\n";
            else if(ret == 4)
                std::cout << "MLE\n";
        }
    }

    return 0;
}