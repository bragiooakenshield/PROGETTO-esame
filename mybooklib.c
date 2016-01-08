#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mybooklib.h"


void instructions()
        {
         printf("Selezionare una voce:\n"
                "1 Per vedere se un libro è presente nella lista attraverso il suo id.\n"
                "2 Per vedere un libro dal suo id.\n"
                "3 Per inseire un elemento in fondo alla lista.\n"
                "4 Per Uscire.\n");
        }        

Cell_t *allocBook()
{
 Cell_t *Ptr = malloc(sizeof(Cell_t));
 Book_t *p = &Ptr->book;
 if(p==NULL)
 {
  printf("Allocazione memoria fallita\n");
 } 
  
 printf("Titolo:");
 scanf("%s", p->title);
 printf("Scrittore:");
 scanf("%s", p->writer);
 printf(" Genere:\n" 
 		"0.Azione;\n"
        "1.Avventura;\n" 
        "2.Romanzo;\n"
        "3.Fantasy;\n" 
        "4.Noir;\n"
        "5.Thriller;\n"
        "6.Horror. ");
 scanf("%u", &p->genre);
while(1) 											//con while (1) entra in un loop infinito
 {
  printf("Data diPubblicazione:\n");
  scanf("%hd%hd%hd", 
  &p->published.day,
  &p->published.month,
  &p->published.year);

 if (p->published.day<32) 
 	if (p->published.month<13)
 		if (p->published.year<2016)
	 break;				 							//con break esce dal loop
 printf("Data non valida\n");
 
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
   printf("La data è:%hd/%hd/%hd.\n",book->published.day, book->published.month, book->published.year);
   printf("Sono presenti %hd libri in archivio\n", book->inLibrary);
   printf("I libri fuori archivio sono %hd\n",book->outLibrary);
   printf("L'id del libro è %hd.\n", book->id);       
} 



Cell_t* searchId(BookList_t* List)                    //Puntatore alla Cell del libro che cerco.
{
 Cell_t* Temp = List->pFirst;
 short id;
 scanf("%hd", &id);
 while(Temp)
   {
   	 if(Temp->book.id == id)
   	 break;
 	Temp = Temp->pNext;
	} 
	return Temp;
}

void insTail(BookList_t* List)
{  
 Cell_t *Gandalf= allocBook();
 if(List->pLast==NULL)                          	 // Gandalf è il nome generico della funzione.
   List->pLast=List->pFirst = Gandalf;				
 else 
     List->pLast->pNext = Gandalf;
     List->pLast = Gandalf ;
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
/*void insHead(BookList_t* List)                  //le ho messe come commento perchè non funzionano :)
{  
 Cell_t *p= allocBook();                       
 if (List->pFirst == NULL)
 List->pFirst = p;
}  
 
 
void rmvHead(BookList_t* List)                                                                   
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
} */
