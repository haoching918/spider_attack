#include "utils.h"
#include <cmath>

int distance(intPair a, intPair b) {
    return sqrt(pow(a.first - b.first, 2) + pow(b.second - a.second, 2));
}

intPair& operator +=(intPair &lhs, const intPair &rhs){
    lhs.first += rhs.first;
    lhs.second += rhs.second;
    return lhs;
}

const intPair operator +(const intPair &lhs, const intPair &rhs){
    intPair tmp=lhs;
    tmp += rhs;
    return tmp;
}

intPair& operator -=(intPair &lhs, const intPair &rhs){
    lhs.first += -rhs.first;
    lhs.second += -rhs.second;
    return lhs;
}

const intPair operator -(const intPair &lhs, const intPair &rhs){
    intPair tmp=lhs;
    tmp -= rhs;
    return tmp;
}

intPair& operator *=(intPair &lhs, const int scalar){
    lhs.first *= scalar;
    lhs.second *= scalar;
    return lhs;
}

const intPair operator *(const intPair &lhs, const int scalar){
    intPair tmp=lhs;
    tmp *= scalar;
    return tmp;
}

intPair& operator /=(intPair &lhs, const int divider){
    lhs.first /= divider;
    lhs.second /= divider;
    return lhs;
}

const intPair operator /(const intPair &lhs, const int divider){
    intPair tmp=lhs;
    tmp /= divider;
    return tmp;
}

intPair& operator %=(intPair &lhs, const int modulo){
    lhs.first %= modulo;
    lhs.second %= modulo;
    return lhs;
}

const intPair operator %(const intPair &lhs, const int modulo){
    intPair tmp=lhs;
    tmp %= modulo;
    return tmp;
}
