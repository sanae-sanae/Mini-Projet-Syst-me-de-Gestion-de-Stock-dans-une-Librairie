#include <stdio.h>
#include <string.h>

int main() {
    char titres[100][100];  
    char auteurs[100][100];  
    float prix[100];         
    int quantite[100];       
    int n = 0;              

    int choix = 0;
    int i;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Ajouter un livre au stock\n");
        printf("2. Afficher tous les livres disponibles\n");
        printf("3. Rechercher un livre par son titre\n");
        printf("4. Mettre à jour la quantité d'un livre\n");
        printf("5. Supprimer un livre\n");
        printf("6. Voir le total des livres\n");
        printf("0. Quitter\n");
        printf("Sélectionnez le choix que vous voulez : ");
        scanf("%d", &choix);
        getchar();

        switch (choix) {
            case 1: 
                printf("Titre : ");
                scanf("%s", titres[n]);
                printf("Auteur : ");
                scanf("%s", auteurs[n]);
                printf("Prix : ");
                scanf("%f", &prix[n]);
                printf("Quantité : ");
                scanf("%d", &quantite[n]);
                n++;
                printf("Livre ajouté avec succès !\n");
                break;

            case 2:
                printf("\n--- Liste des livres ---\n");
                for (i = 0; i < n; i++) {
                    printf("Titre: %s | Auteur: %s | Prix: %.2f | Quantité: %d\n",
                           titres[i], auteurs[i], prix[i], quantite[i]);
                }
                break;

            case 3: 
                {
                    char recherche[100];
                    int trouve = 0;
                    printf("Entrez le titre à rechercher : ");
                    scanf("%s", recherche);
                    for (i = 0; i < n; i++) {
                        if (strcmp(titres[i], recherche) == 0) {
                            printf("Livre trouvé: %s | Auteur: %s | Prix: %.2f | Quantité: %d\n",
                                   titres[i], auteurs[i], prix[i], quantite[i]);
                            trouve = 1;
                            break;
                        }
                    }
                    if (!trouve) printf("Livre non trouvé.\n");
                }
                break;

            case 4:
                {
                    char recherche[100];
                    int trouve = 0;
                    printf("Entrez le titre du livre à mettre à jour : ");
                    scanf("%s", recherche);
                    for (i = 0; i < n; i++) {
                        if (strcmp(titres[i], recherche) == 0) {
                            printf("Quantité actuelle: %d\n", quantite[i]);
                            printf("Nouvelle quantité: ");
                            scanf("%d", &quantite[i]);
                            printf("Quantité mise à jour avec succès.\n");
                            trouve = 1;
                            break;
                        }
                    }
                    if (!trouve) printf(" Livre non trouvé.\n");
                }
                break;

            case 5: 
                {
                    char recherche[100];
                    int trouve = 0;
                    printf("Entrez le titre du livre à supprimer : ");
                    scanf("%s", recherche);
                    for (i = 0; i < n; i++) {
                        if (strcmp(titres[i], recherche) == 0) {
                            for (int j = i; j < n - 1; j++) {
                                strcpy(titres[j], titres[j+1]);
                                strcpy(auteurs[j], auteurs[j+1]);
                                prix[j] = prix[j+1];
                                quantite[j] = quantite[j+1];
                            }
                            n--;
                            printf("Livre supprimé avec succès.\n");
                            trouve = 1;
                            break;
                        }
                    }
                    if (!trouve) printf("Livre non trouvé.\n");
                }
                break;

            case 6:
                {
                    int total = 0;
                    for (i = 0; i < n; i++) {
                        total += quantite[i];
                    }
                    printf("Nombre total de livres en stock: %d\n", total);
                }
                break;

            case 0:
                printf(" Au revoir !\n");
                break;

            default:
                printf("Choix invalide.\n");
        }

    } while (choix != 0);

    return 0;
}
