//
// Created by sn0w1eo on 26.02.18.
//

#include <gtest/gtest.h>
#include "enum_table.hpp"

namespace {
    using namespace Structures;
    class EnumTableTest : public ::testing::Test {
    protected:
        void SetUp() {
            uint32_t guid = 1;
            uint16_t depth = 0;
            title = new rapidjson::Value;
            title->SetString("Table Title");
            table = new EnumTable{1, title, depth, nullptr};
        }
        void TearDown() {
            delete title;
            delete table;
        }
        Table * table;
        rapidjson::Value * title;
    };

    TEST_F(EnumTableTest, GetTitleReturnsConstCharPtrToValueGetStringPtr) {
        EXPECT_EQ(table->get_title(), title->GetString());
    };

    TEST_F(EnumTableTest, GetDepth) {
        EXPECT_EQ(table->get_depth(), 0);
    }

    TEST_F(EnumTableTest, GetGUID) {
        EXPECT_EQ(table->get_guid(), 1);
    }

}