char user[100] = "Roxilius17", pass[100] = "Lolzec17";
char buff_username[100][100], buff_password[100][100], buff_nama[100][100], buff_alamat[100][100], buff_umur[100][100];
void v_id_pw(), admin(), bingkai_admin(), select_admin(), select_user(),PILIH_BARANG(), SINN(), MENU(int halaman), RUBBY(), BARACK();
void bingkai_user(), MENU_USER(), login();
int tempat_user = 1, tempat2 = 1;

const char *tamp_data_user = "%[^#]#%[^#]#%[^#]#%[^#]#%[^\n]\n";
const char *type = "%[^#]#%[^#]#%[^#]#%[^\n]\n";

int buff_harga_sin[100], buff_harga_barack[100], buff_harga_rubby[100];
int buff_pokok_sin[100], buff_pokok_barack[100], buff_pokok_rubby[100];
int buff_stock_sin[100], buff_stock_barack[100], buff_stock_rubby[100];
char sin_bacco[100][100], barack_bacco[100][100], rubby_bacco[100][100];
char harga_sin[100][100], harga_barack[100][100], harga_rubby[100][100];
char pokok_sin[100][100], pokok_barack[100][100], pokok_rubby[100][100];
char stock_sin[100][100], stock_barack[100][100], stock_rubby[100][100];

int buff_nomor_barang1 = 0, buff_jumlah_barang1 = 0;

char* v_nama(char* nama){
    char ch;
    int idx = 0;
    while((ch = getch()) != 13 || idx < 6 || nama[idx-1] == ' '){
        if(( (islower(ch) && idx > 0 && nama[idx - 1] != ' ') || (isupper(ch) && (idx == 0 || nama[idx-1] == ' ')) || (nama[idx - 1] != ' ' && ch == ' ' && idx != 0 && (islower(nama[idx -1])) )) && idx < 25){
            printf("%c",ch);
            nama[idx] = ch;
            idx++;
        }
        if(ch == 8 && idx != 0){
            printf("\b \b");
            nama[idx] = '\0';
            idx--;
        }
        if(ch == 27){
            bingkai_user();
        }
    }            
    nama[idx] = '\0';
    return nama;
}

char* v_alamat(char* alamat){
    char ch;
    int index = 0,karakter = 0;
    while((ch = getch()) != 13 || index < 10 || alamat[index - 1] == ' '){
        if(index < 100 && karakter < 10 && (ch != 8 && ch != 13 && ch != 9 && index != 0 || ch == ' ' && index != 0 && alamat[index-1] != ' ' || ch >= 'A' && ch <= 'Z' && index == 0)){
            printf("%c",ch);
            alamat[index] = ch;
            index++;
            if(!(ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9')){
                karakter++;
            }
        }
        else if(ch == 8 && index != 0){
            printf("\b \b");
            index--;
            if(!(alamat[index] >= 'A' && alamat[index] <= 'Z' || alamat[index] >= 'a' && alamat[index] <= 'z' || alamat[index] >= '0' && alamat[index] <= '9')){
                karakter--;
            }
            alamat[index]= '\0';
        }
        else if (ch == 27){
            bingkai_user();
        }
    }
    alamat[index]= '\0';
    return alamat;
}

char* v_umur( char* umur){
    char ch;
    int idx = 0;
    while((ch = getch()) != 13 || idx < 1){
        if( (ch >= '1' && ch <= '9' && idx == 0) || (ch >= '0' && ch <= '9' && idx != 0) && idx < 2){
            printf("%c",ch);
            umur[idx] = ch;
            idx++;
        }
        else if(ch == 8 && idx != 0){
            printf("\b \b");
            umur[idx] = '\0';
            idx--;
        }
        else if (ch == 27){
            bingkai_user();
        }
    }
    umur[idx] = '\0';
    int cek_umur = atoi(umur);
    if (cek_umur <= 17 ){
        warna(15);
        posisi(34,25); printf("  ");
        posisi(60,36); printf("UMUR MASIH DI BAWAH 18 tahun !!!");
        Sleep(300);
        posisi(60,36); printf("                                ");
        Sleep(300);
        posisi(60,36); printf("UMUR MASIH DI BAWAH 18 tahun !!!");
        Sleep(300);
        posisi(60,36); printf("                                ");
        posisi(34,25); v_umur(umur);
    }
    return umur;
}

char* cekjalan(char* alamat){
    int idx=0;
    int space=0;
    char ch;
    while((ch=getch())!= 13 || idx < 4 || alamat[idx-1]==' '){
        if(ch >= 'a' && ch <= 'z' && idx != 0 && (ch != alamat[idx-1]|| ch != alamat[idx-2]) && idx < 19 ||
        ch >= 'A' && ch <= 'Z' && (idx == 0 || alamat[idx-1] == ' ') && idx < 19 ||
        ch == ' ' && idx != 0 && ch != alamat[idx-1] && space < 1
        ){
            printf("%c", ch);
            alamat[idx]=ch;
            idx++;
            if(ch == ' '){
                space++;
            }
        }else if(ch == 8 && idx != 0){
            if(alamat[idx-1] == ' '){
                space--;
            }
            printf("\b \b");
            idx--;
            alamat[idx]='\0';
        }
        else if (ch == 27){
            bingkai_user();
        }
    }
    alamat[idx]='\0';
    return alamat;
}

char* v_username_login(char* username){
    char ch;
    int idx = 0;
    while (((ch = getch()) != 13 || ch == ' ' || idx == 0)){
        if (ch == 27){
            bingkai_user();
        }
        else if ( ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) && idx < 20){
            warna(15); printf("%c",ch);
            username[idx] = ch;
            idx++;
        }
        else if (ch == 8 && idx != 0){ 
            printf("\b \b");
            username[idx] = '\0';
            idx--;
        }
    }
    username[idx] = '\0';
}

char* v_username(char* username){
    char ch;
    int idx = 0;
    while (((ch = getch()) != 13 || ch == ' ' || idx == 0)){
        if (ch == 27){
            bingkai_user();
        }
        else if ( ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) && idx < 20){
            warna(15); printf("%c",ch);
            username[idx] = ch;
            idx++;
        }
        else if (ch == 8 && idx != 0){ 
            printf("\b \b");
            username[idx] = '\0';
            idx--;
        }
    }
    username[idx] = '\0';
    int cek = 0, sama =0;
    FILE* data_user = fopen("data_user.txt","r");
    while (fscanf(data_user,"%[^#]#%[^#]#%[^#]#%[^#]#%[^\n]\n",&buff_username[cek],&buff_password[cek],&buff_nama[cek],&buff_alamat[cek],&buff_umur[cek]) != EOF){
        if (strcmp(username,buff_username[cek]) == 0){
            sama++;
        }
        cek++;
    }
    fclose(data_user);
    if (sama != 0){
        warna(15);
        posisi(34,31); printf("                            ");
        posisi(60,36); printf("USERNAME USDAH TERDAFTAR !!!");
        Sleep(300);
        posisi(60,36); printf("                            ");
        Sleep(200);
        posisi(60,36); printf("USERNAME USDAH TERDAFTAR !!!");
        Sleep(300);
        posisi(60,36); printf("                            ");
        posisi(34,31); v_username(username);
    }
    return username;
}

char* v_password(char* password){
    char ch;
    int idx = 0, ulang = 0;
    while ((ch = getch()) != 13 || ch == ' ' || idx == 0){
        if (ch == 27){
            bingkai_user();
        }
        else if ( ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) && idx < 20){
            warna(15); printf("*");
            password[idx] = ch;
            idx++;
        }
        else if (ch == 8 && idx != 0){ 
            printf("\b \b");
            password[idx] = '\0';
            idx--;
        }
    }
    password[idx] = '\0';
    return password;
}

char* vv_nomor_barang(char* nomor_barang1, int halaman){
    int idx = 0;
    char ch;
    posisi(123,31);
    while ((ch = getch()) != 13 || idx == 0 || (idx <= 1 && halaman == 2)){
        if ((((ch >= '1' && ch <= '9' && idx == 0 && halaman == 1)) || ((ch >= '1' && ch <= '5' && idx ==1 && nomor_barang1[0] == '1' && idx == 1 && halaman == 1))) && idx < 2){
            printf("%c",ch);
            nomor_barang1[idx] = ch;
            idx++;
        }
        else if (( ((ch >= '1' && ch <= '3' && idx == 0 && halaman == 2)) || ((ch >= '6' && ch <= '9' && idx ==1 && nomor_barang1[0] == '1' && idx == 1 && halaman == 2)) || ((ch >= '0' && ch <= '9' && idx ==1 && nomor_barang1[0] == '2' && idx == 1 && halaman == 2)) || ((ch >= '0' && ch <= '3' && idx ==1 && nomor_barang1[0] == '3' && idx == 1 && halaman == 2))) && idx < 2){
            printf("%c",ch);
            nomor_barang1[idx] = ch;
            idx++;
        }  
        else if (ch == 8 && idx != 0){
            printf("\b \b");
            nomor_barang1[idx] = '\0';
            idx--;
        }
        else if (ch == 75){
            halaman = 1;
            MENU_USER(halaman);
        }
        else if (ch == 77){
            halaman = 2;
            MENU_USER(halaman);
        }
        else if (ch == 27){
            select_user();
        } 
    }
    nomor_barang1[idx] = '\0';
    return nomor_barang1;
}

char* v_nomor_barang(char* nomor_barang, int halaman){
    int idx = 0;
    char ch;
    posisi(123,31);
    while ((ch = getch()) != 13 || idx == 0 || (idx <= 1 && halaman == 2)){
        if ((((ch >= '1' && ch <= '9' && idx == 0 && halaman == 1)) || ((ch >= '1' && ch <= '5' && idx ==1 && nomor_barang[0] == '1' && idx == 1 && halaman == 1))) && idx < 2){
            printf("%c",ch);
            nomor_barang[idx] = ch;
            idx++;
        }
        else if (( ((ch >= '1' && ch <= '3' && idx == 0 && halaman == 2)) || ((ch >= '6' && ch <= '9' && idx ==1 && nomor_barang[0] == '1' && idx == 1 && halaman == 2)) || ((ch >= '0' && ch <= '9' && idx ==1 && nomor_barang[0] == '2' && idx == 1 && halaman == 2)) || ((ch >= '0' && ch <= '3' && idx ==1 && nomor_barang[0] == '3' && idx == 1 && halaman == 2))) && idx < 2){
            printf("%c",ch);
            nomor_barang[idx] = ch;
            idx++;
        }  
        else if (ch == 8 && idx != 0){
            printf("\b \b");
            nomor_barang[idx] = '\0';
            idx--;
        }
        else if (ch == 75){
            halaman = 1;
            MENU(halaman);
        }
        else if (ch == 77){
            halaman = 2;
            MENU(halaman);
        }
        else if (ch == 27){
            select_admin();
        } 
    }
    nomor_barang[idx] = '\0';
    return nomor_barang;
}

char* v_jumlah_barang(char* jumlah_barang, int halaman, int tempat){
    int idx = 0;
    char ch;
    while ((ch = getch()) != 13 || idx == 0){
        if ( ((ch >= '1' && ch <= '9') && idx == 0) || ((ch >= '0' && ch <= '9') && idx >= 1) && (halaman == 2 || halaman == 1) && idx < 2 ){
            printf("%c",ch);
            jumlah_barang[idx] = ch;
            idx++;
        }
        else if (ch == 8 && idx != 0){
            printf("\b \b");
            jumlah_barang[idx] = '\0';
            idx--;
        }
        else if (ch == 75){
            if(tempat == 2 || tempat == 4){
                halaman = 1;
                MENU(halaman);
            }
        }
        else if (ch == 77){
            if(tempat == 2 || tempat == 4){
                halaman = 1;
                MENU(halaman);
            }
        }
        else if (ch == 27){
            select_admin();
        }
    }
    jumlah_barang[idx] = '\0';
    return jumlah_barang;
}

char* vv_jumlah_barang(char* jumlah_barang1, int halaman, int buff_nomor_barang1){
    int idx = 0;
    char ch;
    warna(0);
    while ((ch = getch()) != 13 || idx == 0){
        if ( ((ch >= '1' && ch <= '9') && idx == 0) || ((ch >= '0' && ch <= '9') && idx >= 1) && (halaman == 2 || halaman == 1) && idx < 2 ){
            printf("%c",ch);
            jumlah_barang1[idx] = ch;
            idx++;
        }
        else if (ch == 8 && idx != 0){
            printf("\b \b");
            jumlah_barang1[idx] = '\0';
            idx--;
        }
        else if (ch == 75){
            halaman = 1;
            MENU_USER(halaman);
        }
        else if (ch == 77){
            halaman = 1;
            MENU_USER(halaman);
        }
        else if (ch == 27){
            select_user();
        }
    }
    jumlah_barang1[idx] = '\0';
    buff_jumlah_barang1 = atoi(jumlah_barang1);
    int indx = 0;
    if (tempat2 == 1){
        FILE* sin = fopen("sin_bacco.txt","r");
        while (fscanf(sin,type,&sin_bacco[indx], &harga_sin[indx], &pokok_sin[indx], &stock_sin[indx]) != EOF){
            buff_harga_sin[indx] = atof(harga_sin[indx]);
            buff_pokok_sin[indx] = atof(pokok_sin[indx]);
            buff_stock_sin[indx] = atoi(stock_sin[indx]);
            indx++;
        }
        fclose(sin);
        if (buff_stock_sin[buff_nomor_barang1-1] < buff_jumlah_barang1){
            warna(15);
            posisi(124,37); printf("              ");
            posisi(100,28); printf("STOCK TIDAK CUKUP !!!");
            Sleep(300);
            posisi(100,28); printf("                     ");
            Sleep(300);
            posisi(100,28); printf("STOCK TIDAK CUKUP !!!");
            Sleep(300);
            posisi(100,28); printf("                     ");
            posisi(124,37); vv_jumlah_barang(jumlah_barang1,halaman,buff_nomor_barang1);
        }
    }
    else if (tempat2 == 2){
        FILE* rubby = fopen("rubby_bacco.txt","r");
        while (fscanf(rubby,type,&rubby_bacco[indx], &harga_rubby[indx], &pokok_rubby[indx], &stock_rubby[indx]) != EOF){
            buff_harga_rubby[indx] = atof(harga_rubby[indx]);
            buff_pokok_rubby[indx] = atof(pokok_rubby[indx]);
            buff_stock_rubby[indx] = atoi(stock_rubby[indx]);
            indx++;
        }
        fclose(rubby);
        if (buff_stock_rubby[buff_nomor_barang1-1] < buff_jumlah_barang1){
            warna(15);
            posisi(124,37); printf("              ");
            posisi(115,28); printf("STOCK TIDAK CUKUP !!!");
            Sleep(300);
            posisi(115,28); printf("                     ");
            Sleep(300);
            posisi(115,28); printf("STOCK TIDAK CUKUP !!!");
            Sleep(300);
            posisi(115,28); printf("                     ");
            posisi(124,37); vv_jumlah_barang(jumlah_barang1,halaman,buff_nomor_barang1);
        }
    }
    else if (tempat2 == 3){
        FILE* barack = fopen("barack_bacco.txt","r");
        while (fscanf(barack,type,&barack_bacco[indx], &harga_barack[indx], &pokok_barack[indx], &stock_barack[indx]) != EOF){
            buff_harga_barack[indx] = atof(harga_barack[indx]);
            buff_pokok_barack[indx] = atof(pokok_barack[indx]);
            buff_stock_barack[indx] = atoi(stock_barack[indx]);
            indx++;
        }
        fclose(barack);
        if (buff_stock_barack[buff_nomor_barang1-1] < buff_jumlah_barang1){
            warna(15);
            posisi(124,37); printf("              ");
            posisi(115,28); printf("STOCK TIDAK CUKUP !!!");
            Sleep(300);
            posisi(115,28); printf("                     ");
            Sleep(300);
            posisi(115,28); printf("STOCK TIDAK CUKUP !!!");
            Sleep(300);
            posisi(115,28); printf("                     ");
            posisi(124,37); vv_jumlah_barang(jumlah_barang1,halaman,buff_nomor_barang1);
        }
    }
    itoa(buff_jumlah_barang1,jumlah_barang1,10); 
    return jumlah_barang1;
}


char* v_nama_barang(char* nama_barang, int tempat1){
    char ch;
    int ulang = 0;
    do{
        posisi(76,25);
        ulang = 0;
        int idx = 0 ;
        while((ch = getch()) != 13 || idx == 0 || (tempat1 == 1 && idx < 7) || (tempat1 == 2 && idx < 9) || (tempat1 == 3 && idx < 10) || nama_barang[idx-1] == ' '){
            warna(0);
            if(( (islower(ch) && idx > 0 && nama_barang[idx - 1] != ' ') || (isupper(ch) && (idx == 0 || nama_barang[idx-1] == ' ')) || (nama_barang[idx - 1] != ' ' && ch == ' ' && idx != 0 && (islower(nama_barang[idx -1])) )) && idx < 30){
                printf("%c",ch);
                nama_barang[idx] = ch;
                idx++;
            }
            else if(ch == 8 && idx != 0){
                printf("\b \b");
                nama_barang[idx] = '\0';
                idx--;
            }
            else if(ch == 27){
                select_admin();
            }
        }
        nama_barang[idx] = '\0';
        for (int i = 0; i < strlen(nama_barang); i++){
            if (tempat1 == 1){
                if (nama_barang[0] != 'S' || nama_barang[1] != 'i' || nama_barang[2] != 'n'){
                    ulang = 1;
                }
                else{
                    ulang = 0;
                    break;
                }
            }
            else if (tempat1 == 2){
                if (nama_barang[0] != 'R' || nama_barang[1] != 'u' || nama_barang[2] != 'b' || nama_barang[3] != 'b' || nama_barang[4] != 'y'){
                    ulang = 1;
                }
                else{
                    ulang = 0;
                    break;
                }
            }
            else if (tempat1 == 3){
                if (nama_barang[0] != 'B' || nama_barang[1] != 'a' || nama_barang[2] != 'r' || nama_barang[3] != 'a' || nama_barang[4] != 'c' || nama_barang[5] != 'k'){
                    ulang = 1;
                }
                else{
                    ulang = 0;
                    break;
                }
            }
        }
        if(ulang == 1){
            posisi(76,25); warna(15); printf("MEREK BARANG TELEBIH DAHULU !!");
            Sleep(500);
            posisi(76,25); warna(15); printf("                              ");
            posisi(76,25); warna(15); printf("MEREK BARANG TELEBIH DAHULU !!");
            Sleep(500);
            posisi(76,25); warna(15); printf("                              ");
            v_nama_barang(nama_barang,tempat1);
        }
    } while (ulang == 1);
    return nama_barang;
}

char* v_harga_jual(char* buff_harga_jual){
    int idx = 0;
    char ch;
    while ((ch = getch()) != 13 || idx == 0){
        if ( ((ch >= '1' && ch <= '9') && idx == 0) || ((ch >= '0' && ch <= '9') && idx >= 1) && idx < 6 ){
            printf("%c",ch);
            buff_harga_jual[idx] = ch;
            idx++;
        }
        else if (ch == 8 && idx != 0){
            printf("\b \b");
            buff_harga_jual[idx] = '\0';
            idx--;
        }
        else if (ch == 27){
            select_admin();
        }
    }
    buff_harga_jual[idx] = '\0';
    return buff_harga_jual;
}

char* v_harga_pokok(char* buff_harga_pokok){
    int idx = 0;
    char ch;
    while ((ch = getch()) != 13 || idx == 0){
        if ( ((ch >= '1' && ch <= '9') && idx == 0) || ((ch >= '0' && ch <= '9') && idx >= 1) && idx < 6 ){
            printf("%c",ch);
            buff_harga_pokok[idx] = ch;
            idx++;
        }
        else if (ch == 8 && idx != 0){
            printf("\b \b");
            buff_harga_pokok[idx] = '\0';
            idx--;
        }
        else if (ch == 27){
            select_admin();
        }
    }
    buff_harga_pokok[idx] = '\0';
    return buff_harga_pokok;
}