#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct company_t{
   struct company_t *next;
   char name[255];
   int priority;

} COMPANY;

COMPANY *new_company() 
{
    COMPANY *new = (COMPANY *) malloc(sizeof(COMPANY));
    new->next = NULL;
    printf("Name: ");
    scanf("%10s", new->name);
    while(getchar() != '\n');
    printf("Priority: ");
    scanf("%2i", &new->priority);
    return new;
}

int insert(COMPANY *list,COMPANY *item)
{
    int i = 0;
    if (list == NULL)
        fprintf(stderr, "no list passed\n");
    else {
        COMPANY *tmp = list;
        while (tmp->next) {
            if (tmp->next->priority > item->priority) {
                item->next = tmp->next;
                tmp->next = item;
                return ++i;
            }
            i++;
            tmp = tmp->next;
        }   
       tmp->next = item; 
       return ++i;
    }
}

int print_list(COMPANY *list) 
{
    COMPANY *reader = list;
    while (reader->next) {
       printf("%s\t%i\tNext: %p\n", 
                reader->next->name, reader->next->priority, reader->next->next);
        reader = reader->next;
    }
}


int main(void)
{
    COMPANY *head = malloc(sizeof(COMPANY));
    head->next = NULL;
    for (int i = 0; i < 4; i++) {
        COMPANY *item = new_company();
        int pos = insert(head, item);
        printf("%i\n", pos);
    }
    print_list(head);
    return EXIT_SUCCESS;
}
