//
// Created by rcole on 12/12/23.
//

#ifndef UTILS_FILECOMMANDLOADER_H
#define UTILS_FILECOMMANDLOADER_H

#include <cstdint>
#include <functional>
#include <vector>
#include <string>

class Color;

class Vec2D;

enum CommandType {
    COMMAND_ONE_LINE = 0,
    COMMAND_MULTI_LINE
};

struct ParseFunctionParams {
    std::string line;
    size_t cursorPos;
    uint32_t lineNumber;
};

using ParseFunc = std::function<void(const ParseFunctionParams &params)>;

struct Command {
    CommandType commandType = CommandType::COMMAND_ONE_LINE;
    std::string command;
    ParseFunc parseFunction = nullptr;
};

class FileCommandLoader {
public:
    void AddCommand(const Command &command);
    bool LoadFile(const std::string &filePath);

    static Color ReadColor(const ParseFunctionParams &params);
    static Vec2D ReadSize(const ParseFunctionParams &params);
    static int ReadInt(const ParseFunctionParams &params);
    static std::string ReadString(const ParseFunctionParams &params);
    static char ReadChar(const ParseFunctionParams &params);

private:
    std::vector<Command> mCommands;
};


#endif //UTILS_FILECOMMANDLOADER_H
