#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mybooklib.h"

int main()
{ 
 BookList_t Library;
 int choice;
 instructions();
 printf("\nSelezionare una voce: "); 
 scanf("%d", &choice);
 while(choice!=7)
  {
  switch (choice) 
     {
       case 1:
      printf("Cerca il libro dal suo id:\n");
      Cell_t *tail = searchId(&Library);
      if (tail != NULL)
        printf("VERO\n");
      else printf("FALSO\n");
      break;
      
      case 2:
      /*printf("Controllo la lista\n");
      Cell_t *ptr = Control(&Library);
      if (ptr != NULL)
      break;*/
      printf("Inserire l'id:\n");
      Cell_t *p = searchId(&Library);
      if (p != NULL)
      printElem(&p->book);
      else printf("Nessun libro con questo id è disponibile.\n");
      break;
 
     case 3: 
      printf("Inserire il Libro:\n");
      insTail(&Library);
      break;

      case 4:
      printf("Rimosso l'ultimo libro dalla lista.\n");
      rmvTail(&Library);
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
  scanf("%d", &choice);
  } 
 return 0;
}  
