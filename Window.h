#ifndef WINDOW_H
#define WINDOW_H

#include <gtk/gtk.h>
#include "Connector.h"

class	Window
{
 private:
  GtkWidget *window;
  GtkWidget *table;
  GtkWidget *button;
  GtkWidget *entryAuthor;
  GtkWidget *entrySubject;
  GtkWidget *label;
  Connector *connector;
  
 public:
  Window(int, char *[], Connector*);
  ~Window() {}
  void	add_button(char *, char*, int, int, int, int,
		   void (*)(void), gpointer);
  void	show_main_menu();
  void	show_menu1();
  void	show_menu2();
  void	show_menu3();
  void	show_menu4();
  void	show_menu5();
  void	show_author_list();
  void	show_subject_list();
};

#endif
