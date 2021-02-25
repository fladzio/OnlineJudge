#include <iostream>
#include <vector>

int main(){
    std::vector<std::string> vec;
    std::string s;
    int cont;
    bool M[26][26];
    bool present[26];
    char order[26];

    while(1){
        std::cin >> s;
        if(s[0] == '#') break;

        vec.push_back(s);
    }

    int n = vec.size();

    for(int i = 0; i < 26; i++)
        present[i] = false;

    for(int i = 0; i < 26; i++)
        for(int j = 0; j < 26; j++)
            M[i][j] = false;

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < std::min(vec[i].size(), vec[i+1].size()); j++){
            if(vec[i][j] != vec[i + 1][j]){
                M[vec[i][j] - 'A'][vec[i + 1][j] - 'A'] = 1;
                present[vec[i][j] - 'A'] = present[vec[i +1 ][j] - 'A'] = 1;
                break;
            }
        }
    }

    for(int k = 0; k < 26; k++)
        for(int i = 0; i < 26; i++)
            for(int j = 0; j < 26; j++)
                M[i][j] |= (M[i][k] && M[k][j]);

    n = 0;
    for(int i = 0; i < 26; i++){
        if(present[i]){
            n++;
            cont = 0;

            for(int j = 0; j < 26; j++)
                if(M[i][j]) cont++;

            order[cont] = 'A' + i;
        }
    }

    for(int i = n - 1 ; i >= 0; i--) std::cout << order[i];
    std::cout << std::endl;

    return 0;
}
