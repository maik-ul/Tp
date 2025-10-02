#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

// Fonction pour créer un nouveau noeud
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

// Fonction pour insérer un élément dans une liste triée
void insert_sorted(Node** head, int value) {
    Node* node = create_node(value);

    // Cas où la liste est vide ou l'élément doit être inséré en tête
    if (*head == NULL || (*head)->value >= value) {
        node->next = *head;
        *head = node;
        return;
    }

    // Parcours pour trouver la bonne position
    Node* cur = *head;
    while (cur->next != NULL && cur->next->value < value) {
        cur = cur->next;
    }
    node->next = cur->next;
    cur->next = node;
}

// Fonction pour trier la liste (tri par insertion)
void sort_list(Node** head) {
    Node* sorted = NULL;
    Node* current = *head;
    while (current != NULL) {
        Node* next = current->next;
        // Insertion dans la nouvelle liste triée
        if (sorted == NULL || current->value < sorted->value) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* temp = sorted;
            while (temp->next != NULL && temp->next->value < current->value) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    *head = sorted;
}

// Fonction pour afficher la liste
void print_list(const Node* head) {
    const Node* cur = head;
    printf("Liste actuelle : ");
    while (cur) {
        printf("%d ", cur->value);
        cur = cur->next;
    }
    printf("\n");
}

// Fonction pour libérer la mémoire de la liste
void free_list(Node** head) {
    Node* cur = *head;
    while (cur) {
        Node* tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    *head = NULL;
}

// Fonction principale interactive
int main() {
    Node* head = NULL;
    int choix, valeur;

    printf("=== Insertion dans une liste simplement chainée triée ===\n");

    do {
        printf("\nMenu :\n");
        printf("1. Insérer un élément (trié automatiquement)\n");
        printf("2. Afficher la liste\n");
        printf("3. Trier la liste\n");
        printf("4. Quitter\n");
        printf("Votre choix : ");
        if (scanf("%d", &choix) != 1) {
            printf("Entrée invalide. Veuillez réessayer.\n");
            // Vider le buffer
            while (getchar() != '\n');
            continue;
        }

        switch (choix) {
            case 1:
                printf("Entrez la valeur à insérer : ");
                if (scanf("%d", &valeur) != 1) {
                    printf("Entrée invalide. Veuillez réessayer.\n");
                    while (getchar() != '\n');
                    break;
                }
                insert_sorted(&head, valeur);
                printf("Valeur %d insérée avec succès.\n", valeur);
                break;
            case 2:
                print_list(head);
                break;
            case 3:
                sort_list(&head);
                printf("La liste a été triée.\n");
                break;
            case 4:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 4);

    free_list(&head);
    return 0;
}


