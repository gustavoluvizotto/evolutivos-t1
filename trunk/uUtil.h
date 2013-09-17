/* 
 * File:   uUtil.h
 * Author: marcio
 *
 * Created on 11 de Junho de 2013, 20:23
 */

#ifndef UUTIL_H
#define	UUTIL_H

namespace uUtil{
    extern const double PI;
    extern const double E;
    
    extern double bound(double val, double min, double max);
    extern double decode(long long* mask, int bit, double A, double B);
    extern bool decode(long long* mask, int bit);
    extern bool decode(long long val, int bit);
    extern bool decode(int val, int bit);
    extern int decodeInt(long long* mask, int bit);
    extern int decodeInt(long long val, int bit);
    extern int decodeInt(int val, int bit);
    
    extern void arraycopy(double* src, int srcPos, double* dest, int destPos, int length);
    extern void arraycopy(float* src, int srcPos, float* dest, int destPos, int length);
    extern void arraycopy(long long* src, int srcPos, long long* dest, int destPos, int length);
    extern void arraycopy(int* src, int srcPos, int* dest, int destPos, int length);
    
    extern int max(int a, int b);
    extern double sum(double* weigth, int length);
    extern bool find(int key, int* vet, int length);

    
    extern int minInt(int *array, int length);
    extern int maxInt(int *array, int length);
    extern double minDbl(double *array, int length);
    extern double maxDbl(double *array, int length);
    extern int indexMin(int* array, int array_length);
    extern int indexMin(int* array, int array_length, int *nothing, int nothing_length);
    extern int indexMax(int* array, int array_length);
    extern int indexMax(int* array, int array_length, int *nothing, int nothing_length);
    extern int indexMin(double* array, int array_length);
    extern int indexMin(double* array, int array_length, int *nothing, int nothing_length);
    extern int indexMax(double* array, int array_length);
    extern int indexMax(double* array, int array_length, int *nothing, int nothing_length);
    extern int indexMax(double* array, bool* lotes, int length);
    
    
    template<class T>
    void Swap(T** objs, int a, int b) {
        T* aux = objs[a];
        objs[a] = objs[b];
        objs[b] = aux;
    }
    template<class T>
    int min(T* array, int length) {
        int min=0;
        for(int i=1; i<length; i++){
            if(array[i] < array[min]){
                min = i;
            }
        }
        return min;
    }
    template<class T>
    int max(T* array, int length) {
        int max=0;
        for(int i=1; i<length; i++){
            if(array[i]>array[max]){
                max = i; 
            }
        }
        return max;
    }
    
}



#endif	/* UUTIL_H */

