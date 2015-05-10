#include "Window.h"

static void callback( GtkWidget *widget, gpointer data)
{
  g_print("Hello World, %s was pressed\n", (char*) data);
}

static gboolean delete_event(GtkWidget *widget,
			     GdkEvent  *event,
			     gpointer data )
{
  gtk_main_quit ();
  return FALSE;
}

void	Window::add_button(char *name, char *event,
			   int left, int right, int top, int bottom,
			   void (*func)(void), gpointer data)
{
  button = gtk_button_new_with_label(name);
  g_signal_connect(button, event, func, data);
  gtk_table_attach_defaults(GTK_TABLE(table), button, left, right, top, bottom);
  gtk_widget_show(button);
}

void	Window::show_main_menu()
{
  table = gtk_table_new(6, 1, TRUE);
  gtk_container_add(GTK_CONTAINER(window), table);
  add_button("Checkout or return book", "clicked", 0, 1, 0, 1,
	     G_CALLBACK(callback), (gpointer) "button1");
  add_button("Add or remove book", "clicked", 0, 1, 1, 2,
	     G_CALLBACK(callback), (gpointer) "button2");
  add_button("Get list of books by author/subject", "clicked", 0, 1, 2, 3,
	     G_CALLBACK(callback), (gpointer) "button3");
  add_button("Find list of books checked out", "clicked", 0, 1, 3, 4,
	     G_CALLBACK(callback), (gpointer) "button4");
  add_button("Find who last checked out book", "clicked", 0, 1, 4, 5,
	     G_CALLBACK(callback), (gpointer) "button5");
  add_button("Quit", "clicked", 0, 1, 5, 6,
	     G_CALLBACK(delete_event), NULL);
  gtk_widget_show(table);
}

Window::Window(int argc, char *argv[])
{
  gtk_init (&argc, &argv);  
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window), "Library");
  g_signal_connect (window, "delete-event",
		    G_CALLBACK (delete_event), NULL);
  gtk_container_set_border_width(GTK_CONTAINER(window), 20);
  show_main_menu();
  gtk_widget_show(window);
  gtk_main ();
}

