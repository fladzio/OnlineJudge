#include <iostream>
#include <cstdlib>
#include <ctime>

int *tab = new int[20];
int *help = new int[20];

int index(int *a)
{
    int i;
    for(i = 0; i < 20; i++)
    {
        if(a == &tab[i])
        {
            return i;
        }
    }
}

void quickSort(int *lewy, int *prawy)
{
    int start = index(lewy);
    int finish = index(prawy);
    int i, j, piwot;

    i = (start + finish) / 2;
    piwot = tab[i];
    tab[i] = tab[finish];
    for(j = i = start; i < finish; i++)
    if(tab[i] < piwot)
    {
        std::swap(tab[i], tab[j]);
        j++;
    }
    tab[finish] = tab[j];
    tab[j] = piwot;
    if(start < j - 1)  quickSort(&tab[start], &tab[j - 1]);
    if(j + 1 < finish) quickSort(&tab[j + 1], &tab[finish]);
}

void bubbleSort(int *lewy, int *prawy)
{
    int start = index(lewy);
    int finish = index(prawy);

    for (int i = start; i < finish; i++)
        for (int j = start; j < finish; j++)
            if (tab[j] > tab[j+1])
                std::swap(tab[j], tab[j+1]);
}

void mergeSort(int *lewy, int *prawy)
{
    int start = index(lewy);
    int finish = index(prawy);
    int i_s, i1, i2, i;

    i_s = (start + finish + 1) / 2;

    if(i_s - start > 1)
        mergeSort(&tab[start], &tab[i_s - 1]);

    if(finish - i_s > 0)
        mergeSort(&tab[i_s], &tab[finish]);

    i1 = start; i2 = i_s;

    for(i = start; i <= finish; i++)
        help[i] = ((i1 == i_s) || ((i2 <= finish) && (tab[i1] > tab[i2]))) ? tab[i2++] : tab[i1++];
    for(i = start; i <= finish; i++)
        tab[i] = help[i];
}

int main(){

    srand(time(NULL));

    for(int i = 0; i < 20; i++){
    	tab[i] = (( std::rand() % 1000 ) + 1 );
    }

    std::cout << "Tablica startowa: \n";
    for(int i = 0; i < 20; i++){
        if(i == 19){
            std::cout << tab[i] << std::endl << std::endl;
        }else{
            std::cout << tab[i] << ", ";
        }
    }

    quickSort(&tab[0], &tab[9]);

    std::cout << "Tablica po sortowaniu szybkim: \n";
    for(int i = 0; i < 20; i++){
        if(i == 19){
            std::cout << tab[i] << std::endl << std::endl;
        }else{
            std::cout << tab[i] << ", ";
        }
    }

    bubbleSort(&tab[10], &tab[19]);

    std::cout << "Tablica po sortowaniu babelkowym: \n";
    for(int i = 0; i < 20; i++){
        if(i == 19){
            std::cout << tab[i] << std::endl << std::endl;
        }else{
            std::cout << tab[i] << ", ";
        }
    }

    mergeSort(&tab[0], &tab[19]);

    std::cout << "Tablica po sortowaniu przez scalanie: \n";
    for(int i = 0; i < 20; i++){
        if(i == 19){
            std::cout << tab[i] << std::endl << std::endl;
        }else{
            std::cout << tab[i] << ", ";
        }
    }

    delete [] tab;
    delete [] help;

    return 0;
}
