#include  <stdio.h>

#define MAXSIZE  200

int get_line(char line[], int max);
int index_pattern(char line[], char searchfor[]);

char pattern[] = "you";

int main(int argc, char *argv[])
{
    char line[MAXSIZE];
    int limit = MAXSIZE;
    int found = 0;

    while(get_line(line, limit) > 0){
        if(index_pattern(line, pattern) > 0){
            printf("\n%s", line);
            found++;
        }
    }
    return found;
}

int index_pattern(char s[], char t[])
{
    int i, j;

    for(i=0; s[i] != '\0'; i++){
        for(j=0; t[j] != '\0' && s[i+j] != t[j]; j++)
            ;
        if(j>0 && t[j] == '\0'){
            return i;
        }
    }
    return -1;
}

int get_line(char s[], int limit)
{
    int c;
    int i = 0;

    while(--limit > 0 && (c=getchar())!= EOF && c != '\n')
    {
        s[i++] = c;
    }

    if(c == '\n'){
        s[i++] = c;
    }

    s[i] = '\0';
    return i;
}
