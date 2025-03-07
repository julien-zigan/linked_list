#include <stdio.h>
#include <stdlib.h>

#define STR_BUF 255

typedef struct company{
    struct company *next;
    char name[STR_BUF];
    int priority;

} company_t;

int new_company() 
{
    company_t *new = malloc(sizeof(company_t));
    printf("Enter company name: ");
    
}
