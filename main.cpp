#include <iostream>
#include <random>
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

int main() {
    int randomV = randomValue();
    cout << "Numero que caiu no dado: " << randomV << endl;
    return 0;
}

int randomValue() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 10);

    int random_number = dis(gen);

    return random_number;
}
