#ifndef WINDOW_H
#define WINDOW_H

#include <gtk/gtk.h>

class	Window
{
 private:
  GtkWidget *window;
  GtkWidget *table;
  GtkWidget *button;

 public:
  Window(int, char *argv[]);
  ~Window() {}
  void	show_main_menu();
  void	add_button(char *, char*, int, int, int, int,
		   void (*)(void), gpointer);

};

#endif
