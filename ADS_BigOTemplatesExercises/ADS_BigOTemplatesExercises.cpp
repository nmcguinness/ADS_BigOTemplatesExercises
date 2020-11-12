/*****************************************************************//**
 * \file   ADS_BigOTemplatesExercises.cpp
 * \brief  Selected solutions to the BigO and Templates exercises in Moodle
 * 
 * \author NMCG
 * \date   November 2020
 *********************************************************************/
#include <iostream>
#include "BigO.h"
#include "ADS_BigOTemplatesExercises.h"
using namespace std;

void exercisesBigO();
void exercisesTemplates();

int main()
{
    /*************************** BigO Exercises ***************************/
    cout << "BigO Exercises..." << endl;
    exercisesBigO();

    /*************************** Templates Exercises ***************************/
    cout << "Templates Exercises..." << endl;
    exercisesTemplates();
}

/*************************** BigO Exercises ***************************/
void exercisesBigO()
{

}

//exercise 1
template <typename T>
T max(T x, T y) {
    return x > y ? x : y;
}
//exercise 2
template <typename T>
T min(T x, T y) {
    return x < y ? x : y;
}

//exercise 3
template <typename E>
void print(list<E> list) {
    for (E value : list) {
        cout << value << endl;
    }
}

//exercise 5
template <class E>
class ADS_Array {
private:
    E* pData = nullptr;
    int length = 0;
    E defaultValue;

    void initialize(E defaultValue) {
        for (int i = 0; i < this->length; i++)
            this->pData[i] = defaultValue;
    }

public:
    ADS_Array(int length, E defaultValue) {
        this->pData = new E[length];
        this->length = length;
        this->defaultValue = defaultValue;

        //sets the contents to the default
        initialize(defaultValue);
    }

    void print() const {
        for (int i = 0; i < this->length; i++) {
            cout << pData[i] << endl;
        }
    }

    int size() const { return this->length; }

    E get(int index) const {
        if (index >= 0 && index < this->length)
            return this->pData[index];
        else
            return this->defaultValue; //"", 0, false, default(E)
    }

    bool add(E data, int index){
        if (index >= 0 && index < this->length) {
            this->pData[index] = data;
            return true;
        }
        return false;
    }

    //pushes new data onto the end of the array and grows the array by 50%
    //[1,2,3,4] and we add 5 then [1,2,3,4,5,0]
    bool push(E data) {
        return false;
    }
};


/*************************** Templates Exercises ***************************/
void exercisesTemplates()
{
    ADS_Array<string> arr1(5, "blank");
    arr1.print();

    ADS_Array<int> arr2(5, -1);
    arr2.print();
    arr2.add(2, 0);
    arr2.add(4, 1);
    arr2.add(8, 2);
    arr2.add(16, 3);
    arr2.add(32, 4);

    cout << arr2.get(3) << endl;
}
