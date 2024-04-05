#ifndef RULES_H
#define RULES_H

class rules
{
private:
int Bmin;
int Bmax;
int Smin;
int Smax;

public:
rules(int Bmn, int Bmx, int Smn, int Smx);
void setrules(int Bmn, int Bmx, int Smn, int Smx);
int game(bool **a, bool **b, int tam);
};

#endif // RULES_H
