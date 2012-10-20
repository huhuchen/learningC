

//ex14
/*
#include <stdio.h>
#include <ctype.h>


int can_print_it(char ch);
void print_letters(char arg[]);


void print_arguments(int argc, char *argv[])
{
    int i = 0;

    for(i=0; i<argc; i++){
        print_letters(argv[i]);
    }
}

int can_print_it(char ch)
{
    return isalpha(ch) || isblank(ch);
}

void print_letters(char arg[])
{
    int i = 0;
    for(i = 0; arg[i] != '\0'; i++){
        char ch = arg[i];

        if (can_print_it(ch)){
            printf("%c == %d ", ch, ch); 
        }
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    print_arguments(argc, argv);
    return 0;
}
*/

//ex15
/*
#include <stdio.h>

int main(int argc, char *argv[])
{
    int ages[] = {23, 45, 56, 72, 81};
    char *name[] = {
         "tom", "jim", "mary", "lisa", "john"
    };

    int u = 12;
    int *test = &u;
    printf("%d.\n", *test);
    printf("------\n");

    int count = sizeof(ages) / sizeof(int);
    int i = 0;

    for(i = 0; i < count; i++){
        printf("%s has %d years alive.\n", name[i], ages[i]);
    }

    printf("------\n");

    int *cur_age = ages;
    char **cur_name = name;

    for(i = 0; i < count; i++){
        printf("%s is %d years old.\n", *(cur_name + i), *(cur_age + i));
    }

    printf("------\n");

    for(i = 0; i < count; i++){
        printf("%s is %d years old again.\n", cur_name[i], cur_age[i]);
    }
    return 0;
}
*/

//ex16
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct Person {
    char *name;
    int age;
    int height;
    int weight;
};

struct Person *person_create(char *name, int age, int height, int weight){
    struct Person *who = malloc(sizeof(struct Person));
    assert(who != NULL);

    who->name = strdup(name);
    who->age = age;
    who->height = height;
    who->weight = weight;

    return who;
}

void person_print(struct Person *who){
    assert(who != NULL);
    printf("Name: %s.\n", who->name);
    printf("\tage: %d.\n", who->age);
    printf("\theight: %d.\n", who->height);
    printf("\tweight: %d.\n", who->weight);
}

void person_destory(struct Person *who){
    assert(who != NULL);
    free(who->name);
    free(who);
}

int main(int argc, char *argv[]){

    struct Person *joe = person_create("joe", 23, 172, 65);
    struct Person *mary= person_create("mary", 32, 185, 70);
    
    printf("joe is at memory location %p. \n", joe);
    person_print(joe);

    printf("mary is at memory location %p. \n", mary);
    person_print(mary);

    joe->age += 20;
    joe->height -= 10;
    person_print(joe);

    mary->age -= 2;
    mary->weight += 10;
    person_print(mary);

    person_destory(joe);
    person_destory(mary);

    return 0;
}



