//
//  DiagramaVoronoi.hpp
//  OpenGLTest
//
//  Created by Márcio Sarroglia Pinho on 23/08/23.
//  Copyright © 2023 Márcio Sarroglia Pinho. All rights reserved.
//

#ifndef DiagramaVoronoi_h
#define DiagramaVoronoi_h

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Poligono.h"
#include "Envelope.h"


class Voronoi
{
    Poligono Diagrama[1000];
    unsigned int qtdDePoligonos;
    Ponto Min, Max;

public:
    int contadorProdVetorial = 0;
    int contadorHaInterseccao = 0;
    vector<Envelope> envelopes;

    Voronoi();
    Poligono LeUmPoligono();
    void LePoligonos(const char *nome);
    Poligono getPoligono(int i);
    void obtemLimites(Ponto &min, Ponto &max);
    unsigned int getNPoligonos();
    vector<int> getEnvelopesInterseccao(Ponto p);
    double ProdVetorial(Ponto& p1, Ponto& p2);
    int TaDentroConvexo(Ponto P);
    int TaDentroConcavo(Ponto p);
    void imprimeNumerosEnvelopes(vector<int> envelopesClicados);
    void imprimeEnvelopes();

};

#endif /* DiagramaVoronoi_h */
