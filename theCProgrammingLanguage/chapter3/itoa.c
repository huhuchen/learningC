#include <stdio.h>
#include <string.h>
#define MAXLINE 1000    


void reverse(char s[]);
void itoa(int n, char s[]);

int main(){

    int num = -1024;
    int i;
    char a[MAXLINE];
    
    itoa(num, a); 
    
    for (i = 0; a[i] != '\0'; i++)
        putchar(a[i]);
    return 0;
}

void itoa(int n, char s[])
{
    int sign, i;    

    if ((sign = n) < 0)
        n = -n;

    i = 0;
    do{
        s[i++] = n % 10 + '0';
    }
    while((n /= 10) > 0);

    if (sign < 0)
        s[i++] = '-';
    
    s[i] = '\0';
    reverse(s);
}


void reverse(char s[])
{
    int i, j, temp;

    for (i = 0, j = strlen(s) - 1; j >= i; i++, j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}
