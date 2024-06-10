#include <gtk/gtk.h>
#include <stdlib.h>

static int nombreMystere;
static int tentatives;

static void on_button_guess_clicked(GtkWidget *widget, gpointer data) {
    GtkEntry *entry = GTK_ENTRY(data);
    const gchar *entry_text = gtk_entry_get_text(entry);
    int guess = atoi(entry_text);
    tentatives++;

    GtkWidget *dialog;
    if (guess < nombreMystere) {
        dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "C'est plus !");
    } else if (guess > nombreMystere) {
        dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "C'est moins !");
    } else {
        dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "Bravo ! Vous avez trouvé le nombre mystère en %d tentatives !", tentatives);
    }

    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);

    if (guess == nombreMystere) {
        nombreMystere = (rand() % 100) + 1;
        tentatives = 0;
    }

    gtk_entry_set_text(entry, "");
}

static void on_window_destroy(GtkWidget *widget, gpointer data) {
    gtk_main_quit();
}

int main(int argc, char *argv[]) {
    srand(time(NULL));
    nombreMystere = (rand() % 100) + 1;
    tentatives = 0;

    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Jeu du Juste Prix");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);
    g_signal_connect(window, "destroy", G_CALLBACK(on_window_destroy), NULL);

    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window, vbox));

    GtkWidget *label = gtk_label_new("Devinez le nombre mystère (entre 1 et 100) :");
    gtk_box_pack_start(GTK_BOX(vbox), label, TRUE, TRUE, 0);

    GtkWidget *entry = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(vbox), entry, TRUE, TRUE, 0);

    GtkWidget *button_guess = gtk_button_new_with_label("Deviner");
    g_signal_connect(button_guess, "clicked", G_CALLBACK(on_button_guess_clicked), entry);
    gtk_box_pack_start(GTK_BOX(vbox), button_guess, TRUE, TRUE, 0);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}