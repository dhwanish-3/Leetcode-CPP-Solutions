#include <bits/stdc++.h>
using namespace std;

class UndergroundSystem {
    map <pair<string,string>,pair<int,int>> Journeys;
    map <int,pair<string,int>> persons;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        persons[id]=make_pair(stationName,t);
    }
    
    void checkOut(int id, string stationName, int t) {
        if(persons.find(id)!=persons.end()){
            int timeTaken=t-persons[id].second;
            pair<string,string> thisTravel=make_pair(persons[id].first,stationName);
            int times=0;
            int currSum=0;
            if(Journeys.find(thisTravel)!=Journeys.end()){
                times=Journeys[thisTravel].second;
                currSum=Journeys[thisTravel].first;
            }
            currSum+=timeTaken;
            times++;
            Journeys[thisTravel]=make_pair(currSum,times);
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        pair<string,string> tour=make_pair(startStation,endStation);
        return (double)Journeys[tour].first/Journeys[tour].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

int main(){
    UndergroundSystem* undergroundSystem = new UndergroundSystem();
    undergroundSystem->checkIn(45, "Leyton", 3);
    undergroundSystem->checkIn(32, "Paradise", 8);
    undergroundSystem->checkIn(27, "Leyton", 10);
    undergroundSystem->checkOut(45, "Waterloo", 15);  // Customer 45 "Leyton" -> "Waterloo" in 15-3 = 12
    undergroundSystem->checkOut(27, "Waterloo", 20);  // Customer 27 "Leyton" -> "Waterloo" in 20-10 = 10
    undergroundSystem->checkOut(32, "Cambridge", 22); // Customer 32 "Paradise" -> "Cambridge" in 22-8 = 14
    cout<<undergroundSystem->getAverageTime("Paradise", "Cambridge")<<endl; // return 14.00000. One trip "Paradise" -> "Cambridge", (14) / 1 = 14
    cout<<undergroundSystem->getAverageTime("Leyton", "Waterloo")<<endl;    // return 11.00000. Two trips "Leyton" -> "Waterloo", (10 + 12) / 2 = 11
    undergroundSystem->checkIn(10, "Leyton", 24);
    cout<<undergroundSystem->getAverageTime("Leyton", "Waterloo")<<endl;    // return 11.00000
    undergroundSystem->checkOut(10, "Waterloo", 38);  // Customer 10 "Leyton" -> "Waterloo" in 38-24 = 14
    cout<<undergroundSystem->getAverageTime("Leyton", "Waterloo")<<endl;    // return 12.00000. Three trips "Leyton" -> "Waterloo", (10 + 12 + 14) / 3 = 12
    return 0;
}