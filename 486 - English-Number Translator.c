#include <stdio.h>
#include <string.h>

int convert(char *x){
    if(strcmp(x, "zero") == 0) return 0;
    else if(strcmp(x, "one") == 0) return 1;
    else if(strcmp(x, "two") == 0) return 2;
    else if(strcmp(x, "three") == 0) return 3;
    else if(strcmp(x, "four") == 0) return 4;
    else if(strcmp(x, "five") == 0) return 5;
    else if(strcmp(x, "six") == 0) return 6;
    else if(strcmp(x, "seven") == 0) return 7;
    else if(strcmp(x, "eight") == 0) return 8;
    else if(strcmp(x, "nine") == 0) return 9;
    else if(strcmp(x, "ten") == 0) return 10;
    else if(strcmp(x, "eleven") == 0) return 11;
    else if(strcmp(x, "twelve") == 0) return 12;
    else if(strcmp(x, "thirteen") == 0) return 13;
    else if(strcmp(x, "fourteen") == 0) return 14;
    else if(strcmp(x, "fifteen") == 0 ) return 15;
    else if(strcmp(x, "sixteen") == 0 ) return 16;
    else if(strcmp(x, "seventeen") == 0 ) return 17;
    else if(strcmp(x, "eighteen") == 0 ) return 18;
    else if(strcmp(x, "nineteen") == 0 ) return 19;
    else if(strcmp(x, "twenty") == 0 ) return 20;
    else if(strcmp(x, "thirty") == 0 ) return 30;
    else if(strcmp(x, "forty") == 0 ) return 40;
    else if(strcmp(x, "fifty") == 0 ) return 50;
    else if(strcmp(x, "sixty") == 0 ) return 60;
    else if(strcmp(x, "seventy") == 0 ) return 70;
    else if(strcmp(x, "eighty") == 0 ) return 80;
    else if(strcmp(x, "ninety") == 0 ) return 90;
    else if(strcmp(x, "hundred") == 0 ) return 100;
    else if(strcmp(x, "thousand") == 0 ) return 1000;
    else if(strcmp(x, "million") == 0 ) return 1000000;
    else if(strcmp(x, "negative") == 0 ) return 99;
}

int main(){
    int lastval;

    char word[255];

    while(fgets(word,255,stdin)){
        int negative = 0;
        int suma = 0;
        int num = 0;

        word[strlen(word) - 1] = '\0';

        char *p = strtok(word, " ");

        while(p != NULL){
            if (convert(p) == 99)
                negative = 1;
            else if (convert(p) == 1000000)
            {
                suma += num * 1000000;
                num = 0;
            }
            else if (convert(p) == 1000)
            {
                suma += num * 1000;
                num = 0;
            }
            else if (convert(p) == 100)
            {
                num = num * 100;
            }
            else
            {
                num += convert(p);
            }

            p = strtok(NULL, " ");
        }
        suma += num;
        if(negative == 1) suma *= -1;
        printf("%d\n", suma);
    }

return 0;
}
