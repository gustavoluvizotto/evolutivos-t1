/* 
 * File:   uRandom.h
 * Author: marcio
 *
 * Created on 8 de Março de 2013, 21:47
 */

#ifndef URANDOM_H
#define	URANDOM_H

class uRandom {
public:
    uRandom();
    virtual ~uRandom();
    
    bool nextBoolean();
    double nextDouble();
    int nextInt();
    long long nextLong();
    
    /*[0,n-1]*/
    int nextInt(unsigned int n);
    int nextInt(int a, int b);
    /**
     * @param a
     * @return [a,b[
     */
    double nextDouble(double a, double b);
    int nextInt(int* array, int length);
    int* shuffle(int a, int b);
    int* cuts_points(int n, int length);
    int nextInt(int a, int b, int nothing);
    int nextInt(int length, int* not_ord, int size);
    int nextInt(int a, int b, int* not_ord, int size);
    int* nextCutPoints(int* array, int length, int size);
    long long* nextMask(long long* mask, int bits);
    int* nextMask(int* mask, int bits);
    bool decode(long long* mask, int bit);
    int roulette_wheel(double sum, double* weigth, int length);
    int roulette_wheel(double* weigth, int length);
private:
    bool find(int* vet, int length, int key);
    void insert(int* array, int key, int i);

    bool bin_search(int* array, int length, int key);

    bool bin_search(int* array, int key, int a, int b);
};

#endif	/* URANDOM_H */

