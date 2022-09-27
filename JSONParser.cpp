

#include "JSONParser.h"

JSONParser::JSONParser() {}
JSONParser::~JSONParser() {}


std::map<std::string, std::string> JSONParser::parseJASON(std::string &data) {
    std::map<std::string, std::string> dataMap;
    std::string buffer = data;
    std::string key="", val="";


    uint8_t startPosKey = 0, endPosKey = 0, startPosVal = 0, endPosVal = 0;

    do{
        startPosKey = buffer.find_first_of("\"");
        endPosKey = buffer.find_first_of("\"",startPosKey+1);

        startPosVal = buffer.find_first_of("\"");
        endPosVal = buffer.find_first_of("\"",startPosVal+1);

        key = buffer.substr(startPosKey, endPosKey - startPosKey +1);
        val = buffer.substr(startPosVal, endPosVal - startPosVal +1);

        //std::printf("[JASONParser] Key: %c Val: %c", key, val);

        dataMap.insert(std::pair<std::string,std::string>(key, val));

       buffer = buffer.substr(endPosVal);
    }while(buffer.find("\"") != std::string::npos);


    return dataMap;
}


std::string JSONParser::generateJSON(std::map<std::string, std::string> &data){
     std::string dataString = "{";

     typedef std::map<std::string, std::string>::iterator myIterator;

    for (myIterator iterator = data.begin(); iterator != data.end() ; ++iterator) {
       dataString += "\""+iterator->first + "\": \" "+ iterator->second + "\",";
    }

    // remove the last ,
    dataString.pop_back();

    dataString.push_back('}');

    return dataString;
}
