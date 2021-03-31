#include "gestione_dati.h"

void setCodice(int i, int codice)
{

  arrayPacchi[i].codice = codice;
}

void setCorriere(int i, char *corriere)
{

  strcpy(arrayPacchi[i].corriere, corriere);
}

void setDestinazione(int i, char *destinazione)
{

  strcpy(arrayPacchi[i].destinazione, destinazione);
}

void setTipologia(int i, char *tipologia)
{

  strcpy(arrayPacchi[i].tipologia, tipologia);
}

void setPeso(int i, int peso)
{

  arrayPacchi[i].peso = peso;
}

int getCodice(int i)
{

  return arrayPacchi[i].codice;
}

char *getCorriere(int i)
{

  return arrayPacchi[i].corriere;
}

char *getDestinazione(int i)
{

  return arrayPacchi[i].destinazione;
}

char *getTipologia(int i)
{

  return arrayPacchi[i].tipologia;
}

int getPeso(int i)
{

  return arrayPacchi[i].peso;
}

void stampaRiga(int i)
{

  printf("%d %s %s %s %d\n", getCodice(i), getCorriere(i), getDestinazione(i), getTipologia(i), getPeso(i));
}

void stampaPacchi(int nPacchi)
{

  for (int i = 0; i < nPacchi; i++)
  {

    printf("%d %s %s %s %d\n", getCodice(i), getCorriere(i), getDestinazione(i), getTipologia(i), getPeso(i));
  }
}

int controlloPeso(char *peso)
{

  for (int i = 0; i < MAXPACCHI; i++)
  {

    if (peso == getPeso(i))
    {
      return 0;
    }
  }

  printf("Peso inserito ERRATO\n");
  exit(EXIT_FAILURE);
}

int selezionaCodice(int codice)
{

  int i;

  for (int i = 0; i < MAXPACCHITOTALI; i++)
  {

    if (codice == getCodice(i))
    {

      return i;
    }
  }

  printf("Codice non trovato\nUscita in corso...\n");
  exit(EXIT_FAILURE);
}

void controlloDuplicati()
{

  int codici[MAXPACCHI];

  for (int i = 0; i < MAXPACCHI; i++)
  {

    codici[i] = getCodice(i);

    if (codici[i] == 1 || codici[i] == 2 || codici[i] == 3 || codici[i] == 4 || codici[i] == 5)
    {

      printf("Presente duplicato\n");
      exit(EXIT_FAILURE);
    }
  }
}
