#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
   int data;
   int key;
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

//display the list
void printList() {
   struct node *ptr = head;
   printf("\n[ ");
	
   //start from the beginning
   while(ptr != NULL) {
      printf("(%d,%d) ",ptr->key,ptr->data);
      ptr = ptr->next;
   }
	
   printf(" ]");
}

//insert link at the first location
void insertFirst(int key, int data) {
   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));
	
   link->key = key;
   link->data = data;
	
   //point it to old first node
   link->next = head;
	
   //point first to new first node
   head = link;
}

//delete first item
struct node* deleteFirst() {

   //save reference to first link
   struct node *tempLink = head;
	
   //mark next to first link as first 
   head = head->next;
	
   //return the deleted link
   return tempLink;
}

//is list empty
bool isEmpty() {
   return head == NULL;
}

int length() {
   int length = 0;
   struct node *current;
	
   for(current = head; current != NULL; current = current->next) {
      length++;
   }
	
   return length;
}

//find a link with given key
struct node* find(int key) {

   //start from the first link
   struct node* current = head;

   //if list is empty
   if(head == NULL) {
      return NULL;
   }

   //navigate through list
   while(current->key != key) {
	
      //if it is last node
      if(current->next == NULL) {
         return NULL;
      } else {
         //go to next link
         current = current->next;
      }
   }      
	
   //if data found, return the current Link
   return current;
}
//update
struct node* update(int key, int data)
{
    //start from the first link
   struct node* current = head;

   //if list is empty
   if(head == NULL) {
     printf("\nNo such item exists! Please check the item key.\n");
      return NULL;
   }

   //navigate through list
   while(current->key != key) {
	
      //if it is last node
      if(current->next == NULL) {
          printf("\nNo such item exists! Please check the item key.");
         return NULL;
      } else {
         //go to next link
         current = current->next;
      }
   }      
	current->data = data;
   //if data found, return the current Link
   return current;
};



//delete a link with given key
struct node* delete(int key) {

   //start from the first link
   struct node* current = head;
   struct node* previous = NULL;
	
   //if list is empty
   if(head == NULL) {
      return NULL;
   }

   //navigate through list
   while(current->key != key) {

      //if it is last node
      if(current->next == NULL) {
         return NULL;
      } else {
         //store reference to current link
         previous = current;
         //move to next link
         current = current->next;
      }
   }

   //found a match, update the link
   if(current == head) {
      //change first to point to next link
      head = head->next;
   } else {
      //bypass the current link
      previous->next = current->next;
   }    
	
   return current;
}

int main() {

    //Already allocated inventory!
    insertFirst(1,10);
    insertFirst(2,20);
    insertFirst(3,30);
    insertFirst(4,1);
    insertFirst(5,40);
    insertFirst(6,56);



    printf("\n\nProject name: Inventory Management System\nName: Mrunmai Dahare\nRegistration Number: 2019507053\nSubject: Basic Programming and Data Structures\n\n");
while (1)
{
    int input_first;
    printf("\n*********************** WELCOME **********************\n");
    printf("press 1 to continue as admin\tpress 2 to continue as customer\tpress 0 to exit\n");
    scanf("%d", &input_first);
    if (input_first == 0)
    {
        break;
    }
    if (input_first != 1 && input_first != 2 )
    {
        printf("Please enter valid input!\n");
        break;
    }
    
    switch (input_first)
    {
    case 1:
        while (1)
        {
            int admin_ip;
            printf("*********************** WELCOME ADMIN **********************\n");
            printf("Here is original stock list:\n");
            printList();
            printf("\n \npress 1 to continue to update inventory\npress 2 to continue to delete item\npress 3 to continue to insert item\npress 0 to exit\n");
            scanf("%d", &admin_ip);
            if (admin_ip == 0)
            {
                break;
            }
            if (input_first != 1 && input_first != 2 && input_first != 3)
            {
                printf("Please enter valid input!\n");
                break;
            }
            int key, data;
            switch (admin_ip)
            {
            case 1:
                printf("\nEnter the item key where you want to update stock:");
                scanf("%d",&key);
                printf("\nEnter the data of number of stocks you want to update:");
                scanf("%d",&data);
                struct node* updt = update(key, data);
                printf("\n***************************************************");
                printf("\nCongrats! Item key %d is updated to %d stock!\n\n", updt->key, updt->data);
                break;

            case 2:
                printf("\nEnter the item key you want to delete item:");
                scanf("%d",&key);
                struct node* dlt = delete(key);
                printf("\n***************************************************");
                printf("\nCongrats! Item key %d is deleted from the stock!\n\n", dlt->key);
                break;

            case 3:
                printf("\nEnter the item key you want to insert:");
                scanf("%d",&key);
                printf("\nEnter the data of number of stocks you want to insert:");
                scanf("%d",&data);
                insertFirst(key, data);
                printf("\n***************************************************");
                printf("\nCongrats! Item key %d is inserted in the stock!\n\n", key);
                break;
            case 0:
                break;
            
            default:
                break;
            }
        }
        
        break;
        int key, data;
    case 2:
        
        printf("*********************** WELCOME CUSTOMER **********************\n");
            printf("Here is original Items available:\n");
            printList();
            printf("\n \nPlease enter the key of item you want to buy:\n");
            scanf("%d", &key);
            printf("\n \nPlease enter the number of items you want to buy:\n");
            scanf("%d", &data);
            struct node* link = find(key);
            if (link == NULL)
            {
                printf("\nNo such item exists! Please check the item key.");
                break;
            }
            
            if (link->data < data)
            {
                printf("\nSorry only %d items are available of item key %d. :(\n", link->data, key);
            }else
            {
                update(key, (link->data - data));
                printf("\nCongrats! You purchased %d items of item key %d.\n", data, key);
            }
            printf("The available items are:\n");
            printList();
            printf("\n");
        break;
    case 0:
        return 0;

    default:
        break;
    }
}
return 0;

}