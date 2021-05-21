#include "gestione_dati.h"

/**
* @file main.c
*
* Contiene prototipi e implementazione delle funzioni di dominio.
*
* In particolare il file contiene dichiarazione e definizione delle funzioni di
* acquisizione dei dati di pacchi postali dal file, della selezione di  determinati pacchi postali, dell'aggiornamento dei pacchi,
* della modifica della destinazione di un pacco postale.
*
* @date 05/02/2021
* @author Nicolas Visci
*
* @bug Nessun bug da segnalare
* @warning Tutte le possibilita' di crash sono stati previsti, e risolti.
*/

void acquisizione();
void selezione();
void aggiornamento();
void modifica();

int main()
{
  int risposta = 0;

  do
  {

    menu();
    printf("Scelta: \n");
    scanf("%d", &risposta);
    switch (risposta)
    {

    case 1:
      acquisizione();
      break;
    case 2:
      selezione();
      break;
    case 3:
      aggiornamento();
      break;
    case 4:
      modifica();
      break;
    case 5:
      return 0;
      break;
    default:
      printf("Scelta errata\nUscita in corso...\n");
      exit(EXIT_FAILURE);
      break;
    }

  } while (risposta < 6);

  return 0;
}

/**
*
* La procedura si occupa di acquisire i pacchi da un file, il cui nome e' fornito
* dall'utente.
* In particolare si occupa di svolgere sul file le azioni necessarie per la lettura
* del contenuto, ovvero anche apertura, stampa dei pacchi acquisiti e chiusura.
*
* Presenta vari frammenti di codice dedicato alla programmazione difensiva, i quali
* riguardano la lunghezza definita per il nome del file, essa deve essere maggiore di 0 e controlli riguardanti
* la stringa acquisita, tra cui la terminazione del programma nel caso in cui ci siano
* problemi nell'acquisizione della stringa e anche nei casi in cui non vengano
* rispettate le post-condizioni relative alla funzione corrente.
*
* @pre La lunghezza del file, dettata dalla costante MAXFILE, deve
* essere maggiore di 0, altrimenti il controllo di programmazione difensiva, terminera' il
* programma anticipatamente.
* @post La lunghezza del nome del file non deve superare quella prevista della costante
* MAXFILE, dichiarata nel file gestione_dati.h.
* @post La parte finale (ultimi 4 caratteri) del nome del file devono contenere
* l'estensione ".txt".
*
* @warning L'esecuzione verra' interrotta in anticipo se il nome del file inserito non
* presenta le seguenti caratteristiche: stringa inserita troppo lunga rispetto a quella
* prevista oppure che
* non termina con la sottostringa ".txt". In entrambi i casi, il motivo del crash sara'
* noto all'utente.
*/

void acquisizione()
{

  char nomeFile[MAXFILE];

  if (MAXFILE <= 0)
  {

    printf("\nNome del file non acquisibile.\nUscita in corso...\n");
    exit(EXIT_FAILURE);
  }

  char *estensioneFile = NULL;

  printf("Inserire nome file (pacchi.txt): \n");
  scanf("%s", nomeFile);

  if (nomeFile == NULL)
  {

    printf("Errore nell'acquisizione del nome del file.\nUscita in corso...\n");
    free(nomeFile);
    exit(EXIT_FAILURE);
  }

  if (strlen(nomeFile) > MAXFILE - 1)
  {

    printf("Errore: nome file troppo lungo.\nUscita in corso...");
    free(nomeFile);
    exit(EXIT_FAILURE);
  }

  estensioneFile = &nomeFile[strlen(nomeFile) - 4];

  if (strcmp(estensioneFile, ".txt") != 0)
  {

    printf("Cambiare l'estensione del file in .txt\nUscita in corso...\n");
    free(estensioneFile);
    free(nomeFile);
    exit(EXIT_FAILURE);
  }

  apriFile(nomeFile, "r");
  leggiFile();
  chiudiFile();
}

/**
* La procedura si occupa di chiamare un'altra procedura che svolge  un'operazione di ricerca
* di un determinato pacco tramite relazione d'ordine, in modo tale da stampare correttamente i pacchi
* precedenti al pacco selezionato tramite la relazione d'ordine inserita.
* In particolare, apre il file pacchi.txt in modalita' lettura, legge i pacchi postali presenti sul file, chiude il file, e trova il pacco
* postale tramite l'inserimento della relazione d'ordine e stampa a video i pacchi postali precedenti al pacco postale trovato.
*
* Non sono presenti porzioni di codice dedicati alla programmazione difensiva, in
* quanto i controlli sulla relazione d'ordine sono implementati all'interno della funzione relazioneDordine().
*
* @pre Il file pacchi.txt deve essere gia' creato.
* @post Il file deve essere pieno e, in particolare,  i pacchi postali stampati a video
* devono corrispondere a quelli letti nel file pacchi.txt.
* @post I pacchi postali stampati a video relativi alla relazione d'ordine
* devono corrispondere alle richieste della funzione.
*/

void selezione()
{

  apriFile("pacchi.txt", "r");
  leggiFile();
  chiudiFile();
  relazioneDordine();
}

/**
* La procedura si occupa di chiamare un'altra procedura che svolge l'aggiornamento dei pacchi postali.
*
* Non e' presente codice dedicato alla programmazione difensiva, in quanto i controlli
* sui duplicati dei pacchi postali e sulla corretta stampa/lettura e salvataggio dei pacchi
* si trovano all'interno della funzione chiamata.
*/

void aggiornamento()
{

  aggiornamentoPacchi();
}

/**
* La procedura si occupa di chiamare un'altra procedura che svolge la modifica della destinazione di un pacco postale.
*
* Non e' presente codice dedicato alla programmazione difensiva, in quanto i controlli
* sul codice del pacco inserito e sulla corretta modifica dei pacchi postali si trovano all'interno della funzione chiamata.
*/

void modifica()
{

  modificaPacco();
}
