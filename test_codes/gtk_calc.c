#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>

//creating global variable to calculate two numbers at a time
int first_num = 0;
int second_num = 0;
char operation;

// creating a function to handle printing or displaying of text.
void number_display(GtkWidget *button, gpointer data)
{
	GtkLabel *label = GTK_LABEL(data);

	const char *current = gtk_label_get_text(label);// the new added code to the function


	const char *digit = gtk_button_get_label(GTK_BUTTON(button));

	char result[100];
	sprintf(result, "%s%s",current, digit);

	gtk_label_set_text(label, result);
}

// creating a function to handle the operation i.e + or -
void operator_clicked(GtkWidget *button, gpointer data)
{
	GtkLabel *label = GTK_LABEL(data);
	const char *text = gtk_label_get_text(label);

	first_num = atoi(text);

	operation = gtk_button_get_label(GTK_BUTTON(button))[0];
	gtk_label_set_text(label, "");
}

// creating the equals to function
void equal_clicked(GtkWidget *button, gpointer data)
{
	GtkLabel *label = GTK_LABEL(data);

	const char *text = gtk_label_get_text(label);
	second_num = atoi(text);
	
	int result = 0;

	switch(operation)
	{
		case '+':
			result = first_num + second_num;
			break;

		case '-':
			result = first_num - second_num;
			break;
		case '*':
			result = first_num * second_num;
			break;
		case '/':
			result = first_num / second_num;
			break;
	}

	char answer[20];
	sprintf(answer, "%d", result);

	gtk_label_set_text(label, answer);
}

void clear_lbl(GtkWidget *wid, gpointer ptr)
{
	GtkLabel *label = GTK_LABEL(ptr);
	gtk_label_set_text(label,"" );
}

void main(int argc, char *argv[])
{
	gtk_init(&argc, &argv);

	GtkWidget *win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	GtkWidget *lbl = gtk_label_new("");


	GtkWidget *btn1 = gtk_button_new_with_label("1");
	GtkWidget *btn2 = gtk_button_new_with_label("2");
	GtkWidget *btn3 = gtk_button_new_with_label("3");
	GtkWidget *btn4 = gtk_button_new_with_label("4");
	GtkWidget *btn5 = gtk_button_new_with_label("5");
	GtkWidget *btn6 = gtk_button_new_with_label("6");
	GtkWidget *btn7 = gtk_button_new_with_label("7");
	GtkWidget *btn8 = gtk_button_new_with_label("8");
	GtkWidget *btn9 = gtk_button_new_with_label("9");
	GtkWidget *btn0 = gtk_button_new_with_label("0");
	GtkWidget *btn10 = gtk_button_new_with_label("+");
	GtkWidget *btn11 = gtk_button_new_with_label("-");
	GtkWidget *btn12 = gtk_button_new_with_label("=");
	GtkWidget *btn13 = gtk_button_new_with_label("/");
	GtkWidget *btn14 = gtk_button_new_with_label("*");
	GtkWidget *btn15 = gtk_button_new_with_label("clear");

	g_signal_connect(btn1, "clicked", G_CALLBACK(number_display), lbl);
	g_signal_connect(btn2, "clicked", G_CALLBACK(number_display), lbl);
	g_signal_connect(btn3, "clicked", G_CALLBACK(number_display), lbl);
	g_signal_connect(btn4, "clicked", G_CALLBACK(number_display), lbl);
	g_signal_connect(btn5, "clicked", G_CALLBACK(number_display), lbl);
	g_signal_connect(btn6, "clicked", G_CALLBACK(number_display), lbl);
	g_signal_connect(btn7, "clicked", G_CALLBACK(number_display), lbl);
	g_signal_connect(btn8, "clicked", G_CALLBACK(number_display), lbl);
	g_signal_connect(btn9, "clicked", G_CALLBACK(number_display), lbl);
	g_signal_connect(btn0, "clicked", G_CALLBACK(number_display), lbl);
	g_signal_connect(btn10, "clicked", G_CALLBACK(number_display), lbl);
	// conectiong another function to the same button so as to both display and evaluate
	 g_signal_connect(btn10, "clicked", G_CALLBACK(operator_clicked), lbl);
	// will also do the same for the - button
	g_signal_connect(btn11, "clicked", G_CALLBACK(number_display), lbl);
	g_signal_connect(btn11, "clicked", G_CALLBACK(operator_clicked), lbl);
	g_signal_connect(btn12, "clicked", G_CALLBACK(equal_clicked), lbl);
	g_signal_connect(btn13, "clicked", G_CALLBACK(operator_clicked), lbl);
	g_signal_connect(btn14, "clicked", G_CALLBACK(operator_clicked), lbl);
	g_signal_connect(btn15, "clicked", G_CALLBACK(clear_lbl), lbl);

	GtkWidget *box2 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
	gtk_box_pack_start(GTK_BOX(box2), btn1, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(box2), btn4, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(box2), btn7, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(box2), btn15, TRUE, TRUE, 0);

	GtkWidget *box3 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
	gtk_box_pack_start(GTK_BOX(box3), btn2, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(box3), btn5, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(box3), btn8, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(box3), btn0, TRUE, TRUE, 0);

	GtkWidget *box4 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
	gtk_box_pack_start(GTK_BOX(box4), btn3, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(box4), btn6, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(box4), btn9, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(box4), btn12, TRUE, TRUE, 0);

	GtkWidget *box5 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
	gtk_box_pack_start(GTK_BOX(box5), btn10, TRUE, TRUE, 5);
	gtk_box_pack_start(GTK_BOX(box5), btn11, TRUE, TRUE, 5);
	gtk_box_pack_start(GTK_BOX(box5), btn14, TRUE, TRUE, 5);
	gtk_box_pack_start(GTK_BOX(box5), btn13, TRUE, TRUE, 5);

	GtkWidget *box6 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
	gtk_box_pack_start(GTK_BOX(box6), box2, TRUE, TRUE, 5);
	gtk_box_pack_start(GTK_BOX(box6), box3, TRUE, TRUE, 5);
	gtk_box_pack_start(GTK_BOX(box6), box4, TRUE, TRUE, 5);
	gtk_box_pack_start(GTK_BOX(box6), box5, TRUE, TRUE, 5);

	GtkWidget *box7 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
	gtk_box_pack_start(GTK_BOX(box7), lbl, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(box7), box6, TRUE, TRUE, 0);

	g_signal_connect(win, "delete_event", G_CALLBACK(gtk_main_quit), NULL);
	gtk_container_add(GTK_CONTAINER(win), box7);
	gtk_widget_show_all(win);
	gtk_main();
}
