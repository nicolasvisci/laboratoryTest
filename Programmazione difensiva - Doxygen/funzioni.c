#include "funzioni.h"

/**
* @file funzioni.c
*
* Contiene la definizione delle funzioni chiamate nelle funzioni del main.
*
* In particolare, il file contiene l'implementazione della funzione che stampa il
* menu' delle scelte e l'implementazione delle funzioni che vengono chiamate nelle funzioni del main.
*
* @date 05/02/2021
* @author Nicolas Visci
*
* @bug Nessun bug da segnalare
* @warning Tutte le possibilita' di crash inatteso da parte del programma sono stati
* previsti, risolti, e giustificati tramite controlli di programmazione
* difensiva all'interno delle relative funzioni.
*/

/**
* La funzione svolge il compito di stampa del menu' di scelte, in modo tale che
* l'utente possa capire facilmente come far funzionare il programma.
*/
void menu()
{

  printf("1.Acquisizione\n2.Selezione\n3.Aggiornamento\n4.Modifica\n5.Esci\n");
}

/**
* La funzione svolge il compito di stampare a video i pacchi postali  precedenti
* a un pacco postale selezionato dall'utente tramite l'inserimento di due dati da tastiera.
* In particolare, la funzione chiede di inserire la relazione d'ordine all'utente,
* apre il file Prima.txt in modalita' scrittura (in modo che il file
* possa essere creato sul momento nel caso in cui non esista ancora),
* controlla che entrambi i dati inseriti da tastiera sono presenti all'interno della struttura
* e se sono entrambi presenti allora stampa i pacchi postali precedenti a quello selezionato,
* sino al primo pacco, e salva tali pacchi postali sul file attualmente aperto, e chiude il file.
* La funzione presenta diversi frammenti di codice di programmazione difensiva, con i quali
* ci si accerta che l'indice dell'iterazione non superi il valore predefinito.
*
* @pre La lunghezza della tipologia dettata dalla costante MAXTIPOLOGIA, deve essere maggiore di 0,
* altrimenti il controllo di programmazione difensiva, terminera' il
* programma anticipatamente.
* @warning Il valore di pesoPacco deve essere compreso nel range di valori
* rappresentabili dal tipo di dato int.
* @warning Nessun warning da segnalare riguardo la prima struttura di iterazione determinata,
* dato che non vengono effettuate operazioni sull'indice (oltre l'incremento dettato
* dal for).
* @warning Nella seconda struttura di iterazione, l'indice parte dal valore precedente
* ad un valore definito fino ad arrivare a 0.
*/
void relazioneDordine()
{

  char tipologiaPacco[MAXTIPOLOGIA];

  if (MAXTIPOLOGIA <= 0)
  {

    printf("Tipologia non acquisibile.\nUscita in corso...\n");
    exit(EXIT_FAILURE);
  }

  int pesoPacco;

  int i = 0;
  int j = 0;
  int compareTipologia = 1;
  int comparePeso = 1;

  printf("Inserisci relazione d'ordine(tipologia,peso): \n");
  scanf("%s %d", tipologiaPacco, &pesoPacco);
  apriFile("Prima.txt", "w");
  for (i = 0; i < MAXPACCHI; i++)
  {

    if (i >= MAXPACCHI)
    {
      printf("Errore nel confronto dei dati.\nUscita in corso...\n");
      exit(EXIT_FAILURE);
    }

    compareTipologia = strcmp(tipologiaPacco, getTipologia(i));
    comparePeso = controlloPeso(pesoPacco);
    if (compareTipologia == 0 && comparePeso == 0)
    {
      for (j = i - 1; j > -1; j--)
      {

        if (j <= -1)
        {
          printf("Errore nella stampa delle righe.\nUscita in corso...\n");
          exit(EXIT_FAILURE);
        }

        stampaRiga(j);
        scritturaSuFile(j);
      }
    }
  }

  if (comparePeso != 0 && compareTipologia != 0)
  {

    printf("Dati inseriti non validi...\n");
    exit(EXIT_FAILURE);
  }

  chiudiFile();
}

/**
* La funzione svolge il compito di stampare a video tutti i pacchi postali dei file letti.
* In particolare, apre il file pacchi.txt in modalita' lettura,
* legge il file e stampa i pacchi postali del file attualmente aperto, e chiude il file.
* Successivamente, apre il file Totale.txt in modalita' di scrittura (in modo che il file
* possa essere creato sul momento nel caso in cui non esista ancora), salva sul file attualmente
* aperto i pacchi postali acquisiti e chiude il file,  apre il file Aggiornamento.txt in modalita' lettura,
* legge il file e dopo aver controllato la presenza di duplicati,
* stampa i pacchi postali del file attualmente aperto, e chiude il file.
* Infine apre nuovamente il file Totale.txt in modalita' append e salva i pacchi acquisiti dal file
* Aggiornamento.txt, nel file Totale.txt attualmente aperto.
* Non sono presenti porzioni di codice dedicati alla programmazione difensiva, in
* quanto i controlli sono implementati all'interno delle varie funzioni.
*/
void aggiornamentoPacchi()
{

  apriFile("pacchi.txt", "r");
  printf("Pacchi iniziali\n");
  leggiFile();
  chiudiFile();

  apriFile("Totale.txt", "w");
  scritturaPacchi(MAXPACCHI);
  chiudiFile();

  apriFile("Aggiornamento.txt", "r");
  printf("Pacchi aggiornati\n");
  leggiFile();
  controlloDuplicati();
  chiudiFile();

  apriFile("Totale.txt", "a");
  scritturaPacchi(MAXPACCHI);
  chiudiFile();
}

/**
* La funzione svolge il compito di modificare la destinazione di una determinato pacco postale,
* tramite l'inserimento del codice frl pacco da tastiera.
* In particolare la funzione apre il file Totale.txt in modalita' lettura, legge il file,
* stampa i pacchi postali acquisiti e chiude il file.
* Successivamente tramite l'inserimento del codice del pacco da parte dell'utente, si identifica
* il pacco postale su cui modificare il campo destinazione, e dopo aver inserito la nuova
* destinazione da tastiera, vi � la modifica del campo e la stampa aggiornata di tutti i pacchi postali.
*
* @pre La lunghezza della tipologia dettata dalla costante MAXDESTINAZIONE, deve essere maggiore di 0,
* altrimenti il controllo di programmazione difensiva, terminera' il
* programma anticipatamente.
*/
void modificaPacco()
{

  int cod = 0;
  int i = 0;
  char destinazioneNuova[MAXDESTINAZIONE];

  if (MAXDESTINAZIONE <= 0)
  {
    printf("Destinazione non acquisibile.\nUscita in corso...\n");
    exit(EXIT_FAILURE);
  }

  apriFile("Totale.txt", "r");
  leggiFile();
  chiudiFile();

  printf("Inserire codice: \n");
  scanf("%d", &cod);
  i = selezionaCodice(cod);

  printf("Inserire nuova Destinazione \n");
  scanf("%s", destinazioneNuova);
  setDestinazione(i, destinazioneNuova);
  stampaPacchi(MAXPACCHITOTALI);

  apriFile("Modificato.txt", "w");
  scritturaPacchi(MAXPACCHITOTALI);
  chiudiFile();
}
