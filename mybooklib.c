#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mybooklib.h"


void comandi()
        {
         printf("		\n\n		--BENVENUTO--\n\n"	
         		"Per continuare selezionare una voce!!\n\n"
                "1 Per vedere se un libro è presente nella lista attraverso il suo id.\n"
                "2 Per vedere un libro dal suo id.\n"
                //"3 Per vedere l'intero elenco dei libri.\n"
                "4 Per inserire un elemento in cima alla lista.\n"
                "5 Per inserire un elemento in fondo alla lista.\n"
                "6 Per rimuovere il primo libro dell'elenco.\n"
                "7 Per rimuovere l'ultimo libro dell'elenco.\n"
                "8 Per Uscire...\n");
        }        

Cell_t *allocBook()
{
 Cell_t *Ptr = malloc(sizeof(Cell_t));
 Book_t *p = &Ptr->book;
 if(p==NULL)
 {
  printf("Allocazione memoria fallita\n");
 } 
  
 printf("		TITOLO:\n");
 scanf("%s", p->title);
 printf("		SCRITTORE:\n");
 scanf("%s", p->writer);
 printf(" 		GENERE:\n" 
 		"0	-Azione-\n"
        "1	-Avventura-\n" 
        "2	-Romanzo-\n"
        "3	-Fantasy-\n" 
        "4	-Noir-\n"
        "5	-Thriller-\n"
        "6	-Horror-\n");
        printf("		INSERIRE IL NUMERO DEL GENERE:\n");
 scanf("%u", &p->genre);
while(1) 											//con while (1) entra in un loop infinito
 {
  printf("		DATA DI PUBBLICAZIONE:\n");
  scanf("%hd%hd%hd", 
  &p->published.day,
  &p->published.month,
  &p->published.year);

 if (p->published.day<32) 
 	if (p->published.month<13)
 		if (p->published.year<2016)
	 break;				 							//con break esce dal loop
 printf("		--ATTENZIONE DATA NON VALIDA--.\n\n"
 		"		PERFAVORE REINSERIRE LA DATA..\n");
 }

 printf("Numero copie presenti in libreria:  ");
 scanf("%hd", &p->inLibrary);
 printf("Numero copie in prestito:  ");
 scanf("%hd", &p->outLibrary);
 printf("Il codice id del libro è:  ");
 scanf("%hd" , &p->id);
 return Ptr;
 }




void printElem(Book_t *book)
{
 if(book->genre==0)
 	printf("IL genere è Azione");
 else if(book->genre==1)
 	printf("IL genere è Avventura");
 else if(book->genre==2)
 	printf("IL genere è Romanzo");
 else if(book->genre==3)
 	printf("IL genere è Fantasy");
 else if(book->genre==4)
 	printf("IL genere è Noir");
 else if(book->genre==5)
 	printf("IL genere è Thriller");
 else if (book->genre==6)
 	printf("IL genere è Horror");
 	else printf(". IL genere non è disponibile"); 
  
   printf(" L'autore è: %s ",book->writer);
   printf("La data di pubblicazione è:%hd/%hd/%hd.\n",book->published.day, book->published.month, book->published.year);
   printf("Sono presenti %hd libri in archivio\n", book->inLibrary);
   printf("I libri fuori archivio sono %hd\n",book->outLibrary);
   printf("L'id del libro è %hd.\n", book->id);       
} 



Cell_t* searchId(BookList_t* List)                    //Punta alla Cella del libro che cerco.
{
 Cell_t* Temp = List->pFirst;
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

void insTail(BookList_t* List)
{  
 Cell_t *Ptr= allocBook();
 if(List->pLast==NULL)                          	
   List->pLast=List->pFirst = Ptr;				
 else 
     List->pLast->pNext = Ptr;
     List->pLast = Ptr ;
} 

void rmvTail(BookList_t* List) 
{
	Cell_t* tempPtr=List->pFirst;
	if(tempPtr==List->pFirst) 
	{
		free(tempPtr);
		List->pFirst=List->pLast=NULL;
		}
		else 
		{
		while(tempPtr->pNext != List->pLast)
		tempPtr=tempPtr->pNext;
		tempPtr->pNext=NULL;
		free(List->pLast);
		List->pLast=tempPtr;
		}
}
void insHead(BookList_t* List)                  
{  
 Cell_t *p= allocBook();                       
 if (List->pFirst == NULL)
 List->pFirst = p;
}  
 
 
void rmvHead(BookList_t* List)                                                                   
{
	Cell_t* tempPtr= List->pFirst;                              
	if(tempPtr == List->pFirst)
   {
    free(tempPtr);
    List->pFirst = List ->pLast = NULL;
   } 
    else
     {
      while(tempPtr->pNext != List->pLast)       
       tempPtr= tempPtr->pNext;
       tempPtr->pNext = NULL;
       free (List->pFirst);
       List->pFirst= tempPtr;
     }
} 

/*void printList(BookList_t* List)
{
 Cell_t* Temp = List->pFirst;
 if (Temp == NULL)
 {
  printf("L'elenco è vuoto\n");
 }
 else 
  { 
   printf("\nL'elenco è composto dai seguenti libri:\n");
   while(Temp != NULL) 
    {
     printf("%s", Temp->book.title);
     Temp = Temp->pNext;
    }
   printf("Fine\n\n");
  }   
}*/

