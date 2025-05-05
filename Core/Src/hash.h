#ifndef __HASH_H
#define __HASH_H


#define TABLE_SIZE 100

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// 定义哈希表节点结构体
typedef struct HashNode {
    uint64_t studentId;
    uint64_t startTime;
    uint64_t endTime;
    int punchCount;
    struct HashNode *next;
} HashNode;

// 定义哈希表结构体
typedef struct HashTable {
    HashNode **table;
} HashTable;


// 哈希函数，解析uint64_t类型的学生ID
uint16_t hash(uint64_t key);

// 初始化哈希表
HashTable* createHashTable() ;
void insertPunchRecord(HashTable *ht, uint64_t studentId, uint64_t punchTime);

HashNode* search(HashTable *ht, uint64_t studentId);


#endif
