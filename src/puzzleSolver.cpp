#include "puzzleSolver.hpp"

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace shindler::ics46::project1 {

bool verifySolution(const std::string& addend1, const std::string& addend2,
                    const std::string& result,
                    const std::unordered_map<char, unsigned>& mapping) {
    // TODO: Implement
    int addend1_number = 0;
    for (char current_char : addend1){
        int current_number = mapping.at(current_char);
        addend1_number = addend1_number * 10 + current_number;
    }

    int addend2_number = 0;
    for (char current_char : addend2){
        int current_number = mapping.at(current_char);
        addend2_number = addend2_number * 10 + current_number;
    }

    int result_number = 0;
    for (char current_char : result){
        int current_number = mapping.at(current_char);
        result_number = result_number * 10 + current_number;
    }

    int real_result = addend1_number + addend2_number;

    return real_result == result_number;
}

bool puzzleSolver(const std::string& addend1, const std::string& addend2,
                  const std::string& sum,
                  std::unordered_map<char, unsigned>& mapping) {
    // TODO: Implement this
    std::string all_letter = addend1 + addend2 + sum;
    std::string all_p_letter;
    std::vector<bool> numberTrack(10, false);
    std::unordered_set<char> letter_set;
    for (char letter:all_letter){
        if (letter_set.find(letter) == letter_set.end()){
            letter_set.insert(letter);
            all_p_letter += letter;
        }
    }
    return puzzleRecursion(0, all_p_letter, numberTrack, addend1, addend2, sum, mapping);
}
bool puzzleRecursion(unsigned index, const std::string& allChars, std::vector<bool>& numberTrack,
                     const std::string& addend1, 
                     const std::string& addend2,
                     const std::string& sum,
                     std::unordered_map<char, unsigned>& mapping){

    if (index == allChars.size()){
        return verifySolution(addend1, addend2, sum, mapping);
    }
    char cur_char = allChars[index];
    for (int i = 0; i<10; i++){
        if (!numberTrack[i]){
            mapping[cur_char] = i;
            numberTrack[i] = true;
            if (puzzleRecursion(index + 1, allChars, numberTrack, addend1, addend2, sum, mapping)){
                return true;
            }
            numberTrack[i] = false;
        }
    }
    return false;
}

}  // namespace shindler::ics46::project1
