//
// Created by amirb on 17/12/2022.
//

#include "Hash_Table.h"
#include <iostream>


bool isEqual(const int& t1, const int& t2){
    return t1 == t2;
}

int main(){
    Hash_Table<int> hash(isEqual);
    for(int i = 0; i<37; i++){
        hash.insert(5, 2);
        hash.printHash();
    }
    if(hash.get(37,5).status()==StatusType::SUCCESS){
        cout<<"SUCCESS: " << hash.get(37,5).ans()<<endl;
    }
    else{
        cout<<"FAILURE"<<endl;
    }
}
