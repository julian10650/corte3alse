#include <vector>
using namespace std;

class ATM {
private:
    vector<long long> billetes;
    vector<int> valores;

public:
    ATM() {
        billetes = vector<long long>(5, 0);
        valores = {20, 50, 100, 200, 500};
    }

    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < 5; i++) {
            billetes[i] += banknotesCount[i];
        }
    }

    vector<int> withdraw(int amount) {
        vector<int> usados(5, 0);
        long long restante = amount;

        for (int i = 4; i >= 0; i--) {
            long long cantidad = restante / valores[i];

            if (cantidad > billetes[i]) {
                cantidad = billetes[i];
            }

            usados[i] = static_cast<int>(cantidad);
            restante -= cantidad * valores[i];
        }

        if (restante != 0) {
            return {-1};
        }

        for (int i = 0; i < 5; i++) {
            billetes[i] -= usados[i];
        }

        return usados;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
