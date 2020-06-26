//
// Created by 张小佳 on 2020-06-25.
//

#include "Primer.h"

const string &Primer::getId() const {
    return id;
}

void Primer::setId(const string &id) {
    Primer::id = id;
}

const string &Primer::getA() const {
    return A;
}

void Primer::setA(const string &A) {
    Primer::A = A;
}

const string &Primer::getB() const {
    return B;
}

void Primer::setB(const string &B) {
    Primer::B = B;
}

const string &Primer::getCommon() const {
    return common;
}

void Primer::setCommon(const string &common) {
    Primer::common = common;
}

Primer::Primer(const string &id, const string &A, const string &B, const string &common) : id(id), A(A), B(B),
                                                                                           common(common) {}

Primer::Primer(const string &id, const string &A, const string &B) : id(id), A(A), B(B) {}
