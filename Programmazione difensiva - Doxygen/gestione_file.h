#ifndef GESTIONE_FILE_H_INCLUDED
#define GESTIONE_FILE_H_INCLUDED

#include "gestione_dati.h"

/**
* @file gestione_file.h
*
* Contiene i prototipi delle funzioni che agiscono sui file.
* Vengono incluse le librerie che contengono le dichiarazioni delle funzioni chiamate
* all'interno delle funzioni presenti.
*
* In particolare, il file contiene i prototipi delle funzioni che aprono il file, leggono il file e chiudono il file,
* oltre a quelle di scrittura sui vari file, ovvero le funzioni  di salvataggio
* dei pacchi postali su file, in base alla formattazione richiesta.
*
* @date 05/02/2021
* @author Nicolas Visci
*
* @bug Nessun bug da segnalare.
*/

/**
* Apre il file.
*
* @param[in] nomeFile e' il nome del file da aprire.
* @param[in] mode e' la modalita' con la quale il file deve essere aperto(lettura,
* scrittura...).
*/
void apriFile(char *nomeFile, char *mode);

///Legge i dati del file attualmente aperto.
void leggiFile();

///Chiude il file attualmente aperto
void chiudiFile();

//INUTILIZZATA
void scriviRigaFile();

/**
* Salva i pacchi postali identificati con l'indice (i) nel file attualmente aperto.
*
* @param[in] i e' l'indice dei pacchi postali da salvare.
*/
void scritturaSuFile(int i);

/**
* Salva tutti i pacchi postali sul file attualmente aperto.
*
* @param[in] nPacchi e' il massimo dei pacchi postali che deve salvare sul file attualmente aperto.
*/
void scritturaPacchi(int nPacchi);

#endif // GESTIONE_FILE_H_INCLUDED
