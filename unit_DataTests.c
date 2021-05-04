#include "unity.h"
#include "Data.h"
#include "Interface.h"

MapList *mn = NULL;
MapList *m ;
  FILE *file =1;
void test_loadmap() {
    m= (MapList*)malloc(sizeof(MapList));
    TEST_ASSERT_EQUAL_INT(-1, load_map(NULL, mn, "/Users/mudi/Desktop/CorrectMap.map"));
    TEST_ASSERT_EQUAL_INT(-1, load_map(file, mn, "/Users/mudi/Desktop/CorrectMap.map"));
    TEST_ASSERT_EQUAL_INT(-1, load_map(file, m, "NoSuchFile"));
    TEST_ASSERT_EQUAL_INT(-1, load_map(file, m, "/Users/mudi/Desktop/MistakeMap.map"));
    TEST_ASSERT_EQUAL_INT(0, load_map(file, m, "/Users/mudi/Desktop/CorrectMap.map"));
}
void test_create_edge() {
    TEST_ASSERT_NULL(create_edge(-1, 20));
    TEST_ASSERT_NULL(create_edge(-1, -1));
    TEST_ASSERT_NULL(create_edge(-1, 0));
}

void test_check() {
    TEST_ASSERT_EQUAL_INT(0,(_check("1234567", 0)));
    TEST_ASSERT_EQUAL_INT(-1,(_check("12345a7", 0)));
    TEST_ASSERT_EQUAL_INT(0,(_check("-1234567", 0)));
    TEST_ASSERT_EQUAL_INT(0,(_check("-123.4567", 0)));
}

void test_indexcheck() {
    m= (MapList*)malloc(sizeof(MapList));
    load_map(file, m, "/Users/mudi/Desktop/CorrectMap.map");
    TEST_ASSERT_EQUAL_INT(-1,index_check(-1, *m));
    TEST_ASSERT_EQUAL_INT(-1,index_check(m->vexnum+1, *m));
    TEST_ASSERT_EQUAL_INT(0,index_check(-8847, *m));
}
void setUp(){

}
void tearDown(){

}

int main() {
  UNITY_BEGIN();
  RUN_TEST(test_loadmap);
    RUN_TEST(test_create_edge);
    RUN_TEST(test_check);
    RUN_TEST(test_indexcheck);


  return UNITY_END();
}
