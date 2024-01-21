#ifndef __PROJ_1__HPP
#define __PROJ_1__HPP

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace shindler::ics46::project1 {

/*
 * Project 1:  you need to implement this function.
 I promise that any of my test cases will have an empty
    map as the fourth parameter when called.
 If the puzzle IS solvable, return true AND make the mapping indicate the
 solution. If the puzzle is NOT solvable, it is enough to return false.

 See the project 1 write-up for a better description.
 */

bool verifySolution(
    const std::string& addend1, const std::string& addend2,
    const std::string& result,
    const std::unordered_map<char, unsigned>& mapping);

bool puzzleRecursion(unsigned& index, const std::string& allChars, std::vector<bool>& numberTrack,
                     const std::string& addend1, 
                     const std::string& addend2,
                     const std::string& sum,
                     std::unordered_map<char, unsigned>& mapping);


bool puzzleSolver(const std::string& addend1, const std::string& addend2,
                  const std::string& sum,
                  std::unordered_map<char, unsigned>& mapping);


}  // namespace shindler::ics46::project1


#endif
