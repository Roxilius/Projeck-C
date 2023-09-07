char nama_barang[100];

char nomor_barang[100], jumlah_barang[100];
    
char buff_harga_jual[100];
char buff_harga_pokok[100];

int buff_nomor_barang = 0, buff_jumlah_barang = 0;

int hari, bulan, tahun;
char buff_hari[100], buff_bulan[100], buff_tahun[100];

void CRUD(int buff_nomor_barang, int buff_jumlah_barang);

const char *type1 = "%s#%s#%s#%s\n";
const char *struck_pembelian1 = "%s#%s#%s#%s#%s#%s\n";
const char *tambah_barang = "%s#%s#%s#0\n";
const char *hapus_barang = "%s#%s#%s\n";

void PILIH_BARANG(){
    bingkaii(53,23,40,6,0,8,219);
    bingkaii(105,23,40,6,15,8,219);
    bingkaii(158,23,40,6,15,8,219);
    warna(15);
    posisi(63,26); printf("~~~~~ SIN BACCO ~~~~~");
    posisi(113,26); printf("~~~~~ RUBBY BACCO ~~~~~");
    posisi(166,26); printf("~~~~~ BARACK BACCO ~~~~~");
}

void stock(){
    
    int idx = 0;
    FILE* sin = fopen("sin_bacco.txt","r");
    while (fscanf(sin,type,&sin_bacco[idx], &harga_sin[idx], &pokok_sin[idx], &stock_sin[idx]) != EOF){
        buff_harga_sin[idx] = atof(harga_sin[idx]);
        buff_pokok_sin[idx] = atof(pokok_sin[idx]);
        buff_stock_sin[idx] = atoi(stock_sin[idx]);
        idx++;
    }
    fclose(sin);
    idx = 0;
    FILE* barack = fopen("barack_bacco.txt","r");
    while (fscanf(barack,type,&barack_bacco[idx], &harga_barack[idx], &pokok_barack[idx], &stock_barack[idx]) != EOF){
        buff_harga_barack[idx] = atof(harga_barack[idx]);
        buff_pokok_barack[idx] = atof(pokok_barack[idx]);
        buff_stock_barack[idx] = atoi(stock_barack[idx]);
        idx++;
    }
    fclose(barack);
    idx = 0;
    FILE* rubby = fopen("rubby_bacco.txt","r");
    while (fscanf(rubby,type,&rubby_bacco[idx], &harga_rubby[idx], &pokok_rubby[idx], &stock_rubby[idx]) != EOF){
        buff_harga_rubby[idx] = atof(harga_rubby[idx]);
        buff_pokok_rubby[idx] = atof(pokok_rubby[idx]);
        buff_stock_rubby[idx] = atoi(stock_rubby[idx]);
        idx++;
    }
    fclose(rubby);
}

void SINN(){
    stock();
    bingkaii(47,3,158,41,15,8,219);
    bingkaii(50,5,152,37,0,8,35);
    posisi(60,7); printf("Flavour\t\t\t\tHarga Jual\t\t\t\tHarga Pokok Penjualan\t\t\t\tStock");
    for (int i = 0; i < 32; i++){
        warna(0); posisi(58,9+i); printf("%i). %s",i+1,sin_bacco[i]);
        for (int j = 0; j < 1; j++){
            posisi(95,9+i); printf("Rp. %i.-",buff_harga_sin[i]);
            for (int z = 0; z < 1; z++){
                posisi(140,9+i); printf("Rp. %i.-",buff_pokok_sin[i]);
                for (int x = 0; x < 1; x++){
                    posisi(186,9+i); printf("%i",buff_stock_sin[i]);
                }
            }
        }
    }
    char ch;
    while ((ch = getch()) != 13){
        if (ch == 27){
            tempat = 1;
            tempat1 = 1;
            select_admin();
        }
    }
}

void RUBBY(){
    stock();
    bingkaii(47,3,158,41,15,8,219);
    bingkaii(50,5,152,37,0,8,35);
    posisi(60,7); printf("Flavour\t\t\t\tHarga Jual\t\t\t\tHarga Pokok Penjualan\t\t\t\tStock");
    for (int i = 0; i < 30; i++){
        warna(0); posisi(58,9+i); printf("%i). %s",i+1,rubby_bacco[i]);
        for (int j = 0; j < 1; j++){
            posisi(95,9+i); printf("Rp. %i.-",buff_harga_rubby[i]);
            for (int z = 0; z < 1; z++){
                posisi(140,9+i); printf("Rp. %i.-",buff_pokok_rubby[i]);
                for (int x = 0; x < 1; x++){
                    posisi(186,9+i); printf("%i",buff_stock_rubby[i]);
                }
            }
        }
    }
    char ch;
    while ((ch = getch()) != 13){
        if (ch == 27){
            tempat = 1;
            tempat1 = 1;
            select_admin();
        }
    }
}

void BARACK(){
    stock();
    int idx = 0;
    bingkaii(47,3,158,41,15,8,219);
    bingkaii(50,5,152,37,0,8,35);
    posisi(60,7); printf("Flavour\t\t\t\tHarga Jual\t\t\t\tHarga Pokok Penjualan\t\t\t\tStock");
    for (int i = 0; i < 33; i++){
        warna(0); posisi(58,9+i); printf("%i). %s",i+1,barack_bacco[i]);
        for (int j = 0; j < 1; j++){
            posisi(95,9+i); printf("Rp. %i.-",buff_harga_barack[i]);
            for (int z = 0; z < 1; z++){
                posisi(140,9+i); printf("Rp. %i.-",buff_pokok_barack[i]);
                for (int x = 0; x < 1; x++){
                    posisi(186,9+i); printf("%i",buff_stock_barack[i]);
                }
            }
        }
    }
    char ch;
    while ((ch = getch()) != 13 || idx == 0){
        if (ch == 27){
            tempat = 1;
            tempat1 = 1;
            select_admin();
        }
    }
}

void MENU(int halaman){
    stock();
    char ch;
    int idx = 0;
    if (tempat == 2 || tempat == 4){
        if (tempat1 == 1 ){
            if (halaman == 1){
                bingkaii(47,3,158,41,15,8,219);
                bingkaii(50,5,152,37,0,8,35);
                warna(0); posisi(122,41); printf("< 1");
                warna(15); posisi(127,41); printf("2 >");
                warna(0); posisi(60,7); printf("Flavour\t\t\t\t\t\tHarga Pokok Penjualan\t\t\t\t\t\tStock");
                for (int i = 0; i < 15; i++){
                    warna(0); posisi(58,9+i); printf("%i). %s",i+1,sin_bacco[i]);
                    for (int z = 0; z < 1; z++){
                        posisi(116,9+i); printf("Rp. %i.-",buff_pokok_sin[i]);
                        for (int x = 0; x < 1; x++){
                            posisi(178,9+i); printf("%i",buff_stock_sin[i]);
                        }
                    }        
                }
            }
            else if (halaman == 2){
                bingkaii(50,5,152,37,0,8,35);
                warna(15); posisi(122,41); printf("< 1");
                warna(0); posisi(127,41); printf("2 >");
                warna(0);posisi(60,7); printf("Flavour\t\t\t\t\t\tHarga Pokok Penjualan\t\t\t\t\t\tStock");
                for (int i = 15, j = 0; i < 32; i++, j++){
                    if (sin_bacco[i] != NULL){
                        warna(0); posisi(58,9+j); printf("%i). %s",i+1,sin_bacco[i]);
                        for (int z = 0; z < 1; z++){
                            posisi(116,9+j); printf("Rp. %i.-",buff_pokok_sin[i]);
                            for (int x = 0; x < 1; x++){
                                posisi(178,9+j); printf("%i",buff_stock_sin[i]);
                            }
                        }
                    }
                }
            }
        }
        else if (tempat1 == 2){
            if (halaman == 1){
                bingkaii(47,3,158,41,15,8,219);
                bingkaii(50,5,152,37,0,8,35);
                warna(0); posisi(122,41); printf("< 1");
                warna(15); posisi(127,41); printf("2 >");
                warna(0); posisi(60,7); printf("Flavour\t\t\t\t\t\tHarga Pokok Penjualan\t\t\t\t\t\tStock");
                for (int i = 0; i < 15; i++){
                    warna(0); posisi(58,9+i); printf("%i). %s",i+1,rubby_bacco[i]);
                    for (int z = 0; z < 1; z++){
                        posisi(116,9+i); printf("Rp. %i.-",buff_pokok_rubby[i]);
                        for (int x = 0; x < 1; x++){
                            posisi(178,9+i); printf("%i",buff_stock_rubby[i]);
                        }
                    }        
                }
            }
            else if (halaman == 2){
                bingkaii(50,5,152,37,0,8,35);
                warna(15); posisi(122,41); printf("< 1");
                warna(0); posisi(127,41); printf("2 >");
                warna(0);posisi(60,7); printf("Flavour\t\t\t\t\t\tHarga Pokok Penjualan\t\t\t\t\t\tStock");
                for (int i = 15, j = 0; i < 30; i++, j++){
                    warna(0); posisi(58,9+j); printf("%i). %s",i+1,rubby_bacco[i]);
                    for (int z = 0; z < 1; z++){
                        posisi(116,9+j); printf("Rp. %i.-",buff_pokok_rubby[i]);
                        for (int x = 0; x < 1; x++){
                            posisi(178,9+j); printf("%i",buff_stock_rubby[i]);
                        }
                    }
                }
            }
        }
        else if (tempat1 == 3){
            if (halaman == 1){
                bingkaii(47,3,158,41,15,8,219);
                bingkaii(50,5,152,37,0,8,35);
                warna(0); posisi(122,41); printf("< 1");
                warna(15); posisi(127,41); printf("2 >");
                warna(0); posisi(60,7); printf("Flavour\t\t\t\t\t\tHarga Pokok Penjualan\t\t\t\t\t\tStock");
                for (int i = 0; i < 15; i++){
                    warna(0); posisi(58,9+i); printf("%i). %s",i+1,barack_bacco[i]);
                    for (int z = 0; z < 1; z++){
                        posisi(116,9+i); printf("Rp. %i.-",buff_pokok_barack[i]);
                        for (int x = 0; x < 1; x++){
                            posisi(178,9+i); printf("%i",buff_stock_barack[i]);
                        }
                    }        
                }
            }
            else if (halaman == 2){
                bingkaii(50,5,152,37,0,8,35);
                warna(15); posisi(122,41); printf("< 1");
                warna(0); posisi(127,41); printf("2 >");
                warna(0);posisi(60,7); printf("Flavour\t\t\t\t\t\tHarga Pokok Penjualan\t\t\t\t\t\tStock");
                for (int i = 15, j = 0; i < 33; i++, j++){
                    warna(0); posisi(58,9+j); printf("%i). %s",i+1,barack_bacco[i]);
                    for (int z = 0; z < 1; z++){
                        posisi(116,9+j); printf("Rp. %i.-",buff_pokok_barack[i]);
                        for (int x = 0; x < 1; x++){
                            posisi(178,9+j); printf("%i",buff_stock_barack[i]);
                        }
                    }
                }
            }
        }
        if (tempat >= 1 && tempat <= 2 || tempat == 4){
            bingkaii(98,29,50,4,15,8,219);
            warna(0); posisi(100,31); printf("MASUKAN NOMOR BARANG : ");
        }        
        if (tempat != 4 ){
            bingkaii(98,35,50,4,15,8,219);
            warna(0); posisi(100,37); printf("MASUKAN JUMLAH BARANG : ");
        }
        v_nomor_barang(nomor_barang,halaman);
        buff_nomor_barang = atoi(nomor_barang);
        if (tempat != 4){
            posisi(124,37);
            v_jumlah_barang(jumlah_barang,halaman,tempat);
            buff_jumlah_barang = atoi(jumlah_barang);
        }
    }
    else if (tempat == 3){
        bingkaii(47,3,158,41,15,8,219);
        if (tempat1 >= 1 && tempat1 <= 3){
            bingkaii(60,23,50,4,15,8,219);
            posisi(62,25); warna(0); printf("NAMA BARANG : ");
            bingkaii(60,30,50,4,15,8,219);
            posisi(62,32); warna(0); printf("HARGA JUAL BARANG : ");
            bingkaii(60,37,50,4,15,8,219);
            posisi(62,39); warna(0); printf("HARGA POKOK BARANG : ");
        }
        posisi(76,25);
        v_nama_barang(nama_barang,tempat1);
        posisi(82,32);
        v_harga_jual(buff_harga_jual);
        posisi(83,39);
        v_harga_pokok(buff_harga_pokok);
    }
    CRUD(buff_nomor_barang,buff_jumlah_barang);    
}