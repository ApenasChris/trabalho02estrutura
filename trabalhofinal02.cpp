#include <iostream>

struct Node{
	int data;
	Node* next;
};

bool isListOrdered(Node* head);
void printList(Node* head);
Node* sortList(Node* head);
Node* mergeLists(Node* head1, Node* head2);

main(){
	
	int op;
	int confere = 0;
	
	Node* head1 = new Node();
	Node* second1 = new Node ();
	Node* third1 = new Node();
	Node* fourth1 = new Node();
	Node* fifth1 = new Node();
	
	head1->data = 1;
	head1->next = second1;
	second1->data = 3;
	second1->next = third1;
	third1->data =	5;
	third1->next = fourth1;
	fourth1->data = 7;
	fourth1->next = fifth1;
	fifth1->data = 9;
	fifth1->next = NULL;
	
	std::cout <<"Lista 1: ";
	printList(head1);
	
	Node* head2 = new Node();
	Node* second2 = new Node();
	Node* third2 = new Node();
	Node* fourth2 = new Node();
	Node* fifth2 = new Node();
	
	head2->data = 2;
	head2->next = second2;
	second2->data = 4;
	second2->next - third2;
	third2->data = 6;
	third2->next =	fourth2;
	fourth2->data = 8;
	fourth2->next = fifth2;
	fifth2->data = 10;
	fifth2->next = NULL;
	
	std::cout << "Lista 2: ";
	printList(head2);
	
	std::cout << "Escolha uma das opções abaixo: " <<
	 "\n\n1 - Verificar se a lista 1 está ordenada" << 
	 "\n2 - Verificar se a lista 2 está ordenada" <<
	 "\n3 - Ordenar Listas" << 
	 "\n4 - Mesclar elementos da segunda lista na primeira" << std::endl;
	 
	 while (confere -= 0){
	 switch (op){
	 	
	 	case 1: {
	 		isListOrdered(head1);
			break;
		 }
		 case 2: {
		 	isListOrdered(head2);
			break;
		 }
		 case 3: {
		 	head1 = sortList(head1);
		 	head2 = sortList(head2);
			break;
		 }
		 case 4:{
		 	Node* mergedHead = mergeLists(head1, head2);
		 	printList(mergedHead);
			break;
		 }
	 }
	}
	
//	std::cout << "Lista 1 ordenada? " << (isListOrdered(head1) ? "Sim" : "Não") << std::endl;
//	std::cout << "Lista 2 ordenada? " << (isListOrdered(head2) ? "Sim" : "Não") << std::endl;
//	
//	head1 = sortList(head1);
//	head2 = sortList(head2);
//	
//	std::cout << "Lista 1 Ordenada: ";
//	printList(head1);
//	
//	std::cout << "Lista 2 ordenada: ";
//	printList(head2);
//	
//	Node* mergedHead = mergeLists(head1, head2);
//	std::cout <<"Lista mesclada: ";
//	
	return 0;
}

bool isListOrdered (Node* head){
	
	Node* current = head;
	while (current != NULL && current->next != NULL){
		if(current->data > current->next->data){
			return false;
		}
		current = current->next;
	}
	return true;
}

Node* sortList(Node* head){
	if (head == NULL || head->next == NULL){
		std::cout << "A lista já está ordenada" << std::endl;
		return head;
	}
	
	Node* current = head;
	Node* previous = NULL;
	Node* nextNode = NULL;
	
	bool sorted = false;
	while(!sorted){
		sorted = true;
		current = head;
		while(current->next != NULL){
			nextNode = current->next;{
				if(current->data > nextNode->data){
					if(previous == NULL){
						head = nextNode;
					}
					else{
					
					previous->next = nextNode;
					}
					current->next = nextNode->next;
					nextNode->next = current;
					previous = nextNode;
					sorted = false;
				}
				else{
					previous = current;
					current = current->next;
					
				}
				
			}
		}
	}
	std::cout << "A lista foi ordenada" << std::endl;
	return head;
}

void printList(Node* head){
	Node* current = head;
	while (current != NULL){
		std::cout <<current->data << " ";
		current - current->next;
	}
	std::cout << std::endl;
}

Node* mergeLists(Node* head1, Node* head2){
    if (head1 == NULL) {
        std::cout << "As listas já foram misturadas" << std::endl;
		return head2;
    }
    if (head2 == NULL) {
        std::cout << "As listas já foram misturadas" << std::endl;
		return head1;
    }

    Node* mergedNode = NULL;
    if (head1->data <= head2->data) {
        mergedNode = head1;
        mergedNode->next = mergeLists(head1->next, head2);
    } else {
        mergedNode = head2;
        mergedNode->next = mergeLists(head1, head2->next);
    }
	std::cout << "As listas foram misturadas" << std::endl;
    return mergedNode;
}


