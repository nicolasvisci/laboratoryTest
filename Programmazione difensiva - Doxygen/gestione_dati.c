#include "gestione_dati.h"

/**
* @file gestione_dati.c
*
* Contiene l'implementazione delle funzioni che accedono direttamente al dato.
*
* In particolare il file contiene la definizione degli operatori leciti che scrivono
* nel dato e che prendono i valori dal dato e anche l'implementazione
* delle funzioni che effettuano dei controlli sui dati e stampano quest'ultimi.
*
* @date 05/02/2021
* @author Nicolas Visci
*
* @bug Nessun bug da segnalare.
* @warning Tutte le possibilit� di crash inatteso da parte del programma sono stati
* previsti, risolti e giustificati tramite controlli di programmazione
* difensiva e all'interno delle relative funzioni.
*/

/**
* Operatore lecito che scrive nella struttura  dati l'elemento in posizione (i),
* assegnando il valore del parametro codice all'elemento
* della struttura in posizione (i).
*
* @pre codice deve essere compreso nel range dei valori rappresentabili dal tipo di dato int.
* @pre i deve essere compreso tra 0 e MAXPACCHI (con il valore di MAXPACCHI non compreso).
*/
void setCodice(int i, int codice)
{

  arrayPacchi[i].codice = codice;
}

/**
* Operatore lecito che scrive nella struttura l'elemento in posizione (i),
* assegnando il valore del parametro corriere all'elemento
* della struttura in posizione (i).
*
* @pre corriere deve avere massimo i caratteri dettati dalla costante MAXCORRIERE.
* @pre i deve essere compreso tra 0 e MAXPACCHI (con il valore di MAXPACCHI non compreso).
*/
void setCorriere(int i, char *corriere)
{

  strcpy(arrayPacchi[i].corriere, corriere);
}

/**
* Operatore lecito che scrive nella struttura l'elemento in posizione (i),
* assegnando il valore del parametro destinazione all'elemento
* della struttura in posizione (i).
*
* @pre destinazione deve avere massimo i caratteri dettati dalla costante MAXDESTINAZIONE.
* @pre i deve essere compreso tra 0 e MAXPACCHI (con il valore di MAXPACCHI non compreso).
*/
void setDestinazione(int i, char *destinazione)
{

  strcpy(arrayPacchi[i].destinazione, destinazione);
}

/**
* Operatore lecito che scrive nella struttura l'elemento in posizione (i),
* assegnando il valore del parametro tipologia all'elemento
* della struttura in posizione (i).
*
* @pre tipologia deve avere massimo i caratteri dettati dalla costante MAXTIPOLOGIA.
* @pre i deve essere compreso tra 0 e MAXPACCHI (con il valore di MAXPACCHI non compreso).
*/
void setTipologia(int i, char *tipologia)
{

  strcpy(arrayPacchi[i].tipologia, tipologia);
}

/**
* Operatore lecito che scrive nella struttura l'elemento in posizione (i),
* assegnando il valore del parametro peso all'elemento
* della struttura in posizione (i).
*
* @pre codice deve essere compreso nel range dei valori rappresentabili dal tipo di dato int.
* @pre i deve essere compreso tra 0 e MAXPACCHI (con il valore di MAXPACCHI non compreso).
*/
void setPeso(int i, int peso)
{

  arrayPacchi[i].peso = peso;
}

/**
* Operatore lecito che restituisce l'elemento codice della struttura in posizione (i).
*
* @pre i deve essere compreso tra 0 e MAXPACCHI (con il valore di MAXPACCHI non compreso).
* Risolto con programmazione difensiva.
* @post Valore int dell'elemento codice presente nella struttura in posizione (i).
*/
int getCodice(int i)
{

  return arrayPacchi[i].codice;
}

/**
* Operatore lecito che restituisce l'elemento corriere della struttura in posizione (i).
*
* @pre i deve essere compreso tra 0 e MAXPACCHI (con il valore di MAXPACCHI non compreso).
* Risolto con programmazione difensiva.
* @post Corriere del pacco postale  presente nella struttura in posizione (i).
*/
char *getCorriere(int i)
{

  return arrayPacchi[i].corriere;
}

/**
* Operatore lecito che restituisce l'elemento destinazione della struttura in posizione (i).
*
* @pre i deve essere compreso tra 0 e MAXPACCHI (con il valore di MAXPACCHI non compreso).
* Risolto con programmazione difensiva.
* @post Destinazione del pacco postale presente nella struttura in posizione (i).
*/
char *getDestinazione(int i)
{

  return arrayPacchi[i].destinazione;
}

/**
* Operatore lecito che restituisce l'elemento tipologia della struttura in posizione (i).
*
* @pre i deve essere compreso tra 0 e MAXPACCHI (con il valore di MAXPACCHI non compreso).
* Risolto con programmazione difensiva.
* @post Tipologia del pacco postale presente nella struttura in posizione (i).
*/
char *getTipologia(int i)
{

  return arrayPacchi[i].tipologia;
}

/**
* Operatore lecito che restituisce l'elemento peso della struttura in posizione (i).
*
* @pre i deve essere compreso tra 0 e MAXPACCHI (con il valore di MAXPACCHI non compreso).
* Risolto con programmazione difensiva.
* @post Valore int dell'elemento peso presente nella struttura in posizione (i).
*/
int getPeso(int i)
{

  return arrayPacchi[i].peso;
}

/// La funzione svolge il solo compito di stampa della riga identificata dal parametro in ingresso i.
void stampaRiga(int i)
{

  printf("%d %s %s %s %d\n", getCodice(i), getCorriere(i), getDestinazione(i), getTipologia(i), getPeso(i));
}

/**
* La funzione svolge il solo compito di stampa di tutte le righe identificate dall'indice i,
* con un massimo di righe dettate dal parametro in ingresso nPacchi.
* La funzione presenta un frammento di codice di programmazione difensiva, con il quale ci
* si accerta che l'indice dell'iterazione non sia uguale o non superi il valore nPacchi.
*
* @warning Nessun warning da segnalare riguardo la struttura di iterazione determinata,
* dato che non vengono effettuate operazioni sull'indice (oltre l'incremento dettato
* dal for).
*/
void stampaPacchi(int nPacchi)
{

  for (int i = 0; i < nPacchi; i++)
  {

    if (i >= nPacchi)
    {
      printf("Errore nella stampa dei dati: numero di righe non valido.\nUscita in corso...\n");
      exit(EXIT_FAILURE);
    }

    printf("%d %s %s %s %d\n", getCodice(i), getCorriere(i), getDestinazione(i), getTipologia(i), getPeso(i));
  }
}

/**
* Controlla che il peso inserito dall'utente sia un dato presente nella struttura, nel
* caso fosse presente ritorna 0, nel caso non fosse presente termina il programma anticipatamente,
* mostrando a video all'utente un messaggio con l'avviso di non aver trovato il codice da lui inserito.
* E' anche presente un frammento di codice di programmazione difensiva, con il quale ci
* si accerta che l'indice dell'iterazione non superi il valore predefinito.
*
* @param[in] peso e' il valore da trovare all'interno della struttura.
*
* @return valore 0 se il valore peso � presente nella struttura.
*/
int controlloPeso(char *peso)
{

  for (int i = 0; i < MAXPACCHI; i++)
  {

    if (i >= MAXPACCHI)
    {

      printf("Errore nel controllo: numero di pacchi non valido.\nUscita in corso...\n");
      exit(EXIT_FAILURE);
    }

    if (peso == getPeso(i))
    {
      return 0;
    }
  }

  printf("Peso inserito ERRATO\n");
  exit(EXIT_FAILURE);
}

/**
* Controlla che il codice inserito dall'utente sia un dato presente nella struttura, nel
* caso non fosse presente termina il programma anticipatamente, mostrando a video all'utente
* un messaggio con l'avviso di non aver trovato il codice da lui inserito.
* E' anche presente un frammento di codice di programmazione difensiva, con il quale ci
* si accerta che l'indice dell'iterazione non superi il valore predefinito.
*
* @param[in] codice e' il valore da trovare all'interno della struttura.
*
* @return i e' l'indice del codice trovato nella struttura.
*/
int selezionaCodice(int codice)
{

  int i;

  for (int i = 0; i < MAXPACCHITOTALI; i++)
  {

    if (i >= MAXPACCHITOTALI)
    {

      printf("Errore nel controllo: numero di pacchi non valido.\nUscita in corso...\n");
      exit(EXIT_FAILURE);
    }

    if (codice == getCodice(i))
    {

      return i;
    }
  }

  printf("Codice non trovato\nUscita in corso...\n");
  exit(EXIT_FAILURE);
}

/**
* La procedura si occupa di controllare che i codici appena acquisiti non siano uguali a quelli gi� acquisiti in precedenza,
* se anche un solo codice fosse uguale ad un altro, il programma terminer�, mostrando un avviso all'utente con il messaggio
* che all'interno dei nuovi dati vi e' un duplicato.
* E' anche presente un frammento di codice di programmazione difensiva, con il quale ci
* si accerta che l'indice dell'iterazione non superi il valore predefinito.
*
* @pre Il numero di codici, dettato dalla costante MAXPACCHI, deve
* essere maggiore di 0, altrimenti il controllo di programmazione difensiva, terminer� il
* programma anticipatamente.
*
* @warning Nessun warning da segnalare riguardo la struttura di iterazione determinata,
* dato che non vengono effettuate operazioni sull'indice (oltre l'incremento dettato
* dal for).
*
*/
void controlloDuplicati()
{

  int codici[MAXPACCHI];

  if (MAXPACCHI <= 0)
  {

    printf("Codice non acquisibile.\nUscita in corso...\n");
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < MAXPACCHI; i++)
  {

    if (i >= MAXPACCHI)
    {

      printf("Errore nel controllo: numero di pacchi non valido.\nUscita in corso...\n");
      exit(EXIT_FAILURE);
    }

    codici[i] = getCodice(i);

    if (codici[i] == 1 || codici[i] == 2 || codici[i] == 3 || codici[i] == 4 || codici[i] == 5)
    {

      printf("Presente duplicato\n");
      exit(EXIT_FAILURE);
    }
  }
}
