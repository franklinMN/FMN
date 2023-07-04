#include<stdio.h>

struct node {
    int data;
    struct node *next;
};
struct node *head;

void insertBegin();
void insertBetween();
void insertEnd();
void deleteBegin();
void deleteBetween();
void deleteEnd();
void displayItem();

int main() {
    int choice;
    while(choice != 9)   {  
        printf("\n\n*********Main Menu*********\n");  
        printf("\nChoose one option from the following list ...\n");  
        printf("\n===============================================\n");  
        printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n5.Delete from last\n6.Delete node after specified location\n7.Search for an element\n8.Show\n9.Exit\n");  
        printf("\nEnter your choice?\n");         
        scanf("\n%d",&choice);  
        switch(choice)  {  
            case 1:  
                insertBegin();      
                break;  
            case 2:  
                insertBetween();         
                break;  
            case 3:  
                insertEnd();       
                break;  
            case 4:  
                deleteBegin();       
                break;  
            case 5:  
                deleteBetween();        
                break;  
            case 6:  
                deleteEnd();          
                break;  
            case 7:  
                search();         
                break;  
            case 8:  
                displayItem();        
                break;  
            case 9:  
                exit(0);
                break;  
            default:  
                printf("Please enter valid choice..");  
        }  
    }  
    return 0;
}

void insertBegin() {
    struct node *newNode, *temp = NULL;
    newNode=(struct node*)malloc(sizeof(struct node*));
}