struct LinkedList {
    int data;
    struct LinkedList *next;
};

void printList(struct LinkedList* );
void insert(struct LinkedList** , int );
void insertAt(struct LinkedList** , int , int );
struct LinkedList* LinkedList(int[] , int );
void append(struct LinkedList** , int );
int delete(struct LinkedList** );
int deleteThis(struct LinkedList** , int );
int deleteOn(struct LinkedList** , int );
int pop(struct LinkedList** );
void reverseList(struct LinkedList** );
int length(struct LinkedList* );

void printList(struct LinkedList *head){
    while(head!=NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void insert(struct LinkedList **head, int data){
    struct LinkedList *new;
    new = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    new->data = data;
    new->next = (*head);
    (*head) = new;
}

void insertAt(struct LinkedList **head, int index, int data){
    if(index==0){
        insert(head, data);
        return;
    }
    struct LinkedList *new;
    new = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    new->data = data;
    struct LinkedList *ptr = *head;
    while(ptr!=NULL&&index>1&&ptr->next!=NULL){
        index--;
        ptr =  ptr->next;
    }
    new->next = ptr->next;
    ptr->next = new;
}

struct LinkedList* LinkedList(int arr[], int size){
    struct LinkedList *newHead = NULL;
    for(int i=size-1;i>=0;--i){
        insert(&newHead, arr[i]);
    }
    return newHead;
}

void append(struct LinkedList **head, int data){
    if((*head)==NULL){
        insert(head, data);
        return;
    }
    struct LinkedList *new;
    new = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    new->data = data;
    struct LinkedList *ptr = *head;
    while(ptr!=NULL&&ptr->next!=NULL){
        ptr =  ptr->next;
    }
    new->next = ptr->next;
    ptr->next = new;
}

int delete(struct LinkedList **head){
    if((*head)==NULL){
        return -1;
    }
    int data = (*head)->data;
    struct LinkedList *ptr = (*head);
    (*head) = (*head)->next;
    free(ptr);
    return data;
}

int deleteThis(struct LinkedList **head, int data){
    if((*head)==NULL){
        return -1;
    }
    struct LinkedList *ptr = (*head);
    if(ptr->data==data){
        return delete(head);
    }
    struct LinkedList *prevptr = (*head);
    while(ptr!=NULL&&ptr->next!=NULL){
        ptr = ptr->next;
        if(ptr->data==data){
            break;
        }
        prevptr = prevptr->next;
    }
    int dt = ptr->data;
    prevptr->next = ptr->next;
    free(ptr);
    return dt;
}

int deleteOn(struct LinkedList **head, int index){
    if(index==0){
        return delete(head);
    }
    struct LinkedList *ptr = (*head);
    struct LinkedList *prevptr = (*head);
    int pos = index;
    int i=0;
    while(ptr!=NULL&&ptr->next!=NULL){
        pos--;
        i++;
        ptr = ptr->next;
        if(pos==0){
            break;
        }
        prevptr = prevptr->next;
    }
    if(i<index){
        return -1;
    }
    int data = ptr->data;
    prevptr->next = ptr->next;
    free(ptr);
    return data;
}

int pop(struct LinkedList **head){
    struct LinkedList *ptr = (*head);
    struct LinkedList *prevptr = (*head);
    while(ptr!=NULL){
        ptr = ptr->next;
        if(ptr->next==NULL){
            break;
        }
        prevptr = prevptr->next;
    }
    prevptr->next = NULL;
    int data = ptr->data;
    free(ptr);
    return data;
}

void reverseList(struct LinkedList **head){
    if((*head)==NULL||(*head)->next==NULL){
        return;
    }
    struct LinkedList *prev = (*head);
    (*head) = (*head)->next;
    prev->next = NULL;
    if((*head)->next==NULL){
        (*head)->next = prev;
        return;
    }
    struct LinkedList *next = (*head)->next;
    while(next!=NULL){
        (*head)->next = prev;
        prev = (*head);
        (*head) = next;
        next = next->next;
    }
    (*head)->next = prev;
}

int length(struct LinkedList *head){
    int size = 0;
    while(head!=NULL){
        size++;
        head = head->next;
    }
    return size;
}