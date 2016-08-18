#include <iostream>
#include <stdlib.h>
#include <memory.h>
#include <math.h>

using namespace std;

const int days = 365;
const int friends = 400;
const int birthdaysInOneDay = 5;

int OneTrial()
{
    int boxes[days]; // готовим массив по имени "ячейки"
    memset(boxes, 0, sizeof(boxes));
    for (int i = 0; i<friends; i++) // готовимся проводить 400 испытаний
    {
        int rnd = round((double)rand()*(days-1)/((long)RAND_MAX + 1)) ; // генерим число rnd от 0 до 364
        boxes[rnd]++; // добауляем 1 шарик в коробку с номером rnd
        if (boxes[rnd] == birthdaysInOneDay) //  Если их там уже 5, то нам тут делать нечего
        {
            return 1; // выходим и говорим, что испытание успешно (возвращаем 1)
        }
    }
    return 0; // если за 400 итераций успех не достугнут, то возвращаем 0.
}

int main(int argc, char **argv)
{
    int interations = atoi(argv[1]);
    int totalCount = 0;
    int successCount = 0;
    for (totalCount = 0; totalCount<interations; totalCount++)
    {
        successCount = successCount + OneTrial();
    }

    cout << (double)successCount/totalCount << endl;
    return 0;
}
