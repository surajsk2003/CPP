#include<iostream>
using namespace std;

class Employee
{
    private:
        int a, b, c;
    public:
        int d, e;
        void setData(int a1, int b1, int c1); // Declaration
        void getData(){
            cout<<"The value of a is "<<a<<endl;
            cout<<"The value of b is "<<b<<endl;
            cout<<"The value of c is "<<c<<endl;
            cout<<"The value of d is "<<d<<endl;
            cout<<"The value of e is "<<e<<endl;
        }
};

void Employee :: setData(int a1, int b1, int c1){
    a = a1;
    b = b1;
    c = c1;
}

int main(){
    Employee harry;
    // harry.a = 134; -->This will throw error as a is private
    harry.d = 34;
    harry.e = 89;
    harry.setData(1,2,4);
    harry.getData();
    return 0;
}
// #include <iostream>
// using namespace std;

// class Body_measurement {
//     private:
//         string height, weight, blood_group;
//     public:
//         // Define setdata method
//         void setdata(string h, string w, string bg) {
//             height = h;
//             weight = w;
//             blood_group = bg;
//         }

//         // Method to get data
//         void getdata() {
//             cout << "Height: " << height << endl;
//             cout << "Weight: " << weight << endl;
//             cout << "Blood Group: " << blood_group << endl;
//         }
// };

// int main() {
//     Body_measurement suraj;
//     suraj.setdata("5'7", "65 kg", "O+");
//     suraj.getdata();  // Correct the method name here
//     return 0;
// }
