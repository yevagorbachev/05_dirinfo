struct node {char * item ; struct node * next;};
void print_list(struct node * head);
struct node * insert_front(struct node * head, char * item);
struct node * free_list(struct node * head);