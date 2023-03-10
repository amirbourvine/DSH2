#ifndef DSH2_UNION_FIND_H
#define DSH2_UNION_FIND_H

#include "Team.h"
#include "Hash_Table.h"

#include <memory>

using namespace std;

typedef struct Node{
    shared_ptr<Player> player;
    shared_ptr<Team> team;

    int valgames;

    permutation_t permutationTrack;

    std::shared_ptr<Node> next;

    Node(shared_ptr<Player> player, shared_ptr<Team> team,
         const permutation_t& permutationTrack = permutation_t::neutral(), int gamesPlayed = 0){
        this->player = player;
        this->team = team;
        this->valgames = gamesPlayed - team->getGamesPlayedAsTeam();
        this->permutationTrack = permutationTrack;
        next = nullptr;
    }
} Node;

class Union_Find {
    Hash_Table<shared_ptr<Node>> nodes;
    Hash_Table<shared_ptr<Node>> sets;

    StatusType unite(const shared_ptr<Node>& set1, const shared_ptr<Node>& set2);
    shared_ptr<Team> findaux(shared_ptr<Node>& start);

public:
    Union_Find();
    ~Union_Find() = default;
    Union_Find(Union_Find&) = delete;
    void operator=(Union_Find&) = delete;

    StatusType uniteSets(int team1, int team2);
    StatusType makeSet(const shared_ptr<Player>&, const shared_ptr<Team>&, int gamesPlayed = 0);
    output_t<shared_ptr<Team>> find(int playerId);

    output_t<int> calcGamesPlayed(int playerId);
    output_t<permutation_t> calcPartialPermutation(int playerId);

    void print();
};


#endif //DSH2_UNION_FIND_H
