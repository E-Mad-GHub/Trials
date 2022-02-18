
#include <unistd.h>
#include <iostream>
#include <utility>
#include "FNode.hpp"
#include "FList.hpp"



struct testData
{
    int x;
    float y;
};

int main()
{
    std::cout << "\n\n\n\nTEEEEEEEEEEEESSSSSSSSSSSSSSSSSSSSSSST" << std::endl;

    testData Setter, testData1, testData2, testData3;
    Forward_Node<testData> Node1, Node2, Node3;

    // Setter.x = 3;
    // Setter.y = 5;

    // Node1.setData(&Setter);

    // Node2.setData((Setter));

    // Node3.setData(std::move(Setter));

    // testData1 = *(Node1.getData());

    // testData2 = *(Node2.getData());

    // testData3 = *(Node3.getData());

    // std::cout << testData1.x << " " << testData1.y << "\n";
    // std::cout << testData2.x << " " << testData2.y << "\n";
    // std::cout << testData3.x << " " << testData3.y << "\n";


    testData1.x = 3;
    testData1.y = 4;

    testData2.x = 5;
    testData2.y = 6;

    testData3.x = 7;
    testData3.y = 8;

    Forward_List<testData> myList;

    bool out = false;
    
    out = myList.empty();
    std::cout << "List is empty = " << out << std::endl; 

    myList.push_front(std::move(testData1));

    std::cout << myList.begin()->x << " " << myList.begin()->y << "\n";
    std::cout << myList.end()->x << " " << myList.end()->y << "\n";

    myList.push_front(std::move(testData2));

    std::cout << myList.begin()->x << " " << myList.begin()->y << "\n";
    std::cout << myList.end()->x << " " << myList.end()->y << "\n";

    myList.push_front(std::move(testData3));

    std::cout << myList.begin()->x << " " << myList.begin()->y << "\n";
    std::cout << myList.end()->x << " " << myList.end()->y << "\n";

    std::cout << "POPING\n" ;

    // myList.pop_front();

    // std::cout << myList.begin()->x << " " << myList.begin()->y << "\n";
    // std::cout << myList.end()->x << " " << myList.end()->y << "\n";

    // myList.pop_front();

    // std::cout << myList.begin()->x << " " << myList.begin()->y << "\n";
    // std::cout << myList.end()->x << " " << myList.end()->y << "\n";

    // myList.pop_front();

    myList.clear();

    std::cout << "ALL OUT\n" ;

    out = myList.empty();
    std::cout << "List is empty = " << out << std::endl; 


    sleep(1);
    return 0;
}
