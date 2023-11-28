#include <gtest/gtest.h>

#include <array>
#include <list>
#include <queue>
#include <stack>

#include "headers/s21_containers.h"
#include "headers/s21_containersplus.h"
#include "tests/test_array.inc"
#include "tests/test_btree.inc"
#include "tests/test_list.inc"
#include "tests/test_map.inc"
#include "tests/test_multiset.inc"
#include "tests/test_queue.inc"
#include "tests/test_set.inc"
#include "tests/test_stack.inc"
#include "tests/test_vector.inc"

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
