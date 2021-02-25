#include <iostream>
#include <stack>
#include <queue>

int main(){
int n, command, value;
bool stos = true, kolejka = true, priorytet = true;

std::stack<int> s;
std::queue<int> q;
std::priority_queue<int> p;

while(std::cin >> n) {

for(int i = 0; i < n; i++){

    std::cin >> command >> value;

    if(command == 1){
        s.push(value);
        q.push(value);
        p.push(value);
    }

    if(command == 2){

        if(s.empty() || s.top() != value){
            stos = false;
        }else{
            s.pop();
        }

        if(q.empty() || q.front() != value){
            kolejka = false;
        }else{
            q.pop();
        }

        if(p.empty() || p.top() != value){
            priorytet = false;
        }else{
            p.pop();
        }
    }
}

if(stos && !kolejka && !priorytet){
    std::cout << "stack\n";
}else if(kolejka && !stos && !priorytet){
    std::cout << "queue\n";
}else if(priorytet && !kolejka && !stos){
    std::cout << "priority queue\n";
}else if(!stos && !kolejka && !priorytet){
    std::cout << "impossible\n";
}else{
    std::cout << "not sure\n";
}

while(!s.empty()){
    s.pop();
}
while(!q.empty()){
    q.pop();
}
while(!p.empty()){
    p.pop();
}

stos = true;
kolejka = true;
priorytet = true;

}
return 0;
}
