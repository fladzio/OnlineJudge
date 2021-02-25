#include <iostream>

int main()
{
	int h, w;
    char c;

	while(std::cin >> h >> w)
    {
        float area = 0;

        for(int i = 0; i < h; ++i)
        {
            bool start = false;
            for(int j = 0; j < w; ++j)
            {
                std::cin >> c;
                if(c == '\\' || c == '/')
                {
                    start = !start;
                    area += 0.5;
                }
                
                if(c == '.')
                    if(start)
                        area += 1;
            }
        }
        std::cout << area << std::endl;
    }

	return 0;
}