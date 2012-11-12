#include  <stdio.h>

#define MAXSIZE  200

int get_line(char line[], int max);
int index_pattern(char line[], int max);

char pattern[] = "you";

int main(int argc, char *argv[])
{
    char line[MAXSIZE];
    int limit = MAXSIZE;
    int length;
    int index;

    while((length=get_line(line, limit)) > 0){
        if((index=index_pattern(line, length)) < length){
            printf("\n%s", line);
        }
    }
    return 0;
}

int index_pattern(char s[], int length)
{
    int i, j;
    int len;

    len = sizeof(pattern) / sizeof(*pattern);

    for(i=0; i<length; i++){
        for(j=0; j<len-1; j++){
            if(s[i+j]!=pattern[j]){
                break;
            }
        }
        if(j==len-1){
            break;
        }
    }

    return i;
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
