#include <iostream>
using namespace std;

class ParkingSystem {
    
public:
    int big;
    int medium;
    int small;
    ParkingSystem(int bigCar, int mediumCar, int smallCar) {
        big=bigCar;
        medium=mediumCar;
        small=smallCar;
    }
    
    bool addCar(int carType) {
        // cout<<small<<" "<<medium<<" "<<big<<endl;
        if(carType==3){
            if(small==0){
                return false;
            }
            else{
                small--;
                return true;
            }
        }
        else if(carType==2){
            if(medium==0){
                return false;
            }
            else{
                medium--;
                return true;
            }
        }else if(carType==1){
            if(big==0){
                return false;
            }
            else{
                big--;
                return true;
            }
        }
        return false;
    }
    
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */

int main(){
    ParkingSystem* pS=new ParkingSystem(1,1,0);
    cout<<pS->big<<" "<<pS->medium<<" "<<pS->small<<endl;
    cout<<pS->addCar(1);
    cout<<pS->addCar(2);
    cout<<pS->addCar(3);
    cout<<pS->addCar(1);
    
    return 0;
}