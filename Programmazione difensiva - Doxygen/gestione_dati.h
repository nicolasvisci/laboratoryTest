#ifndef GESTIONE_DATI_H_INCLUDED
#define GESTIONE_DATI_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/**
* @file gestione_dati.h
*
* Contiene i prototipi delle funzioni che accedono direttamente al dato.
* Vengono incluse le librerie standard, le quali saranno visibili all'interno di tutti
* gli altri file del programma.
*
* In particolare, il file contiene le costanti utili in tutti i file del programma, la
* dichiarazione della struct, la dichiarazione degli
* operatori leciti che scrivono nel dato e che prendono i valori
* dal dato (per seguire i principi di astrazione dei dati) e, infine anche i prototipi
* delle funzioni che stampano determinati dati e effettuano controlli su quest'ultimi.
*
* @date 05/02/2021
* @author Nicolas Visci
*
* @bug Nessun bug da segnalare.
*/

///Massima lunghezza accettabile per i nomi del file acquisiti da tastiera
#define MAXFILE 15

///Massima lunghezza accettabile per il campo Destinazione
#define MAXDESTINAZIONE 20

///Massima lunghezza accettabile per il campo Corriere
#define MAXCORRIERE 20

///Massima lunghezza accettabile per il campo Tipologia
#define MAXTIPOLOGIA 20

///Numero massimo di pacchi acquisiti da file
#define MAXPACCHI 5

///Numero massimo di pacchi totali acquisiti dal file "Totale.txt"
#define MAXPACCHITOTALI 10

///E' il puntatore assegnato ai vari file che verranno aperti nel corso dell'esecuzione del programma.
FILE *ptr;

/**
* E' la struttura dati dove verranno acquisiti i pacchi postali letti da file, in particolare
* il codice, il corrire, la destinazione, la tipologia e il peso di un determinato pacco postale.
*/
typedef struct
{

    int codice;
    char corriere[MAXCORRIERE];
    char destinazione[MAXDESTINAZIONE];
    char tipologia[MAXTIPOLOGIA];
    int peso;

} pacchi;

/// Array contenente tutti i dati dei vari pacchi  postali acquisiti da file.
pacchi arrayPacchi[MAXPACCHI];

/**
* Operatore lecito che scrive nella struttura l'elemento in posizione (i).
*
* @param[in] i e' l'indice della posizione nella quale va inserito
* l'elemento
* @param[in] codice e' il valore da inserire nella struttura.
*/
void setCodice(int i, int codice);

/**
* Operatore lecito che scrive nella struttura l'elemento in posizione (i).
*
* @param[in] i e' l'indice della posizione nella quale va inserito
* l'elemento
* @param[in] corriere e' il valore da inserire nella struttura.
*/
void setCorriere(int i, char *corriere);

/**
* Operatore lecito che scrive nella struttura l'elemento in posizione (i).
*
* @param[in] i e' l'indice della posizione nella quale va inserito
* l'elemento
* @param[in] destinazione e' la destinazione del pacco da inserire nella struttura.
*/
void setDestinazione(int i, char *destinazione);

/**
* Operatore lecito che scrive nella struttura l'elemento in posizione (i).
*
* @param[in] i e' l'indice della posizione nella quale va inserito
* l'elemento
* @param[in] tipologia e' la tipologia del pacco da inserire nella struttura.
*/
void setTipologia(int i, char *tipologia);

/**
* Operatore lecito che scrive nella struttura l'elemento in posizione (i).
*
* @param[in] i e' l'indice della posizione nella quale va inserito
* l'elemento
* @param[in] peso e' il valore da inserire nella struttura.
*/
void setPeso(int i, int peso);

/**
* Operatore lecito che restituisce il codice relativo al pacco postale in posizione (i).
*
* @param[in] i e' l'indice della posizione dalla quale va recuperato il dato.
*
* @return Valore intero dell'elemento codice in posizione (i).
*/
int getCodice(int i);

/**
* Operatore lecito che restituisce il corriere relativo al pacco postale in posizione (i).
*
* @param[in] i e' l'indice della posizione dalla quale va recuperato il dato.
*
* @return corriere del pacco postale in posizione (i).
*/
char *getCorriere(int i);

/**
* Operatore lecito che restituisce la destinazione relativo al pacco postale in posizione (i).
*
* @param[in] i e' l'indice della posizione dalla quale va recuperato il dato.
*
* @return destinazione del pacco postale in posizione (i).
*/
char *getDestinazione(int i);

/**
* Operatore lecito che restituisce la tipologia relativo al pacco postale in posizione (i).
*
* @param[in] i e' l'indice della posizione dalla quale va recuperato il dato.
*
* @return tipologia del pacco postale in posizione (i).
*/
char *getTipologia(int i);

/**
* Operatore lecito che restituisce il peso relativo al pacco postale in posizione (i).
*
* @param[in] i e' l'indice della posizione dalla quale va recuperato il dato.
*
* @return Valore intero dell'elemento peso in posizione (i).
*/
int getPeso(int i);

///Stampa della riga di indice (i) dei pacchi postali.
void stampaRiga(int i);

/**
* Stampa di tutti i pacchi postali presenti nella struttura dati.
*
* @param[in] nPacchi e' il massimo numero di pacchi postali che deve stampare.
*/
void stampaPacchi(int nPacchi);

/**
* Controlla che il peso inserito dall'utente sia un dato presente nella struttura, nel
* caso fosse presente ritorna 0.
*
* @param[in] peso e' il valore da trovare all'interno della struttura.
*
* @return valore 0 se il valore peso � presente nella struttura.
*/
int controlloPeso(char *peso);

/**
* Controlla che il codice inserito dall'utente sia un dato presente nella struttura, nel
* caso fosse presente ritorna 0.
*
* @param[in] codice e' il valore da trovare all'interno della struttura.
*
* @return i e' l'indice del codice trovato nella struttura.
*/
int selezionaCodice(int codice);

///Controlla che i codici appena acquisiti non siano uguali a quelli gi� acquisiti precedentemente.
void controlloDuplicati();

#endif // GESTIONE_DATI_H_INCLUDED
