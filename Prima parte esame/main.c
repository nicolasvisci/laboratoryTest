#include "gestione_dati.h"

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

void acquisizione()
{

   char nomeFile[MAXFILE];

   printf("Inserire nome file (pacchi.txt): \n");
   scanf("%s", nomeFile);

   apriFile(nomeFile, "r");
   leggiFile();
   chiudiFile();
}

void selezione()
{

   apriFile("pacchi.txt", "r");
   leggiFile();
   chiudiFile();
   relazioneDordine();
}

void aggiornamento()
{

   aggiornamentoPacchi();
}

void modifica()
{

   modificaPacco();
}
