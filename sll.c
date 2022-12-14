#include<stdio.h>
#include<stdlib.h>

typedef struct sll {
	struct sll *next;
	int data;
}node;


void InsertAtBeg(node **head, int val){
	node *ptr = (node *)malloc(sizeof(node));
	ptr->data = val;

	if(*head == NULL){
		ptr->next = NULL;
		*head = ptr;
	}
	else{
		ptr->next = *head;
		*head = ptr;
	}
}

void InsertAtEnd(node **head , int item){
	node *ptr = (node *)malloc(sizeof(node));
	node *last;
	last = *head;

	ptr->data = item;

	if(*head == NULL){
		ptr->next = NULL;
		*head = ptr;
	}
	else{
		while(last->next != NULL){
			last = last->next;
		}
		ptr->next = NULL;
		last->next = ptr;

	}
}


void dislay(node *head){
	if(head == NULL){
		printf("List Empty!");
		return; 
	}
	else
	{
		while(head->next != NULL){
			printf("%d ", head->data);
			head = head->next;
		}
	}
}

void DeleteAtBeg(node **head){
	node *temp;
	if(*head == NULL)
	{
		printf("List Already Empty!");
		return;
	}
	// else if(*head->next == NULL){
	// 	*head = NULL;
	// }
	else{
		temp = *head;
		*head = temp->next;
		printf("Deleted Item: %d",temp->data);
		free(temp); 
	}
}


void DeleteAtEnd(node **head){
	node *last,*temp;
	last = *head;
	
	if(*head == NULL)
	{
		printf("List Already Empty!");
		return;
	}
	// else if(*head->next == NULL){
	// 	*head = NULL;
	// }
	else{

		while(last->next->next != NULL){
			last = last->next;
		}
		
		temp = last->next;
		last->next = NULL;
		printf("Deleted Item: %d",temp->data);
		free(temp); 
	}
}

int main()
{
	node *head = NULL;

	while(1){
		printf("\t\t\1. Inset At Beginning \n");
		printf("\t\t\2. Inset At End \n");
		printf("\t\t\3. Delete At Beginning \n");
		printf("\t\t\4. Delete At End \n");
		printf("\t\t\5. Search Element \n");
		printf("\t\t\6. Display \n");

		int opt, data;
		scanf("%d",*opt);

		switch(opt){
			case 1: printf("\nEnter Data");
					scanf("%d",&data);
					InsertAtBeg(&head, data);
				break;
			
			case 2: printf("\nEnter Data");
					scanf("%d",&data);
					InsertAtEnd(&head, data);
				break;

			case 3: DeleteAtBeg(&head);
				break;

			case 4: DeleteAtEnd(&head);
				break;

			case 5: dislay(&head);
				break;

			case 6: continue;
				break;

			default: exit(0);

		}


	}
}