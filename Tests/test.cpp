#include <iostream>

using namespace std;


int max(int* data, int size){

  int result = data[0];

  for (int i=1; i<size; i++)

    if (data[i] > result)

      result = data[i];

  return result;

}


int main() {

  int data[3] = {-1,0,1};

  cout << data+max(data,3) << endl;

  return 0;

}