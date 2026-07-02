#include <gtk/gtk.h>

int main(int argc, char *argv[])
{
	gtk_init(&argc, &argv);
	GtkWidget *win1 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	GtkWidget *win2 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_show(win1);
	gtk_widget_show(win2);
	gtk_main();

	return 0;
}
