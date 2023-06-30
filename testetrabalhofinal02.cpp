#include <iostream>

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* insertNode(Node* head, int data) {
    if (head == NULL) {
        head = createNode(data);
    } else {
        Node* currentNode = head;
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = createNode(data);
    }
    return head;
}

void printList(Node* head) {
    Node* currentNode = head;
    while (currentNode != NULL) {
        std::cout << currentNode->data << " ";
        currentNode = currentNode->next;
    }
    std::cout << std::endl;
}

bool isListOrdered(Node* head) {
    Node* currentNode = head;
    while (currentNode != NULL && currentNode->next != NULL) {
        if (currentNode->data > currentNode->next->data) {
            return false;
        }
        currentNode = currentNode->next;
    }
    return true;
}

Node* sortList(Node* head) {
    if (head == NULL || head->next == NULL) {
        std::cout << "A lista já está ordenada" << std::endl;
        return head;
    }

    Node* current = head;
    Node* previous = NULL;
    Node* nextNode = NULL;

    bool sorted = false;
    while (!sorted) {
        sorted = true;
        current = head;
        while (current->next != NULL) {
            nextNode = current->next;
            if (current->data > nextNode->data) {
                if (previous == NULL) {
                    head = nextNode;
                } else {
                    previous->next = nextNode;
                }
                current->next = nextNode->next;
                nextNode->next = current;
                previous = nextNode;
                sorted = false;
            } else {
                previous = current;
                current = current->next;
            }
        }
    }

    std::cout << "A lista foi ordenada" << std::endl;
    return head;
}

Node* mergeLists(Node* head1, Node* head2) {
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

int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;

    // Inserir elementos na lista 1
    head1 = insertNode(head1, 5);
    head1 = insertNode(head1, 2);
    head1 = insertNode(head1, 8);
    head1 = insertNode(head1, 1);
    head1 = insertNode(head1, 9);

    // Inserir elementos na lista 2
    head2 = insertNode(head2, 3);
    head2 = insertNode(head2, 6);
    head2 = insertNode(head2, 4);
    head2 = insertNode(head2, 7);

    std::cout << "Lista 1: ";
    printList(head1);

    std::cout << "Lista 2: ";
    printList(head2);

    std::cout << "Lista 1 ordenada? " << (isListOrdered(head1) ? "Sim" : "Não") << std::endl;
    std::cout << "Lista 2 ordenada? " << (isListOrdered(head2) ? "Sim" : "Não") << std::endl;

    head1 = sortList(head1);
    std::cout << "Lista 1 ordenada: ";
    printList(head1);

    std::cout << "Lista 2 ordenada: ";
    printList(head2);

    Node* mergedList = mergeLists(head1, head2);
    std::cout << "Listas mescladas: ";
    printList(mergedList);

    return 0;
}
