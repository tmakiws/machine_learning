/* 8-1.c 課題：要素の探索、挿入、削除 */

#include<stdio.h>
#include<stdlib.h>

struct list{
	int number ;
	struct list *next ;
};

void search_list(int number);
void add_list(int number);
void delete_list(int number);
void show_list(struct list *p);
void free_list(struct list *p);

struct list *head = NULL;
struct list *tail = NULL;

int main(){
	int number;
	
	add_list(1);
	add_list(2);
	add_list(3);
	add_list(4);
	add_list(5);
	add_list(4);
	add_list(3);
	
	
	while(1){
		
		printf("\ncurrent list: ");
		show_list(head) ;
		
		printf("\ncommand? (search:1, insert:2, delete:3): ");
		int command ;
		scanf("%d", &command);
		if(command == 1){
			printf("value ?:");
			scanf("%d", &number);
			search_list(number);
		}
		else if(command == 2){
			printf("value ?: ");
			scanf("%d", &number);
			add_list(number);
		}
		else if(command == 3){
			printf("value ?: ");
			scanf("%d", &number);
			delete_list(number);
		}
	}
	
	free_list(head) ;
	
	return 0 ;
}

void search_list(int number){
	struct list *p;
	if(head == NULL) printf("Not Found\n");
	for(p = head; p != NULL; p = p->next){
		if(p->number == number){
			printf("Found\n") ;
			break;
		}
	}
	if(p == NULL){
		printf("Not Found\n");
	}
}

void add_list(int number){
	
	struct list *p ;
	
	if((p = (struct list *) malloc(sizeof(struct list))) == NULL){
		printf("malloc error \n") ;
		return;
	}
	
	p->number = number ;
	if(tail == NULL){
		tail = p;
		head = p;
	}
	else{
		tail->next = p;
		tail = p ;
	}
}

void delete_list(int number){
	
	struct list *p ;
	if(head == NULL) return;
	if(head->number == number){
		head = head->next;
		return;
	}
	struct list *q = head ;
	
	for(p = head->next; p != NULL; p = p->next){
		if(p->number == number){
			q->next = p->next;
			if(q->next == NULL) tail = q;
		}
		else{
			q = p ;
		}
	}
}

void show_list(struct list *p){
	while(p != NULL){
		printf("%d ", p->number);
		p = p->next;
	}
}

void free_list(struct list *p){
	struct list *p2 ;
	while(p != NULL){
		p2 = p->next ;
		free(p);
		p = p2 ;
	}
}
