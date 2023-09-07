#include "set/setting.h"
#include "validasi.c"
#include "start.c"
#include "admin.c"
#include "barang.c"
#include "crud.c"
#include "user.c"

void waktu(){
    time_t currentTime;
    time(&currentTime);
    struct tm *myTime = localtime(&currentTime);
    hari =  myTime -> tm_mday;
    bulan = myTime -> tm_mon + 1;
    tahun =  myTime -> tm_year + 1900;
    if (tempat == 2 || tempat == 6){
        itoa(hari,buff_hari,10);
        itoa(bulan,buff_bulan,10);
        itoa(tahun,buff_tahun,10);
    }
}

void main(){
    Sleep(500);
    bingkai_user();
}