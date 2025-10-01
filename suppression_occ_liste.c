#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* create_node(int value);
void push_back(Node** head, int value);
void delete_all_occurrences(Node** head, int target);
void print_list(const Node* head);
void free_list(Node** head);

Node* create_node(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (!node) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }
    node->value = value;
    node->next = NULL;
    return node;
}

void push_back(Node** head, int value) {
    Node* node = create_node(value);
    if (*head == NULL) {
        *head = node;
        return;
    }
    Node* cur = *head;
    while (cur->next) {
        cur = cur->next;
    }
    cur->next = node;
}

void delete_all_occurrences(Node** head, int target) {
    if (head == NULL || *head == NULL) {
        return;
    }

    // Supprimer en tête tant que nécessaire
    while (*head && (*head)->value == target) {
        Node* to_delete = *head;
        *head = (*head)->next;
        free(to_delete);
    }
    if (*head == NULL) {
        return;
    }

    // Supprimer dans le reste de la liste
    Node* cur = *head;
    while (cur->next) {
        if (cur->next->value == target) {
            Node* to_delete = cur->next;
            cur->next = cur->next->next;
            free(to_delete);
        } else {
            cur = cur->next;
        }
    }
}

void print_list(const Node* head) {
    const Node* cur = head;
    int first = 1;
    while (cur) {
        if (!first) {
            printf(" ");
        }
        printf("%d", cur->value);
        first = 0;
        cur = cur->next;
    }
    printf("\n");
}

void free_list(Node** head) {
    Node* cur = *head;
    while (cur) {
        Node* next = cur->next;
        free(cur);
        cur = next;
    }
    *head = NULL;
}

int main(void) {
    int n;
    printf("Entrez le nombre d'elements: ");
    fflush(stdout);
    if (scanf("%d", &n) != 1 || n < 0) {
        fprintf(stderr, "Entrée invalide pour n\n");
        return EXIT_FAILURE;
    }

    Node* head = NULL;
    for (int i = 0; i < n; ++i) {
        int x;
        printf("Entrez l'element %d: ", i + 1);
        fflush(stdout);
        if (scanf("%d", &x) != 1) {
            fprintf(stderr, "Entrée invalide pour l'élément %d\n", i + 1);
            free_list(&head);
            return EXIT_FAILURE;
        }
        push_back(&head, x);
    }

    int target;
    printf("Entrez la valeur a supprimer: ");
    fflush(stdout);
    if (scanf("%d", &target) != 1) {
        fprintf(stderr, "Entrée invalide pour la valeur à supprimer\n");
        free_list(&head);
        return EXIT_FAILURE;
    }

    delete_all_occurrences(&head, target);
    printf("Liste resultante: ");
    print_list(head);
    free_list(&head);
    return EXIT_SUCCESS;
}