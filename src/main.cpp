#include <iostream>
#include <curl/curl.h>
#include <fstream>

#include <filesystem>
#include "boxes.hpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(moofparsertest, URLIsCorrect)
{
	Boxes box;
	char *argv[] = {(char *)"", (char *)"https://demo.castlabs.com/tmp/text0.mp4", (char *)"test.mp4"};
	auto res = box.downloadFile(argv);
	EXPECT_EQ(true, res);
}

TEST(moofparsertest, URLIsWrong)
{
	Boxes box;
	char *argv[] = {(char *)"", (char *)"https://demo.google.com/tmp/text0.mp4", (char *)"test.mp4"};
	auto res = box.downloadFile(argv);
	EXPECT_EQ(false, res);
}

TEST(moofparsertest, FileSizeZero)
{
	Boxes box;
	char *argv[] = {(char *)"", (char *)"https://demo.castlabs.com/tmp/text0.mp4", (char *)"test.mp4"};
	auto res = box.downloadFile(argv);
	EXPECT_EQ(true, res);
	std::ifstream inputFile;
	inputFile.open(argv[2], std::ios_base::in | std::ios_base::binary);
	auto ret = box.parseElements(inputFile, 0);
	EXPECT_EQ(-1, ret);
}
TEST(moofparsertest, EmptyInputStream)
{
	Boxes box;
	char *argv[] = {(char *)"", (char *)"https://demo.castlabs.com/tmp/text0.mp4", (char *)"test.mp4"};
	auto res = box.downloadFile(argv);
	EXPECT_EQ(true, res);
	std::ifstream input;
	auto ret = box.parseElements(input, 1000);
	EXPECT_EQ(-1, ret);
}
// Add More Unit test Cases

int main(int argc, char **argv)
{
	if (argc < 3)
	{
		//https://demo.castlabs.com/tmp/text0.mp4
		std::cout << "USAGE"
				  << "./moofparser https://demo.castlabs.com/tmp/text0.mp4 test.mp4" << std::endl;
		return 0;
	}
	Boxes b;
	if (!b.downloadFile(argv))
	{
		return 0;
	}
	else
	{
		std::cout << "Successfully load file http://demo.castlabs.com/tmp/text0.mp4 " << std::endl;
	}
	uint64_t inputFileSize{0};
	std::ifstream inputFile;
	inputFile.open(argv[2], std::ios_base::in | std::ios_base::binary);
	if (!inputFile)
	{
		std::cout << "File open failed " << std::endl;
	}
	// to know the file size c++17 feature
	std::filesystem::path p{
		argv[2]};
	inputFileSize = std::filesystem::file_size(p);

	b.parseElements(inputFile, inputFileSize);
	inputFile.close();
	b.displayMsg(std::cout);

	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}