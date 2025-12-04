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

    for (i = 1; i < n - 2; i++)  
    {
        if (
               (*(txt+i)==' ' || *(txt+i)==',' 
            || *(txt+i)=='.' || *(txt+i)=='!' 
            || *(txt+i)=='?' || *(txt+i)==';' 
            || *(txt+i)==':' || *(txt+i)=='\"' 
            || *(txt+i)=='@' || *(txt+i)=='&' 
            || *(txt+i)=='(' || *(txt+i)==')' 
            || *(txt+i)=='[' || *(txt+i)==']' 
            || *(txt+i)=='/' )  // separateurs

            &&

               ( *(txt+i-1)=='-' || *(txt+i-1)=='\'' 
            || (*(txt+i-1)>='a' && *(txt+i-1)<='z')
            || (*(txt+i-1)>='A' && *(txt+i-1)<='Z') ) //elli 9ablou 7arf mn kelma donc nmarki kelma
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
