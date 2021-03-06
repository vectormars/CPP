#include "NominalFilter.h"
#include <unordered_set>

NominalFilter::NominalFilter(vector<int> index, int no)
{
    myIndex = index;
    varNo = no;
}
NominalFilter :: ~NominalFilter(){}

vector<Patient *> NominalFilter :: meetCriteria(vector<Patient *> patients){
    vector<Patient *> vectOut;
    vectOut.reserve(3000);
    for(auto p : patients){
        if(find(myIndex.begin(), myIndex.end(), getPatientX(p,varNo)) != myIndex.end()){
            vectOut.push_back(p);
        }
    }
    return vectOut;
}
