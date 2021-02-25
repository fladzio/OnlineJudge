#include <iostream>
#include <list>

int main(){

int P, C, val;
char command;
int cases = 1;

std::list<int> l;

while(std::cin >> P >> C) {

    if(P == 0 && C == 0) break;

    val = std::min(P,C);

    for(int i = 1; i <= val; i++) l.push_back(i);

    char command[C];
    std::cout << "Case " << cases++ << ":\n";

    for(int i = 0; i < C; i++){
        std::cin >> command;
        if (command[0] == 'N') {
            std::cout << l.front() << std::endl;
            l.push_back(l.front());
            l.pop_front();
        }
        else{
            std::cin >> val;
            l.remove (val);
            l.push_front (val);
        }
    }
    l.clear();
}

return 0;
}
