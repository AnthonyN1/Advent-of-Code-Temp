/*
	Advent of Code - 2016: Day 03
	Author: Anthony Nool (AnthonyN1)
*/

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>


/**
 * @brief A collection of three side lengths that possibly make up a triangle.
 * 
*/
class MaybeTriangle{
	public:
		MaybeTriangle(unsigned long long s1=0, unsigned long long s2=0, unsigned long long s3=0): s1_(s1), s2_(s2), s3_(s3) {}
		unsigned long long s1_, s2_, s3_;
};


/**
 * @param input  the collection of input strings
 * 
 * @return a collection of MaybeTriangles parsed from strings.
 * 
*/
std::vector<MaybeTriangle> parseIntoTrianglesPart1(const std::vector<std::string> &input){
	std::vector<MaybeTriangle> triangles;
	for(const std::string &line : input){
		MaybeTriangle mt;

		std::stringstream ss(line);
		ss >> mt.s1_ >> mt.s2_ >> mt.s3_;

		triangles.push_back(mt);
	}

	return triangles;
}

/**
 * @param input  the collection of input strings
 * 
 * @return a collection of MaybeTriangles parsed from strings.
 * 
*/
std::vector<MaybeTriangle> parseIntoTrianglesPart2(const std::vector<std::string> &input){
	std::vector<MaybeTriangle> triangles;

	// Converts the strings into a class of three integral types.
	std::vector<MaybeTriangle> trianglesByRow = parseIntoTrianglesPart1(input);

	// Iteratively reads each group of 3 rows.
	for(unsigned int i = 0; i < trianglesByRow.size() / 3; ++i){
		MaybeTriangle mt1;
		mt1.s1_ = trianglesByRow[3 * i + 0].s1_;
		mt1.s2_ = trianglesByRow[3 * i + 1].s1_;
		mt1.s3_ = trianglesByRow[3 * i + 2].s1_;

		triangles.push_back(mt1);

		MaybeTriangle mt2;
		mt2.s1_ = trianglesByRow[3 * i + 0].s2_;
		mt2.s2_ = trianglesByRow[3 * i + 1].s2_;
		mt2.s3_ = trianglesByRow[3 * i + 2].s2_;

		triangles.push_back(mt2);

		MaybeTriangle mt3;
		mt3.s1_ = trianglesByRow[3 * i + 0].s3_;
		mt3.s2_ = trianglesByRow[3 * i + 1].s3_;
		mt3.s3_ = trianglesByRow[3 * i + 2].s3_;

		triangles.push_back(mt3);
	}

	return triangles;
}

/**
 * @param mt  the MaybeTriangle to look at
 * 
 * @return true if the MaybeTriangle is a triangle, and false otherwise.
 * 
*/
bool possible(const MaybeTriangle &mt){
	if(mt.s1_ + mt.s2_ <= mt.s3_) return false;
	if(mt.s2_ + mt.s3_ <= mt.s1_) return false;
	if(mt.s3_ + mt.s1_ <= mt.s2_) return false;

	return true;
}


void partOne(const std::vector<std::string> &input){
	// Parses the input into MaybeTriangles (by row).
	std::vector<MaybeTriangle> triangles = parseIntoTrianglesPart1(input);

	// Counts the number of possible triangles.
	unsigned long long numPossible = std::count_if(triangles.begin(), triangles.end(), possible);


	std::cout << numPossible << std::endl;
}

void partTwo(const std::vector<std::string> &input){
	// Parses the input into MaybeTriangles (by column).
	std::vector<MaybeTriangle> triangles = parseIntoTrianglesPart2(input);

	// Counts the number of possible triangles.
	unsigned long long numPossible = std::count_if(triangles.begin(), triangles.end(), possible);


	std::cout << numPossible << std::endl;
}
