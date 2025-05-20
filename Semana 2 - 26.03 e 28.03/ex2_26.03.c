#include <stdio.h>
void troca(int x, int y)
{
int temp;
temp = x;
x = y;
y = temp;
}

int main()
{
int x=5, y=10;
printf("x=%d y=%d\n",x,y);
troca(x,y);
printf("x=%d y=%d\n",x,y);
return 0;
}
