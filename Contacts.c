#include <stdio.h>
#include <unistd.h>
#include <string.h>

struct Dico{
    char PPseudo[5];
    char PMdp[50];
};

int LireMdp(struct Dico Paire){
    printf("%s\n", Paire.PMdp);
    return 0;
};

int main(){
    printf("Votre pseudo ? (Max 5 char):");
    int l;
    char Entry[5];
    scanf("%5s", Entry);
    printf("%s\n", Entry);
    while((l = getchar()) != '\n' && l != EOF){
        printf("Emptying Buffer pls wait...\n");
        sleep(2);
    }
    char * pPseudo = Entry;
    struct Dico Paire1;
    strcpy(Paire1.PPseudo, pPseudo);
    printf("Mdp sans maj (Max 50 char):");
    int c;
    char Entry2[50];
    scanf("%50s", Entry2);
    printf("%s\n", Entry2);
    while((c = getchar()) != '\n' && c != EOF){
        printf("Emptying Buffer pls wait...\n");
        sleep(2);
    }
    char * pMdp = Entry2;
    strcpy(Paire1.PMdp, pMdp);

    printf("Acceder ? (oui/non):");
    int n;
    char Entry3[3];
    scanf("%3s", Entry3);
    printf("%s\n", Entry3);
    while((n = getchar()) != '\n' && n != EOF){
        printf("Emptying Buffer pls wait...\n");
        sleep(2);
    }

    if(strcmp(Entry3, "oui") == 0)
        LireMdp(Paire1);

    return 0;
}