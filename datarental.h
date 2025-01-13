#ifndef DATARENTAL_H
#define DATARENTAL_H

#include "date.h"

typedef struct {
    char Nama[50];
    int JamR;    // Lama pemakaian komputer (jam)
    int JumK;    // Jumlah kertas yang dipakai (lembar)
    int TotB;    // Total biaya
    Date TglRental; // Tanggal rental
} Rental;

void InputData(Rental Dt_Rental[], int *N);
void SimpanDataKeFile(Rental Dt_Rental[], int N);
void MuatDataDariFile(Rental Dt_Rental[], int *N);
void TampilkanLaporan(Rental Dt_Rental[], int N);

#endif
