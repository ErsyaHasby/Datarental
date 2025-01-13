/* File        : date.c */
 /* Deskripsi   : Unit untuk keperluan ADT Date */
 /* Pembuat    
: Ersya Hasby Satria */


#include <stdio.h>
#include "date.h"

// Fungsi untuk mengisi tanggal
void SetDate(Date *date) {
    printf("Masukkan tanggal (dd mm yyyy): ");
    scanf("%d %d %d", &date->dd, &date->mm, &date->yyyy);
}

// Fungsi untuk mencetak tanggal
void PrintDate(Date date) {
    printf("%02d-%02d-%04d", date.dd, date.mm, date.yyyy);
}
