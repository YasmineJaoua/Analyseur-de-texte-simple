//YASMINE
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

int fonction_nombre_d_espace(char* texte)
{
    int s = 0, i;
    int n = strlen(texte);

    for (i = 0; i < n; i++)
        if (texte[i] == ' ')
            s++;

    return s;
}

int fonction_nombre_de_majuscule(char* texte)
{
    int s = 0, i;
    int n = strlen(texte);

    for (i = 0; i < n; i++)
        if (texte[i] >= 'A' && texte[i] <= 'Z')
            s++;

    return s;
}

int fonction_nombre_de_minuscule(char* texte)
{
    int s = 0, i;
    int n = strlen(texte);

    for (i = 0; i < n; i++)
        if (texte[i] >= 'a' && texte[i] <= 'z')
            s++;

    return s;
}
int fonction_nombre_de_mots(char* txt)
{
    int s = 0;
    int i;
    int n = strlen(txt);

    for (i = 1; i < n; i++)  
    {
        if (
               (*(txt+i)==' ' || *(txt+i)==',' 
            || *(txt+i)=='.' || *(txt+i)=='!' 
            || *(txt+i)=='?' || *(txt+i)==';' 
            || *(txt+i)==':' || *(txt+i)=='\"' 
            || *(txt+i)=='@' || *(txt+i)=='&' 
            || *(txt+i)=='(' || *(txt+i)==')' 
            || *(txt+i)=='[' || *(txt+i)==']' 
            || *(txt+i)=='/' )

            &&

               ( *(txt+i-1)=='-' || *(txt+i-1)=='\'' 
            || (*(txt+i-1)>='a' && *(txt+i-1)<='z')
            || (*(txt+i-1)>='A' && *(txt+i-1)<='Z') )
           )
        {
            s++;
        }
    }
 // yejem mayoufech b separateur donc ena nthabet ken ekhir 7arf separateur btbi3etha ekhir kelma bch tete7seb sinon nzidha wahdi
    if ( txt[n-1]=='-' || txt[n-1]=='\'' 
      || (txt[n-1]>='a' && txt[n-1]<='z')
      || (txt[n-1]>='A' && txt[n-1]<='Z') )
    {
        s++;
    }

    return s;
}

//AMAL 
void mots_plus_longue(char texte[]) {
    int i = 0;
    int debutMot = 0;
    int longueurActuelle = 0;
    int debutMotLePlusLong = 0;
    int longueurMax = 0;

    while (1) {
        // Si ce n'est pas un espace ni la fin de la chaîne
        if (texte[i] != ' ' && texte[i] != '\0') {
            longueurActuelle++;
        }
        else {
            // Fin d'un mot
            if (longueurActuelle > longueurMax) {
                longueurMax = longueurActuelle;
                debutMotLePlusLong = debutMot;
            }
            // Préparer pour le mot suivant
            longueurActuelle = 0;
            debutMot = i + 1;

            // Si on est à la fin de la chaîne, on sort
            if (texte[i] == '\0')
                break;
        }
        i++;
    }

    // Affichage du mot le plus long
    printf("Mot le plus long : ");
    for (i = debutMotLePlusLong; i < debutMotLePlusLong + longueurMax; i++) {
        printf("%c", texte[i]);
    }
    printf("\n");
}
//fichier 

//CHAIMA 
//
//

 //programme principale 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 int main()
 {
    int a, b, c, d, e;
    //Lire un texte
    char* texte ;
    texte=(char*)malloc(1000*sizeof(char));
    if (fgets(texte,1000,stdin)!=NULL) 
    {
        //et afficher le nombre de mots (yasmine)
        a=fonction_nombre_de_mots(texte);
        printf("le nombre de mots est %d",a);
        //et afficher le nombre de lettres (yasmine)
        b=fonction_nombre_de_lettre(texte);
        printf("le nombre de lettres est %d",b);
        //et afficher le nombre d’espaces (yasmine)
        c=fonction_nombre_d_espace(texte);
        printf("le nombre d’espaces est %d",c);
        //et afficher le nombre de majuscules (yasmine)
        d=fonction_nombre_de_majuscule(texte);
        printf("le nombre de majuscules est %d",d);
        //et afficher le nombre de minuscules (yasmine)
        e=fonction_nombre_de_minuscule(texte);
        printf("le nombre de minuscules est %d",e);
        //Trouver le mot le plus long (amal)
        mots_plus_longue(texte);
        //Calculer la longueur moyenne des mots (chaima)

        //Calculer la fréquence de chaque lettre (ex. histogramme des lettres) (chaima)

        //Sauvegarder les résultats dans un fichier .txt. (amal)

    }
    free(texte);
    return 0 ;
 }
