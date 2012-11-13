#include <stdio.h>

double atof(char *strnum);

int main(int argc, char *argv[])
{
    double result = 0;

    if(argc != 2){
        printf("\n wrong usage");
        return 0;
    }

    result = atof(argv[1]);
    printf("\n the result is %f\n", result);

    return 0;
}


double atof(char *s){
    int i = 0;
    double result;
    int sign;
    int power = 1;


    if(s[0] == '-'){
        sign = -1;
        i = 1;
    }else{
        sign = 1;
    }

    for(result=0; s[i] != '\0'; i++){
        if('0' <= s[i] && s[i]<= '9'){
            result = result * 10 + (s[i] - '0');
        }
        if(s[i] == '.'){
            i++;
            break;
        }
    }

    for(power=1; s[i] != '\0'; i++){
        result = result * 10 + (s[i] - '0');
        power *= 10;
    }

    return result * sign / power;
}
