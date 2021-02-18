# include "biblio.h"

void init (T_Bibliotheque *ptrB)
{

ptrB->nbLivres=0;
// ou (*ptrB).nbLivres=0;
}

int ajouterLivre(T_Bibliotheque  *ptrB)
{
if (ptrB->nbLivres<CAPACITE_BIBLIO)// reste t il de la place?
	{
	saisirLivre(&(ptrB->etagere[ptrB->nbLivres]));
	ptrB->nbLivres++;
	return 1;
	}
	
	
return 0;
	
}


int  afficherBibliotheque(const T_Bibliotheque  *ptrB)
{
int i;
if(ptrB->nbLivres==0)
	return 0;
	else
		{
		for(i=0;i<ptrB->nbLivres;i++)
			{
			afficherLivre( &(ptrB->etagere[i])  );
			
			}


		
		return 1;
		}
}

int rechercherLivre(T_Bibliotheque  *ptrB){
	int nb=0;
	char titre[MAX_TITRE];
	printf("Saisissez le titre du livre que vous recherchez : ");
	lireChaine("\nTITRE :", (titre), MAX_TITRE );
	for (int i = 0; i < ptrB->nbLivres; i++){
		if (strcmp(titre,ptrB->etagere[i].titre)==0){
			nb++;
		}
	}
	return nb;
}

int rechercherAfficherLivre(T_Bibliotheque  *ptrB){
	int nb=0;
	char auteur[MAX_TITRE];
	printf("Saisissez le nom de l'auteur dont vous cherchez le/les livre(s) : ");
	lireChaine("\nAUTEUR :", (auteur), MAX_TITRE );
	printf("\n");
	for (int i = 0; i < ptrB->nbLivres; i++)
	{
		if (strcmp(auteur,ptrB->etagere[i].auteur)==0)
		{
			afficherLivre( &(ptrB->etagere[i]));
			nb++;
		}
	}
	return nb;
}

int supprimerLivre(T_Bibliotheque  *ptrB){
	int nb=0;
	char titre[MAX_TITRE];
	char auteur[MAX_TITRE];
	printf("Saisissez le titre du/des livre(s) à supprimer : ");
	lireChaine("\nTITRE :", (titre), MAX_TITRE );
	printf("Saisissez le nom de l'auteur du/des livre(s) à supprimer : ");
	lireChaine("\nAUTEUR :", (auteur), MAX_TITRE );

	for (int i = 0; i < ptrB->nbLivres; ++i)
	{
		if (strcmp(titre,ptrB->etagere[i].titre)==0 && strcmp(auteur,ptrB->etagere[i].auteur)==0){
			nb++;
			for (int j = i; j < ptrB->nbLivres-1; j++)
			{
				//strcpy(ptrB->etagere[j],ptrB->etagere[j+1]);
				ptrB->etagere[j]=ptrB->etagere[j+1];
			}
			ptrB->nbLivres--;
			
		}
	}
	return nb;
}

void sauvegarde(T_Bibliotheque *ptrB)
{
FILE *fic=NULL; //le type FILE
int i;
fic=fopen("baseLivres","w"); // w = le mode = write avec ECRASEMENT
//fopen renvoie NULL si probleme (disque plein, disque non accessible ...
if (fic!=NULL)
	{
	for(i=0;i<ptrB->nbLivres;i++)
		{
//fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
    fwrite(  &(ptrB->etagere[i])        ,sizeof(T_livre),1,fic);

		}
	fclose(fic);
	puts("SAUVEGARDE REUSSIE ..............");



	}
	else puts("ECHEC DE SAUVEGARDE  !!!!!  ");




}



void chargement(T_Bibliotheque *ptrB)
{
FILE *fic=NULL; //le type FILE
int i=0;
fic=fopen("baseLivres","r"); // r = le mode read
//fopen renvoie NULL si probleme (disque plein, disque non accessible ...
if (fic!=NULL)
	{
	do
		{

		fread(  &(ptrB->etagere[i]) ,sizeof(T_livre),1,fic);
		i++;
		}
		while(!feof(fic));
	fclose(fic);
	ptrB->nbLivres=i-1;
	puts("CHARGEMENT  REUSSI ..............");
	}
	else puts("ECHEC DE CHARGEMENT  !!!!!  ");

}

int emprunterLivre(T_Bibliotheque *ptrB)
{


}


