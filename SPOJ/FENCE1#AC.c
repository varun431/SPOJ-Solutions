#include <stdio.h>
#define pie 3.1415926

int main(void)
{
    float l,area;
    while(1)
    {
        scanf("%f",&l);
        if(l==0)
            break;
        area = (l*l)/(2*pie);
        printf("%.2f\n",area);
    }
    return 0;
}
