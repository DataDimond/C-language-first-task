#include <stdio.h>
#include <string.h>
#define N 6
struct birth
{
    int year;
    int month;
    int day;
};
struct person
{
    char ID[19];
    char name[20];
    struct birth birthday;
    int flag; // verify code: 1 correct, 0 wrong
};

FILE *f;
int read(struct person p[])
{
    int i = 0;
    while (i < 18)
    {
        p->ID[i] = fgetc(f);
        putchar(p->ID[i]);
        i++;
    }
    p->ID[18] = 0;
    i = 0;
    int ch;
    while ((ch = fgetc(f)) != '\n')
    {
        p->name[i] = ch;
        i++;
    }
    p->name[i] = 0;

    // set birthday
    char buf[6];
    strncpy(buf, p->ID + 6, 4);
    buf[4] = 0;
    p->birthday.year = atoi(buf);
    strncpy(buf, p->ID + 10, 2);
    buf[2] = 0;
    p->birthday.month = atoi(buf);
    strncpy(buf, p->ID + 12, 2);
    buf[2] = 0;
    p->birthday.day = atoi(buf);
    
}

int checkID(char *ID)
{
    int coeffect[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};

    // step 1: got the sum
    int sum = 0;
    for (int i = 0; i < 17; i++)
    {
        sum += (ID[i] - '0') * coeffect[i];
    }

    printf("sum = %d\n", sum);

    // step 3: modular by 11
    int m = sum % 11;

    printf("m = %d\n", m);
    // step 4: transform
    int transforms[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    int parityChar = transforms[m];

    printf("parityChar = %c\n", parityChar);

    if (parityChar == ID[17])
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct birth get_birth(char *ID)
{
}

void get_all_person(struct person p[], int n)
{
    f = fopen("c:/labs/c/final/person.txt", "r");
    int i = 0;
    while (i < n)
    {
        printf("get person %d\n", i);
        read(p + i);
        i++;
    }
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
    int times = 0;
    for (int i = 0; i < N; i++) {
        if(strcmp(p[i].name, name) == 0) {
            times += 1;
        }
    }
    return times;
}

void save(struct person p[], int n)
{
    FILE *out = fopen("c:/labs/c/final/out.txt", "w");
    for (int i = 0; i < n; i++)
    {
        if (p[i].flag == 1)
        {
            fprintf(out, "%s\t%s\n", p->ID, p->name);
        }
    }
    fclose(out);
}

int prompt(void)
{
    int cmd = 0;
    printf("-------------------\n");
    printf("1.  Show ID Info(Without wrong IDs.)\n");
    printf("2.  Show Wrong IDs\n");
    printf("3.  By Birtyday(Without Wrong IDs)\n");
    printf("4.  Show Person Name Duplicates(Without Wrong IDs)\n");
    printf("0.  Quit\n");
    printf("-------------------\n");
    printf("enter your choice(0-4):");
    scanf("%d", &cmd);
    return cmd;
}

int main(void)
{
    // checkId testing code
    // char id1[] = "510108197501031517";
    // printf("id validity = %d\n", checkID(id1));
    // char id2[] = "440524198001010013";
    // printf("id validity = %d\n", checkID(id2));

    // read all data
    struct person persons[N + 1];
    get_all_person(persons, N);

    // read all data testing code
    // for (int i = 0; i < N; i++) {
    //     printf("person %s\n", persons[0].ID);
    // }

    // mark the flag
    for (int i = 0; i < N; i++)
    {
        persons[i].flag = checkID(persons[i].ID);
    }

    // for (int i = 0; i < N; i++) {
    //     printf("id = %s, flat = %d\n", persons[i].ID, persons[i].flag);
    // }
    int cmd, n;

    /* read in data */

    /* validation */

    while (1)
    {
        cmd = prompt();
        printf("cmd = %d\n", cmd);

        if (cmd == 1)
        {
            printf("good IDs\n");
            for (int i = 0; i < N; i++)
            {
                if (persons[i].flag == 1)
                {
                    printf("%s\t%s, birthday = %d-%d-%d\n", persons[i].ID, persons[i].name,
                    persons[i].birthday.year, persons[i].birthday.month, persons[i].birthday.day);
                }
            }
        }


        if (cmd == 2)
        {
            printf("wrong ids:\n");
            for (int i = 0; i < N; i++)
            {
                if (persons[i].flag == 0)
                {
                    printf("%s\t%s\n", persons[i].ID, persons[i].name);
                }
            }
        }

        if (cmd == 3) {
            printf("print out, sort by birth day\n");\
        }

        if (cmd == 4) {
            printf("show person name duplicates\n");
            for (int i = 0; i < N; i++) {
             char *name = persons[i].name;
             int times = search(persons, N, name);
             if (times > 1) {
                 printf("%s\t%s, times = %d\n", persons[i].ID, persons[i].name, times);
             }
            }
        }

        if (cmd == 0)
        {
            save(persons, N);
            return 0;
        }
    }
    return 0;
}
