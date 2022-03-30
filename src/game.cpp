#include <iostream>
#include "tour.cpp"
using namespace std;

int main(int argc, char const *argv[])
{
  Tour test(90,0);
  cout <<"test : "<< test.getNb_disque() << endl;

  return 0;
}
