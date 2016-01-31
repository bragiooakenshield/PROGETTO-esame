#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mybooklib.h"


void comandi()
        {
         printf("\n\t\tSELEZIONA UNA VOCE PER CONTINUARE!!\n\n"
                "1\tVERIFICA LA PRESENZA DEL LIBRO DAL SUO ID.\n"
                "2\tCERCA UN LIBRO DAL SUO ID.\n"
                "3\tRIMUOVI UN LIBRO DAL SUO ID.\n"
                "4\tVISUALIZZA L'INTERO ELENCO DEI LIBRI.\n"
                "5\tINSERISCI UN LIBRO IN CIMA ALL'ELENCO.\n"
                "6\tINSERISCI UN LIBRO IN FONDO ALL'ELENCO.\n"
                "7\tRIMUOVI IL PRIMO LIBRO DALL'ELENCO.\n"
                "8\tRIMUOVI L'ULTIMO LIBRO DALL'ELENCO.\n"
                "9\tPRELEVA UN LIBRO.\n"
                "10\tRESTITUISCI UN LIBRO.\n"
                "11\t\t\t--/ESCI\\--\n");
        }       

StructCell *allocaLibro()
{
	StructCell *Puntatore = malloc(sizeof(StructCell));
	StructBook *Ptr = &Puntatore->book;
		if(Ptr==NULL)
			{
			printf("\t\t\t--/ALLOCAZIONE MEMORIA FALLITA\\--\n");
			}	 
				printf("\n\t\t--INSERIRE I PARAMETRI RICHIESTI--\n\n");  
				printf("\t\t\tTITOLO:\n");
				scanf(" %[^\n]", Ptr->title);
				printf("\t\t\tSCRITTORE:\n");
				scanf(" %[^\n]", Ptr->writer);
while(1)
	{
		printf("\t\t\tGENERE:\n" 
				"0-Azione-\t"
				"1-Avventura-\t" 
				"2-Romanzo-\n"
				"3-Fantasy-\t" 
				"4-Thriller-\t"
				"5-Horror-\n");
		printf("\n\t\t--INSERIRE IL N° DEL GENERE--\n");
		scanf("%u", &Ptr->genre);
			if (Ptr->genre<6) 
			break;
		printf("\t\t\t\a--/GENERE NON DISPONIBILE\\--\n"
				"\t\t--PERFAVORE REINSERIRE IL N° DEL GENERE--\n\n");	 	
	}

while(1) 										
{
	printf("\t\tDATA DI PUBBLICAZIONE:\n");
	scanf("%hd%hd%hd",&Ptr->published.day, &Ptr->published.month, &Ptr->published.year);
	if (Ptr->published.day<32) 
		if (Ptr->published.month<13)
			if (Ptr->published.year<2016)
	break;				 							
	printf("\t\t\a--/ATTENZIONE DATA NON VALIDA/--.\n\n"
			"\t\tPERFAVORE REINSERIRE LA DATA..\n");
}

 printf("N°COPIE PRESENTI IN LIBRERIA : ");
 scanf("%hd", &Ptr->inLibrary);
 printf("N°COPIE IN PRESTITO : ");
 scanf("%hd", &Ptr->outLibrary);
 printf("ID: ");
 scanf("%hd" , &Ptr->id);
 if (Puntatore!=NULL)
 {
 printf("\n\a--DATI SALVATI CORRETTAMENTE--\n\n");
 } 
 else printf("\n\a--/DATI NON SALVATI\\!!--\n");
 return Puntatore;
 }



void printElem(StructBook *book)
{
	printf("RICERCA COMPLETATA:\n\n");
	printf("TITOLO:%s\n",book->title);
 		printf("AUTORE: %s\n",book->writer);
 		
 		if(book->genre==0)
 		printf("GENERE:--/Azione\\--\n");
 		else if(book->genre==1)
 		printf("GENERE:--/Avventura\\--\n");
 		else if(book->genre==2)
 		printf("GENERE:--/Romanzo\\--\n");
		else if(book->genre==3)
 		printf("GENERE:--/Fantasy\\--\n");
 		else if(book->genre==4)
 	    printf("GENERE:--/Thriller\\--\n");
	    else if(book->genre==5)
 		printf("GENERE:--/Horror\\--\n");

	
		printf("DATA DI PUBBLICAZIONE:%hd/%hd/%hd\n",book->published.day, book->published.month, book->published.year);
		printf("N° COPIE PRESENTI IN ARCHIVIO: %hd\n", book->inLibrary);
 		printf("N° COPIE IN PRESTITO:%hd\n",book->outLibrary);
		printf("ID: %hd\n", book->id);       
} 


StructCell* searchId(BookList* elenco)                    
{
 StructCell* search = elenco->pFirst;
 short codice;
 scanf("%hd", &codice);
  while(search)
   {
   	if(search->book.id == codice)
   		 break;
 	search= search->pNext;
	} 
	return search;
}


void rmvId(BookList* elenco)
{
	{
	StructCell* id=searchId(elenco);
	StructCell* rmv=elenco->pFirst;
	StructCell* ID;
	if (id !=NULL)
	{
		while(rmv)
		{
			if(rmv->pNext==id)
			break;
		}
			ID=id->pNext;
			free(id);
			rmv->pNext=ID;
	
	}
	else printf("\a--/NESSUN LIBRO TROVATO\\--\n");		
	
} 
return comandi();
}	


void insTail(BookList* elenco)
{
	{  
	 	StructCell *Ptr= allocaLibro();
	 		if (elenco->pLast==NULL)                          	
	  			elenco->pLast=elenco->pFirst = Ptr;				
		 	else 
		 		elenco->pLast->pNext = Ptr;
		 		elenco->pLast = Ptr ;
	}
	return comandi();
}
 
void insHead(BookList* elenco)                  
{
	{  
 	StructCell *Punt = allocaLibro();  
 	StructCell *ok;                
 		if (elenco->pLast == NULL)
 			elenco->pFirst=elenco->pLast=Punt;
 		else
 			ok=elenco->pFirst;
 			elenco->pFirst=Punt;
 			elenco->pFirst->pNext=ok;
 	}
 	return comandi();
 }	
 	
void rmvTail(BookList* elenco) 
{
	StructCell* temp=elenco->pFirst;
	{
		if(temp==elenco->pLast) 
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
	return comandi();
}


void rmvHead(BookList* elenco)                                                                   
{
	StructCell* temp= elenco->pFirst;                            
	if(temp == elenco->pLast)
	{
    	free(temp);
		elenco->pFirst = elenco->pLast = NULL;
	} 
    else
	{
      	temp= elenco->pFirst->pNext;
      	free (elenco->pFirst);
       	elenco->pFirst= temp;
	}
	return comandi();
} 


void printList(BookList* elenco)
{
	{
		StructCell* print = elenco->pFirst;
		if (print==NULL)
		{
			printf("--ELENCO VUOTO--\n\a");
		}
		else 
		printf("\nELENCO COMPLETO DEI LIBRI:\n");
		printf("\n--|||--|||--|||--|||--|||--|||--\n");
		while(print != NULL)
		{
			printf("\n");
			printf("TITOLO:%s\n", print->book.title);
			printf("SCRITTORE:%s\n", print->book.writer);
			printf("COPIE PRESENTI:%d\n",print->book.inLibrary);
			printf("COPIE IN PRESTITO:%d\n",print->book.outLibrary);
			printf("ID:%d\n",print->book.id);
			print = print->pNext;
	  		}
	  		printf("\n--|||--|||--|||--|||--|||--|||--\n\a");	
	}	
	return comandi();
}
