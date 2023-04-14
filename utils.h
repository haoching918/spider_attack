#ifndef UTILS__
#define UTILS__
#include <utility>
#include <string>
typedef std::pair<int, int> intPair;
namespace  constants{
    constexpr int BASERADIUS = 5000;
    constexpr int WINDRADIUS = 1280;
    constexpr int CTRLRADIUS = 2200;
    constexpr int SHLDRADIUS = 2200;
    constexpr int IDAIRADIUS = 300;
    constexpr int SPELLCOSTS = 10;
    // constexpr std::string ⚾ = "BASEBALL"; // Easter Egg
}
int distance(intPair, intPair);
intPair& operator +=(intPair &lhs, const intPair &rhs);
const intPair operator +(const intPair &lhs, const intPair &rhs);
intPair& operator -=(intPair &lhs, const intPair &rhs);
const intPair operator -(const intPair &lhs, const intPair &rhs);
intPair& operator *=(intPair &lhs, const int scalar);
const intPair operator *(const intPair &lhs, const int scalar);
intPair& operator /=(intPair &lhs, const int divider);
const intPair operator /(const intPair &lhs, const int divider);
intPair& operator %=(intPair &lhs, const int modulo);
const intPair operator %(const intPair &lhs, const int modulo);
#endif