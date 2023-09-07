int tempat = 1, tempat1 = 1, halaman = 1;
char buff_hapus_barang[100][100], buff_hapus_pokok[100][100], buff_hapus_stock[100][100];
const char *struck_pembelian = "%[^#]#%[^#]#%[^\n]\n";
int total_pembelian = 0, buff_tamp_pokok = 0, buff_tamp_stock = 0;
int total_hapus_pokok = 0, tamp_pokok[100], tamp_stock[100];

char flavour1[100][100], total_cek1[100][100], pcs1[100][100];
int buff_total_cek1[100], total_penjualan = 0;

void bingkaii(int x, int y, int panjang, int lebar, int color, int bg, int ascii);
void admin(), bingkai_admin(), select_admin(), PILIH_BARANG(), SINN(), MENU(int halaman), RUBBY(), BARACK();
void RIWAYAT_HAPUS_BARANG(),DATA_USER();
char* tampil_hapus();
void data_pembelian(),penjualan();

void admin(){
    tempat = 1;
    bingkaii(2,1,206,46,6,8,219);
    bingkaii(3,2,40,4,6,8,219);
    bingkaii(3,7,40,4,6,8,219);
    bingkaii(3,12,40,4,6,8,219);
    bingkaii(3,17,40,4,6,8,219);
    bingkaii(3,22,40,4,6,8,219);
    bingkaii(3,27,40,4,6,8,219);
    bingkaii(3,32,40,4,6,8,219);
    bingkaii(3,37,40,4,6,8,219);
}

void z(){
    if (tempat == 1){
        bingkaii(3,2,40,4,0,8,219);
    }
    else if (tempat == 2){
        bingkaii(3,7,40,4,0,8,219);
    }
    else if (tempat == 3){
        bingkaii(3,12,40,4,0,8,219);
    }
    else if (tempat == 4){
        bingkaii(3,17,40,4,0,8,219);
    }
    else if (tempat == 5){
        bingkaii(3,22,40,4,0,8,219);
    }
    else if (tempat == 6){
        bingkaii(3,27,40,4,0,8,219);
    }
    else if (tempat == 7){
        bingkaii(3,32,40,4,0,8,219);
    }
    else if (tempat == 8){
        bingkaii(3,37,40,4,0,8,219);
    }
    warna(0);
    posisi(15,4); printf("READ STOCK BARANG"); 
    posisi(15,9); printf("BELI STOCK BARANG");
    posisi(14,14); printf("TAMBAH BARANG BARU"); 
    posisi(17,19); printf("DELETE BARANG"); 
    posisi(19,24); printf("PEMBELIAN"); 
    posisi(19,29); printf("PENJUALAN");
    posisi(10,34); printf("RIWAYAT PENGHAPUSAN BARANG");
    posisi(19,39); printf("DATA USER");
}

void select_admin(){
    char pilih;
    z();
    bingkaii(47,3,158,41,15,8,219);
    PILIH_BARANG();
    tempat1 = 1;
    while ((pilih = getch()) != 13){
        if (pilih == 27){
            bingkai_user();
        }
        else if (pilih == 80){
            // arrow bawah
            if (tempat == 1){
                tempat = 2;
                tempat1 = 1;
                bingkaii(3,2,40,4,6,8,219);
                bingkaii(3,7,40,4,0,8,219);
                warna(0);
                posisi(15,4); printf("READ STOCK BARANG"); 
                posisi(15,9); printf("BELI STOCK BARANG");
                PILIH_BARANG();
            }
            else if (tempat == 2){
                tempat = 3;
                tempat1 = 1;
                bingkaii(3,7,40,4,6,8,219);
                bingkaii(3,12,40,4,0,8,219);
                warna(0);
                posisi(15,9); printf("BELI STOCK BARANG");
                posisi(14,14); printf("TAMBAH BARANG BARU"); 
                PILIH_BARANG();
            }
            else if (tempat == 3){
                tempat = 4;
                tempat1 = 1;
                bingkaii(3,12,40,4,6,8,219);
                bingkaii(3,17,40,4,0,8,219);
                warna(0);
                posisi(14,14); printf("TAMBAH BARANG BARU"); 
                posisi(17,19); printf("DELETE BARANG");
                PILIH_BARANG();
            }
            else if (tempat == 4){
                tempat = 5;
                bingkaii(3,17,40,4,6,8,219);
                bingkaii(3,22,40,4,0,8,219);
                warna(0);
                posisi(17,19); printf("DELETE BARANG"); 
                posisi(19,24); printf("PEMBELIAN"); 
                data_pembelian();
            }
            else if (tempat == 5){
                tempat = 6;
                bingkaii(3,22,40,4,6,8,219);
                bingkaii(3,27,40,4,0,8,219);
                warna(0);
                posisi(19,24); printf("PEMBELIAN"); 
                posisi(19,29); printf("PENJUALAN");
                penjualan();
            }
            else if (tempat == 6){
                tempat = 7;
                tempat1 = 1;
                bingkaii(3,27,40,4,6,8,219);
                bingkaii(3,32,40,4,0,8,219);
                warna(0);
                posisi(19,29); printf("PENJUALAN");
                posisi(10,34); printf("RIWAYAT PENGHAPUSAN BARANG");
                tampil_hapus(halaman);
            }
            else if (tempat == 7){
                tempat = 8;
                tempat1 = 1;
                bingkaii(3,32,40,4,6,8,219);
                bingkaii(3,37,40,4,0,8,219);
                warna(0);
                posisi(10,34); printf("RIWAYAT PENGHAPUSAN BARANG");
                posisi(19,39); printf("DATA USER");
                DATA_USER();
            }
            else if (tempat == 8){
                tempat = 1;
                bingkaii(3,37,40,4,6,8,219);
                bingkaii(3,2,40,4,0,8,219);
                warna(0);
                posisi(19,39); printf("DATA USER");
                posisi(15,4); printf("READ STOCK BARANG");
                PILIH_BARANG();
            }
        }
        else if (pilih == 72){
            // arrow atas
            if (tempat == 8){
                tempat = 7;
                bingkaii(3,32,40,4,0,8,219);
                bingkaii(3,37,40,4,6,8,219);
                warna(0);
                posisi(19,39); printf("DATA USER");
                posisi(10,34); printf("RIWAYAT PENGHAPUSAN BARANG");
                tampil_hapus(halaman);
            }
            else if (tempat == 7){
                tempat = 6;
                bingkaii(3,27,40,4,0,8,219);
                bingkaii(3,32,40,4,6,8,219);
                warna(0);
                posisi(19,29); printf("PENJUALAN");
                posisi(10,34); printf("RIWAYAT PENGHAPUSAN BARANG");
                penjualan();
            }
            else if (tempat == 6){
                tempat = 5;
                bingkaii(3,22,40,4,0,8,219);
                bingkaii(3,27,40,4,6,8,219);
                warna(0); posisi(19,29); printf("PENJUALAN");
                posisi(19,24); printf("PEMBELIAN");
                data_pembelian();
            }
            else if (tempat == 5){
                tempat = 4;
                tempat1 = 1;
                bingkaii(3,17,40,4,0,8,219);
                bingkaii(3,22,40,4,6,8,219);
                warna(0); posisi(19,24); printf("PEMBELIAN");
                posisi(17,19); printf("DELETE BARANG"); 
                PILIH_BARANG();
            }
            else if (tempat == 4){
                tempat = 3;
                tempat1 = 1;
                bingkaii(3,12,40,4,0,8,219);
                bingkaii(3,17,40,4,6,8,219);
                warna(0); posisi(14,14); printf("TAMBAH BARANG BARU"); 
                posisi(17,19); printf("DELETE BARANG"); 
                PILIH_BARANG();
            }
            else if (tempat == 3){
                tempat = 2;
                tempat1 = 1;
                bingkaii(3,7,40,4,0,8,219);
                bingkaii(3,12,40,4,6,8,219);
                warna(0); posisi(15,9); printf("BELI STOCK BARANG");
                posisi(14,14); printf("TAMBAH BARANG BARU");
                PILIH_BARANG();
            }
            else if (tempat == 2){
                tempat = 1;
                tempat1 = 1;
                bingkaii(3,2,40,4,0,8,219);
                bingkaii(3,7,40,4,6,8,219);
                warna(0); posisi(15,4); printf("READ STOCK BARANG"); 
                posisi(15,9); printf("BELI STOCK BARANG");
                PILIH_BARANG();
            }
            else if (tempat == 1){
                tempat = 8;
                bingkaii(3,2,40,4,6,8,219);
                bingkaii(3,37,40,4,0,8,219);
                warna(0);
                posisi(15,4); printf("READ STOCK BARANG"); 
                posisi(19,39); printf("DATA USER");
                DATA_USER();
            }
        }
        else if (pilih == 77 && (tempat >= 1 && tempat <= 4)){
            // arrow kanan tempat1
            if (tempat1 == 1){
                tempat1 = 2;
                bingkaii(53,23,40,6,15,8,219);
                bingkaii(105,23,40,6,0,8,219);
                warna(15); posisi(63,26); printf("~~~~~ SIN BACCO ~~~~~");
                posisi(113,26); printf("~~~~~ RUBBY BACCO ~~~~~");
            }
            else if (tempat1 == 2){
                tempat1 = 3;
                bingkaii(105,23,40,6,15,8,219);
                bingkaii(158,23,40,6,0,8,219);
                warna(15);posisi(113,26); printf("~~~~~ RUBBY BACCO ~~~~~");
                posisi(166,26); printf("~~~~~ BARACK BACCO ~~~~~");
            }
            else if (tempat1 == 3){
                tempat1 = 1;
                bingkaii(158,23,40,6,15,8,219);
                bingkaii(53,23,40,6,0,8,219);
                warna(15); posisi(63,26); printf("~~~~~ SIN BACCO ~~~~~");
                posisi(166,26); printf("~~~~~ BARACK BACCO ~~~~~");
            }
        }
        else if (pilih == 75 && (tempat >= 1 && tempat <= 4)){
            // arrow kiri tempat1
            if (tempat1 == 3){
                tempat1 = 2;
                bingkaii(158,23,40,6,15,8,219);
                bingkaii(105,23,40,6,0,8,219);
                warna(15); posisi(113,26); printf("~~~~~ RUBBY BACCO ~~~~~");
                posisi(166,26); printf("~~~~~ BARACK BACCO ~~~~~");
            }
            else if (tempat1 == 2){
                tempat1 = 1;
                bingkaii(53,23,40,6,0,8,219);
                bingkaii(105,23,40,6,15,8,219);
                warna(15); posisi(63,26); printf("~~~~~ SIN BACCO ~~~~~");
                posisi(113,26); printf("~~~~~ RUBBY BACCO ~~~~~");
            }
            else if (tempat1 == 1){
                tempat1 = 3;
                bingkaii(53,23,40,6,15,8,219);
                bingkaii(158,23,40,6,0,8,219); 
                warna(15); posisi(63,26); printf("~~~~~ SIN BACCO ~~~~~");
                posisi(166,26); printf("~~~~~ BARACK BACCO ~~~~~");
            }
        }
    }
    
    if (tempat == 1){
        if (tempat1 == 1){
            SINN();
        }
        else if (tempat1 == 2){
            RUBBY();
        }
        else if (tempat1 == 3){
            BARACK();
        }
    }
    else if (tempat == 2 || tempat == 4){
        if (tempat1 == 1){
            MENU(halaman);
        }
        else if (tempat1 == 2){
            MENU(halaman);
        }
        else if (tempat1 == 3){
            MENU(halaman);
        }
    }
    else if (tempat == 3){
        if (tempat1 == 1){
            MENU(halaman);
        }
        else if (tempat1 == 2){
            MENU(halaman);
        }
        else if (tempat1 == 3){
            MENU(halaman);
        }
    }
}

char* tampil_hapus(int halaman){
    bingkaii(47,3,158,41,15,8,219);
    halaman = 1;
    int idx = 0, tahan = 0;
    char ch;
    FILE* tampilkan_hapus = fopen("riwayat_hapus_barang.txt","r");
    while (fscanf(tampilkan_hapus,struck_pembelian,&buff_hapus_barang[idx],&buff_hapus_pokok[idx],&buff_hapus_stock[idx]) != EOF){
        tamp_pokok[idx] = atoi(buff_hapus_pokok[idx]);
        total_hapus_pokok += tamp_pokok[idx];
        idx++;
    }
    fclose(tampilkan_hapus);
    bingkaii(50,5,152,37,0,8,35);
    warna(0); posisi(122,41); printf("< 1");
    warna(15); posisi(127,41); printf("2 >");
    warna(0); posisi(60,7); printf("Flavour\t\t\t\t\t\tHarga Pokok Penjualan\t\t\t\t\t\tStock");
    for (int i = 0; i < idx && i < 30; i++){
        warna(0); posisi(58,9+i); printf("%i.) %s",i+1,buff_hapus_barang[i]);
        posisi(116,9+i); printf("Rp. %s.-",buff_hapus_pokok[i]);
        posisi(178,9+i); printf("%s",buff_hapus_stock[i]);
    }
    posisi(115,39); printf("TOTAL : %i",total_hapus_pokok);
    while ((ch = getch()) != 13 || tahan == 0){
        if (ch == 27){
            total_hapus_pokok = 0;
            select_admin();
        }
        else if (ch == 77){
            if (halaman == 1){
                halaman = 2;
                bingkaii(50,5,152,37,0,8,35);
                warna(15); posisi(122,41); printf("< 1");
                warna(0); posisi(127,41); printf("2 >");
                warna(0); posisi(60,7); printf("Flavour\t\t\t\t\t\tHarga Pokok Penjualan\t\t\t\t\t\tStock");
                for (int i = 30, j = 0; i < idx && i < 60; i++, j++){
                    warna(0); posisi(58,9+j); printf("%i.) %s",i+1,buff_hapus_barang[i]);
                    posisi(116,9+j); printf("Rp. %s.-",buff_hapus_pokok[i]);
                    posisi(178,9+j); printf("%s",buff_hapus_stock[i]);
                }
            }
            else if (halaman == 2){
                halaman = 1;
                bingkaii(50,5,152,37,0,8,35);
                warna(0); posisi(122,41); printf("< 1");
                warna(15); posisi(127,41); printf("2 >");
                warna(0); posisi(60,7); printf("Flavour\t\t\t\t\t\tHarga Pokok Penjualan\t\t\t\t\t\tStock");
                for (int i = 0; i < idx && i < 30; i++){
                    warna(0); posisi(58,9+i); printf("%i.) %s",i+1,buff_hapus_barang[i]);
                    posisi(116,9+i); printf("Rp. %s.-",buff_hapus_pokok[i]);
                    posisi(178,9+i); printf("%s",buff_hapus_stock[i]);
                }
            }
        }
        else if (ch == 75){
            if (halaman == 2){
                halaman = 1;
                bingkaii(50,5,152,37,0,8,35);
                warna(0); posisi(122,41); printf("< 1");
                warna(15); posisi(127,41); printf("2 >");
                warna(0); posisi(60,7); printf("Flavour\t\t\t\t\t\tHarga Pokok Penjualan\t\t\t\t\t\tStock");
                for (int i = 0; i < idx && i < 30; i++){
                    warna(0); posisi(58,9+i); printf("%i.) %s",i+1,buff_hapus_barang[i]);
                    posisi(116,9+i); printf("Rp. %s.-",buff_hapus_pokok[i]);
                    posisi(178,9+i); printf("%s",buff_hapus_stock[i]);
                }
            }
            else if (halaman == 1){
                halaman = 2;
                bingkaii(50,5,152,37,0,8,35);
                warna(15); posisi(122,41); printf("< 1");
                warna(0); posisi(127,41); printf("2 >");
                warna(0); posisi(60,7); printf("Flavour\t\t\t\t\t\tHarga Pokok Penjualan\t\t\t\t\t\tStock");
                for (int i = 30, j = 0; i < idx && i < 60; i++, j++){
                    warna(0); posisi(58,9+j); printf("%i.) %s",i+1,buff_hapus_barang[i]);
                    posisi(116,9+j); printf("Rp. %s.-",buff_hapus_pokok[i]);
                    posisi(178,9+j); printf("%s",buff_hapus_stock[i]);
                }
            }
        }
        posisi(115,39); printf("TOTAL : %i",total_hapus_pokok);
    }
}

void data_pembelian(){
    char tamp_tanggal[100][100], tamp_bulan[100][100], tamp_tahun[100][100];
    char tamp_barang[100][100], tamp_pokok[100][100], tamp_stock[100][100];
    int idx = 0;
    int halaman = 1;
    FILE* nota_pembelian = fopen("pembelian.txt","r");
    while (fscanf(nota_pembelian,"%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#%[^\n]\n",tamp_tanggal[idx],tamp_bulan[idx],tamp_tahun[idx],tamp_barang[idx],tamp_pokok[idx],tamp_stock[idx]) != EOF){
        buff_tamp_pokok = atoi(tamp_pokok[idx]);
        total_pembelian += buff_tamp_pokok;
        idx++;
    }
    fclose(nota_pembelian);
    bingkaii(47,3,158,41,15,8,219);
    bingkaii(50,5,152,37,0,8,35);
    warna(0); posisi(122,41); printf("< 1");
    warna(15); posisi(127,41); printf("2 >");
    warna(0); posisi(112,7); printf("~~~ DATA PEMBELIAN ~~~");
    warna(0); posisi(60,8); printf("Flavour\t\t\t\t\t\tHarga Pokok Penjualan\t\t\t\t\t\tStock");
    for (int i = 0; i < idx && i < 30; i++){
        warna(0);
        posisi(58,9+i); printf("%i.) %s-%s/%s -> %s",i+1,tamp_tanggal[i],tamp_bulan[i],tamp_tahun[i],tamp_barang[i]);
        posisi(120,9+i); printf("%s",tamp_pokok[i]);
        posisi(178,9+i); printf("%s",tamp_stock[i]);
    }
    posisi(115,39);printf("TOTAL PEMBELIAN : %i",total_pembelian);
    char ch;
    int tahan = 0;
    while ((ch = getch()) != 13 || tahan == 0){
        if (ch == 27){
            total_pembelian = 0;
            select_admin();
        }
        else if (ch == 77){
            if (halaman == 1){
                halaman = 2;
                bingkaii(50,5,152,37,0,8,35);
                warna(15); posisi(122,41); printf("< 1");
                warna(0); posisi(127,41); printf("2 >");
                warna(0); posisi(112,7); printf("~~~ DATA PEMBELIAN ~~~");
                warna(0); posisi(60,8); printf("Flavour\t\t\t\t\t\tHarga Pokok Penjualan\t\t\t\t\t\tStock");
                for (int i = 30, j = 0; i < idx && i < 60; j++, i++){
                    warna(0);
                    posisi(58,9+j); printf("%i.) %s-%s/%s -> %s",i+1,tamp_tanggal[i],tamp_bulan[i],tamp_tahun[i],tamp_barang[i]);
                    posisi(120,9+i); printf("%s",tamp_pokok[i]);
                    posisi(178,9+i); printf("%s",tamp_stock[i]);
                }
                posisi(115,39);printf("TOTAL PEMBELIAN : %i",total_pembelian);
            }
            else if (halaman == 2){
                halaman = 1;
                bingkaii(50,5,152,37,0,8,35);
                warna(0); posisi(122,41); printf("< 1");
                warna(15); posisi(127,41); printf("2 >");
                warna(0); posisi(112,7); printf("~~~ DATA PEMBELIAN ~~~");
                warna(0); posisi(60,8); printf("Flavour\t\t\t\t\t\tHarga Pokok Penjualan\t\t\t\t\t\tStock");
                for (int i = 0; i < idx && i < 30; i++){
                    warna(0);
                    posisi(58,9+i); printf("%i.) %s-%s/%s -> %s",i+1,tamp_tanggal[i],tamp_bulan[i],tamp_tahun[i],tamp_barang[i]);
                    posisi(120,9+i); printf("%s",tamp_pokok[i]);
                    posisi(178,9+i); printf("%s",tamp_stock[i]);
                }
                posisi(115,39);printf("TOTAL PEMBELIAN : %i",total_pembelian);
            }
        }
        else if (ch == 75){
            if (halaman == 2){
                halaman = 1;
                bingkaii(50,5,152,37,0,8,35);
                warna(0); posisi(122,41); printf("< 1");
                warna(15); posisi(127,41); printf("2 >");
                warna(0); posisi(112,7); printf("~~~ DATA PEMBELIAN ~~~");
                warna(0); posisi(60,8); printf("Flavour\t\t\t\t\t\tHarga Pokok Penjualan\t\t\t\t\t\tStock");
                for (int i = 0; i < idx && i < 30; i++){
                    warna(0);
                    posisi(58,9+i); printf("%i.) %s-%s/%s -> %s",i+1,tamp_tanggal[i],tamp_bulan[i],tamp_tahun[i],tamp_barang[i]);
                    posisi(120,9+i); printf("%s",tamp_pokok[i]);
                    posisi(178,9+i); printf("%s",tamp_stock[i]);
                }
                posisi(115,39);printf("TOTAL PEMBELIAN : %i",total_pembelian);
            }
            else if (halaman == 1){
                halaman = 2;
                bingkaii(50,5,152,37,0,8,35);
                warna(15); posisi(122,41); printf("< 1");
                warna(0); posisi(127,41); printf("2 >");
                warna(0); posisi(112,7); printf("~~~ DATA PEMBELIAN ~~~");
                warna(0); posisi(60,8); printf("Flavour\t\t\t\t\t\tHarga Pokok Penjualan\t\t\t\t\t\tStock");
                for (int i = 30, j = 0; i < idx && i < 60; j++, i++){
                    warna(0);
                    posisi(58,9+j); printf("%i.) %s-%s/%s -> %s",i+1,tamp_tanggal[i],tamp_bulan[i],tamp_tahun[i],tamp_barang[i]);
                    posisi(120,9+i); printf("%s",tamp_pokok[i]);
                    posisi(178,9+i); printf("%s",tamp_stock[i]);
                }
                posisi(115,39);printf("TOTAL PEMBELIAN : %i",total_pembelian);
            }
        }
        
    }
}

void DATA_USER(){
    int idx = 0;
    FILE* data_user = fopen("data_user.txt","r");
    while (fscanf(data_user,tamp_data_user,&buff_username[idx],&buff_password[idx],&buff_nama[idx],&buff_alamat[idx],&buff_umur[idx]) != EOF){
        idx++;
    }
    fclose(data_user);
    bingkaii(47,3,158,41,15,8,219);
    bingkaii(50,5,152,37,0,8,35);
    warna(0); posisi(115,7); printf("~~~ DATA USER ~~~");
    warna(0); posisi(60,8); printf("USERNAME\t\t\t\tPASSWORD\t\t\tNAMA\t\t\tUMUR\t\t\t\tALAMAT");
    for (int i = 0; i < idx && i < 30; i++){
        warna(0);
        posisi(58,9+i); printf("%s", buff_username[i]);
        posisi(98,9+i); printf("%s", buff_password[i]);
        posisi(125,9+i); printf("%s", buff_nama[i]);
        posisi(153,9+i); printf("%s", buff_umur[i]);
        posisi(180,9+i); printf("%s", buff_alamat[i]);
        
    }
    char ch;
    int tahan = 0;
    while ((ch = getch()) != 13 || tahan == 0){
        if (ch == 27){
            select_admin();
        }
    }
}

void penjualan(){
    bingkaii(47,3,158,41,15,8,219);
    bingkaii(50,5,152,37,0,8,35);
    int idx = 0;
    total_penjualan = 0;
    FILE* data_penjualan = fopen("penjualan.txt","r");
    while (fscanf(data_penjualan,"%[^#]#%[^#]#%[^\n]\n",&flavour1[idx],&total_cek1[idx],&pcs1[idx]) != EOF){
        buff_total_cek1[idx] = atoi(total_cek1[idx]);
        total_penjualan += buff_total_cek1[idx];
        idx++;
    }
    fclose(data_penjualan);
    warna(0); posisi(110,7); printf("~~~ DATA PENJUALAN ~~~");
    warna(0); posisi(66,8); printf("Flavour\t\t\t\t\t\tHarga\t\t\t\t\t\t\tStock");
    for (int i = 0; i < idx && i < 30; i++){
        warna(0); posisi(58,9+i); printf("%i.) %s",i+1,flavour1[i]);
        posisi(116,9+i); printf("Rp. %s.-",total_cek1[i]);
        posisi(178,9+i); printf("%s",pcs1[i]);
    }
    posisi(115,41); printf("TOTAL PENJUALAN : %i",total_penjualan);
    char ch;
    int tahan = 0;
    while ((ch = getch()) != 13 || tahan == 0){
        if (ch == 27){
            select_admin();
        }
    }
}