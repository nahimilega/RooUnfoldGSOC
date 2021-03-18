#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>

using namespace std;

string GetStdoutFromCommand(string cmd) {
  string data;
  FILE * stream;
  const int max_buffer = 256;
  char buffer[max_buffer];
  cmd.append(" 2>&1");

  stream = popen(cmd.c_str(), "r");
  if (stream) {
    while (!feof(stream))
      if (fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);
    pclose(stream);
  }
  return data;
}

int main() {
  string rootOutput = GetStdoutFromCommand("./RooUnfoldGSOC | tail -n +3");
  //cout << rootOutput[0] << endl;

  string s = rootOutput ;
  string delimiter = "\n";

  size_t pos = 0;
  std::string token;

  vector<string> lines;


  while ((pos = s.find(delimiter)) != std::string::npos) {
      token = s.substr(0, pos);
      //std::cout << token << std::endl;
      lines.push_back(token);
      s.erase(0, pos + delimiter.length());
  }
  lines.push_back(s);
  //std::cout << s << std::endl;
  for(size_t i = 0; i<(lines.size()-1)/2; i++){
    cout<<lines[i]<<endl<<endl;
    if(lines[i] != lines[(lines.size()+1)/2+i]){
      return 1;
    }
  }



  return 0;
  
}
