#include <stdio.h>
#include <stdlib.h>

#define STR_BUF 255

typedef struct company{
    struct company *next;
    char name[STR_BUF];
    int priority;

} company_t;

company_t *new_company() 
{
    company_t *new = malloc(sizeof(company_t));
    printf("Enter company name: ");
    scanf("%255s", new->name);
    while(getchar() != '\n');
    printf("Enter priority: ");
    scanf("%2i", &new->priority);
    return new;
}

int insert(company_t* list, company_t *item)
{
    if (item == NULL) {
        fprintf(stderr, "No valid company item was passed");
        return -1;
    }
    /* case: list empty */
    if (list == NULL) {
        list = item;
    }
    /* case: only one item in list */
    else if (list->next == NULL) {
            if (list->priorty > item->priority) {
                item->next = list;
                list = item;
    }
   return EXIT_SUCCESS;
}

int main()
{
    company_t *list = NULL;
    company_t *item = new_company();
    insert(list, item);

    return EXIT_SUCCESS;
}
