#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

void splitNumbers(int num, map<int,int> &primes){
    int j;
    map<int,int>::iterator itr;
    for(int i=2;i<=num;++i){
        j=i;
        for(itr=primes.begin();itr!=primes.end() && j>1;++itr){
            while(j%(*itr).first==0 && j>1){
                ++(*itr).second;
                j/=(*itr).first;
            }
        }
        if(j>1) primes.emplace(j,1);
    }
}

void printPrimes(map<int,int> primes){
    int i=0;
    map<int,int>::iterator itr;
    for(itr=primes.begin();itr!=primes.end();++itr,++i){
        if(i%15==0 && i>0) cout << '\n' << "      ";
        cout << setw(3) << (*itr).second;
    }
}

int main() {
    int n;
    map<int,int> primes;
    while(scanf("%d",&n)==1 && n){
        primes.emplace(2,0);
        splitNumbers(n,primes);
        cout << setw(3) << n << "! =";
        printPrimes(primes);
        cout << '\n';
        primes.clear();
    }
    return 0;
}