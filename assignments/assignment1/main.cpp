/*
 * CS106L Assignment 1: EnrollmentNavigator
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 *
 * Welcome to Assignment 1 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 * Students must implement: parse_csv, write_courses_offered,
 * write_courses_not_offered
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

const std::string COURSES_OFFERED_PATH = "student_output/courses_offered.csv";
const std::string COURSES_NOT_OFFERED_PATH = "student_output/courses_not_offered.csv";

struct Course {

  std::string title = "";
  int number_of_units = 0;
  std::string quarter = "";

  Course(std::string t, int n, std::string q): title(t), number_of_units(n), quarter(q){}

};

/**
 * Note:
 * We need to #include utils.cpp _after_ we declare the Course struct above
 * so that the code inside utils.cpp knows what a Course is.
 * Recall that #include literally copies and pastes file contents.
 */
#include "utils.cpp"

/**
 * @param filename The name of the file to parse.
 * @param courses  A vector of courses to populate.
 */
void parse_csv(std::string filename, std::vector<Course>& courses) {
  std::ifstream input(filename);
	std::string s;
	std::vector<std::string> data;
	std::getline(input, s);
  while(std::getline(input, s)){
		data = split(s, ',');
		courses.push_back({data[0], std::stoi(data[1]), data[2]});
		//std::cout << courses[courses.size() - 1] << std::endl;
	}
}

/**
 * @param all_courses A vector of all courses gotten by calling `parse_csv`.
 *                    This vector will be modified by removing all offered courses.
 */
void write_courses_offered(std::vector<Course> all_courses) {

	std::vector<int> index;

	std::ofstream output("./student_output/courses_offered.csv");

	output << "Title,Number of Units,Quarter" << std::endl;

  	for(int i = 0; i < all_courses.size(); i++){
		if(all_courses[i].quarter != "null"){
			output << all_courses[i] << std::endl;
			index.push_back(i);
		}
	}
	for(int i = index.size() - 1; i >= 0; i--){
		delete_elem_from_vector(all_courses, all_courses[index[i]]);
	}
	
}

/**
 * @param unlisted_courses A vector of courses that are not offered.
 */
void write_courses_not_offered(std::vector<Course> unlisted_courses) {
  	std::vector<int> index;

	std::ofstream output("./student_output/courses_not_offered.csv");

	output << "Title,Number of Units,Quarter" << std::endl;

  	for(int i = 0; i < unlisted_courses.size(); i++){
		if(unlisted_courses[i].quarter == "null"){
			output << unlisted_courses[i] << std::endl;
			index.push_back(i);
		}
	}
	for(int i = index.size() - 1; i >= 0; i--){
		delete_elem_from_vector(unlisted_courses, unlisted_courses[index[i]]);
	}
}

int main() {
  /* Makes sure you defined your Course struct correctly! */
  static_assert(is_valid_course<Course>, "Course struct is not correctly defined!");

  std::vector<Course> courses;

  parse_csv("courses.csv", courses);

	//print_courses(courses);

  write_courses_offered(courses);
  write_courses_not_offered(courses);

  return run_autograder();
}