#include <iostream>
#include <random>
using namespace std;

int randomValue();

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

