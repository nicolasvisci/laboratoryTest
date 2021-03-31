#include "funzioni.h"

void menu()
{

  printf("1.Acquisizione\n2.Selezione\n3.Aggiornamento\n4.Modifica\n5.Esci\n");
}

void relazioneDordine()
{

  char tipologiaPacco[MAXTIPOLOGIA];
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
    compareTipologia = strcmp(tipologiaPacco, getTipologia(i));
    comparePeso = controlloPeso(pesoPacco);
    if (compareTipologia == 0 && comparePeso == 0)
    {
      for (j = i - 1; j > -1; j--)
      {
        stampaRiga(j);
        scritturaSuFile(j);
      }
    }
  }

  if (comparePeso != 0 && compareTipologia != 0)
  {

    printf("Dati inseriti non validi...\n");
  }

  chiudiFile();
}

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

void modificaPacco()
{

  int cod = 0;
  int i = 0;
  char destinazioneNuova[MAXDESTINAZIONE];

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
