#define __GXX_WEAK__ 1
#define __cplusplus 1
#define __DEPRECATED 1
#define __GNUG__ 4
#define __EXCEPTIONS 1
#define __private_extern__ extern

#include <iostream>
#include <stdlib.h>
#include <random>

using namespace std;

const int days = 365;
const int friends = 400;
const int birthdaysInOneDay = 5;

random_device rd;   // non-deterministic generator
mt19937 gen(rd());  // to seed mersenne twister

int OneTrial()
{
    std::uniform_int_distribution<int> dist(0,days-1); // distribute results between 0 and 364 inclusive
    int boxes[days]; // готовим массив по имени "ячейки"
    for (int i = 0; i<days; i++)
    {
        boxes[i]=0;  // инициализируем массив нулями       
    }    
    
    
    for (int i = 0; i<friends; i++) // готовимся проводить 400 испытаний
    {
        int rnd = dist(gen); // генерим число rnd от 0 до 364
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
    //cout << "Total trials: " << totalCount << ", Success trials: " << successCount;
    cout <<  (double)successCount/(double)totalCount;
    
    return 0;
}
