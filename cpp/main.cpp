#include <iostream>
#include <random>

using namespace std;


random_device rd;   // non-deterministic generator
mt19937 gen(rd());  // to seed mersenne twister
uniform_int_distribution<> dist(0,364); // distribute results between 0 and 364 inclusive

int OneTrial()
{
    int boxes[365]; // готовим массив по имени "ячейки"
    for (int i = 0; i<365; i++)
    {
        boxes[i]=0;  // инициализируем массив нулями
        //cout << "   Initializing boxes[" << i << "] with 0. Result = " << boxes[i] << endl;
    }    
    
    
    for (int i = 0; i<400; i++) // готовимся проводить 400 испытаний
    {
        int rnd = dist(gen); // генерим число rnd от 0 до 364
        boxes[rnd]++; // добауляем 1 шарик в коробку с номером rnd
        
        //cout << "   Current rnd = " << rnd << ", current boxes[rnd] = " << boxes[rnd] << endl;

        if (boxes[rnd] == 5) //  Если их там уже 5, то нам тут делать нечего
        {
            cout  << endl << "   Successfull hit!" << endl;
            return 1; // выходим и говорим, что испытание успешно (возвращаем 1)
        }
        
    }
    
    cout  << endl << "   No hits registered." << endl;
    return 0; // если за 400 итераций успех не достугнут, то возвращаем 0.
}




int main(int argc, char **argv)
{
    //std::cout << "Hello World" << std::endl;
    
    int totalCount = 0;
    int successCount = 0;
    
    for (totalCount = 0; totalCount<1000000; totalCount++)
    {
        successCount = successCount + OneTrial();
    }
    cout << "Total trials: " << totalCount << ", Success trials: " << successCount;
        
    return 0;
}
