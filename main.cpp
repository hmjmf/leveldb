//
// Created by 启翔 张 on 2017/12/26.
//

#include <iostream>
#include <thread>
#include <chrono>
#include <future>
#include <utility>
#include <exception>
#include <stdexcept>
#include <string>
#include <fcntl.h>
#include <cassert>

#include <cstdlib>
#include <string>
// 包含必要的头文件
#include "leveldb/db.h"


using namespace std;
int main()
{



    leveldb::DB      *db;
    leveldb::Options  options;
    options.create_if_missing = true;
 

    // open
    leveldb::Status status = leveldb::DB::Open(options,"/tmp/testdb", &db);
    assert(status.ok());

    string key = "name";
    string value = "chenqi";

    // write
    status = db->Put(leveldb::WriteOptions(), key, value);
    assert(status.ok());

    // read
    status = db->Get(leveldb::ReadOptions(), key, &value);
    assert(status.ok());

    cout<<value<<endl;

    // delete
    status = db->Delete(leveldb::WriteOptions(), key);
    assert(status.ok());

    status = db->Get(leveldb::ReadOptions(),key, &value);
    if(!status.ok()) {
        cerr<<key<<"    "<<status.ToString()<<endl;
    } else {
        cout<<key<<"==="<<value<<endl;
    }

    // close
    delete db;

    return 0;
}