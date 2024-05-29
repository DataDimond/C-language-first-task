#include <stdio.h>
#include <string.h>
#define N 100
struct birth
{
    int     year;
    int     month;
    int     day;
};
struct person
{
    char    ID[19];
    char    name[20];
    struct  birth  birthday;
    int flag; // verify code: 1 correct, 0 wrong
};

int read(struct person p[])
{
   
}

int checkID(char *ID)
{

}

struct birth get_birth(char *ID)
{

}

void get_all_person(struct person p[], int n)
{

}

void display_person(struct person p[], int n, int flag)
{

}

int birth_cmp(struct birth birth1, struct birth birth2)
{

}

void birth_sort(struct person p[], int n)
{

}

int search(struct person p[], int n, char *name)
{

}

void save(struct person p[], int n)
{

}

int prompt(void)
{
     int cmd=0;
    printf("-------------------\n");
    printf("1.  Show ID Info(Without wrong IDs.)\n");
    printf("2.  Show Wrong IDs\n");
    printf("3.  By Birtyday(Without Wrong IDs)\n");
    printf("4.  Show Duplicates(Without Wrong IDs)\n");
    printf("0.  Quit\n");
    printf("-------------------\n");
    printf("enter your choice(0-4):");
    scanf("%d", &cmd);
    return cmd;
}

int main(void)
{
    struct person p[N];
    int cmd, n;
    while (1)
    {   cmd = prompt();
        printf("cmd = %d\n", cmd);
        if (cmd == 0) {
            /* TODO: should save correct IDs: requirments 1 */
            return 0;
        }
    } 
    return 0;
}
