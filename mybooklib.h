enum book { Azione=0, Avventura, Romanzo, Fantasy, Noir, Thriller, Horror};
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
                      short id;                 //L'id è il codice univoco di riconoscimento.
                      } Book_t;                 //Book_t rappresenta tutta la "struct Book"

typedef struct Cell { Book_t book;                     
                      struct Cell* pNext; 
                    } Cell_t;                   //Ogni elemento della BookList.Sinonimo distruct Cell.
 
typedef struct BookList { Cell_t* pFirst; Cell_t *pLast; } BookList_t; 

                     
Cell_t* allocBook();                            //Alloca memoria per una struct Cell.
void insHead();                                 //Inserisce un libro in cima alla lista
void rmvHead(BookList_t*);                          //Elimina libro in cima alla lista. 
void insTail();                                 //Inserisce un  libro in fondo alla lista.
void rmvTail(BookList_t*);                          //Elimina libro in fondo alla lista.
void printElem(Book_t*);                        //Stampa elementi di un libro dato il suo codice.
void printList(BookList_t*);                   //Stampa tutti i campi di tutta la lista. 
void instructions();                            //Sceglie la funzione da svolgere.
Cell_t* searchId(BookList_t*);                             //Ricerca un elemento attraverso il suo codice.
