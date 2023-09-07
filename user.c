const char *masukan_user = "%s#%s#%s#%s#%s\n";
void gambar_barang(int tempat2), USERR(), select_user(),tampil_check_out();
void check_out(int buff_nomor_barang1, int buff_jumlah_barang1), hapus_checkout(), edit_pcs();
char nomor_barang1[100], jumlah_barang1[100];
char* v_pcs(char* jum_pcs, int buff_nomor);
char* v_nomor(char* nomor_barang);
char* pembayaran(char* bayar);
char flavour[100][100], total_cek[100][100], pcs[100][100];
int buff_total_cek[100], buff_pcs[100], buff_pcs1[100], buff_pcs2[100];
int total_chekout = 0;
const char *chek = "%[^#]#%[^#]#%[^\n]\n";
const char *masuk_chek = "%s#%s#%s\n";
void CRUD_PCS(int buff_nomor, int buff_jum_pcs),balik_hapus_checkout();
void login(){
    char username[100], password[100];
    bingkaii(20,38,50,4,6,8,219);
    bingkaii(140,38,50,4,6,8,219);
    text_login();
    a();
    posisi(22,40); warna(14); printf("USERNAME : ");
    posisi(142,40); printf("PASSWORD : ");
    posisi(96,40); warna(15); printf("<< PRESS ESC TO BACK");
    posisi(34,40); v_username_login(username);
    posisi(153,40); v_password(password);
    int idx = 0, sama =0;
    FILE* data_user = fopen("data_user.txt","r");
    while (fscanf(data_user,"%[^#]#%[^#]#%[^#]#%[^#]#%[^\n]\n",&buff_username[idx],&buff_password[idx],&buff_nama[idx],&buff_alamat[idx],&buff_umur[idx]) != EOF){
        if (strcmp(username,buff_username[idx]) == 0 && strcmp(password,buff_password[idx]) == 0){
            sama++;
        }
        idx++;
    }
    fclose(data_user);
    if (sama != 0){
        USERR();
        select_user();
    }
    else if (strcmp(user,username)==0 && strcmp(pass,password)==0){
        admin();
        select_admin();
    }
    else{
        warna(15);
        posisi(90,38); printf("USERNAME ATAU PASSWORD ANDA SALAH !!!");
        Sleep(300);
        posisi(90,38); printf("                                     ");
        Sleep(200);
        posisi(90,38); printf("USERNAME ATAU PASSWORD ANDA SALAH !!!");
        Sleep(300);
        posisi(90,38); printf("                                     ");
        login();
    }
}

void daftar(){
    char nama[100], alamat[100], umur[100];
    char username[100], password[100];
    bingkaii(2,1,206,47,6,8,219);
    bingkaii(10,4,190,41,6,8,219);
    bingkaii(20,20,100,20,6,8,219);
    bingkaii(21,23,98,0,0,8,22);
    bingkaii(21,26,98,0,0,8,22);
    bingkaii(21,29,98,0,0,8,22);
    bingkaii(21,32,98,0,0,8,22);
    bingkaii(21,35,98,0,0,8,22);
    warna(0);
    text_daftar();
    x();
    posisi(22,22); printf("NAMA\t: ");
    posisi(22,25); printf("UMUR\t:    TAHUN");
    posisi(22,28); printf("ALAMAT\t: ");
    posisi(22,31); printf("USERNAME\t: ");
    posisi(22,34); printf("PASSWORD\t: ");
    posisi(96,44); warna(15); printf("<< PRESS ESC TO BACK");
    posisi(34,22); v_nama(nama);
    posisi(34,25); v_umur(umur);
    posisi(34,28); cekjalan(alamat);
    posisi(34,31); v_username(username);
    posisi(34,34); v_password(password);
    FILE* masuk_user = fopen("data_user.txt","a");
    fprintf(masuk_user,masukan_user,username,password,nama,alamat,umur);
    fclose(masuk_user);
    bingkai_user();
}

void bingkai_user(){
    bingkaii(2,1,206,47,6,8,219);
    bingkaii(10,4,190,34,6,8,219);
    bingkaii(35,41,40,4,0,8,219);
    bingkaii(136,41,40,4,6,8,219);
    posisi(53,43); warna(15); printf("LOGIN");
    posisi(154,43); warna(15); printf("DAFTAR");
    warna(15); posisi(95,43); printf("<< PRESS ESC 2X TO EXIT >>");
    b();
    char ch;
    int pilih = 1;
    while ((ch = getch()) != 13){
        if (ch == 27){
            printf("\a\a\a");
            exit(0);
        }
        else if (ch == 75){
            if ( pilih == 1){
                pilih = 2;
                bingkaii(35,41,40,4,6,8,219);
                bingkaii(136,41,40,4,0,8,219);
                posisi(53,43); warna(15); printf("LOGIN");
                posisi(154,43); warna(15); printf("DAFTAR");
            }
            else if ( pilih == 2){
                pilih = 1;
                bingkaii(35,41,40,4,0,8,219);
                bingkaii(136,41,40,4,6,8,219);
                posisi(53,43); warna(15); printf("LOGIN");
                posisi(154,43); warna(15); printf("DAFTAR");
            }
        }
        else if (ch == 77){
            if ( pilih == 2){
                pilih = 1;
                bingkaii(35,41,40,4,0,8,219);
                bingkaii(136,41,40,4,6,8,219);
                posisi(53,43); warna(15); printf("LOGIN");
                posisi(154,43); warna(15); printf("DAFTAR");
            }
            else if ( pilih == 1){
                pilih = 2;
                bingkaii(35,41,40,4,6,8,219);
                bingkaii(136,41,40,4,0,8,219);
                posisi(53,43); warna(15); printf("LOGIN");
                posisi(154,43); warna(15); printf("DAFTAR");
            }  
        }
    }

    if (pilih == 1){
        bingkaii(2,1,206,47,6,8,219);
        bingkaii(10,4,190,41,6,8,219);
        login();
    }
    else if (pilih == 2){
        daftar();
    }
}

void USERR(){
    tempat_user = 1;
    bingkaii(2,1,206,47,6,8,219);
    //menu barang
    bingkaii(5,5,40,4,15,15,219);
    bingkaii(5,5,9,4,6,6,219);
    bingkaii(40,5,5,4,15,15,219);
    //contoh barang
    bingkaii(5,13,40,4,15,15,219);
    bingkaii(5,13,9,4,6,6,219);
    bingkaii(40,13,5,4,15,15,219);
    //check out
    bingkaii(5,21,40,4,15,15,219);
    bingkaii(5,21,9,4,6,6,219);
    bingkaii(40,21,5,4,15,15,219);
    //keluar
    bingkaii(5,37,40,4,15,15,219);
    bingkaii(5,37,9,4,6,6,219);
    bingkaii(40,37,5,4,15,15,219);
}

void v(){
    if (tempat_user == 1){
        bingkaii(40,5,5,4,12,12,219);
    }
    else if (tempat_user == 2){
        bingkaii(40,13,5,4,12,12,219);
    }
    else if (tempat_user == 3){
        bingkaii(40,21,5,4,12,12,219);
    }
    else if (tempat_user == 4){
        bingkaii(40,37,5,4,12,12,219);
    }
    warna(0); background(15);
    posisi(22,7);  printf("MENU BARANG");
    posisi(21,15); printf("CONTOH BARANG");
    posisi(23,23); printf("CHECK OUT"); 
    posisi(24,39); printf("KELUAR"); 
    
}

void select_user(){
    char ch;
    v();
    bingkaii(47,3,158,41,15,8,219);
    PILIH_BARANG();
    tempat2 = 1;
    while ((ch = getch()) != 13){
        if (ch == 80){
            if (tempat_user == 1){
                tempat_user = 2;
                tempat2 = 1;
                bingkaii(40,5,5,4,15,15,219);
                bingkaii(40,13,5,4,12,12,219);
                bingkaii(47,3,158,41,15,8,219);
                PILIH_BARANG();
            }
            else if (tempat_user == 2){
                tempat_user = 3;
                bingkaii(40,13,5,4,15,15,219);
                bingkaii(40,21,5,4,12,12,219);
                tampil_check_out();
            }
            else if (tempat_user == 3){
                tempat_user = 4;
                bingkaii(40,21,5,4,15,15,219);
                bingkaii(40,37,5,4,12,12,219);
            }
            else if (tempat_user == 4){
                tempat_user = 1;
                tempat2 = 1;
                bingkaii(40,37,5,4,15,15,219);
                bingkaii(40,5,5,4,12,12,219);
                PILIH_BARANG();
            }
        }
        else if (ch == 72){
            if (tempat_user == 4){
                tempat_user = 3;
                bingkaii(40,37,5,4,15,15,219);
                bingkaii(40,21,5,4,12,12,219);
                tampil_check_out();
            }
            else if (tempat_user == 3){
                tempat_user = 2;
                tempat2 = 1;
                bingkaii(40,21,5,4,15,15,219);
                bingkaii(40,13,5,4,12,12,219);
                bingkaii(47,3,158,41,15,8,219);
                PILIH_BARANG();
            }
            else if (tempat_user == 2){
                tempat_user = 1;
                tempat2 = 1;
                bingkaii(40,13,5,4,15,15,219);
                bingkaii(40,5,5,4,12,12,219);
                bingkaii(47,3,158,41,15,8,219);
                PILIH_BARANG();
            }
            else if (tempat_user == 1){
                tempat_user = 4;
                bingkaii(40,5,5,4,15,15,219);
                bingkaii(40,37,5,4,12,12,219);
            }
        }
        else if (ch == 77 && (tempat_user >= 1 && tempat_user <= 2)){
            // arrow kanan tempat2
            if (tempat2 == 1){
                tempat2 = 2;
                bingkaii(53,23,40,6,15,8,219);
                bingkaii(105,23,40,6,0,8,219);
                warna(15); posisi(63,26); printf("~~~~~ SIN BACCO ~~~~~");
                posisi(113,26); printf("~~~~~ RUBBY BACCO ~~~~~");
            }
            else if (tempat2 == 2){
                tempat2 = 3;
                bingkaii(105,23,40,6,15,8,219);
                bingkaii(158,23,40,6,0,8,219);
                warna(15);posisi(113,26); printf("~~~~~ RUBBY BACCO ~~~~~");
                posisi(166,26); printf("~~~~~ BARACK BACCO ~~~~~");
            }
            else if (tempat2 == 3){
                tempat2 = 1;
                bingkaii(158,23,40,6,15,8,219);
                bingkaii(53,23,40,6,0,8,219);
                warna(15); posisi(63,26); printf("~~~~~ SIN BACCO ~~~~~");
                posisi(166,26); printf("~~~~~ BARACK BACCO ~~~~~");
            }
        }
        else if (ch == 75 && (tempat_user >= 1 && tempat_user <= 2)){
            // arrow kiri tempat2
            if (tempat2 == 3){
                tempat2 = 2;
                bingkaii(158,23,40,6,15,8,219);
                bingkaii(105,23,40,6,0,8,219);
                warna(15); posisi(113,26); printf("~~~~~ RUBBY BACCO ~~~~~");
                posisi(166,26); printf("~~~~~ BARACK BACCO ~~~~~");
            }
            else if (tempat2 == 2){
                tempat2 = 1;
                bingkaii(53,23,40,6,0,8,219);
                bingkaii(105,23,40,6,15,8,219);
                warna(15); posisi(63,26); printf("~~~~~ SIN BACCO ~~~~~");
                posisi(113,26); printf("~~~~~ RUBBY BACCO ~~~~~");
            }
            else if (tempat2 == 1){
                tempat2 = 3;
                bingkaii(53,23,40,6,15,8,219);
                bingkaii(158,23,40,6,0,8,219); 
                warna(15); posisi(63,26); printf("~~~~~ SIN BACCO ~~~~~");
                posisi(166,26); printf("~~~~~ BARACK BACCO ~~~~~");
            }
        }
    }
    if (tempat_user == 1){
        MENU_USER(halaman);
    }
    else if (tempat_user == 2){
        gambar_barang(tempat2);
    }
    else if (tempat_user == 4){
        balik_hapus_checkout();
        bingkai_user();
    }
}

void gambar_barang(int tempat2){
    if (tempat2 == 1){
        system("START contoh_barang/sin_img.jpg");
    }
    else if (tempat2 == 2){
        system("START contoh_barang/rubby_img.jpg");
    }
    else if (tempat2 == 3){
        system("START contoh_barang/barack_img.jpg");
    }
    select_user();
}

void MENU_USER(int halaman){
    if (tempat_user == 1){
        if (tempat2 == 1){
            int idx = 0; 
            FILE* sin = fopen("sin_bacco.txt","r");
            while (fscanf(sin,type,&sin_bacco[idx], &harga_sin[idx], &pokok_sin[idx], &stock_sin[idx]) != EOF){
                buff_harga_sin[idx] = atof(harga_sin[idx]);
                buff_pokok_sin[idx] = atof(pokok_sin[idx]);
                buff_stock_sin[idx] = atoi(stock_sin[idx]);
                idx++;
            }
            fclose(sin);
            if (halaman == 1){
                bingkaii(47,3,158,41,15,8,219);
                bingkaii(50,5,152,37,0,8,35);
                warna(0); posisi(122,41); printf("< 1");
                warna(15); posisi(127,41); printf("2 >");
                warna(0); posisi(60,7); printf("Flavour\t\t\t\t\t\t\tHarga\t\t\t\t\t\t\tStock");
                for (int i = 0; i < 15; i++){
                    warna(0); posisi(58,9+i); printf("%i). %s",i+1,sin_bacco[i]);
                    for (int z = 0; z < 1; z++){
                        posisi(116,9+i); printf("Rp. %i.-",buff_harga_sin[i]);
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
                warna(0);posisi(60,7); printf("Flavour\t\t\t\t\t\t\tHarga\t\t\t\t\t\t\tStock");
                for (int i = 15, j = 0; i < idx; i++, j++){
                    warna(0); posisi(58,9+j); printf("%i). %s",i+1,sin_bacco[i]);
                    for (int z = 0; z < 1; z++){
                        posisi(116,9+j); printf("Rp. %i.-",buff_harga_sin[i]);
                        for (int x = 0; x < 1; x++){
                            posisi(178,9+j); printf("%i",buff_stock_sin[i]);
                        }
                    }
                }
            }
        }
        else if (tempat2 == 2){
            int idx = 0;
            FILE* rubby = fopen("rubby_bacco.txt","r");
            while (fscanf(rubby,type,&rubby_bacco[idx], &harga_rubby[idx], &pokok_rubby[idx], &stock_rubby[idx]) != EOF){
                buff_harga_rubby[idx] = atof(harga_rubby[idx]);
                buff_pokok_rubby[idx] = atof(pokok_rubby[idx]);
                buff_stock_rubby[idx] = atoi(stock_rubby[idx]);
                idx++;
            }
            fclose(rubby);
            if (halaman == 1){
                bingkaii(47,3,158,41,15,8,219);
                bingkaii(50,5,152,37,0,8,35);
                warna(0); posisi(122,41); printf("< 1");
                warna(15); posisi(127,41); printf("2 >");
                warna(0); posisi(60,7); printf("Flavour\t\t\t\t\t\t\tHarga\t\t\t\t\t\t\tStock");
                for (int i = 0; i < 15; i++){
                    warna(0); posisi(58,9+i); printf("%i). %s",i+1,rubby_bacco[i]);
                    for (int z = 0; z < 1; z++){
                        posisi(116,9+i); printf("Rp. %i.-",buff_harga_rubby[i]);
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
                warna(0);posisi(60,7); printf("Flavour\t\t\t\t\t\t\tHarga\t\t\t\t\t\t\tStock");
                for (int i = 15, j = 0; i < idx; i++, j++){
                    warna(0); posisi(58,9+j); printf("%i). %s",i+1,rubby_bacco[i]);
                    for (int z = 0; z < 1; z++){
                        posisi(116,9+j); printf("Rp. %i.-",buff_harga_rubby[i]);
                        for (int x = 0; x < 1; x++){
                            posisi(178,9+j); printf("%i",buff_stock_rubby[i]);
                        }
                    }
                }
            }
        }
        else if (tempat2 == 3){
            int idx = 0;
            FILE* barack = fopen("barack_bacco.txt","r");
            while (fscanf(barack,type,&barack_bacco[idx], &harga_barack[idx], &pokok_barack[idx], &stock_barack[idx]) != EOF){
                buff_harga_barack[idx] = atof(harga_barack[idx]);
                buff_pokok_barack[idx] = atof(pokok_barack[idx]);
                buff_stock_barack[idx] = atoi(stock_barack[idx]);
                idx++;
            }
            fclose(barack);
            if (halaman == 1){
                bingkaii(47,3,158,41,15,8,219);
                bingkaii(50,5,152,37,0,8,35);
                warna(0); posisi(122,41); printf("< 1");
                warna(15); posisi(127,41); printf("2 >");
                warna(0); posisi(60,7); printf("Flavour\t\t\t\t\t\t\tHarga\t\t\t\t\t\t\tStock");
                for (int i = 0; i < 15; i++){
                    warna(0); posisi(58,9+i); printf("%i). %s",i+1,barack_bacco[i]);
                    for (int z = 0; z < 1; z++){
                        posisi(116,9+i); printf("Rp. %i.-",buff_harga_barack[i]);
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
                warna(0);posisi(60,7); printf("Flavour\t\t\t\t\t\t\tHarga\t\t\t\t\t\t\tStock");
                for (int i = 15, j = 0; i < idx; i++, j++){
                    warna(0); posisi(58,9+j); printf("%i). %s",i+1,barack_bacco[i]);
                    for (int z = 0; z < 1; z++){
                        posisi(116,9+j); printf("Rp. %i.-",buff_harga_barack[i]);
                        for (int x = 0; x < 1; x++){
                            posisi(178,9+j); printf("%i",buff_stock_barack[i]);
                        }
                    }
                }
            }
        }
        bingkaii(98,29,50,4,15,8,219);
        warna(0); posisi(100,31); printf("MASUKAN NOMOR BARANG : ");
        bingkaii(98,35,50,4,15,8,219);
        warna(0); posisi(100,37); printf("MASUKAN JUMLAH BARANG : ");
        vv_nomor_barang(nomor_barang1,halaman);
        buff_nomor_barang1 = atoi(nomor_barang1);
        posisi(124,37);
        vv_jumlah_barang(jumlah_barang1,halaman,buff_nomor_barang1);
        CRUD_USER(buff_nomor_barang1,buff_jumlah_barang1);
    }
}

void check_out(int buff_nomor_barang1, int buff_jumlah_barang1){
    int idx = 0, sama = 0, cord = 0;
    FILE* checkout = fopen("checkout.txt","r");
    if (tempat2 == 1){
        while (fscanf(checkout,chek,&flavour[idx],&total_cek[idx],&pcs[idx])!= EOF){
            if (strcmp(flavour[idx],sin_bacco[buff_nomor_barang1-1])==0){
                sama++;
                cord = 1;
            }
            idx++;
        }
    }
    else if (tempat2 == 2){
        while (fscanf(checkout,chek,&flavour[idx],&total_cek[idx],&pcs[idx])!= EOF){
            if (strcmp(flavour[idx],rubby_bacco[buff_nomor_barang1-1])==0){
                sama++;
                cord = 2;
            }
            idx++;
        }
    }
    else if (tempat2 == 3){
        while (fscanf(checkout,chek,&flavour[idx],&total_cek[idx],&pcs[idx])!= EOF){
            if (strcmp(flavour[idx],barack_bacco[buff_nomor_barang1-1])==0){
                sama++;
                cord = 3;
            }
            idx++;
        }
    }
    fclose(checkout);
    if (sama != 0){
        if (cord == 1){
            FILE* checkout = fopen("checkout.txt","r");
            int z = 0;
            while (fscanf(checkout,chek,&flavour[z],&total_cek[z],&pcs[z]) != EOF){
                if (buff_nomor_barang1-1 == z){
                    buff_pcs[buff_nomor_barang1-1] = atoi(pcs[buff_nomor_barang1-1]);
                    buff_pcs[buff_nomor_barang1-1] += buff_jumlah_barang1;
                    buff_total_cek[buff_nomor_barang1-1] = atoi(total_cek[buff_nomor_barang1-1]);
                    buff_total_cek[buff_nomor_barang1-1] += buff_harga_sin[buff_nomor_barang1-1] * buff_jumlah_barang1;
                    itoa(buff_pcs[buff_nomor_barang1-1],pcs[buff_nomor_barang1-1],10);
                    itoa(buff_total_cek[buff_nomor_barang1-1],total_cek[buff_nomor_barang1-1],10);
                }                
                z++;
            }
            fclose(checkout);
            checkout = fopen("checkout.txt","w");
            for (int i = 0; i < idx; i++){
                fprintf(checkout,masuk_chek,flavour[i],total_cek[i],pcs[i]);
            }
            fclose(checkout);
        }
        else if (cord == 2){
            FILE* checkout = fopen("checkout.txt","r");
            int z = 0;
            while (fscanf(checkout,chek,&flavour[z],&total_cek[z],&pcs[z]) != EOF){
                if (buff_nomor_barang1-1 == z){
                    buff_pcs[buff_nomor_barang1-1] = atoi(pcs[buff_nomor_barang1-1]);
                    buff_pcs[buff_nomor_barang1-1] += buff_jumlah_barang1;
                    buff_total_cek[buff_nomor_barang1-1] = atoi(total_cek[buff_nomor_barang1-1]);
                    buff_total_cek[buff_nomor_barang1-1] += buff_harga_rubby[buff_nomor_barang1-1] * buff_jumlah_barang1;
                    itoa(buff_pcs[buff_nomor_barang1-1],pcs[buff_nomor_barang1-1],10);
                    itoa(buff_total_cek[buff_nomor_barang1-1],total_cek[buff_nomor_barang1-1],10);
                }                
                z++;
            }
            fclose(checkout);
            checkout = fopen("checkout.txt","w");
            for (int i = 0; i < idx; i++){
                fprintf(checkout,masuk_chek,flavour[i],total_cek[i],pcs[i]);
            }
            fclose(checkout);
        }
        else if (cord == 3){
            FILE* checkout = fopen("checkout.txt","r");
            int z = 0;
            while (fscanf(checkout,chek,&flavour[z],&total_cek[z],&pcs[z]) != EOF){
                if (buff_nomor_barang1-1 == z){
                    buff_pcs[buff_nomor_barang1-1] = atoi(pcs[buff_nomor_barang1-1]);
                    buff_pcs[buff_nomor_barang1-1] += buff_jumlah_barang1;
                    buff_total_cek[buff_nomor_barang1-1] = atoi(total_cek[buff_nomor_barang1-1]);
                    buff_total_cek[buff_nomor_barang1-1] += buff_harga_barack[buff_nomor_barang1-1] * buff_jumlah_barang1;
                    itoa(buff_pcs[buff_nomor_barang1-1],pcs[buff_nomor_barang1-1],10);
                    itoa(buff_total_cek[buff_nomor_barang1-1],total_cek[buff_nomor_barang1-1],10);
                }                
                z++;
            }
            fclose(checkout);
            checkout = fopen("checkout.txt","w");
            for (int i = 0; i < idx; i++){
                fprintf(checkout,masuk_chek,flavour[i],total_cek[i],pcs[i]);
            }
            fclose(checkout);
        }
    }
    else if (sama == 0){
        checkout = fopen("checkout.txt","a");
        if (tempat2 == 1){
            total_chekout += buff_harga_sin[buff_nomor_barang1-1] * buff_jumlah_barang1;
            itoa(buff_harga_sin[buff_nomor_barang1-1],harga_sin[buff_nomor_barang1-1],10);
            fprintf(checkout,masuk_chek,sin_bacco[buff_nomor_barang1-1],harga_sin[buff_nomor_barang1-1],jumlah_barang1);
        }
        else if (tempat2 == 2){
            checkout = fopen("checkout.txt","a");
            total_chekout +=  buff_harga_rubby[buff_nomor_barang1-1] *= buff_jumlah_barang1;
            itoa(buff_harga_rubby[buff_nomor_barang1-1],harga_rubby[buff_nomor_barang1-1],10);
            fprintf(checkout,masuk_chek,rubby_bacco[buff_nomor_barang1-1],harga_rubby[buff_nomor_barang1-1],jumlah_barang1);
        }
        else if (tempat2 == 3){
            checkout = fopen("checkout.txt","a");
            total_chekout += buff_harga_barack[buff_nomor_barang1-1] *= buff_jumlah_barang1;
            itoa(buff_harga_barack[buff_nomor_barang1-1],harga_barack[buff_nomor_barang1-1],10);
            fprintf(checkout,masuk_chek,barack_bacco[buff_nomor_barang1-1],harga_barack[buff_nomor_barang1-1],jumlah_barang1);
        }
        fclose(checkout);
    }
}

void tampil_check_out(){
    bingkaii(47,3,158,41,15,8,219);
    bingkaii(50,5,152,30,0,8,35);
    bingkaii(50,37,152,5,15,8,219);
    warna(0);
    posisi(70,39); printf("> PEMBAYARAN <");
    posisi(115,39); printf("> DELETE BARANG <");
    posisi(171,39);printf("> EDIT PCS <");
    int idx = 0;
    total_chekout = 0;
    FILE* tampil_chek = fopen("checkout.txt","r");
    while (fscanf(tampil_chek,chek,&flavour[idx],&total_cek[idx],&pcs[idx]) != EOF){
        buff_total_cek[idx] = atoi(total_cek[idx]);
        total_chekout += buff_total_cek[idx];
        idx++;
    }
    fclose(tampil_chek);
    warna(0);
    posisi(62,7); printf("NAMA BARANG");
    posisi(100,7); printf("HARGA");
    posisi(119,7); printf("PCS");
    posisi(150,7); printf("TOTAL HARGA");
    posisi(152,9); printf("%i",total_chekout);
    for (int i = 0; i < idx; i++){
        warna(0); posisi(58,9+i); printf("%i.) %s",i+1,flavour[i]);
        warna(0); posisi(100,9+i); printf("%s",total_cek[i]);
        warna(0); posisi(120,9+i); printf("%s",pcs[i]);
    }
    bingkaii(70,40,13,0,0,8,219);
    bingkaii(115,40,16,0,8,8,219);
    bingkaii(171,40,11,0,8,8,219);
    char ch;
    char bayar[100];
    int garis = 1;
    while((ch = getch()) != 13 || total_chekout == 0){
        if (ch == 77){
            if (garis == 1){
                garis = 2;
                bingkaii(70,40,13,0,8,8,219);
                bingkaii(115,40,16,0,0,8,219);
            }
            else if (garis == 2){
                garis = 3;
                bingkaii(115,40,16,0,8,8,219);
                bingkaii(171,40,11,0,0,8,219);
            }
            else if (garis == 3){
                garis = 1;
                bingkaii(171,40,11,0,8,8,219);
                bingkaii(70,40,13,0,0,8,219);
            }
        }
        else if (ch == 75){
            if (garis == 3){
                garis = 2;
                bingkaii(115,40,16,0,0,8,219);
                bingkaii(171,40,11,0,8,8,219);
            }
            else if (garis == 2){
                garis = 1;
                bingkaii(70,40,13,0,0,8,219);
                bingkaii(115,40,16,0,8,8,219);
            }
            else if (garis == 1){
                garis = 3;
                bingkaii(70,40,13,0,8,8,219);
                bingkaii(171,40,11,0,0,8,219);
            }
        }
        else if (ch == 27){
            total_chekout = 0;
            select_user();
        }
    }
    if (garis == 1 && total_chekout != 0){
        pembayaran(bayar);
    }
    else if (garis == 2 && total_chekout != 0){
        hapus_checkout();
    }
    else if (garis == 3 && total_chekout != 0){
        edit_pcs();
    }
}

char* pembayaran(char* bayar){
    bingkaii(50,37,152,5,15,8,219);
    posisi(112,39); printf("MASUKAN UANG : Rp. ");
    char ch;
    int idx = 0, buff_bayar = 0;
    while ((ch = getch()) != 13 || idx < 4 ){
        if ( ((ch >= '1' && ch <= '9') && idx < 1) || ((ch >= '0' && ch <= '9') && idx > 0) && idx < 7){
            warna(0); printf("%c",ch);
            bayar[idx] = ch;
            idx++;
        }
        else if (ch == 8 && idx != 0){
            printf("\b \b");
            bayar[idx] = '\0';
            idx--;
        }
        else if (ch == 27){
            total_chekout = 0;
            tampil_check_out();
        }
    }
    bayar[idx] = '\0';
    buff_bayar = atoi(bayar);
    if (buff_bayar < total_chekout){
        warna(15);
        posisi(113,40); printf("UANG ANDA KURANG !!!");
        Sleep(300);
        posisi(113,40); printf("                    ");
        Sleep(300);
        posisi(113,40); printf("UANG ANDA KURANG !!!");
        Sleep(300);
        posisi(113,40); printf("                    ");
        pembayaran(bayar);
    }
    else if (buff_bayar > total_chekout){
        posisi(112,40); printf("KEMBALIAN UANG ANDA : %i", buff_bayar - total_chekout);
        posisi(115,41); printf("~~~ TERIMAKASIH ~~~");
    }
    else if (buff_bayar == total_chekout){
        posisi(114,40); printf("UANG ANDA PAS");
        posisi(115,41); printf("~~~ TERIMAKASIH ~~~");
    }
    int indx = 0;
    FILE* selesai = fopen("checkout.txt","r");
    while (fscanf(selesai,chek,&flavour[indx],&total_cek[indx],&pcs[indx]) != EOF){
        indx++;
    }
    fclose(selesai);
    selesai = fopen("penjualan.txt","a");
    for (int i = 0; i < indx; i++){
        fprintf(selesai,masuk_chek,flavour[i],total_cek[i],pcs[i]);
    }
    fclose(selesai);
    selesai = fopen("checkout.txt","w");
    fprintf(selesai,"");
    fclose(selesai);
    total_chekout = 0;
    Sleep(300);
    tampil_check_out();
}

void hapus_checkout(){
    bingkaii(50,37,152,5,15,8,219);
    posisi(112,39); printf("MASUKAN NOMOR : ");
    char ch, nomor[100];
    int idx = 0, buff_nomor = 0;
    while ((ch = getch()) != 13 || idx == 0){
        if ( ((ch >= '1' && ch <= '9') && idx == 0) || ((ch >= '0' && ch <= '9') && idx > 0) && idx < 3){
            printf("%c",ch);
            nomor[idx] = ch;
            idx++;
        }
        else if (ch == 8 && idx != 0){
            printf("\b \b");
            nomor[idx] = '\0';
            idx--;
        }
        else if (ch == 27){
            tampil_check_out();
        }
    }
    nomor[idx] = '\0';
    buff_nomor = atoi(nomor);
    int indx = 0, sama = 0;
    FILE* scan_cek = fopen("checkout.txt","r");
    while (fscanf(scan_cek,chek,&flavour[indx],&total_cek[indx],&pcs[indx]) != EOF){
        buff_pcs[indx] = atoi(pcs[indx]);
        if (buff_nomor-1 == indx){
            sama++;
        }
        indx++;
    }
    fclose(scan_cek);

    int cek = 0, cek1 = 0, cek2 = 0, cord = 0;
    FILE* cek_sin = fopen("sin_bacco.txt","r");
    while (fscanf(cek_sin,type,&sin_bacco[cek], &harga_sin[cek], &pokok_sin[cek], &stock_sin[cek]) != EOF){
        if (strcmp(sin_bacco[cek],flavour[buff_nomor-1]) == 0){
            cord = 1;
        }
        cek++;
    }
    fclose(cek_sin);

    FILE* cek_rubby = fopen("rubby_bacco.txt","r");
    while (fscanf(cek_rubby,type,&rubby_bacco[cek1], &harga_rubby[cek1], &pokok_rubby[cek1], &stock_rubby[cek1]) != EOF){
        if (strcmp(rubby_bacco[cek1],flavour[buff_nomor-1]) == 0){
            cord = 2;
        }
        cek1++;
    }
    fclose(cek_sin);

    FILE* cek_barack = fopen("barack_bacco.txt","r");
    while (fscanf(cek_barack,type,&barack_bacco[cek2], &harga_barack[cek2], &pokok_barack[cek2], &stock_barack[cek2]) != EOF){
        if (strcmp(barack_bacco[cek2],flavour[buff_nomor-1]) == 0){
            cord = 3;
        }
        cek2++;
    }

    if (buff_nomor-1 > indx){
        posisi(114,40); printf("NOMOR INVALID !!!");
        Sleep(300);
        hapus_checkout();
    }
    else {
        if (cord == 1){
            cek = 0;
            cek_sin = fopen("sin_bacco.txt","r");
            while (fscanf(cek_sin,type,&sin_bacco[cek], &harga_sin[cek], &pokok_sin[cek], &stock_sin[cek]) != EOF){
                if (strcmp(sin_bacco[cek],flavour[buff_nomor-1]) == 0){
                    buff_stock_sin[buff_nomor-1] = atoi(stock_sin[buff_nomor-1]);
                    buff_stock_sin[buff_nomor-1] += buff_pcs[buff_nomor-1];
                    itoa(buff_stock_sin[buff_nomor-1],stock_sin[cek],10);
                }
                cek++;
            }
            fclose(cek_sin);
            cek_sin = fopen("sin_bacco.txt","w");
            for(int i = 0; i < cek; i++){
                fprintf(cek_sin,type1,sin_bacco[i], harga_sin[i], pokok_sin[i], stock_sin[i]);
            }
            fclose(cek_sin);
            if (sama != 0){
                scan_cek = fopen("checkout.txt","w");
                for (int i = 0; i < indx; i++){
                    if (buff_nomor-1 != i){
                        fprintf(scan_cek,"%s#%s#%s\n",flavour[i],total_cek[i],pcs[i]);
                    }   
                }
                fclose(scan_cek);
            }
        }
        else if (cord == 2){
            cek1 = 0;
            cek_rubby = fopen("rubby_bacco.txt","r");
            while (fscanf(cek_rubby,type,&rubby_bacco[cek1], &harga_rubby[cek1], &pokok_rubby[cek1], &stock_rubby[cek1]) != EOF){
                if (strcmp(rubby_bacco[cek1],flavour[buff_nomor-1]) == 0){
                    buff_stock_rubby[buff_nomor-1] = atoi(stock_rubby[buff_nomor-1]);
                    buff_stock_rubby[buff_nomor-1] += buff_pcs[buff_nomor-1];
                    itoa(buff_stock_rubby[buff_nomor-1],stock_rubby[cek1],10);
                }
                cek1++;
            }
            fclose(cek_rubby);
            cek_rubby = fopen("rubby_bacco.txt","w");
            for(int i = 0; i < cek1; i++){
                fprintf(cek_rubby,type1,rubby_bacco[i], harga_rubby[i], pokok_rubby[i], stock_rubby[i]);
            }
            fclose(cek_rubby);
            if (sama != 0){
                scan_cek = fopen("checkout.txt","w");
                for (int i = 0; i < indx; i++){
                    if (buff_nomor-1 != i){
                        fprintf(scan_cek,"%s#%s#%s\n",flavour[i],total_cek[i],pcs[i]);
                    }   
                }
                fclose(scan_cek);
            }
        }
        else if (cord == 3){
            cek2 = 0;
            cek_barack = fopen("barack_bacco.txt","r");
            while (fscanf(cek_barack,type,&barack_bacco[cek2], &harga_barack[cek2], &pokok_barack[cek2], &stock_barack[cek2]) != EOF){
                if (strcmp(barack_bacco[cek2],flavour[buff_nomor-1]) == 0){
                    buff_stock_barack[buff_nomor-1] = atoi(stock_barack[buff_nomor-1]);
                    buff_stock_barack[buff_nomor-1] += buff_pcs[buff_nomor-1];
                    itoa(buff_stock_barack[buff_nomor-1],stock_barack[cek2],10);
                }
                cek2++;
            }
            fclose(cek_barack);
            cek_barack = fopen("barack_bacco.txt","w");
            for(int i = 0; i < cek2; i++){
                fprintf(cek_barack,type1,barack_bacco[i], harga_barack[i], pokok_barack[i], stock_barack[i]);
            }
            fclose(cek_barack);
            if (sama != 0){
                scan_cek = fopen("checkout.txt","w");
                for (int i = 0; i < indx; i++){
                    if (buff_nomor-1 != i){
                        fprintf(scan_cek,"%s#%s#%s\n",flavour[i],total_cek[i],pcs[i]);
                    }   
                }
                fclose(scan_cek);
            }
        }
    }
    tampil_check_out();
}

void edit_pcs(){
    char nomor[100];
    char jum_pcs[100];
    int buff_nomor = 0, buff_jum_pcs = 0;
    bingkaii(50,37,152,5,15,8,219);
    posisi(80,39); printf("MASUKAN NOMOR : ");
    posisi(128,39); printf("KURANGI PCS : ");
    posisi(96,39); v_nomor(nomor);
    buff_nomor = atoi(nomor);
    posisi(143,39); v_pcs(jum_pcs,buff_nomor);
    buff_jum_pcs = atoi(jum_pcs);
    CRUD_PCS(buff_nomor,buff_jum_pcs);
}

char* v_nomor(char* nomor){
    char ch;
    int idx = 0, buff_nomor = 0;
    while ((ch = getch()) != 13 || idx == 0){
        if ( ((ch >= '1' && ch <= '9') && idx == 0) || ((ch >= '0' && ch <= '9') && idx > 0) && idx < 3){
            warna(0); printf("%c",ch);
            nomor[idx] = ch;
            idx++;
        }
        else if (ch == 8 && idx != 0){
            printf("\b \b");
            nomor[idx] = '\0';
            idx--;
        }
        else if (ch == 27){
            tampil_check_out();
        }
    }
    nomor[idx] = '\0';
    buff_nomor = atoi(nomor);
    int indx = 0;
    FILE* scan_cek = fopen("checkout.txt","r");
    while (fscanf(scan_cek,chek,&flavour[indx],&total_cek[indx],&pcs[indx]) != EOF){
        indx++;
    }
    fclose(scan_cek);
    if (buff_nomor-1 > indx-1){
        warna(15); posisi(96,39); printf("NOMOR INVALID !!");
        Sleep(300);
        posisi(96,39); printf("                ");
        Sleep(300);
        posisi(96,39); printf("NOMOR INVALID !!");
        Sleep(300);
        posisi(96,39); printf("                ");
        posisi(96,39); v_nomor(nomor);
    }
    return nomor;
}

char* v_pcs(char* jum_pcs, int buff_nomor){
    char ch;
    int idx = 0, buff_jum_pcs = 0;
    while ((ch = getch()) != 13 || idx == 0){
        if ( ((ch >= '1' && ch <= '9') && idx == 0) || ((ch >= '0' && ch <= '9') && idx > 0) && idx < 3){
            warna(0); printf("%c",ch);
            jum_pcs[idx] = ch;
            idx++;
        }
        else if (ch == 8 && idx != 0){
            printf("\b \b");
            jum_pcs[idx] = '\0';
            idx--;
        }
        else if (ch == 27){
            tampil_check_out();
        }
    }
    jum_pcs[idx] = '\0';
    buff_jum_pcs = atoi(jum_pcs);
    int indx = 0;
    FILE* scan_cek = fopen("checkout.txt","r");
    while (fscanf(scan_cek,chek,&flavour[indx],&total_cek[indx],&pcs[indx]) != EOF){
        buff_pcs[indx] = atoi(pcs[indx]);
        indx++;
    }
    fclose(scan_cek);
    if (buff_jum_pcs > buff_pcs[buff_nomor-1]){
        warna(15);
        posisi(143,39); printf("PCS INVALID !!!");
        Sleep(300);
        posisi(143,39); printf("               ");
        Sleep(300);
        posisi(143,39); printf("PCS INVALID !!!");
        Sleep(300);
        posisi(143,39); printf("               ");
        posisi(143,39); v_pcs(jum_pcs,buff_nomor);
    }
    return jum_pcs;
}

void CRUD_PCS(int buff_nomor, int buff_jum_pcs){
    int indx = 0, sama = 0;
    int cek = 0, cek1 = 0, cek2 = 0, cord = 1;
    FILE* scan_cek = fopen("checkout.txt","r");
    while (fscanf(scan_cek,chek,&flavour[indx],&total_cek[indx],&pcs[indx]) != EOF){
        buff_pcs[indx] = atoi(pcs[indx]);
        buff_total_cek[indx] = atoi(total_cek[indx]);
        if (buff_nomor-1 == indx){
            sama++;
        }
        indx++;
    }
    fclose(scan_cek);
    
    FILE* cek_sin = fopen("sin_bacco.txt","r");
    while (fscanf(cek_sin,type,&sin_bacco[cek], &harga_sin[cek], &pokok_sin[cek], &stock_sin[cek]) != EOF){
        if (strcmp(sin_bacco[cek],flavour[buff_nomor-1]) == 0){
            cord = 1;
        }
        cek++;
    }
    fclose(cek_sin);
    FILE* cek_rubby = fopen("rubby_bacco.txt","r");
    while (fscanf(cek_rubby,type,&rubby_bacco[cek1], &harga_rubby[cek1], &pokok_rubby[cek1], &stock_rubby[cek1]) != EOF){
        if (strcmp(rubby_bacco[cek1],flavour[buff_nomor-1]) == 0){
            cord = 2;
        }
        cek1++;
    }
    fclose(cek_sin);
    FILE* cek_barack = fopen("barack_bacco.txt","r");
    while (fscanf(cek_barack,type,&barack_bacco[cek2], &harga_barack[cek2], &pokok_barack[cek2], &stock_barack[cek2]) != EOF){
        if (strcmp(barack_bacco[cek2],flavour[buff_nomor-1]) == 0){
            cord = 3;
        }
        cek2++;
    }

    if (sama != 0){
        if (cord == 1){
            cek = 0;
            cek_sin = fopen("sin_bacco.txt","r");
            while (fscanf(cek_sin,type,&sin_bacco[cek], &harga_sin[cek], &pokok_sin[cek], &stock_sin[cek]) != EOF){
                if (strcmp(sin_bacco[cek],flavour[buff_nomor-1]) == 0){
                    buff_stock_sin[buff_nomor-1] = atoi(stock_sin[buff_nomor-1]);
                    buff_harga_sin[buff_nomor-1] = atoi(harga_sin[buff_nomor-1]);
                    buff_stock_sin[buff_nomor-1] += buff_jum_pcs;
                    itoa(buff_stock_sin[buff_nomor-1],stock_sin[cek],10);
                }
                cek++;
            }
            fclose(cek_sin);
            cek_sin = fopen("sin_bacco.txt","w");
            for(int i = 0; i < cek; i++){
                fprintf(cek_sin,type1,sin_bacco[i], harga_sin[i], pokok_sin[i], stock_sin[i]);
            }
            fclose(cek_sin);

            scan_cek = fopen("checkout.txt","r");
            int z = 0;
            while (fscanf(scan_cek,chek,&flavour[z],&total_cek[z],&pcs[z]) != EOF){
                if (buff_nomor-1 == z){
                    buff_pcs[buff_nomor-1] = atoi(pcs[buff_nomor-1]);
                    buff_pcs[buff_nomor-1] -= buff_jum_pcs;
                    buff_total_cek[buff_nomor-1] = atoi(total_cek[buff_nomor-1]);
                    buff_total_cek[buff_nomor-1] -= buff_harga_sin[buff_nomor-1] * buff_jum_pcs;
                    itoa(buff_pcs[buff_nomor-1],pcs[buff_nomor-1],10);
                    itoa(buff_total_cek[buff_nomor-1],total_cek[buff_nomor-1],10);
                }                
                z++;
            }
            fclose(scan_cek);
            scan_cek = fopen("checkout.txt","w");
            for (int i = 0; i < z; i++){
                if (buff_pcs[buff_nomor-1] == 0){
                    scan_cek = fopen("checkout.txt","w");
                    for (int j = 0; j < z; j++){
                        if (buff_nomor-1 != j){
                            fprintf(scan_cek,"%s#%s#%s\n",flavour[j],total_cek[j],pcs[j]);
                        }   
                    }
                    fclose(scan_cek);
                }
                fprintf(scan_cek,"%s#%s#%s\n",flavour[i],total_cek[i],pcs[i]);
            }
            fclose(scan_cek);
        }
        if (cord == 2){
            cek1 = 0;
            cek_rubby = fopen("rubby_bacco.txt","r");
            while (fscanf(cek_rubby,type,&rubby_bacco[cek1], &harga_rubby[cek1], &pokok_rubby[cek1], &stock_rubby[cek1]) != EOF){
                if (strcmp(rubby_bacco[cek1],flavour[buff_nomor-1]) == 0){
                    buff_stock_rubby[buff_nomor-1] = atoi(stock_rubby[buff_nomor-1]);
                    buff_harga_rubby[buff_nomor-1] = atoi(harga_rubby[buff_nomor-1]);
                    buff_stock_rubby[buff_nomor-1] += buff_jum_pcs;
                    itoa(buff_stock_rubby[buff_nomor-1],stock_rubby[cek1],10);
                }
                cek1++;
            }
            fclose(cek_rubby);
            cek_rubby = fopen("rubby_bacco.txt","w");
            for(int i = 0; i < cek1; i++){
                fprintf(cek_rubby,type1,rubby_bacco[i], harga_rubby[i], pokok_rubby[i], stock_rubby[i]);
            }
            fclose(cek_rubby);

            scan_cek = fopen("checkout.txt","r");
            int z = 0;
            while (fscanf(scan_cek,chek,&flavour[z],&total_cek[z],&pcs[z]) != EOF){
                if (buff_nomor-1 == z){
                    buff_pcs[buff_nomor-1] = atoi(pcs[buff_nomor-1]);
                    buff_pcs[buff_nomor-1] -= buff_jum_pcs;
                    buff_total_cek[buff_nomor-1] = atoi(total_cek[buff_nomor-1]);
                    buff_total_cek[buff_nomor-1] -= buff_harga_rubby[buff_nomor-1] * buff_jum_pcs;
                    itoa(buff_pcs[buff_nomor-1],pcs[buff_nomor-1],10);
                    itoa(buff_total_cek[buff_nomor-1],total_cek[buff_nomor-1],10);
                }                
                z++;
            }
            fclose(scan_cek);
            scan_cek = fopen("checkout.txt","w");
            for (int i = 0; i < z; i++){
                if (buff_pcs[buff_nomor-1] == 0){
                    scan_cek = fopen("checkout.txt","w");
                    for (int j = 0; j < z; j++){
                        if (buff_nomor-1 != j){
                            fprintf(scan_cek,"%s#%s#%s\n",flavour[j],total_cek[j],pcs[j]);
                        }   
                    }
                    fclose(scan_cek);
                }
                fprintf(scan_cek,"%s#%s#%s\n",flavour[i],total_cek[i],pcs[i]);
            }
            fclose(scan_cek);
        }
        if (cord == 3){
            cek2 = 0;
            cek_barack = fopen("barack_bacco.txt","r");
            while (fscanf(cek_barack,type,&barack_bacco[cek2], &harga_barack[cek2], &pokok_barack[cek2], &stock_barack[cek2]) != EOF){
                if (strcmp(barack_bacco[cek2],flavour[buff_nomor-1]) == 0){
                    buff_stock_barack[buff_nomor-1] = atoi(stock_barack[buff_nomor-1]);
                    buff_harga_barack[buff_nomor-1] = atoi(harga_barack[buff_nomor-1]);
                    buff_stock_barack[buff_nomor-1] += buff_jum_pcs;
                    itoa(buff_stock_barack[buff_nomor-1],stock_barack[cek2],10);
                }
                cek2++;
            }
            fclose(cek_barack);
            cek_barack = fopen("barack_bacco.txt","w");
            for(int i = 0; i < cek2; i++){
                fprintf(cek_barack,type1,barack_bacco[i], harga_barack[i], pokok_barack[i], stock_barack[i]);
            }
            fclose(cek_barack);
            scan_cek = fopen("checkout.txt","r");
            int z = 0;
            while (fscanf(scan_cek,chek,&flavour[z],&total_cek[z],&pcs[z]) != EOF){
                if (buff_nomor-1 == z){
                    buff_pcs[buff_nomor-1] = atoi(pcs[buff_nomor-1]);
                    buff_pcs[buff_nomor-1] -= buff_jum_pcs;
                    buff_total_cek[buff_nomor-1] = atoi(total_cek[buff_nomor-1]);
                    buff_total_cek[buff_nomor-1] -= buff_harga_barack[buff_nomor-1] * buff_jum_pcs;
                    itoa(buff_pcs[buff_nomor-1],pcs[buff_nomor-1],10);
                    itoa(buff_total_cek[buff_nomor-1],total_cek[buff_nomor-1],10);
                }                
                z++;
            }
            fclose(scan_cek);
            scan_cek = fopen("checkout.txt","w");
            for (int i = 0; i < z; i++){
                if (buff_pcs[buff_nomor-1] == 0){
                    scan_cek = fopen("checkout.txt","w");
                    for (int j = 0; j < z; j++){
                        if (buff_nomor-1 != j){
                            fprintf(scan_cek,"%s#%s#%s\n",flavour[j],total_cek[j],pcs[j]);
                        }   
                    }
                    fclose(scan_cek);
                }
                fprintf(scan_cek,"%s#%s#%s\n",flavour[i],total_cek[i],pcs[i]);
            }
            fclose(scan_cek);
        }
    }
    tampil_check_out();
}

void balik_hapus_checkout(){
    int idx = 0, idx1 = 0, idx2 = 0, sama1[100], sama2[100],sama3[100],a = 0;
    int ketemu1 = 0, ketemu2 = 0, ketemu3 = 0 ;
    FILE* cekk = fopen("checkout.txt","r");
    while (fscanf(cekk,chek,&flavour[idx],&total_cek[idx],&pcs[idx]) != EOF){    
        if (strcmp(flavour[idx],barack_bacco[idx]) == 0){
            buff_pcs2[idx] = atoi(pcs[idx]);
            sama3[idx] = idx;
            ketemu3 = 3;
            a++;
        }
        idx++;
    }
    fclose(cekk);
    cekk = fopen("checkout.txt","r");
    while (fscanf(cekk,chek,&flavour[idx1],&total_cek[idx1],&pcs[idx1]) != EOF){    
        if (strcmp(flavour[idx1],rubby_bacco[idx1]) == 0){
            buff_pcs1[idx1] = atoi(pcs[idx1]);
            sama2[idx1] = idx1;
            ketemu2 = 2;
            a++;
        }
        idx1++;
    }
    fclose(cekk);

    cekk = fopen("checkout.txt","r");
    while (fscanf(cekk,chek,&flavour[idx2],&total_cek[idx2],&pcs[idx2]) != EOF){    
        if (strcmp(flavour[idx2],sin_bacco[idx2]) == 0){
            buff_pcs[idx2] = atoi(pcs[idx2]);
            sama1[idx2] = idx2;
            ketemu1 = 1;
            a++;
        }
        idx2++;
    }
    fclose(cekk);
    if (a != 0){
            int indx = 0;
            FILE* barack = fopen("barack_bacco.txt","r");
            while (fscanf(barack,type,&barack_bacco[indx], &harga_barack[indx], &pokok_barack[indx], &stock_barack[indx]) != EOF){
                if (sama3[indx] == indx){
                    buff_stock_barack[sama3[indx]] = atoi(stock_barack[sama3[indx]]);
                    buff_stock_barack[sama3[indx]] += buff_pcs2[sama3[indx]];
                    itoa(buff_stock_barack[sama3[indx]],stock_barack[sama3[indx]],10);
                }
                indx++;        
            }
            fclose(barack);
            barack = fopen("barack_bacco.txt","w");
            for(int i = 0; i < indx; i++){
                fprintf(barack,type1,barack_bacco[i], harga_barack[i], pokok_barack[i], stock_barack[i]);
            }
            fclose(barack);
            indx = 0;
            FILE* rubby = fopen("rubby_bacco.txt","r");
            while (fscanf(rubby,type,&rubby_bacco[indx], &harga_rubby[indx], &pokok_rubby[indx], &stock_rubby[indx]) != EOF){
                if (sama2[indx] == indx){
                    buff_stock_rubby[sama2[indx]] = atoi(stock_rubby[sama2[indx]]);
                    buff_stock_rubby[sama2[indx]] += buff_pcs1[sama2[indx]];
                    itoa(buff_stock_rubby[sama2[indx]],stock_rubby[sama2[indx]],10);
                }
                indx++;        
            }
            fclose(rubby);
            rubby = fopen("rubby_bacco.txt","w");
            for(int i = 0; i < indx; i++){
                fprintf(rubby,type1,rubby_bacco[i], harga_rubby[i], pokok_rubby[i], stock_rubby[i]);
            }
            fclose(rubby);
            indx = 0;
            FILE* sin = fopen("sin_bacco.txt","r");
            while (fscanf(sin,type,&sin_bacco[indx], &harga_sin[indx], &pokok_sin[indx], &stock_sin[indx]) != EOF){
                if (sama1[indx] == indx){
                    buff_stock_sin[sama1[indx]] = atoi(stock_sin[sama1[indx]]);
                    buff_stock_sin[sama1[indx]] += buff_pcs[sama1[indx]];
                    itoa(buff_stock_sin[sama1[indx]],stock_sin[sama1[indx]],10);
                }
                indx++;        
            }
            fclose(sin);
            sin = fopen("sin_bacco.txt","w");
            for(int i = 0; i < indx; i++){
                fprintf(sin,type1,sin_bacco[i], harga_sin[i], pokok_sin[i], stock_sin[i]);
            }
            fclose(sin);
    }
    cekk = fopen("checkout.txt","w");
    fprintf(cekk,"");
    fclose(cekk);
}