#pragma once

#include "boxes.hpp"

class MediaDataBox : public Boxes
{
public:
    MediaDataBox() = default;
    virtual ~MediaDataBox() = default;
    void saveImageToDisk();
    void displayMsg(std::ostream &os);
};