#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <unordered_map>

using namespace std;

struct Personagem {
    string nome;
    string classe;
    int vida;
    int defesa;
    int level;
    int founded;
    unordered_map<string, int> ataques;

    void mostrarAtaques() const {
        cout << "" << endl;
        cout << "Ataques disponiveis para " << nome << ":" << endl;
        int count = 1;
        for (const auto& ataque : ataques) {
            cout << count << ". - " << ataque.first << ": Dano " << ataque.second << endl;
            count++;
        }
        cout << "" << endl;
    }
};

struct Monstro {
    string nome;
    int vida;
    int danoMin;
    int danoMax;
};

Personagem criarPersonagem(const string& nome, const string& classe);
void menuInicial();
Personagem novoJogo();
void salvarJogo(const Personagem& p);
Personagem carregarJogo();
void iniciarCenario(Personagem& p);
void iniciarCombate(Personagem& jogador, Monstro& monstro);
void definirAtaquesPorClasse(Personagem& p);
void primeiraHistoria(Personagem &p);
void segundaHistoria(Personagem &p);
void terceiraHistoria(Personagem &p);

int main() {
    menuInicial();
    return 0;
}

void menuInicial() {
    int escolha;

    do {
        cout << "" << endl;
        cout << "== Menu do Jogo" << endl;
        cout << "1. Novo jogo" << endl;
        cout << "2. Carregar personagem" << endl;
        cout << "3. Sair" << endl;
        cout << "======================" << endl;
        cout << "Insira sua resposta: ";
        cin >> escolha;

        Personagem p;

        switch (escolha) {
            case 1:
                p = novoJogo();
                iniciarCenario(p);
                break;
            case 2:
                p = carregarJogo();
                if (p.founded == 0) {
                    cout << "Jogador nao encontrado!" << endl;
                } else {
                    if (p.vida > 0) {
                        iniciarCenario(p);
                    } else {
                        cout << "Voce esta morto, vire a chavinha." << endl;
                    }
                }
                break;
            case 3:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opçao invalida" << endl;
                break;
        }
    } while (escolha != 3);
}

Personagem novoJogo() {
    string nome, classe;
    cout << "Digite o nome do seu personagem: ";
    cin >> nome;

    cout << "== Classes disponiveis" << endl;
    cout << "1. Guerreiro" << endl;
    cout << "2. Ladrao" << endl;
    cout << "3. Cavaleiro" << endl;
    cout << "4. Mago" << endl;
    cout << "5. Arqueiro" << endl;
    cout << "Escolha sua classe: ";
    int escolhaClasse;
    cin >> escolhaClasse;

    switch (escolhaClasse) {
        case 1: classe = "Guerreiro"; break;
        case 2: classe = "Ladrao"; break;
        case 3: classe = "Cavaleiro"; break;
        case 4: classe = "Mago"; break;
        case 5: classe = "Arqueiro"; break;
        default: classe = "Guerreiro"; break;
    }

    Personagem jogador = criarPersonagem(nome, classe);
    salvarJogo(jogador);
    return jogador;
}

Personagem carregarJogo() {
    Personagem jogador;

    string personagem;
    cout << "Insira o nome do personagem: ";
    cin >> personagem;

    ifstream arquivo(personagem + ".txt");
    if (arquivo.is_open()) {
        arquivo >> jogador.nome >> jogador.classe >> jogador.vida >> jogador.defesa >> jogador.level;
        jogador.founded = 1;
        arquivo.close();
    } else {
        jogador.founded = 0;
    }
    definirAtaquesPorClasse(jogador);
    return jogador;
}

Personagem criarPersonagem(const string& nome, const string& classe) {
    Personagem p;
    p.nome = nome;
    p.classe = classe;

    if (classe == "Guerreiro") {
        p.vida = 80;
        p.defesa = 10;
        p.level = 1;
    }
    else if (classe == "Ladrao") {
        p.vida = 70;
        p.defesa = 3;
        p.level = 1;
    }
    else if (classe == "Cavaleiro") {
        p.vida = 85;
        p.defesa = 15;
        p.level = 1;
    }
    else if (classe == "Mago") {
        p.vida = 45;
        p.defesa = 5;
        p.level = 1;
    } else if (classe == "Arqueiro") {
        p.vida = 50;
        p.defesa = 6;
        p.level = 1;
    }
    definirAtaquesPorClasse(p);
    return p;
}

void iniciarCenario(Personagem& p) {
    if (p.level == 1) {
        primeiraHistoria(p);
    } else if (p.level == 2) {
        segundaHistoria(p);
    } else if (p.level == 3) {
        terceiraHistoria(p);
    } else {
        cout << "Voce e o grande vencedor! Saboreie a vitoria, " << p.nome << endl;
    }
}

void primeiraHistoria(Personagem &p) {
    cout << "Voce entrou em uma floresta misteriosa. Ao seu redor, arvores antigas formam um teto denso, quase bloqueando a luz do sol." << endl;
    cout << "De repente, voce ouve o som de passos leves. Um Goblin surge das sombras, armado com uma adaga!" << endl;

    Monstro goblin = {"Goblin", 50, 5, 12};
    iniciarCombate(p, goblin);

    if (p.vida > 0) {
        p.level = p.level + 1;
        cout << "Level atual: " << p.level << endl;
        salvarJogo(p);
        cout << "Voce derrotou o Goblin! Mas a floresta guarda mais desafios. Prepare-se!" << endl;
    } else {
        cout << "Fim da linha, grande jogador.";
    }
}

void segundaHistoria(Personagem &p) {
    cout << "Voce entrou em uma gruta." << endl;
    cout << "De repente, voce ouve o som de passos pesados. Um Monstro surge das sombras, com um soco ingles potente!" << endl;
    cout << "Prepare-se, pois a luta sera intensa!" << endl;

    Monstro monstro = {"Monstro Nevado", 50, 12, 19};
    iniciarCombate(p, monstro);

    if (p.vida > 0) {
        p.level = p.level + 1;
        cout << "Voce derrotou o Monstro!" << endl;
        cout << "Saindo da gruta, voce encontra uma pocao de revitalizacao e defesa, te preparando para futuros combates!" << endl;
        cout << "Ganha Vida +10 e Defesa +5" << endl;
        p.vida = p.vida + 10;
        p.defesa = p.defesa + 5;
        salvarJogo(p);
    } else {
        cout << "";
        cout << "Fim da linha, grande jogador.";
    }
}

void terceiraHistoria(Personagem &p) {
    cout << "Voce esta chegando ao final, e ja consegue enxergar o caminho da gloria." << endl;
    cout << "Voce esta quase la, e percebe, que devera passar por uma caverna para chegar ao fim desse intenso desafio." << endl;
    cout << "Passando pela caverna, voce se depara com o maior de todos os medos dos lutadores, o Ciclope chamado Felix, que aplica forca maxima contra seus contraditores" << endl;
    cout << "Seja preciso, senao, fim de linha.";

    Monstro monstro = {"Felix", 50, 15, 22};
    iniciarCombate(p, monstro);

    if (p.vida > 0) {
        p.level = p.level + 1;
        cout << "Level atual: " << p.level << endl;
        salvarJogo(p);
        cout << "Voce derrotou o Felix! Fim da linha, voce venceu!!!" << endl;
    } else {
        cout << "Fim da linha, grande jogador." << endl;
    }
}

int calcularDano(int danoMax) {
    return rand() % (danoMax + 1);
}

void iniciarCombate(Personagem& jogador, Monstro& monstro) {
    cout << "" << endl;
    cout << "Voce encontrou um " << monstro.nome << "!" << endl;
    cout << "Vida do monstro: " << monstro.vida << endl;
    cout << "" << endl;

    while (jogador.vida > 0 && monstro.vida > 0) {

        jogador.mostrarAtaques();
        int escolha;
        cout << "" << endl;
        cout << "Escolha seu ataque: ";
        cin >> escolha;

        if (escolha < 1 || escolha > static_cast<int>(jogador.ataques.size())) {
            cout << "Escolha invalida! Perdeu a vez!" << endl;
            continue;
        }

        auto it = jogador.ataques.begin();
        advance(it, escolha - 1);
        string ataqueEscolhido = it->first;
        int danoMaximo = it->second;

        int danoJogador = calcularDano(danoMaximo);

        int danoMonstro = calcularDano(monstro.danoMax);

        int danoReal = max(0, danoJogador - danoMonstro);
        monstro.vida -= danoReal;

        cout << "" << endl;
        cout << "Voce usou " << ataqueEscolhido << " e causou " << danoReal << " de dano no " << monstro.nome << "!" << endl;

        if (monstro.vida <= 0) {
            cout << monstro.nome << " foi derrotado!" << endl;
            break;
        }

        int danoSofrido = max(0, danoMonstro - jogador.defesa);
        jogador.vida -= danoSofrido;

        cout << "" << endl;
        cout << monstro.nome << " atacou e causou " << danoSofrido << " de dano em voce!" << endl;
        cout << "Sua vida: " << jogador.vida << " | Vida do monstro: " << monstro.vida << endl;
        cout << "" << endl;

        if (jogador.vida <= 0) {
            cout << "Voce foi derrotado! Fim de jogo." << endl;
            break;
        }
    }
}

void definirAtaquesPorClasse(Personagem& p) {
    if (p.classe == "Guerreiro") {
        p.ataques["Ataque de espada"] = 30;
        p.ataques["Golpe pesado"] = 25;
        p.ataques["Ataque duplo"] = 21;
    } else if (p.classe == "Mago") {
        p.ataques["Bola de fogo"] = 25;
        p.ataques["Raio de energia"] = 20;
        p.ataques["Repelente magico"] = 15;
    } else if (p.classe == "Arqueiro") {
        p.ataques["Flechas flamejantes"] = 20;
        p.ataques["Chuva de flechas"] = 21;
        p.ataques["Crítico"] = 28;
    } else if (p.classe == "Cavaleiro") {
        p.ataques["Investida frontal"] = 20;
        p.ataques["Corte vertical"] = 21;
        p.ataques["O X da Morte"] = 28;
    } else if (p.classe == "Ladrao") {
        p.ataques["Roubo de vida"] = 20;
        p.ataques["Chuva de socos"] = 21;
        p.ataques["Chute colateral"] = 28;
    }
     else {
        cout << "Classe desconhecida! Nao ha ataques definidos." << endl;
    }
}


void salvarJogo(const Personagem& jogador) {
    ofstream arquivo(jogador.nome + ".txt");
    if (arquivo.is_open()) {
        arquivo << jogador.nome << " " << jogador.classe << " " << jogador.vida << " " << jogador.defesa << " " << jogador.level;
        arquivo.close();
        cout << "Jogo salvo com sucesso!" << endl;
    } else {
        cout << "Nao foi possivel salvar o jogo." << endl;
    }
}
