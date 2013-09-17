/* 
 * File:   uUtil.cpp
 * Author: marcio
 * 
 * Created on 11 de Junho de 2013, 20:23
 */

#include "uUtil.h"

#include <cstring>
#include <assert.h>     /* assert */

namespace uUtil{
    /**PI = 3.14159265358979*/
    const double PI = 3.14159265358979;
    /**E  = 2.71828182845904*/
    const double E  = 2.71828182845904;

    double bound(double val, double min, double max) {
        return  val<max ?
                val<min ? min: val :
                max
                ;
    }
    double decode(long long* mask, int bit, double A, double B){
        return (A-B) * (int)(-((mask[bit/64]<<(bit%64))>>63)) + B;
    }
    bool decode(long long* mask, int bit){
        return -((mask[bit/64]<<(bit%64))>>63)==1;
    }
    bool decode(long long val, int bit){
        return -((val<<bit)>>63)==1;
    }
    bool decode(int val, int bit){
        return -((val<<bit)>>31)==1;
    }
    int decodeInt(long long* mask, int bit){
        return (int) -((mask[bit/64]<<(bit%64))>>63);
    }
    int decodeInt(long long val, int bit){
        return (int) -((val<<bit)>>63);
    }
    int decodeInt(int val, int bit){
        return -((val<<bit)>>31);
    }
    void arraycopy(double* src, int srcPos, double* dest, int destPos, int length){
        memcpy(&(dest[destPos]), &(src[srcPos]), length*sizeof(double));
    }
    void arraycopy(float* src, int srcPos, float* dest, int destPos, int length){
        memcpy(&(dest[destPos]), &(src[srcPos]), length*sizeof(float));
    }
    void arraycopy(long long* src, int srcPos, long long* dest, int destPos, int length){
        memcpy(&(dest[destPos]), &(src[srcPos]), length*sizeof(long long));
    }
    void arraycopy(int* src, int srcPos, int* dest, int destPos, int length){
        memcpy(&(dest[destPos]), &(src[srcPos]), length*sizeof(int));
    }
    
    
    int max(int a, int b){
        return  a>b ? a : b;
    }
    
    double sum(double* weigth, int length) {
        double sum = 0;
        for(int i=0; i<length; i++){
            sum += weigth[i];
        }
        return sum;
    }
    
    bool find(int key, int* vet, int length){
        for(int i=0; i<length; i++){
            if(vet[i]==key){
                return true;
            }
        }
        return false;
    }

    
    int minInt(int *array, int length) {
        return array[indexMin(array, length)];
    }
    int maxInt(int *array, int length) {
        return array[indexMax(array, length)];
    }
    double minDbl(double *array, int length) {
        return array[indexMin(array, length)];
    }
    double maxDbl(double *array, int length) {
        return array[indexMax(array, length)];
    }
    int indexMin(int* array, int array_length) {
        assert(!(array==NULL || array_length<=0));
        int min = 0;
        for(int i=1; i<array_length; i++){
            if(array[i]<array[min]){
                min = i;
            }
        }
        return min;
    }
    int indexMin(int* array, int array_length, int *nothing, int nothing_length) {
        assert(!(nothing==NULL || nothing_length<=0));
        assert(!(array==NULL || array_length<=0));
        
        int min = -1;
        int i=0;
        while(i<array_length){
            if(!find(i, nothing, nothing_length)){
                min = i;
            }
            i++;
        }
        while(i<array_length){
            if(array[i]<array[min] && !find(i, nothing, nothing_length)){
                min = i;
            }
            i++;
        }
        return min;
    }
    int indexMax(int* array, int array_length) {
        assert(!(array==NULL || array_length<=0));
        int max = 0;
        for(int i=1; i<array_length; i++){
            if(array[i]>array[max]){
                max = i;
            }
        }
        return max;
    }
    int indexMax(int* array, int array_length, int *nothing, int nothing_length) {
        assert(!(nothing==NULL || nothing_length<=0));
        assert(!(array==NULL || array_length<=0));
        
        int max = -1;
        int i=0;
        while(i<array_length){
            if(!find(i, nothing, nothing_length)){
                max = i;
            }
            i++;
        }
        while(i<array_length){
            if(array[i]>array[max] && !find(i, nothing, nothing_length)){
                max = i;
            }
            i++;
        }
        return max;
    }
    int indexMin(double* array, int array_length) {
        assert(!(array==NULL || array_length<=0));
        int min = 0;
        for(int i=1; i<array_length; i++){
            if(array[i]<array[min]){
                min = i;
            }
        }
        return min;
    }
    int indexMin(double* array, int array_length, int *nothing, int nothing_length) {
        assert(!(nothing==NULL || nothing_length<=0));
        assert(!(array==NULL || array_length<=0));
        int min = -1;
        int i=0;
        while(i<array_length){
            if(!find(i, nothing, nothing_length)){
                min = i;
            }
            i++;
        }
        while(i<array_length){
            if(array[i]<array[min] && !find(i, nothing, nothing_length)){
                min = i;
            }
            i++;
        }
        return min;
    }
    int indexMax(double* array, int array_length) {
        assert(!(array==NULL || array_length<=0));
        int max = 0;
        for(int i=1; i<array_length; i++){
            if(array[i]>array[max]){
                max = i;
            }
        }
        return max;
    }
    int indexMax(double* array, int array_length, int *nothing, int nothing_length) {
        assert(!(nothing==NULL || nothing_length<=0));
        assert(!(array==NULL || array_length<=0));
        int max = -1;
        int i=0;
        while(i<array_length){
            if(!find(i, nothing, nothing_length)){
                max = i;
            }
            i++;
        }
        while(i<array_length){
            if(array[i]>array[max] && !find(i, nothing, nothing_length)){
                max = i;
            }
            i++;
        }
        return max;
    }
    int indexMax(double* array, bool* lotes, int length) {
        assert(!(length<=0));
        int i = 0;
        while(i<length && lotes[i]){ 
            i++;
        }
        for(int j = i+1; j<length; j++){
            if(!lotes[j] && array[j] > array[i]){
                i = j;
            }
        }
        return i;
    }
}


