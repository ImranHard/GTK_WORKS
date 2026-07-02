# include <gtk/gtk.h>


int main(int argc, char *argv[])
{
	gtk_init(&argc, &argv);

	GtkWidget *win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	GtkWidget *btn1 = gtk_button_new_with_label("close");
	GtkWidget *btn2 = gtk_button_new_with_label("change");

	gtk_container_add(GTK_CONTAINER (win), btn1);
	gtk_container_add(GTK_CONTAINER (win), btn2);

	gtk_widget_show_all(win);

	gtk_main();
}
