#include <map>
#include <set>
using namespace std;

class AuctionSystem {
private:
    map<int, map<int, int>> ofertas;
    map<int, set<pair<int, int>>> ordenadas;

public:
    AuctionSystem() {
    }

    void addBid(int userId, int itemId, int bidAmount) {
        auto it = ofertas[itemId].find(userId);

        if (it != ofertas[itemId].end()) {
            ordenadas[itemId].erase({it->second, userId});
            it->second = bidAmount;
        } else {
            ofertas[itemId][userId] = bidAmount;
        }

        ordenadas[itemId].insert({bidAmount, userId});
    }

    void updateBid(int userId, int itemId, int newAmount) {
        int montoAnterior = ofertas[itemId][userId];

        ordenadas[itemId].erase({montoAnterior, userId});

        ofertas[itemId][userId] = newAmount;

        ordenadas[itemId].insert({newAmount, userId});
    }

    void removeBid(int userId, int itemId) {
        int montoAnterior = ofertas[itemId][userId];

        ordenadas[itemId].erase({montoAnterior, userId});
        ofertas[itemId].erase(userId);
    }

    int getHighestBidder(int itemId) {
        auto it = ordenadas.find(itemId);

        if (it == ordenadas.end() || it->second.empty()) {
            return -1;
        }

        return it->second.rbegin()->second;
    }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */

