#include <stdio.h>
#include <stdlib.h>
struct stack_node
{
    int data;
    struct stack_node* next;
};
struct stack_node *push(struct stack_node* top, int number)
{
    struct stack_node* new_node = NULL;
    new_node = (struct stack_node*) malloc(sizeof(struct stack_node));
     if(new_node!=NULL)
     {
          new_node->data = number;
          new_node->next = top;
          top = new_node;
     }
     return top;
}
int pop(struct stack_node **top)
{
     int result = -1;
     if(*top!=NULL)
     {
          result = (*top)->data;
          struct stack_node *tmp = (*top)->next;
          free(*top);
          *top = tmp;
     }
     return result;
}
int peek(struct stack_node *top)
{
     if(top!=NULL) return top->data;
     else return -1;
}
int main()
{
    struct stack_node* our_stack = NULL;
    for(int i = 10;i>0;i--)
    {
        our_stack = push(our_stack,i);
        printf("Klade element %d na stos\n",i);
    }
    printf("\nCzytam element na szczycie bez zdejmowania. Ma on wartosc: %d\n",peek(our_stack));
    while(our_stack!=NULL)
    {
        printf("Zdejmuje element %d ze stosu\n",pop(&our_stack));
    }
    return 0;
}
