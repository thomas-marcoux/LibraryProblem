#include "Window.h"

static gboolean delete_event(GtkWidget *widget,
			     GdkEvent  *event,
			     gpointer data )
{
  gtk_main_quit ();
  return FALSE;
}

static void	openMenu1(GtkWidget *widget, gpointer data)
{
  ((Window*)data)->show_menu1();
}

static void	openMenu2(GtkWidget *widget, gpointer data)
{
  ((Window*)data)->show_menu2();
}

static void	openMenu3(GtkWidget *widget, gpointer data)
{
  ((Window*)data)->show_menu3();
}

static void	openMenu4(GtkWidget *widget, gpointer data)
{
  ((Window*)data)->show_menu4();
}

static void	openMenu5(GtkWidget *widget, gpointer data)
{
  ((Window*)data)->show_menu5();
}

static void	openMainMenu(GtkWidget *widget, gpointer data)
{
  ((Window*)data)->show_main_menu();
}

static void	openAuthorList(GtkWidget *widget, gpointer data)
{
  ((Window*)data)->show_author_list();
}

static void	openSubjectList(GtkWidget *widget, gpointer data)
{
  ((Window*)data)->show_subject_list();
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

void	Window::show_menu1()
{
  gtk_container_remove(GTK_CONTAINER(window), table);
  table = gtk_table_new(3, 1, TRUE);
  gtk_container_add(GTK_CONTAINER(window), table);
  add_button("Back", "clicked", 0, 1, 1, 2,
	     G_CALLBACK(openMainMenu), (gpointer)this);
  add_button("Quit", "clicked", 0, 1, 2, 3,
	     G_CALLBACK(delete_event), NULL);
  gtk_widget_show(table);
  gtk_widget_show(window);
}

void	Window::show_menu2()
{
  gtk_container_remove(GTK_CONTAINER(window), table);
  table = gtk_table_new(3, 1, TRUE);
  gtk_container_add(GTK_CONTAINER(window), table);
  add_button("Back", "clicked", 0, 1, 1, 2,
	     G_CALLBACK(openMainMenu), (gpointer)this);
  add_button("Quit", "clicked", 0, 1, 2, 3,
	     G_CALLBACK(delete_event), NULL);
  gtk_widget_show(table);
  gtk_widget_show(window);
}

void	Window::show_menu3()
{
  gtk_container_remove(GTK_CONTAINER(window), table);
  table = gtk_table_new(4, 1, TRUE);
  gtk_container_add(GTK_CONTAINER(window), table);
  label = gtk_label_new("Author:");
  gtk_table_attach_defaults(GTK_TABLE(table), label, 0, 1, 0, 1);
  gtk_widget_show(label);
  entryAuthor = gtk_entry_new();
  g_signal_connect (entryAuthor, "activate", G_CALLBACK (openAuthorList),
		    (gpointer)this);
  gtk_table_attach_defaults(GTK_TABLE(table), entryAuthor, 0, 1, 1, 2);
  gtk_widget_show(entryAuthor);
  add_button("Back", "clicked", 0, 1, 2, 3,
	     G_CALLBACK(openMainMenu), (gpointer)this);
  add_button("Quit", "clicked", 0, 1, 3, 4,
	     G_CALLBACK(delete_event), NULL);
  gtk_widget_show(table);
  gtk_widget_show(window);
}

void	Window::show_menu4()
{
  gtk_container_remove(GTK_CONTAINER(window), table);
  table = gtk_table_new(3, 1, TRUE);
  gtk_container_add(GTK_CONTAINER(window), table);
  add_button("Back", "clicked", 0, 1, 1, 2,
	     G_CALLBACK(openMainMenu), (gpointer)this);
  add_button("Quit", "clicked", 0, 1, 2, 3,
	     G_CALLBACK(delete_event), NULL);
  gtk_widget_show(table);
  gtk_widget_show(window);
}

void	Window::show_menu5()
{
  gtk_container_remove(GTK_CONTAINER(window), table);
  table = gtk_table_new(3, 1, TRUE);
  gtk_container_add(GTK_CONTAINER(window), table);
  add_button("Back", "clicked", 0, 1, 1, 2,
	     G_CALLBACK(openMainMenu), (gpointer)this);
  add_button("Quit", "clicked", 0, 1, 2, 3,
	     G_CALLBACK(delete_event), NULL);
  gtk_widget_show(table);
  gtk_widget_show(window);
}

void	print_books(GtkWidget *table, std::vector<sql::ResultSet*> *v)
{

}

void	Window::show_author_list()
{
  const char *author;
  std::vector<sql::ResultSet*> *v;
  author = gtk_entry_get_text (GTK_ENTRY (entryAuthor));
  v = connector->getBooksFromAuthor(author);
  gtk_container_remove(GTK_CONTAINER(window), table);
  //table = gtk_table_new(v->size() + 2, 8, TRUE);
  table = gtk_table_new(3, 1, TRUE);
  gtk_container_add(GTK_CONTAINER(window), table);
  print_books(table, v);
  entrySubject = gtk_entry_new();
  gtk_entry_set_max_length(GTK_ENTRY(entrySubject), 50);
  g_signal_connect (entrySubject, "activate",
		    G_CALLBACK (openSubjectList), (gpointer)this);
  gtk_table_attach_defaults(GTK_TABLE(table), entrySubject, 0, 1, 0, 1);
  gtk_widget_show(entrySubject);
  add_button("Back", "clicked", 0, 1, 1, 2,
	     G_CALLBACK(openMainMenu), (gpointer)this);
  add_button("Quit", "clicked", 0, 1, 2, 3,
	     G_CALLBACK(delete_event), NULL);
  gtk_widget_show(table);
  gtk_widget_show(window);
}

void	Window::show_subject_list()
{
  const gchar *subject;

  subject = gtk_entry_get_text (GTK_ENTRY (entrySubject));
  printf ("Entry contents: %s\n", subject);
  gtk_container_remove(GTK_CONTAINER(window), table);
  table = gtk_table_new(3, 1, TRUE);
  gtk_container_add(GTK_CONTAINER(window), table);
  add_button("Back", "clicked", 0, 1, 1, 2,
	     G_CALLBACK(openMainMenu), (gpointer)this);
  add_button("Quit", "clicked", 0, 1, 2, 3,
	     G_CALLBACK(delete_event), NULL);
  gtk_widget_show(table);
  gtk_widget_show(window);
}

void	Window::show_main_menu()
{
  gtk_container_remove(GTK_CONTAINER(window), table);
  table = gtk_table_new(6, 1, TRUE);
  gtk_container_add(GTK_CONTAINER(window), table);
  add_button("Checkout or return book", "clicked", 0, 1, 0, 1,
	     G_CALLBACK(openMenu1), (gpointer)this);
  add_button("Add or remove book", "clicked", 0, 1, 1, 2,
	     G_CALLBACK(openMenu2), (gpointer)this);
  add_button("Get list of books by author/subject", "clicked", 0, 1, 2, 3,
	     G_CALLBACK(openMenu3), (gpointer)this);
  add_button("Find list of books checked out", "clicked", 0, 1, 3, 4,
	     G_CALLBACK(openMenu4), (gpointer)this);
  add_button("Find who last checked out book", "clicked", 0, 1, 4, 5,
	     G_CALLBACK(openMenu5), (gpointer)this);
  add_button("Quit", "clicked", 0, 1, 5, 6,
	     G_CALLBACK(delete_event), NULL);
  gtk_widget_show(table);
  gtk_widget_show(window);
}

Window::Window(int argc, char *argv[], Connector *c)
{
  connector = c;
  gtk_init (&argc, &argv);  
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window), "Library");
  g_signal_connect (window, "delete-event",
		    G_CALLBACK (delete_event), NULL);
  gtk_container_set_border_width(GTK_CONTAINER(window), 20);
  table = gtk_table_new(1, 1, TRUE);
  gtk_container_add(GTK_CONTAINER(window), table);
  show_main_menu();
  gtk_main ();
}
