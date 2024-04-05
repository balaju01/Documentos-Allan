#ifndef CARRO_H
#define CARRO_H


class carro
{
public:
    carro();
    void dar_X(int);
    void dar_V(int);
    int res_X();
    int res_V();

private:
    int x;
    int v;
};

#endif // CARRO_H
