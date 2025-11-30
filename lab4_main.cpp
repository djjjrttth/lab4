#include <iostream>

using namespace std;

float dayAverage(float* row, int h)
{
    float summ = 0;
    float ave;

    for (int i = 0; i < h; i++){
        summ += *(row+i);
    }

    ave = summ/h;
    return ave;

}
float overallAverage(float** p, int d, int h){
    float summ = 0;
    float ave = 0;

    for (int i = 0; i < d; i++){
        for (int j = 0; j < h; j++){
            summ += (*(*(p+i)+j));

        }
    }

    ave = summ/d/h;
    return ave;
}
void showHotDays(float** p, int d, int h){
    float ave = overallAverage(p, d, h);
    float day_ave;
    int cnt = 0;

    for (int i = 0; i < d; i++){
        day_ave = dayAverage(*(p+i), h);
        if (day_ave > ave){
            cnt += 1;
        }
    }

    if (!cnt) cout << "Теплых дней нет" << endl;
    else{

        for (int i = 0; i < d; i++){
        day_ave = dayAverage(*(p+i), h);
            if (day_ave > ave){
                cout << "День " << i+1 << " (среднее = " << dayAverage(*(p+i), h) << ")" << endl;
            }
        }
    }
}


int main()
{
    int d;
    int h;

    cout << "Введите количество дней: ";
    cin >> d;
    cout << "Введите количество измерений в дне: ";
    cin >> h;

    float** data = new float*[d];


    for (int i = 0; i < d; i++){
        data[i] = new float[h];

    }


    for (int i = 0; i < d; i++){
        cout << "День " << i+1 << ": ";
        for (int j = 0; j < h; j++){
            cin >> *(*(data+i)+j);
            }
        }



    float ave = overallAverage(data, d, h);
    cout << "Общая средняя температура: " << ave << endl;

    showHotDays(data, d, h);

    for (int i = 0; i < d; i++){
        delete[] *(data+i);
    }
    delete[] data;

    return 0;
}
