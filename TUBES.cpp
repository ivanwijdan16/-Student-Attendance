#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>

using namespace std;

    // variabel perulangan
    int i, j;

    //variabel untuk mengecek
    bool check;

    // variabel data

    string nomor;
    int mhs=-1;
    int mhs2=-1;

    // variabel data kosong
    string kosong = "                                      ";

   //simpan variabel data mahasiswa dan kehadiran
    struct dataMahasiswa {

        string nim;
        string nama;
        string alamat;
        string tahun;

        string nama2;
        string nim2;
        string matkul;
        string timestamp;

    } data[100];



void xy(short int x, short int y) { //Prosedur mengatur output bedasarkan koordinat x dan y

    COORD a = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), a);

}

void inputDataMahasiswa() { // prosedur input data mahasiswa

    mhs++;

    xy(6,2); cout << "INPUT DATA MAHASISWA";

    // tampilan input data mahasiswa

        xy(5,4);   cout << "NIM                  : ";
        xy(5,5);   cout << "Nama Mahasiswa       : ";
        xy(5,6);   cout << "Alamat               : ";
        xy(5,7);   cout << "Tahun Masuk          : ";

        // inputan data mahasiswa

        xy(28,4);  cin >> data[mhs].nim;
        cin.ignore();
        xy(28,5);  getline(cin, data[mhs].nama);
        xy(28,6);  getline(cin, data[mhs].alamat);
        xy(28,7);  cin >> data[mhs].tahun;

        // tampilkan data terakhir

        if (i == mhs-1) {

            xy(28,4);  cout << data[mhs].nim;
            xy(28,5);  cout << data[mhs].nama;
            xy(28,6);  cout << data[mhs].alamat;
            xy(28,7);  cout << data[mhs].tahun;

        }

        // tampilkan data yang sudah diinputkan

        xy(39,9);     cout << "Data Berhasil diinput";
        xy(5,11);     cout << "-----------------------------------------------------------------------------------------";
        xy(5,12);     cout << "|";
        xy(10,12);    cout << "NIM";
        xy(20,12);    cout << "|";
        xy(23,12);    cout << "Nama Mahasiswa";
        xy(40,12);    cout << "|";
        xy(55,12);    cout << "Alamat";
        xy(73,12);    cout << "|";
        xy(78,12);    cout << "Tahun Masuk";
        xy(93,12);    cout << "|";
        xy(5,13);     cout <<  "-----------------------------------------------------------------------------------------";

        xy(5,14);     cout << "|";
        xy(20,14);    cout << "|";
        xy(40,14);    cout << "|";
        xy(73,14);    cout << "|";
        xy(93,14);    cout << "|";
        xy(5,15);     cout <<  "-----------------------------------------------------------------------------------------";

        xy(7,14);     cout << data[mhs].nim;
        xy(22,14);    cout << data[mhs].nama;
        xy(42,14);    cout << data[mhs].alamat;
        xy(77,14);    cout << data[mhs].tahun;

        xy(5,18); system("pause");

}

void sortingAscendingDataMahasiswa() { //prosedur dengan insertion sort secara ascending data mahasiswa

    dataMahasiswa backup;

    for (i = 1; i <= mhs; i++) {

        j = i;
        while (j > 0 && data[j-1].nim > data[j].nim) {

            backup = data[j];
            data[j] = data[j-1];
            data[j-1] = backup;
            j--;
        }
    }
}

void sortingDescendingDataMahasiswa() { //prosedur dengan insertion sort secara descending data mahasiswa

    dataMahasiswa backup;

        for (i = 1; i <= mhs; i++) {

        j = i;
        while (j > 0 && data[j-1].nim < data[j].nim) {

            backup = data[j];
            data[j] = data[j-1];
            data[j-1] = backup;
            j--;
        }
    }
}

void tampilDataSorting() { //prosedur menampilkan hasil data yang sudah di sorting

    string nimKosong = "             ";
    string namaKosong = "                  ";
    string alamatKosong = "                               ";
    string tahunKosong = "               ";


    for (i = 0; i <= mhs; i++) {

        xy(42,1);    cout << "Data Mahasiswa";
        xy(5,3);     cout << "-----------------------------------------------------------------------------------------";
        xy(5,4);     cout << "|";
        xy(10,4);    cout << "NIM";
        xy(20,4);    cout << "|";
        xy(23,4);    cout << "Nama Mahasiswa";
        xy(40,4);    cout << "|";
        xy(55,4);    cout << "Alamat";
        xy(73,4);    cout << "|";
        xy(78,4);    cout << "Tahun Masuk";
        xy(93,4);    cout << "|";
        xy(5,5);     cout << "-----------------------------------------------------------------------------------------";

        // kondisi mengatur tampilan agar fleksibel dengan banyak data

        if (i < 1) {

            xy(5,6);     cout << "|";
            xy(20,6);    cout << "|";
            xy(40,6);    cout << "|";
            xy(73,6);    cout << "|";
            xy(93,6);    cout << "|";
            xy(5,7);     cout << "-----------------------------------------------------------------------------------------";

        } else if (i == 1) {

            xy(5,6+i);   cout << "                                                                                                              ";
            xy(5,7+i);   cout << "-----------------------------------------------------------------------------------------";
            xy(5,6+i);   cout << "|";
            xy(20,6+i);  cout << "|";
            xy(40,6+i);  cout << "|";
            xy(73,6+i);  cout << "|";
            xy(93,6+i);  cout << "|";

        } else {

            xy(5,6+i);   cout << "                                                                                                              ";
            xy(5,7+i);   cout << "-----------------------------------------------------------------------------------------";
            xy(5,6+i);   cout << "|";
            xy(20,6+i);  cout << "|";
            xy(40,6+i);  cout << "|";
            xy(73,6+i);  cout << "|";
            xy(93,6+i);  cout << "|";

        }

        xy(7,6+i);   cout << nimKosong;
        xy(22,6+i);  cout << namaKosong;
        xy(42,6+i);  cout << alamatKosong;
        xy(77,6+i);  cout << tahunKosong;


        xy(7,6+i);   cout << data[i].nim;
        xy(22,6+i);  cout << data[i].nama;
        xy(42,6+i);  cout << data[i].alamat;
        xy(77,6+i);  cout << data[i].tahun;

    }
}

int searchingData(struct dataMahasiswa data[], int mhs, string nomor) { //fungsi untuk searching data mahasiswa dengan menggunakan sequential search

    int posisi, i, ketemu;

    if (mhs <= 0)
        posisi = -1;

    else {

        ketemu = 0;
        i = 0;
        while ((i <= mhs) && !ketemu) {

            if (data[i].nim == nomor) {

                posisi = i;
                ketemu = 1;

            } else {

                i++;

            }
            if (!ketemu) {

                posisi = -1;

            }
        }
    }
    return posisi;
}

void tampilDataMahasiswa() { //prosedur menampilkan data yang sudah diinputkan

    string sorting, cari;

        xy(42,1);    cout << "Data Mahasiswa";
        xy(5,3);     cout << "-----------------------------------------------------------------------------------------";
        xy(5,4);     cout << "|";
        xy(10,4);    cout << "NIM";
        xy(20,4);    cout << "|";
        xy(23,4);    cout << "Nama Mahasiswa";
        xy(40,4);    cout << "|";
        xy(55,4);    cout << "Alamat";
        xy(73,4);    cout << "|";
        xy(78,4);    cout << "Tahun Masuk";
        xy(93,4);    cout << "|";
        xy(5,5);     cout << "-----------------------------------------------------------------------------------------";

    for (i = 0; i <=mhs; i++) {

        // kondisi mengatur tampilan agar fleksibel dengan banyak data

        if (i < 1) {

            xy(5,6);     cout << "|";
            xy(20,6);    cout << "|";
            xy(40,6);    cout << "|";
            xy(73,6);    cout << "|";
            xy(93,6);    cout << "|";
            xy(5,7);     cout << "-----------------------------------------------------------------------------------------";

        } else if (i == 1) {

            xy(5,6+i);   cout << "                                                                                                              ";
            xy(5,7+i);   cout << "-----------------------------------------------------------------------------------------";
            xy(5,6+i);   cout << "|";
            xy(20,6+i);  cout << "|";
            xy(40,6+i);  cout << "|";
            xy(73,6+i);  cout << "|";
            xy(93,6+i);  cout << "|";

        } else {

            xy(5,6+i);   cout << "                                                                                                              ";
            xy(5,7+i);   cout << "-----------------------------------------------------------------------------------------";
            xy(5,6+i);   cout << "|";
            xy(20,6+i);  cout << "|";
            xy(40,6+i);  cout << "|";
            xy(73,6+i);  cout << "|";
            xy(93,6+i);  cout << "|";

        }

        xy(7,6+i);   cout << data[i].nim;
        xy(22,6+i);  cout << data[i].nama;
        xy(42,6+i);  cout << data[i].alamat;
        xy(77,6+i);  cout << data[i].tahun;
    }
        //menu sorting nim data mahasiswa dengan ascending/descending
        backsort:
        xy(5, 8+i); cout << "Urutkan NIM Berdasarkan Ascending / Descending [A/D] : ";
        xy(61,8+i); cin >> sorting;

        if (sorting == "A") {

            sortingAscendingDataMahasiswa();
            tampilDataSorting();

        } else if (sorting == "D") {

            sortingDescendingDataMahasiswa();
            tampilDataSorting();

        } else {

            xy(5,11+i);  cout << "Pengurutan yang anda pilih tidak ditemukan (input A/D)";
            xy(60,8+i); cout << kosong;

            goto backsort;

        }

        //menu untuk mencari data mahasiswa
        xy(5,9+i); cout << "                                               ";
        xy(5,10+i); cout << "Masukkan NIM yang ingin dicari                       : ";
        xy(61,10+i); cin >> nomor;

        // searching data berdasarkan nim
        for (i = 0; i<=mhs; i++) {

            if (nomor == data[i].nim)
                cari = data[i].nim;

        }
        if (cari == nomor) {

            xy(5,11+i); cout << "                    ";
            int posisi = searchingData(data, mhs, nomor);

            if (posisi != -1) {

                xy(5,15+i); cout << "Mahasiswa dengan NIM " << nomor << " Ditemukan pada indeks ke - " << posisi;

            }

        } else {

            xy(5,15+i); cout << "Data tidak ditemukan";
            xy(61,9+i); cout << "       ";

        }
         xy(5,20+i);system("pause");
}
void tampilan(){ //prosedur untuk tampilan data mahasiswa yang sudah diinput

	    xy(44,1);    cout << "Data Mahasiswa";
        xy(5,3);     cout << "-----------------------------------------------------------------------------------------";
        xy(5,4);     cout << "|";
        xy(10,4);    cout << "NIM";
        xy(20,4);    cout << "|";
        xy(23,4);    cout << "Nama Mahasiswa";
        xy(40,4);    cout << "|";
        xy(54,4);    cout << "Alamat";
        xy(73,4);    cout << "|";
        xy(78,4);    cout << "Tahun Masuk";
        xy(93,4);   cout << "|";
        xy(5,5);     cout << "-----------------------------------------------------------------------------------------";

    for (i = 0; i <=mhs; i++) {

        // kondisi mengatur tampilan agar fleksibel dengan banyak data

        if (i < 1) {

            xy(5,6);     cout << "|";
            xy(20,6);    cout << "|";
            xy(40,6);    cout << "|";
            xy(73,6);    cout << "|";
            xy(93,6);    cout << "|";
            xy(5,7);     cout << "-----------------------------------------------------------------------------------------";

        } else if (i == 1) {

            xy(5,6+i);   cout << "                                                                                                              ";
            xy(5,7+i);   cout << "-----------------------------------------------------------------------------------------";
            xy(5,6+i);   cout << "|";
            xy(20,6+i);  cout << "|";
            xy(40,6+i);  cout << "|";
            xy(73,6+i);  cout << "|";
            xy(93,6+i);  cout << "|";

        } else {

            xy(5,6+i);   cout << "                                                                                                              ";
            xy(5,7+i);   cout << "-----------------------------------------------------------------------------------------";
            xy(5,6+i);   cout << "|";
            xy(20,6+i);  cout << "|";
            xy(40,6+i);  cout << "|";
            xy(73,6+i);  cout << "|";
            xy(93,6+i);  cout << "|";

        }

        xy(7,6+i);   cout << data[i].nim;
        xy(22,6+i);  cout << data[i].nama;
        xy(42,6+i);  cout << data[i].alamat;
        xy(77,6+i);  cout << data[i].tahun;
    }
    xy(5,20+i);
}
void hapusdataMahasiswa(){ //prosedur untuk menghapus data mahasiswa

	string x;

	xy(5,10+i);   cout << "Masukkan NIM yang mau dihapus             	: ";
	xy(50,10+i);  cin >> x;

    //perulangan untuk mengecek data mahasiswa apakah sama dengan yang diinput
	for(i = 0; i <= mhs; i++)
    {
      if (x == data[i].nim){
                check = true; //jika sama
                break;
            } else {
               check = false; //jika tidak
            }
    }

    if(check) //jika check=true
    {
     for(j = i; j <= mhs+1; j++)
     {
      data[j] = data[j+1];
     }
      xy(4,14+i);cout << " DATA BERHASIL DI HAPUS";
      mhs--; //data akan dihapus
    }
    else { //jika check=false
      xy(4,14+i);cout << " DATA TIDAK DITEMUKAN";
    }

      xy(5,17+i);system("pause");
}

void editdata(){ //prosedur untuk mengedit data

	string k;

	xy(5,10+i);   cout << "Masukkan NIM yang mau diedit             	: ";
	xy(50,10+i);  cin >> k;

    //perulangan untuk mengecek data mahasiswa apakah sama dengan yang diinput
    for(i = 0; i <= mhs; i++)
    {
      if (k == data[i].nim){
                check = true; //jika sama
                break;
            } else {
               check = false;//jika tidak
            }
    }
     //jika check=true
     if (check) {
        xy(5,13+i);  cout << "MASUKKAN DATA YANG BARU ";
    	xy(5,15+i);  cout << "NIM             			\t: ";
        xy(5,16+i);  cout << "Nama Mahasiswa           	\t\t: ";
        xy(5,17+i);  cout << "Alamat                      \t\t: ";
        xy(5,18+i);  cout << "Tahun Masuk        			: ";

        xy(50,15+i);  cin >> data[i].nim;
        cin.ignore();
        xy(50,16+i);  getline(cin, data[i].nama);
        xy(50,17+i);  getline(cin, data[i].alamat);
        xy(50,18+i);  cin >> data[i].tahun;
        xy(4,20+i);   cout<<" DATA BERHASIL DI EDIT";
	}
	//jika check = false
	else {
        xy(4,20+i);   cout<<" DATA TIDAK DITEMUKAN";
	}
        xy(5,22+i);system("pause");
}
void inputDataKehadiranMahasiswa() { // prosedur input data kehadiran mahasiswa

       time_t now = time(0);
       char* dt = ctime(&now);

       mhs2++;

       xy(6,2); cout << "INPUT DATA KEHADIRAN MAHASISWA";

    // tampilan input data kehadiran mahasiswa

        xy(5,4);   cout << "NIM                  : ";
        xy(5,5);   cout << "Nama Mahasiswa       : ";
        xy(5,6);   cout << "Mata Kuliah          : ";


    // inputan data kehadiran

        xy(28,4);  cin >> data[mhs2].nim2;
        cin.ignore();
        xy(28,5);  getline(cin, data[mhs2].nama2);
        xy(28,6);  getline(cin, data[mhs2].matkul);
        data[mhs2].timestamp =dt;


   	    if (i == mhs2-1){

            xy(28,4);  cout << data[mhs2].nim2;
            xy(28,5);  cout << data[mhs2].nama2;
            xy(28,6);  cout << data[mhs2].matkul;
            xy(28,7);  cout << data[mhs2].timestamp;
        }

        //perulangan untuk mengecek data mahasiswa apakah ada dan sama apa yang diinput
        for (i = 0; i <= mhs; i++) {
            if (data[mhs2].nim2 == data[i].nim && data[mhs2].nama2 == data[i].nama){
                check = true;//jika ada dan sama
                break;
            } else {
               check = false;//jika tidak
            }
        }

        //Tampilan jika data mahasiswa sama dengan data yang diinput di data kehadiran
        if (check) {
        for (i = 0; i <= mhs2; i++) {

        xy(42,9);     cout << "Data Kehadiran Mahasiswa";
        xy(5,10);     cout << "-----------------------------------------------------------------------------------------------------";
        xy(5,11);     cout << "|";
        xy(10,11);    cout << "NIM";
        xy(20,11);    cout << "|";
        xy(23,11);    cout << "Nama Mahasiswa";
        xy(40,11);    cout << "|";
        xy(52,11);    cout << "Mata Kuliah";
        xy(73,11);    cout << "|";
        xy(86,11);    cout << "Timestamp";
        xy(105,11);    cout << "|";
        xy(5,12);     cout << "-----------------------------------------------------------------------------------------------------";

        if (i < 1) {

            xy(5,13);     cout << "|";
            xy(20,13);    cout << "|";
            xy(40,13);    cout << "|";
            xy(73,13);    cout << "|";
            xy(105,13);   cout << "|";
            xy(5,14);     cout << "-----------------------------------------------------------------------------------------------------";

        } else if (i == 1) {

            xy(5,13+i);   cout << "                                                                                                              ";
            xy(5,14+i);   cout << "-----------------------------------------------------------------------------------------------------";
            xy(5,13+i);   cout << "|";
            xy(20,13+i);  cout << "|";
            xy(40,13+i);  cout << "|";
            xy(73,13+i);  cout << "|";
            xy(105,13+i); cout << "|";

        } else {

            xy(5,13+i);   cout << "                                                                                                              ";
            xy(5,14+i);   cout << "-----------------------------------------------------------------------------------------------------";
            xy(5,13+i);   cout << "|";
            xy(20,13+i);  cout << "|";
            xy(40,13+i);  cout << "|";
            xy(73,13+i);  cout << "|";
            xy(105,13+i); cout << "|";

        }

        xy(7,13+i);   cout << data[i].nim2;
        xy(22,13+i);  cout << data[i].nama2;
        xy(42,13+i);  cout << data[i].matkul;
        xy(78,13+i);  cout << data[i].timestamp;
      }

        } else { //Tampilan jika data mahasiswa tidak sama dengan data yang diinput di data kehadiran
                xy(5,8); cout << "NIM ATAU NAMA TIDAK TERDAFTAR SILAHKAN CEK KEMBALI";
                mhs2--;
        }

                xy(5,25+i); system("pause");
}
int main()
{
	char pil; //variabel untuk memasukkan pilihan
	//tampilan menu
    menu :
    xy(7,3);  cout << "MENU PRESENSI MAHASISWA";
    xy(5,5);  cout << "1. INPUT DATA MAHASISWA";
    xy(5,6);  cout << "2. HAPUS DATA MAHASISWA";
    xy(5,7);  cout << "3. EDIT DATA MAHASISWA";
    xy(5,8);  cout << "4. LIHAT DATA MAHASISWA";
    xy(5,9);  cout << "5. INPUT DATA KEHADIRAN MAHASISWA";
    xy(5,12); cout << "Masukkan Pilihan (1/2/3/4/5/6)   : ";

    xy(40,12);  cin >> pil;
    switch(pil) {

    case '1':

        system("cls");
        inputDataMahasiswa();

        system("cls");
        main();
        break;

    case '2':

        system("cls");
        tampilan();

        hapusdataMahasiswa();

        system("cls");
        tampilan();
        system("pause");

        system("cls");
        main();
        break;

    case '3':
    	system("cls");
        tampilan();

        editdata();

        system("cls");
        tampilan();
        system("pause");

        system("cls");
        main();
        break;

    case '4':
    	system("cls");
        tampilDataMahasiswa();

        system("cls");
        main();
        break;


    case '5':
    	system("cls");
        inputDataKehadiranMahasiswa();


        system("cls");
        main();
        break;

    default:

        xy(50,22); cout << "Pilihan tidak ada!!!";
        xy(80,19); cout << "    ";
        main();
    }
	getch();
}
