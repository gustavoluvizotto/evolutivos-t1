/* 
 * File:   uRandom.cpp
 * Author: marcio
 * 
 * Created on 8 de Março de 2013, 21:47
 */

#include "uRandom.h"
#include "uUtil.h"
#include <stdlib.h>
#include <cmath>

#include <assert.h>     /* assert */

uRandom::uRandom() {
}
uRandom::~uRandom() {
}


bool uRandom::nextBoolean(){
    return rand()%2;
}
double uRandom::nextDouble(){
    return rand()/32768.0;
}
int uRandom::nextInt(){
    int a = rand();
    int b = rand();
    return a<<15 | b;
}
long long uRandom::nextLong(){
    long long a = rand();
    long long b = rand();
    long long c = rand();
    long long d = rand();
    long long e = rand();
    return a<<48 | b<<33 | c<<18 | d<<3 | e>>12;
}
int uRandom::nextInt(unsigned int n){
    assert(!(n<1));
    return ( n<32768 ? rand() : nextInt() ) % n;
}

int uRandom::nextInt(int a, int b) {
    return b > a ? a + nextInt(b - a + 1)
            : b < a ? b + nextInt(a - b + 1)
            : a;
}
double uRandom::nextDouble(double a, double b) {
    return b > a ? a + nextDouble() * (b - a)
            : b < a ? b + nextDouble() * (a - b)
            : a;
}
int uRandom::nextInt(int* array, int length) {
    return array[nextInt(length)];
}
int* uRandom::shuffle(int a, int b) {
    assert(!(b<=a));
    
    int length = b-a;
    int* r = new int[length];
    int tmp, j, k;

    r[0] = a;
    for (int i = 1; i < length; i++) {
        r[i] = r[i - 1] + 1;
    }

    for (int i = 0; i < length; i++) {
        j = nextInt(length);
        k = nextInt(length);
        tmp = r[j];
        r[j] = r[k];
        r[k] = tmp;
    }

    return r;
}
int* uRandom::cuts_points(int n, int length) {
    assert(!(n < length));
    
    bool find[n];
    for (int i = 0; i < n; i++) {
        find[i] = false;
    }
    for (int i = 0; i < length; i++) {
        int r = nextInt(n);
        while (find[r]) {
            r = nextInt(n);
        }
        find[r] = true;
    }
    int* p = new int[length];
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (find[i]) {
            p[j] = i;
            j++;
        }
    }
    return p;
}

int uRandom::nextInt(int a, int b, int nothing) {
    assert(!(abs(b - a + 1) < 1));
    int r = nextInt(a, b);
    while (r==nothing) {
        r = nextInt(a, b);
    }
    return r;
}

int uRandom::nextInt(int length, int* not_ord, int size) {
    return nextInt(0, length - 1, not_ord, size);
}

int uRandom::nextInt(int a, int b, int* not_ord, int size) {
    int aux = nextInt(a, b);
    while (bin_search(not_ord, aux, 0, size - 1)) {
        aux = nextInt(a, b);
    }
    return aux;
}



int* uRandom::nextCutPoints(int* array, int length, int size){
    assert(!(length > size || length < 1));
    array[0] = nextInt(size);
    for (int i = 1; i < length; i++) {
        int key = nextInt(size, array, i);
        insert(array, key, i);
    }
    return array;
}

long long* uRandom::nextMask(long long* mask, int bits) {
    int length =  (bits + 63) / 64;
    mask = (mask != NULL)
            ? mask
            : new long long[length];
    for (int j = 0; j < length; j++) {
        mask[j] = nextLong();
    }
    return mask;
}

int* uRandom::nextMask(int* mask, int bits) {
    int length =  (bits + 63) / 64;
    mask = (mask != NULL)
            ? new int[length]
            : mask;
    for (int j = 0; j < length; j++) {
        mask[j] = nextInt();
    }
    return mask;
}

bool uRandom::decode(long long* mask, int bit) {
    return uUtil::decode(mask, bit);
}

int uRandom::roulette_wheel(double sum, double* weigth, int length) {
    double x = nextDouble() * sum;
    for (int i = 0; i < length; i++) {
        if (x > weigth[i]) {
            x = x - weigth[i];
        } else {
            return i;
        }
    }
    assert(0);
}

int uRandom::roulette_wheel(double* weigth, int length) {
    return roulette_wheel(uUtil::sum(weigth, length), weigth, length);
}

//------------------------------------------[PRIVATE]--------------------------------------
bool uRandom::find(int* vet, int length, int key) {
    return uUtil::find(key, vet, length);
}
void uRandom::insert(int* array, int key, int i) {
    int j = i - 1;
    while (j >= 0 && key < array[j]) {
        array[j + 1] = array[j];
        j--;
    }
    array[j + 1] = key;
}
bool uRandom::bin_search(int* array, int length, int key) {
    return bin_search(array, key, 0, length - 1);
}
bool uRandom::bin_search(int* array, int key, int a, int b) {
    if (a <= b) {
        int m = (a + b) / 2;
        if (array[m] < key) {
            return bin_search(array, key, m + 1, b);
        } else if (array[m] > key) {
            return bin_search(array, key, a, m - 1);
        } else {
            return true;
        }
    }
    return false;
}

