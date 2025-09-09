#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int choix;
int N;
float note;
struct AjouEtu{
    char CNE [15];
    char Nom[10];
    char Prenom[10];
};

struct AjouEtu Etudient[100];

int MainMenu(){
printf("======Menu Principale=====\n\n");
printf("1) Ajouter un etudiant\n");
printf("2) Saisir les notes d'un etudiant\n");
printf("3) Afficher tous les etudiants\n");
printf("4) Afficher bulletin d'un etudiant\n");
printf("5) Calculer la moyenne generale\n");
printf("0) Quitter");
printf("Quel est votre choix ? ");
   scanf("%d", &choix);
   return choix;
}

void AjoutEtud(){
    int i;
printf("veuillez saisir le Nombre d'etudiant : ");
scanf("%d",&N);
printf("veuillez saisir les elements suivant : \n");
for(i = 0; i< N; i++){
    printf("veuillez entrer le CNE :");
    scanf("%s",&Etudient[i].CNE);
    printf("veuillez entrer le Nom :");
    scanf("%s",&Etudient[i].Nom);
    printf("veuillez entrer le Prenom :");
    scanf("%s",&Etudient[i].Prenom);
}
}

void SaisirNotes (){
    float S;
    int i;
    char reponse;
    do{
    printf("veuillez choisier Indice d'etudiant pour ajoute les notes 1-%d :",N);
    scanf("%d",&i);
    i=i-1;
    printf("L'etudiant %s %s saisir les notes : \n",Etudient[i].Nom, Etudient[i].Prenom);
    for(i=0; i<4; i++){
    printf("saisir les notes %d : ",i+1);
    scanf("%f",&note);
    S+= note;

            if (note < 0 || note > 20)
            {
               printf("desole ! note entre 0 et 20 ");
               scanf("%f",&note);
            }else{
         
    
    printf("Voulez-vous saisir un autre étudiant ?");
    scanf("%c",&reponse);
}while (reponse != 'O');

}

float moyenne (float S) {
    int i;
    for(i=0; i<4; i++)

    S+= note;
    
    return S/4;
}

void AfficherEtudients(){
    float S;
    int i;
    for(i=0; i<N; i++)
    printf("Etudiant %d :\n%s %s %s \nLa Moyenne : %.2f\n",i+1, Etudient[i].CNE, Etudient[i].Prenom, Etudient[i].Nom, moyenne(S));

}

float MoyenneGEn(float M){
    float s;
    moyenne(s) / N;

    return moyenne(s) / N;
}

void AffichBull(){
 int i;
 float s,m;
    printf("veuillez choisier Indice d'etudiant qui affiche le bulletin 1-%d :",N);
    scanf("%d",&i);
    do
    {
        printf("%s %s\n",Etudient[i].Nom,Etudient[i].Prenom);
        printf("%s\n",Etudient[i].CNE);
        for(i = 0; i<4; i++)
        printf("La note %d : %.2f ",i+1,note);
        printf("La Moyenne : %.2f\n",moyenne(s));
        printf("La Moyenne Generale : %.2f\n",MoyenneGEn(m));
        
    
    } while (N < 0 || N > 20);
    if ((N < 0 || N > 20))
    {
        printf("veuillez entre indice entre 1-%d :",N);
    }
    
    
    
}


int main (){
 float m,s;
    AjoutEtud();
    SaisirNotes();
    AfficherEtudients();
    MoyenneGEn(m);
    AffichBull();
    return 0;
}