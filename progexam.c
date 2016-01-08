#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mybooklib.h"

int main()
{ 
 BookList_t Libreria;
 int scelta;
 comandi();
 printf("\nSelezionare una voce: "); 
 scanf("%d", &scelta);
 while(scelta!=4)
  {
  switch (scelta) 
     {
       case 1:
      printf("Cerca il libro dal suo id:\n");
      Cell_t *Ptr = searchId(&Libreria);
      if (Ptr != NULL)
        printf("VERO\n");
      else printf("FALSO\n");
      break;
      
      case 2:
      printf("Inserire l'id:\n");
      Cell_t *p = searchId(&Libreria);
      if (p != NULL)
      printElem(&p->book);
      else printf("Nessun libro con questo id è disponibile.\n");
      break;
 
     case 3: 
      printf("Inserire il Libro:\n");
      insTail(&Libreria);
      break;

      case 4:
      printf("Rimosso l'ultimo libro dalla lista.\n");
      rmvTail(&Libreria);
      break;

     /* case 5:
      printf("Inserire il libro:\n");
      insHead(&Library);
      break;

      case 6:
      printf("Rimuovi il primo libro dalla lista.\n");
      rmvHead(&Library);
      break;*/
    }
  
  printf("\nSelezionare una voce: ");
  scanf("%d", &scelta);
  } 
 return 0;
}  
