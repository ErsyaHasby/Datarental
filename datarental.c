/* File        : datarental.c */
 /* Deskripsi   : Unit untuk keperluan ADT datarental */
 /* Pembuat    
: Ersya Hasby Satria */


#include <stdio.h>
#include "datarental.h"

// Fungsi untuk menghitung biaya rental
void HitungBiaya(Rental *rental) {
    rental->TotB = (rental->JamR * 3000) + (rental->JumK * 250);
    if (rental->TotB > 10000) {
        rental->TotB -= 1000; // Diskon
    }
}

// Fungsi untuk input data rental
void InputData(Rental Dt_Rental[], int *N) {
    printf("Masukkan nama: ");
    scanf(" %[^\n]s", Dt_Rental[*N].Nama);

    printf("Masukkan lama pemakaian (jam): ");
    scanf("%d", &Dt_Rental[*N].JamR);

    printf("Masukkan jumlah kertas yang digunakan (lembar): ");
    scanf("%d", &Dt_Rental[*N].JumK);

    printf("Masukkan tanggal rental:\n");
    SetDate(&Dt_Rental[*N].TglRental);

    HitungBiaya(&Dt_Rental[*N]);
    (*N)++;
}

// Fungsi untuk menyimpan data ke file
void SimpanDataKeFile(Rental Dt_Rental[], int N) {
    FILE *file = fopen("rental_data.txt", "a");
    if (file == NULL) {
        printf("Gagal membuka file untuk menyimpan data.\n");
        return;
    }

    for (int i = 0; i < N; i++) {
        fprintf(file, "%s %d %d %d %d %d %d\n", Dt_Rental[i].Nama, Dt_Rental[i].JamR, Dt_Rental[i].JumK, 
                Dt_Rental[i].TglRental.dd, Dt_Rental[i].TglRental.mm, Dt_Rental[i].TglRental.yyyy, Dt_Rental[i].TotB);
    }

    fclose(file);
    printf("Data berhasil disimpan ke file.\n");
}

// Fungsi untuk memuat data dari file
void MuatDataDariFile(Rental Dt_Rental[], int *N) {
    FILE *file = fopen("rental_data.txt", "r");
    if (file == NULL) {
        printf("File tidak ditemukan. Data akan dimulai dari awal.\n");
        return;
    }

    *N = 0;
    while (fscanf(file, " %49[^\n] %d %d %d %d %d %d", Dt_Rental[*N].Nama, &Dt_Rental[*N].JamR, 
                  &Dt_Rental[*N].JumK, &Dt_Rental[*N].TglRental.dd, &Dt_Rental[*N].TglRental.mm, 
                  &Dt_Rental[*N].TglRental.yyyy, &Dt_Rental[*N].TotB) == 7) {
        (*N)++;
    }

    fclose(file);
}

// Fungsi untuk menampilkan laporan
void TampilkanLaporan(Rental Dt_Rental[], int N) {
    printf("\n--- LAPORAN RENTAL ---\n");
    for (int i = 0; i < N; i++) {
        printf("Nama: %s\n", Dt_Rental[i].Nama);
        printf("Lama pemakaian: %d jam\n", Dt_Rental[i].JamR);
        printf("Jumlah kertas: %d lembar\n", Dt_Rental[i].JumK);
        printf("Tanggal rental: ");
        PrintDate(Dt_Rental[i].TglRental);
        printf("\nTotal biaya: Rp. %d\n", Dt_Rental[i].TotB);
        printf("------------------------\n");
    }
}
