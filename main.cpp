//
// Created by 启翔 张 on 2017/12/26.
//

#include <iostream>
#include <thread>
#include <future>
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

    string key = "k";
    string value = "v";

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

  std::atomic<int> x = 0;
  std::atomic<int> y = 0;

  auto r1 = y.load(std::memory_order::memory_order_relaxed);
  x.store(r1, std::memory_order::memory_order_relaxed);
  std::atomic

    return 0;
}