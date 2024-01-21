#include "puzzleSolver.hpp"

#include <string>
#include <unordered_map>

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
    return {};  // This is not the correct general solution.
}

}  // namespace shindler::ics46::project1
