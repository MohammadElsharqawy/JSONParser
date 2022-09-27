

#include <map>
#include <string>

#ifndef UNTITLED9_JSONPARSER_H
#define UNTITLED9_JSONPARSER_H


class JSONParser {
public:
    explicit JSONParser();
    JSONParser(JSONParser &) = delete;
    ~JSONParser();


    std::map<std::string, std::string> parseJASON(std::string &data);
    std::string generateJSON(std::map<std::string, std::string> &data);
};


#endif //UNTITLED9_JSONPARSER_H
