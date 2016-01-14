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

StructCell *allocBook()
{
 StructCell *Ptr = malloc(sizeof(StructCell));
 StructBook *p = &Ptr->book;
 if(p==NULL)
 {
  printf("			--/ALLOCAZIONE MEMORIA FALLITA\\--\n");
 } 
 printf("\n			--INSERIRE I PARAMETRI RICHIESTI--\n\n");  
 printf("			TITOLO:\n");
 scanf(" %[^\n]", p->title);
 printf("			SCRITTORE:\n");
 scanf(" %[^\n]", p->writer);
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
	  	if (p->genre<6) 
		break;
		printf("			--/GENERE NON DISPONIBILE\\--\n"
				"		--PERFAVORE REINSERIRE IL N° DEL GENERE--\n\n");
		
	 	
}
 
while(1) 										
 {
  printf("		DATA DI PUBBLICAZIONE:\n");
  scanf("%hd%hd%hd", 
  &p->published.day,
  &p->published.month,
  &p->published.year);

 if (p->published.day<32) 
 	if (p->published.month<13)
 		if (p->published.year<2016)
	 break;				 							
 printf("		--/ATTENZIONE DATA NON VALIDA/--.\n\n"
 		"		PERFAVORE REINSERIRE LA DATA..\n");
 }

 printf("N°COPIE PRESENTI IN LIBRERIA :  ");
 scanf("%hd", &p->inLibrary);
 printf("N°COPIE IN PRESTITO :  ");
 scanf("%hd", &p->outLibrary);
 printf("ID:  ");
 scanf("%hd" , &p->id);
 if (Ptr!=NULL)
 {
 printf("\n--DATI SALVATI CORRETTAMENTE--\n\n");
 } 
 else printf("\n--/DATI NON SALVATI\\!!--\n");
 return Ptr;
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
 StructCell* Temp = elenco->pFirst;
 	short codice;
 		scanf("%hd", &codice);
 while(Temp)
   {
   	if(Temp->book.id == codice)
   		 break;
 	Temp = Temp->pNext;
	} 
	return Temp;
}

StructCell* rmvId(BookList* elenco)
{
	StructCell* rmv=elenco->pFirst;
	short codermv;
	while(rmv)
	{
		if(rmv->book.id==codermv)
		free(rmv);
		break;
		rmv=rmv->pNext;
	}
	return rmv;
}	



void insTail(BookList* elenco)
{  
 	StructCell *Ptr= allocBook();
 		if
 		(elenco->pLast==NULL)                          	
  			elenco->pLast=elenco->pFirst = Ptr;				
	 	else 
     		elenco->pLast->pNext = Ptr;
     		elenco->pLast = Ptr ;
}
 
void insHead(BookList* elenco)                  
	{  
 	StructCell *Ptr = allocBook();                  
 		if
 		 (elenco->pFirst == NULL)
 			elenco->pFirst=elenco->pLast=Ptr;
 			
 			else
 				elenco->pFirst->pNext=Ptr;
 				elenco->pFirst=Ptr;
 					  
	 }
void rmvTail(BookList* elenco) 
{
	StructCell* tempPtr=elenco->pFirst;
	if(tempPtr==elenco->pFirst) 
	{
		free(tempPtr);
			elenco->pFirst=elenco->pLast=NULL;
	}
		else 
		{
			while(tempPtr->pNext != elenco->pLast)
				tempPtr=tempPtr->pNext;
					tempPtr->pNext=NULL;
						free(elenco->pLast);
							elenco->pLast=tempPtr;
		}
}		

void rmvHead(BookList* elenco)                                                                   
{
	StructCell* tempPtr= elenco->pFirst;                //NON VA BENE SCRITTO COSÌ, NON FUNZIONA:(              
	if(tempPtr == elenco->pLast)
   {
    free(tempPtr);
    	elenco->pFirst = elenco->pLast = NULL;
   } 
    else
     {
      while(tempPtr->pNext != elenco->pFirst)       
      	tempPtr= tempPtr->pNext;
       		tempPtr->pNext = NULL;
      			free (elenco->pFirst);
       				elenco->pFirst= tempPtr;
     }
} 

void printList(BookList* elenco)
{
 StructCell* Temp = elenco->pFirst;
 if (Temp != NULL)
 {
   printf("\nELENCO COMPLETO DEI LIBRI:\n");
 	 printf("\n--|||--|||--|||--|||--|||--|||--\n\n");
  	 while(Temp != NULL) 
	{
  	 printf("%s\n", Temp->book.title);
  	 Temp = Temp->pNext;
   	 printf("\n");
   	}
  	
  	  printf("\n--|||--|||--|||--|||--|||--|||--\n");
 }
 else 
	{ 
 	printf("--/L'ELENCO È VUOTO\\--\n");
 	}   
}
