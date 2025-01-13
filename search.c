/* File        : search.c */
 /* Deskripsi   : Unit untuk keperluan ADT search */
 /* Pembuat    
: Ersya Hasby Satria */


#include <stdio.h>
#include "search.h"

// Fungsi untuk mencari pengguna dengan pemakaian komputer terbanyak
void CariPemakaianTerbanyak(Rental Dt_Rental[], int N) {
    int maxIndex = 0;
    for (int i = 1; i < N; i++) {
        if (Dt_Rental[i].JamR > Dt_Rental[maxIndex].JamR) {
            maxIndex = i;
        }
    }

    printf("Pengguna dengan pemakaian komputer terbanyak:\n");
    printf("Nama: %s, Lama: %d jam\n", Dt_Rental[maxIndex].Nama, Dt_Rental[maxIndex].JamR);
}

// Fungsi untuk mencari pengguna dengan penggunaan kertas terbanyak
void CariKertasTerbanyak(Rental Dt_Rental[], int N) {
    int maxIndex = 0;
    for (int i = 1; i < N; i++) {
        if (Dt_Rental[i].JumK > Dt_Rental[maxIndex].JumK) {
            maxIndex = i;
        }
    }

    printf("Pengguna dengan penggunaan kertas terbanyak:\n");
    printf("Nama: %s, Jumlah: %d lembar\n", Dt_Rental[maxIndex].Nama, Dt_Rental[maxIndex].JumK);
}

// Fungsi untuk mencari pengguna dengan biaya tertinggi
void CariBiayaTertinggi(Rental Dt_Rental[], int N) {
    int maxIndex = 0;
    for (int i = 1; i < N; i++) {
        if (Dt_Rental[i].TotB > Dt_Rental[maxIndex].TotB) {
            maxIndex = i;
        }
    }

    printf("Pengguna dengan biaya tertinggi:\n");
    printf("Nama: %s, Biaya: Rp. %d\n", Dt_Rental[maxIndex].Nama, Dt_Rental[maxIndex].TotB);
}
