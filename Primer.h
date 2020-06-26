//
// Created by 张小佳 on 2020-06-25.
//

#ifndef SGORDER_PRIMER_H
#define SGORDER_PRIMER_H

#include <iostream>
using namespace std;
class Primer {
private:
    string id;
    string A;
    string B;
    string common;
public:
    Primer(const string &id, const string &A, const string &B, const string &common);

    Primer(const string &id, const string &A, const string &B);

    const string &getId() const;

    void setId(const string &id);

    const string &getA() const;

    void setA(const string &A);

    const string &getB() const;

    void setB(const string &B);

    const string &getCommon() const;

    void setCommon(const string &common);
};


#endif //SGORDER_PRIMER_H
