#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list{
    char ISBN[20];
    char NAME[20];
    char AUTHOR[20];
    int YEAR;
    char STATUS[20];
    struct list *next;
};

typedef struct list NODE;

NODE *start = NULL;

NODE *create_node(char isbn[], char name[], char author[], int year, char status[]){
    NODE *new_node;
    new_node = (NODE *) malloc(sizeof(NODE));
    strcpy(new_node->ISBN, isbn);
    strcpy(new_node->NAME, name);
    strcpy(new_node->AUTHOR, author);
    new_node->YEAR = year;
    strcpy(new_node->STATUS, status);
    new_node->next = NULL;
    return new_node;
}

void insert_book(){
    char isbn[20], name[20], author[20], status[20];
    int year;

    printf("Eklemek istediginiz kitabin ISBN numarasini giriniz: ");
    scanf("%s", isbn);
    printf("Eklemek istediginiz kitabin ismini giriniz: ");
    scanf("%s", name);
    printf("Eklemek istediginiz kitabin yazrinin ismini giriniz: ");
    scanf("%s", author);
    printf("Eklemek istediginiz kitabin basim yilini giriniz: ");
    scanf("%d", &year);

    if(year < 1985){
        strcpy(status, "Referans");
    }else{
        strcpy(status, "Mevcut");
    }

    NODE *new_node = create_node(isbn, name, author, year, status);

    if(start == NULL){
        start = new_node;
    }else{
        NODE *temp = start;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }

    printf("\nKitap sisteme basariyla eklenmistir.\n");
}

void display_books(){
    if(start == NULL){
        printf("\nKutuphanede mevcut kitap bulunamamistir.\n");
    }else{
        NODE *temp = start;
        printf("\nMevcut kitaplar: \n");
        printf("ISBN numarasi\tKitap Adi\tYazari\tBasim Yili\tDurumu\n");
        while(temp != NULL){
            printf("%s\t%s\t%s\t%d\t\t%s\n", temp->ISBN, temp->NAME, temp->AUTHOR, temp->YEAR, temp->STATUS);
            temp = temp->next;
        }
    }
}

void delete_book(){
    if(start == NULL){
        printf("\nKutuphanede silinmek icin uygun kitap bulunamamistir. \n");
    }else{
        char isbn[20];
        NODE *temp = start;
        NODE *prev = NULL;
        printf("\nSilmek istediginiz kitabın ISBN numarasini giriniz. ");
        scanf("%s", isbn);

        while(temp != NULL && strcmp(temp->ISBN, isbn) != 0){
            prev = temp;
            temp = temp->next;
        }

        if(temp == NULL){
            printf("\nISBN numarasi %s olan kitap bulunamadi.\n", isbn);
        }else{
            if(prev == NULL){
                start = temp->next;
            }else{
                prev->next = temp->next;
            }
            free(temp);
            printf("\n ISBN numarasi %s olan kitap basarili bir sekilde listeden silindi.\n", isbn);
        }
    }
}

int main(){

    int choice;

    while(1){
    	printf("\n**************************************************\n");
        printf("Bir kitap eklemek icin 1. tusuna basin\n");
        printf("Kitap listesini goruntulemek icin 2. tusuna basin\n");
        printf("Listeden bir kitabi silmek icin 3. tusuna basin\n");
        printf("Cikmak icin 4. tusuna basin\n");
        printf("Seciminiz: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                insert_book();
                break;
            case 2:
                display_books();
                break;
            case 3:
                delete_book();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Geçersiz seçim!\n");
                break;
        }
    }
    return 0;
}
