/* 
 * File:   ComParameterAbstract.cpp
 * Author: marcio
 * 
 * Created on 13 de Junho de 2013, 16:37
 */

#include "LinkerParameterAbstract.h"
#include "RgxRule.h"
#include "ComDefines.h"

int LinkerParameterAbstract::Int(const char* name, int init) throw(exception) {
    return Int(name, init, Integer::MIN_VALUE, Integer::MAX_VALUE, NULL);
}
int LinkerParameterAbstract::Int(const char* name, int init, int min, int max) throw(exception) {
    return Int(name, init, min, max, NULL);
}
long long LinkerParameterAbstract::Long(const char* name, long long init) throw(exception) {
    return Long(name, init, Long::MIN_VALUE, Long::MAX_VALUE, NULL);
}
long long LinkerParameterAbstract::Long(const char* name, long long init, long long min, long long max) throw(exception) {
    return Long(name, init, min, max, NULL);
}
double LinkerParameterAbstract::Dbl(const char* name, double init) throw(exception) {
    return Dbl(name, init, Double::MIN_VALUE, Double::MAX_VALUE, NULL);
}
double LinkerParameterAbstract::Dbl(const char* name, double init, double min, double max) throw(exception) {
    return Dbl(name, init, min, max, NULL);
}
const char* LinkerParameterAbstract::String(const char* name, const char* init) throw(exception) {
    return String(name, init, NULL);
}
const char* LinkerParameterAbstract::Regex(const char* name, const char* init, const char* regex) throw(exception) {
    return Regex(name, init, regex, NULL);
}
const char* LinkerParameterAbstract::File(const char* name, const char* extension) throw(exception){
    return File(name, NULL, &extension, 1);
}
const char* LinkerParameterAbstract::File(const char* name, const char** extensions, int length) throw(exception){
    return File(name, NULL, extensions, length);
}
const char* LinkerParameterAbstract::File(const char* name, const char* description, const char** extensions, int length) throw(exception){
    const RgxRule* r = RgxRule::One(extensions, length);
    const char* rtn = FileRgx(name, description, r);
    delete r;
    return rtn;
}
const char** LinkerParameterAbstract::Files(const char* name, const char** extensions, int length) throw(exception) {
    return Files(name, NULL, extensions, length);
}
const char** LinkerParameterAbstract::Files(const char* name, const char* description, const char** extensions, int length) throw(exception) {
    RgxRule** r = RgxRule::All(extensions, length);
    const char** rtn = FilesRgx(name, description, r, length);
    for(int i=0; i<length; i++){
        delete r[i];
    }
    delete[] r;
    return rtn;
}
const char* LinkerParameterAbstract::Directory(const char* name) throw(exception){
    return Directory(name, NULL);
}
const char* LinkerParameterAbstract::Directory(const char* name, const char* description) throw(exception){
    const RgxRule* r = new RgxRule(RgxRule::DIRECTORY);
    const char* rtn = FileRgx(name, description, r);
    delete r;
    return rtn;
}
const char* LinkerParameterAbstract::Directory(const char* name, const char* description, const char** constraints, int length) throw(exception) {
    const RgxRule* r = RgxRule::Directory(constraints, length);
    const char* rtn = FileRgx(name, description, r);
    delete r;
    return rtn;
}
const char* LinkerParameterAbstract::FileRgx(const char* name, const char* description, const char* regex, const char** constraints, int length) throw(exception) {
    const RgxRule* r = new RgxRule(regex, constraints, length);
    const char* rtn = FileRgx(name, description, r);
    delete r;
    return rtn;
}
const char* LinkerParameterAbstract::FileRgx(const char* name, const RgxRule* rule) throw(exception) {
    return FileRgx(name, NULL, rule);
}
const char** LinkerParameterAbstract::FilesRgx(const char* name, RgxRule** rules, int length) throw(exception) {
    return FilesRgx(name, NULL, rules, length);
}

