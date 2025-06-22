#include "HandEvaluator.h"
#include <algorithm>
#include <map>

using namespace std;

pair<HandRank, vector<Card>> HandEvaluator::Evaluate(const vector<Card>& cards) {
    // TODO: implement full logic
    vector<Card> sorted = cards;
    sort(sorted.begin(), sorted.end(), greater<>());

    return { HandRank::HighCard, { sorted[0] } };
}