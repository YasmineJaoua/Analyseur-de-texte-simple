
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//CHAIMA
int fonction_nombre_de_lettre(char* texte)
{
    int s = 0, i;
    int n = strlen(texte);
    for (i = 0; i < n; i++)
        if ((texte[i] >= 'a' && texte[i] <= 'z') ||
            (texte[i] >= 'A' && texte[i] <= 'Z'))
            s++;

    return s;
}
//CHAIMA
int fonction_nombre_d_espace(char* texte)
{
    int s = 0, i;
    int n = strlen(texte);

    for (i = 0; i < n; i++)
        if (texte[i] == ' ')
            s++;

    return s;
}
//CHAIMA
int fonction_nombre_de_majuscule(char* texte)
{
    int s = 0, i;
    int n = strlen(texte);

    for (i = 0; i < n; i++)
        if (texte[i] >= 'A' && texte[i] <= 'Z')
            s++;

    return s;
}
//CHAIMA
int fonction_nombre_de_minuscule(char* texte)
{
    int s = 0, i;
    int n = strlen(texte);

    for (i = 0; i < n; i++)
        if (texte[i] >= 'a' && texte[i] <= 'z')
            s++;

    return s;
}
//YASMINE
int est_caractere_de_mot(char c) {
    return (c >= 'a' && c <= 'z') || 
           (c >= 'A' && c <= 'Z') || 
           c == '-' || 
           c == '\'';
}

int est_separateur(char c) {
    return c == ' ' || c == ',' || c == '.' || c == '!' ||
           c == '?' || c == ';' || c == ':' || c == '\"' ||
           c == '@' || c == '&' || c == '(' || c == ')' ||
           c == '[' || c == ']' || c == '/';
}

//calculer le nombre des mots 
int fonction_nombre_de_mots(char* txt) {
    int nombre_de_mots = 0;
    int longueur_texte = strlen(txt);
    
    if (longueur_texte == 0) return 0;
    
    // Gestion du 1ere caractere
    if (est_caractere_de_mot(txt[0])) {
        nombre_de_mots = 1;
    }
    
    // Parcourir le texte a partir du 2eme caractere
    for (int i = 1; i < longueur_texte; i++) {
        // Verifier si on a un SEPARATEUR à la position i
        if (est_separateur(txt[i])) {
            // Verifier si le caractère PRECEDENT (i-1) fait partie d'un mot
            if (est_caractere_de_mot(txt[i-1])) {
                // Alors fin d'un mot, on le compte
                nombre_de_mots++;
            }
        }
    }
    
    // Gestion pour le DERNIER mot
    // Si le texte ne se termine pas par un separateur
    if (longueur_texte > 0 && est_caractere_de_mot(txt[longueur_texte-1])) {
        // Vérifier si le dernier caractère n'est pas un séparateur
        int dernier_est_separateur = est_separateur(txt[longueur_texte-1]);
        
        if (!dernier_est_separateur) {
            // On doit vérifier qu'on n'a pas déjà compté ce mot
            // Le mot serait compté seulement si avant lui il y a un séparateur
            int avant_dernier_est_dans_mot = 0;
            if (longueur_texte >= 2) {
                avant_dernier_est_dans_mot = est_caractere_de_mot(txt[longueur_texte-2]);
            }
            
            if (!avant_dernier_est_dans_mot) {
                // C'est un mot isolé à la fin, on l'ajoute
                nombre_de_mots++;
            }
        }
    }
    
    return nombre_de_mots;
}

//AMAL
char* mots_plus_longue(char texte[]) {
    int i = 0;
    int debutMot = 0;
    int longueur_Actuelle = 0;
    int debutMotPlusLong = 0;
    int longueurMax = 0;
    int n = strlen(texte);

    for (i = 0; i <= n; i++) {
        if (i < n && (isalpha(texte[i]) || texte[i] == '-' || texte[i] == '\'')) {
            if (longueur_Actuelle == 0) {
                debutMot = i;
            }
            longueur_Actuelle++;
            } 
        else //wa9t i=n
        {
            if (longueur_Actuelle > longueurMax) {
                longueurMax = longueur_Actuelle;
                debutMotPlusLong = debutMot;
        }
            longueur_Actuelle = 0; 
        }
    }

    if (longueurMax == 0) {
        char* mot = malloc(1*sizeof(char));
        mot[0] = '\0';
        return mot;
    }

    char* mot = malloc(longueurMax + 1); //na9ra 7seb l \0
    for (i = 0; i < longueurMax; i++)
        mot[i] = texte[debutMotPlusLong + i];
    mot[longueurMax] = '\0';
    return mot;
}

//CHAIMA
//longueur_moyenne_des_mots
float longueur_moyenne_des_mots(char* texte)
{
    float longueur_moyenne_des_mots;
    int a,b;
    b=fonction_nombre_de_lettre(texte);
    a=fonction_nombre_de_mots(texte);

    if(a > 0)
        longueur_moyenne_des_mots = (float)b/a;
    else
        longueur_moyenne_des_mots = 0;

    return longueur_moyenne_des_mots;
}
//YASMINE
//Calculer la fréquence de chaque lettre (ex. histogramme des lettres)
int*  frequence_de_chaque_lettre(char texte[])
{
    int i, j;
    int n = strlen(texte);
    
    // Conversion en minuscules
    char* texte_copie = malloc(n + 1);
    strcpy(texte_copie, texte);
    
    for(i=0; i<n; i++)
    {
        if('A'<=texte_copie[i] && texte_copie[i]<='Z') 
            texte_copie[i] += 32;
    }

    int* freq = malloc(26 * sizeof(int));

    for(i=0; i<26; i++) 
        freq[i]=0;

    for(j=0; j<n; j++){
        if (texte_copie[j]>='a' && texte_copie[j]<='z'){
            freq[ texte_copie[j]-'a' ]++;
        }
    }

    free(texte_copie);
    return freq;
}

//programme principale
int main()
{
    int a, b, c, d, e;
    float f;
    int* freq;
    char* motPlusLong;
    FILE* fichier;
    
    //lire le texte
    char texte[1000];
    
    printf("Entrer le texte:\n");
    if (fgets(texte, 1000, stdin) != NULL)
    {
        // Supprimer le saut de ligne à la fin
        texte[strcspn(texte, "\n")] = 0;
        
        a = fonction_nombre_de_mots(texte);
        printf("le nombre de mots est %d\n", a);

        b = fonction_nombre_de_lettre(texte);
        printf("le nombre de lettre est %d\n", b);

        c = fonction_nombre_d_espace(texte);
        printf("le nombre d'espaces est %d\n", c);

        d = fonction_nombre_de_majuscule(texte);
        printf("le nombre de majuscules est %d\n", d);

        e = fonction_nombre_de_minuscule(texte);
        printf("le nombre de minuscules est %d\n", e);

        motPlusLong = mots_plus_longue(texte);
        printf("le mot le plus long est %s\n", motPlusLong);

        f = longueur_moyenne_des_mots(texte);
        printf("la longueur moyenne des mots est %f\n", f);

        freq = frequence_de_chaque_lettre(texte);
        
        int i;
        for (i = 0; i < 26; i++)
            printf("le caractere %c existe %d fois dans le texte\n", 'a' + i, freq[i]);
//AMAL
        // Sauvegarder les résultats dans un fichier .txt.
        fichier = fopen("resultats.txt", "w");

        fprintf(fichier, "Analyse du texte\n\n");
        fprintf(fichier, "Mots : %d\n", a);
        fprintf(fichier, "Lettres : %d\n", b);
        fprintf(fichier, "Espaces : %d\n", c);
        fprintf(fichier, "Majuscules : %d\n", d);
        fprintf(fichier, "Minuscules : %d\n", e);
        fprintf(fichier, "Mot le plus long : %s\n", motPlusLong);
        fprintf(fichier, "Longueur moyenne : %.2f\n\n", f);

        fprintf(fichier, "Fréquence des lettres :\n");
        for (i = 0; i < 26; i++)
            fprintf(fichier, "%c : %d\n", 'a' + i, freq[i]);

        fclose(fichier);
        
        free(freq);
        free(motPlusLong);
    }

    return 0;
}




