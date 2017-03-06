#ifndef __MENU_H__
#define __MENU_H__
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
 
// STRUCTS
  typedef struct
  {
    char *nom;
    void (*f) ();
  } action;
 
  typedef enum item_kind
  {
    SubMenu_kind,
    Action_kind,
  } item_kind;
 
  typedef union item_union
  {
    struct menu* SubMenu;
    action Action;
  } item_union;
 
  typedef struct item
  {
    item_kind Kind;
    item_union Union;
  } item;
 
  struct menu 
  {
    struct menu* parent;
    char* nom;
    item items[9];
    int nbItem;
  };
  typedef struct menu menu;
//


// FUNCTIONS
  menu*   createMenu(const char* text);
  void    addMenuAction(menu* m, const char* text, void (*f)());
  void    addSubMenu(menu* m, menu* sm);
  void    deleteMenu(menu* m);
  void    viderBuffer(void);
  void    launchMenu(menu* m);
  void    quit(void);
//
 
#endif
