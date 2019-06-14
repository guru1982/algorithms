#include <iostream>
#include <string>
#include <random>
#include <vector>
using namespace std;

vector<float> randFloatGen(int n){
     vector<float> newList;
    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_real_distribution<> dis(1.0, 100.0);
    for(int i = 0; i < n; i++){
        newList.push_back(dis(gen));   
    }
    return newList;
}

void printFloat(vector<float> vectorF){
    for (int i = 0; (unsigned) i < vectorF.size(); i++){
        cout << vectorF[i] << endl;   
    }
}

vector<float> insertSort(vector<float> listFloat){
    int len = listFloat.size();
    for(int i = 1; i < len; i++){
        int j = i - 1;
        float myKey = listFloat[i];
        while (j >= 0 && listFloat[j] > myKey){
            listFloat[j + 1] = listFloat[j];
            j -= 1;
        }
        listFloat[j+1] = myKey;
    }
    return listFloat;
}

int main()
{
    vector<float> mylist = randFloatGen(20);
    cout << "vector before sort" << endl;
    printFloat(mylist);
    vector<float> finalList = insertSort(mylist);
    cout << "vector after sort" << endl;
    printFloat(finalList);
    return 0;
}
