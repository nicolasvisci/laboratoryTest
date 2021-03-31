#ifndef FUNZIONI_H_INCLUDED
#define FUNZIONI_H_INCLUDED

#include "gestione_dati.h"

/**
* @file funzioni.h
*
* Il file contiene il prototipo della funzione che stampa il menu' delle
* scelte e i prototipi delle funzioni chiamate all'interno delle funzioni del main.
*
* @date 05/02/2021
* @author Nicolas Visci
*
* @bug Nessun bug da segnalare.
*/

///Stampa il menu' delle scelte per aiutare l'utente nell'usabilita' del programma.
void menu();

///Stampa le righe precedenti a una riga selezionata tramite relazione d'ordine.
void relazioneDordine();

///Legge i dati di un file gia' creato e stampa l'elenco completo dei dati acquisiti.
void aggiornamentoPacchi();

///Modifica il campo destinazione della struttura dati.
void modificaPacco();

#endif // FUNZIONI_H_INCLUDED
