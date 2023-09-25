//
//  DiagramaVoronoi.cpp
//  OpenGLTest
//
//  Created by Márcio Sarroglia Pinho on 23/08/23.
//  Copyright © 2023 Márcio Sarroglia Pinho. All rights reserved.
//

#include "DiagramaVoronoi.h"

ifstream input; // ofstream arq;

Voronoi::Voronoi()
{
}
Poligono Voronoi::LeUmPoligono()
{
    Poligono P;
    unsigned int qtdVertices;
    input >> qtdVertices; // arq << qtdVertices
    for (int i = 0; i < qtdVertices; i++)
    {
        double x, y;
        // Le um ponto
        input >> x >> y;
        Ponto(x, y).imprime();
        if (!input)
        {
            cout << "Fim inesperado da linha." << endl;
            break;
        }
        P.insereVertice(Ponto(x, y));
    }
    cout << "Poligono lido com sucesso!" << endl;
    return P;
}

void Voronoi::LePoligonos(const char *nome)
{
    input.open(nome, ios::in); // arq.open(nome, ios::out);
    if (!input)
    {
        cout << "Erro ao abrir " << nome << ". " << endl;
        exit(0);
    }
    string S;

    input >> qtdDePoligonos;
    cout << "qtdDePoligonos:" << qtdDePoligonos << endl;
    Ponto A, B;
    Diagrama[0] = LeUmPoligono();
    Diagrama[0].obtemLimites(Min, Max); // obtem o envelope do poligono
    envelopes.push_back(Envelope(Min, Max));  // cria o envelope do poligono (para colisao)

    for (int i = 1; i < qtdDePoligonos; i++)
    {
        Diagrama[i] = LeUmPoligono();
        Diagrama[i].obtemLimites(A, B); // obtem o envelope do poligono
        envelopes.push_back(Envelope(A, B));  // cria o envelope do poligono (para colisao)

        Min = ObtemMinimo(A, Min);
        Max = ObtemMaximo(B, Max);
    }
    cout << "Lista de Poligonos lida com sucesso!" << endl;
    cout << "Imprimindo envelopes..." << endl;
    
}

Poligono Voronoi::getPoligono(int i)
{
    if (i >= qtdDePoligonos)
    {
        cout << "Nro de Poligono Inexistente" << endl;
        return Diagrama[0];
    }
    return Diagrama[i];
}
unsigned int Voronoi::getNPoligonos()
{
    return qtdDePoligonos;
}
void Voronoi::obtemLimites(Ponto &min, Ponto &max)
{
    min = this->Min;
    max = this->Max;
}


vector<int> Voronoi::getEnvelopesInterseccao(Ponto p) {
    vector<int> envelopesClicados;
    for (int i=0; i<envelopes.size(); i++) {
        if (envelopes[i].pontoEstaDentro(p)) {
            envelopesClicados.push_back(i); 
        }
    }
    return envelopesClicados;
} 

double Voronoi::ProdVetorial(Ponto& p1, Ponto& p2) { 
    contadorProdVetorial++;
    return p1.x*p2.y - p1.y*p2.x;
}

int Voronoi::TaDentroConvexo(Ponto p, int& contador) {
    contadorProdVetorial = 0;
    vector<int> envelopesClicados = getEnvelopesInterseccao(p);

    if (envelopesClicados.size() == 1) {
        // cout << "ContadorProdVetorial: " << contadorProdVetorial << endl;
        contador = contadorProdVetorial;
        return envelopesClicados[0];
    } 

    Ponto p1, p2;
    double prodVetorial;

    for (int i=0; i<envelopesClicados.size(); i++) {
        Poligono poligonoAtual = Diagrama[envelopesClicados[i]];
        
        int nVertices = poligonoAtual.getNVertices();

        bool dentro = true;
        bool positivo = true;
        vector<double> produtos;

        for (int j=0; j<nVertices; j++)  {
            poligonoAtual.getAresta(j, p1, p2); 
            Ponto vec1 = Ponto(p2.x - p1.x, p2.y - p1.y, 0);
            Ponto vec2 = Ponto(p.x - p1.x, p.y - p1.y, 0); 
            
            prodVetorial = ProdVetorial(vec1, vec2);
            if (j == 0) {
                if (prodVetorial >= 0) { 
                    positivo = true;
                } else {
                    positivo = false;
                }
            } else {
                if (positivo) { // caso o primeiro for positivo, todos os outros tem que ser positivo
                    if (prodVetorial < 0) {
                        dentro = false;
                        break; //achou negativo, para e vai pro proximo
                    } else {
                        dentro = true;
                    }
                } else {
                    if (prodVetorial >= 0) {
                        dentro = false;
                        break;
                    } else {
                        dentro = true;
                    }
                }
            }
        }

        if (dentro) {
            // cout << "ContadorProdVetorial: " << contadorProdVetorial << endl;
            contador = contadorProdVetorial;
            return envelopesClicados[i];
        }
        
    }
    return -1;
} 

bool exists(vector<int> vetor, int n) {
    for (int i = 0; i < vetor.size(); i++) {
        if (vetor[i] == n)
            return true;
    }
    return false;
}

int Voronoi::TaDentroConcavo(Ponto p, int& contador){
    contadorHaInterseccao = 0;
    Ponto Dir(-1, 0);
    Ponto teste = p + Dir * (1000);

    Ponto aux;
    vector<int> envelopesParaAnalise;
    vector<int> envelopesNoPonto;
    for (double i=0; i<100; i+=0.1) {
        aux = Ponto(p.x - i, p.y, 0);

        envelopesNoPonto = getEnvelopesInterseccao(aux);
        if (envelopesNoPonto.size() == 0) {
            break;
        }

        for (int j=0; j<envelopesNoPonto.size(); j++) {
            if (!(exists(envelopesParaAnalise, envelopesNoPonto[j]))) {
                envelopesParaAnalise.push_back(envelopesNoPonto[j]);
            }
        }
        envelopesNoPonto.clear();
    }

    if (envelopesParaAnalise.size() == 1) {
        contador = contadorHaInterseccao;
        // vector<int> v;
        // v = Diagrama[envelopesParaAnalise[0]].getVizinhos();
        // for(int j = 0; j<v.size();j++ ){
        //     cout << "Vizinhos:\n: " << v[j] << endl;
        // }
        return envelopesParaAnalise[0];
    }

    int interseccoes;
    Ponto p1, p2;
    for (int i=0; i<envelopesParaAnalise.size(); i++) {
        Poligono polig = Diagrama[envelopesParaAnalise[i]];
        interseccoes = 0;

        int n = polig.getNVertices();
        for (int j=0; j<n; j++) {
            p1 = polig.getVertice(j);
            p2 = polig.getVertice((j+1) % n);

            contadorHaInterseccao++;
            if (HaInterseccao(p, teste, p1, p2)) {
                interseccoes++;
            }
        }

        if (interseccoes % 2 != 0) {
            // cout << "Contador de HaInterseccao: " << contadorHaInterseccao << endl;
            contador = contadorHaInterseccao;
            //testando
            // vector<int> v;
            // v = polig.getVizinhos();
            // cout <<"N vizinhos:"<< v.size() << endl;
            // for(int j = 0; j<v.size();j++ ){
            //     cout << "Vizinhos:\n: " << v[j] << endl;
            // }
            // testando
            return envelopesParaAnalise[i];
        }

    }
    return -1;
}

void Voronoi::imprimeNumerosEnvelopes(vector<int> envelopesClicados) {
    for (int i=0; i<envelopesClicados.size(); i++) {
        cout << envelopesClicados[i] << endl;
    }
}

void Voronoi::imprimeEnvelopes() {
    for (int i=0; i<envelopes.size(); i++) {
        envelopes[i].imprime();
    }
}

void Voronoi::obtemVizinhosDasArestas() {                       
    bool adicionou = false;
    for (int i=0; i<qtdDePoligonos; i++) {
        Poligono poligonoAtual = Diagrama[i];
        for (int a=0; a<poligonoAtual.getNVertices(); a++) {
            Ponto p1, p2;
            poligonoAtual.getAresta(a, p1, p2);
            for (int p=0; p<qtdDePoligonos; p++) {
                if (p != i) {
                    Poligono poligonoVizinho = Diagrama[p];
                    for (int e=0; e<poligonoVizinho.getNVertices(); e++) {
                        adicionou = false;
                        Ponto p3, p4;
                        poligonoVizinho.getAresta(e, p3, p4);
                        if (p1.x == p4.x && p1.y == p4.y && p2.x == p3.x && p2.y == p3.y) {
                            Diagrama[i].addVizinho(p);
                            adicionou = true;
                            break;
                        }
                    }
                }
                if (!adicionou) {
                    poligonoAtual.addVizinho(-1);
                }
            }
        }
    }
}

void Voronoi::vizinhosTeste(Ponto p) {
//     // tem a lista de vizinhos poligono p
//     //  tem o poligono p
//     // pra cada aresta

//     // produto vetorial = faz com todas as arestas do poligono p,o mais proximo de 0 é o que tu ta cruzando.
//     // se for fazer o teste depois de ter cruzado = testa com todos os vizinhos
//     // se for fazer o teste antes de cruzar = testa com as arestas do poligono p
//     // assim sabe qual aresta que tu ta cruzando, e assim automaticamente sabe qual o poligono (numero da aresta corresponde ao indice da lista de vizinhos, ou seja, a posicao da aresta tem o poligono que tu ta)
//     // vector<int> vizinhos = p.getVizinhos();

//     //quer o poligono atual

//     //qual aresta p cruzou? 
        
    for (int i=0; i<qtdDePoligonos; i++) {
        Poligono polig = Diagrama[i];
        
    }

}

