#include <iostream>
#include <random>
#include <unordered_map>
using namespace std;

int randomValue();

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
void definirAtaquesPorClasse(Personagem& p);

int main() {

    cout << "Chamando menu principal.";
    return 0;


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
    else if (classe == "Ladr�o") {
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
    } else if (p.classe == "Ladrão") {
        p.ataques["Roubo de vida"] = 20;
        p.ataques["Chuva de socos"] = 21;
        p.ataques["Chute colateral"] = 28;
    }
     else {
        cout << "Classe desconhecida! Não ha ataques definidos." << endl;
    }
}

