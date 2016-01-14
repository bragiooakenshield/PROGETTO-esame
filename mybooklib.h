enum book { Azione=0, Avventura, Romanzo, Fantasy, Thriller, Horror};
struct Date { short day;
              short month;
              short year; 
            };
typedef struct Book { char title [64];
                      char writer [32];
                      enum book genre;
                      struct Date published;
                      short inLibrary;
                      short outLibrary;
                      short id;               
                      } StructBook;                 //Book_t rappresenta tutta la "struct Book"

typedef struct Cell { StructBook book;                     
                      struct Cell* pNext; 
                    } StructCell;                   //Ogni elemento della BookList.Sinonimo distruct Cell.
 
typedef struct BookList { StructCell* pFirst; StructCell *pLast; } BookList; 

                     
StructCell* allocaLibro();								//Alloca la memoria.
void insHead();											//Inserisce il libro all'inizio dell'elenco.
void rmvHead(BookList*);								//Elimina il libro all'inizio dell'elenco.
void insTail();											//Inserisce il libro alla fine dell'elenco.
void rmvTail(BookList*);								//Elimina l'ultimo libro dell'elenco.
void printElem(StructBook*);                    		//Stampa le informazioni di un libro dato il suo codice.
void printList(BookList*);  			                //Stampa tutto l'elenco. 
void comandi();                              			//Sceglie la funzione da svolgere.
StructCell* searchId(BookList*);						//Ricerca un libro attraverso il suo codice(id).
StructCell* rmvId(BookList*);							//Rimuove un libro dato il suo id
