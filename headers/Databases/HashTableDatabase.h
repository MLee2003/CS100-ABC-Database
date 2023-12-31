#ifndef __HT_DB__
#define __HT_DB__

#include "../Database.h"
#include <unordered_map>

class HashTableDatabase : public Database {
private:
    unordered_map<string, unique_ptr<DatabaseNode> > hashTable;
public:
    ~HashTableDatabase() {};
    HashTableDatabase(const string &name) : Database(name) {}
    string at(int key);
    void add(const string &context);
    DatabaseNode*  get(const string &context);
    void set(const string &context);
    void remove(const string &context);
    int getSize() { return hashTable.size();};
    void sort(const string &name);
};

#endif