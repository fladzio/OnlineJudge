#include <iostream>
#include <string> 
#include <sstream>

int m, n;
int number;
int last_pos = - 1;
int val = -1;
int matrix[27][27];
bool visited[27][27];
bool hit[27][27];

void clearVisited()
{
    for(int i = 0; i < 27; i++)
        for(int j = 0; j < 27; j++)
            visited[i][j] = false;
}

bool hitEdge(int i, int j)
{
    if(matrix[i][j] && !visited[i][j])
    {
        visited[i][j] = true;

        if(i == 0 || i == 26 || j == 0 || j == 26)
            return true;

        bool ret1, ret2, ret3, ret4;

        ret1 = hitEdge(i - 1, j);
        if(ret1) return true;

        ret2 = hitEdge(i + 1, j);
        if(ret2) return true;

        ret3 = hitEdge(i, j - 1);
        if(ret3) return true;

        ret4 = hitEdge(i, j + 1);
        if(ret4) return true;
    }

    return false;
}

void drawRow1(int i, int j, bool lastColumn)
{
    int value = matrix[i][j];
    std::string ret = "";

    // 1st line
    if(value == 1)
    {
        if(matrix[i][j - 1] == 1)
        {
            if(matrix[i - 1][j] == 1)
            {
                if(matrix[i - 1][j - 1] == 1)
                    ret = "     ";
                else
                    ret = "+    ";
            }
            else
                ret = "+++++";
        }
        else
        {
            if(matrix[i - 1][j] == 1)
                ret = "+    ";
            else
                ret = "+++++";
        }

        if(!hit[i - 1][j] && i != 1)
            ret = "+++++";
    }
    else
    {
        ret = "+++++";
    }

    if(lastColumn)
    {
        if(matrix[i - 1][j] == 0 || value == 0)
            ret += "+";
        else
            ret += " ";
    }

    std::cout << ret;
}

void drawRow2(int i, int j, bool lastColumn)
{
    int value = matrix[i][j];
    std::string ret = "";

    // 2nd line
    if(value == 1)
    {
        //2 18 19
        //if((i == 2 && j == 19) || (i == 2 && j == 18))
            //std::cout << !hit[i][j];

        if((matrix[i][j - 1] == 0 && matrix[i][j + 1] == 0 && matrix[i - 1][j] == 0 && matrix[i + 1][j] == 0) || !hit[i][j])
            ret = "+++++";
        else if(matrix[i][j - 1] == 1)
            ret = "     ";
        else
            ret = "+    ";
    }
    else
    {
        // sprawdzenie czy mozna wpisac liczbe
        if((matrix[i + 1][j] == 0 && matrix[i - 1][j] == 1) || (matrix[i][j - 1] == 1 && matrix[i][j + 1] == 0))
        {
            std::stringstream s;
            s << number++;
            std::string str = s.str();
            ret = "+";

            for(int k = 0; k < 3 - str.size(); k++)
                ret += "0";

            ret += str + " ";
        }
        else
            ret = "+    ";
    }

    if(lastColumn)
    {
        if(value)
            ret += " ";
        else
            ret += "+";
    }

    std::cout << ret;
}

void drawRow3(int i, int j, bool lastColumn)
{
    int value = matrix[i][j];
    std::string ret = "";

    // 3rd line
    if(value == 1)
    {
        if((matrix[i][j - 1] == 0 && matrix[i][j + 1] == 0 && matrix[i - 1][j] == 0 && matrix[i + 1][j] == 0) || !hit[i][j])
            ret = "+++++";
        else if(matrix[i][j - 1] == 1)
            ret = "     ";
        else
            ret = "+    ";
    }
    else
    {
        ret = "+    ";
    }

    if(lastColumn)
    {
        if(value)
            ret += " ";
        else
            ret += "+";
    }

    std::cout << ret;
}

void drawRow4(int i)
{
    if(val != -1)
    {
        for (int j = 1; j <= val; j++)
        { 
            int value = matrix[i][j];
            std::string ret = "";

            // 4th line
            if(value == 1)
            {
                if(matrix[i][j - 1] == 1)
                    ret = "     ";
                else
                    ret = "+    ";
            }
            else
            {
                ret = "+++++";
            }

            // lastColumn
            if(j == val)
            {
                if(value == 0)
                    ret += "+";
                else
                    ret += " ";
            }

            std::cout << ret;
        }
    }

    std::cout << std::endl << std::endl;
}

void drawFullRow(int i)
{
    val = -1;

    for(int j = 1; j <= n; j++)
    {
        if(matrix[i][j] == 0)
            val = j;
    }

    int pos = std::max(val, last_pos);

    for(int j = 1; j <= pos; j++)
    {
        if(j == pos)
            drawRow1(i, j, true);
        else   
            drawRow1(i, j, false); 
    }

    std::cout << std::endl;

    for(int j = 1; j <= val; j++)
    {
        if(j == val)
            drawRow2(i, j, true);
        else   
            drawRow2(i, j, false); 
    }

    std::cout << std::endl;

    for(int j = 1; j <= val; j++)
    {
        if(j == val)
            drawRow3(i, j, true);
        else   
            drawRow3(i, j, false); 
    }

    std::cout << std::endl;

    if(i == m)
        drawRow4(i);

    last_pos = val;
}

int main()
{
    while(std::cin >> m >> n)
    {
        if(m == 0 && n == 0)
            break;

        // zerowanie
        number = 1;
        last_pos = - 1;
        val = -1;

        for(int i = 0; i < 27; i++)
            for(int j = 0; j < 27; j++)
                hit[i][j] = false;       

        // otoczka
        for(int i = 0; i < 27; i++)
        {
            matrix[i][0] = 1;
            matrix[i][n + 1] = 1;
            matrix[0][i] = 1;
            matrix[m + 1][i] = 1;
        }

        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
                std::cin >> matrix[i][j];

        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(matrix[i][j] == 1)
                {
                    clearVisited();
                    if(hitEdge(i, j))
                        hit[i][j] = true;
                }
            }
        }
    
        for(int i = 1; i <= m; i++)
           drawFullRow(i);
    }

    return 0;
}