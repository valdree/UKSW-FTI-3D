#include <windows.h>
#include <GL/glut.h>


// Valdy Reado Silaen - 672019010
// Zefanya Loudewieq Gabriel Lala - 672019100
// Rezky Agung Kurniawan Ta'ewa - 672019295

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;

void Init(void) {
    glClearColor(0.0, 0.0, 1.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW);
}

void Display(void) {


    int i, j;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);

    //Alas Besar
    glBegin(GL_QUADS);
    glColor3ub(50, 205, 50);
    glVertex3i(-190, 0, 190);
    glVertex3i(190, 0, 190);
    glVertex3i(190, 0, -190);
    glVertex3i(-190, 0, -190);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(50, 205, 50);
    glVertex3i(-120, 0, 120);
    glVertex3i(120, 0, 120);
    glVertex3i(120, 0, -120);
    glVertex3i(-120, 0, -120);
    glEnd();

    //atap
    glBegin(GL_QUADS);
    glColor3ub(128, 0, 0);
    glVertex3i(30, 60, -30);//a19
    glVertex3i(-10, 60, -30);//b19
    glVertex3i(-10, 60, 30);//c19
    glVertex3i(30, 60, 30);//d19
    glEnd();


    //dinding

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 250);
    glVertex3i(30, 60, 30);//a19
    glVertex3i(30, 0, 30);//b19
    glVertex3i(30, 0, -30);//c19
    glVertex3i(30, 60, -30);//d19
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 250);
    glVertex3i(-10, 60, 30);//a19
    glVertex3i(-10, 0, 30);//b19
    glVertex3i(-10, 0, -30);//c19
    glVertex3i(-10, 60, -30);//d19
    glEnd();




    glBegin(GL_QUADS);
    glColor3ub(255, 250, 250);
    glVertex3i(-10, 60, 30);//a19
    glVertex3i(-10, 0, 30);//b19
    glVertex3i(30, 0, 30);//c19
    glVertex3i(30, 60, 30);//d19
    glEnd();

    // dinding depan pintu
    glBegin(GL_QUADS);
    glColor3ub(255, 250, 250);
    glVertex3i(-10, 60, -30);//a19
    glVertex3i(-10, 0, -30);//b19
    glVertex3i(30, 0, -30);//c19
    glVertex3i(30, 60, -30);//d19
    glEnd();

 //Jendela
    glColor3f(0.25, 0.26, 0.33);
    for (j = 0; j < 17; j++) {
        glPushMatrix();
        glTranslatef(-2.3 * j, 0, 0); //Horizontal
        for (i = 0; i < 8; i++) {
            glPushMatrix();
            glTranslatef(-1, -4 * i, 0); //Vertical
            glBegin(GL_POLYGON);
            glVertex3f(31, 57, -30.1);
            glVertex3f(29, 57, -30.1);
            glVertex3f(29, 54, -30.1);
            glVertex3f(31, 54, -30.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }

    //garis pemisah jendela 1
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3f(18, 60, -30.2);
    glVertex3f(16, 60, -30.2);
    glVertex3f(16, 24, -30.2);
    glVertex3f(18, 24, -30.2);
    glEnd();

    //garis pemisah jendela 2
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3f(5, 60, -30.2);
    glVertex3f(3, 60, -30.2);
    glVertex3f(3, 42, -30.2);
    glVertex3f(5, 42, -30.2);
    glEnd();

    //garis pemisah jendela 3
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3f(18, 42, -30.2);
    glVertex3f(-10, 42, -30.2);
    glVertex3f(-10, 40, -30.2);
    glVertex3f(18, 40, -30.2);
    glEnd();


    //garis pemisah jendela 4
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3f(12, 42, -30.2);
    glVertex3f(10, 42, -30.2);
    glVertex3f(10, 20, -30.2);
    glVertex3f(12, 20, -30.2);
    glEnd();


    //garis pemisah jendela 5
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3f(-5, 42, -30.2);
    glVertex3f(-3, 42, -30.2);
    glVertex3f(-3, 20, -30.2);
    glVertex3f(-5, 20, -30.2);
    glEnd();




  //pintu masuk
    glBegin(GL_QUADS);
    glColor3ub(179, 255, 255);
    glVertex3f(15.2, 0, -30.2);//a19
    glVertex3f(10.2, 0, -30.2);//b19
    glVertex3f(10.2, 12.14, -30.2);//c19
    glVertex3f(15.2, 12.14, -30.2);//d19
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(179, 255, 255);
    glVertex3f(5.2, 0, -30.2);//a19
    glVertex3f(10.2, 0, -30.2);//b19
    glVertex3f(10.2, 12.14, -30.2);//c19
    glVertex3f(5.2, 12.14, -30.2);//d19
    glEnd();

    //Garis pintu
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3f(10.2, 0, -30.4);
    glVertex3f(10.2, 12.14, -30.4);
    glEnd();


    //gedung panjang
    //side2 kiri
    glBegin(GL_QUADS);
    glColor3ub(255, 250, 250);
    glVertex3i(60, 0, -10);
    glVertex3i(60, 0, 10);
    glVertex3i(60, 40, 10);
    glVertex3i(60, 40, -10);
    glEnd();

    //side3 kanan

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 250);
    glVertex3i(-60, 0, -10);
    glVertex3i(-60, 0, 10);
    glVertex3i(-60, 40, 10);
    glVertex3i(-60, 40, -10);
    glEnd();




    //side5 atap
    glBegin(GL_QUADS);
    glColor3ub(255, 250, 250);
    glVertex3i(60, 40, -10);
    glVertex3i(60, 40, 10);
    glVertex3i(-60, 40, 10);
    glVertex3i(-60, 40, -10);
    glEnd();



    //side depan
    glBegin(GL_QUADS);
    glColor3ub(255, 250, 250);
    glVertex3i(-60, 0, 10);
    glVertex3i(60, 0, 10);
    glVertex3i(60, 40, 10);
    glVertex3i(-60, 40, 10);
    glEnd();

    //side belakang
    glBegin(GL_QUADS);
    glColor3ub(255, 250, 250);
    glVertex3i(-60, 0, -10);
    glVertex3i(60, 0, -10);
    glVertex3i(60, 40, -10);
    glVertex3i(-60, 40, -10);
    glEnd();


    //lantai
    glBegin(GL_QUADS);
    glColor3ub(255, 250, 250);
    glVertex3i(-60, 0, 10);
    glVertex3i(-60, 0, -10);
    glVertex3i(60, 0, -10);
    glVertex3i(60, 0, 10);
    glEnd();


    // bangunan belakang FTI
    //kotak luar
    glBegin(GL_QUADS);
    glColor3ub(255, 250, 250);
    glVertex3i(40, 20, 60);
    glVertex3i(40, 0, 60);
    glVertex3i(-40, 0, 60);
    glVertex3i(-40, 20, 60);
    glEnd();

    //kotak kiri
    glBegin(GL_QUADS);
    glColor3ub(255, 250, 250);
    glVertex3i(40, 20, 60);
    glVertex3i(40, 0, 60);
    glVertex3i(40, 0, 40);
    glVertex3i(40, 20, 40);
    glEnd();

    //kotak dalam
    glBegin(GL_QUADS);
    glColor3ub(255, 250, 250);
    glVertex3i(40, 20, 40);
    glVertex3i(40, 0, 40);
    glVertex3i(-40, 0, 40);
    glVertex3i(-40, 20, 40);
    glEnd();

    //kotak kanan
    glBegin(GL_QUADS);
    glColor3ub(255, 250, 250);
    glVertex3i(-40, 20, 40);
    glVertex3i(-40, 0, 40);
    glVertex3i(-40, 0, 60);
    glVertex3i(-40, 20, 60);
    glEnd();

    //kotak bawah
    glBegin(GL_QUADS);
    glColor3ub(255, 250, 250);
    glVertex3i(-40, 2, 60);
    glVertex3i(-40, 2, 40);
    glVertex3i(40, 2, 40);
    glVertex3i(40, 2, 60);
    glEnd();

    //kotak atas
    glBegin(GL_QUADS);
    glColor3ub(255, 250, 250);
    glVertex3i(-40, 20, 60);
    glVertex3i(-40, 20, 40);
    glVertex3i(40, 20, 40);
    glVertex3i(40, 20, 60);
    glEnd();

    //jembatan kecil dalam
    glBegin(GL_QUADS);
    glColor3ub(255, 250, 250);
    glVertex3i(0, 5, 30);
    glVertex3i(5, 5, 30);
    glVertex3i(5, 10, 30);
    glVertex3i(0, 10, 30);
    glEnd();

    //jembatan kecil kanan
    glBegin(GL_QUADS);
    glColor3ub(255, 250, 250);
    glVertex3i(0, 5, 30);
    glVertex3i(0, 10, 30);
    glVertex3i(0, 10, 40);
    glVertex3i(0, 5, 40);
    glEnd();

    //jembatan kecil luar
    glBegin(GL_QUADS);
    glColor3ub(255, 250, 250);
    glVertex3i(0, 10, 40);
    glVertex3i(0, 5, 40);
    glVertex3i(5, 5, 40);
    glVertex3i(5, 10, 40);
    glEnd();

    //jembatan kecil kiri
    glBegin(GL_QUADS);
    glColor3ub(255, 250, 250);
    glVertex3i(5, 10, 40);
    glVertex3i(5, 5, 40);
    glVertex3i(5, 5, 30);
    glVertex3i(5, 10, 30);
    glEnd();

    //jembatan atas
    glBegin(GL_QUADS);
    glColor3ub(169, 169, 169);
    glVertex3i(5, 10, 40);
    glVertex3i(5, 10, 30);
    glVertex3i(0, 10, 30);
    glVertex3i(0, 10, 40);
    glEnd();

    //jembatan bawah
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3i(5, 5, 40);
    glVertex3i(5, 5, 30);
    glVertex3i(0, 5, 30);
    glVertex3i(0, 5, 40);
    glEnd();
    //pintu
    glBegin(GL_QUADS);
    glColor3ub(160, 82, 45);
    glVertex3f( -40.2, 0, 42.2);
    glVertex3f( -40.2, 0, 46.2);
    glVertex3f( -40.2, 9.20596, 46.2);
    glVertex3f( -40.2, 9.20596, 42.2);
    glEnd();

     //jendela
    glBegin(GL_QUADS);
   glColor3f(0.25, 0.26, 0.33);
    glVertex3f( 30.2, 15, 60.2);
    glVertex3f( -30.2, 15, 60.2);
    glVertex3f( -30.2, 4, 60.2);
    glVertex3f( 30.2, 4, 60.2);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 1);
    glVertex3f( 30.2, 10, 60.2);
    glVertex3f( -30.2, 10, 60.2);

    glVertex3f( 20.2, 15, 60.2);
    glVertex3f( 20.2, 4, 60.2);

    glVertex3f( 10.2, 15, 60.2);
    glVertex3f( 10.2, 4, 60.2);

    glVertex3f( 0.2, 15, 60.2);
    glVertex3f( 0.2, 4, 60.2);

    glVertex3f( -10.2, 15, 60.2);
    glVertex3f( -10.2, 4, 60.2);

    glVertex3f( -20.2, 15, 60.2);
    glVertex3f( -20.2, 4, 60.2);

    glEnd();

    glLineWidth(5);
    glBegin(GL_LINE_LOOP);
    glColor3ub(255, 255, 255);
    glVertex3f( 30.2, 15, 60.2);
    glVertex3f( -30.2, 15, 60.2);
    glVertex3f( -30.2, 4, 60.2);
    glVertex3f( 30.2, 4, 60.2);
    glEnd();




    //jembatan gedung pojok
    //side1 belakakang
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3i(-60, 30, -10);
    glVertex3i(-70, 30, -10);
    glVertex3i(-70, 10, -10);
    glVertex3i(-60, 10, -10);
    glEnd();
    //side2 atap
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3i(-60, 30, -10);
    glVertex3i(-70, 30, -10);
    glVertex3i(-70, 30, 10);
    glVertex3i(-60, 30, 10);
    glEnd();
    //side3 depan
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3i(-70, 30, 10);
    glVertex3i(-60, 30, 10);
    glVertex3i(-60, 10, 10);
    glVertex3i(-70, 10, 10);
    glEnd();

    //side4 alas
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3i(-70, 10, 10);
    glVertex3i(-60, 10, 10);
    glVertex3i(-60, 10, -10);
    glVertex3i(-70, 10, -10);
    glEnd();

    //gedung pojok
    //side1 belakang
    glBegin(GL_QUADS);
    glColor3ub(255, 250, 250);
    glVertex3i(-70, 38, -10);
    glVertex3i(-90, 38, -10);
    glVertex3i(-90, 0, -10);
    glVertex3i(-70, 0, -10);
    glEnd();

    //side1 kiri
    glBegin(GL_QUADS);
    glColor3ub(255, 250, 250);
    glVertex3i(-90, 38, -10);
    glVertex3i(-90, 38, 10);
    glVertex3i(-90, 0, 10);
    glVertex3i(-90, 0, -10);
    glEnd();

    //side1 depan
    glBegin(GL_QUADS);
    glColor3ub(255, 250, 250);
    glVertex3i(-90, 38, 10);
    glVertex3i(-70, 38, 10);
    glVertex3i(-70, 0, 10);
    glVertex3i(-90, 0, 10);
    glEnd();

    //side1 kanan
    glBegin(GL_QUADS);
    glColor3ub(255, 250, 250);
    glVertex3i(-70, 38, 10);
    glVertex3i(-70, 38, -10);
    glVertex3i(-70, 0, -10);
    glVertex3i(-70, 0, 10);
    glEnd();

    //side1 atap
    glBegin(GL_QUADS);
    glColor3ub(255, 250, 250);
    glVertex3i(-90, 38, 10);
    glVertex3i(-70, 38, 10);
    glVertex3i(-70, 38, -10);
    glVertex3i(-90, 38, -10);
    glEnd();

    //pillar
    //atap
    glBegin(GL_QUADS);
    glColor3ub(255, 250, 250);
    glVertex3i(30, 25, -10);
    glVertex3i(30, 25, -20);
    glVertex3i(65, 25, -20);
    glVertex3i(65, 25, -10);
    glEnd();


    //depan
    glBegin(GL_QUADS);
    glColor3ub(255, 250, 250);
    glVertex3i(30, 20, -20);
    glVertex3i(30, 25, -20);
    glVertex3i(65, 25, -20);
    glVertex3i(65, 20, -20);
    glEnd();

    //belakang
    glBegin(GL_QUADS);
    glColor3ub(255, 250, 250);
    glVertex3i(30, 20, -10);
    glVertex3i(30, 25, -10);
    glVertex3i(65, 25, -10);
    glVertex3i(65, 20, -10);
    glEnd();

    //bawah
    glBegin(GL_QUADS);
    glColor3ub(255, 250, 250);
    glVertex3i(30, 20, -10);
    glVertex3i(30, 20, -20);
    glVertex3i(65, 20, -20);
    glVertex3i(65, 20, -10);
    glEnd();

    //samping
    glBegin(GL_QUADS);
    glColor3ub(255, 250, 250);
    glVertex3i(65, 25, -10);
    glVertex3i(65, 25, -20);
    glVertex3i(65, 20, -20);
    glVertex3i(65, 20, -10);
    glEnd();

    //pilar 1
    //atas
    glBegin(GL_QUADS);
    glColor3ub(48,56,79);
    glVertex3i(30, 25, -10);
    glVertex3i(30, 25, -20);
    glVertex3i(65, 25, -20);
    glVertex3i(65, 25, -10);
    glEnd();


    //depan
    glBegin(GL_QUADS);
    glColor3ub(48,56,79);
    glVertex3i(34, 20, -20);
    glVertex3i(32, 20, -20);
    glVertex3i(32, 0, -20);
    glVertex3i(34, 0, -20);
    glEnd();

    //belakang
    glBegin(GL_QUADS);
    glColor3ub(48,56,79);
    glVertex3i(34, 20, -18);
    glVertex3i(32, 20, -18);
    glVertex3i(32, 0, -18);
    glVertex3i(34, 0, -18);
    glEnd();

    //bawah
    glBegin(GL_QUADS);
    glColor3ub(48,56,79);
    glVertex3i(30, 20, -10);
    glVertex3i(30, 20, -20);
    glVertex3i(65, 20, -20);
    glVertex3i(65, 20, -10);
    glEnd();

    //samping kiri
    glBegin(GL_QUADS);
    glColor3ub(48,56,79);
    glVertex3i(34, 20, -20);
    glVertex3i(34, 20, -18);
    glVertex3i(34, 0, -18);
    glVertex3i(34, 0, -20);
    glEnd();

    //samping kanan
    glBegin(GL_QUADS);
    glColor3ub(48,56,79);
    glVertex3i(32, 20, -20);
    glVertex3i(32, 20, -18);
    glVertex3i(32, 0, -18);
    glVertex3i(32, 0, -20);
    glEnd();

    //pilar 2
       //atas
    glBegin(GL_QUADS);
    glColor3ub(48,56,79);
    glVertex3i(30, 25, -10);
    glVertex3i(30, 25, -20);
    glVertex3i(65, 25, -20);
    glVertex3i(65, 25, -10);
    glEnd();


    //depan
    glBegin(GL_QUADS);
    glColor3ub(48,56,79);
    glVertex3i(60, 20, -20);
    glVertex3i(58, 20, -20);
    glVertex3i(58, 0, -20);
    glVertex3i(60, 0, -20);
    glEnd();

    //belakang
    glBegin(GL_QUADS);
    glColor3ub(48,56,79);
    glVertex3i(60, 20, -18);
    glVertex3i(58, 20, -18);
    glVertex3i(58, 0, -18);
    glVertex3i(60, 0, -18);
    glEnd();

    //bawah
    glBegin(GL_QUADS);
    glColor3ub(48,56,79);
    glVertex3i(30, 20, -10);
    glVertex3i(30, 20, -20);
    glVertex3i(65, 20, -20);
    glVertex3i(65, 20, -10);
    glEnd();

    //samping kiri
    glBegin(GL_QUADS);
    glColor3ub(48,56,79);
    glVertex3i(60, 20, -20);
    glVertex3i(60, 20, -18);
    glVertex3i(60, 0, -18);
    glVertex3i(60, 0, -20);
    glEnd();

    //samping kanan
    glBegin(GL_QUADS);
    glColor3ub(48,56,79);
    glVertex3i(58, 20, -20);
    glVertex3i(58, 20, -18);
    glVertex3i(58, 0, -18);
    glVertex3i(58, 0, -20);
    glEnd();


   //garis tembok depan
    //garis 1
    glBegin(GL_QUADS);
    glColor3ub(60, 12, 194);
    glVertex3i(-10, 35, -11);
    glVertex3i(-10, 30, -11);
    glVertex3i(-60, 30, -11);
    glVertex3i(-60, 35, -11);
    glEnd();

    //garis 2
    glBegin(GL_QUADS);
    glColor3ub(60, 12, 194);
    glVertex3i(-55, 30, -11);
    glVertex3i(-60, 30, -11);
    glVertex3i(-60, 10, -11);
    glVertex3i(-55, 10, -11);
    glEnd();

    //garis 3
    glBegin(GL_QUADS);
    glColor3ub(60, 12, 194);
    glVertex3i(-20, 10, -11);
    glVertex3i(-20, 5, -11);
    glVertex3i(-10, 5, -11);
    glVertex3i(-10, 10, -11);
    glEnd();

    //garis 4
    glBegin(GL_QUADS);
    glColor3ub(60, 12, 194);
    glVertex3i(-43, 10, -11);
    glVertex3i(-43, 5, -11);
    glVertex3i(-60, 5, -11);
    glVertex3i(-60, 10, -11);
    glEnd();


    //garis 5
    glBegin(GL_QUADS);
    glColor3ub(60, 12, 194);
    glVertex3i(-43, 23, -11);
    glVertex3i(-43, 19, -11);
    glVertex3i(-20, 19, -11);
    glVertex3i(-20, 23, -11);
    glEnd();


    //garis 6
    glBegin(GL_QUADS);
    glColor3ub(60, 12, 194);
    glVertex3i(-43, 10, -11);
    glVertex3i(-43, 23, -11);
    glVertex3i(-45, 23, -11);
    glVertex3i(-45, 10, -11);
    glEnd();


    //garis 7
    glBegin(GL_QUADS);
    glColor3ub(60, 12, 194);
    glVertex3i(-18, 10, -11);
    glVertex3i(-18, 23, -11);
    glVertex3i(-20, 23, -11);
    glVertex3i(-20, 10, -11);
    glEnd();


    //garis gedung pojok
    //side depan
    //garis1
    glBegin(GL_QUADS);
    glColor3ub(60, 12, 194);
    glVertex3i(-70, 38, -11);
    glVertex3i(-75, 38, -11);
    glVertex3i(-75, 15, -11);
    glVertex3i(-70, 15, -11);
    glEnd();
    //garis2
    glBegin(GL_QUADS);
    glColor3ub(60, 12, 194);
    glVertex3i(-75, 38, -11);
    glVertex3i(-75, 33, -11);
    glVertex3i(-85, 33, -11);
    glVertex3i(-85, 38, -11);
    glEnd();
    //garis3
    glBegin(GL_QUADS);
    glColor3ub(60, 12, 194);
    glVertex3i(-75, 20, -11);
    glVertex3i(-85, 20, -11);
    glVertex3i(-85, 15, -11);
    glVertex3i(-75, 15, -11);
    glEnd();
    //garis4
    glBegin(GL_QUADS);
    glColor3ub(60, 12, 194);
    glVertex3i(-85, 38, -11);
    glVertex3i(-90, 38, -11);
    glVertex3i(-90, 15, -11);
    glVertex3i(-85, 15, -11);
    glEnd();
    //side kanan
    //garis5
    glBegin(GL_QUADS);
    glColor3ub(60, 12, 194);
    glVertex3i(-91, 38, 11);
    glVertex3i(-91, 32, 11);
    glVertex3i(-91, 32, -11);
    glVertex3i(-91, 38, -11);
    glEnd();
    //garis6
    glBegin(GL_QUADS);
    glColor3ub(60, 12, 194);
    glVertex3i(-91, 32, -11);
    glVertex3i(-91, 32, -6);
    glVertex3i(-91, 20, -6);
    glVertex3i(-91, 20, -11);
    glEnd();
    //garis7
    glBegin(GL_QUADS);
    glColor3ub(60, 12, 194);
    glVertex3i(-91, 20, -11);
    glVertex3i(-91, 15, -11);
    glVertex3i(-91, 15, 11);
    glVertex3i(-91, 20, 11);
    glEnd();
    //garis8
    glBegin(GL_QUADS);
    glColor3ub(60, 12, 194);
    glVertex3i(-91, 32, 6);
    glVertex3i(-91, 32, 11);
    glVertex3i(-91, 20, 11);
    glVertex3i(-91, 20, 6);
    glEnd();
    //side belakang
     //garis1
    glBegin(GL_QUADS);
    glColor3ub(60, 12, 194);
    glVertex3i(-90, 38, 11);
    glVertex3i(-70, 38, 11);
    glVertex3i(-70, 32, 11);
    glVertex3i(-90, 32, 11);
    glEnd();
     //garis2
    glBegin(GL_QUADS);
    glColor3ub(60, 12, 194);
    glVertex3i(-90, 32, 11);
    glVertex3i(-85, 32, 11);
    glVertex3i(-85, 20, 11);
    glVertex3i(-90, 20, 11);
    glEnd();
    //garis3
    glBegin(GL_QUADS);
    glColor3ub(60, 12, 194);
    glVertex3i(-90, 20, 11);
    glVertex3i(-70, 20, 11);
    glVertex3i(-70, 15, 11);
    glVertex3i(-90, 15, 11);
    glEnd();
     //garis4
    glBegin(GL_QUADS);
    glColor3ub(60, 12, 194);
    glVertex3i(-75, 20, 11);
    glVertex3i(-70, 20, 11);
    glVertex3i(-70, 32, 11);
    glVertex3i(-75, 32, 11);
    glEnd();
    //garis atas atas kiri
      //garis1
    glBegin(GL_QUADS);
    glColor3ub(60, 12, 194);
    glVertex3i(60, 40, -11);
    glVertex3i(32, 40, -11);
    glVertex3i(32, 35, -11);
    glVertex3i(60, 35, -11);
    glEnd();
    //garis2
    glBegin(GL_QUADS);
    glColor3ub(60, 12, 194);
    glVertex3i(60, 35, -11);
    glVertex3i(55, 35, -11);
    glVertex3i(55, 0, -11);
    glVertex3i(60, 0, -11);
    glEnd();
    //garis3
    glBegin(GL_QUADS);
    glColor3ub(60, 12, 194);
    glVertex3i(55, 5, -11);
    glVertex3i(55, 0, -11);
    glVertex3i(32, 0, -11);
    glVertex3i(32, 5, -11);
    glEnd();
    //garis4
    glBegin(GL_QUADS);
    glColor3ub(60, 12, 194);
    glVertex3i(37, 35, -11);
    glVertex3i(32, 35, -11);
    glVertex3i(32, 5, -11);
    glVertex3i(37, 5, -11);
    glEnd();

    //bendera
 //tiang1
    glBegin(GL_QUADS);
    glColor3ub(192,196,196);
    glVertex3i(30, 40, -110);
    glVertex3i(32, 40, -110);
    glVertex3i(32, 0, -110);
    glVertex3i(30, 0, -110);
    glEnd();
    //tiang2
    glBegin(GL_QUADS);
    glColor3ub(192,196,196);
    glVertex3i(32, 40, -110);
    glVertex3i(32, 0, -110);
    glVertex3i(32, 0, -108);
    glVertex3i(32, 40, -108);
    glEnd();
    //tiang3
    glBegin(GL_QUADS);
    glColor3ub(192,196,196);
    glVertex3i(32, 40, -108);
    glVertex3i(30, 40, -108);
    glVertex3i(30, 0, -108);
    glVertex3i(32, 0, -108);
    glEnd();
    //tiang4
    glBegin(GL_QUADS);
    glColor3ub(192,196,196);
    glVertex3i(30, 40, -108);
    glVertex3i(30, 40, -110);
    glVertex3i(30, 0, -110);
    glVertex3i(30, 0, -108);
    glEnd();
    //atap
    glBegin(GL_QUADS);
    glColor3ub(192,196,196);
    glVertex3i(30, 40, -110);
    glVertex3i(30, 40, -108);
    glVertex3i(30, 40, -108);
    glVertex3i(30, 40, -110);
    glEnd();

    //bendera1
    glBegin(GL_QUADS);
    glColor3ub(225, 225, 225);
    glVertex3i(30, 31, -109);
    glVertex3i(30, 35, -109);
    glVertex3i(40, 35, -109);
    glVertex3i(40, 31, -109);
    glEnd();

    //bendera2
    glBegin(GL_QUADS);
    glColor3ub(225, 0, 0);
    glVertex3i(30, 35, -109);
    glVertex3i(40, 35, -109);
    glVertex3i(40, 39, -109);
    glVertex3i(30, 39, -109);
    glEnd();


    //atap pillar pintu masuk
    //atap
    glBegin(GL_QUADS);
    glColor3ub(170,173,173);

    //kanan
    glVertex3i(-25, 25, -30);
    glVertex3i(-15, 25, -65);


    //kiri
    glVertex3i(30, 25, -65);
    glVertex3i(30, 25, -30);
    glEnd();



    //bawah
    glBegin(GL_QUADS);
    //kanan
    glColor3ub(170,173,173);
    glVertex3i(-25, 20, -30);
    glVertex3i(-15, 20, -65);
    //kiri
    glVertex3i(30, 20, -65);
    glVertex3i(30, 20, -30);
    glEnd();


    //depan
    glBegin(GL_QUADS);
    glColor3ub(255, 250, 250);
    glVertex3i(-15, 20, -65);
    glVertex3i(-15, 25, -65);
    glVertex3i(30, 25, -65);
    glVertex3i(30, 20, -65);
    glEnd();

    //belakang
    glBegin(GL_QUADS);
    glColor3ub(255, 250, 250);
    glVertex3f(-25.2, 20, -30.2);
    glVertex3f(-25.2, 25, -30.2);
    glVertex3f(30.2, 25, -30.2);
    glVertex3f(30.2, 20, -30.2);
    glEnd();


    //samping
    glBegin(GL_QUADS);
    glColor3ub(255, 250, 250);
    glVertex3i(30, 25, -30);
    glVertex3i(30, 25, -65);
    glVertex3i(30, 20, -65);
    glVertex3i(30, 20, -30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 250, 250);
    glVertex3i(-25, 25, -30);
    glVertex3i(-15, 25, -65);
    glVertex3i(-15, 20, -65);
    glVertex3i(-25, 20, -30);
    glEnd();

   //pillar masuk kiri
    //depan
    glBegin(GL_QUADS);
    glColor3ub(48,56,79);
    glVertex3i(30, 20, -65);
    glVertex3i(28, 20, -65);
    glVertex3i(28, 0, -65);
    glVertex3i(30, 0, -65);
    glEnd();

    //belakang
    glBegin(GL_QUADS);
    glColor3ub(48,56,79);
    glVertex3i(30, 20, -63);
    glVertex3i(28, 20, -63);
    glVertex3i(28, 0, -63);
    glVertex3i(30, 0, -63);
    glEnd();

    //samping
    glBegin(GL_QUADS);
    glColor3ub(48,56,79);
    glVertex3i(30, 20, -63);
    glVertex3i(30, 20, -65);
    glVertex3i(30, 0, -65);
    glVertex3i(30, 0, -63);
    glEnd();


    //samping
    glBegin(GL_QUADS);
    glColor3ub(48,56,79);
    glVertex3i(28, 20, -63);
    glVertex3i(28, 20, -65);
    glVertex3i(28, 0, -65);
    glVertex3i(28, 0, -63);
    glEnd();


    //pillar masuk tengah
    //depan
    glBegin(GL_QUADS);
    glColor3ub(48,56,79);
    glVertex3i(-15, 20, -65);
    glVertex3i(-13, 20, -65);
    glVertex3i(-13, 0, -65);
    glVertex3i(-15, 0, -65);
    glEnd();

    //belakang
    glBegin(GL_QUADS);
    glColor3ub(48,56,79);
    glVertex3i(-15, 20, -63);
    glVertex3i(-13, 20, -63);
    glVertex3i(-13, 0, -63);
    glVertex3i(-15, 0, -63);
    glEnd();

    //samping
    glBegin(GL_QUADS);
    glColor3ub(48,56,79);
    glVertex3i(-15, 20, -63);
    glVertex3i(-15, 20, -65);
    glVertex3i(-15, 0, -65);
    glVertex3i(-15, 0, -63);
    glEnd();


    //samping
    glBegin(GL_QUADS);
    glColor3ub(48,56,79);
    glVertex3i(-13, 20, -63);
    glVertex3i(-13, 20, -65);
    glVertex3i(-13, 0, -65);
    glVertex3i(-13, 0, -63);
    glEnd();


    //pillar masuk kanan
    //depan
    glBegin(GL_QUADS);
    glColor3ub(48,56,79);
    glVertex3i(-23, 20, -32);
    glVertex3i(-21, 20, -32);
    glVertex3i(-21, 0, -32);
    glVertex3i(-23, 0, -32);
    glEnd();


    //belakang
    glBegin(GL_QUADS);
    glColor3ub(48,56,79);
    glVertex3i(-23, 20, -30);
    glVertex3i(-21, 20, -30);
    glVertex3i(-21, 0, -30);
    glVertex3i(-23, 0, -30);
    glEnd();

    //samping
    glBegin(GL_QUADS);
    glColor3ub(48,56,79);
    glVertex3i(-23, 20, -30);
    glVertex3i(-23, 20, -32);
    glVertex3i(-23, 0, -32);
    glVertex3i(-23, 0, -30);
    glEnd();


    //samping
    glBegin(GL_QUADS);
    glColor3ub(48,56,79);
    glVertex3i(-21, 20, -30);
    glVertex3i(-21, 20, -32);
    glVertex3i(-21, 0, -32);
    glVertex3i(-21, 0, -30);
    glEnd();


    //pillar bangunan panjang garis tembok
    //kanan
    glBegin(GL_QUADS);
    glColor3ub(223,227,227);
    glVertex3i(-37, 19, -11);
    glVertex3i(-35, 19, -11);
    glVertex3i(-35, 0, -11);
    glVertex3i(-37, 0, -11);
    glEnd();

    //kiri
    glBegin(GL_QUADS);
    glColor3ub(223,227,227);
    glVertex3i(-28, 19, -11);
    glVertex3i(-26, 19, -11);
    glVertex3i(-26, 0, -11);
    glVertex3i(-28, 0, -11);
    glEnd();

    //jendela gedung panjang
    //jendela1
    glBegin(GL_QUADS);
    glColor3f(0.25, 0.26, 0.33);
    glVertex3i(-16, 29, -11);
    glVertex3i(-16, 25, -11);
    glVertex3i(-25, 25, -11);
    glVertex3i(-25, 29, -11);
    glEnd();
    //jendela2
    glBegin(GL_QUADS);
    glColor3f(0.25, 0.26, 0.33);
    glVertex3i(-30, 29, -11);
    glVertex3i(-40, 29, -11);
    glVertex3i(-40, 25, -11);
    glVertex3i(-30, 25, -11);
    glEnd();
    //jendela3
    glBegin(GL_QUADS);
   glColor3f(0.25, 0.26, 0.33);
    glVertex3i(-45, 29, -11);
    glVertex3i(-54, 29, -11);
    glVertex3i(-54, 25, -11);
    glVertex3i(-45, 25, -11);
    glEnd();
    //jendela4
    glBegin(GL_QUADS);
    glColor3f(0.25, 0.26, 0.33);
    glVertex3i(-45, 20, -11);
    glVertex3i(-54, 20, -11);
    glVertex3i(-54, 15, -11);
    glVertex3i(-45, 15, -11);
    glEnd();


    //jendela gedung pojok kanan
    //jendela1
    //jendela4
    glBegin(GL_QUADS);
    glColor3f(0.25, 0.26, 0.33);
    glVertex3i(-76, 30, -11);
    glVertex3i(-84, 30, -11);
    glVertex3i(-84, 25, -11);
    glVertex3i(-76, 25, -11);
    glEnd();
    //jendela gedung pojok kanan
    //jendela1
    glBegin(GL_QUADS);
    glColor3f(0.25, 0.26, 0.33);
    glVertex3i(52, 33, -11);
    glVertex3i(40, 33, -11);
    glVertex3i(40, 29, -11);
    glVertex3i(52, 29, -11);
    glEnd();
    //jendela2
    glBegin(GL_QUADS);
    glColor3f(0.25, 0.26, 0.33);
    glVertex3i(52, 18, -11);
    glVertex3i(40, 18, -11);
    glVertex3i(40, 14, -11);
    glVertex3i(52, 14, -11);
    glEnd();
    //jendela3
    glBegin(GL_QUADS);
   glColor3f(0.25, 0.26, 0.33);
    glVertex3i(52, 12, -11);
    glVertex3i(40, 12, -11);
    glVertex3i(40, 8, -11);
    glVertex3i(52, 8, -11);
    glEnd();

    //parkir gedung pojok kanan
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex3i(-100, 1, -20);
    glVertex3i(-100, 1, 20);
    glVertex3i(-160, 1, 20);
    glVertex3i(-160, 1, -20);
    glEnd();

    //jalan1
    glBegin(GL_QUADS);
    glColor3ub(105, 105, 105);
    glVertex3i(70, 1, -60);
    glVertex3i(70, 1, -50);
    glVertex3i(-190, 1, -50);
    glVertex3i(-190, 1, -60);
    glEnd();
    //jalan2
    glBegin(GL_QUADS);
    glColor3ub(105, 105, 105);
    glVertex3i(-150, 1, -60);
    glVertex3i(-160, 1, -60);
    glVertex3i(-160, 1, -20);
    glVertex3i(-150, 1, -20);
    glEnd();
    //jalan3
    glBegin(GL_QUADS);
    glColor3ub(105, 105, 105);
    glVertex3i(-70, 1, -60);
    glVertex3i(-80, 1, -60);
    glVertex3i(-80, 1, -190);
    glVertex3i(-70, 1, -190);
    glEnd();

     //jalan parkir
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 1);
    glVertex3f( -160.2, 0.50, 60.2);
    glVertex3f( -60.2, 0.50, 80.2);
    glVertex3f( -60.2, 0.50, 19.2);
    glVertex3f( -160.2, 0.50, 19.2);
    glEnd();

    //jalan parkir garis putih
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f( -155.2, 0.54, 55.2);
    glVertex3f( -135.25, 0.54, 56.05);
    glVertex3f( -135.25, 0.54, 50.05);
    glVertex3f( -155.2, 0.54, 50.2);
    glEnd();

    //jalan parkir garis putih
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3f( -120.2, 0.54, 50.2);
    glVertex3f( -120.2, 0.54, 56.2);
    glVertex3f( -99.25, 0.54, 56.2);
    glVertex3f( -100.2, 0.54, 50.2);
    glEnd();

    //parkir belakang
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 1);
    glVertex3f( 60.2, 0.50, 70.2);
    glVertex3f( 60.2, 0.50, 100.2);
    glVertex3f( -60.2, 0.50, 100.2);
    glVertex3f( -60.2, 0.50, 70.2);
    glEnd();

    //tempat parkir 1
     glBegin(GL_QUADS);
    glColor3ub(105, 105, 105);
    glVertex3f( 55.2, 0.54, 95.2);
    glVertex3f( 45.2, 0.54, 95.2);
    glVertex3f( 35.2, 0.54, 80.2);
    glVertex3f( 45.2, 0.54, 80.2);
    glEnd();

    //tempat parkir 2
     glBegin(GL_QUADS);
    glColor3ub(105, 105, 105);
    glVertex3f( 35.2, 0.54, 95.2);
    glVertex3f( 25.2, 0.54, 95.2);
    glVertex3f( 15.2, 0.54, 80.2);
    glVertex3f( 25.2, 0.54, 80.2);
    glEnd();

    //tempat parkir 3
     glBegin(GL_QUADS);
    glColor3ub(105, 105, 105);
    glVertex3f( 15.2, 0.54, 95.2);
    glVertex3f( 5.2, 0.54, 95.2);
    glVertex3f( -5.2, 0.54, 80.2);
    glVertex3f( 5.2, 0.54, 80.2);
    glEnd();

     //tempat parkir 4
     glBegin(GL_QUADS);
    glColor3ub(105, 105, 105);
    glVertex3f( -15.2, 0.54, 80.2);
    glVertex3f( -25, 0.54, 80.2);
    glVertex3f( -15.2, 0.54, 95.2);
    glVertex3f( -5.2, 0.54, 95.2);
    glEnd();


    glPopMatrix();
    glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else {
        mouseDown = false;
    }
}

void mouseMotion(int x, int y) {
    if (mouseDown) {
        yrot = x - xdiff;
        xrot = y + ydiff;
        glutPostRedisplay();
    }
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'a':
    case 'A':
        glTranslatef(5.0, 0.0, 0.0);
        break;
    case 'd':
    case 'D':
        glTranslatef(-5.0, 0.0, 0.0);
        break;
    case 'w':
    case 'W':
        glTranslatef(0.0, 0.0, 5.0);
        break;
    case 's':
    case 'S':
        glTranslatef(0.0, 0.0, -5.0);
        break;
    case 'z':
    case 'Z':
        glTranslatef(0.0, 3.0, 0.0);
        break;
    case 'c':
    case 'C':
        glTranslatef(0.0, -3.0, 0.0);
        break;
    case 'q':
    case 'Q':
        glRotatef(5, 0.0, 3.0, 0.0);
        break;
    case 'e':
    case 'E':
        glRotatef(5, 0.0, -3.0, 0.0);
        break;
    case '5':
        if (is_depth) {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    Display();
}

void resize(int width, int height) {
    if (height == 0) height = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(80.0, width / height, 1.0, 600.0);
    glTranslatef(0.0, -10.0, -50.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000, 800);
    glutInitWindowPosition(100, 50);
    glutCreateWindow("FAKULTAS TEKNOLOGI INFORMASI UKSW");
    Init();
    glutDisplayFunc(Display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutReshapeFunc(resize);
    glutMainLoop();

    return 0;
}
