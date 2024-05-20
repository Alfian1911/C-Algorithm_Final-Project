#include <iostream>
using namespace std;

//menghitung rata rata x
float mean_x(float x[], int x_size) {
    float sum_x = 0;
    for(int i = 0; i < x_size; i++) {
        sum_x+=x[i];
    }
    //menghitung rata rata;
    float mean_x = sum_x/x_size;
    return mean_x;
}

//menghitung rata rata y
float mean_y(float y[], int y_size) {
    float sum_y = 0;
    for(int i = 0; i < y_size; i++) {
        sum_y+=y[i];
    }
    //menghitung rata rata;
    float mean_y = sum_y/y_size;
    return mean_y;
}

//mengestimasi b1
float estimate_b1(float x[], float y[], int x_size, float rata_rata_x, float rata_rata_y) {
    //formula bagian atas
    float atas = 0;
    for(int i = 0; i < x_size; i++) {
        float hasil_1 = (x[i]-rata_rata_x)*(y[i]-rata_rata_y);
        atas+=hasil_1;

    } 

    //formula bagian bawah
    float bawah = 0;
    for(int j = 0; j < x_size; j++) {
        float hasil_2 = (x[j]-rata_rata_x)*(x[j]-rata_rata_x);
        bawah+=hasil_2;
    }
    return atas/bawah;
}

//mengestimasi b0
float estimate_b0(float rata_rata_y, float slope, float rata_rata_x) {
    float hasil_b0 = rata_rata_y - (slope*rata_rata_x);
    return hasil_b0;
}

int main() {
    //Homepage
    cout << "=======================================" << endl;
    cout << "SELAMAT DATANG DI PROGRAM ESTIMASI SRS" << endl;
    cout << "=======================================" << endl;

    //input ukuran data
    int x_size, y_size;
    cout << "Masukkan jumlah data x dan y secara berurutan: ";
    cin >> x_size >> y_size;
    float x[x_size];
    float y[y_size];

    while(true) {
        //program utama
        if(x_size == y_size) {
            cout << "Jumlah data yang anda masukkan sudah sama, lanjutkan input data" << endl;

            //input data x
            cout << "Masukkan data x:" << endl;
            for(int i = 0; i < x_size; i++) {
                cout << "masukkan data ke " << i+1 << " : ";
                cin >> x[i];
            }
            
            cout << "-------------------------------------"<< endl;
            //input data y
            cout << "Masukkan data y:" << endl;
            for(int j = 0; j < y_size; j++) {
                 cout << "masukkan data ke " << j+1 << " : ";
                  cin >> y[j];
            }
            
            cout << "-------------------------------------"<< endl;
            //menampilkan x
            cout << "Data x: ";
            for(int a = 0; a < x_size; a++) {
                cout << x[a] << " ";
            }
            
            cout << endl;
            cout << "-------------------------------------"<< endl;
            //menampilkan y
            cout << "Data y: ";
            for(int b = 0; b < x_size; b++) {
                cout << x[b] << " ";
            }
            
            cout << endl;
            cout << "-------------------------------------"<< endl;
            //perhitungan rata rata x
            float rata_rata_x = mean_x(x, x_size);
            cout << "Rata rata x = " << rata_rata_x;
            
            cout << endl;
            cout << "-------------------------------------"<< endl;
            //perhitungan rata rata y
            float rata_rata_y = mean_y(y, y_size);
            cout << "Rata rata y = " << rata_rata_y;
            
            cout << endl;
            cout << "-------------------------------------"<< endl;
            //Menampilkan + hasil estimasi slope (b1)
            float slope = estimate_b1(x,y, x_size, rata_rata_x, rata_rata_y);
            cout << "Nilai untuk slope (b1) nya adalah: " << slope;
            
            cout << endl;
            cout << "-------------------------------------"<< endl;
            //Menampilkan + hasil estimasi intercept (b0)
            float intercept = estimate_b0(rata_rata_y, slope, rata_rata_x);
            cout << "Nilai untuk intercept (b0) nya adalah: " << intercept;
            //menampilkan model srs
            cout << endl;
            cout << "Model SRS: y = " << intercept << " + " << slope << "x" << endl;

        } else {
            cout << "JUMLAH DATA YANG ANDA MASUKKAN TIDAK SAMA!" << endl;
            cout << "OPERASI TIDAK DAPAT DILAKUKAN" << endl;

        }

        char counter;
        cout << "Masukkan data lagi(y/n)?: ";
        cin >> counter;

        if(counter == 'y') {
            continue;

        } else if (counter == 't') {
            break;

        } else {
            break;
            
        }
    }
    
    cout << "Program selesai" << endl;
    
}
