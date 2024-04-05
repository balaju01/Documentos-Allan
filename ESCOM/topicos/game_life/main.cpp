//#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <qdebug.h>

using namespace std;

int fila_dinamica=4;
int columna_dinamica=4;
void imArchivo(int **);
int rules(int, int, int, int, int**, int **);
void cam_Estado(int**, int**);
void imprimir(int**);
int arbolito(int, int**, int **);
bool esta(int,vector<int>);
void arbolesdeTam(int);
void crearMatriz(int,int**);
void arbolitoArchivo(int , int **,int **);
int *ar;
vector<int> edos;
ofstream hol("Automata.dot");

int main(int argc, char *argv[])
{

    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    vector< int *> arbol;
    int aux=0x02000000,x,y;
    int tam=fila_dinamica;
    arbol.reserve(aux);
    int ayy;
    int **matriz,**max,**maux;
    int *edo = new int[2];

    int iniMatriz=0x00000000;
    int llenado;
    ayy=pow(2,(tam*tam));
    ar=new int[ayy];

    hol<<"digraph A {"<<endl;
    //hol << "size=\"6,4\"; ratio = fill;\n node [style=filled];";
    //hol << "\"0\\n|0,0,0|\\n|0,0,0|\\n|0,0,0|\"[shape=circle,height=150.12,width=0.12,fontsize=1200,style=filled,color=blue];\n";
    matriz = new int *[fila_dinamica];
    max = new int *[fila_dinamica];

    for(int i = 0; i<columna_dinamica;i++ )
    {
        matriz[i] = new int[columna_dinamica];
        max[i] = new int[columna_dinamica];
        maux[i] = new int[columna_dinamica];
    }

    for(int i=0;i<columna_dinamica;i++)
    {
        for(int j=0;j<fila_dinamica;j++)
        {
            matriz[i][j] = 0;
            max[i][j] = 0;
            maux[i][j] = 0;
        }
    }

    while(iniMatriz< 57845)//(pow(2,(tam*tam)))/1)
    {
        //qDebug()<<"\n "<<iniMatriz;

        llenado=(pow(2,(tam*tam)))/1;

        //Llenado de la matriz
        while(llenado!=0)
        {
            //qDebug() << llenado << " , " << iniMatriz;
            aux = (int)(log2(llenado));
            y = aux/tam;
            x = aux%tam;
            //qDebug()<< aux << " "<< y << " " << x;
            //qDebug()<<(iniMatriz & llenado);
            if((iniMatriz & llenado)==0)
            {
                //qDebug()<< "se pudo";
                y=y%tam;
                matriz[y][x]= 0;


            }
            else
            {
                //qDebug()<<"no se pudo";
                y=y%tam;
                matriz[y][x]=1;

            }


            llenado = llenado>>1;
         }



        cout<<"\n\n";
         //Game of life

         edo[0] = iniMatriz;
         edo[1] = rules(2,3,3,3,matriz,max);

         //ayy=rules(2,3,3,3,max,maux);
         arbol.push_back(edo);
         //if(edo[0]!=edo[1]){
             hol<< "\"" << edo[0] << "\\n";
             cout<<edo[0]<<".-\n";
             imprimir(matriz);
             imArchivo(matriz);
             hol << "\"[shape=circle,style=filled,color=red,height=5.12,width=0.12,fontsize=100];\n";
            hol<< "\"" << edo[0] << "\\n";
            imArchivo(matriz);
            hol<<"\"->";
            hol<<"\""<< edo[1]<<"\\n";

            imArchivo(max);
            imprimir(max);
            hol<< "\"[label=\"t\",arrowsize=1,penwidth=10]" << endl;
         //}
         iniMatriz++;

    }
    //qDebug()<<"si sale";
   // hol << "\"511\\n|1,1,1|\\n|1,1,1|\\n|1,1,1|\"[shape=circle,height=90.12,width=0.12,fontsize=800,style=filled,color=blue];\n";

    hol << "}" << endl;
    hol.close();
    cout << "\n otra cosa mariposa\n\n";
    matriz[0][0]=0;
    matriz[0][1]=1;
    matriz[0][2]=1;
    matriz[0][3]=0;
    //matriz[0][4]=1;
    matriz[1][0]=0;
    matriz[1][1]=1;
    matriz[1][2]=0;
    matriz[1][3]=1;
    //matriz[1][4]=0;
    matriz[2][0]=1;
    matriz[2][1]=0;
    matriz[2][2]=1;
    matriz[2][3]=0;
    //matriz[2][4]=0;
    matriz[3][0]=1;
    matriz[3][1]=0;
    matriz[3][2]=0;
    matriz[3][3]=0;
    //matriz[3][4]=0;
    //matriz[3][5]=0;


    for(int a=0;a<1;a++)
    {

        imprimir(matriz);

        rules(2,3,3,3,matriz,max);

        cam_Estado(matriz,max);

     }

    //return a.exec();
}

int rules(int x, int y, int z, int w, int **m, int **ax)
{
    int aux,auy,c=0;
    int mask = 0x00000001;
    int conf = 0;
    for(int i=0;i<columna_dinamica;i++)
    {
        for(int j=0;j<fila_dinamica;j++)
        {
            c=0;
            aux=j-1;
            auy=i-1;
            if(aux<0)
            {
                aux=fila_dinamica+aux;
            }
            if(auy<0)
            {
                auy=columna_dinamica+auy;
            }
            if((m[auy][aux])==1)
            {
                c=c+1;
            }

            aux=j;
            if((m[auy][aux])==1)
            {
                c=c+1;
            }

            aux=j+1;
            if(aux>=fila_dinamica)
            {
                aux=aux%fila_dinamica;
            }
            if((m[auy][aux])==1)
            {
                c=c+1;
            }

            auy=i;
            if((m[auy][aux])==1)
            {
                c=c+1;
            }

            auy=i+1;
            if(auy>=columna_dinamica)
            {
                auy=auy%columna_dinamica;
            }
            if((m[auy][aux])==1)
            {
                c=c+1;
            }

            aux=j;
            if((m[auy][aux])==1)
            {
                c=c+1;
            }

            aux=j-1;
            if(aux<0)
            {
                aux=fila_dinamica+aux;
            }
            if((m[auy][aux])==1)
            {
                c=c+1;
            }

            auy=i;
            if((m[auy][aux])==1)
            {
                c=c+1;
            }


            if(m[i][j]==1)
            {
                if((c>=x)&&(c<=y))
                {
                    ax[i][j]=1;
                    conf += mask;
                }
                else
                {
                    ax[i][j]=0;
                }
            }
            else
            {
                if((c>=z)&&(c<=w))
                {
                    ax[i][j]=1;
                    conf += mask;
                }
                else
                {
                    ax[i][j]=0;
                }
            }
            mask = mask<<1;
        }
    }
    return conf;
}

void cam_Estado(int **m, int **ax)
{
    for(int i=0;i<columna_dinamica;i++)
    {
        for(int j=0;j<fila_dinamica;j++)
        {
            m[i][j] = ax[i][j];
        }
    }
}

void imprimir(int **m)
{
    for(int i=0;i<columna_dinamica;i++)
    {
        for(int j=0;j<fila_dinamica;j++)
        {
            cout<< " " << m[i][j];
        }
        cout<<"\n";
    }
    cout<<"\n";
}

void imArchivo(int **m)
{
    for(int i=0;i<columna_dinamica;i++)
    {
        hol<< "|";
        for(int j=0;j<fila_dinamica;j++)
        {
            if(j==fila_dinamica-1)
            hol << m[i][j];
            else
            hol << m[i][j] << ",";
        }
        if(i==columna_dinamica-1)
        hol<<"|";
        else
        hol<<"|\\n";
    }
    //cout<<"\n";
}

int arbolito(int raiz, int **mat,int **m)
{
    int pr,sig=0,pr2,sig2;
    bool c=true;
    vector< int >elementos;
    pr=raiz;
    sig=rules(2,3,3,3,mat,m);
    pr2=pr;
    sig2=sig;
    ar[0]++;
    ar[raiz]++;
    elementos.push_back(pr);

    cout << elementos[0] << "," << elementos[1] << "\n";
    while(c)
    {
        //cout << pr2 << "," << sig2 << "\n";
        elementos.push_back(sig);
        pr=sig;
        cam_Estado(mat,m);
        sig=rules(2,3,3,3,mat,m);
        ar[raiz]++;
        c=esta(sig,elementos);
        //cout << pr << "," << sig << "\n";
    }
    //cout << pr2 << "," << sig2 << "\n";
    cout << ar[raiz];

    return raiz;
}

void arbolitoArchivo(int raiz, int **mat,int **m)
{
    int pr,sig=0,pr2,sig2;
    bool c=true;
    vector< int >elementos;
    pr=raiz;
    sig=rules(2,3,3,3,mat,m);
    pr2=pr;
    sig2=sig;
    ar[0]++;
    ar[raiz]++;
    elementos.push_back(pr);

    cout << elementos[0] << "," << elementos[1] << "\n";

    hol<< "\"" << pr << "\\n";
    imArchivo(mat);
    hol << "\"[shape=circle,style=filled,color=red,height=5.12,width=0.12,fontsize=100];\n";
    hol<< "\"" << pr << "\\n";
    imArchivo(mat);
    hol<<"\"->";
    hol<<"\""<< sig <<"\\n";
    imArchivo(m);

    hol<< "\"[label=\"t\",arrowsize=1,penwidth=10]" << endl;
    while(c)
    {
        //cout << pr2 << "," << sig2 << "\n";
        elementos.push_back(sig);
        pr=sig;
        cam_Estado(mat,m);
        sig=rules(2,3,3,3,mat,m);
        ar[raiz]++;
        c=esta(sig,elementos);
        hol<< "\"" << pr << "\\n";
        imArchivo(mat);
        hol << "\"[shape=circle,style=filled,color=red,height=5.12,width=0.12,fontsize=100];\n";
        hol<< "\"" << pr << "\\n";
        imArchivo(mat);
        hol<<"\"->";
        hol<<"\""<< sig <<"\\n";
        imArchivo(m);
        hol<< "\"[label=\"t\",arrowsize=1,penwidth=10]" << endl;
        //cout << pr << "," << sig << "\n";
    }
    //cout << pr2 << "," << sig2 << "\n";
    cout << ar[raiz];
}

bool esta(int n,vector<int> a)
{
    int ok=0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]==n)
        {
            ok=ok+1;
        }

    }
    if(ok>0)
    {
        return false;
    }
    else return true;
}

void arbolesdeTam(int ref)
{
    int lim=pow(2,fila_dinamica*fila_dinamica);
    int n=0;
    for(int i=0;i<lim-1;i++)
    {
        if(ar[i]==ref)
        {
            n=n+1;
            edos.push_back(i);
            cout << i << "," << ar[i] << "\n";
        }
    }
    cout << n << "\n";
}

void crearMatriz(int n,int** matriz)
{
    int iniMatriz=0,llenado,aux,y,x;
    while(iniMatriz< 2)
    {
        //qDebug()<<"\n "<<iniMatriz;

        llenado=n;

        //Llenado de la matriz
        while(llenado!=0)
        {
            //qDebug() << llenado << " , " << iniMatriz;
            aux = (int)(log2(llenado));
            y = aux/fila_dinamica;
            x = aux%fila_dinamica;
            //qDebug()<< aux << " "<< y << " " << x;
            if((iniMatriz & llenado)==0)
            {
                y=y%fila_dinamica;
                matriz[y][x]= 0;


            }
            else
            {
                y=y%fila_dinamica;
                matriz[y][x]=1;

            }


            llenado = llenado>>1;
         }

        iniMatriz++;
    }
}
