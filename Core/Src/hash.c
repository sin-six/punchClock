
#include "hash.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>



// 哈希函数，解析uint64_t类型的学生ID
uint16_t hash(uint64_t key) {
    return (uint16_t)(key % TABLE_SIZE);
}

// 初始化哈希表
HashTable* createHashTable() {
    HashTable *ht = (HashTable*)malloc(sizeof(HashTable));
    if (ht == NULL) {
        fprintf(stderr, "Memory allocation failed for hash table\n");
        return NULL;
    }
    ht->table = (HashNode**)calloc(TABLE_SIZE, sizeof(HashNode*));
    if (ht->table == NULL) {
        fprintf(stderr, "Memory allocation failed for hash table array\n");
        free(ht);
        return NULL;
    }
    return ht;
}

// 插入打卡记录
void insertPunchRecord(HashTable *ht, uint64_t studentId, uint64_t punchTime) {
    unsigned int index = hash(studentId);
    HashNode *current = ht->table[index];
    // 检查学生ID是否已存在
    while (current != NULL) {
        if (current->studentId == studentId) {
            current->punchCount++;
            if (current->punchCount % 2 == 1) {
                // 第一次打卡或奇数次打卡，记录开始时间
                current->startTime = punchTime;
                current->endTime = 0;
            } else {
                // 第二次打卡或偶数次打卡，记录结束时间
                current->endTime = punchTime;
            }
            return;
        }
        current = current->next;
    }
    // 学生ID不存在，创建新节点
    HashNode *newNode = (HashNode*)malloc(sizeof(HashNode));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed for new hash node\n");
        return;
    }
    newNode->studentId = studentId;
    newNode->startTime = punchTime;
    newNode->endTime = 0;
    newNode->punchCount = 1;
    newNode->next = ht->table[index];
    ht->table[index] = newNode;
}

// 查找学生ID对应的记录
HashNode* search(HashTable *ht, uint64_t studentId) {
    unsigned int index = hash(studentId);
    HashNode *current = ht->table[index];
    while (current != NULL) {
        if (current->studentId == studentId) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}