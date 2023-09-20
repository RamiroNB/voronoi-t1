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
            envelopesClicados.push_back(i); // como checar se ta certo?
        }
    }
    return envelopesClicados;
} //salvar o numero do envelope, ai a gente sabe os poligonos

double Voronoi::ProdVetorial(Ponto& p1, Ponto& p2) { //adicionar o contador aqui
    contadorProdVetorial++;
    return p1.x*p2.y - p1.y*p2.x;
}

int Voronoi::TaDentroConvexo(Ponto p) {
    contadorProdVetorial = 0;
    vector<int> envelopesClicados = getEnvelopesInterseccao(p);

    if (envelopesClicados.size() == 1) {
        cout << "ContadorProdVetorial: " << contadorProdVetorial << "\n" << endl;
        return envelopesClicados[0];
    } 

    Ponto p1, p2;
    double prodVetorial;

    for (int i=0; i<envelopesClicados.size(); i++) {
        Poligono poligonoAtual = Diagrama[envelopesClicados[i]]; // aqui tava o problema = tava pegando sempre os primeiros na lista
        //tipo, a quantidade de envelopes clicados é 2, ai ele pega o 0 e o 1, mas o 0 e o 1 nao sao os que estao dentro do envelope
        // antes tava Diagrama[i] ao inves de envelopesClicados[i]
        
        int nVertices = poligonoAtual.getNVertices();

        bool dentro = true;
        bool positivo = true;
        vector<double> produtos;

        for (int j=0; j<nVertices; j++)  {
            poligonoAtual.getAresta(j, p1, p2); //pegar a aresta do poligono (pegar os vertices do poligono
            Ponto vec1 = Ponto(p2.x - p1.x, p2.y - p1.y, 0);
            Ponto vec2 = Ponto(p.x - p1.x, p.y - p1.y, 0); 
            
            prodVetorial = ProdVetorial(vec1, vec2);
            if (j == 0) { // primeiro prod calculado
                if (prodVetorial >= 0) { // ele determina como os outros devem ser
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
            cout << "ContadorProdVetorial: " << contadorProdVetorial << "\n" << endl;
            return envelopesClicados[i];
        }
        
    }
    return -1;
} //falta alterar para ao inves do click do mouse, usar um ponto com as setas

bool Voronoi::HaIntersecao(Ponto p1, Ponto p2, Ponto q1, Ponto q2){ 
    double s, t;

    // if (intersec2d(p1, teste, q1, q2, s, t) == 1) {
    //     return true;
    // } else {
    //     return false;
    // }


    return true;
}

bool exists(vector<int> vetor, int n) {
    for (int i = 0; i < vetor.size(); i++) {
        if (vetor[i] == n)
            return true;
    }
    return false;
}

void encontrarMinimoMaximoLocal(Poligono polig, int& minimoLocal, int& maximoLocal) {
    
    int n = polig.getNVertices();

    for (int i = 0; i < n; i++) {
        int ant = (i + n - 1) % n;
        int prox = (i + 1) % n;

        Ponto anterior = polig.getVertice(ant);
        Ponto proximo = polig.getVertice(prox);
        Ponto atual = polig.getVertice(i);

        if (atual.y < anterior.y && atual.y < proximo.y) {
            minimoLocal = atual.y;
        }

        if (atual.y > anterior.y && atual.y > proximo.y) {
            maximoLocal = atual.y;
        }
    }
}

int Voronoi::TaDentroConcavo(Ponto p){
    Ponto Dir(-1, 0);
    Ponto teste = p + Dir * (1000); // a partir do ponto reta pra esquerda pra analise
    // teste.imprime();
    //q1 e q2 ? de quem? pegar poligono certo

    // envelopes que cruzem a linha horizontal tracada
    Ponto aux;
    vector<int> envelopesParaAnalise;
    for (int i=0; i>-1000; i--) {
        aux = Ponto(i + p.x, p.y, 0);

        vector<int> envelopesNoPonto = getEnvelopesInterseccao(aux);
        if (envelopesNoPonto.size() == 0) {
            break;
        }
        if (envelopesNoPonto.size() == 1) {
            return envelopesNoPonto[0]; // se tem so um, ta bem na ponta, a gente ja sabe qual q é
        }

        for (int j=0; j<envelopesNoPonto.size(); j++) {
            if (!exists(envelopesParaAnalise, envelopesNoPonto[j])) {
                envelopesParaAnalise.push_back(envelopesNoPonto[j]);
            }
        }
    }

    // analisar somente os q o envelope é cruzado pela linha
    Ponto verticeAtual, proximoVertice;
    for (int i=0; i<envelopesParaAnalise.size(); i++) {
        Poligono polig = Diagrama[envelopesParaAnalise[i]];

        int minimoLocal, maximoLocal;
        encontrarMinimoMaximoLocal(polig, minimoLocal, maximoLocal);

        // se o y for o y max ou minlocal, par = dentro, impar = fora
        
        // agora qq tem que fazer:
        // 1 - ir em cada aresta do poligono, e ir passando pra funcao ali de baixo
        // 2 - se der interseccao, contabilizar em um contador
        // no final da analise do poligono inteiro, tem que ver se o contador é par ou impar
        // dependendo sempre do min e max local (a logica pode mudar)
        // caso for impar ou par (dependendo da logica) ja retorna o poligono que se encontra para parar a analise
    }

    // HaIntersecao(p1, teste, q1, q2);
}

// k e l = uma reta
// m e n = outra reta
// s e t = parametros da intersecção, nao precisa enviar
int Voronoi::intersec2d (Ponto k, Ponto l, Ponto m, Ponto n, double &s, double &t)
{
    double det = (n.x - m.x) * (l.y - k.y) - (n.y - m.y) * (l.x - k.x);
    if (det == 0.0) return 0 ; // não há intersecção
    s = ((n.x - m.x) * (m.y - k.y) - (n.y - m.y) * (m.x - k.x))/ det ;
    t = ((l.x - k.x) * (m.y - k.y) - (l.y - k.y) * (m.x - k.x))/ det ;
    return 1; // há intersecção
}


void Voronoi::imprimeNumerosEnvelopes(vector<int> envelopesClicados) {
    for (int i=0; i<envelopesClicados.size(); i++) {
        cout << envelopesClicados[i] << endl;
    }
} // da pra tirar esses dos se for o caso

void Voronoi::imprimeEnvelopes() {
    for (int i=0; i<envelopes.size(); i++) {
        envelopes[i].imprime();
    }
}


// convexo: precisa salvas as arestas, pegar as arestas de cada poligono da lista pegada pelo metodo acima
//          ai dps tem que ver se o ponto ta dentro do poligono vendo se ta no mesmo lado em relacao a todas as arestas do poligono (prod vetorial???)
//          essa chamada ai com cada poligono vai ser contabilizada, por isso q so se testa com os poligonos da lista que tao no envelope (metodo acima)
// FEITO

// concavo: faz aquela linha bem pra esquerda (ja tem uma demonstracao no mouse quando clica na tela (metodo: mouse))
//          depois, com essa linha tem que contar a quantidade de intersecção com as arestas dos poligonos que ele enconsta (so testar com os poligonos q ele enconsta = mesmo y?)
//          depois de testado, tem que ver se a quantidade de intersecção é par ou impar (se for par, ta fora, se for impar, ta dentro)
//          lembrar da questao dos pontos minmos e maximos = que conta como duas intersecções ao mesmo tempo (Mínimo/Máximo local tem Y maior ou menos que seus vizinho)
//          o poligono que tiver impar intersecções com as suas arestas, é oq ta dentro
//          contabilizar a qtde de vezes que HaInterseccao foi chamada (somente com os que toca nas arestas do poligono)

// vizinhos: ????


// TEM QUE SALVAR AS ARESTAS!!!!! -- salvar as duplas de pontos, ja tem o metodo pra pegar esses pontos

