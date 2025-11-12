#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <gtk/gtk.h>

struct Dico{
    char PPseudo[5];
    char PMdp[50];
};

int LireMdp(struct Dico Paire){
    printf("%s\n", Paire.PMdp);
    return 0;
};

int GUI(int argc, char** argv, struct Dico Paire1){
    gtk_init(&argc, &argv);
    GtkWidget *window;
    GtkWidget *box;
    GtkWidget *label;
    GtkWidget *label2;
    char Var_[50];
    strcpy(Var_, Paire1.PMdp);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 100, 100);

    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);

    label2 = gtk_label_new("Now this is epic.");
    gtk_label_set_text(GTK_LABEL(label2), "Votre Mdp:");

    label = gtk_label_new("Now this is epic.");
    gtk_label_set_text(GTK_LABEL(label), Var_);

    gtk_box_pack_start(GTK_BOX(box), label2, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box), label, TRUE, TRUE, 0);
    gtk_container_add(GTK_CONTAINER(window), box);

    gtk_widget_show_all(window);
    gtk_main();
    return 0;
};

int main(int argc, char** argv){
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

    if(strcmp(Entry3, "oui") == 0){
        LireMdp(Paire1);
        GUI(argc, argv, Paire1);
    }
    return 0;
};