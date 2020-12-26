#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void perm(char *v,int inicio,int n,int *numb)
{
    if(inicio==n-1){
        printf("%d - %s\n",++(*numb),v);
    }else{
        for(int i=inicio;i<n;i++){
            char tmp=v[i];
            v[i]=v[inicio];
            v[inicio]=tmp;
            perm(v,inicio+1,n,numb);
            v[inicio]=v[i];
            v[i]=tmp;
        }
    }
}

int main()
{
    char *v=malloc(sizeof(char));
    printf("Digite a string:\n");
    int i,numb=0;
    for(i=0;v[i-1]!=13;i++){
        v[i]=getche();
        if(v[i]==8 && i>0)
            i-=2;
        v=realloc(v,(i+2)*sizeof(char));
    }
    v[i-1]=0;
    system("cls");
    perm(v,0,i-1,&numb);
    system("pause");
    return 0;
}
