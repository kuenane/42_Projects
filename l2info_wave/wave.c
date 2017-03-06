#include <wave.h>

/*
* cree en memoire un WAVE de frequence F, de precision P, de n canaux C et d'une longueur de B blocs initialises a zero
*/
wave_t wave_new(uint32_t f, uint16_t p, uint16_t c, uint32_t B)
{   
    wave_t  s = (wave_t)malloc(sizeof(struct wave));

    if (!s)
        return (NULL);

    // Valeurs calculees
        uint16_t b = (c * p / 8);
        uint32_t r = (f * b);
        uint64_t D = (B * b);
    //

    // Suite de caracteres 'RIFF' (sur 4 octets)
        s->riff[0] = 'R';
        s->riff[1] = 'I';
        s->riff[2] = 'F';
        s->riff[3] = 'F';
    //

    // Taille S du fichier en octets moins 8 octets (sur 4 octets)
        s->taille_m8 = D + 44 - 8;
    //

    // Suite de caracteres 'WAVE' (sur 4 octets)
        s->wave[0] = 'W';
        s->wave[1] = 'A';
        s->wave[2] = 'V';
        s->wave[3] = 'E';
    //

    // Suite de caracteres 'fmt ' (sur 4 octets)
        s->fmt[0] = 'f';
        s->fmt[1] = 'm';
        s->fmt[2] = 't';
        s->fmt[3] = ' ';
    //

    // taille header, soit les 4 champs du dessus soit 16 (sur 4 octets)
        s->tailleHeader = 16;
    //

    // format audio (= toujours 1) sur 2 octets
        s->format = 1;
    //

    // nb de canaux C de 1 a 6 (sur 2 octets)
        s->canaux = c;
    //

    // frequence d'echantillonnage F (sur 4 octets)
        s->frequenceEchantillonage = f;
    //

    // nb d'octet par seconde R (sur 4 octets)
        s->nbOctetParSeconde = r;
    //

    // nb d'octet par bloc B (sur 2 octets)
        s->nbOctetParBloc = b;
    //

    // precision P des echantillons en bits (sur 2 octets)
        s->precision = p;
    //

    // suite de caracteres 'data' (sur 4 octets)
        s->data[0] = 'd';
        s->data[1] = 'a';
        s->data[2] = 't';
        s->data[3] = 'a';
    //
    
    // taille D des donnees en octets (sur 4 octets)
        s->tailleDesDonnees = D;
    //

    // les donnees...
        s->donnees = NULL;
    //

    return (s);
}

/*
* libere toute la place memoire occupee par le WAVE w
*/
void wave_delete(wave_t w)
{
    if (w)
    {
        if (w->donnees)
            free(w->donnees);
        free(w);
    }
}

/*
* retourne un entier 64b signe correspondant a l amplitude de l echantillon/bloc i sur le canal j du WAVE w
*/
int64_t wave_get(wave_t w, uint32_t i, uint16_t j)
{
    uint32_t bloc_pos = i * w->nbOctetParBloc;
    uint32_t canal_pos = j * w->precision / 8;
    uint32_t pos = bloc_pos + canal_pos;

    if (w->precision == 8)
        return (w->donnees[pos]);
    else if (w->precision == 16)
        return (w->donnees[pos] | (w->donnees[pos+1] << 8));
    else // 24
        return (w->donnees[pos] | (w->donnees[pos+1] << 8) | (w->donnees[pos+1] << 16));
}

/*
* affecte la nouvelle amplitude A a l echantillon/bloc i sur le canal j du WAVE w
*/
void wave_set(wave_t w, uint32_t i, uint16_t j, int64_t a)
{
    uint32_t bloc_pos = i * w->nbOctetParBloc;
    uint32_t canal_pos = j * w->precision / 8;
    uint32_t pos = bloc_pos + canal_pos;

    w->donnees[pos] = a;
    if (w->precision == 16)
        w->donnees[pos + 1] = a >> 8;
    if (w->precision == 24)
        w->donnees[pos + 2] = a >> 16;
}

/*
* ajoute a un WAVE existant le signal a
*/
void add_signal(wave_t w, double (*s)(double))
{
    uint32_t nbBloc = w->tailleDesDonnees / w->nbOctetParBloc;

    unsigned char tmp [w->tailleDesDonnees];

    for (uint32_t curBloc = 0; curBloc < nbBloc; ++curBloc)
    {
        tmp[curBloc] = w->donnees[curBloc];
        (void)s;
    }
}

/*
* charge un WAVE a partir du fichier de nom fname (la fonction renverra NULL en cas d echec)
*/
wave_t wave_load(const char* fname)
{
    // ouvre fichier
        FILE *f;
        if (!(f = fopen(fname, "r")))   
            return (NULL);
    //

    // lit header
        unsigned char header[44];
        bzero(&header[0], sizeof(header));
        if (fread(&header[0], 44, 1, f) != 1)
            return (NULL);
    //

    // verifie constantes
        if (header[0] != 'R'
        || header[1] != 'I'
        || header[2] != 'F'
        || header[3] != 'F'
        || header[8] != 'W'
        || header[9] != 'A'
        || header[10] != 'V'
        || header[11] != 'E'
        || header[12] != 'f'
        || header[13] != 'm'
        || header[14] != 't'
        || header[15] != ' '
        || header[36] != 'd'
        || header[37] != 'a'
        || header[38] != 't'
        || header[39] != 'a')
            return NULL;
    //

    // extrait les autres donnees du header
        uint16_t extracted_format = header[20] | (header[21] << 8);
        uint16_t extracted_canaux = header[22] | (header[23] << 8);
        uint32_t extracted_frequence = header[24] | (header[25] << 8) | (header[26] << 16) | (header[27] << 24);
        uint32_t extracted_nbOctetParSeconde = header[28] | (header[29] << 8) | (header[30] << 16) | (header[31] << 24);
        uint16_t extracted_nbOctetParBloc = header[32] | (header[33] << 8);
        uint16_t extracted_precision = header[34] | (header[35] << 8);
        uint32_t extracted_tailleDesDonnees = header[40] | (header[41] << 8) | (header[42] << 16) | (header[43] << 24);
    //

    // verifie les donnees extraites
        if (extracted_format != 1
        || extracted_canaux < 1
        || extracted_canaux > 6
        || (extracted_precision != 8 && extracted_precision != 16 && extracted_precision != 24))
            return (NULL);
    //

    // longueur de blocs pour creer la strcture
        uint32_t longueurBlocs = (extracted_tailleDesDonnees / (extracted_canaux * extracted_precision / 8));
    //

    // creer la struct wave
        wave_t w = wave_new(extracted_frequence, extracted_precision, extracted_canaux, longueurBlocs);
        if (!w)
            return (NULL);
    //

    // lit les donnees
        unsigned char donnees[extracted_tailleDesDonnees];
        if (fread(donnees, extracted_tailleDesDonnees, 1, f) != 1)
            return (NULL);
        w->donnees = (unsigned char*)malloc(extracted_tailleDesDonnees*sizeof(unsigned char));
        if (!w->donnees)
            return (NULL);
        w->donnees = memcpy(w->donnees, donnees, extracted_tailleDesDonnees);
    //

    return (w);
}

/*
* sauvegarde le WAVE w dans le fichier de nom fname (l ancien fichier est ecrase), renvoit le resultat de l operation
*/
bool wave_save(const char* fname, wave_t w)
{
    // ouvre fichier
        FILE *f;
        if (!(f = fopen(fname, "w")))
            return (false);
    //

    // preparation header
        unsigned char header[44];
        bzero(header, sizeof(header));
        // RIFF 
            header[0] = 'R';
            header[1] = 'I';
            header[2] = 'F';
            header[3] = 'F';
        //

        // Taille S du fichier en octets moins 8 octets (sur 4 octets)
            header[4] = w->taille_m8;
            header[5] = w->taille_m8 >> 8;
            header[6] = w->taille_m8 >> 16;
            header[7] = w->taille_m8 >> 24;
        //

        // Suite de caracteres 'WAVE' (sur 4 octets)
            header[8] = 'W';
            header[9] = 'A';
            header[10] = 'V';
            header[11] = 'E';
        //

        // Suite de caracteres 'fmt ' (sur 4 octets)
            header[12] = 'f';
            header[13] = 'm';
            header[14] = 't';
            header[15] = ' ';
        //

        // taille header, soit les 4 champs du dessus soit 16 (sur 4 octets)
            header[16] = w->tailleHeader;
            header[17] = w->tailleHeader >> 8;
            header[18] = w->tailleHeader >> 16;
            header[19] = w->tailleHeader >> 24;
        //

        // format audio (= toujours 1) sur 2 octets
            header[20] = w->format;
            header[21] = w->format >> 8;
        //

        // nb de canaux C de 1 a 6 (sur 2 octets)
            header[22] = w->canaux;
            header[23] = w->canaux >> 8;
        //

        // frequence d'echantillonnage F (sur 4 octets)
            header[24] = w->frequenceEchantillonage;
            header[25] = w->frequenceEchantillonage >> 8;
            header[26] = w->frequenceEchantillonage >> 16;
            header[27] = w->frequenceEchantillonage >> 24;
        //

        // nb d'octet par seconde R (sur 4 octets)
            header[28] = w->nbOctetParSeconde;
            header[29] = w->nbOctetParSeconde >> 8;
            header[30] = w->nbOctetParSeconde >> 16;
            header[31] = w->nbOctetParSeconde >> 24;
        //

        // nb d'octet par bloc B (sur 2 octets)
            header[32] = w->nbOctetParBloc;
            header[33] = w->nbOctetParBloc >> 8;
        //

        // precision P des echantillons en bits (sur 2 octets)
            header[34] = w->precision;
            header[35] = w->precision >> 8;
        //

        // suite de caracteres 'data' (sur 4 octets)
            header[36] = 'd';
            header[37] = 'a';
            header[38] = 't';
            header[39] = 'a';
        //
        
        // taille D des donnees en octets (sur 4 octets)
            header[40] = w->tailleDesDonnees;
            header[41] = w->tailleDesDonnees >> 8;
            header[42] = w->tailleDesDonnees >> 16;
            header[43] = w->tailleDesDonnees >> 24;
        //
    //

    // ecriture header
        if (fwrite(&header[0], 44, 1, f) != 1)
            return (false);
    //

    // ecriture donnees
        if (fwrite(w->donnees, w->tailleDesDonnees , 1, f) != 1)
            return (false);
    //

    return (true);
}

/*
* porte a c le nb de canaux dans le WAVE w, si c est plus petit que le nombre de canaux de w, les canaux sont fusionnes, si c est plus grand, les canaux sont dupliques
*/
void wave_canal(wave_t w, uint16_t c)
{
    if (w->canaux == c)
        return ;

    // nouvelles valeurs
        uint16_t new_canaux = c;
        uint16_t new_nbOctetParBloc = new_canaux * w->precision / 8;
        uint32_t new_nbOctetParSeconde = w->frequenceEchantillonage * new_nbOctetParBloc;
        uint32_t new_tailleDesDonnees = (c > w->canaux) ? (w->tailleDesDonnees / (c / w->canaux)) : (w->tailleDesDonnees * (w->canaux / c)) ;
        uint32_t nbBloc = new_tailleDesDonnees / new_nbOctetParBloc;
    //

    void *tmp = malloc(sizeof(unsigned char) * new_tailleDesDonnees);

    for (uint32_t curBloc = 0; curBloc < nbBloc; ++curBloc)
    {
        if (c < w->canaux)
            memcpy(&tmp[new_nbOctetParBloc*curBloc], &w->donnees[w->nbOctetParBloc*curBloc], new_nbOctetParBloc);
        else
        {
            // same octets
                memcpy(&tmp[new_nbOctetParBloc*curBloc], &w->donnees[w->nbOctetParBloc*curBloc], w->nbOctetParBloc);
            // missing octets
                memcpy(&tmp[new_nbOctetParBloc*curBloc+w->nbOctetParBloc], &w->donnees[w->nbOctetParBloc*curBloc], new_nbOctetParBloc-w->nbOctetParBloc);
        }
    }
    free(w->donnees);
    w->donnees = tmp;
    w->canaux = new_canaux;
    w->nbOctetParBloc = new_nbOctetParBloc;
    w->nbOctetParSeconde = new_nbOctetParSeconde;
    w->tailleDesDonnees = new_tailleDesDonnees;
    //
}

/*
* inverse le sens de lecture
*/
void wave_reverse(wave_t w)
{
    // nb total de blocs
        uint32_t nbBloc = w->tailleDesDonnees / w->nbOctetParBloc;
    //

    // copie les donnees existantes
        unsigned char tmp [w->tailleDesDonnees];
        memcpy(&tmp[0], w->donnees, w->tailleDesDonnees);
    //

    // recopie a nouveau les donnees a l'envers dans w
        for (uint32_t curBloc = 0; curBloc < nbBloc; ++curBloc)
        {
            memcpy(&w->donnees[w->nbOctetParBloc*(nbBloc-curBloc)], &tmp[w->nbOctetParBloc*curBloc], w->nbOctetParBloc);
        }
    //
}

/*
* separe le WAVE w en plusieurs WAVE mono
*/
wave_t wave_split(wave_t w, int* pc)
{
    for (uint16_t curCanal = 0; curCanal < w->canaux; ++curCanal)
    {
        pc[curCanal] = (int)wave_new(w->frequenceEchantillonage, w->precision, w->canaux, w->tailleDesDonnees);
    }       
    return (w);
}

/*
* fusionne au sein d un unique WAVE les c WAVE mono passes en parametres (operation inverse de wave_split)
*/
wave_t wave_merge(wave_t w, int c)
{
    for (uint16_t curCanal = 0; curCanal < w->canaux; ++curCanal)
    {
        c = (int)wave_new(w->frequenceEchantillonage, w->precision, w->canaux, w->tailleDesDonnees);
    }
    return (w);
}

/*
* cree un nouveau WAVE a partir de w contenant les length blocs pris a partir de la position start (retourne NULL en cas d erreur)
*/
wave_t wave_crop(wave_t w, uint32_t start, uint32_t length)
{
    uint32_t newSize = w->tailleDesDonnees - (start+length);

    wave_t new = wave_new(w->frequenceEchantillonage, w->precision, w->canaux, newSize);

    if (new == NULL)
        return (NULL);
    else
        return (new);
}

/*
* cree un nouveau WAVE a partir de w ayant les memes caracteristiques mais en modifiant le tempo
*/
wave_t wave_scale(wave_t w, double s)
{
    wave_t w2 = (wave_t)malloc(sizeof(struct wave));

    memcpy(w2, w, sizeof(struct wave));

    w2->nbOctetParSeconde *= s;

    return (w2);
}
