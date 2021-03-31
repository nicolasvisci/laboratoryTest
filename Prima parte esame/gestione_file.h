#ifndef GESTIONE_FILE_H_INCLUDED
#define GESTIONE_FILE_H_INCLUDED

#include "gestione_dati.h"

void apriFile(char *nomeFile, char *mode);
void leggiFile();
void chiudiFile();
void scriviRigaFile();
void scritturaSuFile(int i);

void scritturaPacchi(int nPacchi);

#endif // GESTIONE_FILE_H_INCLUDED
