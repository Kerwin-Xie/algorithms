#include <stdio.h> // fopen
#include <iostream> // atoi
#include <vector>

using namespace std;

void sieveOfEratosthenes(long long n) {
    FILE* pFile;
    pFile = fopen("huge-prime-list.bin", "wb");
    vector<bool> primesEratosthenes (n+1, true);

    long long tmp = 2;
    fwrite(&tmp, sizeof(long long),1, pFile);
    for (long long i=3; i<n; i+=2) {
        if (primesEratosthenes[i]) {
            fwrite(&i, sizeof(long long), 1, pFile);

            for (long long j=i*i; j<=n; j+=i) {
                primesEratosthenes[j] = false;
            }
        }
    }

    fclose(pFile);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "You have to specify n" << endl;
    } else {
        long long  n = (long long) atoi(argv[1]);
        sieveOfEratosthenes(n);
    }
    return 0;
}
