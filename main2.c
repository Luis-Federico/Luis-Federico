#include <stdio.h>
#include <math.h>
#include <gtk/gtk.h>
#include <cairo.h>
#include <stdbool.h>


#define SIZE 400
#define PI 3.1416

static int width, height;

float teta;


int vortex[12][2];
int plano[16][4];
int coef,
    col;
static int o=1;

static int v=1;
static float s = 0;

static void drawed();
bool skeleton;
bool transparent;
bool mov;
bool dyed=TRUE;
float angles[8][3];
float medium[6][3];
static void drawed() {



	angles[0][0]=-.5f;
	angles[0][1]=-.5f;
	angles[0][2]=-.5f;
	angles[1][0]=-.5f;
	angles[1][1]=.5f;
	angles[1][2]=-.5f;
	angles[2][0]=.5f;
	angles[2][1]=.5f;
	angles[2][2]=-.5f;
	angles[3][0]=.5f;
	angles[3][1]=-.5f;
	angles[3][2]=-.5f;
	angles[4][0]=-.5f;
	angles[4][1]=-.5f;
	angles[4][2]=.5f;
	angles[5][0]=-.5f;
	angles[5][1]=.5f;
	angles[5][2]=.5f;
	angles[6][0]=.5f;
	angles[6][1]=.5f;
	angles[6][2]=.5f;
	angles[7][0]=.5f;
	angles[7][1]=-.5f;
	angles[7][2]=.5f;

	vortex[0][0]=0;
	vortex[0][1]=1;

	vortex[1][0]=1;
	vortex[1][1]=2;

	vortex[2][0]=2;
	vortex[2][1]=3;

	vortex[3][0]=3;
	vortex[3][1]=0;

	vortex[4][0]=4;
	vortex[4][1]=5;

	vortex[5][0]=5;
	vortex[5][1]=6;

	vortex[6][0]=6;
	vortex[6][1]=7;

	vortex[7][0]=7;
	vortex[7][1]=4;

	vortex[8][0]=0;
	vortex[8][1]=4;

	vortex[9][0]=1;
	vortex[9][1]=5;

	vortex[10][0]=2;
	vortex[10][1]=6;

	vortex[11][0]=3;
	vortex[11][1]=7;

	plano[0][0]=0;
	plano[0][1]=1;
	plano[0][2]=2;
	plano[0][3]=3;
	medium[0][0]=0;
	medium[0][1]=0;
	medium[0][2]=-.5f;

	plano[1][0]=4;
	plano[1][1]=5;
	plano[1][2]=6;
	plano[1][3]=7;
    medium[1][0]=0;
	medium[1][1]=0;
	medium[1][2]=.5f;

	plano[2][0]=10;
	plano[2][1]=11;
	plano[2][2]=6;
	plano[2][3]=2;
	medium[2][0]=.5f;
	medium[2][1]=0;
	medium[2][2]=0;

	plano[3][0]=8;
	plano[3][1]=9;
	plano[3][2]=0;
	plano[3][3]=4;
	medium[3][0]=-.5f;
	medium[3][1]=0;
	medium[3][2]=0;

	plano[4][0]=9;
	plano[4][1]=10;
	plano[4][2]=1;
	plano[4][3]=5;
	medium[4][0]=0;
    medium[4][1]=.5f;
    medium[4][2]=0;

	plano[5][0]=8;
	plano[5][1]=11;
	plano[5][2]=7;
	plano[5][3]=3;
	medium[5][0]=0;
	medium[5][1]=-.5f;
	medium[5][2]=0;


}

void on_button_click(GtkWidget *widget, const gpointer *data) {
	if ( GPOINTER_TO_INT(data) == 1)
	{
		o=1;
		mov=TRUE;
	}
	if (GPOINTER_TO_INT(data) == 2)
	{
		o=2;
		mov=TRUE;
	}
	if (GPOINTER_TO_INT(data) == 3)
	{
		o=3;
		mov=TRUE;
	}
	if (GPOINTER_TO_INT(data) == 4)
	{

		switch (v)
		{
			case -1:
				s=0;
			break;
			case 0:
				s=1;
			break;
			case 1:
				s=-1;
			break;
			default:
				break;
		}
		v=(int)s;

	}
	if (GPOINTER_TO_INT(data) == 5)
	{
		if (mov)
		mov=FALSE;
		else
			mov=TRUE;
	}
	if (GPOINTER_TO_INT(data) == 6)
	{

		if (skeleton) {
			if (dyed) {
				skeleton=FALSE;
				transparent=FALSE;
			}
		}
		else
			skeleton=TRUE;

	}
	if (GPOINTER_TO_INT(data) == 7)
	{
		if (transparent)
            transparent=FALSE;
		else {
			transparent=TRUE;
			skeleton=TRUE;
		}
	}
	if (GPOINTER_TO_INT(data) == 8) {
		if (dyed){
		dyed=FALSE;
		skeleton=TRUE;
	}
		else {
			dyed=TRUE;
		}
	}
}
static gboolean move(GtkWidget* widget)
{
	//char* hola;

    GtkWidget* window = gtk_widget_get_toplevel(widget);

    gtk_window_get_size(GTK_WINDOW(window), &width, &height);

if (mov==TRUE) {
	float nuevo1x,nuevo1y,nuevo1z;

	float nuevox,nuevoy,nuevoz;


	if (teta<PI){teta+=0.005f*s;}else{teta=0;}

	switch(o)
	{
		//rotation x


		case 1:
			for (int i=0; i<6 ; i++)
			{
				nuevo1x=medium[i][0]*cosf(teta)+medium[i][1]*sinf(teta);
				nuevo1y=-medium[i][0]*sinf(teta)+medium[i][1]*cosf(teta);
				nuevo1z=medium[i][2];

				medium[i][0]=nuevo1x;
				medium[i][1]=nuevo1y;
				medium[i][2]=nuevo1z;
			}
		for (int i=0; i<8 ; i++)
		{

			nuevox=angles[i][0]*cosf(teta)+angles[i][1]*sinf(teta);
			nuevoy=-angles[i][0]*sinf(teta)+angles[i][1]*cosf(teta);
			nuevoz=angles[i][2];



			angles[i][0]=nuevox;
			angles[i][1]=nuevoy;
			angles[i][2]=nuevoz;



		}
		break;


		case 2:

			for (int i=0; i<6 ; i++)
			{
				nuevo1x=medium[i][0]*cosf(teta)+medium[i][2]*sinf(teta);
				nuevo1y=medium[i][1];
				nuevo1z=-medium[i][0]*sinf(teta)+medium[i][2]*cosf(teta);


				medium[i][0]=nuevo1x;
				medium[i][1]=nuevo1y;
				medium[i][2]=nuevo1z;
			}

		for (int i=0; i<8 ; i++)
		{

			//rotation y
			nuevox=angles[i][0]*cosf(teta)+angles[i][2]*sinf(teta);
			nuevoy=angles[i][1];
			nuevoz=-angles[i][0]*sinf(teta)+angles[i][2]*cosf(teta);



			angles[i][0]=nuevox;
			angles[i][1]=nuevoy;
			angles[i][2]=nuevoz;



		}
		break;
		case 3:
			for (int i=0; i<6 ; i++)
			{

				nuevo1x=medium[i][0];
				nuevo1y=medium[i][1]*cosf(teta)-medium[i][2]*sinf(teta);
				nuevo1z=medium[i][1]*sinf(teta)+medium[i][2]*cosf(teta);

				medium[i][0]=nuevo1x;
				medium[i][1]=nuevo1y;
				medium[i][2]=nuevo1z;
			}

		for (int i=0; i<8 ; i++)
		{
			//rotation z

			nuevox=angles[i][0];
			nuevoy=angles[i][1]*cosf(teta)-angles[i][2]*sinf(teta);
			nuevoz=angles[i][1]*sinf(teta)+angles[i][2]*cosf(teta);




			angles[i][0]=nuevox;
			angles[i][1]=nuevoy;
			angles[i][2]=nuevoz;



		}
		break;
		default:
			break;
	}
}
    gtk_widget_queue_draw(widget);

    return TRUE;
}

static gboolean draw(GtkWidget* widget,cairo_t* context)
{

	char buffer1[18] = "Acceleration : ";
	const int acceleration=(int)s;
	char speed [3];
	if (acceleration==-1){speed[0]='-';speed[1]='1';speed[2]='\0';}
	if (acceleration==1)
	{speed[0]='+';speed[1]='1';speed[2]='\0';}
	if(acceleration==0){speed[0]=' ';speed[1]='0';speed[2]='\0';}
	strcat(buffer1, speed);

  cairo_select_font_face (context, "serif", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD);
   cairo_set_font_size (context, 20.0);

   cairo_set_source_rgb (context, 1.0, 0.0, 0.0);
	cairo_move_to(context,(float)width/3,(float)width/8);
	cairo_show_text(context,buffer1);

    for (int iw=0; iw < 6; iw++) {
	    if(medium[iw][2]>0) {
	    	if (dyed) {
	    		switch (iw)
	    		{
	    			case 0:

	    				cairo_set_source_rgb(context,0, 0, 1);
	    			break;

	    			case 1:

	    				cairo_set_source_rgb(context, 0, 2, 0 );
	    			break;

	    			case 2:
	    				cairo_set_source_rgb(context, 0, 1, 1);
	    			break;

	    			case 3:

	    				cairo_set_source_rgb(context, 2, 1, 0);
	    			break;

	    			case 4:

	    				cairo_set_source_rgb(context, 2, 0, 1);
	    			break;

	    			case 5:

	    				cairo_set_source_rgb(context, 1, 0, 1);
	    			break;
	    			default: ;
	    		}
	    		cairo_move_to(context,angles[vortex[plano[iw][0]][0]][0]*(float)width/5+(float)width/3,angles[vortex[plano[iw][0]][0]][1]*(float)width/5+(float)width/3);
	    		cairo_line_to(context,angles[vortex[plano[iw][0]][1]][0]*(float)width/5+(float)width/3,angles[vortex[plano[iw][0]][1]][1]*(float)width/5+(float)width/3);
	    		cairo_arc (context, medium[iw][0]*(float)width/5+(float)width/3, medium[iw][1]*(float)width/5+(float)width/3, 10, 0, .1);
	    		cairo_fill (context);

	    		cairo_move_to(context,angles[vortex[plano[iw][1]][0]][0]*(float)width/5+(float)width/3,angles[vortex[plano[iw][1]][0]][1]*(float)width/5+(float)width/3);
	    		cairo_line_to(context,angles[vortex[plano[iw][1]][1]][0]*(float)width/5+(float)width/3,angles[vortex[plano[iw][1]][1]][1]*(float)width/5+(float)width/3);
	    		cairo_arc (context, medium[iw][0]*(float)width/5+(float)width/3, medium[iw][1]*(float)width/5+(float)width/3, 10, 0, .1);
	    		cairo_fill (context);

	    		cairo_move_to(context,angles[vortex[plano[iw][2]][0]][0]*(float)width/5+(float)width/3,angles[vortex[plano[iw][2]][0]][1]*(float)width/5+(float)width/3);
	    		cairo_line_to(context,angles[vortex[plano[iw][2]][1]][0]*(float)width/5+(float)width/3,angles[vortex[plano[iw][2]][1]][1]*(float)width/5+(float)width/3);
	    		cairo_arc (context, medium[iw][0]*(float)width/5+(float)width/3, medium[iw][1]*(float)width/5+(float)width/3, 10, 0, .1);
	    		cairo_fill (context);

	    		cairo_move_to(context,angles[vortex[plano[iw][3]][0]][0]*(float)width/5+(float)width/3,angles[vortex[plano[iw][3]][0]][1]*(float)width/5+(float)width/3);
	    		cairo_line_to(context,angles[vortex[plano[iw][3]][1]][0]*(float)width/5+(float)width/3,angles[vortex[plano[iw][3]][1]][1]*(float)width/5+(float)width/3);
	    		cairo_arc (context, medium[iw][0]*(float)width/5+(float)width/3, medium[iw][1]*(float)width/5+(float)width/3, 10, 0, .1);
	    		cairo_fill (context);
	    	}
	    	if (skeleton && !transparent) {
	    		cairo_set_source_rgb(context, 0, 0, 0);
	    		cairo_move_to(context,angles[vortex[plano[iw][0]][0]][0]*(float)width/5+(float)width/3,angles[vortex[plano[iw][0]][0]][1]*(float)width/5+(float)width/3);
	    		cairo_line_to(context,angles[vortex[plano[iw][0]][1]][0]*(float)width/5+(float)width/3,angles[vortex[plano[iw][0]][1]][1]*(float)width/5+(float)width/3);
	    		cairo_move_to(context,angles[vortex[plano[iw][1]][0]][0]*(float)width/5+(float)width/3,angles[vortex[plano[iw][1]][0]][1]*(float)width/5+(float)width/3);
	    		cairo_line_to(context,angles[vortex[plano[iw][1]][1]][0]*(float)width/5+(float)width/3,angles[vortex[plano[iw][1]][1]][1]*(float)width/5+(float)width/3);
	    		cairo_move_to(context,angles[vortex[plano[iw][2]][0]][0]*(float)width/5+(float)width/3,angles[vortex[plano[iw][2]][0]][1]*(float)width/5+(float)width/3);
	    		cairo_line_to(context,angles[vortex[plano[iw][2]][1]][0]*(float)width/5+(float)width/3,angles[vortex[plano[iw][2]][1]][1]*(float)width/5+(float)width/3);
	    		cairo_move_to(context,angles[vortex[plano[iw][3]][0]][0]*(float)width/5+(float)width/3,angles[vortex[plano[iw][3]][0]][1]*(float)width/5+(float)width/3);
	    		cairo_line_to(context,angles[vortex[plano[iw][3]][1]][0]*(float)width/5+(float)width/3,angles[vortex[plano[iw][3]][1]][1]*(float)width/5+(float)width/3);
	    		cairo_stroke(context);
	    	}

	    }
    }
	if (transparent) {
	for (int iw=0; iw < 6; iw++) {

    		cairo_set_source_rgb(context, 0, 0, 0);
    		cairo_move_to(context,angles[vortex[plano[iw][0]][0]][0]*(float)width/5+(float)width/3,angles[vortex[plano[iw][0]][0]][1]*(float)width/5+(float)width/3);
    		cairo_line_to(context,angles[vortex[plano[iw][0]][1]][0]*(float)width/5+(float)width/3,angles[vortex[plano[iw][0]][1]][1]*(float)width/5+(float)width/3);
    		cairo_move_to(context,angles[vortex[plano[iw][1]][0]][0]*(float)width/5+(float)width/3,angles[vortex[plano[iw][1]][0]][1]*(float)width/5+(float)width/3);
    		cairo_line_to(context,angles[vortex[plano[iw][1]][1]][0]*(float)width/5+(float)width/3,angles[vortex[plano[iw][1]][1]][1]*(float)width/5+(float)width/3);
    		cairo_move_to(context,angles[vortex[plano[iw][2]][0]][0]*(float)width/5+(float)width/3,angles[vortex[plano[iw][2]][0]][1]*(float)width/5+(float)width/3);
    		cairo_line_to(context,angles[vortex[plano[iw][2]][1]][0]*(float)width/5+(float)width/3,angles[vortex[plano[iw][2]][1]][1]*(float)width/5+(float)width/3);
    		cairo_move_to(context,angles[vortex[plano[iw][3]][0]][0]*(float)width/5+(float)width/3,angles[vortex[plano[iw][3]][0]][1]*(float)width/5+(float)width/3);
    		cairo_line_to(context,angles[vortex[plano[iw][3]][1]][0]*(float)width/5+(float)width/3,angles[vortex[plano[iw][3]][1]][1]*(float)width/5+(float)width/3);
    		cairo_stroke(context);
    	}
    }



    return FALSE;
}
gint delete_event(void)
{
	gtk_main_quit ();
	return FALSE;
}
GtkWidget *make_box(const gboolean homogeneous,
                    const gint     spacing,
                    const gboolean expand,
                    const gboolean fill,
                    const guint    padding ) {
	GtkWidget *box2 = gtk_box_new(homogeneous, spacing);


	GtkWidget *button1 = gtk_button_new_with_label("rotation x");
	g_signal_connect (G_OBJECT (button1), "clicked", G_CALLBACK (on_button_click), GINT_TO_POINTER(1));
	gtk_box_pack_start (GTK_BOX (box2), button1, expand, fill, padding);
	gtk_widget_show (button1);

	GtkWidget *button2 = gtk_button_new_with_label("rotation y");
	g_signal_connect (G_OBJECT (button2), "clicked", G_CALLBACK(on_button_click), GINT_TO_POINTER(2));
	gtk_box_pack_start (GTK_BOX (box2), button2, expand, fill, padding);
	gtk_widget_show (button2);

	GtkWidget *button3 = gtk_button_new_with_label("rotation z");
	g_signal_connect (G_OBJECT (button3), "clicked", G_CALLBACK(on_button_click), GINT_TO_POINTER(3));
	gtk_box_pack_start (GTK_BOX (box2), button3, expand, fill, padding);
	gtk_widget_show (button3);



		GtkWidget *button4 = gtk_button_new_with_label(expand ? "SPEED" : "VELOCITY");
		g_signal_connect (G_OBJECT (button4), "clicked", G_CALLBACK(on_button_click), GINT_TO_POINTER(4));

	gtk_box_pack_start (GTK_BOX (box2), button4, expand, fill, padding);
	gtk_widget_show (button4);


	GtkWidget *button5 = gtk_button_new_with_label(fill ? "CONTINUE" : "STOP");
	g_signal_connect (G_OBJECT (button5), "clicked", G_CALLBACK(on_button_click), GINT_TO_POINTER(5));
	gtk_box_pack_start (GTK_BOX (box2), button5, expand, fill, padding);
	gtk_widget_show (button5);



	GtkWidget *button6 = gtk_button_new_with_label("skeleton");
	g_signal_connect (G_OBJECT (button6), "clicked", G_CALLBACK(on_button_click), GINT_TO_POINTER(6));
	gtk_box_pack_start (GTK_BOX (box2), button6, expand, fill, padding);
	gtk_widget_show (button6);

	GtkWidget *button7 = gtk_button_new_with_label("transparent skeleton");
	g_signal_connect (G_OBJECT (button7), "clicked", G_CALLBACK(on_button_click), GINT_TO_POINTER(7));
	gtk_box_pack_start (GTK_BOX (box2), button7, expand, fill, padding);
	gtk_widget_show (button7);

	GtkWidget *button8 = gtk_button_new_with_label("DYED");
	g_signal_connect (G_OBJECT (button8), "clicked", G_CALLBACK(on_button_click), GINT_TO_POINTER(8));
	gtk_box_pack_start (GTK_BOX (box2), button8, expand, fill, padding);
	gtk_widget_show (button8);
	return box2;
}
int main(int argc, char** argv) {
	drawed();
	gtk_init(&argc, &argv);
	GtkWidget *box1 = gtk_box_new (FALSE, 0);
    GtkWidget *window1 = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	gtk_container_set_border_width (GTK_CONTAINER (window1), 10);
    gtk_window_set_position(GTK_WINDOW(window1), GTK_WIN_POS_CENTER_ON_PARENT);
    gtk_window_set_default_size(GTK_WINDOW(window1), 150, 50);
    gtk_window_set_title(GTK_WINDOW(window1), "BUTTONS");
    g_signal_connect(G_OBJECT(window1), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    //gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    //gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);


    //GtkWidget *grid = gtk_grid_new();
    //gtk_container_add (GTK_CONTAINER (window1), grid);

//botones
	GtkWidget *box2 = make_box(FALSE, 0, FALSE, FALSE, 0);
	GtkWidget *label = gtk_label_new("        What you wanna do ?");
	gtk_box_pack_end (GTK_BOX (box2), label, FALSE, FALSE, 0);
	gtk_widget_show(label);

	gtk_box_pack_start (GTK_BOX (box1), box2, FALSE, FALSE, 0);
	gtk_widget_show (box2);
	GtkWidget *separator = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_widget_set_size_request (separator, 150, 50);
	/* coloca el separador en la vbox (box1) */
	gtk_box_pack_start (GTK_BOX (box1), separator, FALSE, TRUE, 5);
	gtk_widget_show (separator);

	//gtk_widget_show (box2);
	GtkWidget *quitbox = gtk_box_new(FALSE, 0);
	GtkWidget *button = gtk_button_new_with_label("Quit");
	g_signal_connect_swapped (G_OBJECT (button), "clicked",
								  G_CALLBACK (gtk_main_quit),
								  G_OBJECT (window1));
	gtk_box_pack_start (GTK_BOX (quitbox), button, TRUE, FALSE, 0);
	/* Coloca la hbox (quitbox) en la vbox (box1) */
	gtk_box_pack_start (GTK_BOX (box1), quitbox, FALSE, FALSE, 0);
	gtk_container_add (GTK_CONTAINER (window1), box1);
	//gtk_widget_show (button);
	//gtk_widget_show (quitbox);

	//gtk_widget_show (box2);
	gtk_widget_show_all (window1);
/*
	gtk_widget_set_name (separator, "separator");
	gtk_container_add (GTK_CONTAINER (window1), separator);
	gtk_box_pack_start (GTK_BOX (box2), separator, FALSE, FALSE, 0);
	gtk_widget_show (separator);
	GtkWidget *quitbox = gtk_box_new(FALSE, 0);
	GtkWidget * button = gtk_button_new_with_label ("Quit");
	g_signal_connect_swapped (G_OBJECT (button), "clicked",
								  G_CALLBACK (gtk_main_quit),
								  G_OBJECT (window1));
	gtk_box_pack_start (GTK_BOX (quitbox), button, TRUE, FALSE, 0);
	gtk_box_pack_start (GTK_BOX (box2), quitbox, FALSE, FALSE, 0);
	gtk_container_add (GTK_CONTAINER (window1), box2);
	gtk_widget_show (button);
	gtk_widget_show (quitbox);

	gtk_widget_show (box2);
	//gtk_widget_set_name (quitbox, "quit");
	//gtk_widget_show (quitbox);
	quitbox = gtk_hbox_new (FALSE, 0);
	//gtk_widget_show (window1);
*/
	/*
   button = gtk_button_new_with_label("rotation x");
  //g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (on_button_click), (gpointer) "1");
  g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (on_button_click), (gpointer) "1");
  gtk_grid_attach (GTK_GRID(window1),button, 200, 10, 1, 1);

  button = gtk_button_new_with_label ("rotation y");
  g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK(on_button_click), (gpointer) "2");
  gtk_grid_attach (GTK_GRID(window1),button,200,100,1, 1);

  button = gtk_button_new_with_label ("rotation z");
  g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK(on_button_click), (gpointer) "3");
  gtk_grid_attach (GTK_GRID(window1),button,200,200,1,1);

  button = gtk_button_new_with_label ("speed");
  g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK(on_button_click), (gpointer) "4");
  gtk_grid_attach (GTK_GRID(window1),button,200,300,1,1);

  button=gtk_button_new_with_label ("exit");
  gtk_grid_attach (GTK_GRID (window1),button,200,400,1,1);
  g_signal_connect (G_OBJECT(window),"destroy",G_CALLBACK(gtk_main_quit),NULL);
  g_signal_connect_swapped (G_OBJECT(button),"clicked",G_CALLBACK(gtk_main_quit),window);
	*/
	GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_container_set_border_width (GTK_CONTAINER (window), 10);
	gtk_window_set_title(GTK_WINDOW(window), "THE LUIS FEDERICO'S CUBE");
    //GtkWidget *frame = gtk_frame_new(NULL);
    GtkWidget *area = gtk_drawing_area_new();

//ratrojos


	//gtk_container_add (GTK_CONTAINER (grid), frame);
    //gtk_container_add (GTK_CONTAINER (frame), area);
	//gtk_window_get_size(GTK_WINDOW(window), &width, &height);
	//gtk_widget_set_size_request(window, width, height);
    //gtk_widget_set_size_request (frame, GTK_EXPAND|GTK_FILL,GTK_EXPAND|GTK_FILL );
	//gtk_widget_set_size_request(area,1000,800 );
    //gtk_grid_attach (GTK_GRID(grid),frame,2,1,GTK_EXPAND|GTK_FILL, GTK_EXPAND|GTK_FILL);
	gtk_container_add(GTK_CONTAINER(window), area);
	gtk_window_set_default_size(GTK_WINDOW(window), 500, 400);

    g_signal_connect (G_OBJECT (area), "draw", G_CALLBACK (draw), NULL);

    //gtk_container_add(GTK_CONTAINER(window), darea);
    //gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    //gtk_window_set_default_size(GTK_WINDOW(window), 600, 400);
    //gtk_window_set_title(GTK_WINDOW(window), "EL CUBO DE LUIS FEDERICO");
    //g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    //g_signal_connect(G_OBJECT(darea), "draw", G_CALLBACK(draw), NULL);

    g_timeout_add(90, (GSourceFunc)move, window);

    //gtk_widget_show_all(window1);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}

