#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

struct node
{
    char site[100];
    int x;
    struct node *previous;
    struct node *next;
} *head;

void insert_end(char gelensite[100])
{
    int adet = 1;
    struct node *var, *temp;
    var = (struct node *) malloc(sizeof(struct node));
    strcpy(var->site , gelensite);
    var->x = 0;

    if(head == NULL)
    {
        head = var;
        head->previous = NULL;
        head->next = NULL;
    }
    else
    {
        temp = head;
        while(temp->next != NULL)
        {
            adet++;
            temp = temp->next;
        }

    if(adet < 5)
    {
        temp->next = var;
        var->previous = temp;
        var->next = NULL;
    }
    else
        printf("DOLU..\n");

    }
}

void Ara(char gelensite[100])
{
    struct node *temp, temp2, *onceki=NULL;
    int kontrol = 0;
    temp = head;

    while(temp != NULL)
    {
        if(strcmp(temp->site , gelensite) == 0)
        {
            kontrol = 1;
            (temp->x)++;
            break;
        }
        onceki = temp;
        temp = temp->next;
    }

    if(kontrol == 0)
    {
        printf("Aranan Yok..");
        return;
    }

    while(onceki!=NULL && temp->x > onceki->x)
    {
        if(onceki->previous != NULL)
            onceki->previous->next = temp;

        temp->previous = onceki->previous;
        onceki->previous = temp;
        onceki->next = temp->next;
        if(temp->next != NULL)
            temp->next->previous = onceki;

        temp->next = onceki;
        if(head == onceki)
            head = temp;

        onceki = temp->previous;

    }
}

void display()
{
    struct node *temp;
    temp = head;

    if(temp == NULL)
    {
        printf("Liste bos..");
    }

    while(temp != NULL)
    {
        printf("-> %s / %d ", temp->site, temp->x);
        temp = temp->next;
    }
    getch();
}

int main()
{
    int value, i, loc;
    head = NULL;
    char siteAdresi[100];

    while(1)
    {
        system("cls");
        printf("1-EKLE\t2-ARA\t3-LISTELE\t4-CIKIS");
        printf("\nSeciminiz: ");
        scanf("%d", &i);
        switch(i)
        {
            case 1: printf("Yeni Site: ");
                    scanf("%s", siteAdresi);
                    insert_end(siteAdresi);
                    display();
                    break;

            case 2: printf("Yeni Site: ");
                    scanf("%s", siteAdresi);
                    Ara(siteAdresi);
                    display();
                    break;

            case 3: display();
                    break;

            case 4: printf("Program sonlandi..");
                    exit(0);
                    break;

            default:
                break;
        }
    }
}
