#include <iostream>

int main()
{
    int N;
    while(true)
    {
        std::cin >> N;
        if(N == 0)
            return 0;

        int final_streak = 0;
        int current_streak = 0;
        int num;
        while(N--)
        {
            std::cin >> num;
            if(current_streak + num >= 0)
            {
                current_streak += num;
                if(current_streak > final_streak)
                    final_streak = current_streak;
            }
            else
            {
                if(current_streak > final_streak)
                    final_streak = current_streak;
                current_streak = 0;
            }
        }
        if(current_streak > final_streak)
            final_streak = current_streak;

        if(final_streak > 0)
            printf("The maximum winning streak is %d.\n", final_streak);
        else
            printf("Losing streak.\n");
    }
}
