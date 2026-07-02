#include <gtk/gtk.h>

int count = 0;

void button_count(GtkWidget *wid, gpointer ptr)
{
	char result[30];
	count++;
	sprintf(result, "button pressed %d times",count);
	gtk_label_set_text(GTK_LABEL(ptr), result);
	
}

void clear_lbl(GtkWidget *wid, gpointer data)
{
	GtkLabel *label = GTK_LABEL(data);
	count = 0;
	gtk_label_set_text(label, "");
}

void main(int argc , char *argv[])
{
	gtk_init(&argc, &argv);
	GtkWidget *win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	GtkWidget *btn1 = gtk_button_new_with_label("count");
	GtkWidget *btn2 = gtk_button_new_with_label("clear");
	GtkWidget *lbl = gtk_label_new("counter");

	g_signal_connect(win, "delete_event", G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(btn1, "clicked", G_CALLBACK(button_count), lbl);
	g_signal_connect(btn2, "clicked", G_CALLBACK(clear_lbl), lbl);

	GtkWidget * grd = gtk_grid_new();

	gtk_grid_attach(GTK_GRID(grd), lbl, 0, 0, 1, 1);
	gtk_grid_attach(GTK_GRID(grd), btn1, 1, 0, 1, 1);
	gtk_grid_attach(GTK_GRID(grd), btn2, 0, 1, 2, 1);
	gtk_container_add(GTK_CONTAINER(win), grd);
	gtk_widget_show_all(win);
	gtk_main();
}

