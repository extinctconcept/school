#include <iostream>
#include <fstream>

const int XDIM=1024;
const int YDIM=1024;
const int MAXINTENSITY=256;

using namespace std;

int main(){
    ofstream fout;
    fout.open("red.ppm");
    fout<<"P3\n";
    fout<<XDIM<<" "<<YDIM<<"\n"<<MAXINTENSITY-1<<"\n";
    for(int i=0;i<YDIM;++i){
        for(int j=0;j<XDIM;++j){
            fout<<j%MAXINTENSITY<<" ";
            fout<<"0 ";
            fout<<i%MAXINTENSITY<<" ";
        }
        fout<<endl;
    }
    fout.close();

    return 0;
}
