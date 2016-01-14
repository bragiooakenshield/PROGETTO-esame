#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mybooklib.h"


void comandi()
        {
         printf("		\n\n			--/BENVENUTO\\--\n\n"	
         		"		Programma a cura di Andrea Bragetta.\n\n"
         		"   		    SELEZIONA UNA VOCE PER CONTINUARE!!\n\n"
                "   1 	VERIFICA LA PRESENZA DEL LIBRO DAL SUO ID.\n"
                "   2 	CERCA UN LIBRO DAL SUO ID.\n"
                "   3	RIMUOVI UN LIBRO DAL SUO ID.\n"
                "   4 	VISUALIZZA L'INTERO ELENCO DEI LIBRI.\n"
                "   5 	INSERISCI UN LIBRO IN CIMA ALL'ELENCO.\n"
                "   6 	INSERISCI UN LIBRO IN FONDO ALL'ELENCO.\n"
                "   7 	RIMUOVI IL PRIMO LIBRO DALL'ELENCO.\n"
                "   8 	RIMUOVI L'ULTIMO LIBRO DALL'ELENCO.\n"
                "   9	PRELEVA UN LIBRO.\n"
                "  10	RESTITUISCI UN LIBRO.\n"
                "  11 			--/ESCI\\--\n");
        }       

StructCell *allocaLibro()
{
 StructCell *Puntatore = malloc(sizeof(StructCell));
 StructBook *Ptr = &Puntatore->book;
 if(Ptr==NULL)
 {
  printf("			--/ALLOCAZIONE MEMORIA FALLITA\\--\n");
 } 
 printf("\n			--INSERIRE I PARAMETRI RICHIESTI--\n\n");  
 printf("			TITOLO:\n");
 scanf(" %[^\n]", Ptr->title);
 printf("			SCRITTORE:\n");
 scanf(" %[^\n]", Ptr->writer);
 while(1)
 {
 printf(" 			GENERE:\n" 
 		"0-Azione-\t"
        "1-Avventura-\t" 
        "2-Romanzo-\n"
        "3-Fantasy-\t" 
        "4-Thriller-\t"
        "5-Horror-\n");

		printf("\n		--INSERIRE IL N° DEL GENERE--\n");
 		scanf("%u", &p->genre);
	  	if (Ptr->genre<6) 
		break;
		printf("			--/GENERE NON DISPONIBILE\\--\n"
				"		--PERFAVORE REINSERIRE IL N° DEL GENERE--\n\n");
		
	 	
}
 
while(1) 										
 {
  printf("		DATA DI PUBBLICAZIONE:\n");
  scanf("%hd%hd%hd", 
  &Ptr->published.day,
  &Ptr->published.month,
  &Ptr->published.year);

 if (Ptr->published.day<32) 
 	if (Ptr->published.month<13)
 		if (Ptr->published.year<2016)
	 break;				 							
 printf("		--/ATTENZIONE DATA NON VALIDA/--.\n\n"
 		"		PERFAVORE REINSERIRE LA DATA..\n");
 }

 printf("N°COPIE PRESENTI IN LIBRERIA :  ");
 scanf("%hd", &Ptr->inLibrary);
 printf("N°COPIE IN PRESTITO :  ");
 scanf("%hd", &Ptr->outLibrary);
 printf("ID:  ");
 scanf("%hd" , &Ptr->id);
 if (Puntatore!=NULL)
 {
 printf("\n--DATI SALVATI CORRETTAMENTE--\n\n");
 } 
 else printf("\n--/DATI NON SALVATI\\!!--\n");
 return Puntatore;
 }



void printElem(StructBook *book)
{
	printf("LIBRO TROVATO:\n\n");
	printf("TITOLO:%s\n",book->title);
 		printf("AUTORE: %s\n",book->writer);
 		
 		if(book->genre==0)
 		printf("GENERE:--Azione--\n");
 		else if(book->genre==1)
 		printf("GENERE:--Avventura--\n");
 		else if(book->genre==2)
 		printf("GENERE:--Romanzo--\n");
		else if(book->genre==3)
 		printf("GENERE:--Fantasy--\n");
 		else if(book->genre==4)
 	    printf("GENERE:--Thriller--\n");
	    else if(book->genre==5)
 		printf("GENERE:--Horror--\n");

	
  			printf("DATA DI PUBBLICAZIONE:%hd/%hd/%hd\n",book->published.day, book->published.month, book->published.year);
  		 		printf("N° COPIE PRESENTI IN ARCHIVIO: %hd\n", book->inLibrary);
  			 		printf("N° COPIE IN PRESTITO:%hd\n",book->outLibrary);
  						printf("ID: %hd\n", book->id);       
} 

StructCell* searchId(BookList* elenco)                    
{
 StructCell* P = elenco->pFirst;
 	short codice;
 		scanf("%hd", &codice);
 while(P)
   {
   	if(P->book.id == codice)
   		 break;
 	P = P->pNext;
	} 
	return P;
}

StructCell* rmvId(BookList* elenco)
{
	StructCell* rmv=elenco->pFirst;
	short codermv;
	while(rmv)
	{
		if(pNext->book.id==codermv)
		free(rmv);
		break;
		rmv=rmv->pNext;
	}
	return rmv;
}	



void insTail(BookList* elenco)
{  
 	StructCell *Ptr= allocaLibro();
 		if
 		(elenco->pLast==NULL)                          	
  			elenco->pLast=elenco->pFirst = Ptr;				
	 	else 
     		elenco->pLast->pNext = Ptr;
     		elenco->pLast = Ptr ;
}
 
void insHead(BookList* elenco)                  
	{  
 	StructCell *Puntatore = allocaLibro();                  
 		if
 		 (elenco->pFirst == NULL)
 			elenco->pFirst=elenco->pLast=Puntatore;
 			
 			else
 				elenco->pFirst->pNext=Puntatore;
 				elenco->pFirst=Puntatore;
 					  
	 }
void rmvTail(BookList* elenco) 
{
	StructCell* temp=elenco->pFirst;
	if(temp==elenco->pFirst) 
	{
		free(temp);
			elenco->pFirst=elenco->pLast=NULL;
	}
		else 
		{
			while(temp->pNext != elenco->pLast)
				temp=temp->pNext;
					temp->pNext=NULL;
						free(elenco->pLast);
							elenco->pLast=temp;
		}
}		

void rmvHead(BookList* elenco)                                                                   
{
	StructCell* temp= elenco->pFirst;                //NON VA BENE SCRITTO COSÌ, NON FUNZIONA:(              
	if(temp == elenco->pLast)
   {
    free(temp);
    	elenco->pFirst = elenco->pLast = NULL;
   } 
    else
     {
      while(temp->pNext != elenco->pFirst)       
      	temp= temp->pNext;
       		temp->pNext = NULL;
      			free (elenco->pFirst);
       				elenco->pFirst= temp;
     }
} 

void printList(BookList* elenco)
{
 StructCell* Ptr = elenco->pFirst;
 if (Ptr != NULL)
 {
   printf("\nELENCO COMPLETO DEI LIBRI:\n");
 	 printf("\n--|||--|||--|||--|||--|||--|||--\n\n");
  	 while(Ptr != NULL) 
	{
  	 printf("%s\n", Ptr->book.title);
  	 Ptr = Ptr->pNext;
   	 printf("\n");
   	}
  	
  	  printf("\n--|||--|||--|||--|||--|||--|||--\n");
 }
 else 
	{ 
 	printf("--/L'ELENCO È VUOTO\\--\n");
 	}   
}
