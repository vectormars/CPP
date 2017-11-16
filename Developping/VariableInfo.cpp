#include "VariableInfo.h"
#include "Support.cpp"
#include <vector>
#include <map>
#include <iostream>


using namespace std;


VariableInfo::VariableInfo(int no, int type, vector<int> dataSetColumn){
        varNo = no;
        varType = type;
        map<vector<int>, vector<int>> mapDict;
        if(type==2){
            vector<int> uni = uniqueValues(dataSetColumn);
            mapDict = mapSubsets(uni,no);
        }else if(type==1){
            vector<int> uni = uniqueValues(dataSetColumn);
            mapDict = mapSequence(uni,no);
        }else if(type==0){
            vector<int> uni = uniqueValues(dataSetColumn);
            mapDict = mapSequence(uni,no);
        }else{
            cout<<"\nIn correct input for data type.\n";
        }
        searchSets = mapDict;
    }

int VariableInfo::getCombSize(){    return searchSets.size();   }
int VariableInfo::getVarNo(){ return varNo;   }
int VariableInfo::getVarType(){ return varType;   }
map<vector<int>, vector<int>> VariableInfo::getCombs(){ return searchSets; }

vector<int> VariableInfo::getComb(vector<int> vectIn) {
    if(getVarType()==2){
        vector<int> add = searchSets[vectIn];
        vectIn.insert(vectIn.end(),add.begin(),add.end());
        return vectIn;
    }else{
        return searchSets[vectIn];
    }
}

void VariableInfo::getCombPrint(vector<int> vectIn){
    print1DVector(getComb(vectIn));
}

void VariableInfo::printVarInfo(){
    cout<<"Variable number: "<<getVarNo()<<"\tType: "<<getEnumType(dataType(getVarType()))<<endl;
    cout<<getCombSize()<<" available combinations:"<<endl;
    if(getVarType()==2){
        printNominalMap(searchSets);
    }else{
        printOrdinalMap(searchSets);
    }
}




