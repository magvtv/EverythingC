// MAGUTU PH NYARANGO

#include <gtk/gtk.h>

static void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

int main(int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *drawing_area;
    GtkWidget *vbox;
    GtkWidget *hbox;

    gtk_init(&argc, &argv);

    // Create the main window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "CPU Usage Graph");
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);

    // Create a drawing area for the chart
    drawing_area = gtk_drawing_area_new();
    gtk_widget_set_size_request(drawing_area, 400, 200);

    // Create a VBox to contain the drawing area
    vbox = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(window), vbox);
    gtk_box_pack_start(GTK_BOX(vbox), drawing_area, TRUE, TRUE, 0);

    // Create a HBox for controls (not implemented here)
    hbox = gtk_hbox_new(FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

    // Signal handlers (not implemented here)
    // Connect drawing area to expose event handler for drawing the chart

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
