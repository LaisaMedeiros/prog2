#include <stdio.h>
void troca1(int *px, int *py)
{ // conte�do dos endere�os
int temp;
temp=*px;
*px = *py;
*py = temp;
}

int main()
{
int x=5, y=10;
printf("x=%d y=%d\n",x,y);
troca1(&x,&y); //aqui, endere�os
printf("x=%d y=%d\n",x,y);
return 0;
}
