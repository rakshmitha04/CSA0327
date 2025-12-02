#include <stdio.h>
#define N 5
int s[N], top=-1;

void push(int x){ if(top<N-1) s[++top]=x; }
void pop(){ if(top>=0) printf("Popped: %d\n", s[top--]); }
void disp(){ for(int i=top;i>=0;i--) printf("%d ",s[i]); printf("\n"); }

int main(){
    int c,x;
    while(1){
        scanf("%d",&c);
        if(c==1){ scanf("%d",&x); push(x); }
        else if(c==2) pop();
        else if(c==3) disp();
        else break;
    }
}

