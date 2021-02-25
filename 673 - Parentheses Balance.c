#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 128

struct Stack{
    int top;
    char arr[MAX_SIZE];
} st;

void init(){
    st.top = -1;
}

bool isEmpty(){
    if(st.top == -1){
        return true;
    }else{
        return false;
    }
}

void push(char item){
    st.top++;
    st.arr[st.top] = item;
}

void pop(){
    st.top--;
}

char gettop(){
    return st.arr[st.top];
}

bool balance(char exp[]){
    int i = 0;

    while (exp[i])
    {
        if (exp[i] == '(' || exp[i] == '[')
            push(exp[i]);

        if (exp[i] == ')'){
            if (gettop() == '(')
                pop();
            else
                return false;
        }
        if (exp[i] == ']'){
            if (gettop() == '[')
                pop();
            else
                return false;
        }
        i++;
   }

   if (isEmpty())
        return true;
   else
        return false;
}

int main()
{
  init();
  int cases, i, s;
  char exp[MAX_SIZE];

  scanf("%d", &cases);
  scanf("%c", &s);

  for(i = 0; i < cases; i++){
        gets(exp);

        if (balance(exp))
            printf("Yes\n");
        else
            printf("No\n");

        while(!isEmpty()) pop();
  }

  return 0;
}
