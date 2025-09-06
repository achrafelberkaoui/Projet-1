#include <stdio.h>
#include <stdbool.h>
int choix,CH2;
int  Taille;
float  notes [100];

int MyMenu (){

   printf("----------Menu----------\n");

   printf("1_  Saisir N notes\n");

   printf("2_  Afficher les notes\n");

   printf("3_  Statistiques (moyenne, max, min, admis/non admis)\n");

   printf("4_  Ajouter une note\n");

   printf("5_  Modifier une note (par index)\n");

   printf("6_  Supprimer une note (par index)\n");

   printf("0_  Quitter\n");

   printf("Quel est votre choix ? ");
   scanf("%d", &choix);
   return choix;

}

void SaiserNotes()
{
   printf("veuillez saiser la taille du tableau : ");
   scanf("%d",&Taille);

   printf("veuillez saiser les elements du tableau : \n");
      for(int i=0; i<Taille; i++)
      {
         printf("notes entre 0 et 20 [%d] = ",i+1);
         scanf("%f",&notes[i]);
      }
      
      
}

void AfficherNotes(){

if(Taille == 0){
printf("aucun notes\n");
}else{
printf("les notes deja entrer sont : \n");
for (int i = 0; i < Taille; i++)
      {
         printf("note %d : %.2f\n",i+1,notes[i]);
      }
}
}

void ModifierNote(){
   int indice;
   float NewValeur;
   AfficherNotes();
   printf("veuillez choisier l'indice qui modifier (1 - %d) : ",Taille);
   scanf("%d",&indice);
   if (indice <= Taille && indice >= 1)
   {
       printf("veuillez entrer la nouvelle valeur : ");
       scanf("%f",&NewValeur);
   }else{
      printf("s'il vous plait ! veuillez choisier l'indice qui modifier (1 - %d) : ",Taille);
      scanf("%d",&indice);
       printf("veuillez entrer la nouvelle valeur : ");
       scanf("%f",&NewValeur);
   }
   
   notes[indice-1] = NewValeur;   

   printf("\nLes Notes Apres Modification sont : \n");

      for (int i = 0; i < Taille; i++)
            {
               printf("note %d : %.2f\n",i+1,notes[i]);
            }
}

float Moyenne(float S){
   S = 0;
   for(int i=0; i<Taille; i++){
   S += notes[i];
   }
   return S/Taille;
   
}

float Max (float max){
   max = notes[0];
   for (int i = 0; i < Taille; i++)
   {
     if(max < notes[i]){
      max =notes[i];
     }
   }
   return max;
}

float Min (float min){
   min = notes[0];
   for (int i = 0; i < Taille; i++)
   {
     if(min > notes[i]){
      min =notes[i];
     }
   }
   return min;
}

void Admis (float admis){
   float a;
admis = Moyenne(a);
   if(admis >= 10){
      printf("felicitations, vous avez ete admis\n");  
   }else{
      printf("Desole, vous avez ete Non admis\n");
   }
   
}

void AjouteNote (float N, int pos)
{
   int i;
   printf("veuillez saiser la valeur a inserer :");
   scanf("%f",&N);
   printf("veuillez saiser sa position : ");
   scanf("%d",&pos);
      do{
         if(pos > Taille+1 || pos < 1){
      printf("veuillez saiser sa position entre 1 et %d: ",Taille+1);
      scanf("%d",&pos);
         }
      }
      while(pos > Taille+1 || pos < 1);

      for (i = Taille; i >= pos; i--)
         {
            notes[i] = notes[i-1];
         }
         notes[pos-1] = N;
         Taille++;
         printf("\nLes elements du tableau apres l'inserstion sont : \n");
         for(i=0; i < Taille; i++){
            printf(" note %d: %.2f\n",i+1, notes[i]);
         }
}

void SuppNote(int pos){
    int i;
   printf("veuillez saiser la position de l'element a supprimer : ");
   scanf("%d",&pos);
      do{
         if(pos > Taille || pos < 1){
      printf("veuillez saiser sa position entre 1 et %d: ",Taille);
      scanf("%d",&pos);
         }
      }
      while(pos > Taille || pos < 1);

      for (i = pos; i < Taille; i++)
         {
           notes[i-1] = notes[i] ;
         }

         Taille--;
         printf("\nLes elements du tableau apres la supprime sont : \n");
         for(i=0; i < Taille; i++){
            printf(" note %d: %.2f\n",i+1, notes[i]);
         }
}

void BackMenu(){
   printf("veuillez entrer 1 pour retour Menu :");
   scanf("%d",&choix);
   if(choix == 1){
      
      MyMenu();
   }else{

   printf("1- retour Menu :");
   scanf("%d",&choix);
   MyMenu();

   }
}

void Statistique() {
   float s, m, ma, a;
   printf("la Moyenne est : %.2f\n",Moyenne(s));
   printf("le minimum valeur est : %.2f\n",Min(m));
   printf("le Maximum valeur est : %.2f\n",Max(ma));
   Admis(a);

}

void Choisier (){
   int pos;
   float N;
   do
   {
       switch (choix)
   {

   case 1:
      SaiserNotes();
      BackMenu();
      
      break;
   case 2:
      AfficherNotes();
      BackMenu();
      break;

   case 3:
      Statistique();      
      BackMenu();
      
      break;
   case 4:
      AjouteNote(N,pos);
      BackMenu();
      break;
   case 5:
      ModifierNote();
      BackMenu();
   break;

   case 6:
      SuppNote(pos);
      BackMenu();
   break;
      
   default:
   printf("s'il vous plait ! veuillez choisier entrer 0 et 6 :");
   scanf("%d",&choix);
      break;
   }
   } while (choix != 0);
   printf("fin de programme ! Merci ~~~~~~");
}


int main(){

   choix = MyMenu();
   Choisier();

 return 0;
}