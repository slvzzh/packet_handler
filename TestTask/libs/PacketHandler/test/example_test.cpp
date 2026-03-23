#include <cstddef>
#include <gtest/gtest.h>
#include <packet.h>
#include <packet_functions_head.h>
#include <filesystem>
#include <tuple>
TEST(PacketHandler, Make_packets) {
    std::string s1 = "Helloworld";
    std::string s2 = "";
    std::vector<Packet> res1 = make_vector_packet(s1, 4);
    std::vector<Packet> res2 = make_vector_packet(s1, 1);
    std::vector<Packet> res3 = make_vector_packet(s1, 10);
    EXPECT_EQ(res1.size(), 4);
    EXPECT_EQ(res2.size(), 1);
    EXPECT_EQ(res3.size(), 10);
    EXPECT_THROW(make_vector_packet(s1, 15), PacketsNumberException);
    EXPECT_THROW(make_vector_packet(s2, 15), EmptyFileException);

}


TEST(PacketHandler, Sort_packets) {
    std::string s1 = "Helloworld this is a string for test sfdfsjlnndfjkndfk";
    std::vector<Packet> p1 = make_vector_packet(s1, 8);
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(p1.begin(), p1.end(), g);
    sort_packet_vect(p1);
    for(size_t i = 1; i < p1.size(); ++i){
        ASSERT_EQ((p1[i].number - p1[i-1].number), 1);
    }

}

TEST(PacketHandler, Reassemble_packets){
    std::string s1 = "Helloworld this is a string for test sfdfsjlnndfjkndfk";
    std::vector<Packet> p1 = make_vector_packet(s1, 10);
    std::string s2 = "ПРОверка на русские буквы";
    std::vector<Packet> p2 = make_vector_packet(s2, 5);
    std::string res1 = reassemble(p1);
    std::string res2 = reassemble(p2);

    ASSERT_EQ(s1, res1);
    ASSERT_EQ(s2, res2);

}
class Fulltest : public ::testing::TestWithParam<std::tuple<std::string, size_t>>{};

TEST_P(Fulltest, FullTestParameters){
    auto [originalText, packetCount] = GetParam();


    std::vector<Packet> vec = make_vector_packet(originalText, packetCount);

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(vec.begin(), vec.end(), g);

    sort_packet_vect(vec);

    std::string processedText = reassemble(vec);
    ASSERT_EQ(processedText, originalText);

}

using TestParams = std::tuple<std::string, size_t>;

INSTANTIATE_TEST_CASE_P(
    CasesForFullTest,
    Fulltest,
    ::testing::Values(
        TestParams("This is \n a text\n  with \n spaces \n", (size_t)8),
        TestParams("helloworld", (size_t)10),
        TestParams(std::string(1000, 'a'), (size_t)100),
        TestParams("Русский текст тоже работает", (size_t)6),
        TestParams("Line1\nLine2\nLine3", (size_t)7)
    )
);
