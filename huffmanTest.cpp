#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "minHeap.h"
#include "HuffTree.h"
#include "HuffBaseNode.h"
#include "Huffman.h"
#include <vector>

TEST_CASE("Testing min heap") {
    std::vector<HuffTree> vec = {HuffTree('a', 5), HuffTree('b', 3), HuffTree('c', 9), HuffTree('d', 2), HuffTree('e', 6)};
    minHeap mh(vec);
    CHECK(mh.size() == 5);
    CHECK(mh.deleteMin().weight() == 2);
    CHECK(mh.deleteMin().weight() == 3);
    CHECK(mh.deleteMin().weight() == 5);
    CHECK(mh.size() == 2);
    CHECK(mh.deleteMin().weight() == 6);
    CHECK(mh.deleteMin().weight() == 9);
    CHECK(mh.size() == 0);
    CHECK(mh.isEmpty() == true);


    mh.insert(HuffTree('f', 4));
    mh.insert(HuffTree('g', 1));
    mh.insert(HuffTree('h', 7));
    mh.insert(HuffTree('i', 8));
    mh.insert(HuffTree('j', 2));
    mh.insert(HuffTree('k', 5));
    mh.insert(HuffTree('l', 3));
    mh.insert(HuffTree('m', 6));
    CHECK(mh.size() == 8);
    CHECK(mh.deleteMin().weight() == 1);
    CHECK(mh.deleteMin().weight() == 2);
    CHECK(mh.deleteMin().weight() == 3);
    CHECK(mh.deleteMin().weight() == 4);
    CHECK(mh.deleteMin().weight() == 5);
    CHECK(mh.size() == 3);
    CHECK(mh.deleteMin().weight() == 6);
    mh.insert(HuffTree('n', 25));
    mh.insert(HuffTree('o', 15));
    mh.insert(HuffTree('p', 1));
    CHECK(mh.size() == 5);
    CHECK(mh.deleteMin().weight() == 1);
    CHECK(mh.deleteMin().weight() == 7);
    CHECK(mh.deleteMin().weight() == 8);
    CHECK(mh.deleteMin().weight() == 15);
    CHECK(mh.deleteMin().weight() == 25);
    CHECK(mh.size() == 0);
    CHECK(mh.isEmpty() == true);
}


TEST_CASE("Testing simple Huffman Character Encoding"){
    Huffman h("aaaabbc");
    h.huffify();
    
    CHECK(h.encodeMessage("a") == "1");
    CHECK(h.encodeMessage("b") == "01");
    CHECK(h.encodeMessage("c") == "00");
}

TEST_CASE("TEsting simple Huffman Character Decoding"){
    Huffman h("aaaabbc");
    h.huffify();
    
    CHECK(h.decodeMessage("1") == "a");
    CHECK(h.decodeMessage("01") == "b");
    CHECK(h.decodeMessage("00") == "c");
}

TEST_CASE("Testing simple Huffman String Encode"){
    Huffman h("aaaabbc");
    h.huffify();
    
    CHECK(h.encodeMessage("aaabbbcc") == "1110101010000");
    CHECK(h.encodeMessage("abc") == "10100");
    CHECK(h.encodeMessage("cba") == "00011");
}

TEST_CASE("Testing simple Huffman String Decode"){
    Huffman h("aaaabbc");
    h.huffify();
    
    CHECK(h.decodeMessage("111010100") == "aaabbc");
    CHECK(h.decodeMessage("10100") == "abc");
    CHECK(h.decodeMessage("00011") == "cba");
}

TEST_CASE("Testing a more complex character encoding"){
    Huffman h("abbccccddddddddeeeeeeeeeeeeeeeeffffffffffffffffffffffffffffffffff");
    h.huffify();
    
    CHECK(h.encodeMessage("a") == "00000");
    CHECK(h.encodeMessage("b") == "00001");
    CHECK(h.encodeMessage("c") == "0001");
    CHECK(h.encodeMessage("d") == "001");
    CHECK(h.encodeMessage("e") == "01");
    CHECK(h.encodeMessage("f") == "1");
}

TEST_CASE("Testing a more complex character decoding"){
    Huffman h("abbccccddddddddeeeeeeeeeeeeeeeeffffffffffffffffffffffffffffffffff");
    h.huffify();
    
    CHECK(h.decodeMessage("00000") == "a");
    CHECK(h.decodeMessage("00001") == "b");
    CHECK(h.decodeMessage("0001") == "c");
    CHECK(h.decodeMessage("001") == "d");
    CHECK(h.decodeMessage("01") == "e");
    CHECK(h.decodeMessage("1") == "f");
}


TEST_CASE("Testing a more complex string encoding"){
    Huffman h("abbccccddddddddeeeeeeeeeeeeeeeeffffffffffffffffffffffffffffffffff");
    h.huffify();
    
    CHECK(h.encodeMessage("abcdef") == "00000000010001001011");
    CHECK(h.encodeMessage("fedcba") == "10100100010000100000");
    CHECK(h.encodeMessage("aaabbbcccddddeeefff") == "000000000000000000010000100001000100010001001001001001010101111");
    CHECK(h.encodeMessage("fffeeeeddddcccbbbaaa") == "11101010101001001001001000100010001000010000100001000000000000000");
    CHECK(h.encodeMessage("fcdebcafc") == "10001001010000100010000010001");
}


TEST_CASE("Testing a more complex string decoding"){
    Huffman h("abbccccddddddddeeeeeeeeeeeeeeeeffffffffffffffffffffffffffffffffff");
    h.huffify();
    
    CHECK(h.decodeMessage("00000000010001001011") == "abcdef");
    CHECK(h.decodeMessage("10100100010000100000") == "fedcba");
    CHECK(h.decodeMessage("000000000000000000010000100001000100010001001001001001010101111") == "aaabbbcccddddeeefff");
    CHECK(h.decodeMessage("11101010101001001001001000100010001000010000100001000000000000000") == "fffeeeeddddcccbbbaaa");
    CHECK(h.decodeMessage("10001001010000100010000010001") == "fcdebcafc");
}

TEST_CASE("Testing another more complex character encoding example"){
    Huffman h("abbccccdddddeeeeeeffffffffggggggggghhhhhhhhhhiiiiiiiiiiiijjjjjjjjjjjjj");
    h.huffify();

    CHECK(h.encodeMessage("a") == "01000");
    CHECK(h.encodeMessage("b") == "01001");
    CHECK(h.encodeMessage("c") == "0101");
    CHECK(h.encodeMessage("d") == "1100");
    CHECK(h.encodeMessage("e") == "1101");
    CHECK(h.encodeMessage("f") == "011");
    CHECK(h.encodeMessage("g") == "100");
    CHECK(h.encodeMessage("h") == "101");
    CHECK(h.encodeMessage("i") == "111");
    CHECK(h.encodeMessage("j") == "00");
}

TEST_CASE("Testing another more complex character decoding example"){
    Huffman h("abbccccdddddeeeeeeffffffffggggggggghhhhhhhhhhiiiiiiiiiiiijjjjjjjjjjjjj");
    h.huffify();

    CHECK(h.decodeMessage("01000") == "a");
    CHECK(h.decodeMessage("01001") == "b");
    CHECK(h.decodeMessage("0101") == "c");
    CHECK(h.decodeMessage("1100") == "d");
    CHECK(h.decodeMessage("1101") == "e");
    CHECK(h.decodeMessage("011") == "f");
    CHECK(h.decodeMessage("100") == "g");
    CHECK(h.decodeMessage("101") == "h");
    CHECK(h.decodeMessage("111") == "i");
    CHECK(h.decodeMessage("00") == "j");
}

TEST_CASE("Testing another more complex string encoding example"){
    Huffman h("abbccccdddddeeeeeeffffffffggggggggghhhhhhhhhhiiiiiiiiiiiijjjjjjjjjjjjj");
    h.huffify();

    CHECK(h.encodeMessage("abcdefghij") == "010000100101011100110101110010111100");
    CHECK(h.encodeMessage("jihgfedcba") == "001111011000111101110001010100101000");
    CHECK(h.encodeMessage("aaabbbcccddddeeefffggghhhiiijjj") == "0100001000010000100101001010010101010101011100110011001100110111011101011011011100100100101101101111111111000000");
    CHECK(h.encodeMessage("jjjiiihhhgggfffeeeddddcccbbbaaa") == "0000001111111111011011011001001000110110111101110111011100110011001100010101010101010010100101001010000100001000");
    CHECK(h.encodeMessage("ajcbdiehfgg") == "010000001010100111001111101101011100100");
    CHECK(h.encodeMessage("abihjfedcjacdefjighabcdefghijjhigfeddcbbaaadfff") == "01000010011111010001111011100010100010000101110011010110011110010101000010010101110011010111001011110000101111100011110111001100010101001010010100001000010001100011011011");
}

TEST_CASE("Testing another more complex string decoding example"){
    Huffman h("abbccccdddddeeeeeeffffffffggggggggghhhhhhhhhhiiiiiiiiiiiijjjjjjjjjjjjj");
    h.huffify();

    CHECK(h.decodeMessage("010000100101011100110101110010111100") == "abcdefghij");
    CHECK(h.decodeMessage("001111011000111101110001010100101000") == "jihgfedcba");
    CHECK(h.decodeMessage("0100001000010000100101001010010101010101011100110011001100110111011101011011011100100100101101101111111111000000") == "aaabbbcccddddeeefffggghhhiiijjj");
    CHECK(h.decodeMessage("0000001111111111011011011001001000110110111101110111011100110011001100010101010101010010100101001010000100001000") == "jjjiiihhhgggfffeeeddddcccbbbaaa");
    CHECK(h.decodeMessage("010000001010100111001111101101011100100") == "ajcbdiehfgg");
    CHECK(h.decodeMessage("01000010011111010001111011100010100010000101110011010110011110010101000010010101110011010111001011110000101111100011110111001100010101001010010100001000010001100011011011") == "abihjfedcjacdefjighabcdefghijjhigfeddcbbaaadfff");
}


TEST_CASE("Testing all characters"){
    Huffman h("the quick brown fox jumps over the lazy dog.  THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG!");
    h.huffify();

    CHECK(h.decodeMessage(h.encodeMessage(" ")) == " ");
    CHECK(h.decodeMessage(h.encodeMessage("a")) == "a");
    CHECK(h.decodeMessage(h.encodeMessage("b")) == "b");
    CHECK(h.decodeMessage(h.encodeMessage("c")) == "c");
    CHECK(h.decodeMessage(h.encodeMessage("d")) == "d");
    CHECK(h.decodeMessage(h.encodeMessage("e")) == "e");
    CHECK(h.decodeMessage(h.encodeMessage("f")) == "f");
    CHECK(h.decodeMessage(h.encodeMessage("g")) == "g");
    CHECK(h.decodeMessage(h.encodeMessage("h")) == "h");
    CHECK(h.decodeMessage(h.encodeMessage("i")) == "i");
    CHECK(h.decodeMessage(h.encodeMessage("j")) == "j");
    CHECK(h.decodeMessage(h.encodeMessage("k")) == "k");
    CHECK(h.decodeMessage(h.encodeMessage("l")) == "l");
    CHECK(h.decodeMessage(h.encodeMessage("m")) == "m");
    CHECK(h.decodeMessage(h.encodeMessage("n")) == "n");
    CHECK(h.decodeMessage(h.encodeMessage("o")) == "o");
    CHECK(h.decodeMessage(h.encodeMessage("p")) == "p");
    CHECK(h.decodeMessage(h.encodeMessage("q")) == "q");
    CHECK(h.decodeMessage(h.encodeMessage("r")) == "r");
    CHECK(h.decodeMessage(h.encodeMessage("s")) == "s");
    CHECK(h.decodeMessage(h.encodeMessage("t")) == "t");
    CHECK(h.decodeMessage(h.encodeMessage("u")) == "u");
    CHECK(h.decodeMessage(h.encodeMessage("v")) == "v");
    CHECK(h.decodeMessage(h.encodeMessage("w")) == "w");
    CHECK(h.decodeMessage(h.encodeMessage("x")) == "x");
    CHECK(h.decodeMessage(h.encodeMessage("y")) == "y");
    CHECK(h.decodeMessage(h.encodeMessage("z")) == "z");
    CHECK(h.decodeMessage(h.encodeMessage(".")) == ".");
    CHECK(h.decodeMessage(h.encodeMessage("!")) == "!");
    CHECK(h.decodeMessage(h.encodeMessage("A")) == "A");
    CHECK(h.decodeMessage(h.encodeMessage("B")) == "B");
    CHECK(h.decodeMessage(h.encodeMessage("C")) == "C");
    CHECK(h.decodeMessage(h.encodeMessage("D")) == "D");
    CHECK(h.decodeMessage(h.encodeMessage("E")) == "E");
    CHECK(h.decodeMessage(h.encodeMessage("F")) == "F");
    CHECK(h.decodeMessage(h.encodeMessage("G")) == "G");
    CHECK(h.decodeMessage(h.encodeMessage("H")) == "H");
    CHECK(h.decodeMessage(h.encodeMessage("I")) == "I");
    CHECK(h.decodeMessage(h.encodeMessage("J")) == "J");
    CHECK(h.decodeMessage(h.encodeMessage("K")) == "K");
    CHECK(h.decodeMessage(h.encodeMessage("L")) == "L");
    CHECK(h.decodeMessage(h.encodeMessage("M")) == "M");
    CHECK(h.decodeMessage(h.encodeMessage("N")) == "N");
    CHECK(h.decodeMessage(h.encodeMessage("O")) == "O");
    CHECK(h.decodeMessage(h.encodeMessage("P")) == "P");
    CHECK(h.decodeMessage(h.encodeMessage("Q")) == "Q");
    CHECK(h.decodeMessage(h.encodeMessage("R")) == "R");
    CHECK(h.decodeMessage(h.encodeMessage("S")) == "S");
    CHECK(h.decodeMessage(h.encodeMessage("T")) == "T");
    CHECK(h.decodeMessage(h.encodeMessage("U")) == "U");
    CHECK(h.decodeMessage(h.encodeMessage("V")) == "V");
    CHECK(h.decodeMessage(h.encodeMessage("W")) == "W");
    CHECK(h.decodeMessage(h.encodeMessage("X")) == "X");
    CHECK(h.decodeMessage(h.encodeMessage("Y")) == "Y");
    CHECK(h.decodeMessage(h.encodeMessage("Z")) == "Z");
}

TEST_CASE("Testing full sentence encoding/decoding"){
    std::string testMessage = "the quick brown fox jumps over the lazy dog.  THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG!";
    Huffman h(testMessage);
    h.huffify();

    std::string encoded = h.encodeMessage(testMessage);
    std::string decoded = h.decodeMessage(encoded);

    CHECK(decoded == testMessage);
}