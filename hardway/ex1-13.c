#include <stdio.h>

/*
int main(int argc, char *argv[]) {
    printf("hello world\n");
    puts("hello world\n");

    return 0;
}
*/


/*
int main()
{
    int age = 26;
    int height = 172;
    float power = 12.2f;
    double super_power = 12.21223;
    char initial = 'A';
    char name[] = "chen";

    printf("I'm is %d old.\n", age);
    printf("I'm is %d cm tall.\n", height);
    printf("the power is %f.\n", power);
    printf("the super_power is %f.\n", super_power);
    printf("the initial is %c.\n", initial);
    printf("the initial is %s.\n", name);

    return 0;
}
*/


/*
int main()
{
    int areas[] = {12, 13, 14, 15, 16};
    char name[] = "huhuchen";
    char full_name[] = {
        'a', 'b', 'c', 'd',
        'e', 'f', 'g', 'h', '\0'
    };

    printf("the size of an int: %ld\n", sizeof(int));
    printf("the size of areas(int) %ld\n", sizeof(areas));
    printf("the number of ints in the areas is %ld.\n", sizeof(areas) / sizeof(int));
    printf("the first area is %d, the second area is %d.\n", areas[0], areas[1]);
    
    printf("the size of a char is %ld.\n", sizeof(char));
    printf("the size of name(char) is  %ld\n", sizeof(name));
    printf("the number of chars in name is %ld.\n", sizeof(name) / sizeof(char));

    printf("the size of fullname is %ld.\n", sizeof(full_name));
    printf("the number of char in full_name is %ld.\n", sizeof(full_name) / sizeof(char));

    printf("name = \"%s\" and full_name = \"%s\".\n", name, full_name);

    return 0;
}
*/


/*
int main(int argc, char *argv[])
{
    int numbers[4] = {0};
    char name[4] = {'a'};

    printf("numbers: %d %d %d %d\n",
          numbers[0], numbers[1],
          numbers[2], numbers[3]);

    printf("names: %c %c %c %c\n",
            name[0], name[1],
            name[2], name[3]);

    printf("name: %s.\n", name);
    
    numbers[0] = 1;
    numbers[1] = 2;
    numbers[2] = 3;
    numbers[3] = 4;

    name[0] = 'a';
    name[1] = 'b';
    name[2] = 'c';
    name[3] = '\0';
    
    printf("numbers: %d %d %d %d\n",
          numbers[0], numbers[1],
          numbers[2], numbers[3]);

    printf("names: %c %c %c %c\n",
            name[0], name[1],
            name[2], name[3]);

    printf("name: %s.\n", name);

    char *another = "huh";

    printf("another: %c %c %c %c\n",
            another[0], another[1],
            another[2], another[3]);

    printf("another: %s.\n", another);
    return 0;
}
*/

//ex10
/*
int main(int argc, char *argv[])
{
    int i = 0;

    printf("arg: %d %s\n", i, argv[i]);

    for(i=1; i<argc; i++){
        printf("arg: %d %s\n", i, argv[i]);
    }

    char *countries[] = {"china", "Japan", "USA", "Canda"};
    int count_country = 4;

    for(i=0; i < count_country; i++){
        printf("country: %d %s\n", i, countries[i]);
    }

    return 0;
}
*/

//ex11
/*
int main(int argc, char *argv[])
{
    int i = 0;

    while(i < argc){
        printf("arg: %d %s\n", i, argv[i]);
        i++;
    }

    char *countries[] = {"china", "Japan", "USA", "Canda"};
    int count_country = 4;

    i = 0;
    while(i < count_country){
        printf("country: %d %s\n", i, countries[i]);
        i++;
    }

    return 0;
}
*/

//ex12
/*
int main(int argc, char *argv[])
{
    if(argc == 1){
        printf("You have only one argument, you suck.\n");
    }else if(argc>1 && argc <4){
        printf("Here's your arguments.\n");
        int i = 0;
        
        while(i < argc){
            printf("arg: %d %s\n", i, argv[i]);
            i++;
        }
    }else{
        printf("You have too many arguments.\n");
    }

    return 0;
}
*/

//ex13
int main(int argc, char *argv[])
{
    if(argc != 2){
        printf("ERROR, you need one argument!\n");
        return 1;
    }

    int i = 0;
    for(i=0; argv[1][i] != '\0'; i++){
        char letter = argv[1][i];

        switch(letter){
            case 'a':
            case 'A':
                printf("%d: 'A'\n", i);
                break;

            case 'e':
            case 'E':
                printf("%d: 'E'\n", i);
                break;
                
            case 'i':
            case 'I':
                printf("%d: 'I'\n", i);
                break;
                
            case 'o':
            case 'O':
                printf("%d: 'O'\n", i);
                break;

            case 'u':
            case 'U':
                printf("%d: 'U'\n", i);
                break;

            default:
                printf("%d: %c is not a vowel.\n", i, letter);
        }
    }

    return 0;
}
