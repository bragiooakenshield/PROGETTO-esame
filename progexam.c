#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mybooklib.h"

int main()
{ 	
	printf("\n\n\t\t\t--/BENVENUTO\\--\n\n");
	BookList Libreria;
	int scelta;
	comandi();
	printf("\nDIGITA LA VOCE SCELTA:\n"); 
	scanf("%d", &scelta);
	while(1)
	{
		switch (scelta) 
		{
		case 1:
		printf("INSERISCI L'ID:\n");
		StructCell *Ptr = searchId(&Libreria);
		if (Ptr != NULL)
		printf("--IL LIBRO È PRESENTE--:)\n");
		else printf("--/IL LIBRO NON È PRESENTE\\--\n\a");
		break;
		  
		case 2:
		printf("INSERISCI L'ID:\n");
		StructCell *p = searchId(&Libreria);
		if (p != NULL)
		{
			printElem(&p->book);
		}
		else printf("\n			--ATTENZIONE--\n\a"
		 			"\n NESSUN LIBRO CON QUESTO ID È DISPONIBILE...\n");
		break;
	 	
	 	case 3:
	 	printf("CERCA IL LIBRO DA RIMUOVERE (INSERISCI L'ID:)\n");
		rmvId(&Libreria);
		break;
	 
	 
		case 4:
		printList(&Libreria);
		break; 

		case 5:
		printf("INSERISCI IL LIBRO IN CIMA:\n");
		insHead(&Libreria);
		break;

		case 6: 
		printf("INSERISCI IL LIBRO IN FONDO:\n");
		insTail(&Libreria);
		break;

		case 7:
		if(Ptr==NULL)
		{ 
		printf("--/NESSUN LIBRO DA RIMUOVERE\\--\n\a");
		}
		else 
		printf("SEI SICURO DI VOLER RIMUOVERE IL PRIMO LIBRO DELL'ELENCO(si/no) ?..\n\a");
		char g[2];
		scanf(" %s",g); 
		if(g[0]=='s'||!strcmp(g,"si"))
			{ 
				rmvHead(&Libreria);
				printf("LIBRO RIMOSSO CORRETTAMENTE.\n\a");
			}
			else if(g[0]=='n'||!strcmp(g,"no"))
				{
					break;
				}
		break;
		  
		case 8:
		if(Ptr==NULL)
		{ 
		printf("--/NESSUN LIBRO DA RIMUOVERE\\--\n\a");
		}
		else 
			printf("SEI SICURO DI VOLER RIMUOVERE L'ULTIMO LIBRO DELL'ELENCO(si/no) ?..\a\n");
			char d[2];
			scanf(" %s",d); 
			if(d[0]=='s'||!strcmp(d,"si"))
			{ 
				if (Ptr!=NULL)
				 {
				 rmvTail(&Libreria);
				 printf("LIBRO RIMOSSO CORRETTAMENTE.\n");
				 }
				 else printf("NESSUN LIBRO PRESENTE\n");
			}
			else if(d[0]=='n'||!strcmp(d,"no"))
			{
			break;
			}
		
		break;
		 
		case 9:
		printf("CERCA IL LIBRO DA PRELEVARE:..(INSERISCI L'ID)\n");
		StructCell* in=searchId(&Libreria);
		if (in!=NULL)
		{
		 	in->book.inLibrary--;
		 	in->book.outLibrary++;
		 	printf("LIBRO PRELEVATO CORRETTAMENTE\n");
		}
		else printf("\t\t--/LIBRO NON PRELEVATO\\--\n\a"
		" (NESSUN ID CORRISPONDENTE)");
		break;
		  
		case 10:
		printf("RESTITUISCI UN LIBRO..(INSERISCI L'ID)\n");
		StructCell* out=searchId(&Libreria);
		if (out!=NULL)
		{
			out->book.outLibrary--;
			out->book.inLibrary++;
			printf("RESO COMPLETATO..GRAZIE!\n");
		} 
		else printf("\t\t--/LIBRO NON RESTITUITO\\--\a\n"
		" (NESSUN ID CORRISPONDENTE)");
		break;
		
		case 11:
		printf("SEI SICURO DI VOLER USCIRE:(si/no)?\n\a");
		char c[2];
		scanf(" %s",c);
		if(c[0]=='s'||!strcmp(c,"si"))
			{ 
				printf("\n\t\t\aARRIVEDERCI!..A PRESTO!!\n\n");
				return 0;
			}
			else if(c[0]=='n'||!strcmp(c,"no"))
			{
				break;
			}
		}  
	printf("\n\tSELEZIONARE UNA VOCE:\n ");
	scanf("%d", &scelta);
	} 
	return 0;
} 





 
