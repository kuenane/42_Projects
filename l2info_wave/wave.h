#ifndef __WAVE_H__
#define __WAVE_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
 
// struct t_wave
    struct wave
    {
        // Suite de caracteres 'RIFF' (sur 4 octets)
        char        riff[4];
 
        // Taille S du fichier en octets moins 8 octets (sur 4 octets)
        uint32_t    taille_m8;
 
        // Suite de caracteres 'WAVE' (sur 4 octets)
        char        wave[4];

        // Suite de caracteres 'fmt ' (sur 4 octets)
        char        fmt[4];

        // taille header, soit les 4 champs du dessus soit 16 (sur 4 octets)
        uint32_t    tailleHeader;

        // format audio (= toujours 1) sur 2 octets
        uint16_t    format;

        // nb de canaux C de 1 a 6 (sur 2 octets)
        uint16_t    canaux;

        // frequence d'echantillonnage F (sur 4 octets)
        uint32_t    frequenceEchantillonage;

        // nb d'octet par seconde R (sur 4 octets)
        uint32_t    nbOctetParSeconde;

        // nb d'octet par bloc B (sur 2 octets)
        uint16_t    nbOctetParBloc;

        // precision P des echantillons en bits (sur 2 octets)
        uint16_t    precision;

        // suite de caracteres 'data' (sur 4 octets)
        char        data[4];
    
        // taille D des donnees en octets (sur 4 octets)
        uint32_t    tailleDesDonnees;

        // les donnees...
        unsigned char *donnees;
    };
//

// type wave_t comme l'adresse vers une structure WAVE
    typedef struct wave* wave_t;
//

// cree en memoire un WAVE de frequence F, de precision P, de n canaux C et d'une longueur de B blocs initialises a zero
    wave_t wave_new(uint32_t f, uint16_t p, uint16_t c, uint32_t B);
//

// libere toute la place memoire occupee par le WAVE w
    void wave_delete(wave_t w);
//

// retourne un entier 64b signe correspondant a l amplitude de l echantillon/bloc i sur le canal j du WAVE w
    int64_t wave_get(wave_t w, uint32_t i, uint16_t j);
//

// affecte la nouvelle amplitude A a l echantillon/bloc i sur le canal j du WAVE w
    void wave_set(wave_t w, uint32_t i, uint16_t j, int64_t a);
//

// ajoute a un WAVE existant le signal a
    void add_signal(wave_t w, double (*s)(double));
//

// charge un WAVE a partir du fichier de nom fname (la fonction renverra NULL en cas d echec)
    wave_t wave_load(const char* fname);
//

// sauvegarde le WAVE w dans le fichier de nom fname (l ancien fichier est ecrase), renvoit le resultat de l operation
    bool wave_save(const char* fname, wave_t w);
//

// porte a c le nb de canaux dans le WAVE w, si c est plus petit que le nombre de canaux de w, les canaux sont fusionnes, si c est plus grand, les canaux sont dupliques
    void wave_canal(wave_t w, uint16_t c);
//

// inverse le sens de lecture
    void wave_reverse(wave_t w);
//

// separe le WAVE w en plusieurs WAVE mono
    wave_t wave_split(wave_t w, int* pc);
//

// fusionne au sein d un unique WAVE les c WAVE mono passes en parametres (operation inverse de wave_split)
    wave_t wave_merge(wave_t w, int c);
//

// cree un nouveau WAVE a partir de w contenant les length blocs pris a partir de la position start (retourne NULL en cas d erreur)
    wave_t wave_crop(wave_t w, uint32_t start, uint32_t length);
//

// cree un nouveau WAVE a partir de w ayant les memes caracteristiques mais en modifiant le tempo
    wave_t wave_scale(wave_t w, double s);
//

#endif
