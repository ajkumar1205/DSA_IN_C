struct LLOfCharacter {
    char data;
    struct LLOfCharacter *next;
};

void printLLOfCharacter(struct LLOfCharacter* );
void insert(struct LLOfCharacter** , char );
void insertAt(struct LLOfCharacter** , int , char );
struct LLOfCharacter* LLOfCharacter(char[] , int );
void append(struct LLOfCharacter** , char );
char delete(struct LLOfCharacter** );
char deleteThis(struct LLOfCharacter** , char );
char deleteOn(struct LLOfCharacter** , int );
char pop(struct LLOfCharacter** );
void reverseList(struct LLOfCharacter** );
int length(struct LLOfCharacter* );

void printLLOfCharacter(struct LLOfCharacter *head){
    while(head!=NULL){
        printf("%c", head->data);
        head = head->next;
    }
    printf("\n");
}

void insert(struct LLOfCharacter **head, char data){
    struct LLOfCharacter *new;
    new = (struct LLOfCharacter*)malloc(sizeof(struct LLOfCharacter));
    new->data = data;
    new->next = (*head);
    (*head) = new;
}

void insertAt(struct LLOfCharacter **head, int index, char data){
    if(index==0){
        insert(head, data);
        return;
    }
    struct LLOfCharacter *new;
    new = (struct LLOfCharacter*)malloc(sizeof(struct LLOfCharacter));
    new->data = data;
    struct LLOfCharacter *ptr = *head;
    while(ptr!=NULL&&index>1&&ptr->next!=NULL){
        index--;
        ptr =  ptr->next;
    }
    new->next = ptr->next;
    ptr->next = new;
}

struct LLOfCharacter* LLOfCharacter(char arr[], int size){
    struct LLOfCharacter *newHead = NULL;
    for(int i=size-1;i>=0;--i){
        insert(&newHead, arr[i]);
    }
    return newHead;
}

void append(struct LLOfCharacter **head, char data){
    if((*head)==NULL){
        insert(head, data);
        return;
    }
    struct LLOfCharacter *new;
    new = (struct LLOfCharacter*)malloc(sizeof(struct LLOfCharacter));
    new->data = data;
    struct LLOfCharacter *ptr = *head;
    while(ptr!=NULL&&ptr->next!=NULL){
        ptr =  ptr->next;
    }
    new->next = ptr->next;
    ptr->next = new;
}

char delete(struct LLOfCharacter **head){
    if((*head)==NULL){
        return -1;
    }
    int data = (*head)->data;
    struct LLOfCharacter *ptr = (*head);
    (*head) = (*head)->next;
    free(ptr);
    return data;
}

char deleteThis(struct LLOfCharacter **head, char data){
    if((*head)==NULL){
        return -1;
    }
    struct LLOfCharacter *ptr = (*head);
    if(ptr->data==data){
        return delete(head);
    }
    struct LLOfCharacter *prevptr = (*head);
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

char deleteOn(struct LLOfCharacter **head, int index){
    if(index==0){
        return delete(head);
    }
    struct LLOfCharacter *ptr = (*head);
    struct LLOfCharacter *prevptr = (*head);
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

char pop(struct LLOfCharacter **head){
    struct LLOfCharacter *ptr = (*head);
    struct LLOfCharacter *prevptr = (*head);
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

void reverseList(struct LLOfCharacter **head){
    if((*head)==NULL||(*head)->next==NULL){
        return;
    }
    struct LLOfCharacter *prev = (*head);
    (*head) = (*head)->next;
    prev->next = NULL;
    if((*head)->next==NULL){
        (*head)->next = prev;
        return;
    }
    struct LLOfCharacter *next = (*head)->next;
    while(next!=NULL){
        (*head)->next = prev;
        prev = (*head);
        (*head) = next;
        next = next->next;
    }
    (*head)->next = prev;
}

int length(struct LLOfCharacter *head){
    int size = 0;
    while(head!=NULL){
        size++;
        head = head->next;
    }
    return size;
}