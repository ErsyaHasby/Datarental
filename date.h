#ifndef DATE_H
#define DATE_H

typedef struct {
    int dd;   // Hari
    int mm;   // Bulan
    int yyyy; // Tahun
} Date;

// Fungsi untuk mengisi tanggal
void SetDate(Date *date);

// Fungsi untuk mencetak tanggal
void PrintDate(Date date);

#endif
