#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct person
{
    char name[32];
    char surname[32];
};
union data_types
{
    int number;
    char text[64];
    struct person per;
};

struct stack_node
{
    union data_types dt;
    struct stack_node* next;
};
struct stack_node *push(struct stack_node* top, union data_types new_dt)
{
    struct stack_node* new_node = NULL;
    new_node = (struct stack_node*) malloc(sizeof(struct stack_node));
     if(new_node!=NULL)
     {
        new_node->dt = new_dt;
        new_node->next = top;
        top = new_node;
     }
     return top;
}
bool pop(struct stack_node **top,union data_types* result)
{
     if(*top!=NULL)
     {
          *result = (*top)->dt;
          struct stack_node *tmp = (*top)->next;
          free(*top);
          *top = tmp;
          return true;
     }
     return false;
}
int main()
{
    system("chcp 1250");
    system("cls");
    struct stack_node* stack1 = NULL, *stack2 = NULL;
    //Odk³adamy na stos
    for(int i = 0;i<5;i++)
    {
        union data_types dt;
        dt.number = i;
        stack1 = push(stack1,dt);
    }
    union data_types person1,person2;
    strcpy(person1.per.name,"Jan");
    strcpy(person1.per.surname,"Kowalski");
    strcpy(person2.per.name,"Anna");
    strcpy(person2.per.surname,"Nowak");
    stack2 = push(stack2,person1);
    stack2 = push(stack2,person2);
    // Zdejmujemy ze stosu
    for(int i = 0;i<5;i++)
    {
        union data_types dt;
        pop(&stack1,&dt);
        printf("Zdjalem %d\n",dt.number);
    }
    puts("zdejmuje ciagi znakow");
    union data_types dt2,dt3;
    pop(&stack2,&dt2);
    pop(&stack2,&dt3);
    printf("Pierwsza osoba: %s %s\n",dt2.per.name,dt2.per.surname);
    printf("Druga osoba: %s %s\n",dt3.per.name,dt3.per.surname);
}
