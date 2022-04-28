#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>
#include <cmath>
// TODO: Centralize more functions here, reduce includes

float simpleCalc(std::string&);

int main(int argc, char const *argv[])
{

  std::cout << "Welcome to this AWESOME calculator! \nEnter basic arithmetic expressions to be quickly computed:\nIf desired, type 'q' to exit" << std::endl;

  std::string expression;

  while(true)
  {
    std::cout << "calc> ";
    std::cin >> expression;
    if(expression == "q") return 0;
    const float result = simpleCalc(expression);
    std::cout << result << std::endl;
  }
  return -1;
}

float simpleCalc(std::string &exp)
{
  float result;

  // Removes all whitespace (spaces and tabs)
  exp.erase(remove(exp.begin(), exp.end(), ' '), exp.end());
  exp.erase(remove(exp.begin(), exp.end(), '\t'), exp.end());

  std::vector<float> terms;
  std::vector<char> operators;

  for (size_t i = 0; i < exp.size(); i++)
  {
    float posChar = (float)(exp[i]-'0');
    // Continue adding onto previous term
    if(i > 0 && isdigit(exp[i]) && isdigit(exp[i-1]))
    {
      float val = terms.back()*10 + posChar;
      terms.pop_back();
      terms.push_back(val);
    }
    // Create a new term
    else if(isdigit(exp[i]))
    {
      terms.push_back(posChar);
    }
    // Add to operators array
    else operators.push_back(exp[i]);
  }

  unsigned int term = 1;
  result = terms.front();
  // TODO: Order of operations (PEMDAS)
  // TODO: Implement parenthetical syntax and brackets
  for(auto o : operators)
  {
    switch (o) {
      case '+':
        result += terms[term++];
        break;
      case '-':
        result -= terms[term++];
        break;
      case '*':
        result *= terms[term++];
        break;
      case '/':
        result /= terms[term++];
        break;
      case '^':
        result = pow(result, terms[term++]);
        break;
    }
  }

  // DEBUGGING::::::
  // std::cout << "Terms:\n";
  // for (size_t i = 0; i < terms.size(); i++) {
  //   std::cout << terms[i] << "\n";
  // }
  // std::cout << "Operators:\n";
  // for (size_t i = 0; i < operators.size(); i++) {
  //   std::cout << operators[i] << "\n";
  // }
  return result;
}
