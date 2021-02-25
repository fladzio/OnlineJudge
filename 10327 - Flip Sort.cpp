#include <iostream>

int main(){
int n;
while(std::cin >> n){
    int tab[n];
    int count = 0;
    for(int i = 0; i < n; i++){
        std::cin >> tab[i];
    }

    for(int j = 0; j < n; j++){
        for(int i = 0; i < n-1; i++){
            if(tab[i] > tab[i+1]){
                int temp = tab[i];
                tab[i] = tab[i+1];
                tab[i+1] = temp;
                count++;
            }
        }
    }

    std::cout << "Minimum exchange operations : " << count << std::endl;
}

return 0;
}