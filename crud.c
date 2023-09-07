void PROSES_PEMBELIAN(int buff_nomor_barang, int buff_jumlah_barang);
void waktu();
void check_out(int buff_nomor_barang1, int buff_jumlah_barang1);
void CRUD_USER(int buff_nomor_barang1, int buff_jumlah_barang1);


void CRUD(int buff_nomor_barang, int buff_jumlah_barang){
    int idx = 0;
    if (tempat == 2 || tempat == 4 ){
        if (tempat1 == 1){
            FILE* update = fopen("sin_bacco.txt","r");
            while (fscanf(update,type,&sin_bacco[idx], &harga_sin[idx], &pokok_sin[idx], &stock_sin[idx]) != EOF){
                if (buff_nomor_barang - 1 == idx){
                    if (tempat == 2){
                        buff_stock_sin[buff_nomor_barang-1] += buff_jumlah_barang;
                    }
                    itoa(buff_stock_sin[buff_nomor_barang-1],stock_sin[buff_nomor_barang-1],10);
                }
                idx++;
            }
            fclose(update);
            if (tempat >= 1 && tempat <= 2){
                update = fopen("sin_bacco.txt","w");
                for (int i = 0; i < idx; i++){
                    fprintf(update,type1,sin_bacco[i],harga_sin[i],pokok_sin[i],stock_sin[i]);
                }
                fclose(update);
            }
            else if (tempat == 4){
                update = fopen("sin_bacco.txt","w");
                for (int i = 0; i < idx; i++){
                    if (buff_nomor_barang- 1 != i){
                        fprintf(update,type1,sin_bacco[i],harga_sin[i],pokok_sin[i],stock_sin[i]);
                    }
                }
                fclose(update);
            }
        }
        if (tempat1 == 2){
            FILE* update = fopen("rubby_bacco.txt","r");
            while (fscanf(update,type,&rubby_bacco[idx], &harga_rubby[idx], &pokok_rubby[idx], &stock_rubby[idx]) != EOF){
                if (buff_nomor_barang - 1 == idx){
                    if (tempat == 2){
                        buff_stock_rubby[buff_nomor_barang-1] += buff_jumlah_barang;
                    }
                    itoa(buff_stock_rubby[buff_nomor_barang-1],stock_rubby[buff_nomor_barang-1],10);
                }
                idx++;
            }
            fclose(update);
            if (tempat >= 1 && tempat <= 2){
                update = fopen("rubby_bacco.txt","w");
                for (int i = 0; i < idx; i++){
                    fprintf(update,type1,rubby_bacco[i],harga_rubby[i],pokok_rubby[i],stock_rubby[i]);
                }
                fclose(update);
            }
            else if (tempat == 4){
                update = fopen("rubby_bacco.txt","w");
                for (int i = 0; i < idx; i++){
                    if (buff_nomor_barang- 1 != i){
                        fprintf(update,type1,rubby_bacco[i],harga_rubby[i],pokok_rubby[i],stock_rubby[i]);
                    }
                }
                fclose(update);
            }
        }
        if (tempat1 == 3){
            FILE* update = fopen("barack_bacco.txt","r");
            while (fscanf(update,type,&barack_bacco[idx], &harga_barack[idx], &pokok_barack[idx], &stock_barack[idx]) != EOF){
                if (buff_nomor_barang - 1 == idx){
                    if (tempat == 2){
                        buff_stock_barack[buff_nomor_barang-1] += buff_jumlah_barang;
                    }
                    itoa(buff_stock_barack[buff_nomor_barang-1],stock_barack[buff_nomor_barang-1],10);
                }
                idx++;
            }
            if (tempat >= 1 && tempat <= 2){
                update = fopen("barack_bacco.txt","w");
                for (int i = 0; i < idx; i++){
                    fprintf(update,type1,barack_bacco[i],harga_barack[i],pokok_barack[i],stock_barack[i]);
                }
                fclose(update);
            }
            else if (tempat == 4){
                update = fopen("barack_bacco.txt","w");
                for (int i = 0; i < idx; i++){
                    if (buff_nomor_barang- 1 != i){
                        fprintf(update,type1,barack_bacco[i],harga_barack[i],pokok_barack[i],stock_barack[i]);
                    }
                }
                fclose(update);
            }
        }
    }
    else if (tempat == 3){
        int ada = false;
        if (tempat1 == 1){
            if (tempat1 == 1){
                FILE* tambah_sin = fopen("sin_bacco.txt","r");
                while (fscanf(tambah_sin,type,&sin_bacco[idx], &harga_sin[idx], &pokok_sin[idx], &stock_sin[idx]) != EOF){
                    idx++;
                }
                fclose(tambah_sin);
            }
            else if (tempat1 == 2){
                FILE* tambah_rubby = fopen("rubby_bacco.txt","r");
                while (fscanf(tambah_rubby,type,&rubby_bacco[idx], &harga_rubby[idx], &pokok_rubby[idx], &stock_rubby[idx]) != EOF){
                    idx++;
                }
                fclose(tambah_rubby);
            }
            else if (tempat1 == 3){
                FILE* tambah_barack = fopen("barack_bacco.txt","r");
                while (fscanf(tambah_barack,type,&barack_bacco[idx], &harga_barack[idx], &pokok_barack[idx], &stock_barack[idx]) != EOF){
                    idx++;
                }
                fclose(tambah_barack);
            }
            for (int i = 0; i < idx; i++){
                if (tempat1 == 1){
                    if (strcmp(nama_barang,sin_bacco[i]) == 0){
                        ada = true;
                    }
                }
                else if (tempat1 == 2){
                    if (strcmp(nama_barang,rubby_bacco[i]) == 0){
                        ada = true;
                    }
                }
                else if (tempat1 == 3){
                    if (strcmp(nama_barang,barack_bacco[i]) == 0){
                        ada = true;
                    }
                }
            }
            if (ada == true){
                posisi(76,25); warna(15); printf("                            ");
                posisi(82,32); warna(15); printf("                       ");
                posisi(83,40); warna(15); printf("                       ");
                posisi(62,22); warna(15); printf("%s SUDAH ADA !!!",nama_barang);
                Sleep(200);
                posisi(62,22); warna(15); printf("                             ");
                Sleep(200);
                posisi(62,22); warna(15); printf("%s SUDAH ADA !!!",nama_barang);
                Sleep(200);
                posisi(62,22); warna(15); printf("                             ");
                MENU(halaman);
            }
            else if (ada == false){
                if (tempat1 == 1){
                    FILE* tambah_sin = fopen("sin_bacco.txt","a");
                    if (idx < 32){
                        fprintf(tambah_sin,tambah_barang,nama_barang,buff_harga_jual,buff_harga_pokok);
                    }
                    else{
                        posisi(62,22); warna(15); printf("TEMPAT BARANG SUDAH PENUH !!!");
                        Sleep(300);
                        MENU(halaman);
                    }
                    fclose(tambah_sin);
                }
                if (tempat1 == 2){
                    FILE* tambah_rubby = fopen("rubby_bacco.txt","a");
                    if (idx < 30){
                        fprintf(tambah_rubby,tambah_barang,nama_barang,buff_harga_jual,buff_harga_pokok);
                    }
                    else{
                        posisi(62,22); warna(15); printf("TEMPAT BARANG SUDAH PENUH !!!");
                        Sleep(300);
                        MENU(halaman);
                    }
                    fclose(tambah_rubby);
                }
                if (tempat1 == 3){
                    FILE* tambah_barack = fopen("barack_bacco.txt","a");
                    if (idx < 32){
                        fprintf(tambah_barack,tambah_barang,nama_barang,buff_harga_jual,buff_harga_pokok);
                    }
                    else{
                        posisi(62,22); warna(15); printf("TEMPAT BARANG SUDAH PENUH !!!");
                        Sleep(300);
                        MENU(halaman);
                    }
                    fclose(tambah_barack);
                }
            }
        }
    }

    if (halaman == 1){
        halaman = 1;
    }
    else if (halaman == 2){
        halaman = 2;
    }
    if (tempat == 2){
        PROSES_PEMBELIAN(buff_nomor_barang,buff_jumlah_barang);
    }
    else if (tempat == 4){
        RIWAYAT_HAPUS_BARANG(buff_nomor_barang);
    }
    if (tempat >= 2 && tempat <= 4){
        MENU(halaman);
    }
    
}

void PROSES_PEMBELIAN(int buff_nomor_barang, int buff_jumlah_barang){
    int idx = 0;
    FILE* pembelian = fopen("pembelian.txt","a");
    waktu();
    if (tempat1 == 1){
        buff_pokok_sin[buff_nomor_barang-1] *= buff_jumlah_barang;
        itoa(buff_pokok_sin[buff_nomor_barang-1],pokok_sin[buff_nomor_barang-1],10); 
        printf("%s",pokok_sin[buff_nomor_barang-1]);
        fprintf(pembelian,struck_pembelian1,buff_hari,buff_bulan,buff_tahun,sin_bacco[buff_nomor_barang-1],pokok_sin[buff_nomor_barang-1],jumlah_barang);
    }
    else if (tempat1 == 2){
        buff_pokok_rubby[buff_nomor_barang-1] *= buff_jumlah_barang;
        itoa(buff_pokok_rubby[buff_nomor_barang-1],pokok_rubby[buff_nomor_barang-1],10); 
        fprintf(pembelian,struck_pembelian1,buff_hari,buff_bulan,buff_tahun,rubby_bacco[buff_nomor_barang-1],pokok_rubby[buff_nomor_barang-1],jumlah_barang);
    }
    else if (tempat1 == 3){
        buff_pokok_barack[buff_nomor_barang-1] *= buff_jumlah_barang;
        itoa(buff_pokok_barack[buff_nomor_barang-1],pokok_barack[buff_nomor_barang-1],10); 
        fprintf(pembelian,struck_pembelian1,buff_hari,buff_bulan,buff_tahun,barack_bacco[buff_nomor_barang-1],pokok_barack[buff_nomor_barang-1],jumlah_barang);
    }
    fclose(pembelian);
}

void RIWAYAT_HAPUS_BARANG(int buff_nomor_barang){
    FILE* riwayat = fopen("riwayat_hapus_barang.txt","a");
    if (tempat1 == 1){
        buff_stock_sin[buff_nomor_barang-1] = atoi(stock_sin[buff_nomor_barang-1]);
        buff_pokok_sin[buff_nomor_barang-1] = atoi(pokok_sin[buff_nomor_barang-1]);
        buff_pokok_sin[buff_nomor_barang-1] *= buff_stock_sin[buff_nomor_barang-1];
        itoa(buff_pokok_sin[buff_nomor_barang-1],pokok_sin[buff_nomor_barang-1],10);
        fprintf(riwayat,hapus_barang,sin_bacco[buff_nomor_barang-1],pokok_sin[buff_nomor_barang-1],stock_sin[buff_nomor_barang-1]);
    }
    else if (tempat1 == 2){
        buff_stock_rubby[buff_nomor_barang-1] = atoi(stock_rubby[buff_nomor_barang-1]);
        buff_pokok_rubby[buff_nomor_barang-1] = atoi(pokok_rubby[buff_nomor_barang-1]);
        buff_pokok_rubby[buff_nomor_barang-1] *= buff_stock_rubby[buff_nomor_barang-1];
        itoa(buff_pokok_rubby[buff_nomor_barang-1],pokok_rubby[buff_nomor_barang-1],10);
        fprintf(riwayat,hapus_barang,rubby_bacco[buff_nomor_barang-1],pokok_rubby[buff_nomor_barang-1],stock_rubby[buff_nomor_barang-1]);
    }
    else if (tempat1 == 3){
        buff_stock_barack[buff_nomor_barang-1] = atoi(stock_barack[buff_nomor_barang-1]);
        buff_pokok_barack[buff_nomor_barang-1] = atoi(pokok_barack[buff_nomor_barang-1]);
        buff_pokok_barack[buff_nomor_barang-1] *= buff_stock_barack[buff_nomor_barang-1];
        itoa(buff_pokok_barack[buff_nomor_barang-1],pokok_barack[buff_nomor_barang-1],10);
        fprintf(riwayat,hapus_barang,barack_bacco[buff_nomor_barang-1],pokok_barack[buff_nomor_barang-1],stock_barack[buff_nomor_barang-1]);
    }
    fclose(riwayat);
}

void CRUD_USER(int buff_nomor_barang1, int buff_jumlah_barang1){
    int idx = 0;
    if (tempat_user == 1){
        if (tempat2 == 1){
            FILE* update = fopen("sin_bacco.txt","r");
            while (fscanf(update,"%[^#]#%[^#]#%[^#]#%[^\n]\n",&sin_bacco[idx], &harga_sin[idx], &pokok_sin[idx], &stock_sin[idx]) != EOF){
                if (buff_nomor_barang1-1 == idx){
                    buff_stock_sin[buff_nomor_barang1-1] -= buff_jumlah_barang1;
                    itoa(buff_stock_sin[buff_nomor_barang1-1],stock_sin[buff_nomor_barang1-1],10);
                }
                idx++;
            }
            fclose(update);
            update = fopen("sin_bacco.txt","w");
            for (int i = 0; i < idx; i++){
                fprintf(update,type1,sin_bacco[i],harga_sin[i],pokok_sin[i],stock_sin[i]);
            }
            fclose(update);
        } 
        if (tempat2 == 2){
            FILE* update = fopen("rubby_bacco.txt","r");
            while (fscanf(update,"%[^#]#%[^#]#%[^#]#%[^\n]\n",&rubby_bacco[idx], &harga_rubby[idx], &pokok_rubby[idx], &stock_rubby[idx]) != EOF){
                if (buff_nomor_barang1-1 == idx){
                    buff_stock_rubby[buff_nomor_barang1-1] -= buff_jumlah_barang1;
                    itoa(buff_stock_rubby[buff_nomor_barang1-1],stock_rubby[buff_nomor_barang1-1],10);
                }
                idx++;
            }
            fclose(update);
            update = fopen("rubby_bacco.txt","w");
            for (int i = 0; i < idx; i++){
                fprintf(update,type1,rubby_bacco[i],harga_rubby[i],pokok_rubby[i],stock_rubby[i]);
            }
            fclose(update);
        } 
        if (tempat2 == 3){
            FILE* update = fopen("barack_bacco.txt","r");
            while (fscanf(update,"%[^#]#%[^#]#%[^#]#%[^\n]\n",&barack_bacco[idx], &harga_barack[idx], &pokok_barack[idx], &stock_barack[idx]) != EOF){
                if (buff_nomor_barang1-1 == idx){
                    buff_stock_barack[buff_nomor_barang1-1] -= buff_jumlah_barang1;
                    itoa(buff_stock_barack[buff_nomor_barang1-1],stock_barack[buff_nomor_barang1-1],10);
                }
                idx++;
            }
            fclose(update);
            update = fopen("barack_bacco.txt","w");
            for (int i = 0; i < idx; i++){
                fprintf(update,type1,barack_bacco[i],harga_barack[i],pokok_barack[i],stock_barack[i]);
            }
            fclose(update);
        }  
        check_out(buff_nomor_barang1,buff_jumlah_barang1);
    }
    MENU_USER(halaman);
}