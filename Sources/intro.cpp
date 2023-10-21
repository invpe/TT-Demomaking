#define WIN32_LEAN_AND_MEAN

//y point for the application.
//

#include <windows.h>

#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <GL/glaux.h>

#include <stdio.h>
#include  <stdlib.h>
// le decoder de gif
#include "gifdecoder/GifDecoder.h"

#include "lib/minifmod.h"

// les metaballs
#include "metaballs/metalib.h"

// la zik
#include "essai/softwrld.h"

// le Chat
#include "essai/chat.h"

 



#include "essai/flara.h"
#include "essai/vein.h"
#include "essai/lava.h"


#include "struktury.h"



// la fonte
#include "essai/fnt3.h"

 


// le code
#include "3d_intro.h"
#include "normal.h"


//
float ct2=0;
#define USEMEMLOAD
#define USEMEMLOADRESOURCE
#define USEFMOD TRUE
// Return a random number

#define RAND(min, max) rand()%((max)+1-(min))+(min)




float delt;
float c1=0;
float c2=255;
int drawed=0;
float c3=255;


float d1=1;
float d2=1;
float d3=1;



float skala;
float fct=0;float fct2=0;
int y;

// les metaballs
float R1=0.1f;
float R2=0.15f;
float R3=0.11f;
float R4=0.09f;

float xb1 =-0.3f;
float yb1 = 0;
float zb1 = 0;
float xb2 = 0.3f;
float yb2 = 0;
float zb2 = 0;
float xb3,yb3,zb3;
float xb4,yb4,zb4;



void BAR(float x,float y);
TITAN();
void BARS();
IPE();
void RAZOR();

struct t{
int y;
int go;
int burn;
}tekst[10];

//FPS
int total_fps=0;
int frames = 0;
GLdouble FPS = 0;
GLdouble Time1;
GLdouble Time2;
GLdouble DiffTime;
GLdouble StartTime;
char efpe[256];

float eX=100;

int cct;
int loop;
int loop2;


inline GLdouble TimerGetTime()
{
  __int64 time;                                  // 'time' Will Hold A 64 Bit Integer
  if (timer.performance_timer)           // Are We Using The Performance Timer?
  {
    QueryPerformanceCounter((LARGE_INTEGER *) &time); // Current Performance Time
    // Return The Time Elapsed since TimerInit was called
  //  return ( (GLdouble) ( time - timer.performance_timer_start) * timer.resolution)*1000.0f;
  }
  else
  {
    // Return The Time Elapsed since TimerInit was called
//    return ( (GLdouble) ( timeGetTime() - timer.mm_timer_start) * timer.resolution)*1000.0f;
  }
}















void force(float x1,float y1,float z1,float x2,float y2,float z2,float *dx,float *dy,float *dz)
{
#define FORCE 40
  float r;
  
  r=(x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) + (z2-z1)*(z2-z1);
  if(r==0.0) r=99999; else r=1/r;

  *dx=(x1-x2)*r/FORCE;
  *dy=(y1-y2)*r/FORCE;
  *dz=(z1-z2)*r/FORCE;
  
}
/*3=Nb boule*/
float TEMP[3*4][128];

float pos_plan=40.0f,pos_barre=0.0f,pos_rubber=+30.0f,pos_meta=11.0f;
// les objets
GLuint		GL_Glace,GL_Potdefleur,GL_Oeuf,GL_Carotte,GL_Etoile;
// les textures
GLuint		T_Fonte,T_Flare,T_Vein,T_Lava;
unsigned char	*tfonte,*tfonte2,*flare1_1,*flare2_2,*flare1_2,*flare1,*flare2,*vein1,*vein2,*lava1_2,*lava2_2;
// Pour la zik
int		ord = 0, row = 0;

Cylindre	*cyl,*tunnel;
Plan		*pl;
float		deform_cyl=0.0f,deform_cyl_val=0.005f,deform_cyl_maxval=1.5f;
float		deform_cyl2=0.0f,deform_cyl_val2=0.008f,deform_cyl_maxval2=4.0f;
float		deform_cyl3=0.0f,deform_cyl_val3=0.005f,deform_cyl_maxval3=4.0f;

// couleur
float		c_fond[3]={0.390625f, 0.390625f, 0.5f};
float		c_noir[3]={0.0f, 0.0f, 0.0f};
float		c_calcul[3]={0.0f, 0.0f, 0.0f};

float		depx = -310,depz = -320,etoilex=-90.8f,poschat=-1.0f;
float		posx_plan = -4.0f,poscarot1 = 200.0f,poscarot2 = 350.0f,poscarot3 = 500.0f;

int			nb_coul=120,nb_coulcal=0;;
int			nbt=1;
int			nbfaces=0;
HDC			hDC=NULL;		// Private GDI Device Context
HGLRC		hRC=NULL;		// Permanent Rendering Context
HWND		hWnd=NULL;		// Holds Our Window Handle
HINSTANCE	hInstance;		// Holds The Instance Of The Application
bool		keys[256];			// Array Used For The Keyboard Routine
bool		active=TRUE;		// Window Active Flag Set To TRUE By Default
float		X=1.0f;

bool		fullscreen = true;
char		bpp = 32;
int			res_x = 640,res_y = 480;
char		quality = 1;
int			max_tab=0;


void fNEG2(float **T,int N2)
{
 static int    off;
 static int    i,j,k,N;
 static float  x,y,z,dt,t;
 static float  dz1,dy1,dx1,r1;
 static float  dz2,dy2,dx2,r2;
 static float  dz3,dy3,dx3,r3;
 static float  dz4,dy4,dx4,r4;
  
 N=1<<N2;
 /*
 size=1<<N;
 
 dec=32/size;

 
 i1=(int)(16*(xb1+1));
 j1=(int)(16*(yb1+1));
 k1=(int)(16*(zb1+1));

 printf("%d %d %d %d\n",i1,j1,k1,dec);

 off1=64*j1+i1;
 
 for(k=0;k<size;k++)
 {
   for(j=0;j<size;j++)
   {
	   l=0;
	   for(i=0;i<size;i++)
	   {
	     T[k][i+(j*1<<N)]=BALL[k1][off1 + l];
	     l+=dec;
	   }
	   off1+=64*dec;
   }
   off1=64*j1+i1;
   k1+=dec;
 }
 */

     dt=2.0f/(float)(N-1);
     t=-1;
     for(k=0;k<N;k++)
       {
         TEMP[0][k]=(t-xb1)*(t-xb1);
	 TEMP[1][k]=(t-yb1)*(t-yb1);
	 TEMP[2][k]=(t-zb1)*(t-zb1);

	 TEMP[3][k]=(t-xb2)*(t-xb2);
	 TEMP[4][k]=(t-yb2)*(t-yb2);
	 TEMP[5][k]=(t-zb2)*(t-zb2);

	 TEMP[6][k]=(t-xb3)*(t-xb3);
	 TEMP[7][k]=(t-yb3)*(t-yb3);
	 TEMP[8][k]=(t-zb3)*(t-zb3);

	 TEMP[9 ][k]=(t-xb4)*(t-xb4);
	 TEMP[10][k]=(t-yb4)*(t-yb4);
	 TEMP[11][k]=(t-zb4)*(t-zb4);
	 
         t+=dt;
       }
 /*
	
     dt=2.0/(float)(N-1);
     x=-1;y=-1;z=-1;
     for(k=0;k<N;k++)
       {
         y=-1;
	 dz1=(z-zb1)*(z-zb1);
	 dz2=(z-zb2)*(z-zb2);
	 dz3=(z-zb3)*(z-zb3);
	 for(j=0;(j<N);j++)
	   {
             off=j<<N2;
             x=-1;
	     dy1=(y-yb1)*(y-yb1);
	     dy2=(y-yb2)*(y-yb2);
	     dy3=(y-yb3)*(y-yb3);
             for(i=0;i<N;i++)
	       {
		 dx1=(x-xb1)*(x-xb1);
		 dx2=(x-xb2)*(x-xb2);
		 dx3=(x-xb3)*(x-xb3);
		 r1=dx1+dy1+dz1;
		 if(r1==0.0) r1=999999;
		 else r1=1/(r1*r1*r1*r1);
		 r2=dx2+dy2+dz2;
		 if(r2==0.0) r2=999999;
		 else r2=1/(r2*r2*r2*r2);
		 r3=dx3+dy3+dz3;
		 if(r3==0.0) r3=999999;
		 else r3=1/(r3*r3*r3*r3);
		 T[k][off+i]=r1+r2-r3;                 
                 x+=dt;
	       }
             y+=dt;
	   }
         z+=dt;
       }
 */


     for(j=0;j<N;j++)
     {
	     for(i=0;i<N;i++)
	     {
		     T[0  ][j*(1<<N2)+i    ]=0;
		     T[N-1][j*(1<<N2)+i    ]=0;
		     T[  j][i*(1<<N2)      ]=0;
		     T[  j][i*(1<<N2)+N-1  ]=0;
		     T[  j][i              ]=0;
		     T[  j][(N-1)*(1<<N2)+i]=0;
	     }
     }

     for(k=1;k<N-1;k++)
       {
         
	 dz1=TEMP[2][k];
	 dz2=TEMP[5][k];
	 dz3=TEMP[8][k];
	 dz4=TEMP[11][k];
	 for(j=1;(j<N-1);j++)
	   {
             off=j<<N2;
             dy1=TEMP[1][j];
	     dy2=TEMP[4][j];
	     dy3=TEMP[7][j];	     
             dy4=TEMP[10][j];
             
             for(i=1;i<N-1;i++)
	       {
		  dx1=TEMP[0][i];
	          dx2=TEMP[3][i];
	          dx3=TEMP[6][i];
                  dx4=TEMP[9][i];

		  r1=dx1+dy1+dz1;
		  if(r1==0.0) r1=999999;
		  else {t=r1*r1;r1=1/(t*t);}

		  r2=dx2+dy2+dz2;
		  if(r2==0.0) r2=999999;
		  else {t=r2*r2;r2=1/(t*t);}

		  r3=dx3+dy3+dz3;
		  if(r3==0.0) r3=999999;
		  else {t=r3*r3;r3=1/(t*t);}

		  r4=dx4+dy4+dz4;
		  if(r4==0.0) r4=999999;
		  else {t=r4*r4;r4=1/(t*t);}

		  T[k][off+i]=0.7f*r1 + 0.8f*r2 - 0.6f*r3 - 0.6f*r4;                 
		  /*
                  if(i==0) T[k][off+i]=0;
		  if(j==0) T[k][off+i]=0;
		  if(k==0) T[k][off+i]=0;
		  if(i==N-1) T[k][off+i]=0;
		  if(j==N-1) T[k][off+i]=0;
		  if(k==N-1) T[k][off+i]=0;
		  */
	       }
             
	   }
         
       }
}


#ifndef USEMEMLOAD
#else

typedef struct 
{
	int length;
	int pos;
	void *data;
} MEMFILE;


unsigned int memopen(char *name)
{
	MEMFILE *memfile;

	memfile = (MEMFILE *)calloc(sizeof(MEMFILE),1);

#ifndef USEMEMLOADRESOURCE
	{	// load an external file and read it
		FILE *fp;
		fp = fopen(name, "rb");
		if (fp)
		{
			fseek(fp, 0, SEEK_END);
			memfile->length = ftell(fp);
			memfile->data = calloc(memfile->length,1);
			memfile->pos = 0;

			fseek(fp, 0, SEEK_SET);
			fread(memfile->data, 1, memfile->length, fp);
			fclose(fp);
		}
	}
#else
	{	// hey look some load from resource code!
		/*HRSRC		rec;
		HGLOBAL		handle;

		rec = FindResource(NULL, name, RT_RCDATA);
		handle = LoadResource(NULL, rec);
		
		memfile->data = LockResource(handle);
		memfile->length = SizeofResource(NULL, rec);
		memfile->pos = 0;*/

		memfile->data = (void *)music;
		memfile->length = MUSIC_LEN;
		memfile->pos = 0;

	}
#endif
	return (unsigned int)memfile;
}

void memclose(unsigned int handle)
{
	MEMFILE *memfile = (MEMFILE *)handle;

#ifndef USEMEMLOADRESOURCE
	free(memfile->data);			// dont free it if it was initialized with LockResource
#endif

	free(memfile);
}

int memread(void *buffer, int size, unsigned int handle)
{
	MEMFILE *memfile = (MEMFILE *)handle;

	if (memfile->pos + size >= memfile->length)
		size = memfile->length - memfile->pos;

	memcpy(buffer, (char *)memfile->data+memfile->pos, size);
	memfile->pos += size;
	
	return size;
}

void memseek(unsigned int handle, int pos, signed char mode)
{
	MEMFILE *memfile = (MEMFILE *)handle;

	if (mode == SEEK_SET) 
		memfile->pos = pos;
	else if (mode == SEEK_CUR) 
		memfile->pos += pos;
	else if (mode == SEEK_END)
		memfile->pos = memfile->length + pos;

	if (memfile->pos > memfile->length)
		memfile->pos = memfile->length;
}

int memtell(unsigned int handle)
{
	MEMFILE *memfile = (MEMFILE *)handle;

	return memfile->pos;
}
#endif


void Affiche_texte(char *texte,long taille,long x,long y, GLuint Texture,float rotation)
{
	float val = 0.063f,pos;
	float depx,espace,depy,posx,posy;

	depx = 1.1f / ((float)640 / (float)taille);
	espace = depx - 0.015f;
	depy = 0.73f / ((float)480 / (float)taille);
	posx = ((float)x / (float)640) - 0.5f;
	posy = ((float)y / (float)480) - 0.355f;
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,Texture);
	//glDisable(GL_DEPTH_TEST);
	glLoadIdentity();	
	for(long i = 0;texte[i] != '\n';i++)
	{glRotatef(rotation*0.2,0,0,1);
	
			if (texte[i] >= 'a' && texte[i] <= 'h')
		{
			glBegin(GL_QUADS);
			pos = float(texte[i] - 'a') * val;
			glTexCoord2f(pos,1.0f - val);		glVertex3f((i * espace) + posx,posy - depy,-1.0f);
			glTexCoord2f(pos + val,1.0f - val);	glVertex3f((i * espace) + posx + depx,posy - depy,-1.0f);
			glTexCoord2f(pos + val,1.0f);		glVertex3f((i * espace) + posx + depx,posy,-1.0f);
			glTexCoord2f(pos,1.0f);				glVertex3f((i * espace) + posx,posy,-1.0f);
			glEnd();		
		}
		else if (texte[i] >= 'i' && texte[i] <= 'p')
		{
			glBegin(GL_QUADS);
			pos = float(texte[i] - 'i') * val;
			glTexCoord2f(pos,1.0f - (2 * val));			glVertex3f((i * espace) + posx,posy - depy,-1.0f);
			glTexCoord2f(pos + val,1.0f -  (2 * val));	glVertex3f((i * espace) + posx + depx,posy - depy,-1.0f);
			glTexCoord2f(pos + val,1.0f - val);			glVertex3f((i * espace) + posx + depx,posy,-1.0f);
			glTexCoord2f(pos,1.0f - val);				glVertex3f((i * espace) + posx,posy,-1.0f);
			glEnd();		
		}
		else if (texte[i] >= 'q' && texte[i] <= 'x')
		{
			glBegin(GL_QUADS);
			pos = float(texte[i] - 'q') * val;
			glTexCoord2f(pos,1.0f - (3 * val));			glVertex3f((i * espace) + posx,posy - depy,-1.0f);
			glTexCoord2f(pos + val,1.0f -  (3 * val));	glVertex3f((i * espace) + posx + depx,posy - depy,-1.0f);
			glTexCoord2f(pos + val,1.0f - (2 * val));	glVertex3f((i * espace) + posx + depx,posy,-1.0f);
			glTexCoord2f(pos,1.0f - (2 * val));			glVertex3f((i * espace) + posx,posy,-1.0f);
			glEnd();		
		}
		else if (texte[i] >= 'y' && texte[i] <= 'z')
		{
			glBegin(GL_QUADS);
			pos = float(texte[i] - 'y') * val;
			glTexCoord2f(pos,1.0f - (4 * val));			glVertex3f((i * espace) + posx,posy - depy,-1.0f);
			glTexCoord2f(pos + val,1.0f -  (4 * val));	glVertex3f((i * espace) + posx + depx,posy - depy,-1.0f);
			glTexCoord2f(pos + val,1.0f - (3 * val));	glVertex3f((i * espace) + posx + depx,posy,-1.0f);
			glTexCoord2f(pos,1.0f - (3 * val));			glVertex3f((i * espace) + posx,posy,-1.0f);
			glEnd();		
		}
		else if (texte[i] == '2')
		{
			glBegin(GL_QUADS);
			pos = 2 * val;
			glTexCoord2f(pos,1.0f - (4 * val));			glVertex3f((i * espace) + posx,posy - depy,-1.0f);
			glTexCoord2f(pos + val,1.0f -  (4 * val));	glVertex3f((i * espace) + posx + depx,posy - depy,-1.0f);
			glTexCoord2f(pos + val,1.0f - (3 * val));	glVertex3f((i * espace) + posx + depx,posy,-1.0f);
			glTexCoord2f(pos,1.0f - (3 * val));			glVertex3f((i * espace) + posx,posy,-1.0f);
			glEnd();		
		}
		else if (texte[i] == '/')
		{
			glBegin(GL_QUADS);
			pos = 3 * val;
			glTexCoord2f(pos,1.0f - (4 * val));			glVertex3f((i * espace) + posx,posy - depy,-1.0f);
			glTexCoord2f(pos + val,1.0f -  (4 * val));	glVertex3f((i * espace) + posx + depx,posy - depy,-1.0f);
			glTexCoord2f(pos + val,1.0f - (3 * val));	glVertex3f((i * espace) + posx + depx,posy,-1.0f);
			glTexCoord2f(pos,1.0f - (3 * val));			glVertex3f((i * espace) + posx,posy,-1.0f);
			glEnd();		
		}
		else if (texte[i] == '.')
		{
			glBegin(GL_QUADS);
			pos = 4 * val;
			glTexCoord2f(pos,1.0f - (4 * val));			glVertex3f((i * espace) + posx,posy - depy,-1.0f);
			glTexCoord2f(pos + val,1.0f -  (4 * val));	glVertex3f((i * espace) + posx + depx,posy - depy,-1.0f);
			glTexCoord2f(pos + val,1.0f - (3 * val));	glVertex3f((i * espace) + posx + depx,posy,-1.0f);
			glTexCoord2f(pos,1.0f - (3 * val));			glVertex3f((i * espace) + posx,posy,-1.0f);
			glEnd();		
		}
		else if (texte[i] == ':')
		{
			glBegin(GL_QUADS);
			pos = 5 * val;
			glTexCoord2f(pos,1.0f - (4 * val));			glVertex3f((i * espace) + posx,posy - depy,-1.0f);
			glTexCoord2f(pos + val,1.0f -  (4 * val));	glVertex3f((i * espace) + posx + depx,posy - depy,-1.0f);
			glTexCoord2f(pos + val,1.0f - (3 * val));	glVertex3f((i * espace) + posx + depx,posy,-1.0f);
			glTexCoord2f(pos,1.0f - (3 * val));			glVertex3f((i * espace) + posx,posy,-1.0f);
			glEnd();		
		}
		else if (texte[i] == '-')
		{
			glBegin(GL_QUADS);
			pos = 6 * val;
			glTexCoord2f(pos,1.0f - (4 * val));			glVertex3f((i * espace) + posx,posy - depy,-1.0f);
			glTexCoord2f(pos + val,1.0f -  (4 * val));	glVertex3f((i * espace) + posx + depx,posy - depy,-1.0f);
			glTexCoord2f(pos + val,1.0f - (3 * val));	glVertex3f((i * espace) + posx + depx,posy,-1.0f);
			glTexCoord2f(pos,1.0f - (3 * val));			glVertex3f((i * espace) + posx,posy,-1.0f);
			glEnd();		
		}
	}
	glDisable(GL_TEXTURE_2D);
//	glEnable(GL_DEPTH_TEST);
}




/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////              O P E N G L   H E R E                  ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	// Declaration For WndProc

GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize And Initialize The GL Window
{
	if (height==0)										// Prevent A Divide By Zero By
	{
		height=1;										// Making Height Equal One
	}

	glViewport(0,0,width,height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	//gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);
	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,1.0f,500.0f);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}

int InitGL(GLvoid)										// All Setup For OpenGL Goes Here
{
	GLfloat		L0dif[]= { 1.0f,1.0f,1.0f};
	GLfloat		L0spe[]= { 1.0f,1.0f,1.0f};
 
	glEnable(GL_TEXTURE_2D);							// Enable Texture Mapping
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(c_noir[0],c_noir[1],c_noir[2], 0.0f);	// Background
	//glClearDepth(11110.5f);									// Depth Buffer Setup
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);

  
 

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_FASTEST);	// Really Nice Perspective Calculations

GLfloat fogColor[4]= {0.190625f, 0.040625f, 0.0f, 1.0f};		// Fog Color

glFogi(GL_FOG_MODE, GL_LINEAR);		// Fog Mode
glFogfv(GL_FOG_COLOR, fogColor);			// Set Fog Color
glFogf(GL_FOG_DENSITY, 0.1f);				// How Dense Will The Fog Be
glHint(GL_FOG_HINT, GL_DONT_CARE);			// Fog Hint Value
glFogf(GL_FOG_START, -150.0f);				// Fog Start Depth
glFogf(GL_FOG_END, 515.0f);				// Fog End Depth
glEnable(GL_FOG);					// Enables GL_FOG



int rr=0;int dd=0;int ddd=0;int ccc=0;
for (loop=0; loop<num; loop++)
	{dd++;
ccc++;



rr=RAND(1,3);
point[loop].txt=rr;
star[loop].txt=rr;

		point[loop].angle=0.0f;
		point[loop].dist=(float(loop)/num)*5.0f;
		point[loop].r=rand()%256;
		point[loop].g=rand()%256;
		point[loop].b=rand()%256;



		flame[loop].angle=0.0f;
		flame[loop].dist=(float(loop)/num)*5.0f;
		flame[loop].r=rand()%256;
		flame[loop].g=rand()%256;
		flame[loop].b=rand()%256;


		star[loop].angle=0.0f;
		star[loop].dist=(float(loop)/num)*5.0f;
		star[loop].r=rand()%256;
		star[loop].g=rand()%256;
		star[loop].b=rand()%256;
		star[loop].scale=RAND(1,10)*0.2;

		flame[loop].angle=0.0f;
		flame[loop].dist=(float(loop)/num)*5.0f;
		flame[loop].r=rand()%256;
		flame[loop].g=rand()%256;
		flame[loop].b=rand()%256;



flame[loop].x=rand()%256;
flame[loop].y=rand()%256;
flame[loop].z=rand()%256;

point[loop].x=rand()%256;
point[loop].y=rand()%256;
point[loop].z=rand()%256;
point[loop].ct=rand()%360;
star[loop].x=rand()%256;
star[loop].y=rand()%256;

flame[loop].x=ccc*3.0;

if(dd>40){dd=0;ddd+=3;ccc=0;
}




point[loop].z=RAND(1,100)*-1;
//star[loop].z=0;

	}


	//glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
/*
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,L0dif);
	glLightfv(GL_LIGHT0,GL_SPECULAR,L0spe);
*/
/*
//	GLfloat mat_specular0[] = { 1.0, 1.0, 1.0, 1.0 };
//	GLfloat mat_shininess0[] = { 100.0 };
	GLfloat light_position0[] = { 0.0, +10.0, 0.0, 0.0 };
	GLfloat light_ambient0[] = { 1.0, 1.0, 1.0, 1.0};
	GLfloat light_specular0[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_diffuse0[] = { 1.0, 1.0, 1.0, 1.0 };

	GLfloat light_position1[] = { -10.0, 10.0, +50.0, 0.0 };
	GLfloat light_ambient1[] = { 1.0, 0.0, 0.0, 1.0};
	GLfloat light_specular1[] = { 1.0, 0.0, 0.0, 1.0 };
	GLfloat light_diffuse1[] = { 0.5, 0.5, 0.5, 1.0 };


//	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

   	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse0);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position0);

	glEnable(GL_LIGHT1);

   	glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient1);
	glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse1);
	glLightfv(GL_LIGHT1, GL_POSITION, light_position1);
*/

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	return TRUE;										// Initialization Went OK
}




GLvoid KillGLWindow(GLvoid)								// Properly Kill The Window
{
	if (fullscreen)										// Are We In Fullscreen Mode?
	{
		ChangeDisplaySettings(NULL,0);					// If So Switch Back To The Desktop
		ShowCursor(TRUE);								// Show Mouse Pointer
	}

	if (hRC)											// Do We Have A Rendering Context?
	{
		if (!wglMakeCurrent(NULL,NULL))					// Are We Able To Release The DC And RC Contexts?
		{
//			MessageBox(NULL,"Release Of DC And RC Failed.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		}

		if (!wglDeleteContext(hRC))						// Are We Able To Delete The RC?
		{
//			MessageBox(NULL,"Release Rendering Context Failed.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		}
		hRC=NULL;										// Set RC To NULL
	}

	if (hDC && !ReleaseDC(hWnd,hDC))					// Are We Able To Release The DC
	{
//		MessageBox(NULL,"Release Device Context Failed.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		hDC=NULL;										// Set DC To NULL
	}

	if (hWnd && !DestroyWindow(hWnd))					// Are We Able To Destroy The Window?
	{
//		MessageBox(NULL,"Could Not Release hWnd.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		hWnd=NULL;										// Set hWnd To NULL
	}

	if (!UnregisterClass("OpenGL",hInstance))			// Are We Able To Unregister Class
	{
//		MessageBox(NULL,"Could Not Unregister Class.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		hInstance=NULL;									// Set hInstance To NULL
	}
}

/*	This Code Creates Our OpenGL Window.  Parameters Are:					*
 *	title			- Title To Appear At The Top Of The Window				*
 *	width			- Width Of The GL Window Or Fullscreen Mode				*
 *	height			- Height Of The GL Window Or Fullscreen Mode			*
 *	bits			- Number Of Bits To Use For Color (8/16/24/32)			*
 *	fullscreenflag	- Use Fullscreen Mode (TRUE) Or Windowed Mode (FALSE)	*/
 
BOOL CreateGLWindow(char* title, int width, int height, int bits, bool fullscreenflag)
{
	GLuint		PixelFormat;			// Holds The Results After Searching For A Match
	WNDCLASS	wc;						// Windows Class Structure
	DWORD		dwExStyle;				// Window Extended Style
	DWORD		dwStyle;				// Window Style
	RECT		WindowRect;				// Grabs Rectangle Upper Left / Lower Right Values
	WindowRect.left=(long)0;			// Set Left Value To 0
	WindowRect.right=(long)width;		// Set Right Value To Requested Width
	WindowRect.top=(long)0;				// Set Top Value To 0
	WindowRect.bottom=(long)height;		// Set Bottom Value To Requested Height

	fullscreen=fullscreenflag;			// Set The Global Fullscreen Flag

	hInstance			= GetModuleHandle(NULL);				// Grab An Instance For Our Window
	wc.style			= CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	// Redraw On Size, And Own DC For Window.
	wc.lpfnWndProc		= (WNDPROC) WndProc;					// WndProc Handles Messages
	wc.cbClsExtra		= 0;									// No Extra Window Data
	wc.cbWndExtra		= 0;									// No Extra Window Data
	wc.hInstance		= hInstance;							// Set The Instance
	wc.hIcon			=  LoadIcon(NULL,MAKEINTRESOURCE(1));
//	wc.hIconSm =LoadIcon(NULL,MAKEINTRESOURCE(1));


	wc.hCursor			= LoadCursor(NULL, IDC_ARROW);			// Load The Arrow Pointer
	wc.hbrBackground	= NULL;									// No Background Required For GL
	wc.lpszMenuName		= NULL;									// We Don't Want A Menu
	wc.lpszClassName	= "OpenGL";								// Set The Class Name

	if (!RegisterClass(&wc))									// Attempt To Register The Window Class
	{
		//MessageBox(NULL,"Failed To Register The Window Class.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;											// Return FALSE
	}
	
	if (fullscreen)												// Attempt Fullscreen Mode?
	{
		DEVMODE dmScreenSettings;								// Device Mode
		memset(&dmScreenSettings,0,sizeof(dmScreenSettings));	// Makes Sure Memory's Cleared
		dmScreenSettings.dmSize=sizeof(dmScreenSettings);		// Size Of The Devmode Structure
		dmScreenSettings.dmPelsWidth	= width;				// Selected Screen Width
		dmScreenSettings.dmPelsHeight	= height;				// Selected Screen Height
		dmScreenSettings.dmBitsPerPel	= bits;					// Selected Bits Per Pixel
		dmScreenSettings.dmFields=DM_BITSPERPEL|DM_PELSWIDTH|DM_PELSHEIGHT;

		// Try To Set Selected Mode And Get Results.  NOTE: CDS_FULLSCREEN Gets Rid Of Start Bar.
		if (ChangeDisplaySettings(&dmScreenSettings,CDS_FULLSCREEN)!=DISP_CHANGE_SUCCESSFUL)
		{
/*			// If The Mode Fails, Offer Two Options.  Quit Or Use Windowed Mode.
			if (MessageBox(NULL,"The Requested Fullscreen Mode Is Not Supported By\nYour Video Card. Use Windowed Mode Instead?","Just for fun",MB_YESNO|MB_ICONEXCLAMATION)==IDYES)
			{
				fullscreen=FALSE;		// Windowed Mode Selected.  Fullscreen = FALSE
			}
			else
			{
				// Pop Up A Message Box Letting User Know The Program Is Closing.
				MessageBox(NULL,"Program Will Now Close.","ERROR",MB_OK|MB_ICONSTOP);
				return FALSE;									// Return FALSE
			}
*/		}
	}

	if (fullscreen)												// Are We Still In Fullscreen Mode?
	{
		dwExStyle=WS_EX_APPWINDOW;								// Window Extended Style
		dwStyle=WS_POPUP;										// Windows Style
		ShowCursor(FALSE);										// Hide Mouse Pointer
	}
	else
	{
		dwExStyle=WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;			// Window Extended Style
		dwStyle=WS_OVERLAPPEDWINDOW;							// Windows Style
	}

	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);		// Adjust Window To True Requested Size

	// Create The Window
	if (!(hWnd=CreateWindowEx(	dwExStyle,							// Extended Style For The Window
								"OpenGL",							// Class Name
								title,								// Window Title
								dwStyle |							// Defined Window Style
								WS_CLIPSIBLINGS |					// Required Window Style
								WS_CLIPCHILDREN,					// Required Window Style
								0, 0,								// Window Position
								WindowRect.right-WindowRect.left,	// Calculate Window Width
								WindowRect.bottom-WindowRect.top,	// Calculate Window Height
								NULL,								// No Parent Window
								NULL,								// No Menu
								hInstance,							// Instance
								NULL)))								// Dont Pass Anything To WM_CREATE
	{
		KillGLWindow();								// Reset The Display
		//MessageBox(NULL,"Window Creation Error.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	static	PIXELFORMATDESCRIPTOR pfd=				// pfd Tells Windows How We Want Things To Be
	{
		sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
		1,											// Version Number
		PFD_DRAW_TO_WINDOW |						// Format Must Support Window
		PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
		PFD_DOUBLEBUFFER,							// Must Support Double Buffering
		PFD_TYPE_RGBA,								// Request An RGBA Format
		bits,										// Select Our Color Depth
		0, 0, 0, 0, 0, 0,							// Color Bits Ignored
		0,											// No Alpha Buffer
		0,											// Shift Bit Ignored
		0,											// No Accumulation Buffer
		0, 0, 0, 0,									// Accumulation Bits Ignored
		16,											// 16Bit Z-Buffer (Depth Buffer)  
		0,											// No Stencil Buffer
		0,											// No Auxiliary Buffer
		PFD_MAIN_PLANE,								// Main Drawing Layer
		0,											// Reserved
		0, 0, 0										// Layer Masks Ignored
	};
	
	if (!(hDC=GetDC(hWnd)))							// Did We Get A Device Context?
	{
		KillGLWindow();								// Reset The Display
		//MessageBox(NULL,"Can't Create A GL Device Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(PixelFormat=ChoosePixelFormat(hDC,&pfd)))	// Did Windows Find A Matching Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		//MessageBox(NULL,"Can't Find A Suitable PixelFormat.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if(!SetPixelFormat(hDC,PixelFormat,&pfd))		// Are We Able To Set The Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		//MessageBox(NULL,"Can't Set The PixelFormat.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(hRC=wglCreateContext(hDC)))				// Are We Able To Get A Rendering Context?
	{
		KillGLWindow();								// Reset The Display
		//MessageBox(NULL,"Can't Create A GL Rendering Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if(!wglMakeCurrent(hDC,hRC))					// Try To Activate The Rendering Context
	{
		KillGLWindow();								// Reset The Display
		//MessageBox(NULL,"Can't Activate The GL Rendering Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	ShowWindow(hWnd,SW_SHOW);						// Show The Window
	SetForegroundWindow(hWnd);						// Slightly Higher Priority
	SetFocus(hWnd);									// Sets Keyboard Focus To The Window
	ReSizeGLScene(width, height);					// Set Up Our Perspective GL Screen

	if (!InitGL())									// Initialize Our Newly Created GL Window
	{
		KillGLWindow();								// Reset The Display
		//MessageBox(NULL,"Initialization Failed.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	return TRUE;									// Success
}

// CREE un obj
// nbp: nb de points
// nbf: nb de faces
// p  : liste des points
// f  : liste des faces
// UV : liste des UV
// retourn Obj: Object opengl a creer!
GLuint create_object(int nbp,int nbf,double *p,unsigned long *f,float *UV)
{
	GLuint				Obj;
	int					i=0,j=0;
	int					point1,point2,point3;
	float				x,y,z;
	float				u,v;
	
	float				min_x=50000.0f,max_x=-50000.0f,min_y=50000.0f,max_y=-50000.0f,min_z=50000.0f,max_z=-50000.0f;
	float				val_x,val_y,val_z;

	// on cherche a centrer l'objet
	for (i=0;i<nbp;i++)
	{
		x=(float) (p[i*3+0]);
		if (x<min_x)		{			min_x=x;		}
		if (x>max_x)		{			max_x=x;		}

		y=(float) (p[i*3+1]);
		if (y<min_y)		{			min_y=y;		}
		if (y>max_y)		{			max_y=y;		}
				
		z=(float) (p[i*3+2]);
		if (z<min_z)		{			min_z=z;		}
		if (z>max_z)		{			max_z=z;		}
	}
	
	val_x=-(((max_x-min_x)/2)+min_x);
	val_y=-(((max_y-min_y)/2)+min_y);
	val_z=-(((max_z-min_z)/2)+min_z);

		
	Obj=glGenLists(1);
	glNewList(Obj,GL_COMPILE);

	for (i=0;i<nbf;i++)
	{
		glBegin(GL_TRIANGLES);

		point1=f[3*i+0];
		point2=f[3*i+1];
		point3=f[3*i+2];

		// POINT 1
		x=(float) (p[point1*3+0]+val_x);
		y=(float) (p[point1*3+1]+val_y);
		z=(float) (p[point1*3+2]+val_z);

		u=UV[point1*2+0];
		v=UV[point1*2+1];

		//glNormal3f(n_points[3*point1+0],n_points[3*point1+1],n_points[3*point1+2]);	
		glTexCoord2f(u, v); glVertex3f(x,y,z);

		// POINT 2
		x=(float) (p[point2*3+0]+val_x);
		y=(float) (p[point2*3+1]+val_y);
		z=(float) (p[point2*3+2]+val_z);

		u=UV[point2*2+0];
		v=UV[point2*2+1];

		//glNormal3f(n_points[3*point2+0],n_points[3*point2+1],n_points[3*point2+2]);	
		glTexCoord2f(u, v); glVertex3f(x,y,z);

		// POINT 3
		x=(float) (p[point3*3+0]+val_x);
		y=(float) (p[point3*3+1]+val_y);
		z=(float) (p[point3*3+2]+val_z);

		u=UV[point3*2+0];
		v=UV[point3*2+1];

		//glNormal3f(n_points[3*point3+0],n_points[3*point3+1],n_points[3*point3+2]);	
		glTexCoord2f(u, v); glVertex3f(x,y,z);

		glEnd();
	}
	glEndList();

	return Obj;
}

// cré une texture de taille*taille et pointer sur t(R8G8B8)
GLuint create_texture(unsigned char *t,int taille,char type)
{
	GLuint		Texture;
		
	glGenTextures(1, &Texture);
	glBindTexture(GL_TEXTURE_2D, Texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

	
	if (type==0) // pixel
	{
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);	
		glTexImage2D(GL_TEXTURE_2D, 0, 3, taille, taille, 0, GL_RGB, GL_UNSIGNED_BYTE, t);
	} 
	if (type==1) // Adouci
	{
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR_MIPMAP_NEAREST);	
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, taille, taille, GL_RGB, GL_UNSIGNED_BYTE,t);
	}
	if (type==2) // pixel + Alpha
	{
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);	
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, taille, taille, 0, GL_RGBA, GL_UNSIGNED_BYTE, t);
	} 
	if (type==3) // Adouci + Alpha
	{
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR_MIPMAP_NEAREST);	
		gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, taille, taille, GL_RGBA, GL_UNSIGNED_BYTE,t);
	}


	return Texture;
}


  
LRESULT CALLBACK WndProc(	HWND	hWnd,			// Handle For This Window
							UINT	uMsg,			// Message For This Window
							WPARAM	wParam,			// Additional Message Information
							LPARAM	lParam)			// Additional Message Information
{
	char tmpp[32];
	switch (uMsg)									// Check For Windows Messages
	{



 	case WM_CREATE:
		SetTimer(hWnd,1,1,0);
		SetWindowText( hWnd, "TiTAN");
break;



case WM_TIMER:
		switch (wParam) 
    { 


	case 1:

if(ord==11 || ord>=12){
if(row==0 && ord==9)fct=0;
fct+=0.2;
for(loop=0;loop<=num;loop++){
if(star[loop].ct>10) {star[loop].ct=0;star[loop].burn=0;}
if(star[loop].burn){star[loop].ct+=0.05;}
}


}

if(ord==9 || ord==10){
if(row==0 && ord==9)fct=0;

fct+=0.2;
for(loop=0;loop<=num;loop++){
if(star[loop].ct>10) {star[loop].ct=0;star[loop].burn=0;}
if(star[loop].burn){star[loop].ct+=0.05;}
}

}
if(ord==8){fct+=0.2;

if(row>10)if(flame[1].scale<2) flame[1].scale+=0.02;
if(row>20)if(flame[2].scale<4) flame[2].scale+=0.2;
if(row>25)if(flame[3].scale<4) flame[3].scale+=0.02;
if(row>30)if(flame[4].scale<3) flame[4].scale+=0.02;
if(row>35)if(flame[5].scale<2) flame[5].scale+=0.02;
if(row>37)if(flame[6].scale<2) flame[6].scale+=0.02;
if(row>40)if(flame[7].scale<4) flame[7].scale+=0.02;
if(row>42)if(flame[8].scale<4) flame[8].scale+=0.02;
if(row>44)if(flame[9].scale<4) flame[9].scale+=0.02;
for(loop=0;loop<=num;loop++){
if(star[loop].ct>360) {star[loop].ct=0;star[loop].burn=0;}
if(star[loop].burn){star[loop].ct+=0.05;}
}


}

if(ord==7){if(ord==7 && row==0)fct=0;
fct+=0.2;

}

if(ord==5||ord==6){
fct+=0.2;

for(loop=0;loop<=num;loop++){
if(star[loop].ct>360) {star[loop].ct=0;star[loop].burn=0;}
if(star[loop].burn){star[loop].ct+=0.005;}
}



for(loop=0;loop<20;loop++){for(loop2=0;loop2<num;loop2++){
if(flow[loop][loop2].burn){flow[loop][loop2].ct+=0.2;}
if(flow[loop][loop2].ct>50){flow[loop][loop2].burn=0;flow[loop][loop2].ct=0;}

}}

}

if(ord==3||ord==4){ if(row==0 &&ord==3)fct=0;
fct+=0.2;
}

if(ord==0||ord==1){
fct+=0.2;

for(loop=0;loop<20;loop++){for(loop2=0;loop2<num;loop2++){
if(flow[loop][loop2].burn){flow[loop][loop2].ct+=0.2;}
if(flow[loop][loop2].ct>50){flow[loop][loop2].burn=0;flow[loop][loop2].ct=0;}

}}


for(loop=0;loop<=num;loop++){
if(star[loop].ct>360) {star[loop].ct=0;star[loop].burn=0;}
if(star[loop].burn){star[loop].ct+=0.005;}
}


}


if(ord==2){
deform_cyl2+=(float)(0.5*deform_cyl_val2);
deform_cyl3+=(float)(0.5*deform_cyl_val3);
fct+=0.2;

for(loop=0;loop<=num;loop++){
if(star[loop].ct>360) {star[loop].ct=0;star[loop].burn=0;}
if(star[loop].burn){star[loop].ct+=0.005;}
}







}














///////////////////////////ORD 1


	return TRUE;


 

		}
break;

		case WM_ACTIVATE:							// Watch For Window Activate Message
		{
			if (!HIWORD(wParam))					// Check Minimization State
			{
				active=TRUE;						// Program Is Active
			}
			else
			{
				active=FALSE;						// Program Is No Longer Active
			}

			return 0;								// Return To The Message Loop
		}

		case WM_SYSCOMMAND:							// Intercept System Commands
		{
			switch (wParam)							// Check System Calls
			{
				case SC_SCREENSAVE:					// Screensaver Trying To Start?
				case SC_MONITORPOWER:				// Monitor Trying To Enter Powersave?
				return 0;							// Prevent From Happening
			}
			break;									// Exit
		}

		case WM_CLOSE:								// Did We Receive A Close Message?
		{
			PostQuitMessage(0);						// Send A Quit Message
			return 0;								// Jump Back
		}

		case WM_KEYDOWN:							// Is A Key Being Held Down?
		{
			keys[wParam] = TRUE;					// If So, Mark It As TRUE
			return 0;								// Jump Back
		}

		case WM_KEYUP:								// Has A Key Been Released?
		{
			keys[wParam] = FALSE;					// If So, Mark It As FALSE
			return 0;								// Jump Back
		}

		case WM_SIZE:								// Resize The OpenGL Window
		{
			ReSizeGLScene(LOWORD(lParam),HIWORD(lParam));  // LoWord=Width, HiWord=Height
			return 0;								// Jump Back
		}
	}

	// Pass All Unhandled Messages To DefWindowProc
	return DefWindowProc(hWnd,uMsg,wParam,lParam);
}

float f(float x,float y,float z)
{

  float r;
  float r1,r2;
  /*static float R1=0.5;
    static float R2=0.7;*/
  float  alpha;

  alpha=R2*R2/(R1*R1);

  r=0;
  /*a=0.035;
  if(x>-1 && x<=0 && y>-1 && y<=0 && z>-1 && z<=0) {r=1;}*/
  r=(float)((x-2.3)*(x-2.3)+y*y+z*z);
  r+=(float)((x+2.3)*(x+2.3)+y*y+z*z);

  r1=(x-xb1)*(x-xb1) + (y-yb1)*(y-yb1) + (z-zb1)*(z-zb1);
  /*r1=r1*r1;*/

  /*r2=(x-(0.5))*(x-(0.5)) + y*y + z*z;*/
  r2=(x-xb2)*(x-xb2) + (y-yb2)*(y-yb2) + (z-zb2)*(z-zb2);
  /*r2=r2*r2;*/

  if(r1==0.0) r1=99999;
  else r1=1/r1;

  if(r2==0.0) r2=99999;
  else r2=1/r2;
  
  r= r1 + alpha*r2;
  
  return(r);
}


void affiche_fond(GLuint texture,float posx)
{
	glLoadIdentity();			// Reset The View
	glTranslatef(posx,0.0f,-4.0f);
	glRotatef(6*X,0.0f,0.0f,1.0f);
	glBindTexture(GL_TEXTURE_2D, texture);
	glColor3f(1.0f,1.0f,1.0f);
	glDisable(GL_DEPTH_TEST);
	glBegin(GL_QUADS);						// Draw A Quad
		glTexCoord2f(0, 0); 
		glVertex3f(-1.0f,-1.0f, 0.0f);				// Bottom Left
		glTexCoord2f(1, 0); 		
		glVertex3f( 1.0f,-1.0f, 0.0f);				// Bottom Right
		glTexCoord2f(1, 1); 		
		glVertex3f( 1.0f, 1.0f, 0.0f);				// Top Right
		glTexCoord2f(0, 1); 		
		glVertex3f(-1.0f, 1.0f, 0.0f);				// Top Left
	glEnd();
	glEnable(GL_DEPTH_TEST);
}





void affiche_metaballs(void)
{



static GLuint i;
  static int start, end;
   float *P/**p1,*p2,*p3,*Norm;*/;
//   float *RGB;
   int   *F;
   int   NP,NF;
   char *NEG;

   static float U[3],V[3],W[3];

//   float r,t1,t2,t3;
   
   float fo12x,fo13x,fo14x,fo23x,fo24x,fo34x;
   float fo12y,fo13y,fo14y,fo23y,fo24y,fo34y;
   float fo12z,fo13z,fo14z,fo23z,fo24z,fo34z;





  /* do the trackball rotation. */

  spin+=dspin;

  xb1=(0.4f*(float)cos(spin/3))*(float)cos(spin);
  yb1=(0.4f*(float)cos(spin/3))*(float)sin(spin);  
  zb1=(0.4f*(float)sin(spin/5));
  


 
 
  
  xb2=0.3f*(float)sin(spin);
  yb2=0.2f*(float)cos(spin);
  zb2=0.3f*(float)sin(spin);

  xb3=0.3f*(float)sin(spin);
  yb3=0.2f*(float)cos(spin/3);
  zb3=0.2f*(float)cos(spin);


  xb4=0.2f*(float)cos(spin);
  yb4=0.1f*(float)sin(spin);
  zb4=0.2f*(float)cos(spin);


  force(xb1,yb1,zb1,xb2,yb2,zb2,&fo12x,&fo12y,&fo12z);
  force(xb1,yb1,zb1,xb3,yb3,zb3,&fo13x,&fo13y,&fo13z);
  force(xb1,yb1,zb1,xb4,yb4,zb4,&fo14x,&fo14y,&fo14z);
  force(xb2,yb2,zb2,xb3,yb3,zb3,&fo23x,&fo23y,&fo23z);
  force(xb2,yb2,zb2,xb4,yb4,zb4,&fo24x,&fo24y,&fo24z);
  force(xb3,yb3,zb3,xb4,yb4,zb4,&fo34x,&fo34y,&fo34z);



  xb1+= fo12x + fo13x + fo14x;
  yb1+= fo12y + fo13y + fo14y;
  zb1+= fo12z + fo13z + fo14z;

  xb2+=-fo12x + fo23x + fo24x;
  yb2+=-fo12y + fo23y + fo24y;
  zb2+=-fo12z + fo23z + fo24z;

  xb3+=-fo13x - fo23x + fo34x;
  yb3+=-fo13y - fo23y + fo34y;
  zb3+=-fo13z - fo23z + fo34z; 

  xb4+=-fo14x - fo24x - fo34x;
  yb4+=-fo14y - fo24y - fo34y;
  zb4+=-fo14z - fo24z - fo34z; 


  
  /*glBegin(GL_TRIANGLES);*/
  
  glCullFace(GL_FRONT | GL_BACK);
 glEnable(GL_CULL_FACE);
 glEnable(GL_BLEND);
glDisable(GL_DEPTH_TEST);

#define ARET 0.95f  

  //glBegin(GL_QUADS);

/*
  glColor3f(0.25f,0.25f,0.25f);

	glVertex3f(-ARET,-ARET, ARET);
	glVertex3f( ARET,-ARET, ARET);
	glVertex3f( ARET, ARET, ARET);
	glVertex3f(-ARET, ARET, ARET);
	
  glColor3f(0.35f,0.35f,0.35f);
	glVertex3f( ARET,-ARET, ARET);
	glVertex3f( ARET,-ARET,-ARET);
	glVertex3f( ARET, ARET,-ARET);
	glVertex3f( ARET, ARET, ARET);
	
  glColor3f(0.25f,0.25f,0.25f);
	glVertex3f( ARET,-ARET,-ARET);
	glVertex3f(-ARET,-ARET,-ARET);
	glVertex3f(-ARET, ARET,-ARET);
	glVertex3f( ARET, ARET,-ARET);
	
  glColor3f(0.35f,0.35f,0.35f);
	glVertex3f(-ARET,-ARET,-ARET);
	glVertex3f(-ARET,-ARET, ARET);
	glVertex3f(-ARET, ARET, ARET);
	glVertex3f(-ARET, ARET,-ARET);
	
  glColor3f(0.3f,0.3f,0.3f);
	glVertex3f(-ARET, ARET, ARET);
	glVertex3f( ARET, ARET, ARET);
	glVertex3f( ARET, ARET,-ARET);
	glVertex3f(-ARET, ARET,-ARET);
	
  glColor3f(0.3f,0.3f,0.3f);
 	glVertex3f(-ARET,-ARET,-ARET);
	glVertex3f( ARET,-ARET,-ARET);
	glVertex3f( ARET,-ARET, ARET);
	glVertex3f(-ARET,-ARET, ARET);
  glEnd();

*/

  glCullFace(GL_FRONT);
  glEnable(GL_CULL_FACE);
  glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

  
  //glColor3f(255.0f,255.0f,255.0f);
  
  meta_objectNEG(&P,&F,&NF,&NEG,&NP,&fNEG2,0.02f/(R1*R1));

  glCullFace(GL_BACK);
  glEnable(GL_CULL_FACE);
  glEnable(GL_DEPTH_TEST);
  /*glEnd();*/

 



  
  
}

void Paski()
{glPushMatrix();
	//GORA
		glDisable(GL_TEXTURE_2D);
	//glDisable(GL_DEPTH_TEST);
	glLoadIdentity();
	glTranslatef(-2,0.365f,0.0f);
	glDisable(GL_BLEND);	
		//glEnable(GL_BLEND);									
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(0.0f,0.0f,0.0f,0.3f);
	glBegin(GL_QUADS);
		glVertex3f(1.0f,-0.05f,-1.0f);
		glVertex3f(3.0f,-0.05f,-1.0f);
		glVertex3f(3.0f,0.07f,-1.0f);
		glVertex3f(1.0f,0.072f,-1.0f);
	glEnd();
	glDisable(GL_BLEND);	
	glColor3f(1.0f,1.0f,1.0f);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);


	

	//DOL
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_DEPTH_TEST);
	glLoadIdentity();
	glTranslatef(-2,-0.365f,0.0f);
	glDisable(GL_BLEND);	
	//glEnable(GL_BLEND);									
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(0.0f,0.0f,0.0f,0.3f);
	glBegin(GL_QUADS);
		glVertex3f(1.0f,-0.1f,-1.0f);
		glVertex3f(3.0f,-0.1f,-1.0f);
		glVertex3f(3.0f,0.05f,-1.0f);
		glVertex3f(1.0f,0.05f,-1.0f);
	glEnd();
	
	glColor3f(1.0f,1.0f,1.0f);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
		
glPopMatrix();
}
 


void decode_gif(unsigned char *src,unsigned char *dest,long len)
{
	CGifDecoder		decoder;
	long			i,r,taille;
	unsigned char	cr,cb;
	taille=decoder.Open(src,len);
	taille=(long)sqrt(taille/3);

	r=decoder.Decode(dest);
	for (i=0;i<taille*taille;i++)
	{
		cr=dest[i*3];
		cb=dest[i*3+2];
		dest[i*3+2]=cr;
		dest[i*3]=cb;
	}
}

void convert_rgba(unsigned char *src,unsigned char *dest,int taille,unsigned char r,unsigned char v,unsigned char b)
{
	for (int i=0;i<256*256;i++)
	{
		if ((src[i*3]==r) && (src[i*3+1]==v) && (src[i*3+2]==b))
		{
			dest[i*4]=r;
			dest[i*4+1]=v;
			dest[i*4+2]=b;
			dest[i*4+3]=0;
		}
		else
		{
			dest[i*4]=src[i*3];
			dest[i*4+1]=src[i*3+1];
			dest[i*4+2]=src[i*3+2];
			dest[i*4+3]=255;
		}
	}
}

/*
void create_perlin(unsigned char *src)
{
	unsigned char c,d,e;

	int	xdim=256,ydim=256,z=0,zdim=256;
	int	i=0;
	for(int y=0; y < ydim ;++y)
	{
		for(int x=0; x < xdim ;++x)
		{
//			    c = (sin(tnoise(Cx/(xdim/1.0),(float)y/(ydim/1),(float)z/(zdim/1))))*255;
//				d = (sin(tnoise((float)x/(xdim/2.0),(float)y/(ydim/2.0),(float)z/(zdim/2))))*255;
//				e = (sin(tnoise((float)x/(2*xdim),(float)y/(2*ydim),(float)z/(2*zdim))))*255;

//			    c = tnoise((float)x/(float)xdim,(float)y/(float)ydim,(float)z/(float)zdim)*255;
//				d = ((tnoise((float)x/(xdim/1.0),(float)y/(ydim/1.0),(float)z/(zdim/1))))*255;
//				e = ((tnoise((float)x/(2*xdim),(float)y/(2*ydim),(float)z/(2*zdim))))*255;

				c=PerlinNoise2D((float)x,(float)y,20,0.5,7)*255;

				//c = tnoise( (float)x/4.0,(float)y/4.0,.5)*255.0;
				//src[z*ydim*xdim*3+y*xdim*3+x*3] = e*255;//(c*.5+.5)*255;//c;//x%4*255/4;
				//src[z*ydim*xdim*3+y*xdim*3+x*3 + 1] = c*255;//(cd)/2,0,1)*255;
				//src[z*ydim*xdim*3+y*xdim*3+x*3 + 2] = d*255;// +d/2;(d + c)/2;//c/2.0;

				src[i*3] = c*255;//(c*.5+.5)*255;//c;//x%4*255/4;
				src[i*3 + 1] = c*255;//(cd)/2,0,1)*255;
				src[i*3 + 2] = c*255;// +d/2;(d + c)/2;//c/2.0;
				i++;

		}
	}
}
*/

void Repmlir(unsigned char *tenv,long taille,float r,float g,float b)
{
	for(long i = 0;i < taille * taille;i++)
	{
		tenv[i * 3]     = (unsigned char)r;
		tenv[i * 3 + 1] = (unsigned char)g;
		tenv[i * 3 + 2] = (unsigned char)b;
	}
}

void Create_Env(unsigned char *tenv,long taille,long x1,long y1,float r,float g,float b,float rayon)
{
	float valx,valy,dist;

	for(long y = 0;y < taille;y++)
		for(long x = 0;x < taille;x++)
		{
			valx = (float)(x - x1) / (float)(taille / 2);
			valy = (float)(y - y1) / (float)(taille / 2);
			dist = valx * valx + valy * valy;
			dist = (float)exp(rayon * dist);

			tenv[(y * taille * 3) + (x * 3)]     =  (unsigned char)(dist * r);
			tenv[(y * taille * 3) + (x * 3) + 1] =  (unsigned char)(dist * g);
			tenv[(y * taille * 3) + (x * 3) + 2] =  (unsigned char)(dist * b);
		}
}

void Create_Env2(unsigned char *tenv,long taille,long x1,long y1,float r,float g,float b,float rayon)
{
	float valx,valy,dist;

	for(long y = 0;y < taille;y++)
		for(long x = 0;x < taille;x++)
		{
			valx = (float)(x - x1) / (float)(taille / 2);
			valy = (float)(y - y1) / (float)(taille / 2);
			dist = valx * valx + valy * valy;
			dist = (float)exp(rayon * dist);
/*
			tenv[(y * taille * 3) + (x * 3)]     = (unsigned char)(tenv[(y * taille * 3) + (x * 3)] *0.5)+ (unsigned char)(dist * r*0.5);
			tenv[(y * taille * 3) + (x * 3) + 1] = (unsigned char)(tenv[(y * taille * 3) + (x * 3) + 1]*0.5)+ (unsigned char)(dist * g*0.5);
			tenv[(y * taille * 3) + (x * 3) + 2] = (unsigned char)(tenv[(y * taille * 3) + (x * 3) + 2]*0.5)+(unsigned char)(dist * b*0.5);
*/
			tenv[(y * taille * 3) + (x * 3)]     +=  (unsigned char)(dist * r);
			tenv[(y * taille * 3) + (x * 3) + 1] +=  (unsigned char)(dist * g);
			tenv[(y * taille * 3) + (x * 3) + 2] +=  (unsigned char)(dist * b);
		}
}













LOGO(int o){

glEnable(GL_BLEND);
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D,1);
//PushMatrix();
//if(!o)	glTranslatef(-4.4,-3.8,sin(ct*0.5)-10);
//else
glTranslatef(-4.4,-3.8,-10);

	glRotatef(180,0,0,1);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,-1.0f, 0.0f);
			glTexCoord2f(1.0f, 0.0f);glVertex3f( 1.0f,-1.0f, 0.0f);
			glTexCoord2f(1.0f, 1.0f);glVertex3f( 1.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 1.0f);glVertex3f(-1.0f, 1.0f, 0.0f);
		glEnd();

glPopMatrix();
glDisable(GL_BLEND);
glDisable(GL_TEXTURE_2D);

}




/////////////////////////////////////////////////////////////////////////////////////////////////////////
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	MSG				msg;									// Windows Message Structure
	BOOL			done=FALSE;								// Bool Variable To Exit Loop

	// Change fullscreen HERE
	fullscreen=true;
FILE *fp;
#ifdef USEFMOD
	FMUSIC_MODULE *mod;

#ifndef USEMEMLOAD
	FSOUND_File_SetCallbacks(fileopen, fileclose, fileread, fileseek, filetell);
#else
	FSOUND_File_SetCallbacks(memopen, memclose, memread, memseek, memtell);
#endif
#endif

	if (!CreateGLWindow("titan pussy",res_x,res_y,bpp,fullscreen))
	{
		return 0;									// Quit If Window Was Not Created
	}


#ifdef USEFMOD
	// INITIALIZE
	if (!FSOUND_Init(44100, 0))	{		return 1;	}
	// LOAD SONG
	mod = FMUSIC_LoadSong("xm", NULL); //sampleloadcallback);
	if (!mod)	{		return 1;	}
	// PLAY SONG
#endif







cyl=new Cylindre(22,50,40.0f,4.0f);
	tunnel=new Cylindre(22,50,100.0f,6.0f);
	pl=new Plan(64,64,100,100);


lava1_2=(unsigned char*) malloc(256*256*3);
lava2_2=(unsigned char*) malloc(256*256*4);





	flare1_2=(unsigned char*) malloc(256*256*3);
	flare2_2=(unsigned char*) malloc(256*256*4);


	tfonte=(unsigned char*) malloc(256*256*3);
	tfonte2=(unsigned char*) malloc(256*256*4);


	flare1=(unsigned char*) malloc(256*256*3);
	flare2=(unsigned char*) malloc(256*256*4);
	
	vein1=(unsigned char*) malloc(256*256*3);
	vein2=(unsigned char*) malloc(256*256*4);



decode_gif(lava,lava1_2,LAVA_LEN);
	convert_rgba(lava1_2,lava2_2,256,100,100,128);
	T_Lava=create_texture(lava2_2,256,3);




	decode_gif(vein,vein1,VEIN_LEN);
	convert_rgba(vein1,vein2,32,100,100,128);
	T_Vein=create_texture(vein2,32,3);
	


	decode_gif(fnt3,tfonte,FNT3_LEN);
	convert_rgba(tfonte,tfonte2,256,214,99,123);
	T_Fonte=create_texture(tfonte2,256,3);
	
decode_gif(flara,flare1,FLARA_LEN);
	convert_rgba(flare1,flare2,32,100,100,128);
	T_Flare=create_texture(flare2,32,3);







	#ifdef USEFMOD
	FMUSIC_PlaySong(mod);
	
#else

//row=0;

#endif
	while (!done)								// Loop That Runs While done=FALSE 
	{	
		if (PeekMessage(&msg,NULL,0,0,PM_REMOVE))	// Is There A Message Waiting?
		{
			if (msg.message==WM_QUIT)				// Have We Received A Quit Message?
			{
				done=TRUE;							// If So done=TRUE
			}
			else									// If Not, Deal With Window Messages
			{
				TranslateMessage(&msg);				// Translate The Message
				DispatchMessage(&msg);				// Dispatch The Message
			}
		}
		else										// If There Are No Messages
		{
			// Draw The Scene.  Watch For ESC Key And Quit Messages From DrawGLScene()
			if (active)								// Program Active?
			{


		if(keys['1']){
ord=1;

		}


				if(keys['0']){
ord=0;

		}


				if (keys[VK_INSERT]){
					ord++;
				}

				if(keys[VK_DELETE]){
				ord--;
				}
				if (keys[VK_ESCAPE])				// Was ESC Pressed?
				{
					done=TRUE;						// ESC Signalled A Quit
				}
				else								// Not Time To Quit, Update Screen
				{
					//DrawGLScene();					// Draw The Scene

					// Fondu du départ du noir vers le bleu
				/*	 if (nb_coulcal<=nb_coul)
					{
						c_calcul[0]=(float)(nb_coulcal*((c_fond[0]-c_noir[0])/(float)(nb_coul)));
						c_calcul[1]=(float)(nb_coulcal*((c_fond[1]-c_noir[1])/(float)(nb_coul)));
						c_calcul[2]=(float)(nb_coulcal*((c_fond[2]-c_noir[2])/(float)(nb_coul)));
						glClearColor(c_calcul[0]/2,c_calcul[1]/2,c_calcul[2]/2, 0.0f);
						nb_coulcal++;
						glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
					}*/
					/*else*/
#ifdef USEFMOD
ord = FMUSIC_GetOrder(mod);
row = FMUSIC_GetRow(mod);
#endif




//1-ord=9;
if(ord==0||ord==1){if(row==0)fct=0;
glClearColor(1-fct*0.2,1-fct*0.2,1-fct*0.2,1);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glBlendFunc(GL_SRC_ALPHA,GL_ONE);



glLoadIdentity();	

 BARS();



if(ord==1)
gluLookAt(0,150,0,  1,1,fct2,0,0,1);
else
gluLookAt(-2,150,-100  ,1,1,50,0,0,1);























glRotatef(fct,0,0,1);

for(loop=1;loop<20;loop++){
glEnable(GL_DEPTH_TEST);
glDisable(GL_CULL_FACE); 
glEnable(GL_FOG);

glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
//glEnable(GL_BLEND);
glColor4f(1,1,1,1);
glColor3f(255,0,0);
glPushMatrix(); 
veins[loop].x=point[loop].x*0.5;
veins[loop].y=point[loop].y*0.4;
veins[loop].z=0;

glTranslatef(veins[loop].x,veins[loop].y,veins[loop].z);

cyl->Cylindre_Deforme(fct*veins[loop].x,fct*0.2,fct*0.05);
glScalef(0.5,0.5,1);
cyl->Cylindre_affiche();
glTranslatef(0,0,-20);
glColor4f(1,1,1,1);
//glScalef(10,5,5);
auxWireCube(10);


glPopMatrix();

glDisable(GL_LIGHTING);
glDisable(GL_FOG);
glDisable(GL_BLEND);
glDisable(GL_TEXTURE_2D);
glDisable(GL_DEPTH_TEST);
}















for(loop=1;loop<20;loop++){
for(loop2=0;loop2<500;loop2++){

if(RAND(1,1000)==1){
flow[loop][loop2].burn=1;
}


glDisable(GL_LIGHTING);
glDisable(GL_FOG);
glDisable(GL_BLEND);
glDisable(GL_TEXTURE_2D);


//glEnable(GL_TEXTURE_2D);
//glBindTexture(GL_TEXTURE_2D,T_Flare);

glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA,GL_ONE);

glEnable(GL_DEPTH_TEST);

glPushMatrix();
glTranslatef(sin(flow[loop][loop2].ct)+veins[loop].x,veins[loop].y,(veins[loop].z+15)+flow[loop][loop2].ct);

if(flow[loop][loop2].ct>5){

 
glScalef(1.3,1.3,1.3);
}
else{
glScalef(0.2,0.2,0.2);}


if(flow[loop][loop2].ct>2){
glColor3f(255,255,255);
/*glRotatef(180,90,0,1);
 glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,-1.0f, 0.0f);
			glTexCoord2f(1.0f, 0.0f);glVertex3f( 1.0f,-1.0f, 0.0f);
			glTexCoord2f(1.0f, 1.0f);glVertex3f( 1.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 1.0f);glVertex3f(-1.0f, 1.0f, 0.0f);
		glEnd();
glDisable(GL_TEXTURE_2D);
glDisable(GL_BLEND);
*/
auxWireCube(1);
}
glPopMatrix();

}//2


}//1




}







//################ORD
//################ORD
if(ord==2){
//glClearColor(0.44,0.2,0.20, 0.0f);
if(row==0)fct=0;
glClearColor(1-fct*0.2,1-fct*0.2,1-fct*0.2,1);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glBlendFunc(GL_SRC_ALPHA,GL_ONE);
glLoadIdentity();	
glRotatef(fct,0,0,1);
glDisable(GL_LIGHTING);
glDisable(GL_FOG);
glDisable(GL_DEPTH_TEST);


 for(loop=0;loop<=550;loop++){
glDisable(GL_FOG);
glPushMatrix();
if(RAND(1,1007)==2){star[loop].burn=1;}

glEnable(GL_TEXTURE_2D);
glBlendFunc(GL_SRC_ALPHA,GL_ONE);
glBindTexture(GL_TEXTURE_2D,T_Lava);
glEnable(GL_BLEND);



  glColor4f(0.2,0.2,0.2,1);
  
  
  glTranslatef(-12+star[loop].x*0.1,-7+star[loop].y*0.06,-20+star[loop].ct);




glScalef(sin(star[loop].ct)*3,sin(star[loop].ct)*3,0.001);
glRotatef(star[loop].ct*20,0,0,1);
 glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,-1.0f, 0.0f);
			glTexCoord2f(1.0f, 0.0f);glVertex3f( 1.0f,-1.0f, 0.0f);
			glTexCoord2f(1.0f, 1.0f);glVertex3f( 1.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 1.0f);glVertex3f(-1.0f, 1.0f, 0.0f);
		glEnd();
glDisable(GL_BLEND);

glDisable(GL_TEXTURE_2D);	
glPopMatrix();

	}



for(loop=1;loop<2;loop++){
glDisable(GL_CULL_FACE); 
//glEnable(GL_FOG);
glEnable(GL_TEXTURE_2D);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glEnable(GL_BLEND);
glColor4f(1,1,1,1);
glColor3f(255,0,0);
glPushMatrix(); 
glTranslatef(-10+point[loop].x*0.05,-5+point[loop].y*0.04+loop,-50-star[loop].z);
glRotatef(fct-point[loop].z*0.5,0,fct-point[loop].z*0.5,1);





cyl->Cylindre_Deforme(fct*0.05,fct*0.05,fct*0.05);
glScalef(0.5,0.5,1);
cyl->Cylindre_affiche();

glColor4f(1,1,1,1);
glScalef(10,20,50);
auxWireCube(1);


glPopMatrix();
glDisable(GL_LIGHTING);
glDisable(GL_FOG);
glDisable(GL_BLEND);
glDisable(GL_TEXTURE_2D);

}






for(loop=0;loop<550;loop++){
//glRotatef(fct*0.005,0,0,1);


glPushMatrix(); 
glColor4f(0.2,0.2,0.2,1);
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D,T_Flare);
glEnable(GL_BLEND);
glScalef(0.2,0.2,0.2);
if(-100+sin(star[loop].ct)*200>-100){
glColor4f(0.6,0.5,0.5,1);
}
glTranslatef((-55+flame[loop].x)+sin(fct-loop)/2,-38+flame[loop].y*0.3,-100+sin(star[loop].ct)*200);
 glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,-1.0f, 0.0f);
			glTexCoord2f(1.0f, 0.0f);glVertex3f( 1.0f,-1.0f, 0.0f);
			glTexCoord2f(1.0f, 1.0f);glVertex3f( 1.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 1.0f);glVertex3f(-1.0f, 1.0f, 0.0f);
		glEnd();
glPopMatrix();
glDisable(GL_LIGHTING);
glDisable(GL_FOG);
glDisable(GL_BLEND);

}

 
BARS();
}


else if(ord==3||ord==4){
if(row==0)fct=0;
glClearColor(1-fct*0.2,1-fct*0.2,1-fct*0.2,1);

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glBlendFunc(GL_SRC_ALPHA,GL_ONE);
glLoadIdentity();	
if(ord==3)
  gluLookAt(fct,0,fct,fct*0.5,1,1,0,0,1);
else if(ord==4)
  gluLookAt(fct,0,-50+fct,fct*0.5,1,1,0,0,1);

  if(row>0){
for(loop=1;loop<25;loop++){
glDisable(GL_CULL_FACE); 
glEnable(GL_FOG);
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D,T_Flare);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glEnable(GL_BLEND);
glColor4f(1,1,1,1);
glColor3f(255,0,0);
glPushMatrix(); 
glTranslatef(-10+point[loop].x*0.05,-15+point[loop].y*0.04+loop,-50-star[loop].z);
glRotatef(fct-point[loop].z*0.5,0,fct-point[loop].z*0.5,1);


cyl->Cylindre_Deforme(fct*0.05,fct*0.05,fct*0.05);
if(fct<10){skala=fct*0.5;}
glScalef(0.5,0.5,skala);
 cyl->Cylindre_affiche();

 

glPopMatrix();
glDisable(GL_LIGHTING);
glDisable(GL_FOG);
glDisable(GL_BLEND);
glDisable(GL_TEXTURE_2D);

}
 
}

glPushMatrix();
glTranslatef(0,0,-150);
glBlendFunc(GL_SRC_ALPHA,GL_ONE);
glEnable(GL_BLEND);
glColor4f(0.5,0.5,0.5,1);
Affiche_texte("titan blood sucking vains\n",20,0,190,T_Fonte,fct);
glDisable(GL_BLEND);
glPopMatrix();

BARS();
}



else if(ord==5||ord==6){
if(row==0)fct=0;
glClearColor(1-fct*0.2,1-fct*0.2,1-fct*0.2,1);


glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glBlendFunc(GL_SRC_ALPHA,GL_ONE);
glLoadIdentity();	



if(ord==5)
  gluLookAt(0,fct,150,50,50,1,0,0,1);
else
gluLookAt(fct,fct,150    ,50,50,fct   ,0,0,1);





for(loop=0;loop<1550;loop++){
//glRotatef(fct*0.005,0,0,1);


glPushMatrix(); 
glColor4f(1.2,1.2,1.2,1);
glEnable(GL_TEXTURE_2D);
glDisable(GL_LIGHTING);
glDisable(GL_FOG);
glBindTexture(GL_TEXTURE_2D,T_Flare);
glEnable(GL_BLEND);
glScalef(star[loop].scale,star[loop].scale,star[loop].scale);
if(-100+sin(star[loop].ct)*200>-100){
glColor4f(0.6,0.5,0.5,1);
}
glTranslatef(sin(fct)+star[loop].x*0.4,cos(fct-loop)+star[loop].y*0.4,-200+loop*0.5);
glRotatef(fct,0,0,1);
 glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,-1.0f, 0.0f);
			glTexCoord2f(1.0f, 0.0f);glVertex3f( 1.0f,-1.0f, 0.0f);
			glTexCoord2f(1.0f, 1.0f);glVertex3f( 1.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 1.0f);glVertex3f(-1.0f, 1.0f, 0.0f);
		glEnd();
glPopMatrix();
glDisable(GL_LIGHTING);
glDisable(GL_FOG);
glDisable(GL_BLEND);

}






for(loop=1;loop<25;loop++){
glDisable(GL_CULL_FACE); 
glEnable(GL_FOG);
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D,T_Flare);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glEnable(GL_BLEND);
glColor4f(1,1,1,1);
glColor3f(255,0,0);
glPushMatrix(); 
veins[loop].x=-10+point[loop].x*0.5;
veins[loop].y=-15+point[loop].y*0.4+loop;
veins[loop].z=-50-star[loop].z;

glTranslatef(veins[loop].x,veins[loop].y,veins[loop].z);
 

cyl->Cylindre_Deforme(fct*0.05,fct*0.05,fct*0.05);
if(fct<10){skala=fct*0.5;}
glScalef(0.5,0.5,10.5);
 cyl->Cylindre_affiche();

 

glPopMatrix();
glDisable(GL_LIGHTING);
glDisable(GL_FOG);
glDisable(GL_BLEND);
glDisable(GL_TEXTURE_2D);

}
 

 if(ord==5){
glPushMatrix();
glTranslatef(0,0,-150);
glBlendFunc(GL_SRC_ALPHA,GL_ONE);
glEnable(GL_BLEND);
glColor4f(0.5,0.5,0.5,1);
Affiche_texte("titan blood sucking vains\n",20,0,190,T_Fonte,fct);
glDisable(GL_BLEND);
glPopMatrix();
} 
BARS();
}


else if(ord==7){
if(row==0)fct=0;
glClearColor(1-fct*0.2,1-fct*0.2,1-fct*0.2,1);


if(ord==7 && row==0){fct=0;skala=0;}
c1=0;
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glBlendFunc(GL_SRC_ALPHA,GL_ONE);
glLoadIdentity();	
//glTranslatef(-150,-100,-150);
gluLookAt(200-fct,fct,-30+fct*3,  -5,-5,-50, 0,0,1);


//glRotatef(fct*5,0,0,1);

for(loop=0;loop<=10;loop++){
c1+=10;

glDisable(GL_CULL_FACE); 
glEnable(GL_FOG);
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D,T_Flare);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glEnable(GL_BLEND);
glColor4f(1,1,1,1);
glColor3f(255,0,0);
glPushMatrix(); 
veins[loop].x=-10+point[loop].x*0.5;
veins[loop].y=-15+point[loop].y*0.4+loop;
veins[loop].z=-50-star[loop].z;
			// ^		// <-->
glTranslatef(c1/10,-120+veins[loop].y*2,veins[loop].z);
 

cyl->Cylindre_Deforme(fct*0.05,fct*0.05,fct*0.05);
if(fct<10){skala=fct*0.5;}
glScalef(skala,1,1);
glRotatef(90,0,90,1);
 cyl->Cylindre_affiche();

 

glPopMatrix();
glDisable(GL_LIGHTING);
glDisable(GL_FOG);
glDisable(GL_BLEND);
glDisable(GL_TEXTURE_2D);

} 

c1=0;

//for(loop2=0;loop2<10;loop2++){
//c2+=10;
for(loop=0;loop<=20;loop++){
c1+=10;

glDisable(GL_CULL_FACE); 
glEnable(GL_FOG);
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D,T_Flare);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glEnable(GL_BLEND);
glColor4f(1,1,1,1);
glColor3f(255,0,0);
glPushMatrix(); 
veins[loop].x=-10+point[loop].x*0.5;
veins[loop].y=-15+point[loop].y*0.4+loop;
veins[loop].z=-50-star[loop].z;
			// ^		// <-->
glTranslatef((-80+c1/10),-120+veins[loop].y*2,veins[loop].z);
 

cyl->Cylindre_Deforme(fct*0.05,fct*0.05,fct*0.05);
glScalef(0.2,0.2,skala);
glRotatef(0,0,90,1);
 cyl->Cylindre_affiche();

 

glPopMatrix();




glPushMatrix(); 
veins[loop].x=-10+point[loop].x*0.5;
veins[loop].y=-15+point[loop].y*0.4+loop;
veins[loop].z=-50-star[loop].z;
			// ^		// <-->
glTranslatef((70+c1/10),-120+veins[loop].y*2,veins[loop].z);
 

cyl->Cylindre_Deforme(fct*0.05,fct*0.05,fct*0.05);
glScalef(0.2,0.2,skala);
glRotatef(0,0,90,1);
 cyl->Cylindre_affiche();

 

glPopMatrix();




glPushMatrix(); 
glTranslatef((70+c1/10),-120+veins[loop].y*2,veins[loop].z);
glColor3f(255,255,255);
auxWireCube(5);
glPopMatrix();

glPushMatrix(); 
glTranslatef((-70+c1/10),-120+veins[loop].y*2,veins[loop].z);
glColor3f(255,255,255);
auxWireCube(5);
glPopMatrix();




glDisable(GL_LIGHTING);
glDisable(GL_FOG);
glDisable(GL_BLEND);
glDisable(GL_TEXTURE_2D);

} 



//}//2


glPushMatrix();
glTranslatef(0,0,-150);
glBlendFunc(GL_SRC_ALPHA,GL_ONE);
glEnable(GL_BLEND);
glColor4f(0.5,0.5,0.5,1);
if(c1-fct*50>10){
Affiche_texte("tech suicide\n",20,50,190,T_Fonte,c1-fct*50);}else{
Affiche_texte("tech suicide\n",20,50,190,T_Fonte,10);
}
glDisable(GL_BLEND);
glPopMatrix();



BARS();


}


else if(ord==8){
if(row==0)fct=0;
glClearColor(1-fct*0.2,1-fct*0.2,1-fct*0.2,1);


if(ord==8 && row==0){fct=0;skala=0;}
if(row==0)fct=0;
glClearColor(1-fct*0.2,1-fct*0.2,1-fct*0.2,1);

c1=0;
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glBlendFunc(GL_SRC_ALPHA,GL_ONE);
glLoadIdentity();	
 for(loop=0;loop<=1550;loop++){
if(RAND(1,1107)==2){star[loop].burn=1;}
if(star[loop].burn){ 
glDisable(GL_FOG);
glPushMatrix();




glEnable(GL_TEXTURE_2D);
glBlendFunc(GL_SRC_ALPHA,GL_ONE);
glBindTexture(GL_TEXTURE_2D,T_Lava);
glEnable(GL_BLEND);



  glColor4f(0.2,0.1,0.1,1);
    glTranslatef(-12+star[loop].x*0.1,-7+star[loop].y*0.06,-20+star[loop].ct*2);

  
 



glScalef(1.2,1.2,1.2);
glRotatef(star[loop].ct*20,0,0,1);
 glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,-1.0f, 0.0f);
			glTexCoord2f(1.0f, 0.0f);glVertex3f( 1.0f,-1.0f, 0.0f);
			glTexCoord2f(1.0f, 1.0f);glVertex3f( 1.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 1.0f);glVertex3f(-1.0f, 1.0f, 0.0f);
		glEnd();
glDisable(GL_BLEND);

glDisable(GL_TEXTURE_2D);	
glPopMatrix();


}

	}


gluLookAt(fct,0,40+fct,  -5,fct,-50, 0,0,1);
 


// glRotatef(fct,0,0,1);


if(row==0){fct=0;skala=0;flame[1].scale=0;flame[2].scale=0;}


 
if(!drawed){
glDisable(GL_CULL_FACE); 
glEnable(GL_FOG);
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D,T_Flare);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glEnable(GL_BLEND);
glColor4f(1,1,1,1);
glColor3f(255,0,0);
glPushMatrix(); 
veins[1].x=0;
veins[1].y=0;
veins[1].z=-50;
			
glTranslatef(veins[1].x,veins[1].y,veins[1].z);


cyl->Cylindre_Deforme(fct*0.05,fct*0.05,fct*0.05);
if(fct<10){skala=fct*0.5;}
glScalef(skala,1,1);
glRotatef(90,0,90,1);
 cyl->Cylindre_affiche();




glPopMatrix();
glDisable(GL_LIGHTING);
glDisable(GL_FOG);
glDisable(GL_BLEND);
glDisable(GL_TEXTURE_2D);
 
if(row>10){


glDisable(GL_CULL_FACE); 
glEnable(GL_FOG);
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D,T_Flare);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glEnable(GL_BLEND);
glColor4f(1,1,1,1);
glColor3f(255,0,0);
glPushMatrix(); 
veins[1].x=0;
veins[1].y=0;
veins[1].z=-50;
			

 

cyl->Cylindre_Deforme(fct*0.05,fct*0.05,fct*0.05);
glTranslatef(veins[1].x,veins[1].y,veins[1].z);
glRotatef(90,90,90,1);
glScalef(0.5,0.5,flame[1].scale);
 cyl->Cylindre_affiche();




glPopMatrix();
glDisable(GL_LIGHTING);
glDisable(GL_FOG);
glDisable(GL_BLEND);
glDisable(GL_TEXTURE_2D);
 
}



if(row>20){


glDisable(GL_CULL_FACE); 
glEnable(GL_FOG);
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D,T_Flare);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glEnable(GL_BLEND);
glColor4f(1,1,1,1);
glColor3f(255,0,0);
glPushMatrix(); 
veins[1].x=0;
veins[1].y=0;
veins[1].z=-50;
			

 

cyl->Cylindre_Deforme(fct*0.05,fct*0.05,fct*0.05);
glTranslatef(veins[1].x,veins[1].y+30,veins[1].z);
glRotatef(90,0,90,1);
glScalef(1,1,flame[2].scale);
 cyl->Cylindre_affiche();




glPopMatrix();
glDisable(GL_LIGHTING);
glDisable(GL_FOG);
glDisable(GL_BLEND);
glDisable(GL_TEXTURE_2D);
 
}





if(row>25){
glDisable(GL_CULL_FACE); 
glEnable(GL_FOG);
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D,T_Flare);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glEnable(GL_BLEND);
glColor4f(1,1,1,1);
glColor3f(255,0,0);
glPushMatrix(); 
		
glTranslatef(veins[1].x,veins[1].y+55,veins[1].z);
cyl->Cylindre_Deforme(fct*0.05,fct*0.05,fct*0.05);
glScalef(flame[3].scale*2,1,1);
glRotatef(90,0,90,1);
 cyl->Cylindre_affiche();




glPopMatrix();
glDisable(GL_LIGHTING);
glDisable(GL_FOG);
glDisable(GL_BLEND);
glDisable(GL_TEXTURE_2D);
 
}



if(row>30){
glDisable(GL_CULL_FACE); 
glEnable(GL_FOG);
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D,T_Flare);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glEnable(GL_BLEND);
glColor4f(1,1,1,1);
glColor3f(255,0,0);
glPushMatrix(); 
		
glTranslatef(veins[1].x-140,veins[1].y+55,veins[1].z);
cyl->Cylindre_Deforme(fct*0.05,fct*0.05,fct*0.05);
glScalef(1,flame[4].scale,1);
glRotatef(90,90,90,1);
 cyl->Cylindre_affiche();




glPopMatrix();
glDisable(GL_LIGHTING);
glDisable(GL_FOG);
glDisable(GL_BLEND);
glDisable(GL_TEXTURE_2D);

}

if(row>35){
glDisable(GL_CULL_FACE); 
glEnable(GL_FOG);
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D,T_Flare);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glEnable(GL_BLEND);
glColor4f(1,1,1,1);
glColor3f(255,0,0);
glPushMatrix(); 
		
glTranslatef(veins[1].x,veins[1].y+85,veins[1].z);
cyl->Cylindre_Deforme(fct*0.05,fct*0.05,fct*0.05);
glScalef(flame[5].scale*2,flame[5].scale,1);
glRotatef(90,45,90,1);
 cyl->Cylindre_affiche();




glPopMatrix();
glDisable(GL_LIGHTING);
glDisable(GL_FOG);
glDisable(GL_BLEND);
glDisable(GL_TEXTURE_2D);

}

if(row>37){
glDisable(GL_CULL_FACE); 
glEnable(GL_FOG);
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D,T_Flare);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glEnable(GL_BLEND);
glColor4f(1,1,1,1);
glColor3f(255,0,0);
glPushMatrix(); 
		
glTranslatef(veins[1].x,veins[1].y+110,veins[1].z);
cyl->Cylindre_Deforme(fct*0.05,fct*0.05,fct*0.05);
glScalef(flame[6].scale*2,flame[6].scale,1);
glRotatef(90,-45,90,1);
 cyl->Cylindre_affiche();




glPopMatrix();
glDisable(GL_LIGHTING);
glDisable(GL_FOG);
glDisable(GL_BLEND);
glDisable(GL_TEXTURE_2D);

}


if(row>37){
glDisable(GL_CULL_FACE); 
glEnable(GL_FOG);
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D,T_Flare);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glEnable(GL_BLEND);
glColor4f(1,1,1,1);
glColor3f(255,0,0);
glPushMatrix(); 
		
glTranslatef(veins[1].x,veins[1].y+100,veins[1].z);
cyl->Cylindre_Deforme(fct*0.05,fct*0.05,fct*0.05);
glScalef(1,flame[6].scale,1);
glRotatef(90,180,90,1);
 cyl->Cylindre_affiche();




glPopMatrix();
glDisable(GL_LIGHTING);
glDisable(GL_FOG);
glDisable(GL_BLEND);
glDisable(GL_TEXTURE_2D);

}

if(row>40){
glDisable(GL_CULL_FACE); 
glEnable(GL_FOG);
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D,T_Flare);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glEnable(GL_BLEND);
glColor4f(1,1,1,1);
glColor3f(255,0,0);
glPushMatrix(); 
		
glTranslatef(veins[1].x,veins[1].y+160,veins[1].z);
cyl->Cylindre_Deforme(fct*0.05,fct*0.05,fct*0.05);
glScalef(flame[7].scale,1,1);
glRotatef(90,45,90,1);
 cyl->Cylindre_affiche();




glPopMatrix();
glDisable(GL_LIGHTING);
glDisable(GL_FOG);
glDisable(GL_BLEND);
glDisable(GL_TEXTURE_2D);

}
if(row>42){
glDisable(GL_CULL_FACE); 
glEnable(GL_FOG);
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D,T_Flare);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glEnable(GL_BLEND);
glColor4f(1,1,1,1);
glColor3f(255,0,0);
glPushMatrix(); 
		
glTranslatef(veins[1].x,veins[1].y+180,veins[1].z);
cyl->Cylindre_Deforme(fct*0.05,fct*0.05,fct*0.05);
glScalef(flame[8].scale,1,1);
glRotatef(90,-45,90,1);
 cyl->Cylindre_affiche();




glPopMatrix();
glDisable(GL_LIGHTING);
glDisable(GL_FOG);
glDisable(GL_BLEND);
glDisable(GL_TEXTURE_2D);

}
if(row>44){
glDisable(GL_CULL_FACE); 
glEnable(GL_FOG);
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D,T_Flare);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glEnable(GL_BLEND);
glColor4f(1,1,1,1);
glColor3f(255,0,0);
glPushMatrix(); 
		
glTranslatef(veins[1].x,veins[1].y+200,veins[1].z);
cyl->Cylindre_Deforme(fct*0.05,fct*0.05,fct*0.05);
glScalef(flame[9].scale,1,1);
glRotatef(90,45,90,1);
 cyl->Cylindre_affiche();




glPopMatrix();
glDisable(GL_LIGHTING);
glDisable(GL_FOG);
glDisable(GL_BLEND);
glDisable(GL_TEXTURE_2D);


}}
glPushMatrix();
glBlendFunc(GL_SRC_ALPHA,GL_ONE);
glEnable(GL_BLEND);
glColor4f(0.5,0.5,0.5,1);
if(fct<200)
Affiche_texte("mental ressurection\n",20,150,300,T_Fonte,fct);else
Affiche_texte("mental ressurection\n",20,150,300,T_Fonte,200);
glDisable(GL_BLEND);
glPopMatrix();

BARS();


}
else if(ord==9){if(row==0)fct=0;
glClearColor(1-fct*0.2,1-fct*0.2,1-fct*0.2,1);

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glBlendFunc(GL_SRC_ALPHA,GL_ONE);
glLoadIdentity();	


 for(loop=0;loop<=1550;loop++){
 
if(RAND(1,100)==2){star[loop].burn=1;}
if(star[loop].burn){ 

glDisable(GL_FOG);
glPushMatrix();




glEnable(GL_TEXTURE_2D);
glBlendFunc(GL_SRC_ALPHA,GL_ONE);
glBindTexture(GL_TEXTURE_2D,T_Flare);
glEnable(GL_BLEND);



  glColor4f(2*star[loop].ct*0.02,star[loop].ct*0.02,star[loop].ct*0.02,1);
    glTranslatef(-10+star[loop].x*0.1-sin(star[loop].ct),-7+star[loop].y*0.06,-20+star[loop].ct*2);

  
 



glScalef(0.2,0.2,0.2);
glRotatef(star[loop].ct*20,0,0,1);
 glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,-1.0f, 0.0f);
			glTexCoord2f(1.0f, 0.0f);glVertex3f( 1.0f,-1.0f, 0.0f);
			glTexCoord2f(1.0f, 1.0f);glVertex3f( 1.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 1.0f);glVertex3f(-1.0f, 1.0f, 0.0f);
		glEnd();
glDisable(GL_BLEND);

glDisable(GL_TEXTURE_2D);	
glPopMatrix();


}

	}


 gluLookAt(200,100,60,  -5,100,-50, 0,0,1);

glTranslatef(0,0,10);

TITAN();

for(loop=0;loop<=100;loop++){

glPushMatrix();
glTranslatef(star[loop].x,star[loop].y,star[loop].z);
glPopMatrix();

}
glPushMatrix();
glBlendFunc(GL_SRC_ALPHA,GL_ONE);
glEnable(GL_BLEND);
glColor4f(0.5,0.5,0.5,1);
if(fct<200)
Affiche_texte("divine halo\n",20,sin(fct),300,T_Fonte,fct);else
Affiche_texte("divine halo\n",20,sin(fct),300,T_Fonte,200);
glDisable(GL_BLEND);
glPopMatrix();


BARS();
}


else if(ord==10 || ord==11){
if(row==0)fct=0;
glClearColor(1-fct*0.2,1-fct*0.2,1-fct*0.2,1);

float lp=0;
if(row==0){skala=0;fct=0;}
else {
if(ord==11){glClearColor(1-fct*0.02,1-fct*0.02,1-fct*0.02,1);}
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glBlendFunc(GL_SRC_ALPHA,GL_ONE);
glLoadIdentity();	
glRotatef(fct,0,0,1);
if(ord!=10){

 for(loop=0;loop<=550;loop++){
 
if(RAND(1,11)==2){star[loop].burn=1;}
//if(star[loop].burn){ 

glDisable(GL_FOG);
glPushMatrix();




glEnable(GL_TEXTURE_2D);
glBlendFunc(GL_SRC_ALPHA,GL_ONE);
glBindTexture(GL_TEXTURE_2D,T_Flare);
glEnable(GL_BLEND);



  glColor4f(2*star[loop].ct*0.2,star[loop].ct*0.2,star[loop].ct*0.2,1);
    glTranslatef(-2+star[loop].x*0.01-sin(star[loop].ct*5),-15+star[loop].y*0.2,-50+sin(star[loop].ct));

  
 



glScalef(0.2,0.2,0.2);
glRotatef(star[loop].ct*50,0,0,1);
 glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,-1.0f, 0.0f);
			glTexCoord2f(1.0f, 0.0f);glVertex3f( 1.0f,-1.0f, 0.0f);
			glTexCoord2f(1.0f, 1.0f);glVertex3f( 1.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 1.0f);glVertex3f(-1.0f, 1.0f, 0.0f);
		glEnd();
glDisable(GL_BLEND);

glDisable(GL_TEXTURE_2D);	
glPopMatrix();


}
}
//	}
if(ord==10)
gluLookAt(300,0,10-fct,fct,1,-60,0,0,1);
else if(ord==11)
  gluLookAt(50,0,-10,  -35,0,-60,0,0,1);

for(loop=1;loop<20;loop++){
glDisable(GL_CULL_FACE); 
glEnable(GL_FOG);
glEnable(GL_TEXTURE_2D);
//glBindTexture(GL_TEXTURE_2D,T_Vein);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glEnable(GL_BLEND);
glColor4f(1,1,1,1);
glColor3f(255,0,0);
glPushMatrix(); 
glTranslatef(-10+point[loop].x*0.05,-15+point[loop].y*0.04+loop,-50-star[loop].z);
//glRotatef(fct-point[loop].z*0.5,0,fct-point[loop].z*0.5,1);


cyl->Cylindre_Deforme(fct*0.05,fct*0.05,fct*0.5);
if(fct<10){skala=fct*0.5;}
glScalef(1.5,1.5,skala);
 cyl->Cylindre_affiche();

 

glPopMatrix();
glDisable(GL_LIGHTING);
glDisable(GL_FOG);
glDisable(GL_BLEND);
glDisable(GL_TEXTURE_2D);

}
 



}
if(ord==10){
glPushMatrix();
glBlendFunc(GL_SRC_ALPHA,GL_ONE);
glEnable(GL_BLEND);
glColor4f(0.5,0.5,0.5,1);
Affiche_texte("code ipe\nidea irokos\n",20,100,300,T_Fonte,fct);
Affiche_texte("idea irokos\n",20,150,200,T_Fonte,fct*-1);
Affiche_texte("msx paledeth\n",20,250,100,T_Fonte,fct*-1);
glDisable(GL_BLEND);
glPopMatrix();}else if(ord==11){
glPushMatrix();
glBlendFunc(GL_SRC_ALPHA,GL_ONE);
glEnable(GL_BLEND);
glColor4f(0.5,0.5,0.5,1);
Affiche_texte("titans two o o five\n",20,420,100,T_Fonte,1);
glDisable(GL_BLEND);
glPopMatrix();

}

BARS();

/*for(lp=-10;lp<=1;lp+=0.1){
BAR(0,lp);
}*/

}


else if(ord>=12){
if(row==0)fct=0;
if(row<50){
glClearColor(1-fct*0.02,1-fct*0.02,1-fct*0.02,1);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glPushMatrix();
//glBlendFunc(GL_SRC_ALPHA,GL_ONE);
//glEnable(GL_BLEND);
glColor4f(0.5,0.5,0.5,1);
glDisable(GL_BLEND);
glPopMatrix();}
if(row>60){

#ifdef USEFMOD
	FMUSIC_FreeSong(mod);
	FSOUND_Close();
#endif
return 0;
}
									// Kill The Window
}




    frames++;    
   
	  total_fps+=frames;

	  
//sprintf(efpe,"Pos: %i Row: %i",ord,row);

 	 
					SwapBuffers(hDC);				// Swap Buffers (Double Buffering)

				}
			}
		}
	}
  
	// Shutdown
	KillGLWindow();									// Kill The Window


	// STOP SONG
#ifdef USEFMOD
	FMUSIC_FreeSong(mod);
	FSOUND_Close();

	//sprintf(efpe,"Speed rated with %i points!",total_fps);
	//MessageBox(0,efpe,efpe,MB_OK);

#endif
	return 0;
}







 



void RAZOR(){
 
glBegin(GL_TRIANGLES);
glVertex2f(0,0);
glVertex2f(10,0);
glVertex2f(0,10);

glVertex2f(0,10);
glVertex2f(10,10);
glVertex2f(0,20);

glVertex2f(10,0);
glVertex2f(20,0);
glVertex2f(10,10);



glEnd();



}



void BAR(float x,float y){
glLoadIdentity();
glPushMatrix();
glDisable(GL_TEXTURE_2D);
glTranslatef(x,y,-1);
glColor3f(0,0,0);
glScalef(1,1,1);
	glRotatef(180,0,0,1);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,00.001f, 0.0f);
			glTexCoord2f(1.0f, 0.0f);glVertex3f( 1.0f,00.001f, 0.0f);
			glTexCoord2f(1.0f, 1.0f);glVertex3f( 1.0f,00.0f, 0.0f);
			glTexCoord2f(0.0f, 1.0f);glVertex3f(-1.0f,00.0f, 0.0f);
		glEnd();

glPopMatrix();

}

void BARS(){

glLoadIdentity();
glPushMatrix();
glDisable(GL_TEXTURE_2D);
glTranslatef(0,-1.3,-1);
glColor3f(0,0,0);
glScalef(10,1,1);
	glRotatef(180,0,0,1);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,-1.0f, 0.0f);
			glTexCoord2f(1.0f, 0.0f);glVertex3f( 1.0f,-1.0f, 0.0f);
			glTexCoord2f(1.0f, 1.0f);glVertex3f( 1.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 1.0f);glVertex3f(-1.0f, 1.0f, 0.0f);
		glEnd();

glPopMatrix();

glPushMatrix();
glDisable(GL_TEXTURE_2D);
glTranslatef(0,1.3,-1);

glScalef(10,1,1);
	glRotatef(180,0,0,1);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,-1.0f, 0.0f);
			glTexCoord2f(1.0f, 0.0f);glVertex3f( 1.0f,-1.0f, 0.0f);
			glTexCoord2f(1.0f, 1.0f);glVertex3f( 1.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 1.0f);glVertex3f(-1.0f, 1.0f, 0.0f);
		glEnd();

glPopMatrix();


 }



TITAN(){
glDisable(GL_CULL_FACE); 
glEnable(GL_FOG);
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D,T_Flare);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glEnable(GL_BLEND);
glColor4f(1,1,1,1);
glColor3f(255,0,0);
glPushMatrix(); 
veins[1].x=0;
veins[1].y=0;
veins[1].z=-50;
			
glTranslatef(veins[1].x,veins[1].y,veins[1].z);


cyl->Cylindre_Deforme(fct*0.05,fct*0.05,fct*0.05);
if(fct<10){skala=fct*0.5;}
glScalef(4,1,1);
glRotatef(90,0,90,1);
 cyl->Cylindre_affiche();



glPopMatrix();
glDisable(GL_LIGHTING);
glDisable(GL_FOG);
glDisable(GL_BLEND);
glDisable(GL_TEXTURE_2D);
glDisable(GL_CULL_FACE); 
glEnable(GL_FOG);
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D,T_Flare);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glEnable(GL_BLEND);
glColor4f(1,1,1,1);
glColor3f(255,0,0);
glPushMatrix(); 
veins[1].x=0;
veins[1].y=0;
veins[1].z=-50;
			

 

cyl->Cylindre_Deforme(fct*0.05,fct*0.05,fct*0.05);
glTranslatef(veins[1].x-70,veins[1].y,veins[1].z);
glRotatef(90,90,90,1);
glScalef(0.5,0.5,2);
 cyl->Cylindre_affiche();




glPopMatrix();
glDisable(GL_LIGHTING);
glDisable(GL_FOG);
glDisable(GL_BLEND);
glDisable(GL_TEXTURE_2D);


glDisable(GL_CULL_FACE); 
glEnable(GL_FOG);
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D,T_Flare);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glEnable(GL_BLEND);
glColor4f(1,1,1,1);
glColor3f(255,0,0);
glPushMatrix(); 
veins[1].x=0;
veins[1].y=0;
veins[1].z=-50;
			

 

cyl->Cylindre_Deforme(fct*0.05,fct*0.05,fct*0.05);
glTranslatef(veins[1].x,veins[1].y+30,veins[1].z);
glRotatef(90,0,90,1);
glScalef(1,1,2);
 cyl->Cylindre_affiche();




glPopMatrix();
glDisable(GL_LIGHTING);
glDisable(GL_FOG);
glDisable(GL_BLEND);
glDisable(GL_TEXTURE_2D);

glDisable(GL_CULL_FACE); 
glEnable(GL_FOG);
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D,T_Flare);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glEnable(GL_BLEND);
glColor4f(1,1,1,1);
glColor3f(255,0,0);
glPushMatrix(); 
		
glTranslatef(veins[1].x,veins[1].y+55,veins[1].z);
cyl->Cylindre_Deforme(fct*0.05,fct*0.05,fct*0.05);
glScalef(4,1,1);
glRotatef(90,0,90,1);
 cyl->Cylindre_affiche();




glPopMatrix();
glDisable(GL_LIGHTING);
glDisable(GL_FOG);
glDisable(GL_BLEND);
glDisable(GL_TEXTURE_2D);
 
glDisable(GL_CULL_FACE); 
glEnable(GL_FOG);
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D,T_Flare);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glEnable(GL_BLEND);
glColor4f(1,1,1,1);
glColor3f(255,0,0);
glPushMatrix(); 
		
glTranslatef(veins[1].x-140,veins[1].y+55,veins[1].z);
cyl->Cylindre_Deforme(fct*0.05,fct*0.05,fct*0.05);
glScalef(1,2,1);
glRotatef(90,90,90,1);
 cyl->Cylindre_affiche();




glPopMatrix();
glDisable(GL_LIGHTING);
glDisable(GL_FOG);
glDisable(GL_BLEND);
glDisable(GL_TEXTURE_2D);
glDisable(GL_CULL_FACE); 
glEnable(GL_FOG);
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D,T_Flare);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glEnable(GL_BLEND);
glColor4f(1,1,1,1);
glColor3f(255,0,0);
glPushMatrix(); 
		
glTranslatef(veins[1].x,veins[1].y+85,veins[1].z);
cyl->Cylindre_Deforme(fct*0.05,fct*0.05,fct*0.05);
glScalef(4,1,1);
glRotatef(90,45,90,1);
 cyl->Cylindre_affiche();




glPopMatrix();
glDisable(GL_LIGHTING);
glDisable(GL_FOG);
glDisable(GL_BLEND);
glDisable(GL_TEXTURE_2D);

glDisable(GL_CULL_FACE); 
glEnable(GL_FOG);
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D,T_Flare);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glEnable(GL_BLEND);
glColor4f(1,1,1,1);
glColor3f(255,0,0);
glPushMatrix(); 
		
glTranslatef(veins[1].x,veins[1].y+110,veins[1].z);
cyl->Cylindre_Deforme(fct*0.05,fct*0.05,fct*0.05);
glScalef(4,1,1);
glRotatef(90,-45,90,1);
 cyl->Cylindre_affiche();




glPopMatrix();
glDisable(GL_LIGHTING);
glDisable(GL_FOG);
glDisable(GL_BLEND);
glDisable(GL_TEXTURE_2D);
glDisable(GL_CULL_FACE); 
glEnable(GL_FOG);
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D,T_Flare);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glEnable(GL_BLEND);
glColor4f(1,1,1,1);
glColor3f(255,0,0);
glPushMatrix(); 
		
glTranslatef(veins[1].x,veins[1].y+100,veins[1].z);
cyl->Cylindre_Deforme(fct*0.05,fct*0.05,fct*0.05);
glScalef(1,2,1);
glRotatef(90,180,90,1);
 cyl->Cylindre_affiche();




glPopMatrix();
glDisable(GL_LIGHTING);
glDisable(GL_FOG);
glDisable(GL_BLEND);
glDisable(GL_TEXTURE_2D);


glDisable(GL_CULL_FACE); 
glEnable(GL_FOG);
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D,T_Flare);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glEnable(GL_BLEND);
glColor4f(1,1,1,1);
glColor3f(255,0,0);
glPushMatrix(); 
		
glTranslatef(veins[1].x,veins[1].y+160,veins[1].z);
cyl->Cylindre_Deforme(fct*0.05,fct*0.05,fct*0.05);
glScalef(2,1,1);
glRotatef(90,45,90,1);
 cyl->Cylindre_affiche();




glPopMatrix();
glDisable(GL_LIGHTING);
glDisable(GL_FOG);
glDisable(GL_BLEND);
glDisable(GL_TEXTURE_2D);


glDisable(GL_CULL_FACE); 
glEnable(GL_FOG);
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D,T_Flare);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glEnable(GL_BLEND);
glColor4f(1,1,1,1);
glColor3f(255,0,0);
glPushMatrix(); 
		
glTranslatef(veins[1].x,veins[1].y+180,veins[1].z);
cyl->Cylindre_Deforme(fct*0.05,fct*0.05,fct*0.05);
glScalef(2,1,1);
glRotatef(90,-45,90,1);
 cyl->Cylindre_affiche();




glPopMatrix();
glDisable(GL_LIGHTING);
glDisable(GL_FOG);
glDisable(GL_BLEND);
glDisable(GL_TEXTURE_2D);

glDisable(GL_CULL_FACE); 
glEnable(GL_FOG);
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D,T_Flare);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glEnable(GL_BLEND);
glColor4f(1,1,1,1);
glColor3f(255,0,0);
glPushMatrix(); 
		
glTranslatef(veins[1].x,veins[1].y+200,veins[1].z);
cyl->Cylindre_Deforme(fct*0.05,fct*0.05,fct*0.05);
glScalef(2,1,1);
glRotatef(90,45,90,1);
 cyl->Cylindre_affiche();




glPopMatrix();
glDisable(GL_LIGHTING);
glDisable(GL_FOG);
glDisable(GL_BLEND);
glDisable(GL_TEXTURE_2D);



}