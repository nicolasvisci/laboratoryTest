#ifndef GESTIONE_DATI_H_INCLUDED
#define GESTIONE_DATI_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXFILE 10

#define MAXDESTINAZIONE 20
#define MAXCORRIERE 20
#define MAXTIPOLOGIA 20
#define MAXPACCHI 5
#define MAXPACCHITOTALI 10

FILE *ptr;

typedef struct
{

    int codice;
    char corriere[MAXCORRIERE];
    char destinazione[MAXDESTINAZIONE];
    char tipologia[MAXTIPOLOGIA];
    int peso;

} pacchi;

pacchi arrayPacchi[MAXPACCHI];

void setCodice(int i, int codice);
void setCorriere(int i, char *corriere);
void setDestinazione(int i, char *destinazione);
void setTipologia(int i, char *tipologia);
void setPeso(int i, int peso);

int getCodice(int i);
char *getCorriere(int i);
char *getDestinazione(int i);
char *getTipologia(int i);
int getPeso(int i);

void stampaRiga(int i);
void stampaPacchi(int nPacchi);

int controlloPeso(char *peso);
int selezionaCodice(int codice);
void controlloDuplicati();

#endif // GESTIONE_DATI_H_INCLUDED
