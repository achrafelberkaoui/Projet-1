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
   float NewValleur;
   AfficherNotes();
   printf("veuillez choisier l'indice qui modifier (1 - %d) : ",Taille);
   scanf("%d",&indice);
   if (indice <= Taille && indice >= 0)
   {
       printf("veuillez entrer la nouvelle valaur : ");
       scanf("%f",&NewValleur);
   }else{
      printf("s'il vous plait ! veuillez choisier l'indice qui modifier (1 - %d) : ",Taille);
      scanf("%d",&indice);
       printf("veuillez entrer la nouvelle valaur : ");
       scanf("%f",&NewValleur);
   }
   
   notes[indice-1] = NewValleur;   

   printf("\nLes Notes Apres Modification sont : \n");

      for (int i = 0; i < Taille; i++)
            {
               printf("note %d : %.2f\n",i+1,notes[i]);
            }
}

int Statistique() {
   printf("~~~~~~Statistique~~~~~~\n");
   printf("1- Moyenne\n");
   printf("2- Min\n");
   printf("3- Max\n");
   printf("4- Admis / No Admis\n");
   printf("Quel est votre choix ? ");
   scanf("%d", &CH2);
   return CH2;
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

float Admis (float admis){
   float a;
admis = Moyenne(a);
   if(admis > 10){
      printf("felicitations, vous avez ete admis\n");  
   }else{
      printf("Desole, vous avez ete Non admis\n");
   }
   return admis;
}

void AjouteNote (float N, int pos)
{
   int i;
   printf("veuillez saiser la valeur a inserer :");
   scanf("%f",&N);
   printf("veuillez saiser sa pstion : ");
   scanf("%d",&pos);
      do{
         if(pos > Taille+1 || pos < 1){
      printf("veuillez saiser sa pstion entre 1 et %d: ",Taille+1);
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
      printf("veuillez saiser sa pstion entre 1 et %d: ",Taille);
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
   if(choix != 1){
      printf("1- retour Menu :");
      scanf("%d",&choix);
      MyMenu();
   }else
   MyMenu();

}

void BackStati(){
    printf("veuillez entrer 1 pour retour Menu statistique:\n");
    printf("veuillez entrer 2 pour retour Menu :");
    scanf("%d",&choix);
   if(choix == 1){
      StatiMenu();
   } else if(choix == 2){
   MyMenu();
   }
   else
   printf("veuillez sasier 1 pour Menu statistique , ou 2 Menu : " );
   scanf("%d",&choix);
}

int StatiMenu (){
    float a,b,c;
   switch (CH2)

   {
   case 1:
      Moyenne(a);
      BackStati();
      BackMenu();

      break;
   
   default:
      break;
   }
}

int Choisier (){
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
      ModifierNote();
      BackMenu();
      break;
   case 4:
      Statistique();

      BackMenu();
      break;
   
   default:
      break;
   }
   } while (choix != 0);
   printf("fin de programme ! Merci ~~~~~~");
   
}

int main(){
  int pos, pos2;
  float s, max, min,A,N;
   printf("\n",MyMenu(choix));
   printf("\n",Choisier(choix));
  /*SaiserNotes();
  AfficherNotes(SaiserNotes);
  ModifierNote();
   printf("%.2f\n",Moyenne(s));
   printf("%.2f\n",Max(max));
   printf("%.2f\n",Min(min));
   printf("\n",Admis(A));
  AjouteNote(N,pos);
  SuppNote(pos2);
*/

 return 0;
}