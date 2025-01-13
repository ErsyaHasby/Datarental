#include <stdio.h>
#include "datarental.h"
#include "search.h"

int main() {
    Rental Dt_Rental[100];
    int N = 0;

    // Muat data dari file
    MuatDataDariFile(Dt_Rental, &N);

    int pilihan;
    do {
        printf("\nMenu:\n");
        printf("1. Input Data Rental\n");
        printf("2. Tampilkan Laporan\n");
        printf("3. Cari Pengguna dengan Pemakaian Terbanyak\n");
        printf("4. Cari Pengguna dengan Kertas Terbanyak\n");
        printf("5. Cari Pengguna dengan Biaya Tertinggi\n");
        printf("6. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                InputData(Dt_Rental, &N);
                SimpanDataKeFile(Dt_Rental, N);
                break;
            case 2:
                TampilkanLaporan(Dt_Rental, N);
                break;
            case 3:
                CariPemakaianTerbanyak(Dt_Rental, N);
                break;
            case 4:
                CariKertasTerbanyak(Dt_Rental, N);
                break;
            case 5:
                CariBiayaTertinggi(Dt_Rental, N);
                break;
            case 6:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 6);

    return 0;
}
