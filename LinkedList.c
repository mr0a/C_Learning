#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;
} node;

int main(){
    node * createNode(int data){
        node * temp = malloc(sizeof(node));
        temp->data = data;
        temp->next = NULL;
        return temp;
    }
    
    node *head = NULL, *tail = NULL;
    int count = 0;
    
    void addFirst(int data){
        if(head == NULL){
            head = createNode(data);
            tail = head;
            count++;
            return;
        }
        node * temp = createNode(data);
        temp -> next = head;
        head = temp;
        count++;
    }
    
    void addLast(int data){
        if(head == NULL){
            addFirst(data);
            return;
        }
        node * temp = createNode(data);
        tail->next = temp;
        tail = temp;
        count++;
    }
    
    void insert(int position, int data){
        if(position <= 0){
            addFirst(data);
            return;
        }
        if(position >= count){
            addLast(data);
            return;
        }
        node * temp = head;
        while(position != 1){
            position--;
            temp = temp -> next;
        }
        node * newNode = createNode(data);
        newNode -> next = temp -> next;
        temp -> next = newNode;
        count++;
    }
    
    void printData(){
        node * temp = head;
        while( temp != NULL){
            printf(" %d ", temp->data);
            temp = temp->next;   
        }       
        printf("\n");
    }
    
    void deleteFirst(){
        if (head == NULL){
            printf("\nThe List is empty\n");
            return;
        }
        if (head == tail){
            tail = NULL;
        }
        node * temp = head;
        head = head -> next;
        free(temp);
        temp = NULL;
        count--;
    }
    
    void deleteLast(){
        if (head == NULL){
            printf("\nThe List is empty\n");
            return;
        }
        if (head == tail){
            deleteFirst();
            return;
        }
        node * temp = head;
        while(temp -> next != tail){
            temp = temp -> next;
        }
        free(tail);
        tail = temp;
        tail -> next = NULL;
        count--;
    }
    
    void delete(int position){
        if(position <= 0){
            deleteFirst();
            return;
        }
        if(position >= count){
            deleteLast();
            return;
        }
        node * temp = head;
        while( position != 1){
            position -= 1;
            temp = temp -> next;
        }
        node * remove = temp -> next;
        temp -> next = remove -> next;
        free(remove);
        count--;
        return;
    }
    
    int size(){
        return count;
    }
    
    int isEmpty(){
        return !count;
    }
    
    addFirst(10);
    addFirst(20);
    addLast(30);
    addLast(40);
    addLast(50);
    printData();
    insert(3, 100);
    delete(3);
    insert(4,200);
    printData();
    delete(100);
    deleteFirst();
    deleteFirst();
    deleteFirst();
    deleteFirst();
    deleteLast();
    printData();
    printf("\n Size: %d isEmpty: %d Head: %ld Tail: %ld", size(), isEmpty(), head, tail);
}
