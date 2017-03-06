#include <menu.h>
#include <wave.h>
#include <args.h>

#define __SEPARATOR__ "\n\n------------------------------------------\n\n"

typedef struct s_env
{
    // MAIN
        bool        startedWithMenu;
        bool        startedWithCmd;
        
    //

    // MENU
        menu*       menu_;
        menu*       menu_fichier;
        menu*       menu_fichier_enregistrer;
        menu*       menu_dureetempo;
        menu*       menu_canaux;
        menu*       menu_hauteur;
    //

    // OPTIONS
        option_t*   options_;
    //

    // WAVE
        bool        is_loaded;
        char*       filename_in;
        char*       filename_out;
        wave_t      cur_wave;
    //
}               t_env;
static t_env env;

void ft_menu_fichier_ouvrir(void)
{
    system("clear");
    if (env.is_loaded) // wave already opened
    {

        printf("Un fichier est deja charge, souhaitez-vous le fermer (o/n)? ");
        char c1 = getchar(), c2 = getchar();
        if ((c1 != 'o' && c1 != 'O') || c2 != '\n')
        {
            printf(__SEPARATOR__);
            launchMenu(env.menu_fichier);
        }
        else
        {
            wave_delete(env.cur_wave);
            free(env.filename_in);
            env.is_loaded = false;
            ft_menu_fichier_ouvrir();
        }
        return;
    }
    printf("Entrez le nom du fichier a charger: ");
    char tmp_input[1024], i = -1;
    while (true)
    {
        if ((tmp_input[++i] = getchar()) == EOF)
        quit();
        if (tmp_input[i] == '\n' || (int)i == 1023)
        {
            tmp_input[i] = '\0';
            system("clear");
            break ;
        }
    }
    if (!(env.cur_wave = wave_load(&tmp_input[0])))
    {
        printf("Impossible de charger le fichier '%s'!%s", &tmp_input[0], __SEPARATOR__);
        launchMenu(env.menu_fichier);
    }
    else
    {
        printf("Le fichier '%s' a ete ouvert !%s", &tmp_input[0], __SEPARATOR__);
        env.is_loaded = true;
        env.filename_in = strdup(&tmp_input[0]);
    }
}

void ft_menu_fichier_enregistrer_wave8()
{
    system("clear");
    if (!env.is_loaded) // wave not opened
    {
        printf("erreur: aucun fichier ouvert"__SEPARATOR__);
        launchMenu(env.menu_fichier_enregistrer);
        return;
    }
    printf("Sous quel nom enregistrer le nouveau fichier? ");
    char tmp_input[1024], i = -1;
    while (true)
    {
        if ((tmp_input[++i] = getchar()) == EOF)
            quit();
        if (tmp_input[i] == '\n' || (int)i == 1023)
        {
            tmp_input[i] = '\0';
            system("clear");
            break ;
        }
    }
    if (wave_save(&tmp_input[0], env.cur_wave))
        printf("Fichier '%s' enregistré !"__SEPARATOR__, &tmp_input[0]);
    else
        printf("Erreur lors de l'enregistrement du fichier!"__SEPARATOR__);
}

void ft_menu_fichier_enregistrer_wave16()
{
    system("clear");
    if (!env.is_loaded) // wave not opened
    {
        printf("erreur: aucun fichier ouvert"__SEPARATOR__);
        launchMenu(env.menu_fichier_enregistrer);
        return;
    }
    printf("Sous quel nom enregistrer le nouveau fichier? ");
    char tmp_input[1024], i = -1;
    while (true)
    {
        if ((tmp_input[++i] = getchar()) == EOF)
            quit();
        if (tmp_input[i] == '\n' || (int)i == 1023)
        {
            tmp_input[i] = '\0';
            system("clear");
            break ;
        }
    }
    if (wave_save(&tmp_input[0], env.cur_wave))
        printf("Fichier '%s' enregistré !"__SEPARATOR__, &tmp_input[0]);
    else
        printf("Erreur lors de l'enregistrement du fichier!"__SEPARATOR__);
}

void ft_menu_fichier_enregistrer_wave24()
{
    system("clear");
    if (!env.is_loaded) // wave not opened
    {
        printf("erreur: aucun fichier ouvert"__SEPARATOR__);
        launchMenu(env.menu_fichier_enregistrer);
        return;
    }
    printf("Sous quel nom enregistrer le nouveau fichier? ");
    char tmp_input[1024], i = -1;
    while (true)
    {
        if ((tmp_input[++i] = getchar()) == EOF)
            quit();
        if (tmp_input[i] == '\n' || (int)i == 1023)
        {
            tmp_input[i] = '\0';
            system("clear");
            break ;
        }
    }
    if (wave_save(&tmp_input[0], env.cur_wave))
        printf("Fichier '%s' enregistré !"__SEPARATOR__, &tmp_input[0]);
    else
        printf("Erreur lors de l'enregistrement du fichier!"__SEPARATOR__);
}

void ft_menu_fichier_enregistrer_wavecust()
{
    system("clear");
    if (!env.is_loaded) // wave not opened
    {
        printf("erreur: aucun fichier ouvert"__SEPARATOR__);
        launchMenu(env.menu_fichier_enregistrer);
        return;
    }
    printf("Sous quel nom enregistrer le nouveau fichier? ");
    char tmp_input[1024], i = -1;
    while (true)
    {
        if ((tmp_input[++i] = getchar()) == EOF)
            quit();
        if (tmp_input[i] == '\n' || (int)i == 1023)
        {
            tmp_input[i] = '\0';
            system("clear");
            break ;
        }
    }
    if (wave_save(&tmp_input[0], env.cur_wave))
        printf("Fichier '%s' enregistré !"__SEPARATOR__, &tmp_input[0]);
    else
        printf("Erreur lors de l'enregistrement du fichier!"__SEPARATOR__);
}

void ft_menu_fichier_information()
{
    system("clear");
    if (!env.is_loaded) // wave not opened
    {
        printf("erreur: aucun fichier ouvert"__SEPARATOR__);
        launchMenu(env.menu_fichier);
        return;
    }
    printf("Fichier:  %s\n", env.filename_in);
    printf("Type:     %dbits %d%s %dkHz\n", env.cur_wave->precision, env.cur_wave->canaux, ((env.cur_wave->canaux == 1) ? "canal" : "canaux"), env.cur_wave->frequenceEchantillonage);
    printf("Taille:   %dko\n", env.cur_wave->tailleDesDonnees+44);
    uint32_t nbSecond = env.cur_wave->tailleDesDonnees / env.cur_wave->nbOctetParSeconde;
    printf("Duree:    %.2d:%.2d:%d", nbSecond/3600, (nbSecond-(nbSecond/3600))/60, (nbSecond-(nbSecond/3600))%60);
    printf(__SEPARATOR__);
}

void ft_menu_dureetempo_inverser()
{
    system("clear");
    if (!env.is_loaded) // wave not opened
    {
        printf("erreur: aucun fichier ouvert"__SEPARATOR__);
        launchMenu(env.menu_dureetempo);
        return;
    }
    wave_reverse(env.cur_wave);
}

void ft_menu_dureetempo_decouper()
{
    system("clear");
    if (!env.is_loaded) // wave not opened
    {
        printf("erreur: aucun fichier ouvert"__SEPARATOR__);
        launchMenu(env.menu_dureetempo);
        return;
    }
    printf("A partir de quelle seconde vouslez-vous decouper? ");
    char tmp_input[1024], i = -1;
    while (true)
    {
        if ((tmp_input[++i] = getchar()) == EOF)
            quit();
        if (tmp_input[i] == '\n' || (int)i == 1023)
        {
            tmp_input[i] = '\0';
            system("clear");
            break ;
        }
    }
    printf("Pour quelle duree? ");
    char tmp_input2[1024];
    i = -1;
    while (true)
    {
        if ((tmp_input2[++i] = getchar()) == EOF)
            quit();
        if (tmp_input2[i] == '\n' || (int)i == 1023)
        {
            tmp_input2[i] = '\0';
            system("clear");
            break ;
        }
    }
}

void ft_menu_dureetempo_redimensionner()
{
    system("clear");
    if (!env.is_loaded) // wave not opened
    {
        printf("erreur: aucun fichier ouvert"__SEPARATOR__);
        launchMenu(env.menu_dureetempo);
        return;
    }
    printf("Quel ratio? ");
    char tmp_input[1024], i = -1;
    while (true)
    {
        if ((tmp_input[++i] = getchar()) == EOF)
            quit();
        if (tmp_input[i] == '\n' || (int)i == 1023)
        {
            tmp_input[i] = '\0';
            if (!atof(&tmp_input[0]))
            {
                printf("valeur incorrecte... quel ratio? ");
                i = -1;
            }
            else
            {
                system("clear");
                break ;
            }
        }
    }
    wave_t w = wave_scale(env.cur_wave, atof(&tmp_input[0]));
    env.cur_wave->nbOctetParSeconde = w->nbOctetParSeconde;
    wave_delete(w);
}

void ft_menu_canaux_split()
{
    system("clear");
    if (!env.is_loaded) // wave not opened
    {
        printf("erreur: aucun fichier ouvert"__SEPARATOR__);
        launchMenu(env.menu_canaux);
        return;
    }
    uint16_t can = env.cur_wave->canaux;
    env.cur_wave->canaux = 0;
    env.cur_wave = wave_split(env.cur_wave, 0);
    env.cur_wave->canaux = can;
}

void ft_menu_canaux_merge()
{
    system("clear");
    if (!env.is_loaded) // wave not opened
    {
        printf("erreur: aucun fichier ouvert"__SEPARATOR__);
        launchMenu(env.menu_canaux);
        return;
    }
    uint16_t can = env.cur_wave->canaux;
    env.cur_wave->canaux = 0;
    env.cur_wave = wave_merge(env.cur_wave, 0);
    env.cur_wave->canaux = can;
}

void ft_menu_hauteur_augmenter()
{
    system("clear");
    if (!env.is_loaded) // wave not opened
    {
        printf("erreur: aucun fichier ouvert"__SEPARATOR__);
        launchMenu(env.menu_hauteur);
        return;
    }
    if (!env.is_loaded)
        wave_set(env.cur_wave, 1, 1, env.cur_wave->canaux);
}

void ft_menu_hauteur_diminuer()
{
    system("clear");
    if (!env.is_loaded) // wave not opened
    {
        printf("erreur: aucun fichier ouvert"__SEPARATOR__);
        launchMenu(env.menu_hauteur);
        return;
    }
    if (!env.is_loaded)
        wave_set(env.cur_wave, -1, -1, env.cur_wave->canaux);
}

void createWaveMenu()
{
    env.startedWithMenu = true;
    env.menu_ = createMenu("Menu:");
        env.menu_fichier = createMenu("Fichier");
        addSubMenu(env.menu_, env.menu_fichier);
            addMenuAction(env.menu_fichier, "Ouvrir", ft_menu_fichier_ouvrir);
            env.menu_fichier_enregistrer = createMenu("Enregistrer");
            addSubMenu(env.menu_fichier, env.menu_fichier_enregistrer);
                addMenuAction(env.menu_fichier_enregistrer, "WAVE 8bits Mono 11.025kHz", ft_menu_fichier_enregistrer_wave8);
                addMenuAction(env.menu_fichier_enregistrer, "WAVE 16bits Stereo 44,1kHz", ft_menu_fichier_enregistrer_wave16);
                addMenuAction(env.menu_fichier_enregistrer, "WAVE 24bits 5.1 192kHz", ft_menu_fichier_enregistrer_wave24);
                // addMenuAction(env.menu_fichier_enregistrer, "WAVE customise", ft_menu_fichier_enregistrer_wavecust);
            addMenuAction(env.menu_fichier, "Information", ft_menu_fichier_information);
        env.menu_dureetempo = createMenu("Durée et tempo");
        addSubMenu(env.menu_, env.menu_dureetempo);
            addMenuAction(env.menu_dureetempo, "Inverser", ft_menu_dureetempo_inverser);
            addMenuAction(env.menu_dureetempo, "Decouper", ft_menu_dureetempo_decouper);
            addMenuAction(env.menu_dureetempo, "Redimensionner", ft_menu_dureetempo_redimensionner);
        env.menu_canaux = createMenu("Canaux");
        addSubMenu(env.menu_, env.menu_canaux);
            addMenuAction(env.menu_canaux, "Split", ft_menu_canaux_split);
            addMenuAction(env.menu_canaux, "Merge", ft_menu_canaux_merge);
        env.menu_hauteur = createMenu("Hauteur");
        addSubMenu(env.menu_, env.menu_hauteur);
            addMenuAction(env.menu_hauteur, "Augmenter", ft_menu_hauteur_augmenter);
            addMenuAction(env.menu_hauteur, "Diminuer", ft_menu_hauteur_diminuer);
}

void check_cli(int ac, char**av)
{
    for (int i = 1; i < ac; ++i)
    {
        if (strcmp(av[i], "-m")
        && strcmp(av[i], "-d")
        && strcmp(av[i], "-s")
        && strcmp(av[i], "-i"))
        {
            printf(
                "option '%s' inconnue\n"
                "usage: ./app.exe [options]\n"
                "\n"
                "-m nomfichier:   exporter au format WAVE 8bits Mono 11.025kHz\n"
                "-d nomfichier:   exporter au format WAVE 16bits Stereo 44,1kHz\n"
                "-s nomfichier:   exporter au format WAVE 24bits 5.1 192kHz\n"
                "-i:              informations sur le fichier\n"
                , av[i]);
            exit(1);
        }
        else if (++i == ac)
        {
            printf("missing argument for option '%s'\n", av[i-1]);
            exit(1);
        }
    }
}

void ft_cmd_m(const char *arg)
{
    if (!(env.cur_wave = wave_load(arg)))
    {
        printf("Impossible de charger le fichier '%s'!\n", arg);
        exit(1);
    }
    env.is_loaded = true;
    env.filename_in = strdup(arg);

    char *s = malloc(sizeof(char)*(strlen(env.filename_in)+2));
    strcat(s,env.filename_in);
    strcat(s,"2");
    s[strlen(env.filename_in)+1] = '\0';
    if (wave_save(s, env.cur_wave))
        printf("Fichier enregistré !\n");
    else
        printf("Erreur lors de l'enregistrement du fichier!\n");

    wave_delete(env.cur_wave);
    free(env.filename_in);
    env.is_loaded = false;
}

void ft_cmd_d(const char *arg)
{
    if (!(env.cur_wave = wave_load(arg)))
    {
        printf("Impossible de charger le fichier '%s'!\n", arg);
        exit(1);
    }
    env.is_loaded = true;
    env.filename_in = strdup(arg);

    char *s = malloc(sizeof(char)*(strlen(env.filename_in)+2));
    strcat(s,env.filename_in);
    strcat(s,"2");
    s[strlen(env.filename_in)+1] = '\0';
    if (wave_save(s, env.cur_wave))
        printf("Fichier enregistré !\n");
    else
        printf("Erreur lors de l'enregistrement du fichier!\n");

    wave_delete(env.cur_wave);
    free(env.filename_in);
    env.is_loaded = false;
}

void ft_cmd_s(const char *arg)
{
    if (!(env.cur_wave = wave_load(arg)))
    {
        printf("Impossible de charger le fichier '%s'!\n", arg);
        exit(1);
    }
    env.is_loaded = true;
    env.filename_in = strdup(arg);

    char *s = malloc(sizeof(char)*(strlen(env.filename_in)+2));
    strcat(s,env.filename_in);
    strcat(s,"2");
    s[strlen(env.filename_in)+1] = '\0';
    if (wave_save(s, env.cur_wave))
        printf("Fichier enregistré !\n");
    else
        printf("Erreur lors de l'enregistrement du fichier!\n");

    wave_delete(env.cur_wave);
    free(env.filename_in);
    env.is_loaded = false;
}

void ft_cmd_i(const char *arg)
{
    if (!(env.cur_wave = wave_load(arg)))
    {
        printf("Impossible de charger le fichier '%s'!\n", arg);
        exit(1);
    }
    env.is_loaded = true;
    env.filename_in = strdup(arg);

    printf("Fichier:  %s\n", env.filename_in);
    printf("Type:     %dbits %d%s %dkHz\n", env.cur_wave->precision, env.cur_wave->canaux, ((env.cur_wave->canaux == 1) ? "canal" : "canaux"), env.cur_wave->frequenceEchantillonage);
    printf("Taille:   %dko\n", env.cur_wave->tailleDesDonnees+44);
    uint32_t nbSecond = env.cur_wave->tailleDesDonnees / env.cur_wave->nbOctetParSeconde;
    printf("Duree:    %.2d:%.2d:%d\n", nbSecond/3600, (nbSecond-(nbSecond/3600))/60, (nbSecond-(nbSecond/3600))%60);

    wave_delete(env.cur_wave);
    free(env.filename_in);
    env.is_loaded = false;
}

void createWaveArgs()
{
    env.startedWithCmd = true;
    
    env.options_ = opt_str(env.options_, "-m", ft_cmd_m); 
    env.options_ = opt_str(env.options_, "-d", ft_cmd_d); 
    env.options_ = opt_str(env.options_, "-s", ft_cmd_s); 
    env.options_ = opt_str(env.options_, "-i", ft_cmd_i); 
}

int main(int ac, char **av)
{
    bzero(&env, sizeof(env));

    if (ac == 1)
    {
        createWaveMenu();
        system("clear");
        while (true)
            launchMenu(env.menu_);
    }
    else
    {
        check_cli(ac, av);
        createWaveArgs();
        process_arguments(env.options_, ac, av);
    }
    
    return (0);
}

