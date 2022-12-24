#include<iostream>
using namespace std;
main()
{
string name;
float matric;
float inter;
float ecat;
float aggregate;
cout<< "Enter your Name : ";
cin>> name;
cout<< "Enter your Matric marks : ";
cin>> matric;
cout<< "Enter your Inter marks : ";
cin>> inter;
cout<< "Enter your ECAT marks : ";
cin>> ecat; 
aggregate = (40*(inter/510)) +(10*(matric/1100)) + (50*(ecat/400));
cout<<"Your aggregate is : ";
cout<< aggregate;
}