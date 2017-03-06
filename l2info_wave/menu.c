#include <menu.h>

menu* createMenu(const char* text)
{
  menu* m = (menu*) malloc(sizeof(menu));
  m->parent = NULL;
  m->nom = malloc(strlen(text + 1) * sizeof(char));
  strcpy(m->nom, text);
  m->nbItem = 0;
  return m;
}

void addMenuAction(menu* m, const char* text, void (*f)())
{
    m->items[m->nbItem].Kind = Action_kind;
    m->items[m->nbItem].Union.Action.nom = malloc(strlen(text + 1) * sizeof(char));
    strcpy(m->items[m->nbItem].Union.Action.nom, text);
    m->items[m->nbItem].Union.Action.f = f;
    m->nbItem++;
}

void addSubMenu(menu* m, menu* sm)
{
  if(sm->parent == NULL){   
    sm->parent = m;
    m->items[m->nbItem].Kind = SubMenu_kind;
    m->items[m->nbItem].Union.SubMenu = sm;
    m->nbItem++;
  }
}

void deleteMenu(menu* m)
{
  if(m->parent == NULL)
    free(m);  
}

void viderBuffer()
{
  char c = getchar();
  while (c != '\n' && c != EOF)
    c = getchar();
}

void launchMenu(menu* m)
{
  // print menu name
    printf("%s\n\n", m->nom);
  //
  
  // print choices
    for (int i = 1; i <= m->nbItem; ++i)
    {
        if (m->items[i-1].Kind == SubMenu_kind)
        printf("%d - %s\n\n", i, m->items[i-1].Union.SubMenu->nom);
        else // Action_kind
        printf("%d - %s\n\n", i, m->items[i-1].Union.Action.nom);
    }
  //

  // get choice
    char c;
    while (true)
    {
        printf("\n\n(R) Retour / (Q) Quitter\n\nChoix ? ");
        if ((c = getchar()) == EOF)
          quit();
        viderBuffer();
        if (c == 'q' || c == 'Q')
            quit();
        if (c != 'R' && c != 'r')
            c -= '1'; // ascii number to char + -1 for direct index access
        if ((c >= 0 && c < m->nbItem) || c == 'r' || c == 'R')
            break;
        system("clear");
        launchMenu(m);
        return ;
    }
    system("clear");
    if (c == 'r' || c == 'R')
    {
        if (m->parent)
            launchMenu(m->parent);
    }
    else if (m->items[c].Kind == Action_kind)
        m->items[c].Union.Action.f();
    else
        launchMenu(m->items[c].Union.SubMenu); 
}
 
void quit()
{
  exit(0);
}
