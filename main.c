#include <stdio.h>
#include <math.h>
#include <gtk/gtk.h>
#include <cairo.h>
#include <stdbool.h>


#define SIZE 400
#define PI 3.1416
#define GRANDE 0.1

static int width, height;

float teta;

float circulos[6][6][8][3];
float m_circulo[6][6][3];
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
float circulo[8][3];
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
	// printf("Ya ha salido el ya...");
	for(int i=0;i<8;i++){
	circulo[i][0]=cos(i*2*PI/8)*GRANDE;
	circulo[i][1]=sin(i*2*PI/8)*GRANDE;
	}
	
	// EL UNO Y EL DOS COSTITUYEN EL EJE  X (UNO ENFRENTE DEL OTRO)
	          
	     for(int i=0;i<8;i++){
	     
	     circulos[0][0][i][0]=circulo[i][0];
	     circulos[0][0][i][1]=circulo[i][1];
	     circulos[0][0][i][2]=-.5f;

	     m_circulo[0][0][0] = 0;
	     m_circulo[0][0][1] = 0;
	     m_circulo[0][0][2] = -.5f;
	     }
	     
	         
	         for(int i=0;i<8;i++){
	     circulos[1][0][i][0]=circulo[i][0]-.25f;
	     circulos[1][0][i][1]=circulo[i][1]-.25f;
	     circulos[1][0][i][2]=.5f;

	     m_circulo[1][0][0] = -.25f;
	     m_circulo[1][0][1] = -.25f;
	     m_circulo[1][0][2] = .5f;

	     circulos[1][1][i][0]=circulo[i][0]+.25f;
	     circulos[1][1][i][1]=circulo[i][1]+.25f;
	     circulos[1][1][i][2]=.5f;

	     m_circulo[1][1][0] = +.25f;
	     m_circulo[1][1][1] = +.25f;
	     m_circulo[1][1][2] = .5f;
	     }
	     

	     //EL 3 Y EL 4 CONSTITUYEN EL EJE Y (UNO ENFRENTE DEL OTRO)
	     
	     for(int i=0;i<8;i++){
	     circulos[2][0][i][0]=.5f;
	     circulos[2][0][i][1]=circulo[i][0]-.25f;
	     circulos[2][0][i][2]=circulo[i][1]+.25f;

	     m_circulo[2][0][0] = .5f;
	     m_circulo[2][0][1] = -.25f;
	     m_circulo[2][0][2] = .25f;

	     circulos[2][1][i][0]=.5f;
	     circulos[2][1][i][1]=circulo[i][0];
	     circulos[2][1][i][2]=circulo[i][1];

	     m_circulo[2][1][0] = .5f;
	     m_circulo[2][1][1] = 0;
	     m_circulo[2][1][2] = 0;

	     circulos[2][2][i][0]=.5f;
	     circulos[2][2][i][1]=circulo[i][0]+.25f;
	     circulos[2][2][i][2]=circulo[i][1]-.25f;

	     m_circulo[2][2][0] = .5f;
	     m_circulo[2][2][1] = +.25f;
	     m_circulo[2][2][2] = -.25f;

	     }
	     
	     
	          //System.out.println(caras);
	          
	     for(int i=0;i<8;i++){

	     circulos[3][0][i][0]=-.5f;
	     circulos[3][0][i][1]=circulo[i][0]-.25f;
	     circulos[3][0][i][2]=circulo[i][1]-.25f;

	     m_circulo[3][0][0] = -.5f;
	     m_circulo[3][0][1] = -.25f;
	     m_circulo[3][0][2] = -.25f;

	     circulos[3][1][i][0]=-.5f;
	     circulos[3][1][i][1]=circulo[i][0]+.25f;
	     circulos[3][1][i][2]=circulo[i][1]-.25f;

	     m_circulo[3][1][0] = -.5f;
	     m_circulo[3][1][1] = +.25f;
	     m_circulo[3][1][2] = -.25f;

         circulos[3][2][i][0]=-.5f;
	     circulos[3][2][i][1]=circulo[i][0]-.25f;
	     circulos[3][2][i][2]=circulo[i][1]+.25f;

	     m_circulo[3][2][0] = -.5f;
	     m_circulo[3][2][1] = -.25f;
	     m_circulo[3][2][2] = +.25f;
            
         circulos[3][3][i][0]=-.5f;
	     circulos[3][3][i][1]=circulo[i][0]+.25f;
	     circulos[3][3][i][2]=circulo[i][1]+.25f;

	     m_circulo[3][3][0] = -.5f;
	     m_circulo[3][3][1] = +.25f;
	     m_circulo[3][3][2] = +.25f;

	     }
	     
	     // EL 5 Y EL 6 CONSTITUYEN EL EJE Z (UNO ENFRENTE DEL OTRO)
	         
	         for(int i=0;i<8;i++){
	         
	     
	     circulos[4][0][i][0]=circulo[i][0]-.25f;
	     circulos[4][0][i][1]=.5f;
	     circulos[4][0][i][2]=circulo[i][1]-.25f;

	     m_circulo[4][0][0] = -.25f;
	     m_circulo[4][0][1] = .5f;
	     m_circulo[4][0][2] = -.25f;
	     
	     circulos[4][1][i][0]=circulo[i][0]+.25f;
	     circulos[4][1][i][1]=.5f;
	     circulos[4][1][i][2]=circulo[i][1]-.25f;

	     m_circulo[4][1][0] = +.25f;
	     m_circulo[4][1][1] = .5f;
	     m_circulo[4][1][2] = -.25f;

	     circulos[4][2][i][0]=circulo[i][0];
	     circulos[4][2][i][1]=.5f;
	     circulos[4][2][i][2]=circulo[i][1];

	     m_circulo[4][2][0] = 0;
	     m_circulo[4][2][1] = .5f;
	     m_circulo[4][2][2] = 0;

	     circulos[4][3][i][0]=circulo[i][0]-.25f;
	     circulos[4][3][i][1]=.5f;
	     circulos[4][3][i][2]=circulo[i][1]+.25f;

	     m_circulo[4][3][0] = -.25f;
	     m_circulo[4][3][1] = .5f;
	     m_circulo[4][3][2] = +.25f;

	     circulos[4][4][i][0]=circulo[i][0]+.25f;
	     circulos[4][4][i][1]=.5f;
	     circulos[4][4][i][2]=circulo[i][1]+.25f;

	     m_circulo[4][4][0] = +.25f;
	     m_circulo[4][4][1] = .5f;
	     m_circulo[4][4][2] = +.25f;

	     }
	     
	     
	     for(int i=0;i<8;i++){
	     
	     circulos[5][0][i][0]=circulo[i][0]-.25f;
	     circulos[5][0][i][1]=-.5f;
	     circulos[5][0][i][2]=circulo[i][1]-.25f;

	     m_circulo[5][0][0] = -.25f;
	     m_circulo[5][0][1] = -.5f;
	     m_circulo[5][0][2] = -.25f;
	     
	     circulos[5][1][i][0]=circulo[i][0]+.25f;
	     circulos[5][1][i][1]=-.5f;
	     circulos[5][1][i][2]=circulo[i][1]-.25f;

	     m_circulo[5][1][0] = +.25f;
	     m_circulo[5][1][1] = -.5f;
	     m_circulo[5][1][2] = -.25f;

	     circulos[5][2][i][0]=circulo[i][0]+.25f;
	     circulos[5][2][i][1]=-.5f;
	     circulos[5][2][i][2]=circulo[i][1];

	     m_circulo[5][2][0] = +.25f;
	     m_circulo[5][2][1] = -.5f;
	     m_circulo[5][2][2] = 0;

	     circulos[5][3][i][0]=circulo[i][0]-.25f;
	     circulos[5][3][i][1]=-.5f;
	     circulos[5][3][i][2]=circulo[i][1];

	     m_circulo[5][3][0] = -.25f;
	     m_circulo[5][3][1] = -.5f;
	     m_circulo[5][3][2] = 0;

	     circulos[5][4][i][0]=circulo[i][0]-.25f;
	     circulos[5][4][i][1]=-.5f;
	     circulos[5][4][i][2]=circulo[i][1]+.25f;

	     m_circulo[5][4][0] = -.25f;
	     m_circulo[5][4][1] = -.5f;
	     m_circulo[5][4][2] = +.25f;

	     circulos[5][5][i][0]=circulo[i][0]+.25f;
	     circulos[5][5][i][1]=-.5f;
	     circulos[5][5][i][2]=circulo[i][1]+.25f;

	     m_circulo[5][5][0] = +.25f;
	     m_circulo[5][5][1] = -.5f;
	     m_circulo[5][5][2] = +.25f;
	     
	     }
	     
	     
	     
	    
}

void on_button_click(GtkWidget *widget, const gpointer data) {
	int datas=GPOINTER_TO_INT(data);
	if ( datas == 1)
	{
		o=1;
		mov=TRUE;
	}
	if (datas == 2)
	{
		o=2;
		mov=TRUE;
	}
	if (datas == 3)
	{
		o=3;
		mov=TRUE;
	}
	if (datas == 4)
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
	if (datas == 5)
	{
		if (mov)
		mov=FALSE;
		else
			mov=TRUE;
	}
	if (datas == 6)
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
	if (datas == 7)
	{
		if (transparent)
            transparent=FALSE;
		else {
			transparent=TRUE;
			skeleton=TRUE;
		}
	}
	if (datas == 8) {
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

	float nuevo2x,nuevo2y,nuevo2z;

	float nuevo3x,nuevo3y,nuevo3z;



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
				
                        for (int j=0;j<=i;j++){
                        for (int k=0;k<8;k++){
                        nuevo2x=circulos[i][j][k][0]*cosf(teta)+circulos[i][j][k][1]*sinf(teta);
			nuevo2y=-circulos[i][j][k][0]*sinf(teta)+circulos[i][j][k][1]*cosf(teta);
			nuevo2z=circulos[i][j][k][2];
			
			circulos[i][j][k][0]=nuevo2x;
			circulos[i][j][k][1]=nuevo2y;
			circulos[i][j][k][2]=nuevo2z;
}
            nuevo3x=m_circulo[i][j][0]*cosf(teta)+m_circulo[i][j][1]*sinf(teta);
			nuevo3y=-m_circulo[i][j][0]*sinf(teta)+m_circulo[i][j][1]*cosf(teta);
			nuevo3z=m_circulo[i][j][2];

			m_circulo[i][j][0] = nuevo3x;
			m_circulo[i][j][1] = nuevo3y;
			m_circulo[i][j][2] = nuevo3z;
}
				
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
				
			for (int j=0;j<=i;j++){
                        for (int k=0;k<8;k++){
			nuevo2x=circulos[i][j][k][0]*cosf(teta)+circulos[i][j][k][2]*sinf(teta);
			nuevo2y=circulos[i][j][k][1];
			nuevo2z=-circulos[i][j][k][0]*sinf(teta)+circulos[i][j][k][2]*cosf(teta);
			
			circulos[i][j][k][0]=nuevo2x;
			circulos[i][j][k][1]=nuevo2y;
			circulos[i][j][k][2]=nuevo2z;
			}

			nuevo3x=m_circulo[i][j][0]*cosf(teta)+m_circulo[i][j][2]*sinf(teta);
			nuevo3y=m_circulo[i][j][1];
			nuevo3z=-m_circulo[i][j][0]*sinf(teta)+m_circulo[i][j][2]*cosf(teta);

			m_circulo[i][j][0] = nuevo3x;
			m_circulo[i][j][1] = nuevo3y;
			m_circulo[i][j][2] = nuevo3z;
}
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
				
			for (int j=0;j<=i;j++){
                        for (int k=0;k<8;k++){
			nuevo2x=circulos[i][j][k][0];
			nuevo2y=circulos[i][j][k][1]*cosf(teta)-circulos[i][j][k][2]*sinf(teta);
			nuevo2z=circulos[i][j][k][1]*sinf(teta)+circulos[i][j][k][2]*cosf(teta);
			
			circulos[i][j][k][0]=nuevo2x;
			circulos[i][j][k][1]=nuevo2y;
			circulos[i][j][k][2]=nuevo2z;
			}
			nuevo3x=m_circulo[i][j][0];
			nuevo3y=m_circulo[i][j][1]*cosf(teta)-m_circulo[i][j][2]*sinf(teta);
			nuevo3z=m_circulo[i][j][1]*sinf(teta)+m_circulo[i][j][2]*cosf(teta);

			m_circulo[i][j][0] = nuevo3x;
			m_circulo[i][j][1] = nuevo3y;
			m_circulo[i][j][2] = nuevo3z;
			}
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
                cairo_set_source_rgb(context,0,0,0);
	    		for (int r=0;r<iw+1;r++){
	    		cairo_move_to(context,circulos[iw][r][7][0]*(float)width/5+(float)width/3,circulos[iw][r][7][1]*(float)width/5+(float)width/3);
	    		cairo_line_to(context,circulos[iw][r][0][0]*(float)width/5+(float)width/3,circulos[iw][r][0][1]*(float)width/5+(float)width/3);
                cairo_arc (context, m_circulo[iw][r][0]*(float)width/5+(float)width/3, m_circulo[iw][r][1]*(float)width/5+(float)width/3, 0.1, 0, .1);
	    		cairo_fill (context);
	    		for(int u=0;u<7;u++){
	    			cairo_move_to(context,circulos[iw][r][u][0]*(float)width/5+(float)width/3,circulos[iw][r][u][1]*(float)width/5+(float)width/3);
	    		    cairo_line_to(context,circulos[iw][r][u+1][0]*(float)width/5+(float)width/3,circulos[iw][r][u+1][1]*(float)width/5+(float)width/3);
	    		    cairo_arc (context, m_circulo[iw][r][0]*(float)width/5+(float)width/3, m_circulo[iw][r][1]*(float)width/5+(float)width/3, 0.1, 0, .1);
	    		    cairo_fill (context);
	    		    }
	    		cairo_stroke (context);
	    		
	    		} 		
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
	    		cairo_set_source_rgb(context,0,0,0);
	    		for (int r=0;r<iw+1;r++){
	    		cairo_move_to(context,circulos[iw][r][7][0]*(float)width/5+(float)width/3,circulos[iw][r][7][1]*(float)width/5+(float)width/3);
	    		cairo_line_to(context,circulos[iw][r][0][0]*(float)width/5+(float)width/3,circulos[iw][r][0][1]*(float)width/5+(float)width/3);
	    		cairo_arc (context, m_circulo[iw][r][0]*(float)width/5+(float)width/3, m_circulo[iw][r][1]*(float)width/5+(float)width/3, 0.1, 0, .1);
	    		cairo_fill (context);
	    		for(int u=0;u<7;u++){
	    			cairo_move_to(context,circulos[iw][r][u][0]*(float)width/5+(float)width/3,circulos[iw][r][u][1]*(float)width/5+(float)width/3);
	    		    cairo_line_to(context,circulos[iw][r][u+1][0]*(float)width/5+(float)width/3,circulos[iw][r][u+1][1]*(float)width/5+(float)width/3);
	    		    cairo_arc (context, m_circulo[iw][r][0]*(float)width/5+(float)width/3, m_circulo[iw][r][1]*(float)width/5+(float)width/3, 0.1, 0, .1);
	    		    cairo_fill (context);
	    		    }
	    		cairo_stroke (context);
	    		
	    		}
	    	}

	    
    
	if (transparent) {
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

	    		cairo_set_source_rgb(context,0,0,0);
	    		for (int r=0;r<iw+1;r++){
	    		cairo_move_to(context,circulos[iw][r][7][0]*(float)width/5+(float)width/3,circulos[iw][r][7][1]*(float)width/5+(float)width/3);
	    		cairo_line_to(context,circulos[iw][r][0][0]*(float)width/5+(float)width/3,circulos[iw][r][0][1]*(float)width/5+(float)width/3);
	    		for(int u=0;u<7;u++){
	    			cairo_move_to(context,circulos[iw][r][u][0]*(float)width/5+(float)width/3,circulos[iw][r][u][1]*(float)width/5+(float)width/3);
	    		    cairo_line_to(context,circulos[iw][r][u+1][0]*(float)width/5+(float)width/3,circulos[iw][r][u+1][1]*(float)width/5+(float)width/3);
	    		    }
	    		cairo_stroke (context);
	    		
	    		}
   		
    	}
    }

	    		/*
	    		cairo_set_source_rgb(context,0,0,0);
	    		cairo_move_to(context,circulos[0][0][7][0]*(float)width/5+(float)width/3,circulos[0][0][7][1]*(float)width/5+(float)width/3);
	    		cairo_line_to(context,circulos[0][0][0][0]*(float)width/5+(float)width/3,circulos[0][0][0][1]*(float)width/5+(float)width/3);
	    		for(int u=0;u<7;u++){
                cairo_move_to(context,circulos[0][0][u][0]*(float)width/5+(float)width/3,circulos[0][0][u][1]*(float)width/5+(float)width/3);
	    		cairo_line_to(context,circulos[0][0][u+1][0]*(float)width/5+(float)width/3,circulos[0][0][u+1][1]*(float)width/5+(float)width/3);
	    	}
	    	cairo_stroke (context);
	    	*/
}

    return FALSE;
}
gint delete_event(void)
{
	gtk_main_quit ();
	return FALSE;
}
int main(int argc, char** argv) {
	



     cairo_t *context;
     GtkWidget *window;
     GtkWidget  *boton9;
     GtkButton *boton1,*boton2, *boton3, *boton4, *boton5, *boton6, *boton7, *boton8;
     GtkWidget *area ;
     GtkBox *box;
     GtkFrame *frame2;
     GtkFrame *frame1;
     GtkButtonBox *buttons;
     GtkBuilder *builder;
     GError *error = NULL;
drawed();
	gtk_init(&argc, &argv);
	
    builder = gtk_builder_new();

     if( gtk_builder_add_from_file (builder,"rubick1.glade" , &error) == 0)
    {
         printf("gtk_builder_add_from_file FAILED\n");
         return(0);
     }
    
     
     window = GTK_WIDGET (gtk_builder_get_object (builder,"window"));
     box =  GTK_BOX (gtk_builder_get_object (builder,"box"));
     frame2 = GTK_FRAME (gtk_builder_get_object (builder,"frame2"));
     buttons = GTK_BUTTON_BOX (gtk_builder_get_object (builder,"buttons"));
     frame1 = GTK_FRAME (gtk_builder_get_object (builder,"frame1"));
     boton1 = GTK_BUTTON (gtk_builder_get_object (builder,"rotx"));
     boton2 = GTK_BUTTON (gtk_builder_get_object (builder,"roty"));
     boton3 = GTK_BUTTON (gtk_builder_get_object (builder,"rotz"));
     boton4 = GTK_BUTTON (gtk_builder_get_object (builder,"velocity"));
     boton5 = GTK_BUTTON (gtk_builder_get_object (builder,"stop"));
     boton6 = GTK_BUTTON (gtk_builder_get_object (builder,"skeleton"));
     boton7 = GTK_BUTTON (gtk_builder_get_object (builder,"transparent"));
     boton8 = GTK_BUTTON (gtk_builder_get_object (builder,"dyed"));
     boton9 = GTK_WIDGET (gtk_builder_get_object (builder,"quit"));
     
     area = GTK_WIDGET(gtk_builder_get_object (builder,"drawing_area"));
     
    
    g_signal_connect (boton1, "clicked", G_CALLBACK(on_button_click),(gpointer)1);
	
	g_signal_connect (boton2, "clicked", G_CALLBACK(on_button_click),(gpointer)2);

	g_signal_connect (boton3, "clicked", G_CALLBACK(on_button_click),(gpointer)3);
	
    g_signal_connect (boton4, "clicked", G_CALLBACK(on_button_click),(gpointer)4);

    g_signal_connect (boton5, "clicked", G_CALLBACK(on_button_click),(gpointer)5);
		
  	g_signal_connect (boton6, "clicked", G_CALLBACK(on_button_click),(gpointer)6);

	g_signal_connect (boton7, "clicked", G_CALLBACK(on_button_click),(gpointer)7);

    g_signal_connect (boton8, "clicked", G_CALLBACK(on_button_click),(gpointer)8);
    
    g_signal_connect (boton9, "clicked", G_CALLBACK(gtk_main_quit), NULL);
    
	
	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
	
	

	

    g_signal_connect (G_OBJECT(area),"draw", G_CALLBACK (draw), NULL);
    
   

    g_timeout_add(90, (GSourceFunc)move, window);

    gtk_window_set_title(GTK_WINDOW(window), "THE LUIS FEDERICO'S CUBE");
	
	
	
    
    
    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
