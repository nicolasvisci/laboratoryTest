#include "gestione_file.h"

void apriFile(char *nomeFile, char *mode)
{

    ptr = fopen(nomeFile, mode);
    if (ptr == NULL)
    {
        printf("Errore durante l'apertura del file...\nUscita in corso...\n");
        exit(EXIT_FAILURE);
    }
}

void leggiFile()
{

    int j;

    while (!feof(ptr))
    {

        int codice;
        char corriere[MAXCORRIERE];
        char destinazione[MAXDESTINAZIONE];
        char tipologia[MAXTIPOLOGIA];
        int peso;

        int i;
        char h;

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

void chiudiFile()
{

    fclose(ptr);
}

void scritturaSuFile(int i)
{

    fprintf(ptr, "%d$%s$%s$%s$%d\n", getCodice(i), getCorriere(i), getDestinazione(i), getTipologia(i), getPeso(i));
}

void scritturaPacchi(int nPacchi)
{

    for (int i = 0; i < nPacchi; i++)
    {

        scritturaSuFile(i);
    }
}
