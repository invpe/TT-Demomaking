int numero=10;
float ct=120;	int yy=0;
int ks;
float spin=0;
#define DSPIN (float)(3.14/360)
float dspin=DSPIN;
float zoom=1.0;
const	num=8000;				// Number Of Stars To Draw

struct v{

float x;
float y;
float z;

}veins[num];


 struct	s			// Create A Structure For Star
{
	int r, g, b;			// Stars Color
	GLfloat dist,			// Stars Distance From Center
			angle;			// Stars Current Angle
GLuint txt;
GLuint xx;
float x,y,z;
int burn;
float scale;
float ct;
float rspeed;
float ct2;
 }
point[num];	




















 struct	ss			// Create A Structure For Star
{
	int r, g, b;			// Stars Color
	GLfloat dist,			// Stars Distance From Center
			angle;			// Stars Current Angle
GLuint txt;
GLuint xx;
float x,y,z;
int burn;
float scale;
float ct;
float rspeed;
float ct2;
 }
xstar[num];	


 struct	sss			// Create A Structure For Star
{
	int r, g, b;			// Stars Color
	GLfloat dist,			// Stars Distance From Center
			angle;			// Stars Current Angle
GLuint txt;
GLuint xx;
float x;
float y;
float z;
int burn;
float scale;
float ct;
float rspeed;
float ct2;

 }
flame[num];	


typedef struct				// Create A Structure For Star
{
	int r, g, b;			// Stars Color
	GLfloat dist,			// Stars Distance From Center
			angle;			// Stars Current Angle
GLuint txt;
GLuint xx;
float x,y,z;
int burn;
float scale;
float ct;
int ct3;
int color;
int dir;
float rspeed;

}
stars;
stars star[num];	

struct
{
  __int64       frequency;          // Timer Frequency
  GLdouble            resolution;          // Timer Resolution
  unsigned long mm_timer_start;     
  
  // Multimedia Timer Start Value
  unsigned long mm_timer_elapsed;      // Multimedia Timer Elapsed Time
  bool   performance_timer;    
  
  // Using The Performance Timer?
  __int64       performance_timer_start;      // Performance Timer Start Value
  __int64       performance_timer_elapsed; // Performance Timer Elapsed Time
} timer;





 struct	eks			// Create A Structure For Star
{
	int r, g, b;			// Stars Color
	GLfloat dist,			// Stars Distance From Center
			angle;			// Stars Current Angle
GLuint txt;
GLuint xx;
float x,y,z;
int burn;
float scale;
float ct;
float rspeed;
float ct2;
 }
flow[30][num];	

