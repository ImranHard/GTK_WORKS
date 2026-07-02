#include <gtk/gtk.h>

void main(int argc, char *argv[])
{
	gtk_init(&argc, &argv);

	GtkWidget *win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	// connecting the signal to the close icon of the win
	g_signal_connect(win,"delete_event", G_CALLBACK(gtk_main_quit),NULL);
	GtkWidget *btn = gtk_button_new_with_label("close");

	g_signal_connect(btn,"clicked", G_CALLBACK(gtk_main_quit),NULL);

	gtk_container_add(GTK_CONTAINER (win), btn);
	gtk_widget_show_all(win);
	gtk_main();
}
