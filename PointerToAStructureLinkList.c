#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definition of Complete Name
typedef struct {
	char FName[20], MI, LName[20];
}nametype;

struct LNode {
	nametype name;
	struct LNode *link;
};

typedef struct node{
	struct LNode *elemPtr;
	int count;
}*LinkList;

void initList(LinkList *LL);
void populates(LinkList LL, nametype name);
LinkList getNames(LinkList LL, char LName[]);
void display(LinkList LL);

int main(){
	
	LinkList myList;
	
	nametype a[7] = {{"Ching", 'C', "Mendoza"}, {"Chala", 'A', "Llamido"},
				 {"Ryan", 'B', "Llamido"}, {"Krsyhna", 'K', "Jaye"},
				 {"Christine", 'D', "Bucag"}, {"Jonalyn", 'X', "Llamido"},
				 {"Yu", 'Z', "Llamats"}};
	char LName[] = "Llamido";
	
	int i;
	
	initList(&myList);
	for(i = 0; i < 7; i++) populates(myList, a[i]);
	display(myList);
	printf("GET NAMES:\n");
	LinkList newList = getNames(myList, LName);
	display(newList);
	return 0;
}

void initList(LinkList *LL){
	*LL = calloc(1, sizeof(struct node));
	(*LL)->elemPtr = NULL;
	(*LL)->count = 0;
}

void populates(LinkList LL, nametype name){
	struct LNode *temp;
	temp = malloc(sizeof(struct LNode));
	if(temp != NULL){
		temp->name = name;
		temp->link = LL->elemPtr;
		LL->elemPtr = temp;
	}
}

LinkList getNames(LinkList LL, char LName[]){
	struct LNode *temp, *trav;
	LinkList newList;
	initList(&newList);

	for(trav = LL->elemPtr; trav != NULL; trav = trav->link){
		if(strcmp(trav->name.LName, LName) == 0){
			temp = malloc(sizeof(struct LNode));
			if(temp != NULL){
				temp->name = trav->name;
				temp->link = newList->elemPtr;
				newList->elemPtr = temp;
				newList->count++;
			}
		}
	}
	
	return newList;
}


void display(LinkList LL){
	struct LNode *trav = LL->elemPtr;
	printf("%d\n", LL->count);
	printf("[ ");
	while(trav != NULL){
		printf("%10s", trav->name.LName);
		trav = trav->link;
	}
	printf(" ]\n");
}
