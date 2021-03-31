#include "gestione_file.h"

/**
* @file gestione_file.c
*
* Contiene l'implementazione delle funzioni che agiscono sui file.
*
* In particolare, il file contiene la definizione delle funzioni che aprono il file,
* leggono il file e chiudono il file, oltre a quelle di scrittura sui vari file, ovvero le funzioni  di salvataggio
* dei pacchi postali su file, in base alla formattazione richiesta.
*
* @date 05/02/2021
* @author Nicolas Visci
*
* @bug Nessun bug da segnalare.
* @warning Tutte le possibilita' di crash inatteso da parte del programma sono stati
* previsti, risolti e giustificati tramite controlli di programmazione
* difensiva all'interno delle relative funzioni.
*/

/**
* La funzione si occupa di aprire il file e di assegnare l'area di memoria al puntatore
* ptr di tipo FILE.
*
* @post Il puntatore deve essere assegnato a un indirizzo di memoria.
*/
void apriFile(char *nomeFile, char *mode)
{

    ptr = fopen(nomeFile, mode);
    if (ptr == NULL)
    {
        printf("Errore durante l'apertura del file...\nUscita in corso...\n");
        free(ptr);
        exit(EXIT_FAILURE);
    }
}

/**
* La funzione si occupa di leggere da file le informazioni relative ai pacchi postali.
*
* Nella funzione sono presenti controlli di programmazione difensiva, per
* controllare che il file non sia vuoto, infatti viene letto un carattere e, se esso e'
* il carattere EOF (end of file), l'esecuzione del programma viene interrotta con un
* messaggio di errore visibile all'utente, altrimenti il file position pointer viene
* riportato all'inizio del file tramite la funzione rewind().
* Sono anche presenti i controlli con i quali si assicura che i dati siano acquisiti correttamente,
* in particolare ogni carattere di una stringa viene confrontato con un determinato carattere speciale
* e se tale carattere corrisponde, allora verra' sostituito con "\0" (carattere di fine stringa).
*/
void leggiFile()
{

    int j;
    char h;

    if ((h = getc(ptr)) == EOF)
    {
        printf("Errore: file vuoto.\nUscita in corso...\n");
        exit(EXIT_FAILURE);
    }

    rewind(ptr);

    while (!feof(ptr))
    {

        int codice;
        char corriere[MAXCORRIERE];
        char destinazione[MAXDESTINAZIONE];
        char tipologia[MAXTIPOLOGIA];
        int peso;

        int i;

        fscanf(ptr, "%d$", &codice);

        for (i = 0; i < MAXCORRIERE; i++)
        {
            h = fgetc(ptr);
            if (h == '$')
            {
                corriere[i] = '\0';
                break;
            }
            corriere[i] = h;
        }

        for (i = 0; i < MAXDESTINAZIONE; i++)
        {
            h = fgetc(ptr);
            if (h == '$')
            {
                destinazione[i] = '\0';
                break;
            }
            destinazione[i] = h;
        }

        for (i = 0; i < MAXTIPOLOGIA; i++)
        {
            h = fgetc(ptr);
            if (h == '$')
            {
                tipologia[i] = '\0';
                break;
            }
            tipologia[i] = h;
        }

        fscanf(ptr, "%d", &peso);

        setCodice(j, codice);
        setCorriere(j, corriere);
        setDestinazione(j, destinazione);
        setTipologia(j, tipologia);
        setPeso(j, peso);

        stampaRiga(j);

        j++;
    }

    printf("\n");
}

/**
* La funzione si occupa di chiudere il file correntemente aperto.
*
* La funzione presenta un frammento di codice di programmazione difensiva, per
* accertarsi che la chiusura del file sia andata a buon fine (valore restituito
* dalla funzione fclose sia 0).
*
* @post Il file sia effettivamente chiuso.
*/
void chiudiFile()
{

    if (fclose(ptr) != 0)
    {
        printf("Errore nella chiusura del file.\nUscita in corso...\n");
        free(ptr);
        exit(EXIT_FAILURE);
    }
}

/**
* La funzione svolge il solo compito di salvataggio dei pacchi postali identificati dal
* parametro in ingresso i. Il formato della scrittura su file e' dettato in base alla formattazione richiesta.
*/
void scritturaSuFile(int i)
{

    fprintf(ptr, "%d$%s$%s$%s$%d\n", getCodice(i), getCorriere(i), getDestinazione(i), getTipologia(i), getPeso(i));
}

/**
* La funzione svolge il solo compito di salvataggio dei pacchi postali identificati tramite l'indice i interno al ciclo for.
*
* La funzione presenta un frammento di codice di programmazione difensiva, con il quale ci
* si accerta che l'indice dell'iterazione non superi il valore
* predefinito.
*
* @post Sul file siano stati effettivamente scritti i pacchi postali.
*
* @warning Nessun warning da segnalare riguardo la struttura di iterazione determinata,
* dato che non vengono effettuate operazioni sull'indice (oltre l'incremento dettato
* dal for).
*/
void scritturaPacchi(int nPacchi)
{

    for (int i = 0; i < nPacchi; i++)
    {

        if (i >= nPacchi)
        {
            printf("Errore nel salvataggio dei pacchi postali: numero di pacchi postali non valido\nUscita in corso...\n");
            exit(EXIT_FAILURE);
        }

        scritturaSuFile(i);
    }
}
