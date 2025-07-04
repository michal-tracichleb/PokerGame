#include "HandEvaluator.h"
#include <algorithm>
#include <map>

using namespace std;

namespace {
    map<Value, vector<Card>, greater<>> GroupByValue(const vector<Card>& cards) {
        map<Value, vector<Card>, greater<>> groups;
        for (const auto& card : cards) {
            groups[card.GetValue()].push_back(card);
        }
        return groups;
    }

    bool IsFlush(const vector<Card>& cards) {
        const Color color = cards[0].GetColor();
        return all_of(cards.begin(), cards.end(), [=](const Card& c) { return c.GetColor() == color; });
    }

    bool IsStraight(const vector<Card>& sorted) {
        for (size_t i = 1; i < sorted.size(); ++i) {
            if (static_cast<int>(sorted[i - 1].GetValue()) - 1 != static_cast<int>(sorted[i].GetValue())) {
                return false;
            }
        }
        return true;
    }

    bool CheckFourOfAKind(const map<Value, vector<Card>, greater<>>& groups, const vector<Card>& sorted, vector<Card>& result) {
        for (auto it = groups.begin(); it != groups.end(); ++it) {
            Value val = it->first;
            const vector<Card>& group = it->second;
            if (group.size() == 4) {
                result.assign(group.begin(), group.end());
                for (const auto& card : sorted) {
                    if (static_cast<int>(card.GetValue()) != static_cast<int>(val)){
                        result.push_back(card);
                        break;
                    }
                }
                return true;
            }
        }
        return false;
    }

    bool CheckFullHouse(const map<Value, vector<Card>, greater<>>& groups, vector<Card>& result) {
        vector<Card> three, two;
        for (auto it = groups.begin(); it != groups.end(); ++it) {
            const vector<Card>& group = it->second;
            if (group.size() >= 3 && three.empty()) {
                for (int i = 0; i < 3; ++i)
                    three.push_back(group[i]);
            } else if (group.size() >= 2 && two.empty()) {
                for (int i = 0; i < 2; ++i)
                    two.push_back(group[i]);
            }
        }
        if (!three.empty() && !two.empty()) {
            result = three;
            result.insert(result.end(), two.begin(), two.end());
            return true;
        }
        return false;
    }

    bool CheckThreeOfAKind(const map<Value, vector<Card>, greater<>>& groups, const vector<Card>& sorted, vector<Card>& result) {
        for (auto it = groups.begin(); it != groups.end(); ++it) {
            Value val = it->first;
            const vector<Card>& group = it->second;
            if (group.size() == 3) {
                result.assign(group.begin(), group.end());
                for (const auto& card : sorted) {
                    if (static_cast<int>(card.GetValue()) != static_cast<int>(val)) result.push_back(card);
                    if (result.size() == 5) break;
                }
                return true;
            }
        }
        return false;
    }

    bool CheckTwoPair(const map<Value, vector<Card>, greater<>>& groups, const vector<Card>& sorted, vector<Card>& result) {
        int pairCount = 0;
        auto firstPairValue = Value::Size;
        for (auto it = groups.begin(); it != groups.end(); ++it) {
            const Value val = it->first;
            const vector<Card>& group = it->second;
            if (group.size() >= 2 && pairCount < 2) {
                result.push_back(group[0]);
                result.push_back(group[1]);
                if (pairCount == 0) firstPairValue = val;
                pairCount++;
            }
        }
        if (pairCount == 2) {
            for (const auto& card : sorted) {
                if (card.GetValue() != firstPairValue) {
                    result.push_back(card);
                    break;
                }
            }
            return true;
        }
        return false;
    }

    bool CheckOnePair(const vector<Card>& sorted, const map<Value, vector<Card>, greater<>>& groups, vector<Card>& result) {
        for (auto it = groups.begin(); it != groups.end(); ++it) {
            Value val = it->first;
            const vector<Card>& group = it->second;
            if (group.size() == 2) {
                result.assign(group.begin(), group.end());
                for (const auto& card : sorted) {
                    if (static_cast<int>(card.GetValue()) != static_cast<int>(val)) result.push_back(card);
                    if (result.size() == 5) break;
                }
                return true;
            }
        }
        return false;
    }
}

pair<HandRank, vector<Card>> HandEvaluator::Evaluate(const vector<Card>& cards) {
    vector<Card> sorted = cards;
    sort(sorted.begin(), sorted.end(), greater<>());

    const auto groups = GroupByValue(sorted);
    vector<Card> result;

    if (IsFlush(sorted) && IsStraight(sorted)) {
        if (sorted[0].GetValue() == Value::Ace) return { HandRank::RoyalFlush, sorted };
        return { HandRank::StraightFlush, sorted };
    }

    if (CheckFourOfAKind(groups, sorted, result)) return { HandRank::FourOfAKind, result };
    if (CheckFullHouse(groups, result)) return { HandRank::FullHouse, result };
    if (IsFlush(sorted)) return { HandRank::Flush, sorted };
    if (IsStraight(sorted)) return { HandRank::Straight, sorted };
    if (CheckThreeOfAKind(groups, sorted, result)) return { HandRank::ThreeOfAKind, result };
    if (CheckTwoPair(groups, sorted, result)) return { HandRank::TwoPair, result };
    if (CheckOnePair(sorted, groups, result)) return { HandRank::OnePair, result };

    return { HandRank::HighCard, { sorted[0] } };
}