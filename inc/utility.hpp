#pragma once
#include <string>
#include <boxes.hpp>
#include "mediaDataBox.hpp"
#include "movieFragmentBox.hpp"
#include "movieFragmentHeaderBox.hpp"
#include "trackFragmentBox.hpp"
#include "trackFragmentHeaderBox.hpp"
#include "trackRunBox.hpp"
#include "unknownBox.hpp"
#include "fileBox.hpp"
namespace MoofBoxes
{
    static const std::string FILE{"file"};
    static const std::string MOOF{"moof"};
    static const std::string MDAT{"mdat"};
    static const std::string MFHD{"mfhd"};
    static const std::string TRAF{"traf"};
    static const std::string TFHD{"tfhd"};
    static const std::string TRUN{"trun"};

}; //namespaces MoofBoxes

namespace MediaDataBoxParsing
{
    static const char *TT{"tt"};
    static const char *HEAD{"head"};
    static const char *METADATA{"metadata"};

}; //namespaces MoofBoxes

class Factory
{
private:
    Factory() = default;

public:
    static std::unique_ptr<Boxes> create(const std::string &boxType)
    {
        std::unique_ptr<Boxes> box;
        if (!boxType.compare(MoofBoxes::FILE))
        {
            box = std::make_unique<FileBox>();
        }
        else if (!boxType.compare(MoofBoxes::MDAT))
        {
            box = std::make_unique<MediaDataBox>();
        }
        else if (!boxType.compare(MoofBoxes::MOOF))
        {
            box = std::make_unique<MovieFragmentBox>();
        }
        else if (!boxType.compare(MoofBoxes::MFHD))
        {
            box = std::make_unique<MovieFragmentHeaderBox>();
        }
        else if (!boxType.compare(MoofBoxes::TRAF))
        {
            box = std::make_unique<TrackFragmentBox>();
        }
        else if (!boxType.compare(MoofBoxes::TFHD))
        {
            box = std::make_unique<TrackFragmentHeaderBox>();
        }
        else if (!boxType.compare(MoofBoxes::TRUN))
        {
            box = std::make_unique<TrackRunBox>();
        }
        else
        {
            box = std::make_unique<UnknownBox>();
        }
        box->setBoxType(boxType);
        return box;
    }
};