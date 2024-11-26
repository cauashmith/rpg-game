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
    else if (classe == "Ladrão") {
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
    //definirAtaquesPorClasse(p);
    return p;
}


