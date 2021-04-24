#pragma once
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <iostream>

class Boxes
{
    using Boxespointer = std::unique_ptr<Boxes>;

public:
    Boxes() = default;
    virtual ~Boxes() = default;

    virtual void displayMsg(std::ostream &os);
    virtual int parseElements(std::ifstream &ifs, const uint64_t size);
    void setMediaDataBoxData(const std::string &mdatData);
    std::string getMediaDataBoxData() const;
    void setBoxType(const std::string &type);
    bool downloadFile(char **argv);

protected:
    std::string m_boxtype;
    uint32_t m_boxSize{0};

private:
    std::vector<Boxespointer> elements;
    uint32_t m_dataReadSoFar{8}; // 4 bytes for size and 4 bytes for type
    std::string m_mdatBoxData;
};
