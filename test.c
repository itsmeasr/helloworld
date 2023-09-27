#include <stdio.h>
#define MIN(a,b) ((a) < (b)  ? (a) : (b) )
//#define MIN(a,b,c) MIN(MIN(a,b)),c)

int main (void)
{
int a,b,c;
a = 391;
b = 44;
c = 5;
printf( "The minimum of value is %d\n", MIN(a,b) );
return 0;
}
