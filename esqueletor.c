#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gtk/gtk.h>
#include <cairo.h>

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


static void pintado();


float angles[8][3];
float medium[6][3];
static void pintado() {

	
	
	angles[0][0]=-.5;
	angles[0][1]=-.5;
	angles[0][2]=-.5;
	angles[1][0]=-.5;
	angles[1][1]=.5;
	angles[1][2]=-.5;
	angles[2][0]=.5;
	angles[2][1]=.5;
	angles[2][2]=-.5;
	angles[3][0]=.5;
	angles[3][1]=-.5;
	angles[3][2]=-.5;
	angles[4][0]=-.5;
	angles[4][1]=-.5;
	angles[4][2]=.5;
	angles[5][0]=-.5;
	angles[5][1]=.5;
	angles[5][2]=.5;
	angles[6][0]=.5;
	angles[6][1]=.5;
	angles[6][2]=.5;
	angles[7][0]=.5;
	angles[7][1]=-.5;
	angles[7][2]=.5;
	
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
	medium[0][2]=-.5;
	
	plano[1][0]=4;
	plano[1][1]=5;
	plano[1][2]=6;
	plano[1][3]=7;
    medium[1][0]=0;
	medium[1][1]=0;
	medium[1][2]=.5;
	
	plano[2][0]=10;
	plano[2][1]=11;
	plano[2][2]=6;
	plano[2][3]=2;
	medium[2][0]=0.5;
	medium[2][1]=0;
	medium[2][2]=0;
	
	plano[3][0]=8;
	plano[3][1]=9;
	plano[3][2]=0;
	plano[3][3]=4;
	medium[3][0]=-.5;
	medium[3][1]=0;
	medium[3][2]=0;
	
	plano[4][0]=9;
	plano[4][1]=10;
	plano[4][2]=1;
	plano[4][3]=5;
	medium[4][0]=0;
    medium[4][1]=.5;
    medium[4][2]=0;

	plano[5][0]=8;
	plano[5][1]=11;
	plano[5][2]=7;
	plano[5][3]=3;
	medium[5][0]=0;
	medium[5][1]=-.5;
	medium[5][2]=0;
//	printf("Hasta aqui, todo bien\n");
	
}

void on_button_click(GtkWidget *widget, gpointer data)
{

    //g_print(" Button_number %s was clicked \n",(char *) data);

    if ((char *) data=="1")
    {
        o=1;;
    }
    if ((char *) data=="2")
    {
        o=2;;
    }
    if ((char *) data=="3")
    {
        o=3;
    }
    if ((char *) data=="4")
    {
		int s;
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
		}
		v=s;
        
    }
    }
static gboolean move(GtkWidget* widget)
{

//printf("Hasta aqui, todo bien\n");
	
	float nuevox, nuevoy, nuevoz;
	float nuevo1x, nuevo1y, nuevo1z;
	

  //char* hola;
  
    GtkWidget* window = gtk_widget_get_toplevel(widget);
    gtk_window_get_size(GTK_WINDOW(window), &width, &height);
    
   
   if (teta<PI){teta+=0.005*v;}else{teta=0;}
   
		switch(o)
		{ 
    //rotacion x

    
    case 1:
    for (int i=0; i<6 ; i++)
    {
    nuevo1x=medium[i][0]*cos(teta)+medium[i][1]*sin(teta);
    nuevo1y=-medium[i][0]*sin(teta)+medium[i][1]*cos(teta);
    nuevo1z=medium[i][2];

    medium[i][0]=nuevo1x;
    medium[i][1]=nuevo1y;
    medium[i][2]=nuevo1z;
}
    for (int i=0; i<8 ; i++)
    {
    //g_print("pasa xaqui 1");
    nuevox=angles[i][0]*cos(teta)+angles[i][1]*sin(teta);
    nuevoy=-angles[i][0]*sin(teta)+angles[i][1]*cos(teta);
    nuevoz=angles[i][2];
    
    
    
    angles[i][0]=nuevox;
    angles[i][1]=nuevoy;
    angles[i][2]=nuevoz;
    
    
    
    }
    break;
    
    
            case 2:
            
            for (int i=0; i<6 ; i++)
    {
	nuevo1x=medium[i][0]*cos(teta)+medium[i][2]*sin(teta);
    nuevo1y=medium[i][1];
    nuevo1z=-medium[i][0]*sin(teta)+medium[i][2]*cos(teta);
    
    
    medium[i][0]=nuevo1x;
    medium[i][1]=nuevo1y;
    medium[i][2]=nuevo1z;
}

            for (int i=0; i<8 ; i++)
    {
            //g_print("pasa xaqui 2");
    //rotacion y
    nuevox=angles[i][0]*cos(teta)+angles[i][2]*sin(teta);
    nuevoy=angles[i][1];
    nuevoz=-angles[i][0]*sin(teta)+angles[i][2]*cos(teta);
    
    
    //g_print("pasa xaqui y");
    angles[i][0]=nuevox;
    angles[i][1]=nuevoy;
    angles[i][2]=nuevoz;
    
    
    
    }
    break;        
            case 3:
            for (int i=0; i<6 ; i++)
    {
		
	nuevo1x=medium[i][0];
    nuevo1y=medium[i][1]*cos(teta)-medium[i][2]*sin(teta);
    nuevo1z=medium[i][1]*sin(teta)+medium[i][2]*cos(teta);
    
    medium[i][0]=nuevo1x;
    medium[i][1]=nuevo1y;
    medium[i][2]=nuevo1z;
}

            for (int i=0; i<8 ; i++)
    {
    //rotacion z
    //g_print("pasa xaqui 3");
    nuevox=angles[i][0];
    nuevoy=angles[i][1]*cos(teta)-angles[i][2]*sin(teta);
    nuevoz=angles[i][1]*sin(teta)+angles[i][2]*cos(teta);
    
    
    
    //g_print("pasa xaqui z");
    angles[i][0]=nuevox;
    angles[i][1]=nuevoy;
    angles[i][2]=nuevoz;
    
    
    
    }
    break;
    }

    gtk_widget_queue_draw(widget);
    
    return TRUE;
}

static gboolean draw(GtkWidget* widget,cairo_t* context)
{
	
	char buffer1[40] = "speed : ";
  char * ptr;
 
  char speed [4];
	if (v==-1){speed[0]='-';speed[1]='1';}
	if (v==1)
	{speed[0]='+';speed[1]='1';}
	if(v==0){speed[0]=' ';speed[1]='0';}
	ptr = strcat( buffer1, speed );
  //printf( "buffer1 = %s\n", buffer1 );
	cairo_move_to(context,200,20);
	cairo_show_text(context,buffer1);
   
    for (int iw=0; iw < 6; iw++) {
		
		if(medium[iw][2]>0){
			
   
	
        switch (iw)
		{
			case 0:
			//Esto es azul:
		cairo_set_source_rgba(context,0.0, 0.0, 1.0, 1.0);
		cairo_move_to(context,angles[vortex[plano[iw][0]][0]][0]*width/5+width/3,angles[vortex[plano[iw][0]][0]][1]*width/5+width/3);
        cairo_line_to(context,angles[vortex[plano[iw][0]][1]][0]*width/5+width/3,angles[vortex[plano[iw][0]][1]][1]*width/5+width/3);
        cairo_arc (context, medium[iw][0]*width/5+width/3, medium[iw][1]*width/5+width/3, 10, 0, .1);
        cairo_fill (context);
        
        cairo_move_to(context,angles[vortex[plano[iw][1]][0]][0]*width/5+width/3,angles[vortex[plano[iw][1]][0]][1]*width/5+width/3);
        cairo_line_to(context,angles[vortex[plano[iw][1]][1]][0]*width/5+width/3,angles[vortex[plano[iw][1]][1]][1]*width/5+width/3);
        cairo_arc (context, medium[iw][0]*width/5+width/3, medium[iw][1]*width/5+width/3, 10, 0, .1);
        cairo_fill (context);
        
        cairo_move_to(context,angles[vortex[plano[iw][2]][0]][0]*width/5+width/3,angles[vortex[plano[iw][2]][0]][1]*width/5+width/3);
        cairo_line_to(context,angles[vortex[plano[iw][2]][1]][0]*width/5+width/3,angles[vortex[plano[iw][2]][1]][1]*width/5+width/3);
        cairo_arc (context, medium[iw][0]*width/5+width/3, medium[iw][1]*width/5+width/3, 10, 0, .1);
        cairo_fill (context);
        
        cairo_move_to(context,angles[vortex[plano[iw][3]][0]][0]*width/5+width/3,angles[vortex[plano[iw][3]][0]][1]*width/5+width/3);
        cairo_line_to(context,angles[vortex[plano[iw][3]][1]][0]*width/5+width/3,angles[vortex[plano[iw][3]][1]][1]*width/5+width/3);
        cairo_arc (context, medium[iw][0]*width/5+width/3, medium[iw][1]*width/5+width/3, 10, 0, .1);
        cairo_fill (context);
        
        //cairo_fill(context);
		cairo_stroke(context);
		break;
		
		case 1:
		//Esto es verde:
		cairo_set_source_rgb(context, 0, 2, 0 );
		 cairo_move_to(context,angles[vortex[plano[iw][0]][0]][0]*width/5+width/3,angles[vortex[plano[iw][0]][0]][1]*width/5+width/3);
        cairo_line_to(context,angles[vortex[plano[iw][0]][1]][0]*width/5+width/3,angles[vortex[plano[iw][0]][1]][1]*width/5+width/3);
        cairo_arc (context, medium[iw][0]*width/5+width/3, medium[iw][1]*width/5+width/3, 10, 0, .1);
        cairo_fill (context);
        
        cairo_move_to(context,angles[vortex[plano[iw][1]][0]][0]*width/5+width/3,angles[vortex[plano[iw][1]][0]][1]*width/5+width/3);
        cairo_line_to(context,angles[vortex[plano[iw][1]][1]][0]*width/5+width/3,angles[vortex[plano[iw][1]][1]][1]*width/5+width/3);
        cairo_arc (context, medium[iw][0]*width/5+width/3, medium[iw][1]*width/5+width/3, 10, 0, .1);
        cairo_fill (context);
        
        cairo_move_to(context,angles[vortex[plano[iw][2]][0]][0]*width/5+width/3,angles[vortex[plano[iw][2]][0]][1]*width/5+width/3);
        cairo_line_to(context,angles[vortex[plano[iw][2]][1]][0]*width/5+width/3,angles[vortex[plano[iw][2]][1]][1]*width/5+width/3);
        cairo_arc (context, medium[iw][0]*width/5+width/3, medium[iw][1]*width/5+width/3, 10, 0, .1);
        cairo_fill (context);
        
        cairo_move_to(context,angles[vortex[plano[iw][3]][0]][0]*width/5+width/3,angles[vortex[plano[iw][3]][0]][1]*width/5+width/3);
        cairo_line_to(context,angles[vortex[plano[iw][3]][1]][0]*width/5+width/3,angles[vortex[plano[iw][3]][1]][1]*width/5+width/3);
        cairo_arc (context, medium[iw][0]*width/5+width/3, medium[iw][1]*width/5+width/3, 10, 0, .1);
        cairo_fill (context);
        //cairo_fill(context);
		cairo_stroke(context);
		break;
		
		case 2:
		//Esto es azulete claro:
		cairo_set_source_rgb(context, 0, 1, 1);
		cairo_move_to(context,angles[vortex[plano[iw][0]][0]][0]*width/5+width/3,angles[vortex[plano[iw][0]][0]][1]*width/5+width/3);
        cairo_line_to(context,angles[vortex[plano[iw][0]][1]][0]*width/5+width/3,angles[vortex[plano[iw][0]][1]][1]*width/5+width/3);
        cairo_arc (context, medium[iw][0]*width/5+width/3, medium[iw][1]*width/5+width/3, 10, 0, .1);
        cairo_fill (context);
        
        cairo_move_to(context,angles[vortex[plano[iw][1]][0]][0]*width/5+width/3,angles[vortex[plano[iw][1]][0]][1]*width/5+width/3);
        cairo_line_to(context,angles[vortex[plano[iw][1]][1]][0]*width/5+width/3,angles[vortex[plano[iw][1]][1]][1]*width/5+width/3);
        cairo_arc (context, medium[iw][0]*width/5+width/3, medium[iw][1]*width/5+width/3, 10, 0, .1);
        cairo_fill (context);
        
        cairo_move_to(context,angles[vortex[plano[iw][2]][0]][0]*width/5+width/3,angles[vortex[plano[iw][2]][0]][1]*width/5+width/3);
        cairo_line_to(context,angles[vortex[plano[iw][2]][1]][0]*width/5+width/3,angles[vortex[plano[iw][2]][1]][1]*width/5+width/3);
        cairo_arc (context, medium[iw][0]*width/5+width/3, medium[iw][1]*width/5+width/3, 10, 0, .1);
        cairo_fill (context);
        
        cairo_move_to(context,angles[vortex[plano[iw][3]][0]][0]*width/5+width/3,angles[vortex[plano[iw][3]][0]][1]*width/5+width/3);
        cairo_line_to(context,angles[vortex[plano[iw][3]][1]][0]*width/5+width/3,angles[vortex[plano[iw][3]][1]][1]*width/5+width/3);
        cairo_arc (context, medium[iw][0]*width/5+width/3, medium[iw][1]*width/5+width/3, 10, 0, .1);
        cairo_fill (context);
        
        //cairo_fill(context);
		cairo_stroke(context);
		break;
		
		case 3:
		//Esto es amarillo:
		cairo_set_source_rgb(context, 2, 1, 0);
		cairo_move_to(context,angles[vortex[plano[iw][0]][0]][0]*width/5+width/3,angles[vortex[plano[iw][0]][0]][1]*width/5+width/3);
        cairo_line_to(context,angles[vortex[plano[iw][0]][1]][0]*width/5+width/3,angles[vortex[plano[iw][0]][1]][1]*width/5+width/3);
        cairo_arc (context, medium[iw][0]*width/5+width/3, medium[iw][1]*width/5+width/3, 10, 0, .1);
        cairo_fill (context);
        
        cairo_move_to(context,angles[vortex[plano[iw][1]][0]][0]*width/5+width/3,angles[vortex[plano[iw][1]][0]][1]*width/5+width/3);
        cairo_line_to(context,angles[vortex[plano[iw][1]][1]][0]*width/5+width/3,angles[vortex[plano[iw][1]][1]][1]*width/5+width/3);
        cairo_arc (context, medium[iw][0]*width/5+width/3, medium[iw][1]*width/5+width/3, 10, 0, .1);
        cairo_fill (context);
        
        cairo_move_to(context,angles[vortex[plano[iw][2]][0]][0]*width/5+width/3,angles[vortex[plano[iw][2]][0]][1]*width/5+width/3);
        cairo_line_to(context,angles[vortex[plano[iw][2]][1]][0]*width/5+width/3,angles[vortex[plano[iw][2]][1]][1]*width/5+width/3);
        cairo_arc (context, medium[iw][0]*width/5+width/3, medium[iw][1]*width/5+width/3, 10, 0, .1);
        cairo_fill (context);
        
        cairo_move_to(context,angles[vortex[plano[iw][3]][0]][0]*width/5+width/3,angles[vortex[plano[iw][3]][0]][1]*width/5+width/3);
        cairo_line_to(context,angles[vortex[plano[iw][3]][1]][0]*width/5+width/3,angles[vortex[plano[iw][3]][1]][1]*width/5+width/3);
        cairo_arc (context, medium[iw][0]*width/5+width/3, medium[iw][1]*width/5+width/3, 10, 0, .1);
        cairo_fill (context);
        
        cairo_stroke(context);
		break;
		
		case 4:
		//Esto es rosa:
		cairo_set_source_rgb(context, 2, 0, 1);
		cairo_move_to(context,angles[vortex[plano[iw][0]][0]][0]*width/5+width/3,angles[vortex[plano[iw][0]][0]][1]*width/5+width/3);
        cairo_line_to(context,angles[vortex[plano[iw][0]][1]][0]*width/5+width/3,angles[vortex[plano[iw][0]][1]][1]*width/5+width/3);
        cairo_arc (context, medium[iw][0]*width/5+width/3, medium[iw][1]*width/5+width/3, 10, 0, .1);
        cairo_fill (context);
        
        cairo_move_to(context,angles[vortex[plano[iw][1]][0]][0]*width/5+width/3,angles[vortex[plano[iw][1]][0]][1]*width/5+width/3);
        cairo_line_to(context,angles[vortex[plano[iw][1]][1]][0]*width/5+width/3,angles[vortex[plano[iw][1]][1]][1]*width/5+width/3);
        cairo_arc (context, medium[iw][0]*width/5+width/3, medium[iw][1]*width/5+width/3, 10, 0, .1);
        cairo_fill (context);
        
        cairo_move_to(context,angles[vortex[plano[iw][2]][0]][0]*width/5+width/3,angles[vortex[plano[iw][2]][0]][1]*width/5+width/3);
        cairo_line_to(context,angles[vortex[plano[iw][2]][1]][0]*width/5+width/3,angles[vortex[plano[iw][2]][1]][1]*width/5+width/3);
        cairo_arc (context, medium[iw][0]*width/5+width/3, medium[iw][1]*width/5+width/3, 10, 0, .1);
        cairo_fill (context);
        
        cairo_move_to(context,angles[vortex[plano[iw][3]][0]][0]*width/5+width/3,angles[vortex[plano[iw][3]][0]][1]*width/5+width/3);
        cairo_line_to(context,angles[vortex[plano[iw][3]][1]][0]*width/5+width/3,angles[vortex[plano[iw][3]][1]][1]*width/5+width/3);
        cairo_arc (context, medium[iw][0]*width/5+width/3, medium[iw][1]*width/5+width/3, 10, 0, .1);
        cairo_fill (context);
        //cairo_fill(context);
        cairo_stroke(context);
		break;
		
		case 5:
		cairo_set_source_rgb(context, 1, 0, 1);
		cairo_move_to(context,angles[vortex[plano[iw][0]][0]][0]*width/5+width/3,angles[vortex[plano[iw][0]][0]][1]*width/5+width/3);
        cairo_line_to(context,angles[vortex[plano[iw][0]][1]][0]*width/5+width/3,angles[vortex[plano[iw][0]][1]][1]*width/5+width/3);
        cairo_arc (context, medium[iw][0]*width/5+width/3, medium[iw][1]*width/5+width/3, 10, 0, .1);
        cairo_fill (context);
        
        cairo_move_to(context,angles[vortex[plano[iw][1]][0]][0]*width/5+width/3,angles[vortex[plano[iw][1]][0]][1]*width/5+width/3);
        cairo_line_to(context,angles[vortex[plano[iw][1]][1]][0]*width/5+width/3,angles[vortex[plano[iw][1]][1]][1]*width/5+width/3);
        cairo_arc (context, medium[iw][0]*width/5+width/3, medium[iw][1]*width/5+width/3, 10, 0, .1);
        cairo_fill (context);
        
        cairo_move_to(context,angles[vortex[plano[iw][2]][0]][0]*width/5+width/3,angles[vortex[plano[iw][2]][0]][1]*width/5+width/3);
        cairo_line_to(context,angles[vortex[plano[iw][2]][1]][0]*width/5+width/3,angles[vortex[plano[iw][2]][1]][1]*width/5+width/3);
        cairo_arc (context, medium[iw][0]*width/5+width/3, medium[iw][1]*width/5+width/3, 10, 0, .1);
        cairo_fill (context);
        
        cairo_move_to(context,angles[vortex[plano[iw][3]][0]][0]*width/5+width/3,angles[vortex[plano[iw][3]][0]][1]*width/5+width/3);
        cairo_line_to(context,angles[vortex[plano[iw][3]][1]][0]*width/5+width/3,angles[vortex[plano[iw][3]][1]][1]*width/5+width/3);
        cairo_arc (context, medium[iw][0]*width/5+width/3, medium[iw][1]*width/5+width/3, 10, 0, .1);
        cairo_fill (context);
        //cairo_fill(context);
        cairo_stroke(context);
		break;
	}
	            cairo_set_source_rgb(context, 0, 0, 0);
                cairo_move_to(context,angles[vortex[plano[iw][0]][0]][0]*width/5+width/3,angles[vortex[plano[iw][0]][0]][1]*width/5+width/3);
                cairo_line_to(context,angles[vortex[plano[iw][0]][1]][0]*width/5+width/3,angles[vortex[plano[iw][0]][1]][1]*width/5+width/3);
                cairo_move_to(context,angles[vortex[plano[iw][1]][0]][0]*width/5+width/3,angles[vortex[plano[iw][1]][0]][1]*width/5+width/3);
                cairo_line_to(context,angles[vortex[plano[iw][1]][1]][0]*width/5+width/3,angles[vortex[plano[iw][1]][1]][1]*width/5+width/3);
                cairo_move_to(context,angles[vortex[plano[iw][2]][0]][0]*width/5+width/3,angles[vortex[plano[iw][2]][0]][1]*width/5+width/3);
                cairo_line_to(context,angles[vortex[plano[iw][2]][1]][0]*width/5+width/3,angles[vortex[plano[iw][2]][1]][1]*width/5+width/3);
                cairo_move_to(context,angles[vortex[plano[iw][3]][0]][0]*width/5+width/3,angles[vortex[plano[iw][3]][0]][1]*width/5+width/3);
                cairo_line_to(context,angles[vortex[plano[iw][3]][1]][0]*width/5+width/3,angles[vortex[plano[iw][3]][1]][1]*width/5+width/3);
                cairo_stroke(context);
	}
	//cairo_set_source_rgb(context, 1, 0, 0);
      //  cairo_fill(context);
    }
    

    return FALSE;
}

int main(int argc, char** argv) {
//printf("Hasta aqui, todo bien\n");
    pintado();
    GtkWidget* window;
    GtkWidget* window1;
    GtkWidget* darea;
    cairo_t *context;
  GtkWidget *button;
  GtkWidget *table;
  GtkWidget *label;
  GtkWidget *frame;
    //printf("Hasta aqui, todo bien\n");
    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    window1 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);
    gtk_window_set_position(GTK_WINDOW(window1), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window1), 500, 400);
    gtk_window_set_title(GTK_WINDOW(window1), "BOTONERA");
    g_signal_connect(G_OBJECT(window1), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
    gtk_window_set_title(GTK_WINDOW(window), "EL CUBO DE LUIS FEDERICO");
    
    table = gtk_table_new (3,4,FALSE);
    gtk_container_add (GTK_CONTAINER (window), table);

//botones

button = gtk_button_new_with_label ("rotation x");
  //g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (on_button_click), (gpointer) "1");
  g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (on_button_click), (gpointer) "1");
  gtk_table_attach (GTK_TABLE(table),button,0,1,0,1,0,0,2,2);

  button = gtk_button_new_with_label ("rotation y");
  g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK(on_button_click), (gpointer) "2");
  gtk_table_attach (GTK_TABLE (table),button,1,2,0,1,0,0,2,2);

  button = gtk_button_new_with_label ("rotation z");
  g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK(on_button_click), (gpointer) "3");
  gtk_table_attach (GTK_TABLE(table),button,2,3,0,1,0,0,2,2);

  button = gtk_button_new_with_label ("speed");
  g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK(on_button_click), (gpointer) "4");
  gtk_table_attach (GTK_TABLE(table),button,2,3,0,3,0,0,2,2);

  button=gtk_button_new_with_label ("exit");
  gtk_table_attach (GTK_TABLE (table),button,0,2,1,2,0,0,2,2);
  g_signal_connect (G_OBJECT(window),"destroy",G_CALLBACK(gtk_main_quit),NULL);
  g_signal_connect_swapped (G_OBJECT(button),"clicked",G_CALLBACK(gtk_main_quit),(gpointer)window);

    frame=gtk_frame_new(NULL);
    darea = gtk_drawing_area_new();

//ratrojos

    gtk_container_add (GTK_CONTAINER (frame), darea);
    gtk_widget_set_size_request (darea, 400, 400);
    gtk_table_attach (GTK_TABLE(table),frame,3,4,0,2,GTK_EXPAND|GTK_FILL, GTK_EXPAND|GTK_FILL,0,0);
    g_signal_connect (G_OBJECT (darea), "draw", G_CALLBACK (draw), NULL);
    
    //gtk_container_add(GTK_CONTAINER(window), darea);
    //gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    //gtk_window_set_default_size(GTK_WINDOW(window), 600, 400);
    //gtk_window_set_title(GTK_WINDOW(window), "EL CUBO DE LUIS FEDERICO");
    //g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    //g_signal_connect(G_OBJECT(darea), "draw", G_CALLBACK(draw), NULL);

    g_timeout_add(90, (GSourceFunc)move, window);

    gtk_widget_show_all(window1);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}

