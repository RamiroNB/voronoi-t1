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
        envelopes.push_back(Envelope(Min, Max));  // cria o envelope do poligono (para colisao)

        Min = ObtemMinimo(A, Min);
        Max = ObtemMaximo(B, Max);
    }
    cout << "Lista de Poligonos lida com sucesso!" << endl;
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




// convexo: precisa salvas as arestas, pegar as arestas de cada poligono da lista pegada pelo metodo acima
//          ai dps tem que ver se o ponto ta dentro do poligono vendo se ta no mesmo lado em relacao a todas as arestas do poligono (prod vetorial???)
//          essa chamada ai com cada poligono vai ser contabilizada, por isso q so se testa com os poligonos da lista que tao no envelope (metodo acima)

// concavo: faz aquela linha bem pra esquerda (ja tem uma demonstracao no mouse quando clica na tela (metodo: mouse))
//          depois, com essa linha tem que contar a quantidade de intersecção com as arestas dos poligonos que ele enconsta (so testar com os poligonos q ele enconsta = mesmo y?)
//          depois de testado, tem que ver se a quantidade de intersecção é par ou impar (se for par, ta fora, se for impar, ta dentro)
//          lembrar da questao dos pontos minmos e maximos = que conta como duas intersecções ao mesmo tempo (Mínimo/Máximo local tem Y maior ou menos que seus vizinho)
//          o poligono que tiver impar intersecções com as suas arestas, é oq ta dentro
//          contabilizar a qtde de vezes que HaInterseccao foi chamada (somente com os que toca nas arestas do poligono)

// vizinhos: ????





// TEM QUE SALVAR AS ARESTAS!!!!!


// agora com os envelopes, tem que ver que poligonos que se encontram naqueles envelopes
//sabendo que poligonos estao dentro do envelope, tem que testar ver se ta dentro do poligono
// usando os vertices do poligono -- acho que ta guardado no coisa dele
// -------------
// envelope = quadradao em volta do poigonon, altura e largura apenas
// --------------
// agora acho que talvez ir de evenlope em envelope (ou posicao do poligono é o mesmo do envelope) -> acha o numero do envelope, sabe qual o poligono?
