#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *next;
    int value;
}linked_list;

int len_list(linked_list *a) //length of list
{
    int len = 0;
    linked_list *ptr = a->next;
    while (ptr!=NULL)
    {
        len++;
        ptr = ptr->next;
    }

    return len;
}

int show_list(linked_list *a) //print all nodes in list
{
    linked_list *ptr = a->next;
    while (ptr!=NULL)
    {
        printf("%d | ", ptr->value);
        ptr = ptr->next;
    }
    printf("\n");
    return 0;
}

int get_in_list(linked_list *a, int ind) //get value by index
{
    int val = 0;
    linked_list *ptr = a->next;
    while (ptr->next!=NULL && ind--)
    {
        ptr = ptr->next;
    }
    val = ptr->value;

    return val;
}

int get_index(linked_list *a, int val) //get firsr index by value
{
    int ind = 0;
    linked_list *ptr = a->next;
    while (ptr->next!=NULL && ptr->value!=val)
    {
        ptr = ptr->next;
        ind++;
    }
    val = ptr->value;

    return ind;
}

int del_by_value(linked_list *a, int val) //delete the first value found
{
    int pop_v = 0;

    linked_list *ptr = a;
    linked_list *del_ptr = ptr->next;
    while (ptr!=NULL && del_ptr->next!=NULL && del_ptr->value!=val)
    {
        del_ptr = del_ptr->next;
        ptr = ptr->next;
    }

    pop_v = del_ptr->value;
    ptr->next = del_ptr->next;
    free(del_ptr);

    return pop_v;
}

int append_list(linked_list *a, int val) //append value at last index
{
    linked_list *newNode = (linked_list*)malloc(sizeof(linked_list));
    newNode->next=NULL;
    newNode->value=val;

    linked_list *ptr = a;
    while (ptr->next!=NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;

    return 0;
}

int insert_list(linked_list *a, int val, int ins_ind) //insert value at specific index
{
    int last_ind = ins_ind;

    linked_list *ptr = a;
    linked_list *ins_ptr = ptr->next;
    while (ptr!=NULL && ins_ptr!=NULL && last_ind--)
    {
        ins_ptr = ins_ptr->next;
        ptr = ptr->next;
    }

    linked_list *newNode = (linked_list*)malloc(sizeof(linked_list));
    newNode->next = ins_ptr;
    newNode->value=val;
    ptr->next = newNode;

    return 0;

}

int pop_list(linked_list *a) //delete and retuen last value
{
    int pop_v = 0;
    int last_ind = len_list(a);

    linked_list *ptr = a;
    linked_list *del_ptr = ptr->next;
    while (ptr!=NULL && del_ptr->next!=NULL && last_ind--)
    {
        del_ptr = del_ptr->next;
        ptr = ptr->next;
    }

    pop_v = del_ptr->value;
    free(del_ptr);
    ptr->next = NULL;

    return pop_v;
}

int del_list(linked_list *a, int del_ind) //delete and return value at specific index
{
    int pop_v = 0;
    int last_ind = del_ind;

    linked_list *ptr = a;
    linked_list *del_ptr = ptr->next;
    while (ptr!=NULL && del_ptr->next!=NULL && last_ind--)
    {
        del_ptr = del_ptr->next;
        ptr = ptr->next;
    }

    pop_v = del_ptr->value;
    ptr->next = del_ptr->next;
    free(del_ptr);

    return pop_v;

}

int reverse_list(linked_list *a) //reverse nodes
{
    int leng = len_list(a);
    linked_list *stack[leng];

    linked_list *ptr = a->next;
    int i=0;
    while (ptr!=NULL)
    {
        stack[i] = ptr;
        ptr = ptr->next;
        i++;
    }
    for(int j=leng; j>0; j--)
    {
        stack[j]->next = stack[j-1];
    }
    stack[0]->next = NULL;
    a->next = stack[leng-1];
    
    return 0;
}

int __compare(linked_list *head, linked_list *val1, linked_list *val2, linked_list *tail)
{
    if(val1->value > val2->value)
    {
        head->next=val2;
        val1->next=tail;
        val2->next=val1;
    }
    else if(val1->value <= val2->value)
    {
        //do nothing
    }
}

int sort_list(linked_list *a) //bubble sort
{
    int leng = len_list(a);
    linked_list *ptr = a;

    for(int i=0; i<leng-1; i++)
    {
        ptr = a;
        for(int j=i; j<leng-1; j++)
        {
            __compare(ptr, ptr->next, (ptr->next)->next, ((ptr->next)->next)->next);
            ptr=ptr->next;
        }
    }
}