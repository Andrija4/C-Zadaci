#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu() {
    printf("\nOdaberite jednu od sledecih opcija:\n");
    printf("\t1: ucitavanje sojeva iz fajla\n");
    printf("\t2: ispis sojeva na konzolu\n");
    printf("\t3: prebrojavanje sojeva koji pocinju odgovarajucim slovom\n");
    printf("\t4: ispis varijanti\n");
    printf("\t5: brisanje podataka iz memorije i izlaz iz programa\n");
    printf("\nVasa opcija: ");
    int n;
    scanf("%d", &n);
    return n;
}

typedef struct {
    char naziv[15];
    char klasa[20];
    char drzava[20];
    int godina;
} varijanta;

varijanta* varijanta_kreiraj(char naziv[], char klasa[], char drzava[], int godina) {
    varijanta* varijanta = malloc(sizeof(varijanta));
    strcpy(varijanta->naziv, naziv);
    strcpy(varijanta->klasa, klasa);
    strcpy(varijanta->drzava, drzava);
    varijanta->godina = godina;
    return varijanta;
}

int varijanta_poredi(varijanta* v1, varijanta* v2) {
    return strcmp(v1->naziv, v2->naziv);
}

int varijanta_se_poklapa(varijanta* varijanta,
                         char naziv[], char klasa[], char drzava[], int godina) {
    if (strcmp(varijanta->naziv, naziv) == 0)
        return 1;
    if (strcmp(varijanta->klasa, klasa) == 0)
        return 1;
    if (strcmp(varijanta->drzava, drzava) == 0)
        return 1;
    return varijanta->godina == godina;
}

void varijanta_ispisi(varijanta* varijanta) {
    printf("%s\t%s\t%s\t%d\n", varijanta->naziv, varijanta->klasa,
                                varijanta->drzava, varijanta->godina);
}

void varijanta_obrisi(varijanta* varijanta) {
    free(varijanta);
}

typedef struct variant_tree {
    varijanta* value;
    struct variant_tree* left;
    struct variant_tree* right;
} variant_tree;

variant_tree* variant_tree_create(varijanta* varijanta) {
    variant_tree* vars = (variant_tree*) calloc(1, sizeof(variant_tree));
    vars->value = varijanta;
    return vars;
}

variant_tree* variant_tree_add(variant_tree* root, variant_tree* e) {
    if (root == NULL)
        return e;
    if (varijanta_poredi(root->value, e->value) > 0)
        root->left = variant_tree_add(root->left, e);
    else
        root->right = variant_tree_add(root->right, e);
    return root;
}

varijanta* variant_tree_variant_exists(variant_tree** root,
                                char naziv[], char klasa[], char drzava[], int godina) {
    if (root == NULL) {
        varijanta* var = varijanta_kreiraj(naziv, klasa, drzava, godina);
        *root = variant_tree_add(*root, variant_tree_create(var));
        return var;
    }
    if (varijanta_se_poklapa((*root)->value, naziv, klasa, drzava, godina))
        return (*root)->value;
    varijanta* left = variant_tree_variant_exists(&((*root)->left), naziv, klasa, drzava, godina);
    if (left == NULL)
        return variant_tree_variant_exists(&((*root)->right), naziv, klasa, drzava, godina);
    return left;
}

void variant_tree_print(variant_tree* root) {
    if (root) {
        variant_tree_print(root->left);
        varijanta_ispisi(root->value);
        variant_tree_print(root->right);
    }
}

void variant_tree_erase(variant_tree* root) {
    if (root) {
        variant_tree_erase(root->left);
        variant_tree_erase(root->right);
        varijanta_obrisi(root->value);
        free(root);
    }
}

typedef struct {
    varijanta* varijanta;
    char naziv[15];
} soj;

soj* soj_kreiraj(char varijanta[], char klasa[], char drzava[], int godina, char naziv[],
                 variant_tree** varijante) {
    soj* soj = malloc(sizeof(soj));
    soj->varijanta = variant_tree_variant_exists(varijante, varijanta, klasa, drzava, godina);
    strcpy(soj->naziv, naziv);
    return soj;
}

int soj_poredi(soj* s1, soj* s2) {
    return strcmp(s1->naziv, s2->naziv);
}

void soj_ispisi(soj* soj) {
    printf("%s %s %s %d %s\n", soj->varijanta->naziv, soj->varijanta->klasa,
                                soj->varijanta->drzava, soj->varijanta->godina, soj->naziv);
}

void soj_obrisi(soj* soj) {
    free(soj);
}

typedef struct tree {
    soj* value;
    struct tree* left;
    struct tree* right;
} tree;

tree* tree_create(char varijanta[], char klasa[], char drzava[], int godina, char naziv[],
                 variant_tree** varijante) {
    tree* e = (tree*) malloc(sizeof(tree));
    e->value = soj_kreiraj(varijanta, klasa, drzava, godina, naziv, varijante);
    e->left = NULL;
    e->right = NULL;
    return e;
}

tree* tree_add(tree* root, tree* e) {
    if (root == NULL)
        return e;
    if (soj_poredi(root->value, e->value) > 0)
        root->left = tree_add(root->left, e);
    else
        root->right = tree_add(root->right, e);
    return root;
}

void tree_print(tree* root) {
    if (root) {
        tree_print(root->left);
        soj_ispisi(root->value);
        tree_print(root->right);
    }
}

void tree_erase(tree* root) {
    if (root) {
        tree_erase(root->left);
        tree_erase(root->right);
        soj_obrisi(root->value);
        free(root);
    }
}

tree* zad1(char* filename, variant_tree** root) {
    FILE* f = fopen(filename, "r");
    if (f == NULL) {
        printf("Fajl ne postoji u trenutnom direktorijumu\n");
        return NULL;
    }
    tree* e = NULL;
    char line[200] = {0};
    char naziv[15] = {0};
    char klasa[20] = {0};
    char drzava[20] = {0};
    int godina;
    while (fscanf("%[^\n]\n", line) == 1) {
        if (strchr(line, ";")) {
            strcpy(naziv, strtok(line, ";"));
            strcpy(klasa, strtok(NULL, ";"));
            strcpy(drzava, strtok(NULL, ";"));
            godina = atoi(strtok(NULL, ";"));
        } else {
            e = tree_add(e, tree_create(naziv, klasa, drzava, godina, line, root));
        }
    }
    fclose(f);
    return e;
}

void zad2(tree* root) {
    tree_print(root);
}

void zad3(tree* root) {
}

void zad4() {
}

void zad5(tree* root) {
    tree_erase(root);
}

int main() {
    int n;
    tree* e = NULL;
    variant_tree* variants = NULL;
    do {
        int n = menu();
        switch (n) {
            case 1: e = zad1("covid19.txt"); break;
            case 2: zad2(e); break;
            case 3: zad3(e); break;
            case 4: zad4(); break;
            case 5: zad5(e); return 0;
            default: printf("Niste uneli validnu opciju\n");
        }
    } while (n != 5);
    return 0;
}
