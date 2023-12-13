//
// Created by rcole on 12/12/23.
//

#include "FileCommandLoader.h"
#include <fstream>
#include "../Graphics/Color.h"
#include "Vec2D.h"

void FileCommandLoader::AddCommand(const Command &command) {
    mCommands.push_back(command);
}

bool FileCommandLoader::LoadFile(const std::string &filePath) {
    std::ifstream inFile;

    inFile.open(filePath);
    std::string line;

    if (!inFile.is_open()) {
        std::cout << "Couldn't open file: " << filePath << "\n";
        return false;
    }

    while (!inFile.eof()) {
        std::getline(inFile, line);

        size_t commandPosition = std::string::npos;

        if ((commandPosition = line.find(':') != std::string::npos)) {
            size_t cursorPosition = line.find_first_of(' ', commandPosition);
            if (cursorPosition == std::string::npos) {
                cursorPosition = line.length();
            } else {
                cursorPosition -= 1;
            }

            std::string commandStr = line.substr(commandPosition + 1, cursorPosition);
            cursorPosition += 1;

            for (auto &mCommand: mCommands) {
                if (commandStr == mCommand.command) {
                    if (mCommand.commandType == CommandType::COMMAND_ONE_LINE) {
                        ParseFunctionParams params;
                        params.cursorPos = cursorPosition;
                        params.lineNumber = 0;
                        params.line = line;

                        mCommand.parseFunction(params);
                    } else {
                        std::string numLines = line.substr(cursorPosition + 1);
                        int totalLines = std::stoi(numLines);
                        int lineNum = 0;

                        while (lineNum < totalLines) {
                            std::getline(inFile, line);

                            if (line.empty()) continue;
                            
                            ParseFunctionParams params;
                            params.cursorPos = 0;
                            params.lineNumber = lineNum;
                            params.line = line;

                            mCommand.parseFunction(params);
                            ++lineNum;
                        }
                    }
                }
            }
        }
    }

    return true;
}

Color FileCommandLoader::ReadColor(const ParseFunctionParams &params) {
    size_t nextSpacePos = params.line.find_first_of(' ', params.cursorPos + 1);
    uint8_t r = std::stoi(params.line.substr(params.cursorPos, (nextSpacePos - params.cursorPos)));

    size_t lastSpacePos = nextSpacePos;
    nextSpacePos = params.line.find_first_of(' ', lastSpacePos + 1);
    uint8_t g = std::stoi(params.line.substr(lastSpacePos + 1, (nextSpacePos - lastSpacePos)));

    lastSpacePos = nextSpacePos;
    nextSpacePos = params.line.find_first_of(' ', lastSpacePos + 1);
    uint8_t b = std::stoi(params.line.substr(lastSpacePos + 1, (nextSpacePos - lastSpacePos)));
    uint8_t a = std::stoi(params.line.substr(nextSpacePos + 1));

    return {r, g, b, a};
}

Vec2D FileCommandLoader::ReadSize(const ParseFunctionParams &params) {
    size_t nextSpacePos = params.line.find_first_of(' ', params.cursorPos + 1);
    int width = stoi(params.line.substr(params.cursorPos, (nextSpacePos - params.cursorPos)));

    size_t lastSpacePos = nextSpacePos;
    nextSpacePos = params.line.find_first_of(' ', lastSpacePos + 1);
    int height = stoi(params.line.substr(lastSpacePos + 1, nextSpacePos - lastSpacePos));

    return {static_cast<float>(width), static_cast<float>(height)};
}

int FileCommandLoader::ReadInt(const ParseFunctionParams &params) {
    std::string intStr = params.line.substr(params.cursorPos + 1);
    return stoi(intStr);
}

std::string FileCommandLoader::ReadString(const ParseFunctionParams &params) {
    return params.line.substr(params.cursorPos + 1);
}

char FileCommandLoader::ReadChar(const ParseFunctionParams &params) {
    return params.line.substr(params.cursorPos + 1)[0];
}

