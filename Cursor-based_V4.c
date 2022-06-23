//void initVirtualHeap_V2(VirtualHeap *VH){
//	int i;
//	for(i = SIZE-1; i >= 0; i--){
//		VH->Nodes[i].link = i-1;
//	}
//	VH->avail = SIZE-1;
//}

//typedef struct{
//	char data;
//	int link;
//}Nodetype;
//
//typedef struct node{
//	Nodetype Nodes[SIZE];
//	int avail;
//}*VirtualHeap;
//
//typedef int List;

//void initVirtualHeap_V4(VirtualHeap *VH){
//	int i;
//	*VH = calloc(1, sizeof(struct node));
//	for(i = 0; i < SIZE-1; i++){
//		(*VH)->Nodes[i].link = i-1;
//	}
//	(*VH)->avail = SIZE-1;
//}

//void visualSpace(VirtualHeap VH){
//	printf("\n%15s | %15s | %15s", "INDEX", "ELEM", "NEXT");
//	int i;
//	for(i = 0; i < SIZE; i++){
//		printf("\n%15d | %15d | %15d", i, VH->Nodes[i].data, VH->Nodes[i].link);
//	}
//	printf("\nAvailable: %d\n", VH->avail);
//}

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct{
	char data;
	int link;
}Nodetype;

typedef struct{
	Nodetype Nodes[SIZE];
	int avail;
}VirtualHeap;

typedef int List;

void initVirtualHeap_V1(VirtualHeap *VH){
	int i;
	for(i = 0; i < SIZE; i++){
		VH->Nodes[i].data = 0;
		VH->Nodes[i].link = i-1;
	}
	VH->avail = SIZE-1;
}

void visualSpace(VirtualHeap VH){
	printf("\n%15s | %15s | %15s", "INDEX", "ELEM", "NEXT");
	int i;
	for(i = 0; i < SIZE; i++){
		printf("\n%15d | %15d | %15d", i, VH.Nodes[i].data, VH.Nodes[i].link);
	}
	printf("\nAvailable: %d\n", VH.avail);
}

int allocateSpace(VirtualHeap *VH){
	int retAvail = VH->avail;
	if(retAvail != -1){
		VH->avail = VH->Nodes[retAvail].link;
	}
	return retAvail;
}

//Linked List
void insertFirst(List *L, char elem){
	List temp = malloc(sizeof(NodeType));
	if(temp != NULL){
		temp->data = elem;
		temp->link = *L;
		*L = temp;
	}
}

//Cursor-based
void insertFirst(List *L, char elem, VirtualHeap *VH){
	List temp = allocateSpace(VH);
	
	if(temp != -1){
		VH->Nodes[temp].data = elem;
		VH->Nodes[temp].link = *L;
		*L = temp;
	}
}

int main(){
	VirtualHeap VH;
	List L;

	initVirtualHeap_V1(&VH);
//	initVirtualHeap_V2(&VH);
//	initVirtualHeap_V4(&VH);
	visualSpace(VH);
	
	return 0;
}
