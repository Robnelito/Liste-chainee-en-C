#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//////////Declaration de struct en variable global
struct cellule
	{
		int info;
		struct cellule*suivant;
	};
	typedef struct cellule* pointeur , *pointe;
	
//////////Fonction de lecture de la liste en mode recurssive
void affichelisterecurssif(pointeur l){
	if(l != NULL){
		printf("[%d]", l->info);
		affichelisterecurssif(l->suivant);
	}
}
//////////Fonction de lecture de la liste en mode iterative

void affichelisteiterative(pointeur l){
	while(l!= NULL){
		printf("[%d]", l->info);
		l = l->suivant;
	}
}
//////////Fonction de creation de la liste a l'envers

pointe creerlistalenvers(int nliste){
	pointeur l;
	pointeur p;
	int val;
	int i;
	l = NULL;
	p = (pointeur)malloc(sizeof(struct cellule));
	printf("inserer le premier element de la liste a l'envers:");
	scanf("%d", &val);
	p->info = val;
	p->suivant = l;
	l=p;
	for (i = 1; i < nliste; ++i)
	{
		p = (pointeur)malloc(sizeof(struct cellule));
		printf("insere %d element:", i+1);
		scanf("%d", &val);
		p->info = val;
		p->suivant = l;
		l=p;
	}
return l;
}

//////////Fonction de creation de la liste a l'endroit

pointe creelistealendroit(int nliste){
	pointeur p;
	pointeur l;
	pointeur der = NULL;
	int i, val;

	l=(pointeur)malloc(sizeof(struct cellule));
	printf("Inserer le premiere element de la liste a l'endroit:");
	scanf("%d", &val);
	l->info = val;
	der=l;

	for (int i = 1; i < nliste; ++i)
	{
		p=(pointeur)malloc(sizeof(struct cellule));
		printf("insere %d element:", i+1);
		scanf("%d", &val);
		p->info = val;
		der->suivant=p;
		der=p;
	}
	der->suivant = NULL;

	return l;

}
//////////Fonction principal

int main()
{
	int nliste;
	printf("veuiller entrer le nombre d'element a lister:\n");
	scanf("%d", &nliste);
	pointeur v = creerlistalenvers(nliste);
	pointeur c = creelistealendroit(nliste);
	
	printf("\nliste iterative a l'envers\n");
	affichelisteiterative(v);
	printf("\nliste recurssive a l'envers\n");
	affichelisterecurssif(v);

	printf("\nliste iterative a l'endroit\n");
	affichelisteiterative(c);
	printf("\nliste recurssive a l'endroit\n");
	affichelisterecurssif(c);
}
