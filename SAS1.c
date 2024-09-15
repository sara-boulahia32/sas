// Projet Fin de Sas: Gestion des etudiants dans une universite
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ETUDIANTS 500
#define MAX_NOM 20
#define MAX_DEPARTEMENTS 3

enum Departement {
    maths,
    physique,
    svt
};
enum Mention{
    passable,  //0
    assezbien, //1
    bien,      //2
    tresbien,   //3
};
typedef struct {
    int j;
    int m;
    int a;
} Date;

typedef struct {
    int id;
    char nom[MAX_NOM];
    char prenom[MAX_NOM];
    Date dateNaissance;
    float noteGeneral;
    enum Departement section;
    char mention[MAX_NOM];
} Etudiant;

Etudiant info[MAX_ETUDIANTS];
int compteur = 0;
int i, j;

void Menu();
void sousMenuAjouterEtudiant();
void ajoutEtudiant(int n);
void exitProgram();
void sousMenuModifierOuSupprimerEtudiant();
void supprimerEtudiant();
void modifierInfoEtudiant();
void afficherTous();
void calculMoyenneGeneraleUniversitaire();
void calculMoyenneGeneraleDepartement();
void calculMoyenneGenerale();
void sousMenuRechercherEtudiant();
int rechercherParNom();
//int rechercheParNumero(char numeroTelephone[MAX_NOM]);
void sousMenuRechercherEtudiant();
void triAlpha(int n);
void sousMenuTriAlpha();
void sousMenuTriEtudiant();
void afficherEtudiantsParDepartement();
void sousMenuTriMoyenne();
void nombreEtudiantParDepartement();
void MoyenneSupSeuil();
void sousMenuStatistique();
void triMoyenne(int n);
void reussiParDepartement();
void top3();
void chargerListe();
const char* convertirDepartement(int n);
//char checkNumeroTelephone(int entree);
void afficherMention(char mention[], float note);
void afficherUnEtudiant(Etudiant info);
void triBullesNote();
void triDesReussi();


int main(){
    Menu();
    return 0;
}

void Menu(){
    int choix;
    do{
        printf("\t-------------------------------------------------------------------------------------\n");
        printf("\t----------------------- Gestion des etudiants d'universite --------------------------\n\n\n");
        printf("\t  1 - Ajouter un etudiant.                    2 - Modifier ou supprimer un etudiant.\n\n");
        printf("\t  3 - Afficher la liste des etudiants.        4 - Calculer la moyenne générale.\n\n");
        printf("\t  5 - Rechercher un etudiant.                 6 - Tri des etudiants .\n\n");
        printf("\t  7 - Statistiques                            8 - Quitter le programme.\n\n");
        printf("\t 9-charger\n");
        printf("\t------------------------------------------------------------------------------------\n");
        printf("\t------------------------------------------------------------------------------------\n\n");
        printf("\n\tChoix   :   ");
        scanf("%d", &choix);
        printf("\n\n");
        getchar();
        switch(choix)
        {
   case 1:
       sousMenuAjouterEtudiant();
        break;
        case 2:
            sousMenuModifierOuSupprimerEtudiant();
        break;
        case 3:
            afficherTous();
        break;
        case 4:
            calculMoyenneGenerale();
   break;
   case 5:
       sousMenuRechercherEtudiant();
        break;
        case 6:
            sousMenuTriEtudiant();
        break;
        case 7:
            sousMenuStatistique();
   break;
   case 8:
            exitProgram();
   break;
   case 9:
   chargerListe();
   break;
   default:
       printf("choix invalide \n");
            break;
            }
    }while(choix>0 && choix<=9);
}

void sousMenuAjouterEtudiant() {
    int choix, n;
    while (1) {
        printf("\t------------------------------- Sous-Menu Ajout -------------------------------------\n");
        printf("\t-------------------------------------------------------------------------------------\n");
        printf("\n\t  1 - Ajout simple.                  2 - Ajout multiple d'etudiants.\n\n");
        printf("\n\t  3 - Retour menu principal.         4 - Quitter le programme.\n\n");
        printf("\t------------------------------------------------------------------------------------\n");
        printf("\t------------------------------------------------------------------------------------\n\n");
        printf("\n\tChoix   :   ");
        scanf("%d", &choix);
        getchar();
        printf("\n\n");
        switch (choix) {
            case 1:
                ajoutEtudiant(1); //ajoute 1 etudiant
                break;
            case 2:
                ajoutEtudiant(0); //ajoute n etudiants
                break;
            case 3:
                return;
            case 4:
                exitProgram();
                break;
            default:
                printf("Choix invalide.\n");
                break;
        }
    }
}

void ajoutEtudiant(int n) {
    int departement;
    if (compteur + n > MAX_ETUDIANTS) {
            printf("\nLa liste est pleine.\n");
            return;}
    if (n == 0) {
        printf("\t------------------Ajouter plusieurs etudiants ---------------------\n\n");
        printf("\tEntrez le nombre d'etudiants que vous souhaitez entrer : ");
        scanf("%d", &n);
        getchar();
        printf("\n\n");
        }
    if (n == 1) {
        printf("\t----------------------- Ajouter un etudiant -----------------------\n\n");
    }
    for ( i = 0; i < n; i++) {
        printf("\n\t----------- Entrer les informations de l'etudiant %d -----------\n", compteur+1);
        info[i].id=compteur+1;
        printf("\tEntrez le nom de l'etudiant : ");
        scanf("%[^\n]s", info[compteur].nom);
        getchar();
        printf("\n\n");
        printf("\tEntrez le prenom de l'etudiant : ");
        scanf("%[^\n]s", info[compteur].prenom);
        getchar();  //NETTOYER LE BUFFER
        printf("\n\n");
        do {
            printf("\tEntrez la date de naissance de l'etudiant (format JJ/MM/AAAA) : ");
            scanf(" %d/%d/%d", &info[compteur].dateNaissance.j, &info[compteur].dateNaissance.m, &info[compteur].dateNaissance.a);
            getchar();
        } while (info[compteur].dateNaissance.j <= 0 || info[compteur].dateNaissance.j > 31 ||
                 info[compteur].dateNaissance.m <= 0 || info[compteur].dateNaissance.m > 12 || info[compteur].dateNaissance.a<=1970 || info[compteur].dateNaissance.a>2024 );
        do {
            printf("\n\tEntrez le departement de l'etudiant : ");
            printf("\n\t  1 - Maths              2 - Physique\n");
            printf("\n\t  3 - Svt\n\n");
            printf("\n\tChoix   :   ");
            scanf(" %d", &departement);
            getchar();
            printf("\n\n");
        } while (departement < 1 || departement > 3);
        info[compteur].section = (enum Departement)(departement - 1);
        printf("\tEntrez la note generale de l'etudiant : ");
        scanf(" %f", &info[compteur].noteGeneral);
        getchar();
        system("cls");
        printf("\n\tAjout affectue avec succes\n\n");
        compteur++;
    }
}
void exitProgram(){
    char choix[4];
    system("cls");
    printf("\n\tVous etes sure de vouloir quitter (oui/non)  :  ");
    scanf("%s", choix);
    getchar();
    printf("\n\n");
    if (strcmp(choix, "oui")==0){
        printf("\n\tVous etes deconnecte....");
        exit(0);
        return;
    }else if (strcmp(choix, "non")==0){
        return;
    }else{
        printf("\n\tChoix invalide\n");
    }
}
void sousMenuModifierOuSupprimerEtudiant(){
    int choix;
    char numeroTelephone[MAX_NOM];
    do{

        printf("\n\t--------------------------- Sous-Menu Manipulation ----------------------------------\n");
        printf("\t-------------------------------------------------------------------------------------\n");
        printf("\n\t 1 - Supprimer un etudiant.          2 - Modifier une information d etudiant.\n\n");
        printf("\n\t 3 - Retour menu principal.          4 - Quitter le programme.\n\n");
        printf("\t-------------------------------------------------------------------------------------\n");
        printf("\t-------------------------------------------------------------------------------------\n");
        printf("\n\tChoix   :   ");
        scanf("%d", &choix);
        getchar();
        printf("\n\n");
        switch (choix)
        {
            case 1:
            supprimerEtudiant();
            break;
            case 2:
            modifierInfoEtudiant();
            break;
            case 3:
            return;
            case 4:
            exitProgram();
            break;
            default:
            printf("\n\tChoix invalide. Veuillez reessayer\n");
            break;
        }
    }while(choix<=0&&choix>=3);
}

void supprimerEtudiant(){
    int chercheId;
    char choix[4];
    printf("\n\t----------------------- Supprimer un etudiant -----------------------  \n\n");
    printf("\n\tEntrez l identifiant de l etudiant  :  ");
    scanf("%d", &chercheId);
    getchar();
    printf("\n\n");
    for(i=0; i<compteur; i++){
        if(info[i].id== chercheId){
           printf("\nVoulez vous vraiment supprimer cet etudiant de la liste ? (oui/non)");
            scanf(" %s", choix);
            getchar();
            printf("\n\n");
            if (strcmp(choix, "oui")==0) {
                for (int j = i; j < compteur-1 ; j++) {
                    info[j] = info[j + 1];
                }
                    compteur--;
                    system("cls");
                    printf("\n\tÉtudiant supprimé avec succes.\n");
                    return;
            }else if (strcmp(choix, "non")==0) {
                system("cls");
                 printf("\n\tSuppression annulée.\n");
            }else{
                system("cls");
                printf("\n\tChoix invalide\n\n");
                Menu();
            }
        }
          
}
printf("\n\t identifiant introuvable\n");
}


void modifierInfoEtudiant(){
    int choix;
    int chercheId;
    puts("\n\t ----------------------- Modifier un etudiant ------------------------  \n\n");
    int nvDepartement;
    Date nvDate;
    char nvPrenom[MAX_NOM], nvNom[MAX_NOM], nvTel[MAX_NOM];
    float nvNote;
    printf("\n\tEntrez l identifiant de l etudiant  :  ");
    scanf("%d", &chercheId);
    getchar();
    printf("\n\n");
    for(i=0; i<compteur; i++){
        if(info[i].id == chercheId){
            printf("\nQue voulez vous modifier?\n");
                printf("\t-------------------------------------------------------------------------------------\n\n\n");
printf("\t 1 - Nom                               2 - Prenom.\n\n");
printf("\t 3 - Departement                       4 - la moyenne generale.\n\n");
printf("\t 5 - Date de naissance                   \n\n");
printf("\t------------------------------------------------------------------------------------\n");
printf("\t------------------------------------------------------------------------------------\n\n");
printf("\n\t      Choix   :   ");
scanf("%d", &choix);
getchar();
printf("\n\n");
switch (choix)
{
   case 1:
   printf("\n\tEntrez le nouveau nom de l'etudiant  :  ");
        scanf(" %[^\n]s", nvNom);
        getchar();
        printf("\n\n");
        strcpy(info[i].nom, nvNom);
        system("cls");
        printf("\n\tNom modifie avec succee.\n");
   break;
   case 2:
   printf("\n\tEntrez le nouveau prenom de l'etudiant  :  ");
        scanf(" %[^\n]s", nvPrenom);
        getchar();
        strcpy(info[i].prenom, nvPrenom);
        system("cls");
        printf("\n\tPrenom modifiee avec succee.\n");
   break;
   case 3:
   printf("\n\tEntrez le departement de l'etudiant  :  ");
        do{
            printf("\n\t1 - maths          2 -  physique");
            printf("\n\t3 - svt               ");
            printf("\n\tChoix   :   ");
   scanf("%d", &nvDepartement);
   getchar();
}while(nvDepartement<1 || nvDepartement>4);
info[i].section=(enum Departement)(nvDepartement - 1);
system("cls");
        printf("\n\tDepartement modifie avec succes.\n");
   break;
   case 4:
   printf("\n\tEntrez la note general de l'etudiant  :  ");
        scanf(" %f", &nvNote);
        getchar();
   info[i].noteGeneral=nvNote;
   system("cls");
   printf("\n\tNote generale modifiee avec succee.\n");
   break;
   case 5:
   printf("\n\tEntrez la date de naissance de l'etudiant  (format JJ/MM/AAAA)  :  ");
        scanf("%d/%d/%d", &nvDate.j, &nvDate.m, &nvDate.a);
        info[i].dateNaissance=nvDate;
        system("cls");
        printf("\n\tDate modifiee avec succee.\n");
   break;
   default:
   printf("\n\tChoix impossible\n");
   break;
}
}return;
}
}

void afficherTous(){
    printf("\n\t----------------------- La liste des etudiants -----------------------\n\n");
    printf("\t+----------------------+----------------------+----------------------+----------------+----------------------+--------------+----------+\n");
    printf("\t| %-20s | %-20s | %-20s | %-10s | %-20s | %-10s |\n", "IDENTIFIANT", "Nom", "Prenom", "Date Naissance", " Departement", "Note generale");
    printf("\t+----------------------+----------------------+----------------------+----------------+----------------------+---------------+\n");
    for(i=0; i<compteur; i++){
    char mention[30];
    afficherMention(mention, info[i].noteGeneral);
    printf("\t| %-20d | %-20s | %-20s |   %-2d/%-2d/%-4d   | %-20s | %-10.2f |\n",  i+1, info[i].nom, info[i].prenom, info[i].dateNaissance.j, info[i].dateNaissance.m, info[i].dateNaissance.a, convertirDepartement(info[i].section), info[i].noteGeneral);
    printf("\t+----------------------+----------------------+----------------------+----------------+----------------------+---------------+\n");
        
    }
}
void calculMoyenneGenerale(){
    calculMoyenneGeneraleDepartement();
    calculMoyenneGeneraleUniversitaire();
}
void calculMoyenneGeneraleDepartement(){
    float total[3] = {0};
    int compte[3] = {0};
    for (int i = 0; i < compteur; i++) {
        int departement = info[i].section;
        total[departement] += info[i].noteGeneral;
        compte[departement]++;
    }
    printf("\n\t------ Moyenne generale par departement------- :\n");
    printf("\t+-----------------------------+-------------+\n");
    printf("\t| %-20s | %-20s |\n", " Departement", "Moyenne");
    printf("\t+-----------------------------+-------------+\n");
    for (int i = 0; i < 3; i++) {
        if (compte[i] > 0) {
            float moyenne = total[i] / compte[i];
            printf("\t| %-20s | %-20.02f| \n",  convertirDepartement(info[i].section), moyenne);
            printf("\t+-----------------------------+-------------+\n");

        } else {
            printf("\t|%-20d | Aucun etudiant       |\n",  i+1);
            printf("\t+-----------------------------+-------------+\n");
        }
    }
}
void calculMoyenneGeneraleUniversitaire(){
    float total=0;
    int compte=0;
    for (int i = 0; i < compteur; i++) {
        total += info[i].noteGeneral;
        compte++;
    }
    if (compte > 0) {
        double moyenneUniversite = total / compte;
        printf("\n\t------ Moyenne generale par universite------- \n");
        printf("\t|%-30s| %-20.2f |\n",  "Moyenne general universitaire", moyenneUniversite);
        printf("\t+-----------------------------+--------------+\n\n\n");
    } else {
        printf("\t| Aucun etudiant                      |\n");
        printf("\t+-------------------------------------+\n\n\n");
    }
}
void sousMenuRechercherEtudiant(){
    int choix;
    while (1) {
        printf("\n\t------------- Rechercher ------------------ :\n");
        printf("\t---------------------------------------------");
        printf("\n\t 1 - Rechercher un etudiant avec nom\n\n");
        printf("\n\t 2 - Afficher la liste des etudiants inscrits dans un departement specifique\n\n");
        printf("\n\t 3 - Retour au menu principal\n\n");
        printf("\n\tEntrer votre choix: ");
        scanf("%d", &choix);
        getchar();
        printf("\n\n");
        switch (choix) {
            case 1:
                rechercherParNom();
                break;
            case 2:
                afficherEtudiantsParDepartement();
                break;
            case 3:
                return;
            default:
                printf("\n\tChoix invalid.");
                break;
        }
    }
}
int rechercherParNom(){
    char chercheNom[MAX_NOM];
    int trouve=0;
    printf("\n\tEntrez nom a chercher   :  ");
    scanf("%[^\n]s", chercheNom);
    getchar();
    for(i=0; i<compteur; i++){
        for(j=i; j<compteur; j++){
        if(strcmp(info[j].nom, chercheNom)==0){
            afficherUnEtudiant(info[j]);
            trouve = 1;
        }
    }
    }
    if(!trouve){
        puts("\n\tNom introuvable\n");
    }
}


void afficherEtudiantsParDepartement(){
    int departement;
    printf("\n\tEntrez le numero du departement : ");
    scanf("%d", &departement);
    getchar();
    printf("\n\n");
    if (departement < 1 || departement > 4) {
        printf("\n\tDepartement invalide.");
        return;
    }
    printf("\n\tEtudiants du departement %d :\n", departement);
    for (int i = 0; i < compteur; i++) {
        if (info[i].section == departement - 1) {
            afficherUnEtudiant(info[i]);
        }
    }
}
void sousMenuTriEtudiant(){
    int choix;
    while(1){
        printf("\t-------------------------Tri-Etudiant---------------------------\n\n");
        printf("\t----------------------------------------------------------------\n\n");
        printf("\n\t  1 - Tri alphabetique des etudiants par nom (de A -> Z ou de Z -> A)\n");
        printf("\n\t    2 - Tri des etudiants par moyenne generale\n");
        printf("\n\t    3 - Tri des etudiants selon leur statut de reussite(moyenne superieure ou egale a 10/20)\n");
        printf("\n\t    4 - Retour au menu principal.\n");
        printf("\n\t----------------------------------------------------------------\n\n");
        printf("\nEntrer votre choix: ");
        scanf("%d", &choix);
        getchar();
        printf("\n\n");
        switch (choix) {
            case 1:
                sousMenuTriAlpha();
                break;
            case 2:
                sousMenuTriMoyenne();
                break;
            case 3:
                triDesReussi();
                break;
            case 4:
                return;
            default:
                printf("\n\tChoix invalide.\n");
                break;
        }
    }
}
void sousMenuTriAlpha(){
    int choix;
    printf("\t----------------------------------------------------------------\n\n");
    printf("\n\t1 - Tri croissant ( A -> Z)    2 - Tri decroissant (A -> Z)\n");
    printf("\t----------------------------------------------------------------\n\n");
    printf("\nEntrez votre choix: ");
    scanf("%d", &choix);
    getchar();
    printf("\n\n");
    switch (choix)
    {
        case 1:
        triAlpha(1); //croissant
        break;
        case 2:
        triAlpha(0);
        break;
        default:
        return;
    }
}
void triAlpha(int n){
    if(n==1){
        for(i=0; i<compteur; i++){
            for(j=0; j<compteur-i-1; j++){
       if(strcmp(info[j].nom, info[j+1].nom)>0){
           Etudiant temp=info[j];
           info[j]=info[j+1];
           info[j+1]=temp;
       }
            }
        }
    }
    if(n==0){
        for(i=0; i<compteur; i++){
            for(j=0; j<compteur-i-1; j++){
       if(strcmp(info[j].nom, info[j+1].nom)<0){
           Etudiant temp=info[j];
           info[j]=info[j+1];
           info[j+1]=temp;
       }
            }
        }
    }
    afficherTous();
}
void sousMenuTriMoyenne(){
    int choix;
    printf("\t-------------Classement gloabal des etudiants------------------\n\n");
    printf("\n\t1 - Decroissant                        2 - Croissant \n");
    printf("\t----------------------------------------------------------------\n\n");
    printf("\nEntrez votre choix: ");
    scanf("%d", &choix);
    getchar();
    switch (choix)
    {
        case 1:
        triMoyenne(1);//decroissant

        break;
        case 2:
        triMoyenne(0);
        break;
        default:
        return;
    }
}
void triMoyenne(int n){
    if(n==1){
        triBullesNote();
        afficherTous();
    }else if(n==0){
        for(i=0; i<compteur-1; i++){
            for(j=0; j<compteur-i-1; j++){
		    if(info[j].noteGeneral> info[j+1].noteGeneral){
		        Etudiant temp=info[j];
		        info[j]=info[j+1];
		        info[j+1]=temp;
		        }
            }
        }
            afficherTous();
        }
}


void sousMenuStatistique(){
    int choix;
    printf("\t----------------------------------------------------------------\n\n");
    printf("\n\t1 - Total d'etudiants inscrits.                    2 - Nombre d'etudiants dans chaque departement. \n\n");
    printf("\n\t3 - Etudiants depassant un certain seuil           4 - Afficher les 3 etudiants ayant les 3 meilleures notes. \n\n");
    printf("\n\t5 - Nombre d'etudiants ayant reussi dans chaque departement(note superieure ou egale a 10/20).\n\n");
    printf("\t----------------------------------------------------------------\n\n");
    printf("\n\tEntrez votre choix: ");
    scanf("%d", &choix);
    getchar();
    printf("\n\n");
    switch (choix)
    {
        case 1:
        printf("\n\tLe total d'etudiants inscrits dans l'universite est : %d etudiants\n", compteur);
        break;
        case 2:
        nombreEtudiantParDepartement();
        break;
        case 3:
        MoyenneSupSeuil();
        break;
        case 4:
        top3();
        break;
        case 5:
        reussiParDepartement();
        break;
        default:
        printf("Choix invalide\n");
        break;
    }
}
void nombreEtudiantParDepartement() {
    int totalMaths = 0, totalPhysique = 0, totalSVT = 0;
    printf("\n\t----------------------- Total des étudiants par département -----------------------  \n\n");
    for (int i = 0; i < compteur; i++) {
        if (info[i].section == 0) {
            totalMaths++;
        } else if (info[i].section == 1) {
            totalPhysique++;
        } else if (info[i].section == 2) {
            totalSVT++;
        }
    }
    printf("\n\tTotal des étudiants en Maths : %d\n", totalMaths);
    printf("\n\tTotal des étudiants en Physique : %d\n", totalPhysique);
    printf("\n\tTotal des étudiants en SVT : %d\n", totalSVT);
}
void MoyenneSupSeuil(){
    float seuil;
    printf("\n\tEntrez le seuil :  ");
    scanf("%f", &seuil);
    for(i=0; i<compteur; i++){
        if(info[i].noteGeneral>=seuil){
            afficherUnEtudiant(info[i]);
        }
    }
}
void top3(){
    triBullesNote(); // decroissant
    printf("Les 3 meilleurs etudiants sont :\n");
    for (i = 0; i < 3 && i < compteur; i++) {
        afficherUnEtudiant(info[i]);
    }
}
void reussiParDepartement() {
    int totalMaths = 0, totalPhysique = 0, totalSVT = 0;
    printf("\n\t----------------------- Total des étudiants réussis par département -----------------------  \n\n");
    for(int i = 0; i < compteur; i++) {
        if (info[i].noteGeneral >= 10) {
            if (info[i].section == 0) {
                totalMaths++;
            } else if (info[i].section == 1) {
                totalPhysique++;
            } else if (info[i].section == 2) {
                totalSVT++;
            }
        }
    }
    printf("\n\tTotal des étudiants réussis en Maths : %d\n", totalMaths);
    printf("\n\tTotal des étudiants réussis en Physique : %d\n", totalPhysique);
    printf("\n\tTotal des étudiants réussis en SVT : %d\n", totalSVT);
}
void afficherMention(char mention[], float note){
    if (note < 10)
    {
        strcpy(mention, "Insuffisant");
    }
    else if (note < 14)
    {
        strcpy(mention, "Passable");
    }
    else if (note < 17)
    {
        strcpy(mention, "Bien");
    }
    else
    {
        strcpy(mention, "Tres Bien");
    }
}
void afficherUnEtudiant(Etudiant info){
    char mention[10];
    afficherMention(mention, info.noteGeneral);
    printf("\n\t+---------------------------+-------------------------+\n");
    printf("\t | Le Nom                     : %s\n", info.nom);
    printf("\t | Le Prenom                  : %s\n", info.prenom);
    printf("\t | La Note Generale           : %.2f\n", info.noteGeneral);
    printf("\t | La Mention                 : %s\n", mention);
    printf("\t | Le Departement             : %s \n",convertirDepartement(info.section));
    printf("\t |La Date de naissance        : %02d/%02d/%4d\n", info.dateNaissance.j, info.dateNaissance.m, info.dateNaissance.a);
    printf("\n\t+---------------------------+-------------------------+\n");
}

const char* convertirDepartement(int n){
    switch (n)
    {
    case 0: return "Maths";
    case 1: return "Physique";
    case 2: return "Svt";
    default: return "Indefini";
    }
}

void triBullesNote(){
    for(i=0; i<compteur-1; i++){
        for(j=0; j<compteur-i-1; j++){
        if(info[j].noteGeneral< info[j+1].noteGeneral){
            Etudiant temp=info[j];
            info[j]=info[j+1];
            info[j+1]=temp;
        }
    }
}
}
void triDesReussi(){
    printf("\n\tTri des elements reussi\n");
    triBullesNote();
    for(j=0; j<compteur; j++){
        if(info[j].noteGeneral>=10){
            afficherUnEtudiant(info[j]);
        }
    }
}
void chargerListe(){
    info[0].noteGeneral=13;
    info[1].noteGeneral=1;
    info[2].noteGeneral=19;
    info[3].noteGeneral=10;
    info[4].noteGeneral=17;
    info[5].noteGeneral=15;
    info[6].noteGeneral=12;
    strcpy(info[0].nom, "test1");
    strcpy(info[1].nom,"test2");
    strcpy(info[2].nom, "test3");
    strcpy(info[3].nom, "test2");
    strcpy(info[4].nom, "test2");
    strcpy(info[5].nom, "test6");
    strcpy(info[6].nom,"test7");
    strcpy(info[0].prenom, "yasser");
    strcpy(info[1].prenom,"ali");
    strcpy(info[2].prenom,"wiam");
    strcpy(info[3].prenom,"jalal");
    strcpy(info[4].prenom,"qk");
    strcpy(info[5].prenom,"jnd");
    strcpy(info[6].prenom,"hbde");
    info[0].section=1;
    info[1].section=1;
    info[2].section=3;
    info[3].section=3;
    info[4].section=2;
    info[5].section=1;
    info[6].section=2;
    compteur=7;
    
}
