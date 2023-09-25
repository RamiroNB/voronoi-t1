// **********************************************************************
// PUCRS/Escola Polit�cnica
// COMPUTA��O GR�FICA
//
// Programa basico para criar aplicacoes 2D em OpenGL
//
// Marcio Sarroglia Pinho
// pinho@pucrs.br
// **********************************************************************

// Para uso no Xcode:
// Abra o menu Product -> Scheme -> Edit Scheme -> Use custom working directory
// Selecione a pasta onde voce descompactou o ZIP que continha este arquivo.

#include <iostream>
#include <cmath>
#include <ctime>
#include <fstream>
#include <stdlib.h>

using namespace std;

#ifdef __APPLE__
#include <glut.h>
#endif

#ifdef __linux__
#include <GL/glut.h>
#endif

#include "Ponto.h"
#include "Poligono.h"
#include "DiagramaVoronoi.h"

#include "ListaDeCoresRGB.h"

#include "Temporizador.h"
#include "Envelope.h"

Temporizador T;
double AccumDeltaT = 0;

Poligono Pontos;

Voronoi Voro;
int *CoresDosPoligonos;

// Limites logicos da area de desenho
Ponto Min, Max, PontoClicado;
Ponto p1;

bool desenha = false;
bool FoiClicado = false;

float angulo = 0.0;
int poligono = -1;
int novoPoligono = -1;

int contadorProdVetorial;
int contadorHaInterseccao;

// **********************************************************************
//
// **********************************************************************
void printString(string s, int posX, int posY)
{
    // defineCor(cor);
    glColor3f(1, 1, 1);
    glRasterPos3i(posX, posY, 0); // define posicao na tela
    for (int i = 0; i < s.length(); i++)
    {
        // GLUT_BITMAP_HELVETICA_10, GLUT_BITMAP_TIMES_ROMAN_24,GLUT_BITMAP_HELVETICA_18
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s[i]);
    }
}
// **********************************************************************
//
// **********************************************************************
void ImprimeNumeracaoDosVertices(Poligono &P)
{
    for (int i = 0; i < P.getNVertices(); i++)
    {
        Ponto aux;
        aux = P.getVertice(i);
        char msg[10];
        sprintf(msg, "%d", i);
        printString(msg, aux.x, aux.y);
    }
}
// **********************************************************************
//
// **********************************************************************
void ImprimeNroDoPoligono(Poligono P,int n)
{
    char msg[10];
    sprintf(msg,"%d",n);
    Ponto Soma, A;

    for (int i=0;i<P.getNVertices();i++)
    {
        A = P.getVertice(i);
        Soma = Soma + A;
    }

    double div = 1.0/P.getNVertices();
    Soma = Soma * div;
    printString(msg,Soma.x, Soma.y);

}
// **********************************************************************
//
// **********************************************************************
void GeraPontos(int qtd)
{
    time_t t;
    Ponto Escala;
    Escala = (Max - Min) * (1.0 / 1000.0);
    srand((unsigned)time(&t));
    for (int i = 0; i < qtd; i++)
    {
        float x = rand() % 1000;
        float y = rand() % 1000;
        x = x * Escala.x + Min.x;
        y = y * Escala.y + Min.y;
        Pontos.insereVertice(Ponto(x, y));
    }
}

// **********************************************************************
//
// **********************************************************************
void init()
{
    srand(0);
    // Define a cor do fundo da tela (AZUL)
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

    Voro.LePoligonos("ListaDePoligonos-V2.txt");
    Voro.obtemLimites(Min, Max);
    // aqui o metodo dos vizinhos
    Voro.obtemVizinhosDasArestas();
    Min.imprime("Minimo:", "\n");
    Max.imprime("Maximo:", "\n");

    CoresDosPoligonos = new int[Voro.getNPoligonos()];

    for (int i = 0; i < Voro.getNPoligonos(); i++)
        CoresDosPoligonos[i] = i * 2; // rand()%80;

    // Ajusta a largura da janela l�gica
    // em fun��o do tamanho dos pol�gonos
    Ponto Largura;
    Largura = Max - Min;

    Min = Min - Largura * 0.1;
    Max = Max + Largura * 0.1;

    p1 = Ponto(1, 1);
}

double nFrames = 0;
double TempoTotal = 0;
// **********************************************************************
//
// **********************************************************************
void animate()
{
    double dt;
    dt = T.getDeltaT();
    AccumDeltaT += dt;
    TempoTotal += dt;
    nFrames++;

    if (AccumDeltaT > 1.0 / 30) // fixa a atualiza��o da tela em 30
    {
        AccumDeltaT = 0;
        // angulo+=0.05;
        glutPostRedisplay();
    }
    if (TempoTotal > 50.0)
    {
        cout << "Tempo Acumulado: " << TempoTotal << " segundos. ";
        cout << "Nros de Frames sem desenho: " << nFrames << endl;
        cout << "FPS(sem desenho): " << nFrames / TempoTotal << endl;
        TempoTotal = 0;
        nFrames = 0;
    }
}
// **********************************************************************
//  void reshape( int w, int h )
//  trata o redimensionamento da janela OpenGL
// **********************************************************************
void reshape(int w, int h)
{
    // Reset the coordinate system before modifying
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Define a area a ser ocupada pela area OpenGL dentro da Janela
    glViewport(0, 0, w, h);
    // Define os limites logicos da area OpenGL dentro da Janela
    glOrtho(Min.x, Max.x,
            Min.y, Max.y,
            0, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
// **********************************************************************
//
// **********************************************************************
void desenhaTriangulo()
{
    // glBegin(GL_TRIANGLES);
    // glVertex2f(p1.x, p1.y);
    // glVertex2f(p1.x + 1, p1.y);
    // glVertex2f(p1.x + 0.5, p1.y + 1);
    // glEnd();
    glColor3f(1, 1, 1); // R, G, B  [0..1]
    glPointSize(5);
    glBegin(GL_POINTS);
        glVertex3f(p1.x, p1.y, p1.z);
    glEnd();
}
// **********************************************************************
//
// **********************************************************************
void DesenhaEixos()
{
    Ponto Meio;
    Meio.x = (Max.x + Min.x) / 2;
    Meio.y = (Max.y + Min.y) / 2;
    Meio.z = (Max.z + Min.z) / 2;

    glBegin(GL_LINES);
    //  eixo horizontal
    glVertex2f(Min.x, Meio.y);
    glVertex2f(Max.x, Meio.y);
    //  eixo vertical
    glVertex2f(Meio.x, Min.y);
    glVertex2f(Meio.x, Max.y);
    glEnd();
}
// **********************************************************************
//
// **********************************************************************
void DesenhaLinha(Ponto P1, Ponto P2)
{
    glBegin(GL_LINES);
    glVertex3f(P1.x, P1.y, P1.z);
    glVertex3f(P2.x, P2.y, P2.z);
    glEnd();
}
// **********************************************************************
void InterseptaArestas(Poligono P)
{
    /*
    Ponto P1, P2;
    for (int i=0; i < P.getNVertices();i++)
    {
        P.getAresta(i, P1, P2);
        //if(PassaPelaFaixa(i,F))
        if (HaInterseccao(PontoClicado,Esq, P1, P2))
            P.desenhaAresta(i);
    }*/
}
// **********************************************************************
//  void display( void )
// **********************************************************************
void display(void)
{
    // Limpa a tela coma cor de fundo
    glClear(GL_COLOR_BUFFER_BIT);

    // Define os limites l�gicos da area OpenGL dentro da Janela
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    // Coloque aqui as chamadas das rotinas que desenham os objetos
    // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

    glLineWidth(1);
    glColor3f(1, 1, 1); // R, G, B  [0..1]
    DesenhaEixos();

    glRotatef(angulo, 0, 0, 1);
    glLineWidth(2);

    Poligono P;
    for (int i = 0; i < Voro.getNPoligonos(); i++)
    {
        defineCor(CoresDosPoligonos[i]);
        P = Voro.getPoligono(i);
        P.pintaPoligono();
        ImprimeNroDoPoligono(P, i);
    }
    glColor3f(0, 0, 0);
    for (int i = 0; i < Voro.getNPoligonos(); i++)
    {
        P = Voro.getPoligono(i);
        P.desenhaPoligono();
    }

    if (desenha)
    {
        desenha = false;
    }
    if (FoiClicado == true)
    {
        Ponto Esq;
        Ponto Dir(-1, 0);
        Esq = PontoClicado + Dir * (1000);
        // glColor3f(0, 1, 0); // R, G, B  [0..1]
        // DesenhaLinha(PontoClicado, Esq);
    }

    // Voro.HaIntersecao(PontoClicado);
    // Voro.TaDentroConvexo(PontoClicado);

    // Mapa.desenhaVertices();
    // glColor3f(1,0,0); // R, G, B  [0..1]
    // DesenhaLinha(Mapa.getVertice(0), Ponto(Min.x, Max.y));

    glColor3f(1, 0, 0); // R, G, B  [0..1]
    desenhaTriangulo();

    glutSwapBuffers();
}
// **********************************************************************
// ContaTempo(double tempo)
//      conta um certo n�mero de segundos e informa quanto frames
// se passaram neste per�odo.
// **********************************************************************
void ContaTempo(double tempo)
{
    Temporizador T;

    unsigned long cont = 0;
    cout << "Inicio contagem de " << tempo << "segundos ..." << flush;
    while (true)
    {
        tempo -= T.getDeltaT();
        cont++;
        if (tempo <= 0.0)
        {
            cout << "fim! - Passaram-se " << cont << " frames." << endl;
            break;
        }
    }
}
// **********************************************************************   
//  void keyboard ( unsigned char key, int x, int y )
// **********************************************************************
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:     // Termina o programa qdo
        exit(0); // a tecla ESC for pressionada
        break;
    case 't':
        ContaTempo(3);
        break;
    case ' ':
        desenha = !desenha;
        break;
    case 'w':
        p1.y += 0.1;
        novoPoligono = Voro.TaDentroConvexo(p1, contadorProdVetorial); //como fazer em relacao aos prints dos contadores? -- getContador e printar aqui fora
        if (novoPoligono != poligono) {
            cout << "\n\nConvexo:\nPoligono: " << novoPoligono << endl;
            cout << "Contador de Produto Vetorial: " << contadorProdVetorial << endl; 
            cout << "\n\nConcavo:\nPoligono: " << Voro.TaDentroConcavo(p1, contadorHaInterseccao) << endl;
            cout << "Contador de Ha Interseccao: " << contadorHaInterseccao << endl;
            poligono = novoPoligono;
        }
        break;
    case 'a':
        p1.x -= 0.1;
        novoPoligono = Voro.TaDentroConvexo(p1, contadorProdVetorial); //como fazer em relacao aos prints dos contadores? -- getContador e printar aqui fora
        if (novoPoligono != poligono) {
            cout << "\n\nConvexo:\nPoligono: " << novoPoligono << endl;
            cout << "Contador de Produto Vetorial: " << contadorProdVetorial << endl; 
            cout << "\n\nConcavo:\nPoligono: " << Voro.TaDentroConcavo(p1, contadorHaInterseccao) << endl;
            cout << "Contador de Ha Interseccao: " << contadorHaInterseccao << endl;
            poligono = novoPoligono;
        }
        break;
    case 's':
        p1.y -= 0.1;
        novoPoligono = Voro.TaDentroConvexo(p1, contadorProdVetorial); //como fazer em relacao aos prints dos contadores? -- getContador e printar aqui fora
        if (novoPoligono != poligono) {
            cout << "\n\nConvexo:\nPoligono: " << novoPoligono << endl;
            cout << "Contador de Produto Vetorial: " << contadorProdVetorial << endl; 
            cout << "\n\nConcavo:\nPoligono: " << Voro.TaDentroConcavo(p1, contadorHaInterseccao) << endl;
            cout << "Contador de Ha Interseccao: " << contadorHaInterseccao << endl;
            poligono = novoPoligono;
        }
        break;
    case 'd':
        p1.x += 0.1;
        novoPoligono = Voro.TaDentroConvexo(p1, contadorProdVetorial); //como fazer em relacao aos prints dos contadores? -- getContador e printar aqui fora
        if (novoPoligono != poligono) {
            cout << "\n\nConvexo:\nPoligono: " << novoPoligono << endl;
            cout << "Contador de Produto Vetorial: " << contadorProdVetorial << endl; 
            cout << "\n\nConcavo:\nPoligono: " << Voro.TaDentroConcavo(p1, contadorHaInterseccao) << endl;
            cout << "Contador de Ha Interseccao: " << contadorHaInterseccao << endl;
            poligono = novoPoligono;
        }
        break;
    default:
        break;
    }
}
// **********************************************************************
//  void arrow_keys ( int a_keys, int x, int y )
// **********************************************************************
void arrow_keys(int a_keys, int x, int y)
{
    switch (a_keys)
    {
    case GLUT_KEY_UP:     // Se pressionar UP
        glutFullScreen(); // Vai para Full Screen
        break;
    case GLUT_KEY_DOWN: // Se pressionar UP
                        // Reposiciona a janela
        glutPositionWindow(50, 50);
        glutReshapeWindow(700, 500);
        break;
    default:
        break;
    }
}
// **********************************************************************
// Esta fun��o captura o clique do botao direito do mouse sobre a �rea de
// desenho e converte a coordenada para o sistema de refer�ncia definido
// na glOrtho (ver fun��o reshape)
// Este c�digo � baseado em http://hamala.se/forums/viewtopic.php?t=20
// **********************************************************************
void Mouse(int button, int state, int x, int y)
{
    GLint viewport[4];
    GLdouble modelview[16], projection[16];
    GLfloat wx = x, wy, wz;
    GLdouble ox = 0.0, oy = 0.0, oz = 0.0;

    if (state != GLUT_DOWN)
        return;
    if (button != GLUT_LEFT_BUTTON)
        return;
    cout << "Botao da Esquerda! ";

    glGetIntegerv(GL_VIEWPORT, viewport);
    y = viewport[3] - y;
    wy = y;
    glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
    glGetDoublev(GL_PROJECTION_MATRIX, projection);
    glReadPixels(x, y, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &wz);
    gluUnProject(wx, wy, wz, modelview, projection, viewport, &ox, &oy, &oz);
    PontoClicado = Ponto(ox, oy, oz);
    PontoClicado.imprime("- Ponto no universo: ", "\n");
    // cout << "\n\nPoligono: " << Voro.TaDentroConvexo(PontoClicado) << endl;
    // cout << "\n\nPoligono: " << Voro.TaDentroConcavo(PontoClicado) << endl;

    FoiClicado = true;
}

// **********************************************************************
//  void main ( int argc, char** argv )
//
// **********************************************************************
int main(int argc, char **argv)
{
    cout << "Programa OpenGL" << endl;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
    glutInitWindowPosition(0, 0);

    // Define o tamanho inicial da janela grafica do programa
    glutInitWindowSize(650, 500);

    // Cria a janela na tela, definindo o nome da
    // que aparecera na barra de titulo da janela.
    glutCreateWindow("Poligonos em OpenGL");

    // executa algumas inicializa��es
    init();

    // Define que o tratador de evento para
    // o redesenho da tela. A funcao "display"
    // ser� chamada automaticamente quando
    // for necess�rio redesenhar a janela
    glutDisplayFunc(display);

    // Define que o tratador de evento para
    // o invalida��o da tela. A funcao "display"
    // ser� chamada automaticamente sempre que a
    // m�quina estiver ociosa (idle)
    glutIdleFunc(animate);

    // Define que o tratador de evento para
    // o redimensionamento da janela. A funcao "reshape"
    // ser� chamada automaticamente quando
    // o usu�rio alterar o tamanho da janela
    glutReshapeFunc(reshape);

    // Define que o tratador de evento para
    // as teclas. A funcao "keyboard"
    // ser� chamada automaticamente sempre
    // o usu�rio pressionar uma tecla comum
    glutKeyboardFunc(keyboard);

    // Define que o tratador de evento para
    // as teclas especiais(F1, F2,... ALT-A,
    // ALT-B, Teclas de Seta, ...).
    // A funcao "arrow_keys" ser� chamada
    // automaticamente sempre o usu�rio
    // pressionar uma tecla especial
    glutSpecialFunc(arrow_keys);

    glutMouseFunc(Mouse);

    // inicia o tratamento dos eventos
    glutMainLoop();

    return 0;
}
